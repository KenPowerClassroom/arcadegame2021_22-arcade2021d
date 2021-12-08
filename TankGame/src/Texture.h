#pragma once
#include <SFML/Graphics.hpp>

class Texture {
	sf::Texture texture;

public:
	void load(const std::string& filename) {
		if (!texture.loadFromFile(filename))
		{
			std::string s("Error loading  texture");
			throw std::exception(s.c_str());
		}
	}

	sf::Texture& get() { return texture; }

};