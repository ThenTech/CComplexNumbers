#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/**
*	Returns the sign of a given number.
*/
#define sign(x)			(x < 0 ? -1 : 1)

/**
*	Convert degrees to radians.
*/
#define DEG_TO_RAD(x)	(x * M_PI / 180)

/**
*	Convert radians to degrees.
*/
#define RAD_TO_DEG(x)	(x * 180 / M_PI)

/**
*	Structure representing a complex number.
*/
typedef const struct cNumber {
	double real; double imag;
	double magn; double angle;
};

/**
*	Calculate and return the real part of a complex number.
*/
double creal(struct cNumber c) {
	return c.magn * cos(DEG_TO_RAD(c.angle));
}

double real(double magn, double angle) {
	return magn * cos(DEG_TO_RAD(angle));
}

/**
*	Calculate and return the imaginary part of a complex number.
*/
double cimag(struct cNumber c) {
	return c.magn * sin(DEG_TO_RAD(c.angle));
}

double imag(double magn, double angle) {
	return magn * sin(DEG_TO_RAD(angle));
}

/**
*	Calculate and return the magnitude of a complex number.
*/
double cmagn(struct cNumber c) {
	return sqrt(c.real * c.real + c.imag * c.imag);
}

double magn(double real, double imag) {
	return sqrt(real * real + imag * imag);
}

/**
*	Calculate and return the angle of a complex number.
*/
double cangle(struct cNumber c) {
	return RAD_TO_DEG(atan2(c.imag, c.real));
}

double angle(double real, double imag) {
	return RAD_TO_DEG(atan2(imag, real));
}

/**
*	Create and return a new complex number from X+iY.
*/
struct cNumber newCNmbrR(double x, double y)	{
	return (struct cNumber) { .real = x, .imag = y, .magn = magn(x, y), .angle = angle(x, y) };
}

/**
*	Create and return a new complex number from Z<O.
*/
struct cNumber newCNmbrP(double z, double o)	{
	return (struct cNumber) { .real = real(z, o), .imag = imag(z, o), .magn = z, .angle = o };
}

/**
*	Add 2 complex numbers.
*/
struct cNumber cadd(struct cNumber c1, struct cNumber c2) {
	return newCNmbrR(c1.real + c2.real, c1.imag + c2.imag);
}

/**
*	Subtract 2 complex numbers.
*/
struct cNumber csub(struct cNumber c1, struct cNumber c2) {
	return newCNmbrR(c1.real - c2.real, c1.imag - c2.imag);
}

/**
*	Multiply 2 complex numbers.
*/
struct cNumber cmul(struct cNumber c1, struct cNumber c2) {
	return newCNmbrP(c1.magn * c2.magn, c1.angle + c2.angle);
}

/**
*	Devide 2 complex numbers.
*/
struct cNumber cdiv(struct cNumber c1, struct cNumber c2) {
	return newCNmbrP(c1.magn / c2.magn, c1.angle - c2.angle);
}

/**
*	Conjugate a complex number, invert the imaginary part.
*/
struct cNumber cconj(struct cNumber c) {
	return newCNmbrR(c.real, -c.imag);
}

/**
*	Print a complex number in rectangular form X+iY.
*/
void toStringCNmbrR(struct cNumber Z) {
	printf("%g %s %gi", Z.real, sign(Z.imag) < 0 ? "-" : "+", fabs(Z.imag));
}

/**
*	Print a complex number in polar form Z<O.
*/
void toStringCNmbrP(struct cNumber Z) {
	printf("%g < %g", Z.magn, Z.angle);
}
