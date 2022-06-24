//
// Created by dawid on 16.04.2022.
//

#ifndef CASINOGAME_USER_H
#define CASINOGAME_USER_H

#include "string"

using namespace std;

class User {
private:
    string _nick;
    float _money;

public:
    string GetNick() {
        return _nick;
    }

    float GetMoney() {
        return _money;
    }

    User(string nick, float money) {
        _nick = nick;
        _money = money;
    }

    User(string nick) {
        _nick = nick;
        _money = 100;
    }

    User() {}

    float AddMoney(float moneyToAdd) {
        return _money += moneyToAdd;
    }

    float MinusMoney(float moneyToMinus) {
        return _money -= moneyToMinus;
    }
    bool hasEnoughMoney(float money){
        return _money >= money;
    }
};


#endif //CASINOGAME_USER_H
