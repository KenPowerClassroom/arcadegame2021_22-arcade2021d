#include "pch.h"
#include "../TankGame/src/TankController.h"

TEST(TankController, RotationWrapsAround) {
	TankController tc;

	for (int i = 0; i < 361; i++)
		tc.increaseRotation();

	EXPECT_EQ(tc.getRotationDegrees(), 1);
}

TEST(TankController, RotationWrapsAroundGoingTheOtherway) {
	TankController tc;

	tc.decreaseRotation();

	EXPECT_EQ(tc.getRotationDegrees(), 359);
}

TEST(TankController, GoesForwardAlongXAxis) {
	TankController tc;

	tc.increaseSpeed();
	tc.update(1000);

	EXPECT_EQ(tc.getYpos(), 0);
	EXPECT_EQ(tc.getXpos(), 10);
}

TEST(TankController, GoesBackAlongXAxis) {
	TankController tc;

	tc.decreaseSpeed();
	tc.update(1000);

	EXPECT_EQ(tc.getYpos(), 0);
	EXPECT_EQ(tc.getXpos(), -10);
}

TEST(TankController, MaxSpeedIsCapped) {
	TankController tc;

	for (int i = 0; i < 1000; i++)
		tc.increaseSpeed();

	tc.update(1000);

	EXPECT_EQ(tc.getYpos(), 0);
	EXPECT_EQ(tc.getXpos(), 580);
}

TEST(TankController, MinSpeedIsCapped) {
	TankController tc;

	for (int i = 0; i < 1000; i++)
		tc.decreaseSpeed();

	tc.update(1000);

	EXPECT_EQ(tc.getYpos(), 0);
	EXPECT_EQ(tc.getXpos(), -580);
}

TEST(TankController, MoveInNEDirection) {
	TankController tc;

	tc.increaseSpeed();
	for (int i = 0; i < 45; i++)
		tc.increaseRotation();

	tc.update(1000);

	EXPECT_NEAR(tc.getYpos(), 7, 1);
	EXPECT_NEAR(tc.getXpos(), 7, 1);
}

TEST(TankController, MoveInSEDirection) {
	TankController tc;

	for (int i = 0; i < 135; i++)
		tc.decreaseRotation();

	tc.increaseSpeed();
	tc.update(1000);

	EXPECT_NEAR(tc.getYpos(), -7, 1);
	EXPECT_NEAR(tc.getXpos(), -7, 1);
}

TEST(TankController, SlowsDownAfterUpdate) {
	TankController tc;

	tc.increaseSpeed();

	tc.update(1000);

	double start = tc.getXpos();
	tc.update(1000);
	double distanceTravelled = tc.getXpos() - start;

	EXPECT_NEAR(distanceTravelled, 9.9, 0.1);
}

TEST(TankController, StopsAfterManyUpdates) {
	TankController tc;

	tc.increaseSpeed();

	for (int i = 0; i < 500; i++)
		tc.update(1000);

	double start = tc.getXpos();
	tc.update(1000);
	double distanceTravelled = tc.getXpos() - start;

	EXPECT_NEAR(distanceTravelled, 0.0, 0.1);
}


