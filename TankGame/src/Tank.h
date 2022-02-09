#pragma once
#include <SFML/Graphics.hpp>
#include "./TankController.h"
#include "SpriteEntity.h"
#include "Texture.h"

class Tank: public SpriteEntity
{
public:	
	Tank(TankController& tc);
	void init(Texture& texture);
	TankController& controller;
	sf::Sprite getSprite() const { return sprites.back(); }
private:
	void update();
};

