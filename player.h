#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player();
    Player(const std::string& name, int id);
    std::string getName() const;
    int getId() const;
private:
    std::string name;
    int id;
};

#endif
