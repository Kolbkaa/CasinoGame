//
// Created by dawid on 20.06.2022.
//

#ifndef CASINOGAME_RUSSIANROULETTE_H
#define CASINOGAME_RUSSIANROULETTE_H


#include "../Model/Game.h"

class RussianRoulette : public Game {
public:
    RussianRoulette() : Game("Rosyjska ruletka", "Wygrywaj albo gin") {}

    void Run(User *user) override {
        PrintWelcome(user);
        cout << "W tej grze mozesz duzo wygrac. Mnozymy Twoje pieniadze razy 100, ale jest szansa 1 na 7 ze zginiesz."
             << endl;
        cout << "Jezeli chcesz sie jeszcze wycowac, wpisz T" << endl;

        string choose;
        cin >> choose;

        if (choose == "T" || choose == "t") {
            return;
        }
        cout << "Do odwaznych swiat nalezy" << endl;

        do {
            _bet = Bet(user);
            if (_bet > 0) {
                if (!Play(user, _bet)) {
                    return;
                }
            }
            isRunning = Again(user);
        } while (isRunning);

    }

private:
    bool Play(User *user, int bet) {
        srand(time(NULL));
        bool isLoaded = false;
        int bulletPosition = 0;

        do {
            cout << "Zaladuj naboj do komory. Od 1 do 7" << endl;
            UI::GetUserIntInput(bulletPosition);

            if (bulletPosition < 1 || bulletPosition > 7) {
                cout << "Wybierz odpowiedni mniejsce w rewolwerze" << endl;
            } else {
                isLoaded = true;
            }

        } while (isLoaded != true);

        int positionToMatch = (rand() % 7) + 1;

        cout << "Nacisnij ENTER aby pociagnac za spust!" << endl;
        cin.ignore();
        cin.get();

        if (positionToMatch == bulletPosition) {
            cout << "Bumm !!! Giniesz. Twoje pieniadze przepadaja" << endl;
            user->MinusMoney(user->GetMoney());
            return false;
        }
        cout << "Tym razem Ci sie udalo. Wygrywasz " << _bet * 100 << endl;
        user->AddMoney(_bet * 100);
        return true;
    }

};


#endif //CASINOGAME_RUSSIANROULETTE_H
