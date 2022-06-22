//
// Created by dawid on 01.06.2022.
//

#ifndef CASINOGAME_ONEARMEDBANDITGAME_H
#define CASINOGAME_ONEARMEDBANDITGAME_H


#include "../Model/Game.h"

class OneArmedBanditGame : public Game {
private:

    void Play(User *user, int bet) {
        srand(time(NULL));
        cout << "Nacisnij ENTER by zatrzymac losowanie" << endl;
        cin.ignore();
        cin.get();

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
        cout << endl;

    }

    int DrawNumber() {
        int number = 0;

        do {
            number = rand() % 7 + 1;
        } while (rand() % 200 == 0);
        return number;
    }

public:
    OneArmedBanditGame() : Game("Jednoreki bandyta", "Aby wygrać gracz musi trafić trzy takie same liczby") {}

    void Run(User *user) override {
        PrintWelcome(user);

        do {
            _bet = Bet(user);
            if (_bet > 0) {
                Play(user, _bet);
            }
            isRunning = Again(user);
        } while (isRunning);
    }

};


#endif //CASINOGAME_ONEARMEDBANDITGAME_H
