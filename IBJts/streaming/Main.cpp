/* Copyright (C) 2019 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

// #include "StdAfx.h"

#include <stdio.h>
#include <stdlib.h>

#include <chrono>
#include <thread>
#include <iostream>

#include "Client.h"

const unsigned MAX_ATTEMPTS = 10;
const unsigned SLEEP_TIME = 1;
const unsigned PORT = 4002;

/* IMPORTANT: always use your paper trading account. The code below will submit orders as part of the demonstration. */
/* IB will not be responsible for accidental executions on your live account. */
/* Any stock or option symbols displayed are for illustrative purposes only and are not intended to portray a recommendation. */
/* Before contacting our API support team please refer to the available documentation. */
int main(int argc, char** argv)
{
	const char* host = argc > 1 ? argv[1] : "";
	int port = argc > 2 ? atoi(argv[2]) : 0;
	if (port <= 0)
		port = PORT;
	const char* connectOptions = argc > 3 ? argv[3] : "";
	int clientId = 0;

	unsigned attempt = 0;
    std::cout << "Starting C++ Data Streaming" << std::endl;

	while(true) {
		attempt++;
        std::cout << "Attempt " << attempt << " of " << MAX_ATTEMPTS << std::endl;

		// TestCppClient client;

		// Run time error will occur (here) if TestCppClient.exe is compiled in debug mode but TwsSocketClient.dll is compiled in Release mode
		// TwsSocketClient.dll (in Release Mode) is copied by API installer into SysWOW64 folder within Windows directory 
		
		// if(connectOptions) {
		// 	client.setConnectOptions( connectOptions);
		// }
		
		// client.connect(host, port, clientId);
		
		// while(client.isConnected()) {
		// 	client.processMessages();
		// }

		if(attempt >= MAX_ATTEMPTS) {
			break;
		}

		printf( "Sleeping %u seconds before next attempt\n", SLEEP_TIME);
		std::this_thread::sleep_for(std::chrono::seconds(SLEEP_TIME));
	}

	printf ( "End of C++ Socket Client Test\n");
}

