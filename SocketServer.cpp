/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SocketServer.cpp
 * Author: gorod_000
 * 
 * Created on 22 августа 2016 г., 3:27
 */

#include "SocketServer.h"
#include "ClientsBox.h"
list<shared_ptr<thread>> SocketServer::threads;

SocketServer::SocketServer() {
}

SocketServer* SocketServer::factory(SParams* params, tdoes does, tqrun qrun) {
    int on = 1;
    if (server_id > 0) {
        return SocketServer::single_server;
    }
    cout << "CREATE NEW SERVER" << endl;
    server_id++;
    sockaddr_in serv_addr;
    single_server = new SocketServer();

    cout << "CREATE NEW SERVER set params" << endl;
    single_server->part_length = params->getInt("part_length");
    single_server->port = params->getInt("port");
    single_server->threads_count = params->getInt("threads_count");
    single_server->does = does;
    single_server->qrun = qrun;

    cout << "CREATE NEW SERVER create socket " << single_server->qrun << endl;
    if ((single_server->socket_server = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        exit(1);
    }

    fcntl(single_server->socket_server, F_SETFL, fcntl(single_server->socket_server, F_GETFL, 0) | O_NONBLOCK);
    cout << "CREATE NEW SERVER set zero serv_addr" << endl;
    bzero((char *) &serv_addr, sizeof (serv_addr));

    cout << "CREATE NEW SERVER set serv_addr" << endl;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(single_server->port);
    cout << "CREATE NEW SERVER bind serv socket" << endl;
    if (bind(single_server->socket_server, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0) {
        exit(1);
    }
    cout << "CREATE NEW SERVER set to listen" << endl;
    listen(single_server->socket_server, SOMAXCONN);


    cout << "CREATE NEW SERVER static set ClientsBox" << endl;
    ClientsBox::cbid = 0;
    ClientsBox::max_threads = single_server->threads_count;
    ClientsBox::part_lenght = single_server->part_length;
    ClientsBox::playing = true;
    ClientsBox::server_socket = single_server->socket_server;
    ClientsBox::timeout = params->getInt("timeout");
    cout << "CREATE NEW SERVER static set SClient" << endl;

    SClient::part_length = single_server->part_length;
    SClient::does = does;
    SClient::qrun = qrun;
    cout << "CREATE NEW SERVER static set queue" << endl;
    //    SClient::queue = &single_server->queue;
    //    SQueue qu;
    static SQueue* outQueue = new SQueue();
    cout << "CREATE NEW SERVER static set queue size: " << outQueue->qm->size() << endl;

    cout << "CREATE NEW SERVER Clients threads start" << endl;
    for (int cbid = 0; cbid < ClientsBox::max_threads; cbid++) {
        new ClientsBox(outQueue);
    }
    cout << "CREATE NEW SERVER queue doing start" << endl;
    static mutex mutex_qrun;
    static auto srv_th = [ & ]()->void {
        try {
            while (ClientsBox::playing) {
//                cout << "Queue processing" << endl;
                [&]()->void {
                    lock_guard<mutex> lk(mutex_qrun);
                    QMessage msg = outQueue->front();
                    SClient::qrun(msg);
                }();
            }
        } catch (int e) {
            cout << "SocketServer::construct :  thrown exception: " << e << endl;
        }
    };

    if (qrun) {
        for (int cbid = 0; cbid < ClientsBox::max_threads; cbid++) {
            try {
                SocketServer::threads.insert(SocketServer::threads.end(), make_shared<thread>(srv_th));
                cout << "SocketServer::construct :  THREAD OK" << endl;
            } catch (int e) {
                cout << "SocketServer::construct :  thrown exception: " << e << endl;
            }
        }
    }
    cout << "SocketServer::constructed :  OK" << endl;
    return SocketServer::single_server;
}

void SocketServer::join() {
    ClientsBox::join();
    for (auto th : SocketServer::threads) {
        if (th->joinable()) {
            th->join();
        }
    }
}

void SocketServer::destroy() {
    ClientsBox::playing = false;
    close(ClientsBox::server_socket);
    //    SocketServer::join();
}

SocketServer::SocketServer(const SocketServer& orig) {
}

SocketServer::~SocketServer() {
}

