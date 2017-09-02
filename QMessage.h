/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QMessage.h
 * Author: gorod_000
 *
 * Created on 28 августа 2016 г., 5:21
 */

#ifndef QMESSAGE_H
#define QMESSAGE_H

#include <vector>
#include <iostream>
using namespace std;

class SClient;

class QMessage {
public:
    QMessage(SClient* client, vector<unsigned char> message);
    QMessage(const QMessage& orig);
    SClient* client;
    vector<unsigned char> message;
    virtual ~QMessage();
private:

};

#endif /* QMESSAGE_H */

