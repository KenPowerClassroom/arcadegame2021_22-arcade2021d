#include "pch.h"
#include "../TankGame/Laser.h"

TEST(Laser, TankController, makeLaserTest)
{
	TankController tc;
	tc.setPos(100.0, 100.0);
	Laser laser;
	// lasers.makeLaser(sf::Vector2f(m_tank.controller.getXpos(), m_tank.controller.getYpos()), 
	// m_tank.controller.getRotationDegrees(), 5);
	laser.moveLaser();

	EXPECT_EQ(laser.getSprite().getPosition().x, 95.0);
	EXPECT_EQ(laser.getSprite().getPosition().y, 100.0);
}