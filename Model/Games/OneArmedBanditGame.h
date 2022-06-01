//
// Created by dawid on 01.06.2022.
//

#ifndef CASINOGAME_ONEARMEDBANDITGAME_H
#define CASINOGAME_ONEARMEDBANDITGAME_H


#include "../Game.h"

class OneArmedBanditGame : public Game {
private:

    void PrintWelcome(User *_user) {
        cout << "Witaj w grze " << _user->GetNick() << endl;
        cout << "Masz do dyspozycji " << _user->GetMoney() << " kredytow." << endl;
        cout << "Powodzenia!" << endl;
        cout << endl;
    }

    int Bet(User *_user) {
        int bet = 0;
        cout << "Jaka kwote chcesz obstawic(min:1, max: " << _user->GetMoney() << "?" << endl;
        cin >> bet;
        if (_user->hasEnoughMoney(bet)) {
            _user->MinusMoney(bet);
            cout << "Obstawiles " << bet << endl;
            return bet;
        }
        cout << "Nie masz wystarczajaco pieniedzy zeby obstawic " << bet << endl;
        cout << endl;
        return 0;
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

    void Play(User *user, int bet) {
        srand(time(NULL));
        int number1 = DrawNumber();
        int number2 = DrawNumber();
        int number3 = DrawNumber();
        cout << number1 << "\t" << number2 << "\t" << number3 << endl;
        cout << endl;

        if (number1 == number2 && number1 == number3 && number2 == number3) {
            int prize = bet * number1 * 1.5;
            cout << "Brawo wygrales: " << prize << endl;
            user->AddMoney(prize);
        } else {
            cout << "Tym razem sie nie udalo" << endl;
        }
        cout<<endl;
    }
    int DrawNumber(){
        int number = 0;

        do{
            number = rand() % 7 + 1;
        }while(rand()%200 == 0);
        return number;
    }

public:
    OneArmedBanditGame() : Game("Jednoreki bandyta", "Aby wygrać gracz musi trafić trzy takie same liczby") {}

    void Run(User *user) {
        int _bet = 0;
        bool isRunning = true;
        PrintWelcome(user);

        do {
            _bet = Bet(user);
            Play(user,_bet);
            isRunning = Again(user);
        } while (isRunning);
    }

};


#endif //CASINOGAME_ONEARMEDBANDITGAME_H
