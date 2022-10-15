#include "Header.h"
#include "Pixel.h"

class ImageFile {
private:
	Header header;	
	int numberOfPixels;	
public:	
	vector<Pixel> pixel;
	ImageFile();
	ImageFile(Header header);
	Header* getHeader();
	vector<Pixel>* getPixels();
	void addPixel(Pixel pixelToAdd);
	int getNumberOfPixels();
	void setNumberOfPixels(int pixels);
	bool isEquivalent(ImageFile* otherFile);
};