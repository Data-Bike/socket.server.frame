/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientsBox.cpp
 * Author: gorod_000
 * 
 * Created on 23 августа 2016 г., 1:22
 */

#include <stdlib.h>
#include <map>

#include "ClientsBox.h"
#include "SClient.h"
list<thread*> ClientsBox::threads;
mutex* ClientsBox::clients_operate;
map<int, SClient*> ClientsBox::socket_clients;

ClientsBox::ClientsBox(SQueue* queue) {

    this->clients_operate = new mutex();
    this->queue = queue;
    cbid++;
    inner_id = cbid;
    pid_t pid;
    this->server_event.fd = this->server_socket;
    this->server_event.events = POLLIN;
    this->socks_set.insert(this->socks_set.end(), this->server_event);
    cout << "ClientsBoxs socks_set" << endl;

    this->thread_clients_box = [&]()->void {
        int client_socket = 0;

        while (this->playing) {
            this->socks_set_evented = vector<pollfd>(this->socks_set.cbegin(), this->socks_set.cend());
            if (poll(&this->socks_set_evented[0], (nfds_t) this->socks_set_evented.size(), this->timeout) <= 0) {
                continue;
            }
            for (pollfd client : this->socks_set_evented) {



                int errorCode;
                int len = sizeof (errorCode);
                int socket_error = getsockopt(client.fd, SOL_SOCKET, SO_ERROR,
                        &errorCode, (socklen_t*) & len);
                if (errorCode && this->socket_clients.count(client.fd)) {
                    *this -= this->socket_clients[client.fd];
                    cout << "ClientsBox socket ERROR: " << socket_error << " №" << errorCode << endl;
                    continue;
                }


                if ((!ClientsBox::socket_clients[client.fd]) && (client.fd != this->server_socket)) {
                    continue;
                }

                if ((!client.revents)) {
                    continue;
                }
                //                cout << "ClientsBoxs EVENT :" << client.fd << ":" << client.revents << ":" << client.events << endl;
                //                cout << "ClientsBoxs server socket :" << this->server_socket << endl;

                if (client.revents & POLLIN) {
                    if (client.fd == this->server_socket) {
                        client_socket = accept(this->server_socket, NULL, NULL);
                        //                        cout << "ClientsBoxs new client :" << client_socket << ":" << client.revents << endl;
                        if (client_socket < 0) {
                            if (!(errno & (EAGAIN | EWOULDBLOCK))) {
                                cout << "ClientsBoxs new client add fail ERR№" << errno << endl;
                            }
                            continue;
                        }
                        if ((client_socket > 0) && (this->socket_clients.count(client_socket) == 0)) {
                            //                            cout << "ClientsBoxs accpeted client :" << client_socket << endl;
                            client.revents = 0;
                            *this += new SClient(client_socket, this->queue);
                        }
                        continue;
                    }


                    //                    cout << "ClientsBoxs POLLIN :" << client.fd << ":" << client.revents << endl;
                    if (this->socket_clients[client.fd]->part_recv()) {
                        *this -= this->socket_clients[client.fd];
                        continue;
                    };

                }



                if (client.revents & POLLOUT) {
                    if (this->socket_clients[client.fd]->part_send()) {
                        *this -= this->socket_clients[client.fd];
                        continue;
                    }
                    //                    cout << "ClientsBoxs POLLOUT :" << client.fd << endl;
                }
                if ((client.revents & POLLERR) || (client.revents & POLLHUP) || (client.revents & POLLNVAL)) {
                    //                    cout << "ClientsBoxs fork own thread recv socket fallout :" << client.fd << " : ";
                    if (client.revents & POLLERR) {
                        //                        cout << "POLLERR" << client.fd << endl;
                    }
                    if (client.revents & POLLHUP) {
                        //                        cout << "POLLHUP" << client.fd << endl;
                    }
                    if (client.revents & POLLNVAL) {
                        //                        cout << "POLLNVAL" << client.fd << endl;
                    }
                    *this -= this->socket_clients[client.fd];
                    continue;
                }

            }
            this->socks_set_evented.clear();

        }
    };

    cout << "ClientsBoxs fork own thread timeout :" << this->timeout << endl;
    threads.insert(threads.end(), new thread(thread_clients_box));
    //    thCB.join();
}

void ClientsBox::join() {
    for (thread* th : ClientsBox::threads) {
        if (th->joinable()) {
            th->join();
        }
    }
}

ClientsBox::ClientsBox(const ClientsBox& orig) {
}

ClientsBox::~ClientsBox() {
}
