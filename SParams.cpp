/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SParams.cpp
 * Author: gorod_000
 * 
 * Created on 18 августа 2016 г., 3:00
 */


#include "SParams.h"

SParams::SParams(string filename) {
    string STRING, key, value;
    ifstream infile;
    char str [1024];
    infile.open(filename);
    cout << (infile.good() ? "CONFIG FILE GOOD" : "CONFIG FILE BAD") << endl;
    while (!infile.eof()) {

        infile.getline(&str[0], 1024);
        stringstream ss(str);
        getline(ss, key, '=');
        getline(ss, value, '=');
        key.erase(key.begin(), find_if(key.begin(), key.end(),
                not1(ptr_fun<int, int>(isspace))));
        key.erase(find_if(key.rbegin(), key.rend(),
                not1(ptr_fun<int, int>(isspace))).base(), key.end());
        value.erase(value.begin(), find_if(value.begin(), value.end(),
                not1(ptr_fun<int, int>(isspace))));
        value.erase(find_if(value.rbegin(), value.rend(),
                not1(ptr_fun<int, int>(isspace))).base(), value.end());
        this->params.insert(pair<string, string>(key, value));
        cout <<  "::" << key << ":" << value << "\r\n";
    }

}

SParams::SParams(const SParams& orig) {
}

int SParams::getInt(string key) {
    return atoi(this->params[key].c_str());
}

SParams::~SParams() {
}

