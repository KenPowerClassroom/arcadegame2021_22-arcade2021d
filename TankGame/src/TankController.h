#pragma once
#include "Angle.h"

class TankController{
	double m_xpos, m_ypos;
	double m_speed;
	Angle m_rotation;
	double m_maximumSpeed;

	const int SPEED_INCREASE_PER_FRAME{ 10 };
public:

	TankController():
		m_maximumSpeed(580),
		m_rotation(Angle::fromDegrees(0)),
		m_speed(0),
		m_xpos(0), m_ypos(0)
		{}

	double getXpos() { return m_xpos; }
	double getYpos() { return m_ypos; }
	double getRotationDegrees() { return m_rotation.degrees(); }

	void setPos(double x, double y) {
		m_xpos = x;
		m_ypos = y;
	}

	void update(double dt);
	/// <summary>
	/// @brief Increases the speed by 1, max speed is capped at 100.
	/// 
	/// </summary>
	void increaseSpeed();

	/// <summary>
	/// @brief Decreases the speed by 1, min speed is capped at -100.
	/// 
	/// </summary>
	void decreaseSpeed();

	/// <summary>
	/// @brief Increases the rotation by 1 degree, wraps to 0 degrees after 359.
	/// 
	/// </summary>
	void increaseRotation();

	/// <summary>
	/// @brief Decreases the rotation by 1 degree, wraps to 359 degrees after 0.
	/// 
	/// </summary>
	void decreaseRotation();
};