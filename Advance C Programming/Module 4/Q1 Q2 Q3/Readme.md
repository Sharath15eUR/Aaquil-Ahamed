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

# Q2: What is the use of bind() function in socket programming  ? 
After the Creation a socketfd the bind function binds the socket to the address and port number.
#### syntax
```c
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

# Q3: What is Datagram Socket ?
In socket programming, a datagram socket is a type of socket that provides a **connectionless** communication mechanism between processes running on different hosts in a network. Unlike stream sockets, which provide a reliable, bidirectional, byte-stream communication channel, datagram sockets send and receive individual messages known as **datagrams** without feedback giving more **speed** . dataram socket uses **User Datagram Protocol** (UDP)
#### Application 
Speed-centric systems like multimedia streaming and gaming.
