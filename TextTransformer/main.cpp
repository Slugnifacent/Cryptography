#pragma once
#include<cstdio>
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include "TextTransform.h";

int main(int argc, char*argv[]){
	TextTransform text;
	text.GenerateEncoding("File.txt");
	fstream file();
	ofstream fileStream;
	fileStream.open("Text.txt",ios_base::out);
	string value = "";
	for(int index = 0; index < 127; index++){
		char character = 32;
		value.append(1,character);
		double * temp = new double[50];
		temp[5] = 'a';
		delete[] temp;
	}
	value = "1457857847800000000000098753000000000";
	fileStream << value.c_str();
	fileStream.close();

	
	text.EncodeText("Text.txt");



}