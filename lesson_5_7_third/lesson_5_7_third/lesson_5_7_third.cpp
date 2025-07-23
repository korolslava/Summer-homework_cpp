#include "GameStudio.h"

int main()
{
	Developer dev1("Alice", programmer, 5);
	Developer dev2("Bob", designer, 3);
	Developer dev3("Charlie", analyst, 4);

	Game game1("Epic Adventure", 9.5f, dev1);
	Game game2("Mystery Quest", 8.7f, dev2);
	Game game3("Puzzle Master", 7.8f, dev3);

	Game games[] = { game1, game2, game3 };

	GameStudio studio("Game Innovators", 2010, games, 3);
	studio.ShowAllGames();

	GameStudio studioCopy = studio;
	studioCopy.ShowAllGames();

	GameStudio studioMove = std::move(studio);
	studioMove.ShowAllGames();
	studio.ShowAllGames();
}

