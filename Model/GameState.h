//
// Created by dawid on 31.05.2022.
//

#ifndef CASINOGAME_GAMESTATE_H
#define CASINOGAME_GAMESTATE_H


#include "User.h"

class GameState {
public:
    GameState(){
        _isRunning = true;
    }

    void SetUser(User *user) {
        _user = user;
    }

    User* GetUser(){
        return _user;
    }
    void StopGame(){
        _isRunning = false;
    }
    bool IsRunning(){
        return _isRunning;
    }

private:
    User *_user = NULL;
    bool _isRunning;
};


#endif //CASINOGAME_GAMESTATE_H
