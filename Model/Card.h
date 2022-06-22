//
// Created by dawid on 20.06.2022.
//

#ifndef CASINOGAME_CARD_H
#define CASINOGAME_CARD_H

#include "string"

using namespace std;

class Card {
private:
    string _name;
    int _value;
public:
    string GetName() {
        return _name;
    }

    int GetValue() {
        return _value;
    }

    Card(string name, int value) {
        _name = name;
        _value = value;
    }


};


#endif //CASINOGAME_CARD_H
