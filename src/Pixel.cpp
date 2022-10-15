#include "Pixel.h"

Pixel::Pixel() {
	R = 0;
	G = 0;
	B = 0;
}

Pixel::Pixel(unsigned char R, unsigned char G, unsigned char B) {
	this->R = R;
	this->G = G;
	this->B = B;
}
unsigned char Pixel::getR() {
	return R;
}
unsigned char Pixel::getG() {
	return G;
}
unsigned char Pixel::getB() {
	return B;
}
void Pixel::setR(unsigned char R) {
	this->R = R;
}
void Pixel::setG(unsigned char G) {
	this->G = G;
}
void Pixel::setB(unsigned char B) {
	this->B = B;
}