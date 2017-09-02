/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SClient.cpp
 * Author: gorod_000
 * 
 * Created on 18 августа 2016 г., 1:50
 */


#include "SClient.h"

namespace {
    SQueue queue_g();
}

//mutex *SClient::client_operate;

vector<unsigned char>* SClient::request() {
    return this->message_in;
}

SQueue*& SClient::getqueue() {
    return queue;
}

bool SClient::part_recv() {
    if (!this) {
        cout << "SClient::part_recv super error no client but part recv" << endl;
        return false;
    }

    if (this->client_operate->try_lock()) {
        vector<unsigned char> buf;
        buf.resize(this->part_length);
        int recvl = 0;
        int err = errno;
        if ((recvl = read(this->socket, &buf[0], this->part_length)) < 0) {
            this->client_operate->unlock();
            if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                return false;
            } else {
                cout << "ANOTHER :" << err << ":" << errno << endl;
            }
            return true;
        }
        buf.resize(recvl);
        if (recvl > 0) {
            this->message_in->insert(this->message_in->cend(), buf.begin(), buf.end());
//            cout << "recv DATA :" << recvl << endl;
            this->does(this);
        } else {
            this->client_operate->unlock();
            return true;
        }
        this->client_operate->unlock();
        return false;
    }
    return false;
}

bool SClient::part_send() {
//    cout << "send data" << endl;
    if (this->client_operate->try_lock()) {
        if (!this) {
            cout << "SClient::part_send super error no client but part send" << endl;
            return false;
        }
        vector<unsigned char> buf = *(this->message_out);

//        cout << "sending data :" << buf.size() << endl;
        if ((write(this->socket, &buf[0], buf.size())) < 0) {
            this->client_operate->unlock();
            if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                cout << "sending data error EAGAIN|EWOULDBLOCK" << buf.size() << endl;
                return false;
            }
            return true;
        }
        //        this->client_event->events = POLLIN;
        this->message_out->clear();
        if (this->tofinish) {
            close(this->socket);
        }
        this->client_operate->unlock();
        return false;
    }
}

void SClient::todo(vector<unsigned char>* request) {
    if (!this) {
//        cout << "SClient::todo Super error" << endl;
    }
//    cout << "SClient::todo" << endl;
    if (request == NULL) {
        request = this->request();
    }
//    cout << "SClient::todo push" << endl;
    this->getqueue()->push(QMessage(this, *request));
//    cout << "SClient::todo ok" << endl;
}

void SClient::finish() {
    tofinish = true;
}

void SClient::clear_request() {
    this->request()->clear();
}

SClient::SClient(int socket, SQueue* queue) {
    this->client_operate = new mutex();
    this->queue = queue;
    this->socket = socket;
    this->message_in = new vector<unsigned char>();
    this->message_out = new vector<unsigned char>();
}

SClient::SClient(const SClient& orig) {
}

SClient::~SClient() {
}