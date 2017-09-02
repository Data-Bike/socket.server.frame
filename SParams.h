/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SParams.h
 * Author: gorod_000
 *
 * Created on 18 августа 2016 г., 3:00
 */

#ifndef SPARAMS_H
#define SPARAMS_H
#include <string>
#include <fstream>
#include <algorithm> 
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

class SParams {
public:
    SParams(string filename);
    SParams(const SParams& orig);
    int getInt(string key);
    map<string, string> params;
    int threads_count;
    int port;
    int part_length;
    int max_clients;
    int socket;
    int timeout;
    virtual ~SParams();
private:

};

#endif /* SPARAMS_H */

