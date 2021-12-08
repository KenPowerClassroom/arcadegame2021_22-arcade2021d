#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
#include "./TankController.h"

double const DEG_TO_RAD = M_PI / 180.0f;

void TankController::update(double dt) {
	//get new position
	float newXPosition = m_xpos + cos(m_rotation.radians()) * m_speed * (dt / 1000);
	float newYPosition = m_ypos + sin(m_rotation.radians()) * m_speed * (dt / 1000);

	m_xpos = newXPosition;
	m_ypos = newYPosition;

	//simulate friction
	m_speed *= 0.99;

	//limiting speed 
	//m_speed = std::clamp(m_speed, m_maximumSpeed * -1, m_maximumSpeed);
	m_speed = m_speed > m_maximumSpeed ? m_maximumSpeed : m_speed;
	m_speed = m_speed < -m_maximumSpeed ? -m_maximumSpeed : m_speed;
}

void TankController::increaseSpeed()
{
	if (m_speed < 100.0)
	{
		m_speed += 1;
	}
}

////////////////////////////////////////////////////////////
void TankController::decreaseSpeed()
{
	if (m_speed > -100.0)
	{
		m_speed -= 1;
	}
}

Angle ROTATION_ONE_FRAME = Angle::fromDegrees(1);
void TankController::increaseRotation()
{
	m_rotation = m_rotation + ROTATION_ONE_FRAME;
}

////////////////////////////////////////////////////////////
void TankController::decreaseRotation()
{
	m_rotation = m_rotation - ROTATION_ONE_FRAME;
}