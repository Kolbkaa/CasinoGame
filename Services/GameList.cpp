//
// Created by dawid on 15.04.2022.
//

#include "GameList.h"

int GameList::AddGame(Game *game) {
    if (_gameElement == NULL) {
        _gameElement = new GameListElement(game);
        return ++_length;
    }
    GameListElement *_head = _gameElement;
    while (_head->IsNextElement()) {
        _head = _head->GetNextElement();
    }
    _head->SetNextElement(new GameListElement(game));
    return ++_length;

}

Game *GameList::GetGameById(int id) {
    if (id >= _length) {
        return NULL;
    }
    GameListElement *_head = _gameElement;

    int index = 0;
    while (index != id) {
        ++index;
        _head = _head->GetNextElement();
    }
    return _head->GetGame();

}

void GameList::Clear() {

    GameListElement *_element = _gameElement;
    while (_element != NULL) {
        GameListElement *toDelete = _element;
        _element = _element->GetNextElement();
        delete toDelete->GetGame();
        delete toDelete;
    }

}