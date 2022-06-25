//
// Created by dawid on 20.06.2022.
//

#ifndef CASINOGAME_DECKCARDSSERVICE_H
#define CASINOGAME_DECKCARDSSERVICE_H


#include <iostream>
#include "../Model/Card.h"
#include "../Utils/List.h"

class DeckCardsService {
private:
    List<Card> *_decks;
public:
    DeckCardsService() {
        srand(time(NULL));

        _decks = new List<Card>();
        _decks->AddItem(new Card("2", 2));
        _decks->AddItem(new Card("2", 2));
        _decks->AddItem(new Card("2", 2));
        _decks->AddItem(new Card("2", 2));
        _decks->AddItem(new Card("3", 3));
        _decks->AddItem(new Card("3", 3));
        _decks->AddItem(new Card("3", 3));
        _decks->AddItem(new Card("3", 3));
        _decks->AddItem(new Card("4", 4));
        _decks->AddItem(new Card("4", 4));
        _decks->AddItem(new Card("4", 4));
        _decks->AddItem(new Card("4", 4));
        _decks->AddItem(new Card("5", 5));
        _decks->AddItem(new Card("5", 5));
        _decks->AddItem(new Card("5", 5));
        _decks->AddItem(new Card("5", 5));
        _decks->AddItem(new Card("6", 6));
        _decks->AddItem(new Card("6", 6));
        _decks->AddItem(new Card("6", 6));
        _decks->AddItem(new Card("6", 6));
        _decks->AddItem(new Card("7", 7));
        _decks->AddItem(new Card("7", 7));
        _decks->AddItem(new Card("7", 7));
        _decks->AddItem(new Card("7", 7));
        _decks->AddItem(new Card("8", 8));
        _decks->AddItem(new Card("8", 8));
        _decks->AddItem(new Card("8", 8));
        _decks->AddItem(new Card("8", 8));
        _decks->AddItem(new Card("9", 9));
        _decks->AddItem(new Card("9", 9));
        _decks->AddItem(new Card("9", 9));
        _decks->AddItem(new Card("9", 9));
        _decks->AddItem(new Card("10", 10));
        _decks->AddItem(new Card("10", 10));
        _decks->AddItem(new Card("10", 10));
        _decks->AddItem(new Card("10", 10));
        _decks->AddItem(new Card("Walet", 10));
        _decks->AddItem(new Card("Walet", 10));
        _decks->AddItem(new Card("Walet", 10));
        _decks->AddItem(new Card("Walet", 10));
        _decks->AddItem(new Card("Dama", 10));
        _decks->AddItem(new Card("Dama", 10));
        _decks->AddItem(new Card("Dama", 10));
        _decks->AddItem(new Card("Dama", 10));
        _decks->AddItem(new Card("Krol", 10));
        _decks->AddItem(new Card("Krol", 10));
        _decks->AddItem(new Card("Krol", 10));
        _decks->AddItem(new Card("Krol", 10));
        _decks->AddItem(new Card("AS", 11));
        _decks->AddItem(new Card("AS", 11));
        _decks->AddItem(new Card("AS", 11));
        _decks->AddItem(new Card("AS", 11));

    }

    ~DeckCardsService() {
        if (_decks != NULL) {
            delete _decks;
            _decks = NULL;
        }
    }

    Card *GetRandomCard() {
        int cardId = (rand() % _decks->Length());
        Card *card = _decks->GetItemById(cardId);
        _decks->RemoveById(cardId);

        return card;
    }

};


#endif //CASINOGAME_DECKCARDSSERVICE_H
