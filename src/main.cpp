#include "ImageFile.h"

using namespace std;
ImageFile* readTGAFile(string filePath);
void writeTGAFile(ImageFile* image, string filePath);
ImageFile* multiply(ImageFile* fileOne, ImageFile* fileTwo);
ImageFile* substract(ImageFile* fileOne, ImageFile* fileTwo);
ImageFile* screen(ImageFile* fileOne, ImageFile* fileTwo);
ImageFile* overlay(ImageFile* fileOne, ImageFile* fileTwo);


int main() {

	unsigned int totalScore = 0;
	
	/*PART ONE*/
	string inputFilePathOne = "input/layer1.tga";
	string inputFilePathTwo = "input/pattern1.tga";
	string outputFilePath = "output/part1.tga";
	string testFile = "examples/EXAMPLE_part1.tga";
	ImageFile* imageOne = readTGAFile(inputFilePathOne);
	ImageFile* imageTwo = readTGAFile(inputFilePathTwo);
	ImageFile* newImage = multiply(imageOne, imageTwo);
	ImageFile* testImage = readTGAFile(testFile);
	writeTGAFile(newImage, outputFilePath);
	cout << "Test #1... ";
	if (newImage->isEquivalent(testImage)) {
		cout << "Passed!" << endl;
		cout << endl;
		totalScore += 11;
	}
	else {
		cout << "Failed!" << endl;
		cout << endl;
	}

	/*PART TWO*/
	inputFilePathOne = "input/layer2.tga";
	inputFilePathTwo = "input/car.tga";
	outputFilePath = "output/part2.tga";
	testFile = "examples/EXAMPLE_part2.tga";
	imageOne = readTGAFile(inputFilePathOne);
	imageTwo = readTGAFile(inputFilePathTwo);
	newImage = substract(imageTwo, imageOne);
	testImage = readTGAFile(testFile);
	writeTGAFile(newImage, outputFilePath);
	cout << "Test #2... ";
	if (newImage->isEquivalent(testImage)) {
		cout << "Passed!" << endl;
		cout << endl;
		totalScore += 11;
	}
	else {
		cout << "Failed!" << endl;
		cout << endl;
	}

	/*PART THREE*/
	inputFilePathOne = "input/layer1.tga";
	inputFilePathTwo = "input/pattern2.tga";
	string inputFilePathThree = "input/text.tga";
	outputFilePath = "output/part3.tga";
	testFile = "examples/EXAMPLE_part3.tga";
	imageOne = readTGAFile(inputFilePathOne);
	imageTwo = readTGAFile(inputFilePathTwo);
	ImageFile* imageThree = readTGAFile(inputFilePathThree);
	newImage = multiply(imageOne, imageTwo);
	ImageFile* newImageTwo = screen(imageThree, newImage);
	testImage = readTGAFile(testFile);
	writeTGAFile(newImageTwo, outputFilePath);
	cout << "Test #3... ";
	if (newImageTwo->isEquivalent(testImage)) {
		cout << "Passed!" << endl;
		cout << endl;
		totalScore += 11;
	}
	else {
		cout << "Failed!" << endl;
		cout << endl;
	}

	/*PART FOUR*/
	inputFilePathOne = "input/layer2.tga";
	inputFilePathTwo = "input/circles.tga";
	inputFilePathThree = "input/pattern2.tga";
	outputFilePath = "output/part4.tga";
	testFile = "examples/EXAMPLE_part4.tga";
	imageOne = readTGAFile(inputFilePathOne);
	imageTwo = readTGAFile(inputFilePathTwo);
	imageThree = readTGAFile(inputFilePathThree);
	newImage = multiply(imageOne, imageTwo);
	newImageTwo = substract(newImage, imageThree);
	testImage = readTGAFile(testFile);
	writeTGAFile(newImageTwo, outputFilePath);
	cout << "Test #4... ";
	if (newImageTwo->isEquivalent(testImage)) {
		cout << "Passed!" << endl;
		cout << endl;
		totalScore += 11;
	}
	else {
		cout << "Failed!" << endl;
		cout << endl;
	}

	/*PART FIVE*/
	inputFilePathOne = "input/layer1.tga";
	inputFilePathTwo = "input/pattern1.tga";
	outputFilePath = "output/part5.tga";
	testFile = "examples/EXAMPLE_part5.tga";
	imageOne = readTGAFile(inputFilePathOne);
	imageTwo = readTGAFile(inputFilePathTwo);
	newImage = overlay(imageOne, imageTwo);
	testImage = readTGAFile(testFile);
	writeTGAFile(newImage, outputFilePath);
	cout << "Test #5... ";
	if (newImage->isEquivalent(testImage)) {
		cout << "Passed!" << endl;
		cout << endl;
		totalScore += 11;
	}
	else {
		cout << "Failed!" << endl;
		cout << endl;
	}

	/*PART SIX*/
	inputFilePathOne = "input/car.tga";
	outputFilePath = "output/part6.tga";
	testFile = "examples/EXAMPLE_part6.tga";
	imageOne = readTGAFile(inputFilePathOne);
	for (int i = 0; i < imageOne->getNumberOfPixels(); i++) {
		if (imageOne->getPixels()->at(i).getG() < 55) {
			imageOne->getPixels()->at(i).setG(imageOne->getPixels()->at(i).getG() + 200);
		}
		else {
			imageOne->getPixels()->at(i).setG(255);
		}
	}
	testImage = readTGAFile(testFile);
	writeTGAFile(imageOne, outputFilePath);
	cout << "Test #6... ";
	if (imageOne->isEquivalent(testImage)) {
		cout << "Passed!" << endl;
		cout << endl;
		totalScore += 11;
	}
	else {
		cout << "Failed!" << endl;
		cout << endl;
	}

	/*PART SEVEN*/
	inputFilePathOne = "input/car.tga";
	outputFilePath = "output/part7.tga";
	testFile = "examples/EXAMPLE_part7.tga";
	imageOne = readTGAFile(inputFilePathOne);
	for (int i = 0; i < imageOne->getNumberOfPixels(); i++) {
		int newR = 4 * imageOne->getPixels()->at(i).getB();
		if (newR > 255) {
			newR = 255;
		}
		imageOne->getPixels()->at(i).setR(0); //I know these are switched up because of how TGA stores pixel values. I just found  
		imageOne->getPixels()->at(i).setB(newR); //more convenient to change it here instead of editing the rest of the code.
	}
	testImage = readTGAFile(testFile);
	writeTGAFile(imageOne, outputFilePath);
	cout << "Test #7... ";
	if (imageOne->isEquivalent(testImage)) {
		cout << "Passed!" << endl;
		cout << endl;
		totalScore += 11;
	}
	else {
		cout << "Failed!" << endl;
		cout << endl;
	}

	/*PART EIGHT*/
	inputFilePathOne = "input/car.tga";
	outputFilePath = "output/part8_b.tga";	
	string outputFilePathTwo = "output/part8_g.tga";
	string outputFilePathThree = "output/part8_r.tga";
	testFile = "examples/EXAMPLE_part8_r.tga";
	string testFileTwo = "examples/EXAMPLE_part8_g.tga";
	string testFileThree = "examples/EXAMPLE_part8_b.tga";
	imageOne = readTGAFile(inputFilePathOne);
	for (int i = 0; i < imageOne->getNumberOfPixels(); i++) {
		unsigned char R = imageOne->getPixels()->at(i).getR();
		imageOne->getPixels()->at(i).setB(R);
		imageOne->getPixels()->at(i).setG(R);
	}
	imageTwo = readTGAFile(inputFilePathOne);
	for (int i = 0; i < imageTwo->getNumberOfPixels(); i++) {
		unsigned char G = imageTwo->getPixels()->at(i).getG();
		imageTwo->getPixels()->at(i).setR(G);
		imageTwo->getPixels()->at(i).setB(G);
	}
	imageThree = readTGAFile(inputFilePathOne);
	for (int i = 0; i < imageThree->getNumberOfPixels(); i++) {
		unsigned char B = imageThree->getPixels()->at(i).getB();
		imageThree->getPixels()->at(i).setR(B);
		imageThree->getPixels()->at(i).setG(B);
	}
	testImage = readTGAFile(testFile);
	ImageFile* testImageTwo = readTGAFile(testFileTwo);
	ImageFile* testImageThree = readTGAFile(testFileThree);
	writeTGAFile(imageOne, outputFilePathThree);
	writeTGAFile(imageTwo, outputFilePathTwo);
	writeTGAFile(imageThree, outputFilePath);

	cout << "Test #8... ";
	if (imageOne->isEquivalent(testImageThree) && imageTwo->isEquivalent(testImageTwo) && imageThree->isEquivalent(testImage)) {
		cout << "Passed!" << endl;
		cout << endl;
		totalScore += 11;
	}
	else {
		cout << "Failed!" << endl;
		cout << endl;
	}

	/*PART NINE*/
	inputFilePathOne = "input/layer_red.tga";
	inputFilePathTwo = "input/layer_green.tga";
	inputFilePathThree = "input/layer_blue.tga";
	outputFilePath = "output/part9.tga";
	testFile = "examples/EXAMPLE_part9.tga";
	imageOne = readTGAFile(inputFilePathOne);
	imageTwo = readTGAFile(inputFilePathTwo);
	imageThree = readTGAFile(inputFilePathThree);
	for (int i = 0; i < imageOne->getNumberOfPixels(); i++) {
		unsigned char G = imageTwo->getPixels()->at(i).getG();
		unsigned char B = imageThree->getPixels()->at(i).getR();
		imageOne->getPixels()->at(i).setG(G);
		imageOne->getPixels()->at(i).setR(B);
	}
	testImage = readTGAFile(testFile);
	writeTGAFile(imageOne, outputFilePath);
	cout << "Test #9... ";
	if (imageOne->isEquivalent(testImage)) {
		cout << "Passed!" << endl;
		cout << endl;
		totalScore += 11;
	}
	else {
		cout << "Failed!" << endl;
		cout << endl;
	}


	/*PART TEN*/
	inputFilePathOne = "input/text2.tga";
	outputFilePath = "output/part10.tga";
	testFile = "examples/EXAMPLE_part10.tga";
	imageOne = readTGAFile(inputFilePathOne);
	imageTwo = readTGAFile(inputFilePathOne);
	for (int i = 0; i < imageOne->getNumberOfPixels(); i++) {
		unsigned char R = imageTwo->getPixels()->at(imageTwo->getNumberOfPixels() - i - 1).getR();
		unsigned char G = imageTwo->getPixels()->at(imageTwo->getNumberOfPixels() - i - 1).getG();
		unsigned char B = imageTwo->getPixels()->at(imageTwo->getNumberOfPixels() - i - 1).getB();
		imageOne->getPixels()->at(i).setR(R);
		imageOne->getPixels()->at(i).setG(G);
		imageOne->getPixels()->at(i).setB(B);
	}
	testImage = readTGAFile(testFile);
	writeTGAFile(imageOne, outputFilePath);
	cout << "Test #10... ";
	if (imageOne->isEquivalent(testImage)) {
		cout << "Passed!" << endl;
		cout << endl;
		totalScore += 11;
	}
	else {
		cout << "Failed!" << endl;
		cout << endl;
	}

	cout << "Test results: " << totalScore << "/110" << endl;

	/*EXTRA CREDIT*/
	inputFilePathOne = "input/car.tga";
	inputFilePathTwo = "input/circles.tga";
	inputFilePathThree = "input/pattern1.tga";
	testFile = "examples/EXAMPLE_extracredit.tga";
	string inputFilePathFour = "input/text.tga";
	outputFilePath = "output/extracredit.tga";
	imageOne = readTGAFile(inputFilePathOne);
	imageTwo = readTGAFile(inputFilePathTwo);
	imageThree = readTGAFile(inputFilePathThree);
	ImageFile* imageFour = readTGAFile(inputFilePathFour);
	testImage = readTGAFile(testFile);
	ImageFile extraCredit;
	extraCredit.setNumberOfPixels(imageOne->getNumberOfPixels() + imageTwo->getNumberOfPixels() + imageThree->getNumberOfPixels() + imageFour->getNumberOfPixels());
	extraCredit.getHeader()->height = imageOne->getHeader()->height + imageFour->getHeader()->height;
	extraCredit.getHeader()->width = imageFour->getHeader()->width + imageThree->getHeader()->width;
	extraCredit.getHeader()->bitsPerPixel = 24;
	for (int i = 0; i < imageFour->getHeader()->height; i++) {
		for (int j = 0; j < imageFour->getHeader()->width; j++) {
			extraCredit.pixel.push_back(imageFour->pixel.at(j + imageFour->getHeader()->width * i));
		}
		for (int j = 0; j < imageThree->getHeader()->width; j++) {
			extraCredit.pixel.push_back(imageThree->pixel.at(j + imageFour->getHeader()->width * i));
		}
	}
	for (int i = 0; i < imageOne->getHeader()->height; i++) {
		for (int j = 0; j < imageOne->getHeader()->width; j++) {
			extraCredit.pixel.push_back(imageOne->pixel.at(j + imageFour->getHeader()->width * i));
		}
		for (int j = 0; j < imageTwo->getHeader()->width; j++) {
			extraCredit.pixel.push_back(imageTwo->pixel.at(j + imageFour->getHeader()->width * i));
		}
	}
	writeTGAFile(&extraCredit, outputFilePath);

	if (extraCredit.isEquivalent(testImage)) {
		cout << "Extra credit is correct.";
	}


	return 0;
}

ImageFile* readTGAFile(string filePath) {
	fstream inFS;
	inFS.open(filePath, ios_base::in | ios_base::binary);
	Header headerObject;
	inFS.read(&headerObject.idLength, sizeof(headerObject.idLength));
	inFS.read(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
	inFS.read(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));
	inFS.read((char*)& headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
	inFS.read((char*)& headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
	inFS.read((char*)& headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));
	inFS.read((char*)& headerObject.xOrigin, sizeof(headerObject.xOrigin));
	inFS.read((char*)& headerObject.yOrigin, sizeof(headerObject.yOrigin));
	inFS.read((char*)& headerObject.width, sizeof(headerObject.width));
	inFS.read((char*)& headerObject.height, sizeof(headerObject.height));
	inFS.read(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));
	inFS.read(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));

	ImageFile* newImage = new ImageFile(headerObject);
	for (int i = 0; i < newImage->getNumberOfPixels(); i++) {
		unsigned char R;
		unsigned char G;
		unsigned char B;
		inFS.read((char*)& R, sizeof(char));
		inFS.read((char*)& G, sizeof(char));
		inFS.read((char*)& B, sizeof(char));
		Pixel newPixel(R, G, B);
		newImage->addPixel(newPixel);
	}
	inFS.close();
	return newImage;
}

void writeTGAFile(ImageFile* image, string filePath) {
	fstream outFS(filePath, ios_base::out | ios_base::binary);
	if (outFS.is_open()) {
		Header* thatHeader = image->getHeader();
		outFS.write(&thatHeader->idLength, sizeof(char));
		outFS.write(&thatHeader->colorMapType, sizeof(char));
		outFS.write(&thatHeader->dataTypeCode, sizeof(char));
		outFS.write((char*)& thatHeader->colorMapOrigin, sizeof(short));
		outFS.write((char*)& thatHeader->colorMapLength, sizeof(short));
		outFS.write(&thatHeader->colorMapDepth, sizeof(char));
		outFS.write((char*)& thatHeader->xOrigin, sizeof(short));
		outFS.write((char*)& thatHeader->yOrigin, sizeof(short));
		outFS.write((char*)& thatHeader->width, sizeof(short));
		outFS.write((char*)& thatHeader->height, sizeof(short));
		outFS.write(&thatHeader->bitsPerPixel, sizeof(char));
		outFS.write(&thatHeader->imageDescriptor, sizeof(char));
		for (int i = 0; i < image->getNumberOfPixels(); i++) {
			unsigned char R = image->pixel.at(i).getR();
			unsigned char G = image->pixel.at(i).getG();
			unsigned char B = image->pixel.at(i).getB();
			outFS.write((char*)& R, sizeof(char));
			outFS.write((char*)& G, sizeof(char));
			outFS.write((char*)& B, sizeof(char));
		}
	}
	outFS.close();
}

ImageFile* multiply(ImageFile* fileOne, ImageFile* fileTwo) {
	ImageFile* newImage = new ImageFile(*fileOne->getHeader()); //in this operation, the header will have the same values as the first file
	for (int i = 0; i < fileOne->getNumberOfPixels(); i++) {
		double ftempR = fileOne->getPixels()->at(i).getR() / 255.0;
		double stempR = fileTwo->getPixels()->at(i).getR() / 255.0;
		double ftempG = fileOne->getPixels()->at(i).getG() / 255.0;
		double stempG = fileTwo->getPixels()->at(i).getG() / 255.0;
		double ftempB = fileOne->getPixels()->at(i).getB() / 255.0;
		double stempB = fileTwo->getPixels()->at(i).getB() / 255.0;
		int R = (ftempR * stempR * 255) + 0.5f;
		int G = (ftempG * stempG * 255) + 0.5f;
		int B = (ftempB * stempB * 255) + 0.5f;
		newImage->getPixels()->push_back(Pixel(R, G, B));
	}
	return newImage;
}

ImageFile* substract(ImageFile* fileOne, ImageFile* fileTwo) {
	ImageFile* newImage = new ImageFile(*fileTwo->getHeader());
	for (int i = 0; i < fileTwo->getNumberOfPixels(); i++) {
		int R = (fileOne->getPixels()->at(i).getR() - fileTwo->getPixels()->at(i).getR());
		if (R < 0) {
			R = 0;
		}
		int G = (fileOne->getPixels()->at(i).getG() - fileTwo->getPixels()->at(i).getG());
		if (G < 0) {
			G = 0;
		}
		int B = (fileOne->getPixels()->at(i).getB() - fileTwo->getPixels()->at(i).getB());
		if (B < 0) {
			B = 0;
		}
		newImage->getPixels()->push_back(Pixel(R, G, B));
	}
	return newImage;
}

ImageFile* screen(ImageFile* fileOne, ImageFile* fileTwo) {
	ImageFile* newImage = new ImageFile(*fileTwo->getHeader());
	for (int i = 0; i < fileTwo->getNumberOfPixels(); i++) {
		double ftempR = ((double)fileOne->getPixels()->at(i).getR() / 255);
		double stempR = ((double)fileTwo->getPixels()->at(i).getR() / 255);
		double ftempG = ((double)fileOne->getPixels()->at(i).getG() / 255);
		double stempG = ((double)fileTwo->getPixels()->at(i).getG() / 255);
		double ftempB = ((double)fileOne->getPixels()->at(i).getB() / 255);
		double stempB = ((double)fileTwo->getPixels()->at(i).getB() / 255);
		double tempR = 1 - ((1 - ftempR) * (1 - stempR));
		double tempG = 1 - ((1 - ftempG) * (1 - stempG));
		double tempB = 1 - ((1 - ftempB) * (1 - stempB));
		int R = ((tempR * 255) + 0.5f);
		int G = ((tempG * 255) + 0.5f);
		int B = ((tempB * 255) + 0.5f);
		newImage->getPixels()->push_back(Pixel(R, G, B));
	}
	return newImage;
}

ImageFile* overlay(ImageFile* fileOne, ImageFile* fileTwo) {
	ImageFile* newImage = new ImageFile(*fileTwo->getHeader());
	for (int i = 0; i < fileTwo->getNumberOfPixels(); i++) {
		int sumOfAll = fileTwo->getPixels()->at(i).getR() + fileTwo->getPixels()->at(i).getG() + fileTwo->getPixels()->at(i).getB();
		double grayTone = sumOfAll / 765.0;
		if (grayTone > 0.5) {
			double ftempR = ((double)fileOne->getPixels()->at(i).getR() / 255);
			double stempR = ((double)fileTwo->getPixels()->at(i).getR() / 255);
			double ftempG = ((double)fileOne->getPixels()->at(i).getG() / 255);
			double stempG = ((double)fileTwo->getPixels()->at(i).getG() / 255);
			double ftempB = ((double)fileOne->getPixels()->at(i).getB() / 255);
			double stempB = ((double)fileTwo->getPixels()->at(i).getB() / 255);
			double tempR = 1 - (2 * (1 - ftempR) * (1 - stempR));
			double tempG = 1 - (2 * (1 - ftempG) * (1 - stempG));
			double tempB = 1 - (2 * (1 - ftempB) * (1 - stempB));
			int R = ((tempR * 255) + 0.5f);
			int G = ((tempG * 255) + 0.5f);
			int B = ((tempB * 255) + 0.5f);
			newImage->getPixels()->push_back(Pixel(R, G, B));
		}
		else {
			double ftempR = ((double)fileOne->getPixels()->at(i).getR() / 255);
			double stempR = ((double)fileTwo->getPixels()->at(i).getR() / 255);
			double ftempG = ((double)fileOne->getPixels()->at(i).getG() / 255);
			double stempG = ((double)fileTwo->getPixels()->at(i).getG() / 255);
			double ftempB = ((double)fileOne->getPixels()->at(i).getB() / 255);
			double stempB = ((double)fileTwo->getPixels()->at(i).getB() / 255);
			double tempR = 2 * ftempR * stempR;
			double tempG = 2 * ftempG * stempG;
			double tempB = 2 * ftempB * stempB;
			int R = ((tempR * 255) + 0.5f);
			int G = ((tempG * 255) + 0.5f);
			int B = ((tempB * 255) + 0.5f);
			newImage->getPixels()->push_back(Pixel(R, G, B));
		}
	}
	return newImage;
}