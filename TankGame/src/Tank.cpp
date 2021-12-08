#include "Tank.h"
#include <iostream>
#include "MathUtility.h"

Tank::Tank(TankController& tn)
:controller(tn)
{	
}

void Tank::update()
{
	float newXPosition = (float)controller.getXpos();
	float newYPosition = (float)controller.getYpos();

	sf::Sprite& tankBase = sprites[0]; 
	sf::Sprite& turret = sprites[1];

	tankBase.setPosition(sf::Vector2f(newXPosition,newYPosition));
	turret.setPosition(sf::Vector2f(newXPosition, newYPosition));

	tankBase.setRotation((float)controller.getRotationDegrees());
	turret.setRotation((float)controller.getRotationDegrees());
}


void Tank::init(Texture& texture)
{
	// Initialise the tank base
	sf::Sprite tankBase, turret;
	tankBase.setTexture(texture.get());
	sf::IntRect baseRect(2, 43, 79, 43);
	tankBase.setTextureRect(baseRect);
	tankBase.setOrigin(baseRect.width / 2.0f, baseRect.height / 2.0f);

	// Initialise the turret
	turret.setTexture(texture.get());
	sf::IntRect turretRect(19, 1, 83, 31);
	turret.setTextureRect(turretRect);
	turret.setOrigin(turretRect.width / 3.0f, turretRect.height / 2.0f);

	sprites.push_back(tankBase);
	sprites.push_back(turret);
}

