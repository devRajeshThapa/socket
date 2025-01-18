# Socket Client and Server

## Overview
This project demonstrates a basic implementation of client-server communication using sockets in C++. The server listens for incoming connections and exchanges messages with the client.

## Features
- Simple client-server messaging
- Multi-client handling (server)
- Comprehensive example included

## Getting Started

### Requirements
* C++11 (or later) compiler
* CMake 3.10+
* Unix-based system (Linux, macOS) or WSL on Windows

### Installation

1. **Clone the repository**:
    ```sh
    git clone https://github.com/devrajeshthapa/socket.git
    cd socket
    ```

2. **Build the project using CMake**:
    ```sh
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```

3. **Install the executables**:
    ```sh
    cmake --install . --prefix ../dist
    ```

### Usage

#### Starting the Server
1. Open a terminal and navigate to the `dist/bin` directory:
    ```sh
    cd /path/to/socket/dist/bin
    ```

2. Run the server executable:
    ```sh
    ./server
    ```

3. Enter the port number you want the server to listen on:
    ```sh
    Enter the PORT you want to listen: 8080
    ```
    The server will start listening for incoming connections.

#### Starting the Client
1. Open another terminal and navigate to the `dist/bin` directory:
    ```sh
    cd /path/to/socket/dist/bin
    ```

2. Run the client executable:
    ```sh
    ./client
    ```

3. Follow the prompts to enter the server's IP address and port number:
    ```sh
    Enter server IP: 127.0.0.1
    Enter server PORT: 8080
    ```

4. Enter the message you want to send to the server:
    ```sh
    Message for server: Hello server
    ```
    The client will connect to the server and send the message. You'll see responses on both the client and server terminals.

### Example Interaction

#### Server Terminal
```sh
Server is listening on port 8080
Message from client: Hello server
```

#### Client Terminal
```sh
Enter server IP: 127.0.0.1
Enter server PORT: 8080
Message for server: Hello server
```

### Contributing

We welcome contributions! Please see CONTRIBUTING.md for details on how to get involved.

###License

This project is licensed under the MIT License. See the LICENSE file for details.

### Code of Conduct

Please read our Code of Conduct to understand the standards we expect from our community.

### Acknowledgements

This implementation demonstrates basic socket programming in C++ using Unix APIs. Inspired by various online resources and tutorials on socket programming.
