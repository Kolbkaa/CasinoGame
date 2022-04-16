//
// Created by dawid on 15.04.2022.
//

#include "GameListElement.h"

GameListElement::GameListElement(Game* game) {
    _game = game;
}

Game *GameListElement::GetGame() {
    return _game;
}
bool GameListElement::IsNextElement() {
    return !_nextElement== NULL;
}

GameListElement* GameListElement::GetNextElement() {
    return _nextElement;
}

void GameListElement::SetNextElement(GameListElement *nextElement) {
    _nextElement = nextElement;
}