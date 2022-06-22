#include <iostream>
#include "Model/Game.h"
#include "Utils/List.h"
#include "Model/User.h"
#include "Persistent/UserRepository.h"
#include "UI/UI.h"
#include "Services/UserService.h"
#include "UI/UserMenuAction.h"
#include "UI/GameMenuAction.h"
using namespace std;
int main() {
    GameState* gameState = new GameState();
    UserRepository *userRepository = new UserRepository();
    UserService *userService = new UserService(userRepository);
    GameService *gameService = new GameService();

    UserMenuAction *userMenuAction = new UserMenuAction(userService);
    GameMenuAction *gameMenuAction = new GameMenuAction(gameService);


    int choose = 0;
    int maxChoose = 0;

    while (gameState->IsRunning()) {
        do {
            maxChoose = UI::PrintMainMenu();
        } while (!UI::GetUserMenuChoose(choose, maxChoose));
        switch (choose) {
            case 1:
                userMenuAction->Run(gameState);
                break;
            case 2:
                gameMenuAction->Run(gameState);
                break;
            case 3:
                userService->SaveUsers();
                gameState->StopGame();
                break;
        }
        choose = 0;
        cin.clear();
    }
    delete gameMenuAction;
    delete userMenuAction;
    delete gameService;
    delete userService;
    delete userRepository;
    delete gameState;
    return 0;
}
