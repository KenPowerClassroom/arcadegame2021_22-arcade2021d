#include "Game.h"
#include "GameLoop.h"

#include <iostream>

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>

//New stuff

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
	background.init(m_bgTexture, sf::Vector2f(8, 8));
	
	m_spriteSheetTexture.load("./resources/images/SpriteSheet.png");
	walls.init(m_spriteSheetTexture, m_level.m_obstacles);

	// Now the level data is loaded, set the tank position.
	m_tank.init(m_spriteSheetTexture);
	m_tankController.setPos(m_level.m_tank.m_position.x, m_level.m_tank.m_position.y);
}

bool Game::isRunning() {
	return window.isOpen();
}

void Game::spawnInEnemy(int t_amount, sf::Vector2f t_pos)
{
	for (int i = 0; i < t_amount; i++)
	{
		TankController tempController;
		tempController.setPos(t_pos.x, t_pos.y);
		m_enemyTankController.push_back(tempController);
		//noOfEnemies++;
		Tank tempTank(m_enemyTankController.back());
		tempTank.init(m_spriteSheetTexture);
		m_enemyTanks.push_back(tempTank); 
	}
	noOfEnemies += t_amount;
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

	sf::Event newEvent;
	while (window.getWindow().pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type)
		{
			window.getWindow().close();
		}
		if (sf::Event::KeyPressed == newEvent.type)
		{
			if (sf::Keyboard::Space == newEvent.key.code)
				lasers.makeLaser(sf::Vector2f(m_tank.controller.getXpos(), m_tank.controller.getYpos()), m_tank.controller.getRotationDegrees(), 5);
			if (sf::Keyboard::Escape == newEvent.key.code)
				window.getWindow().close();
			if(sf::Keyboard::O == newEvent.key.code) // opens the project url!
				ShellExecute(0, 0, L"https://github.com/KenPowerClassroom/arcadegame2021_22-arcade2021d", 0, 0, SW_SHOW);
		}
		if (sf::Event::MouseButtonReleased == newEvent.type)
		{ 
			spawnInEnemy(1, sf::Vector2f(sf::Mouse::getPosition(window.getWindow()).x / window.getScale(), sf::Mouse::getPosition(window.getWindow()).y / window.getScale()));
		}
	}
}

void Game::update(double dt)
{
	window.processEvents();
	m_tankController.update(dt);
	for (int i = 0; i < noOfEnemies; i++)
	{
		m_enemyTankController[i].update(dt);
	}
	lasers.update();
}

void Game::render()
{
	window.startFrame();
	
	window.drawSprites(background.getSprites());
	window.drawSprites(walls.getSprites()) ;
	lasers.draw(window.getWindow());
	for (int i = 0; i < noOfEnemies; i++)
	{
		window.drawSprites(m_enemyTanks[i].getSprites());
	}
	window.drawSprites(m_tank.getSprites()) ;

	window.endFrame(); 
}