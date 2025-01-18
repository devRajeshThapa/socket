# Socket Client and Server

## Overview
This package contains the client and server executables for a simple socket communication setup.

## Getting Started

### Requirements
* Unix-based system (Linux, macOS) or WSL on Windows
* Basic understanding of terminal commands

### Installation
1. **Download and extract** the `dist` package to a desired location.
2. **Navigate to the `bin` directory** within the extracted package.
    ```sh
    cd /path/to/dist/bin
    ```

## Usage

### Starting the Server
1. Open a terminal and navigate to the directory where `server` is located.
    ```sh
    cd /path/to/dist/bin
    ```

2. Run the server executable:
    ```sh
    ./server
    ```

3. Enter the port number you want the server to listen to, for example:
    ```sh
    Enter the PORT you want to listen: 8080
    ```
    The server will start listening for incoming connections.

### Starting the Client
1. Open another terminal and navigate to the directory where `client` is located.
    ```sh
    cd /path/to/dist/bin
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

## Example

1. **Server Terminal**:
    ```sh
    Server is listening on port 8080
    Message from client: Hello server
    ```

2. **Client Terminal**:
    ```sh
    Enter server IP: 127.0.0.1
    Enter server PORT: 8080
    Message for client: Hello server
    ```

## Notes
* Ensure the server is running before starting the client.
* If you're using a firewall, make sure to allow traffic on the specified port.

## Troubleshooting
* **Connection issues**: Verify the server IP address and port. Ensure the server is running.
* **Permission errors**: Make sure the executables have the correct permissions using `chmod +x ./server` and `chmod +x ./client`.

## Source Code and Contributions
For the source code and contribution guidelines, visit the [GitHub repository](https://github.com/devRajeshThapa/socket).

