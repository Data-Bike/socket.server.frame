/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientsBox.h
 * Author: gorod_000
 *
 * Created on 23 августа 2016 г., 1:22
 */

#ifndef CLIENTSBOX_H
#define CLIENTSBOX_H
#include <sys/time.h>
#include <vector>
#include <poll.h>
#include <mutex>
#include <map>
#include <set>
#include <thread>
#include <list>
#include <iostream>
#include <fcntl.h>
#include "SClient.h"
using namespace std;

struct pollfd_less {

    bool operator()(const pollfd a, const pollfd b) const {
        return a.fd < b.fd;
    }
};

class ClientsBox {
    friend class SocketServer;
public:
    ClientsBox(SQueue* queue);
    ClientsBox(const ClientsBox& orig);

    ClientsBox& operator+=(SClient* client) {

        lock_guard<mutex> lock(*this->clients_operate);
//        lock_guard<mutex> locks_client(*client->client_operate);
        if (this->socket_clients.find(client->socket) != this->socket_clients.end()) {
            return *this;
        }
//        cout << "CLIENT ADDED :" << inner_id << " : " << client->socket << " th_id:" << this_thread::get_id() << endl;
        pollfd sock_event;
        fcntl(client->socket, F_SETFL, fcntl(client->socket, F_GETFL, 0) | O_NONBLOCK);
        sock_event.fd = client->socket;
        sock_event.events = POLLIN + POLLOUT;
        ;
        client->client_event = &(*this->socks_set.insert(this->socks_set.end(), sock_event));
        this->socket_clients.insert(pair<int, SClient*&>(client->socket, client));
        inner_id++;
        return *this;
    };

    ClientsBox& operator-=(const SClient* client) {
//        cout << "ClientsBox erease client" << endl;
        if (!client) {
            return *this;
        }
//        cout << "ClientsBox erease client erasing" << endl;
        lock_guard<mutex> lock(*this->clients_operate);
//        cout << "ClientsBox erease client went clients_operate" << endl;
        lock_guard<mutex> locks_client(*client->client_operate);
//        cout << "ClientsBox erease client went client_operate" << endl;
        this->socks_set.erase(*client->client_event);
//        cout << "ClientsBox erease client went socks_set" << endl;

        this->socket_clients.erase(client->socket);
//        cout << "ClientsBox erease client went socket_clents" << endl;
        return *this;
    };
    int size();
    static bool playing;
    static int timeout;
    static int part_lenght;
    static int max_threads;
    static int cbid;
    static int server_socket;
    static list<thread*> threads;
    static void join();
    function<void() > thread_clients_box;
    SQueue* queue;
    int inner_id;
private:
    set<pollfd, pollfd_less> socks_set;
    vector<pollfd> socks_set_evented;
    static mutex* clients_operate;
    pollfd server_event;
    vector<SClient*> clients;
    static map<int, SClient*> socket_clients;
    virtual ~ClientsBox();
};



#endif /* CLIENTSBOX_H */

