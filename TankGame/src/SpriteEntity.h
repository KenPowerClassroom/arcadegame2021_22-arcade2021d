#pragma once
#include <SFML/Graphics.hpp>
#include "Texture.h"

class SpriteEntity{
protected:
	virtual void update() = 0;
	std::vector<sf::Sprite>  sprites;
public:
	virtual const std::vector<sf::Sprite>& getSprites() {
		update();
		return sprites;
	}
};
