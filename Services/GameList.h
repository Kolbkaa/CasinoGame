//
// Created by dawid on 15.04.2022.
//

#ifndef CASINOGAME_GAMELIST_H
#define CASINOGAME_GAMELIST_H


#include "../Model/GameListElement.h"

class GameList {
private:
    GameListElement* _gameElement;
    int _length = 0;
public:
    int AddGame(Game * game);
    Game* GetGameById(int id);
    void Clear();

};


#endif //CASINOGAME_GAMELIST_H
