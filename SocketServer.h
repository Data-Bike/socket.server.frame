/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SocketServer.h
 * Author: gorod_000
 *
 * Created on 22 августа 2016 г., 3:27
 */

#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <functional>
#include <thread>
#include <memory>
#include <sys/mman.h>
#include <system_error>
#include "SParams.h"
#include "SClient.h"
#include "ClientsBox.h"
#include "SQueue.h"

using namespace std;

class SocketServer {
public:
    typedef void (*tdoes)(SClient*);
    typedef bool (*tqrun)(QMessage);
    static SocketServer* factory(SParams* params, tdoes does, tqrun qrun = NULL);
    virtual ~SocketServer();
    static int server_id;
    static SocketServer* single_server;
    static void join();
    static void destroy();
    SQueue* queue;
private:
    SocketServer();
    SocketServer(const SocketServer& orig);
    static list<shared_ptr<thread>> threads;
    bool playing = false;
    int threads_count;
    int port;
    int part_length;
    int socket_server;
    tdoes does;
    tqrun qrun;
};

#endif /* SOCKETSERVER_H */

