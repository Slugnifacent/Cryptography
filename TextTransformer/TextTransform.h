#pragma once
#include<string>
#include<cmath>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;
class TextTransform
{

	int Wrap(int Value, int Min, int Max);
	
public:

	static const int KEYBOARDSIZE = 40;

	char * encoding;
	char * keyBoard;

	
	void HorizontalSwap();
	void VerticalSwap();
	void Shift(int Amount);
	void Swap(char& One, char&Two);
	void GenerateEncoding(string FileLocation);
	void EncodeText(string FileLocation);
	TextTransform(void);
	TextTransform(const TextTransform &Item);
	string* ToString();
	~TextTransform(void);

};

