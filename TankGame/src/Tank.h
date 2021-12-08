#pragma once
#include <SFML/Graphics.hpp>
#include "./TankController.h"

/// <summary>
/// @brief A simple tank controller.
/// 
/// This class will manage all tank movement.
/// </summary>
class Tank
{
public:	
	Tank(sf::Texture const & texture , TankController& tn /*, sf::Vector2f const & pos */);
	void initSprites();
	void render(sf::RenderWindow & window);
	
private:
	sf::Sprite m_tankBase;
	sf::Sprite m_turret;
	sf::Texture const & m_texture;

	TankController& controller;
		
};

