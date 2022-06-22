//
// Created by dawid on 01.06.2022.
//

#ifndef CASINOGAME_GAMESERVICE_H
#define CASINOGAME_GAMESERVICE_H


#include "../Model/Game.h"
#include "../Utils/List.h"
#include "../Games/OneArmedBanditGame.h"
#include "../Games/RussianRoulette.h"
#include "../Games/BlackJack.h"


class GameService {
    private:
    List<Game> *_games;
public:
    GameService(){
        _games = new List<Game>();
        _games->AddItem(new OneArmedBanditGame());
        _games->AddItem(new RussianRoulette());
        _games->AddItem(new BlackJack());
    }

    List<Game> *GetGames(){
        return _games;
    }

    Game *GetGameById(int id){
        return _games->GetItemById(id);
    }
};


#endif //CASINOGAME_GAMESERVICE_H
