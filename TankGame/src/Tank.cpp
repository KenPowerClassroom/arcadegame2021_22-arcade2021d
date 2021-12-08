#include "Tank.h"
#include <iostream>
#include "MathUtility.h"


Tank::Tank(sf::Texture const & texture, TankController& tn)
: m_texture(texture), controller(tn)
{	
}

void Tank::render(sf::RenderWindow & window) 
{
	double newXPosition = controller.getXpos();
	double newYPosition = controller.getYpos();

	//set new position 
	m_tankBase.setPosition(sf::Vector2f(newXPosition,newYPosition));
	m_turret.setPosition(sf::Vector2f(newXPosition, newYPosition));

	//set rotation 
	m_tankBase.setRotation(controller.getRotationDegrees());
	m_turret.setRotation(controller.getRotationDegrees());

	window.draw(m_tankBase);
	window.draw(m_turret);
}


void Tank::initSprites()
{
	// Initialise the tank base
	m_tankBase.setTexture(m_texture);
	sf::IntRect baseRect(2, 43, 79, 43);
	m_tankBase.setTextureRect(baseRect);
	m_tankBase.setOrigin(baseRect.width / 2.0, baseRect.height / 2.0);

	// Initialise the turret
	m_turret.setTexture(m_texture);
	sf::IntRect turretRect(19, 1, 83, 31);
	m_turret.setTextureRect(turretRect);
	m_turret.setOrigin(turretRect.width / 3.0, turretRect.height / 2.0);
}

