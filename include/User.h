#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>

// Enum for user roles to avoid magic strings
enum class UserRole {
    MUSICIAN,
    BAND,
    LISTENER,
    STUDENT
};

// Enum for skill levels
enum class SkillLevel {
    BEGINNER,
    INTERMEDIATE,
    EXPERT
};

class User {
public:
    //Constructors
    User(const std::string& name, const std::string& email, UserRole role);

    //Public Methods
    void displayProfile() const;
    void addInstrument(const std::string& instrument);
    void addGenre(const std::string& genre);
    void setSkillLevel(SkillLevel level);

    //Getters
    std::string getName() const;
    std::string getEmail() const;

private:
    // Private Member Variables
    // Identification
    std::string name;
    std::string email; // Used as a unique identifier
    std::string phone; // Optional
    UserRole role;

    // Collaboration
    std::vector<std::string> instrumentsPlayed;
    std::vector<std::string> genresPreferred;
    SkillLevel skillLevel;
    std::vector<std::string> bands; // Names of bands user is a part of

    // Engagement
    std::vector<std::string> likedSongs;
};

#endif // USER_H
