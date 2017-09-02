/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SClient.h
 * Author: gorod_000
 *
 * Created on 18 августа 2016 г., 1:50
 */

#ifndef QCLIENT_H
#define QCLIENT_H
#include <vector>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/poll.h>
#include <mutex>
#include <iostream>
#include <unistd.h>
#include "SQueue.h"

using namespace std;

class SClient {
    friend class ClientsBox;
public:
    typedef void (*tdoes)(SClient*);
    typedef bool (*tqrun)(QMessage);

    SClient& operator+=(vector<unsigned char>& in) {
        if(!this){
            cout<<"SClient += super error added data to null"<<endl;
            return *this;
        }
        lock_guard<mutex> lock(*this->client_operate);
//        cout << "SClient += " << endl;
//        cout << "SClient += size message_in: " << in.size() << endl;
//        cout << "SClient += size message_out: " << (this ? "OK" : "FAIL") << endl;
        this->message_out->insert(this->message_out->end(), in.begin(), in.end());
//        cout << "SClient += setup params" << endl;
//        this->client_event->events = POLLIN | POLLOUT;

//        cout << "SClient += ok" << endl;
        return *this;
    }

    vector<unsigned char>* request();
    int socket;
    const pollfd* client_event;
    bool part_recv();
    bool part_send();
    virtual ~SClient();
    static int part_length;
    static tdoes does;
    static tqrun qrun;
    mutex *client_operate;
    SQueue* queue;
    SQueue*& getqueue();
    bool tofinish = false;
    void todo(vector<unsigned char>* request = NULL);
    void finish();
    void clear_request();
private:
    SClient(int socket, SQueue* queue);
    SClient(const SClient& orig);
    vector<unsigned char>* message_in;
    vector<unsigned char>* message_out;
};

#endif /* QCLIENT_H */