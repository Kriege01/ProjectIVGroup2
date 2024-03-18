#include "UserAuthentication.h"

// Assuming a small, fixed number of maximum users for demonstration purposes.
const int MAX_USERS = 100;
User users[MAX_USERS];
int userCount = 0;
// Function to register a new user.
bool registerUser(const std::string& username, const std::string& password) {
    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == username) {
            std::cout << "Username already exists!\n";
            return false;
        }
    }
    if (userCount < MAX_USERS) {
        users[userCount++] = { username, password };
        std::cout << "User registered successfully!\n";
        return true;
    }
    else {
        std::cout << "User limit reached. Cannot register more users.\n";
        return false;
    }
}

// Function for user login.
bool loginUser(const std::string& username, const std::string& password) {
    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == username) {
            if (users[i].password == password) {
                std::cout << "Password correct. User logged in!\n";
                return true;
            }
            else {
                std::cout << "Incorrect password.\n";
            }
            return false;
        }
    }
    std::cout << "Username does not exist.\n";
    return false;
}