//
// Created by dawid on 20.06.2022.
//

#ifndef CASINOGAME_BLACKJACK_H
#define CASINOGAME_BLACKJACK_H


#include "../Model/Game.h"
#include "../Services/DeckCardsService.h"

class BlackJack : public Game {
private:
    DeckCardsService *_deckCardService;

    void Play(User *user, int bet) {
        _deckCardService = new DeckCardsService();
        int playerSum = 0;
        int croupierSum = 0;
        bool playerStand = false;
        bool croupierStand = false;
        Card *card;

        card = _deckCardService->GetRandomCard();
        cout << "Pierwsza karta krupiera " << card->GetName() << endl;
        croupierSum += card->GetValue();
        card = _deckCardService->GetRandomCard();
        cout << "Druga karta krupiera zakryta" << endl;
        croupierSum += card->GetValue();
        cout<<endl;

        card = _deckCardService->GetRandomCard();
        cout << "Twoja pierwsza karta " << card->GetName() << endl<;
        playerSum += card->GetValue();
        card = _deckCardService->GetRandomCard();
        cout << "Twoja druga karta " << card->GetName() << endl;
        playerSum += card->GetValue();

        if (playerSum == 22) {
            cout << "Zdobyłes Black Jacka. Wygrywasz " << _bet * 1.5 << endl;
            user->AddMoney(_bet * 1.5);
            return;
        }

        do {
            if (croupierSum <= 16) {
                card = _deckCardService->GetRandomCard();
                croupierSum += card->GetValue();
            } else {
                croupierStand = true;
            }
            if (playerStand == false) {
                cout << "Wpisz 'T' jezeli dobierasz karte: ";
                string choose;
                cin >> choose;
                if (choose == "T" || choose == "t") {
                    card = _deckCardService->GetRandomCard();
                    cout << "Twoja karta to " << card->GetName() << endl;
                    playerSum += card->GetValue();
                } else {
                    playerStand = true;
                }
            }

        } while (!playerStand || !croupierStand);

        cout << "Uzyskales " << playerSum << " , a krupier " << croupierSum << endl << endl;


        if (playerSum > 21 || (playerSum < croupierSum && croupierSum <= 21)) {
            cout << "Niestety przegrales" << endl;
        } else if (playerSum <= 21 || (playerSum < croupierSum && croupierSum > 21)) {
            cout << "Brawo! Wygrales " << bet * 1.2 << endl;
            user->AddMoney(bet * 1.2);
        } else {
            cout << "Remis. odyskujesz pieniadze" << endl;
            user->AddMoney(bet);
        }
        delete _deckCardService;
    }

public:
    BlackJack() : Game("Black Jack", "Dobierz karty zeby byc jak najblizej 21") {
    }

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


#endif //CASINOGAME_BLACKJACK_H
