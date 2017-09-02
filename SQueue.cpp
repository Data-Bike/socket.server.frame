/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SQueue.cpp
 * Author: gorod_000
 * 
 * Created on 28 августа 2016 г., 5:13
 */

#include "SQueue.h"

mutex *SQueue::qlock;

SQueue::SQueue() {
    cout << "SQueue::SQueue() : queue()" << endl;
    this->cv = new condition_variable();
    this->empty_lock = new mutex();
    this->qlock = new mutex();
    this->qm = new queue<QMessage*>();
    this->qlock->unlock();
}

SQueue::SQueue(const SQueue& orig) {
}

void SQueue::pop() {
//    cout << "SQueue::pop" << endl;
//    lock_guard<mutex> lock(*this->qlock);
//    cout << "SQueue::lock queue locked" << endl;
    this->qm->pop();
//    cout << "SQueue::pop popped" << endl;
    if (this->qm->empty()) {
//        cout << "SQueue::pop empty locked" << endl;

        this->cv->notify_all();
    } else {
//        cout << "SQueue::pop empty non-locked" << endl;
    }
//    cout << "SQueue::pop ok" << endl;

}

void SQueue::push(QMessage __x) {
//    cout << "SQueue::push" << endl;

//    cout << "SQueue::push msg client " << (__x.client ? "OK" : "FAIL") << endl;
//    cout << "SQueue::push msg size " << (__x.message.size() ? "OK" : "FAIL") << endl;
//    cout << "SQueue::push wait lock qm->size: " << this->qm->size() << endl;
    lock_guard<mutex> lock(*this->qlock);
//    cout << "SQueue::push queue locked" << endl;
    this->qm->push(new QMessage(__x));
//    cout << "SQueue::push pushed :" << this->qm->size() << endl;
    this->cv->notify_one();

//    cout << "SQueue::push empty unlocked" << endl;
}

QMessage SQueue::front() {
    try {
        mutex m;
        unique_lock<mutex> lk(*empty_lock);
//        cout << "SQueue::front" << endl;
        this->cv->wait(lk, [this]() {
//            cout << "SQueue::front to wait size is: " << this->qm->size() << endl;
            return (this->qm && !this->qm->empty());
        });
        lock_guard<mutex> lock(*this->qlock);
        QMessage msg = *this->qm->front();
        this->pop();

//        cout << "SQueue::front msg client " << (msg.client ? "OK" : "FAIL") << endl;
//        cout << "SQueue::front msg size " << (msg.message.size() ? "OK" : "FAIL") << endl;
//        cout << "SQueue::front ok" << endl;
//        cout << "SQueue::front to wait size is: " << this->qm->size() << endl;
        //    cout << "SQueue::front msg: " << msg.message.data() << endl;

        return msg;
    } catch (const std::system_error& e) {
        std::cout << "SQueue:: Caught system_error with code " << e.code()
                << " meaning " << e.what() << '\n';

    }
}

SQueue::~SQueue() {
}

