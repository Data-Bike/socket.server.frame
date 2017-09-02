/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gorod_000
 *
 * Created on 22 августа 2016 г., 3:25
 */

#include <cstdlib>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include<arpa/inet.h> //inet_addr
#include <string.h>
#include "SocketServer.h"
#include "ClientsBox.h"
#include <vector>
#include <thread>
#include <iostream>
#include <system_error>
#include "QMessage.h"

using namespace std;

/*
 * 
 */


int ClientsBox::cbid;
int ClientsBox::max_threads;
int ClientsBox::part_lenght;
bool ClientsBox::playing;
int ClientsBox::server_socket;
int ClientsBox::timeout;

int SClient::part_length;

SClient::tdoes SClient::does;
SClient::tqrun SClient::qrun;

int SocketServer::server_id;
SocketServer* SocketServer::single_server;

//unique_lock<mutex>* SQueue::uqlock;
//mutex SQueue::empty_lock;

int main(int argc, char** argv) {
    try {
        auto ds = [ = ](SClient * client){
//            cout << "HELLO! :" << client->socket << ":" << client->request()->size() << endl;
            if (client->request()->size() > 4 && (*(client->request()->end() - 1) == 10) && (*(client->request()->end() - 2) == 13)
                    && (*(client->request()->end() - 3) == 10) && (*(client->request()->end() - 4) == 13)) {
                string str("Hello World!");
                client->todo(new vector<unsigned char>(str.begin(), str.end()));
                client->clear_request();
            }
        };
        SClient::does = ds;
        auto ms = [ = ](QMessage message){
            if (message.message.size()) {
//                cout << "Message operate size ok" << endl;
            } else {
                cout << "Message operate size fail" << endl;
            }
//            cout << "Message operate th_id:" << this_thread::get_id() << endl;
            string str("HTTP/1.1 200 OK \r\nDate : Mon, 27 Jul 2009 12 : 28 : 53 GMT\r\nServer : Apache / 2.2.14 (Win32)\r\nLast - Modified : Wed, 22 Jul 2009 19 : 15 : 56 GMT\r\nContent - Length : 6\r\nContent - Type : text / html\r\nConnection : keep-alive\r\n\r\nHELLO!");
//            cout << "Message operate create string for recv" << endl;
            vector<unsigned char> asd(str.begin(), str.end());
//            cout << "Message operate add header to string for recv" << endl;
            if (message.client) {
//                cout << "Message operate client ok" << endl;
            } else {
                cout << "Message operate client fail" << endl;
            }
            *message.client += asd;
//            cout << "Message operate ok" << endl;
            
            message.client->finish();
            return true;
        };

        cout << "MAIN:: STARTING SERVER" << endl;
        SocketServer::factory(new SParams("/socket.server.frame.conf"),
                ds, ms
                );

        cout << "MAIN:: STARTED server" << endl;
        cin.get();
        cout << "MAIN:: FINISH server" << endl;
    } catch (const std::system_error& e) {
        std::cout << "MAIN:: Caught system_error with code " << e.code()
                << " meaning " << e.what() << '\n';
    }




    //
    //    for (int j = 0; j < 10; j++) {
    //        sockaddr_in serv_addr;
    //        int sock = socket(AF_INET, SOCK_STREAM, 0);
    //        if ((sock) < 0) {
    //            exit(1);
    //        }
    //        cout << "CREATE NEW SERVER set zero serv_addr" << endl;
    //        bzero((char *) &serv_addr, sizeof (serv_addr));
    //
    //        cout << "CREATE NEW SERVER set serv_addr" << endl;
    //        string address = "127.0.0.1";
    //        string data = "hello!\r\n\r\n";
    //        char buffer[1024];
    //        serv_addr.sin_family = AF_INET;
    //        serv_addr.sin_addr.s_addr = inet_addr(address.c_str());
    //        serv_addr.sin_port = htons(9090);
    //        connect(sock, (struct sockaddr *) &serv_addr, sizeof (serv_addr));
    //
    //        send(sock, data.c_str(), strlen(data.c_str()), 0);
    //        recv(sock, buffer, sizeof (buffer), 0);
    ////        cout << buffer << endl;
    //
    //    }
    //
    //    cin.get();

    SocketServer::destroy();
    return 0;
}

