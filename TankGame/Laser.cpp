#include "Laser.h"


Laser::Laser()
{
	if (!m_texture.loadFromFile("./resources/images/SpriteSheet.png"))
	{
		std::cout << "problem loading laser" << std::endl;
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 17, 1, 1));
	m_sprite.setOrigin(3, 6);
	m_sprite.setPosition(-2000, -2000);
	m_velocity = sf::Vector2f(0, 0);
	m_alive = false;
	hits = 3;
	m_sprite.setColor(sf::Color(255, 255, 255, 255));
}

void Lasers::draw(sf::RenderWindow& t_window)
{
	for (int step = 0; step < m_noOfLasers; step++)
	{
		if (laserVector[step].getAlive())
		{
			t_window.draw(laserVector[step].getSprite());
		}
	}
}

void Lasers::makeLaser(sf::Vector2f t_loc, int t_rot, int t_speed)
{
	bool spawnedIn = false;
	if (m_noOfLasers > 0)
	{
		for (int step = 0; step < m_noOfLasers; step++)
		{
			if (!laserVector[step].getAlive())
			{
				laserVector[step].shoot(t_loc, t_rot, t_speed);
				spawnedIn = true;
				//break;
			}
		}
	}
	if (!spawnedIn)
	{
		m_noOfLasers++;
		Laser tempLaser;
		tempLaser.shoot(t_loc, t_rot, t_speed);
		laserVector.push_back(tempLaser);

	}
}


void Laser::shoot(sf::Vector2f t_location, int t_loc, int t_speed)
{
	if (m_alive == false)
	{
		hits = 3;
		m_sprite.setRotation(t_loc - 90);
		m_alive = true;
		sf::Vector2f newV{ 0,0 };
		newV.x = cos((t_loc * PI) / 180.0) * m_speed;
		newV.y = sin((t_loc * PI) / 180.0) * m_speed;
		m_sprite.setPosition(t_location + newV);
		m_velocity = newV;
	}
}

void Lasers::update(std::vector<Tank>& t_tanks, int& t_noOfEnemies)
{
	for (int step = 0; step < m_noOfLasers; step++)
	{
		if (laserVector[step].getAlive())
		{
			laserVector[step].moveLaser();
			laserVector[step].checkLaser();
			// check collision between laser and tank
			if (t_tanks.size() > 0)
			{
				//if (laserVector[step].getSprite().getGlobalBounds().intersects(t_tanks.back().getSprite().getGlobalBounds()));
				if (t_tanks.back().getSprite().getGlobalBounds().contains(laserVector[step].getSprite().getPosition()))
				{
					laserVector[step].kill();
					t_tanks.clear();
					t_noOfEnemies = 0;
					//std::cout << "hit\n";
					//std::cout << t_tanks.back().getSprite().getGlobalBounds().left << "\n";
				}
			}
		}
	}
}

void Laser::moveLaser()
{
	m_sprite.setPosition(m_sprite.getPosition() + m_velocity);
}
void Laser::checkLaser()
{
	if (m_sprite.getPosition().x < 0 || m_sprite.getPosition().x > ScreenSize::s_width || m_sprite.getPosition().y < 0 || m_sprite.getPosition().y > ScreenSize::s_height)
	{
		kill();
	}
}
void Laser::kill()
{
	m_sprite.setPosition(-2000, -2000);
	m_velocity = sf::Vector2f(0, 0);
	m_alive = false;
}
bool Lasers::checkIfCollision(sf::Vector2f t_loc, int t_tolerence)
{
	bool bollHold{ false };

	for (int step = 0; step < m_noOfLasers; step++)
	{
		if (laserVector[step].getAlive())
		{
			if (t_tolerence > sqrtf((t_loc.x - laserVector[step].getSprite().getPosition().x) *
				(t_loc.x - laserVector[step].getSprite().getPosition().x) +
				(t_loc.y - laserVector[step].getSprite().getPosition().y) *
				(t_loc.y - laserVector[step].getSprite().getPosition().y)))
			{
				bollHold = true;
				laserVector[step].kill();
			}
		}
	}

	return bollHold;
}

void Lasers::checkWallCollison(sf::Sprite t_wallSprite)
{
	for (int step = 0; step < m_noOfLasers; step++)
	{
		if (laserVector[step].getAlive())
		{
			if (laserVector[step].getSprite().getPosition().x + laserVector[step].getVel().x > t_wallSprite.getPosition().x &&
				laserVector[step].getSprite().getPosition().x + laserVector[step].getVel().x < t_wallSprite.getPosition().x + t_wallSprite.getTextureRect().width &&
				laserVector[step].getSprite().getPosition().y > t_wallSprite.getPosition().y &&
				laserVector[step].getSprite().getPosition().y < t_wallSprite.getPosition().y + t_wallSprite.getTextureRect().height)
			{
				laserVector[step].getVel().x *= -1.0f;
				laserVector[step].getSprite().setRotation(360 - laserVector[step].getSprite().getRotation());
				laserVector[step].getHits()--;
			}
			if (laserVector[step].getSprite().getPosition().x > t_wallSprite.getPosition().x &&
				laserVector[step].getSprite().getPosition().x < t_wallSprite.getPosition().x + t_wallSprite.getTextureRect().width &&
				laserVector[step].getSprite().getPosition().y + laserVector[step].getVel().y > t_wallSprite.getPosition().y &&
				laserVector[step].getSprite().getPosition().y + laserVector[step].getVel().y < t_wallSprite.getPosition().y + t_wallSprite.getTextureRect().height)
			{
				laserVector[step].getVel().y *= -1.0f;
				laserVector[step].getSprite().setRotation(360 - laserVector[step].getSprite().getRotation());
				laserVector[step].getHits()--;
			}
			if (laserVector[step].getSprite().getPosition().x > t_wallSprite.getPosition().x &&
				laserVector[step].getSprite().getPosition().x < t_wallSprite.getPosition().x + t_wallSprite.getTextureRect().width &&
				laserVector[step].getSprite().getPosition().y > t_wallSprite.getPosition().y &&
				laserVector[step].getSprite().getPosition().y < t_wallSprite.getPosition().y + t_wallSprite.getTextureRect().height)
			{
				laserVector[step].kill();
			}
			switch (laserVector[step].getHits())
			{
			case 3:
				laserVector[step].getSprite().setColor(sf::Color(255, 255, 255, 255));
				break;
			case 2:
				laserVector[step].getSprite().setColor(sf::Color(255, 255, 0, 255));
				break;
			case 1:
				laserVector[step].getSprite().setColor(sf::Color(255, 0, 0, 255));
				break;
			default:
				laserVector[step].kill();
				break;
			}
		}
	}
}
