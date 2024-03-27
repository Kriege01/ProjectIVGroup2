#pragma once
#include <unordered_map>
#include <set>
#include <string>

class UserManager {
public:
    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
    void logoutUser(const std::string& username);
    bool isUserLoggedIn(const std::string& username) const;

private:
    std::unordered_map<std::string, std::string> userCredentials; // Stores username -> password
    std::set<std::string> loggedInUsers; // Tracks logged in users
};
