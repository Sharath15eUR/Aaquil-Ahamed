# Q1: Explain the connection procedure followed in client server communication

### Steps to followed in the server side
1) creation of server Socket file discriptor using **socket function**
2) bind logical address to socetfd using **bind function**
3) make the socket to open to listening use **listen function**
4) accept incoming requests from clients using **accept function**
5) Read/Write between server and client
6) close the sockets 

### Steps to be followed in Client side 
1) creation of client Socket file discriptor using **socket function**
2) connect client socket to server address using **connect function**
3) Read/Write between server and client
4) close the sockets

![images](https://github.com/Sharath15eUR/Aaquil-Ahamed/assets/88236255/a7331063-91c1-4890-ac18-39e7ac4577f5)
