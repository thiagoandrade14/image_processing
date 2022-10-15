#include "ImageFile.h"

ImageFile::ImageFile() {
	numberOfPixels = 0;
}

ImageFile::ImageFile(Header header) {
	this->header = header;
	numberOfPixels = header.height * header.width;
}

Header* ImageFile::getHeader() {
	return &header;
}
vector<Pixel>* ImageFile::getPixels() {
	return &pixel;
}
void ImageFile::addPixel(Pixel pixelToAdd) {
	pixel.push_back(pixelToAdd);
}

int ImageFile::getNumberOfPixels() {
	return numberOfPixels;
}

void ImageFile::setNumberOfPixels(int pixels) {
	numberOfPixels = pixels;
}

bool ImageFile::isEquivalent(ImageFile* otherFile) {
	if (ImageFile::getHeader()->idLength != otherFile->getHeader()->idLength) {
		return false;
	}
	if (ImageFile::getHeader()->colorMapType != otherFile->getHeader()->colorMapType) {
		return false;
	}
	if (ImageFile::getHeader()->dataTypeCode != otherFile->getHeader()->dataTypeCode) {
		return false;
	}
	if (ImageFile::getHeader()->colorMapOrigin != otherFile->getHeader()->colorMapOrigin) {
		return false;
	}
	if (ImageFile::getHeader()->colorMapLength != otherFile->getHeader()->colorMapLength) {
		return false;
	}
	if (ImageFile::getHeader()->colorMapDepth != otherFile->getHeader()->colorMapDepth) {
		return false;
	}
	if (ImageFile::getHeader()->xOrigin != otherFile->getHeader()->xOrigin) {
		return false;
	}
	if (ImageFile::getHeader()->yOrigin != otherFile->getHeader()->yOrigin) {
		return false;
	}
	if (ImageFile::getHeader()->width != otherFile->getHeader()->width) {
		return false;
	}
	if (ImageFile::getHeader()->height != otherFile->getHeader()->height) {
		return false;
	}
	if (ImageFile::getHeader()->bitsPerPixel != otherFile->getHeader()->bitsPerPixel) {
		return false;
	}
	if (ImageFile::getHeader()->imageDescriptor != otherFile->getHeader()->imageDescriptor) {
		return false;
	}
	if (ImageFile::getNumberOfPixels() != otherFile->getNumberOfPixels()) {
		return false;
	}
	for (int i = 0; i < ImageFile::getNumberOfPixels(); i++) {
		if (ImageFile::getPixels()->at(i).getB() != otherFile->getPixels()->at(i).getB()) {
			cout << "Pixel " << i << " is not equivalent. B value should be " << (short) otherFile->getPixels()->at(i).getB() << ". It actually is " << (short) ImageFile::getPixels()->at(i).getB() << endl;
			return false;
		}
		if (ImageFile::getPixels()->at(i).getG() != otherFile->getPixels()->at(i).getG()) {
			cout << "Pixel " << i << " is not equivalent. G value should be " << (short)otherFile->getPixels()->at(i).getB() << ". It actually is " << (short)ImageFile::getPixels()->at(i).getB() << endl;
			return false;
		}
		if (ImageFile::getPixels()->at(i).getR() != otherFile->getPixels()->at(i).getR()) {
			cout << "Pixel " << i << " is not equivalent. R value should be " << (short)otherFile->getPixels()->at(i).getB() << ". It actually is " << (short)ImageFile::getPixels()->at(i).getB() << endl;
			return false;
		}
	}
	return true;
}