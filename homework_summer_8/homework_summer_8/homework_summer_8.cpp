#include "GameCenter.h"

int main() {
    Character chars[] = {
        Character("Grommash", 85, "warrior"),
        Character("Jaina", 90, "mage")
    };
    Player player1("Thrall", 35, chars, 2);

    Character chars2[] = {
        Character("Sylvanas", 88, "archer")
    };
    Player player2("Arthas", 28, chars2, 1);

    Player players[] = { player1, player2 };
    GameCenter center("Azeroth", players, 2);

    center.listPlayers();

    const Player* topPlayer = center.findTopPlayer();
    if (topPlayer) {
        cout << "Top player: " << topPlayer->getNickname()
            << " (Highest level: " << topPlayer->getHighestLevel() << ")" << endl;
    }

	return 0;

};


