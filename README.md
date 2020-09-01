# Interactive Brokers Data Streaming
This is BetaZero Capital's code to stream market data into a local database. IBKR's API does not limit the number of data lines IBKR sends to a user per second.

# IBKR API Samples
This repository includes the IBKR API and the samples that come along with them. To run the samples, simply go into the respective samples folder in the API directory. To properly run the C++ samples, the following is required:
1. C++ compiler above C++ 11
2. IB Gateway Most Recent (https://www.interactivebrokers.com/en/index.php?f=5041).
3. An IB account

## Running a Simple Example
With the requirements above, to run a C++ sample, follow these instructions:
'''
cd IBJts/samples/Cpp/TestCppClient/
make
./TestCppClient
'''
### Changing Parameters
#### Port Number
IB Gateway uses a specific port (Live Trading - 4001, Paper Trading - 4002). This is designated in the Main.cpp file and can be changed to whatever IB Gateway is set to use in the IB Gateway settings.

#### Function
In the file TestCppClient.cpp, 'm_state' is determines what functionality the C++ sample will showcase. 'm_state' is determined in the 'TestCppClient::nextValidId( OrderId orderId)' function.
