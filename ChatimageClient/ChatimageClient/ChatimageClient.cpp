// Client.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsaData;
    SOCKET sock = INVALID_SOCKET;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = { 0 };

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed\n";
        return -1;
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cerr << "Socket creation error\n";
        WSACleanup();
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "192.168.2.20", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported\n";
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        std::cerr << "Connection Failed\n";
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    // Read image file
    std::ifstream infile("smile.jpg", std::ios::binary);
    if (!infile) {
        std::cerr << "Error: Failed to open input file\n";
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    while (!infile.eof()) {
        infile.read(buffer, BUFFER_SIZE);
        send(sock, buffer, infile.gcount(), 0);
    }

    infile.close();
    std::cout << "Image sent successfully!\n";

    // Cleanup
    closesocket(sock);
    WSACleanup();

    return 0;
}

