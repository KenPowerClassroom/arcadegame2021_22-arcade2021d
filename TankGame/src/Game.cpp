#include "Game.h"
#include "GameLoop.h"

#include <iostream>

Game::Game():
	m_tank(m_tankController)
{
	//loading the level data from the YAML file corresponding
	int currentLevel = 1;
	try
	{
		LevelLoader::load(currentLevel, m_level);
	}// Will generate an exception if level loading fails.
	catch (std::exception& e)
	{
		std::cout << "Level Loading failure." << std::endl;
		std::cout << e.what() << std::endl;
		throw e;
	}
	
	m_bgTexture.load(m_level.m_background.m_fileName);
	background.init(m_bgTexture);
	
	m_spriteSheetTexture.load("./resources/images/SpriteSheet.png");
	walls.init(m_spriteSheetTexture, m_level.m_obstacles);

	// Now the level data is loaded, set the tank position.
	m_tank.init(m_spriteSheetTexture);
	m_tankController.setPos(m_level.m_tank.m_position.x, m_level.m_tank.m_position.y);
}

bool Game::isRunning() {
	return window.isOpen();
}

void Game::run()
{
	//Servant pattern https://en.wikipedia.org/wiki/Servant_(design_pattern)#Similar_design_pattern:_Command
	GameLoop gameloop;
	gameloop.loop(*this);
}

void Game::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_tankController.increaseSpeed();
			
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_tankController.decreaseSpeed();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_tankController.increaseRotation();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_tankController.decreaseRotation();
}

void Game::update(double dt)
{
	window.processEvents();
	handleInput();
	m_tankController.update(dt);
}

void Game::render()
{
	window.startFrame();
	
	window.drawSprites(background.getSprites());
	window.drawSprites(walls.getSprites()) ;
	window.drawSprites(m_tank.getSprites()) ;

	window.endFrame(); 

}