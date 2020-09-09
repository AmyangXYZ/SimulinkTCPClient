# SimulinkTCPClient

 Customized TCP/IP Client block for Simulink, supports Rapid Accerlater mode!

## Getting start

### Install MinGW

Follow this instruction: https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites.

You also need to install the Matlab library: Mingw-w64 compiler

### Compile and run the test server

`gcc .\server_test.c -lws2_32 -o server_test.exe`

`.\server_test.exe`

### Run the model

Open c_simulink.slx and run.