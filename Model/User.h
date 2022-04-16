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
    int _money;

public:
    string GetNick(){
        return _nick;
    }
    int GetMoney(){
        return _money;
    }
    User(string nick, int money) {
        _nick = nick;
        _money = money;
    }
    User(string nick) {
        _nick = nick;
        _money = 10000;
    }
};


#endif //CASINOGAME_USER_H
