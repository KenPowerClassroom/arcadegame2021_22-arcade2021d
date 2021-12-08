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

	sf::Sprite& turret = sprites[0];

	turret.setPosition(sf::Vector2f(newXPosition, newYPosition));

	turret.setRotation((float)controller.getRotationDegrees());
}


void Tank::init(Texture& texture)
{
	// Initialise the tank base
	sf::Sprite turret;

	// Initialise the turret
	turret.setTexture(texture.get());
	sf::IntRect turretRect(16, 0, 16, 16);
	turret.setTextureRect(turretRect);
	turret.setOrigin(turretRect.width / 2.0f, turretRect.height / 2.0f);

	sprites.push_back(turret);
}

