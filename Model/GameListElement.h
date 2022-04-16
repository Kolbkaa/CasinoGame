//
// Created by dawid on 15.04.2022.
//

#ifndef CASINOGAME_GAMELISTELEMENT_H
#define CASINOGAME_GAMELISTELEMENT_H


#include "Game.h"

class GameListElement {
private:
    Game *_game;
    GameListElement* _nextElement = 0;

public:
    GameListElement(Game* game);
    Game* GetGame();
    bool IsNextElement();
    GameListElement* GetNextElement();
    void SetNextElement(GameListElement* nextElement);

};


#endif //CASINOGAME_GAMELISTELEMENT_H
