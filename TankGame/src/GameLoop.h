#pragma once
#include <SFML/System/Clock.hpp>
#include "Game.h"

// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;

class GameLoop {
public:
	static void loop(Game& game) {
		sf::Clock clock;
		sf::Int32 lag = 0;

		while (game.isRunning())
		{
			sf::Time dt = clock.restart();

			while (clock.getElapsedTime().asMilliseconds() < MS_PER_UPDATE)
				game.processEvents();

			game.update(clock.getElapsedTime().asMilliseconds());

			game.render();
		}
	}
};