#include <iostream>
#include <unistd.h>         // For close() function
#include <arpa/inet.h>      // For inet_addr(), htons(), etc.
#include <sys/socket.h>     // For socket functions
#include <netinet/in.h>     // For sockaddr_in
#include <cstring>          // For memset function
#include <cerrno>           // For errno
#include <limits>           // For std::numeric_limits

#define PORT 8080

int main() {
    char server_ip[INET_ADDRSTRLEN];
    int server_port;
    char message[1024];

    std::cout << "Enter server IP: ";
    std::cin >> server_ip;

    std::cout << "Enter server PORT: ";
    std::cin >> server_port;
    std::cin.ignore();  // Ignore leftover newline from previous input

    std::cout << "Message for server: ";
    std::cin.getline(message, 1024);  // Read the entire line into message

    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        std::cerr << "Socket creation failed: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));  // Initialize server_addr to zero
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported: " << strerror(errno) << " (" << errno << ")" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connection failed: " << strerror(errno) << " (" << errno << ")" << std::endl;
        close(client_fd);  // Close client_fd before exiting
        exit(EXIT_FAILURE);
    }

    send(client_fd, message, strlen(message), 0);

    char buffer[1024] = {0};
    int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        std::cout << "Message from server: " << buffer << std::endl;
    } else if (bytes_received < 0) {
        std::cerr << "Receive failed: " << strerror(errno) << std::endl;
    }

    close(client_fd);
    return 0;
}

