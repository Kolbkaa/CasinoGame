//
// Created by dawid on 15.04.2022.
//

#ifndef CASINOGAME_GAME_H
#define CASINOGAME_GAME_H

#include "string"
#include "GameState.h"
#include "../UI/UI.h"

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

protected:
    int _bet = 0;
    bool isRunning = true;


    void PrintWelcome(User *_user) {
        cout << "Witaj w grze " << _user->GetNick() << endl;
        cout << "Masz do dyspozycji " << _user->GetMoney() << " kredytow." << endl;
        cout << "Powodzenia!" << endl;
        cout << endl;
    }

    bool Again(User *_user) {
        if (_user->GetMoney() == 0) {
            cout << "Nie masz już pieniędzy. Dziękujemy za grę." << endl;
            return false;
        }
        cout << "Czy chcesz zagrac jeszcze raz? (T)";

        string choose;
        cin >> choose;

        if (choose == "T" || choose == "t") {
            return true;
        }
        return false;
    }

    int Bet(User *_user) {
        int bet = 0;
        cout << "Jaka kwote chcesz obstawic(min:1, max: " << _user->GetMoney() << ")?" << endl;
        UI::GetUserIntInput(bet);
        if (bet <= 0) {
            cout << "Musisz obstawic jakas kwote" << endl;
            return 0;
        }

        if (_user->hasEnoughMoney(bet)) {
            _user->MinusMoney(bet);
            cout << "Obstawiles " << bet << endl;
            return bet;
        }
        cout << "Nie masz wystarczajaco pieniedzy zeby obstawic " << bet << endl;
        cout << endl;
        return 0;
    }

};


#endif //CASINOGAME_GAME_H
