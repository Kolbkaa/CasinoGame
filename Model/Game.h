//
// Created by dawid on 15.04.2022.
//

#ifndef CASINOGAME_GAME_H
#define CASINOGAME_GAME_H

#include "string"

using namespace std;

class Game {
private:
    string _title;
    string _description;
public:
    Game(string title, string description);
    string GetTitle();

};


#endif //CASINOGAME_GAME_H
