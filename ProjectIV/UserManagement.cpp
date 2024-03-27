#include "UserManagement.h"

bool UserManager::registerUser(const std::string& username, const std::string& password) {
    if (userCredentials.find(username) != userCredentials.end()) {
        // User already exists
        return false;
    }
    userCredentials[username] = password;
    return true;
}

bool UserManager::loginUser(const std::string& username, const std::string& password) {
    auto it = userCredentials.find(username);
    if (it != userCredentials.end() && it->second == password) {
        loggedInUsers.insert(username);
        return true;
    }
    return false;
}

void UserManager::logoutUser(const std::string& username) {
    loggedInUsers.erase(username);
}

bool UserManager::isUserLoggedIn(const std::string& username) const {
    return loggedInUsers.find(username) != loggedInUsers.end();
}
