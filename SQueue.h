/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SQueue.h
 * Author: gorod_000
 *
 * Created on 28 августа 2016 г., 5:13
 */

#ifndef SQUEUE_H
#define SQUEUE_H
#include <queue>
#include <mutex>
#include "QMessage.h"
#include <iostream>
#include <condition_variable>
#include <system_error>
using namespace std;

class SQueue {
public:
    SQueue();
    void pop();
    void push(QMessage __x);

    SQueue operator=(SQueue qu) {
        return qu;
    };
    QMessage front();
    mutex *empty_lock;
    queue<QMessage*>* qm;
    SQueue(const SQueue& orig);
    virtual ~SQueue();
private:
    static mutex *qlock;
    mutex frontlock;
    condition_variable* cv;
};

#endif /* SQUEUE_H */

