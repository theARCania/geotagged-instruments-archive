#include "../include/Network.h"

// Initialize the network with a user connection graph capable of holding 100 users initially.
// This can be made dynamic in a more advanced implementation.
Network::Network() : userConnections(100) {}

std::optional<int> Network::findUserIndexByEmail(const std::string& email) const {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].getEmail() == email) {
            return i; // Return the index if found
        }
    }
    return std::nullopt; // Return an empty optional if not found
}

void Network::addUser(const std::string& name, const std::string& email, UserRole role) {
    if (findUserIndexByEmail(email)) {
        std::cout << "Error: User with email " << email << " already exists." << std::endl;
        return;
    }
    // For simplicity, we assume the number of users won't exceed the graph's initial capacity.
    if (users.size() >= 100) {
        std::cout << "Error: Maximum number of users reached." << std::endl;
        return;
    }
    users.emplace_back(name, email, role);
    std::cout << "User '" << name << "' added successfully." << std::endl;
}

void Network::displayUserProfile(const std::string& email) const {
    auto indexOpt = findUserIndexByEmail(email);
    if (indexOpt) {
        users[*indexOpt].displayProfile();
    } else {
        std::cout << "Error: User with email " << email << " not found." << std::endl;
    }
}

void Network::displayAllUsers() const {
    if (users.empty()) {
        std::cout << "No users in the network." << std::endl;
        return;
    }
    std::cout << "\n--- All Users in Network ---" << std::endl;
    for (const auto& user : users) {
        std::cout << "- " << user.getName() << " (" << user.getEmail() << ")" << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}


void Network::createConnection(const std::string& email1, const std::string& email2) {
    auto index1_opt = findUserIndexByEmail(email1);
    auto index2_opt = findUserIndexByEmail(email2);

    if (index1_opt && index2_opt) {
        userConnections.addEdge(*index1_opt, *index2_opt);
        std::cout << "Connection created between " << users[*index1_opt].getName() 
                  << " and " << users[*index2_opt].getName() << "." << std::endl;
    } else {
        if (!index1_opt) std::cout << "Error: User " << email1 << " not found." << std::endl;
        if (!index2_opt) std::cout << "Error: User " << email2 << " not found." << std::endl;
    }
}

void Network::showConnections() const {
    std::cout << "\n--- User Connections Graph ---" << std::endl;
    for(size_t i = 0; i < users.size(); ++i) {
        std::cout << "User: " << users[i].getName() << " (ID: " << i << ")" << std::endl;
    }
     userConnections.printGraph();
}

void Network::findMusiciansByInstrument(const std::string& instrument) const {
    std::cout << "\nSearching for musicians who play " << instrument << "..." << std::endl;
    std::cout << "(Feature not fully implemented)" << std::endl;
}
