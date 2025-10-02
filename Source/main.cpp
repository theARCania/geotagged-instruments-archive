#include "../include/Network.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void printHelp() {
    std::cout << "\n--- Musician Connect Terminal ---" << std::endl;
    std::cout << "Available Commands:" << std::endl;
    std::cout << "  addUser <name> <email> <role>  (role: musician, band, listener, student)" << std::endl;
    std::cout << "  showUser <email>               (Display a user's profile)" << std::endl;
    std::cout << "  allUsers                       (List all users in the network)" << std::endl;
    std::cout << "  connect <email1> <email2>      (Create a connection between two users)" << std::endl;
    std::cout << "  showConnections                (Display the connections graph)" << std::endl;
    std::cout << "  help                           (Show this help message)" << std::endl;
    std::cout << "  exit                           (Exit the application)" << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

UserRole stringToRole(const std::string& s) {
    if (s == "musician") return UserRole::MUSICIAN;
    if (s == "band") return UserRole::BAND;
    if (s == "listener") return UserRole::LISTENER;
    if (s == "student") return UserRole::STUDENT;
    return UserRole::LISTENER; // Default role
}

int main() {
    Network musicianNetwork;
    std::string line;

    printHelp();

    // Main terminal loop
    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, line);

        if (std::cin.eof() || line == "exit") {
            break;
        }

        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "addUser") {
            std::string name, email, roleStr;
            if (ss >> name >> email >> roleStr) {
                musicianNetwork.addUser(name, email, stringToRole(roleStr));
            } else {
                std::cout << "Usage: addUser <name> <email> <role>" << std::endl;
            }
        } else if (command == "showUser") {
            std::string email;
            if (ss >> email) {
                musicianNetwork.displayUserProfile(email);
            } else {
                std::cout << "Usage: showUser <email>" << std::endl;
            }
        } else if (command == "allUsers") {
            musicianNetwork.displayAllUsers();
        } else if (command == "connect") {
            std::string email1, email2;
            if (ss >> email1 >> email2) {
                musicianNetwork.createConnection(email1, email2);
            } else {
                std::cout << "Usage: connect <email1> <email2>" << std::endl;
            }
        } else if (command == "showConnections") {
            musicianNetwork.showConnections();
        } else if (command == "help") {
            printHelp();
        } else if (!command.empty()) {
            std::cout << "Unknown command: '" << command << "'. Type 'help' for a list of commands." << std::endl;
        }
    }

    std::cout << "Exiting Musician Connect. Goodbye!" << std::endl;
    return 0;
}
