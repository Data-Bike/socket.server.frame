/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QMessage.cpp
 * Author: gorod_000
 * 
 * Created on 28 августа 2016 г., 5:21
 */

#include "QMessage.h"
#include "SClient.h"

QMessage::QMessage(SClient* client, vector<unsigned char> message) {
    this->client = client;
    this->message = message;
//    cout << "NEW MESSAGE" << endl;
//    cout << "NEW MESSAGE size: " << message.size() << endl;
//    cout << "NEW MESSAGE client: " << (client->request()->size()) << endl;
}

QMessage::QMessage(const QMessage& orig) {
    this->client = orig.client;
    this->message = orig.message;
}

QMessage::~QMessage() {
}

