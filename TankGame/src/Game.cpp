#include "Game.h"
#include "GameLoop.h"
#include <iostream>



////////////////////////////////////////////////////////////
Game::Game()
	: m_window(sf::VideoMode(ScreenSize::s_width, ScreenSize::s_height, 32), "SFML Playground", sf::Style::Default),
	m_tank(m_spriteSheetTexture, m_tankController)
{
	
	
	//loading the level data from the YAML file corresponding
	int currentLevel = 1;
	// Will generate an exception if level loading fails.
	try
	{
		LevelLoader::load(currentLevel, m_level);
	}
	catch (std::exception& e)
	{
		std::cout << "Level Loading failure." << std::endl;
		std::cout << e.what() << std::endl;
		throw e;
	}

	m_window.setVerticalSyncEnabled(true);
	
	//loading the backgroud texture to the backgroud sprite 
	if (!m_bgTexture.loadFromFile(m_level.m_background.m_fileName))
	{
		std::string s("Error loading background texture");
		throw std::exception(s.c_str());
	}
	m_bgSprite.setTexture(m_bgTexture);
	

	//extract the wall image from the spritesheet.
	sf::Sprite sprite;
	sf::IntRect wallRect(2, 129, 33, 23);
	sprite.setTexture(m_spriteSheetTexture);
	sprite.setTextureRect(wallRect);
	//loop through each obstacle instance
	for (auto& obstacle : m_level.m_obstacles)
	{
		//position the wall sprite using the obstacle data
		sprite.setPosition(obstacle.m_position);
		sprite.rotate(obstacle.m_rotation);
		m_sprites.push_back(sprite);
	}

	
	//loading the tank texture 
	if (!m_spriteSheetTexture.loadFromFile("./resources/images/SpriteSheet.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());
	}

	// Now the level data is loaded, set the tank position.
	m_tank.initSprites();
	m_tankController.setPos(m_level.m_tank.m_position.x, m_level.m_tank.m_position.y);
}

////////////////////////////////////////////////////////////

bool Game::isRunning() {
	return m_window.isOpen();
}

void Game::run()
{
	GameLoop gameloop;
	gameloop.loop(*this);
}

////////////////////////////////////////////////////////////
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}

////////////////////////////////////////////////////////////
void Game::processGameEvents(sf::Event& event)
{
	// check if the event is a a mouse button release
	if (sf::Event::KeyPressed == event.type)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			m_window.close();
			break;

		case sf::Keyboard::Up:
			m_tankController.increaseSpeed();
			break;
			
		case sf::Keyboard::Down:
			m_tankController.decreaseSpeed();
			break;

		case sf::Keyboard::Right:
			m_tankController.increaseRotation();
			break;

		case sf::Keyboard::Left:
			m_tankController.decreaseRotation();
			break;
		default:
			break;
		}
	}
}

////////////////////////////////////////////////////////////
void Game::update(double dt)
{
	m_tankController.update(dt);
}

////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 0));
	
	//drawing the backgroud
	m_window.draw(m_bgSprite);

	//draw the walls
	for (sf::Sprite& wallSprite : m_sprites)
	{
		m_window.draw(wallSprite);
	}

	//drawing the tank 
	m_tank.render(m_window);

	m_window.display();
}





