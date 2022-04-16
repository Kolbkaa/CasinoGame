//
// Created by dawid on 15.04.2022.
//

#include "Game.h"

Game::Game(string title, string description) {
    _title = title;
    _description = description;
}

string Game::GetTitle() {
    return _title;
}