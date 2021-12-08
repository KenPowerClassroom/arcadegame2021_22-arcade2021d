#pragma once
#include "SpriteEntity.h"
#include "Texture.h"

class Walls : public SpriteEntity
{
public:
	void init(Texture& texture, std::vector<ObstacleData> obstacles) {
		//extract the wall image from the spritesheet.
		sf::Sprite sprite;
		sprite.setTexture(texture.get());

		sprite.setTextureRect(sf::IntRect(2, 129, 33, 23));
		//loop through each obstacle instance
		for (auto& obstacle : obstacles)
		{
			//position the wall sprite using the obstacle data
			sprite.setPosition(obstacle.m_position);
			sprite.rotate(obstacle.m_rotation);
			sprites.push_back(sprite);
		}

	};
private:
	void update() {};
};