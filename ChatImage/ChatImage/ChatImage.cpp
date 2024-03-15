// Server.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <winsock2.h>

#define PORT 8080
#define BUFFER_SIZE 1024

#pragma comment(lib, "Ws2_32.lib")

int main() {
    WSADATA wsaData;
    SOCKET server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = { 0 };

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed\n";
        return 1;
    }

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        std::cerr << "Bind failed\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    // Listen
    if (listen(server_fd, 3) == SOCKET_ERROR) {
        std::cerr << "Listen failed\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) == INVALID_SOCKET) {
        std::cerr << "Accept failed\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    std::ofstream outfile("received_image.jpg", std::ios::binary);
    if (!outfile) {
        std::cerr << "Error: Failed to open output file\n";
        closesocket(new_socket);
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    while (true) {
        int valread = recv(new_socket, buffer, BUFFER_SIZE, 0);
        if (valread <= 0) {
            break;
        }
        outfile.write(buffer, valread);
    }

    outfile.close();
    std::cout << "Image received successfully!\n";

    // Close sockets
    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();

    return 0;
}


