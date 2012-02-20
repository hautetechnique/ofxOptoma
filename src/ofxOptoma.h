/*
 *  ofxOptoma.h
 *  openFrameworks
 *
 *  Created by Sander ter Braak on 20-02-12.
 *
 */

#ifndef _OFX_OPTOMA_
#define _OFX_OPTOMA_

#include "ofxNetwork.h"

class ofxOptoma {
	
	public:
	
		void power_on(string ip);
        void power_off(string ip);
		
		
	private:
    
    void send(string command, string ip);
		
        ofxTCPClient connection;
	
	
};

#endif



