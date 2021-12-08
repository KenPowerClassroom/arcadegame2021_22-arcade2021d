#pragma once
#include "SpriteEntity.h"
#include "Texture.h"

class Background : public SpriteEntity
{
public:
	void init(Texture& texture) {
		sf::Sprite sprite;
		sprite.setTexture(texture.get());
		sprites.push_back(sprite);
	};
private:
	void update() {};
}; 