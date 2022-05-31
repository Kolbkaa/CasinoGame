#include <iostream>
#include "Model/Game.h"
#include "Utils/List.h"
#include "Model/User.h"
#include "Persistent/UserRepository.h"
#include "UI/UI.h"
#include "Services/UserService.h"
#include "UI/UserMenuAction.h"

int main() {
    GameState* gameState = new GameState();

    UserMenuAction *userMenuAction = new UserMenuAction();


    int choose = 0;
    int maxChoose = 0;

    while (gameState->IsRunning()) {
        do {
            maxChoose = UI::PrintMainMenu();
        } while (!UI::GetUserInput(choose, maxChoose));
        switch (choose) {
            case 1:
                userMenuAction->Run(gameState);
                break;
            case 2:
                if (gameState->GetUser() == NULL) {
                    cout << "Nie wybrano gracza" << endl;
                }
                break;
            case 3:
                gameState->StopGame();
                break;
        }
        choose = 0;
    }

    return 0;
}
