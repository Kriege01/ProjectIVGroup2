#pragma once

#include <string>

//Protocols

const std::string USER_REGISTER = "USER_REGISTER"; // username:password
const std::string USER_LOGIN = "USER_LOGIN"; // username:password
const std::string USER_LOGOUT = "USER_LOGOUT"; // username
const std::string AUTH_SUCCESS = "AUTH_SUCCESS";
const std::string AUTH_FAILURE = "AUTH_FAILURE";
const std::string MENU_SELECTION = "MENU_SELECTION";
const std::string TIC_TAC_TOE_MOVE = "TIC_TAC_TOE_MOVE";
const std::string TIC_TAC_TOE_STATE_UPDATE = "TIC_TAC_TOE_STATE_UPDATE";
const std::string CHECKERS_MOVE = "CHECKERS_MOVE";
const std::string CHECKERS_STATE_UPDATE = "CHECKERS_STATE_UPDATE";
const std::string GAME_START_SIGNAL = "GAME_START_SIGNAL";
const std::string GAME_OVER = "GAME_OVER";
const std::string CHAT_MESSAGE = "CHAT_MESSAGE";