#pragma once
#include "SpriteEntity.h"
#include "Texture.h"

class Background : public SpriteEntity
{
public:
	void init(Texture& texture, sf::Vector2f t_pos) {
		sf::Sprite sprite;
		sprite.setTexture(texture.get());
		sprite.setPosition(t_pos);
		sprites.push_back(sprite);
	};
private:
	void update() {};
}; 