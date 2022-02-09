#pragma once
#include <SFML/Graphics.hpp>
#include "src/ScreenSize.h"
#include <math.h>
#include <iostream>
#include <SFML/Audio.hpp>
#include "src/Tank.h"

class Laser
{

public:
	Laser();
	void shoot(sf::Vector2f t_location, int t_loc, int t_speed);
	void moveLaser();
	void checkLaser();
	void kill();
	bool getAlive() { return m_alive; }
	sf::Sprite& getSprite() { return m_sprite; }
	sf::Vector2f& getVel() { return m_velocity; }
	int& getHits() { return hits; }

private:
	const float PI = 3.14159265;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_velocity;
	bool m_alive;
	int m_speed{ 5 };
	int hits{ 3 };
};

class Lasers
{
public:
	Lasers() {};
	void draw(sf::RenderWindow& t_window);
	void makeLaser(sf::Vector2f t_loc, int t_rot, int t_speed);
	//void update(Tank& t_tank);
	void update(std::vector<Tank>& t_tanks, int& t_noOfEnemies);
	bool checkIfCollision(sf::Vector2f t_loc, int t_tolerence);
	void checkWallCollison(sf::Sprite t_wallSprite);
private:
	int m_noOfLasers{ 0 };
	std::vector <Laser> laserVector;

};