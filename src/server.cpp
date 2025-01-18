#include <iostream>
#include <sstream>         // For std::ostringstream
#include <unistd.h>        // For close() function
#include <arpa/inet.h>     // For inet_addr(), htons(), etc.
#include <sys/socket.h>    // For socket functions
#include <netinet/in.h>    // For sockaddr_in
#include <cstring>         // For memset function
#include <cerrno>          // For errno

int main() {
    int PORT;
    std::cout << "Enter the port number you want to listen on: ";
    std::cin >> PORT;

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Socket creation failed: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind failed: " << strerror(errno) << std::endl;
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed: " << strerror(errno) << std::endl;
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    while (true) {
        int client_fd = accept(server_fd, nullptr, nullptr);
        if (client_fd < 0) {
            std::cerr << "Accept failed: " << strerror(errno) << std::endl;
            close(server_fd);
            exit(EXIT_FAILURE);
        }

        char buffer[1024] = {0};
        int bytes_read = recv(client_fd, buffer, sizeof(buffer), 0);
        if (bytes_read > 0) {
            std::cout << "Message from client: " << buffer << std::endl;
        } else if (bytes_read < 0) {
            std::cerr << "Receive failed: " << strerror(errno) << std::endl;
        }

        std::ostringstream oss;
        oss << "You had successfully connected to the server on PORT " << PORT;
        std::string message = oss.str();
        
        send(client_fd, message.c_str(), message.length(), 0);
        close(client_fd);
    }

    close(server_fd);
    return 0;
}

