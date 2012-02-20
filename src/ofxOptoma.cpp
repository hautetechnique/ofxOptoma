/*
 *  ofxOptoma.cpp
 *  openFrameworks
 *
 *  Created by Sander ter Braak on 20-02-12.
 *
 */

#include "ofxOptoma.h"


void ofxOptoma::power_on(string ip){
    send("on\n", ip);
    
}

void ofxOptoma::power_off(string ip){
    send("off\n", ip);
}

void ofxOptoma::send(string command, string ip){
    connection.setup(ip, 23);
    int bytesRecieved = 0;
    
    string msgRx1;
    string msgRx2;
    
    while (msgRx1.length() < 8) 
    {
        msgRx1 = connection.receiveRaw();	
        if(msgRx1.length() > 6)
        {	
            cout<< msgRx1 << endl;
        }	
    }
    cout << "sending command: " << command << endl; 
    
    connection.sendRaw(command);
    
    
    msgRx2 = msgRx1;
    while (msgRx1 == msgRx2) 
    {
        // new message!
        msgRx2 = connection.receiveRaw();	
    }
    cout << "---------" << endl;
    cout<< msgRx2 << endl;
    cout << "---------" << endl;   
    connection.close();
}