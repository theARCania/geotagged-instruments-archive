#ifndef NETWORK_H
#define NETWORK_H

#include "User.h"
#include "Graph.h"
#include <vector>
#include <string>
#include <optional>

// The Network class manages all users and their connections.
// It acts as the main database and logic handler for the application.
class Network {
public:
    Network(); // Constructor

    // --- User Management ---
    void addUser(const std::string& name, const std::string& email, UserRole role);
    void displayUserProfile(const std::string& email) const;
    void displayAllUsers() const;

    // --- Connection Management ---
    void createConnection(const std::string& email1, const std::string& email2);
    void showConnections() const;
    
    // --- Search & Filtering ---
    void findMusiciansByInstrument(const std::string& instrument) const;


private:
    std::vector<User> users;
    // A unique graph for user connections. The integer in the graph will correspond
    // to the index of the user in the `users` vector.
    Graph userConnections;

    // Helper function to find a user's index by their email.
    // std::optional is used to safely handle cases where the user is not found.
    std::optional<int> findUserIndexByEmail(const std::string& email) const;
};

#endif // NETWORK_H
