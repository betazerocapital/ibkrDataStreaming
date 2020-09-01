# Interactive Brokers Data Streaming
This is BetaZero Capital's code to stream market data into a local database. IBKR's API does not limit the number of data lines IBKR sends to a user per second.

# IBKR API
IBKR's main program is a trading platform called Trader Workstation (TWS). Any IBKR user can use TWS to trade on the financial markets. TWS controls user authentication and connecting to IBKR's servers to provide financial data that a user is subscribed to. IBKR provides an API for 3rd party software to access financial data and IBKR services. IBKR provides another program called IB Gateway for its API to connect to and handle user authentication. IB Gateway is a stripped down version of TWS that does not have any GUI for trading and only handles user authentication and connecting to IBKR's servers.
### Documentation and Error Codes
IBKR API's documentation can be found at https://interactivebrokers.github.io/tws-api/index.html. Error codes can be found at the same link.

# IBKR API Samples
This repository includes the IBKR API and the samples that come along with them. To run the samples, simply go into the respective samples folder in the API directory. To properly run the C++ samples, the following is required:
1. C++ compiler above C++ 11
2. IB Gateway [Most Recent] (https://www.interactivebrokers.com/en/index.php?f=5041).
3. An IB account

## Running a Simple Example
To compile the sample code, run the following:
```
cd IBJts/samples/Cpp/TestCppClient/
make
```
To run the program:
```
./TestCppClient
```
### Changing Parameters
#### Port Number
IB Gateway uses a specific port (Live Trading - 4001, Paper Trading - 4002) to communicate with any programming using the API. [Never run the API in development on a Live Trading port or account. The reason for this is straightforward: to not lose money via accidental trades.] This is designated in the Main.cpp file and can be changed to whatever IB Gateway is set to use in the IB Gateway settings.

#### Function
In the file TestCppClient.cpp, `m_state` is determines what functionality the C++ sample will showcase. `m_state` is determined in the `TestCppClient::nextValidId(OrderId orderId)` function.


# Data Streaming and Storing
The main purpose of this program is to stream financial data (trades, prices, and fundamental) into a local database for use in an automated trading environment.

# TODO:
1. Data: Research best and easiest way to store financial data.
2. Data: Implement a program to stream financial data from IBKR API
3. Data: Create a database(s) to store financial data (time series, fundamental, etc.)
4. Execution: Create a program to submit orders given a target portfolio.
5. Optional: Create a dashboard to monitor and control all programs.
6. Optional: Determine how to use LIMIT orders to minimize cost.
7. Optional: Look into stop loss orders.
8. Optional: Look into manual routing instead of using IBKR SMART routing.

# Execution
We will start with the simplest target portfolio technique: find the difference between the target and current portfolios and submit MARKET orders to correct for difference.