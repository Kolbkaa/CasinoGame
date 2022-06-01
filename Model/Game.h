//
// Created by dawid on 15.04.2022.
//

#ifndef CASINOGAME_GAME_H
#define CASINOGAME_GAME_H

#include "string"
#include "GameState.h"

using namespace std;

class Game {
private:
    string _title;
    string _description;
public:
    Game(string title, string description) {
        _title = title;
        _description = description;
    }

    string GetTitle() {
        return _title;
    }

    virtual void Run(User *user) {

    }

};


#endif //CASINOGAME_GAME_H
