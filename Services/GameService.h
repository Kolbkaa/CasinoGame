//
// Created by dawid on 01.06.2022.
//

#ifndef CASINOGAME_GAMESERVICE_H
#define CASINOGAME_GAMESERVICE_H


#include "../Model/Game.h"
#include "../Utils/List.h"
#include "../Model/Games/OneArmedBanditGame.h"


class GameService {
    private:
    List<Game> *_games;
public:
    GameService(){
        _games = new List<Game>();
        _games->AddItem(new OneArmedBanditGame());
    }

    List<Game> *GetGames(){
        return _games;
    }

    Game *GetGameById(int id){
        return _games->GetItemById(id);
    }
};


#endif //CASINOGAME_GAMESERVICE_H
