
class Pixel {
private:
	unsigned char R;
	unsigned char G;
	unsigned char B;
public:
	Pixel();
	Pixel(unsigned char R, unsigned char G, unsigned char B);
	unsigned char getR();
	unsigned char getG();
	unsigned char getB();
	void setR(unsigned char R);
	void setG(unsigned char G);
	void setB(unsigned char B);
};

