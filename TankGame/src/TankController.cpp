#define _USE_MATH_DEFINES
#include <cmath>
#include "./TankController.h"

void TankController::update(double dt) {
	//get new position
	double newXPosition = m_xpos + cos(m_rotation.radians()) * m_speed * (dt / 1000);
	double newYPosition = m_ypos + sin(m_rotation.radians()) * m_speed * (dt / 1000);

	m_xpos = newXPosition;
	m_ypos = newYPosition;

	m_speed *= 0.99; //simulate friction

	//limiting speed 
	m_speed = m_speed > m_maximumSpeed ? m_maximumSpeed : m_speed;
	m_speed = m_speed < -m_maximumSpeed ? -m_maximumSpeed : m_speed;
}

void TankController::increaseSpeed()
{
	if (m_speed < m_maximumSpeed)
		m_speed += SPEED_INCREASE_PER_FRAME;
}

void TankController::decreaseSpeed()
{
	if (m_speed > -m_maximumSpeed)
		m_speed -= SPEED_INCREASE_PER_FRAME;
}

Angle ROTATION_ONE_FRAME = Angle::fromDegrees(1);
void TankController::increaseRotation()
{
	m_rotation = m_rotation + ROTATION_ONE_FRAME;
}

void TankController::decreaseRotation()
{
	m_rotation = m_rotation - ROTATION_ONE_FRAME;
}