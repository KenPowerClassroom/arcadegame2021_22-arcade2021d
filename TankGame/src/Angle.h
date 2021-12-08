#pragma once
#include<cmath>

class Angle {
private:
	static double radianToDegree(double radians) {
		return (radians / TWO_PI) * DEGREES_IN_CIRCLE;
	}

	Angle(double degree) :degree(degree) {} // make this private so users forced to use factory methods
	double degree;				

public:
	static const long DEGREES_IN_CIRCLE = 360;
	static const double PI;
	static const double TWO_PI;

	static Angle fromDegrees(double degrees) { //Factory Method
		double wrappedDeg = std::fmod(degrees, DEGREES_IN_CIRCLE);
		if (wrappedDeg < 0)
			wrappedDeg += DEGREES_IN_CIRCLE;
		return Angle{ wrappedDeg };
	}

	static Angle fromRadians(double radians) { //Factory Method
		return fromDegrees(radianToDegree(radians));
	}

	double degrees() {
		return degree;
	}

	double radians() {
		return TWO_PI * (degree / DEGREES_IN_CIRCLE);
	}

	bool operator>(const Angle& other) {
		return degree > other.degree;
	}

	bool operator<(const Angle& other) {
		return degree < other.degree;
	}

	Angle operator+(const Angle& other) {
		return fromDegrees(degree + other.degree);
	}

	Angle operator-(const Angle& other) {
		return fromDegrees(degree - other.degree);
	}

};
