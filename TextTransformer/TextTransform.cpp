#include "TextTransform.h"

TextTransform::TextTransform(const TextTransform &Item){
	keyBoard = new char[40];
	encoding =  new char[40];
	for(unsigned int index = 0; index < 40; index++){
		keyBoard[index] = Item.keyBoard[index];
		encoding[index] = Item.encoding[index];
	}
}

TextTransform::TextTransform(void)
{
	keyBoard = new char[40];
	encoding =  new char[40];
	char temp[] = {'1','2','3','4','5','6','7','8','9','0',
		'q','w','e','r','t','y','u','i','o','p',
		'a','s','d','f','g','h','j','k','l',';',
		'z','x','c','v','b','n','m',',','.','/'
	};
	for(unsigned int index = 0; index < 40; index++){
		keyBoard[index] = temp[index];
		encoding[index] = temp[index];
	}
}

void TextTransform::HorizontalSwap(){
	for(unsigned int y = 0; y < 4; y++){
		for(unsigned int x = 0; x < 5; x++){
			Swap(encoding[(0+x) + y*10],encoding[(9-x) + y*10]);
		} 
	}
}

void TextTransform::VerticalSwap(){
	for(unsigned int x = 0; x < 10; x++){
		Swap(encoding[x + 0*10],encoding[x + 3*10]);
		Swap(encoding[x + 1*10],encoding[x + 2*10]);
	} 
}



void TextTransform::Shift(int Amount){
	Amount = Amount%KEYBOARDSIZE;
	char temp[40];
	for(unsigned int index = 0;index < KEYBOARDSIZE;index++){
		int currentIndex = Wrap(Amount + index,0,KEYBOARDSIZE);
		temp[currentIndex] = encoding[index];
	}

	for(unsigned int index = 0; index < KEYBOARDSIZE; index++){
		encoding[index] = temp[index];
	}
}



void TextTransform::Swap(char& One, char&Two){
	char temp = One;
	One = Two;
	Two = temp;
}


string * TextTransform::ToString(){
	string * temp = new string();

	temp->append("Standard KeyBoard\n\n");
	for(unsigned int y = 0; y < 4; y++){
		for(unsigned int x = 0; x < 10; x++){
			temp->append(1,keyBoard[x + y*10]);
			temp->append(" ");
		} 
		temp->append("\n");
	} 
	temp->append("\n\n");
	temp->append("Transformation Encoding\n\n");
	for(unsigned int y = 0; y < 4; y++){
		for(unsigned int x = 0; x < 10; x++){
			temp->append(1,encoding[x + y*10]);
			temp->append(" ");
		} 
		temp->append("\n");
	} 

	return temp;
}

int TextTransform::Wrap(int Value, int Min, int Max){
	if(Value >= Max){
		return (Value - Max) + Min;
	}
	if(Value < Min){
		return (Value - Min) + Max;
	}
	return Value;
}

void TextTransform::EncodeText(string FileLocation){
	ifstream stream;
	string token = "";
	string answer = "";
	stream.open(FileLocation.c_str());

	while(getline(stream,token)){
		for(int endex = 0; endex < token.length();endex++){
			char temp = token.at(endex);
			for(unsigned int index = 0; index < KEYBOARDSIZE; index++){
				if(temp == keyBoard[index]){
					answer.append(1,encoding[index]);
				}
				if(temp == 32){
					answer.append(" ");
				}
			}
		}
	}

	ofstream results;
	results.open("EncdedText.txt",std::ios::out);
	results << answer.c_str();
	results.close();
	stream.close();
}

void TextTransform::GenerateEncoding(string FileLocation){
	ifstream stream;
	string token = "";
	stream.open(FileLocation.c_str());
	while(getline(stream,token,',')){
		char temp = token.at(0);
		if(isalpha(temp)){
			if(temp == 'H'){
				HorizontalSwap();
			}
			if(temp == 'V'){
				VerticalSwap();
			}	
		}else{
			if(isdigit(temp) || temp == '-'){
				int number = atoi(token.c_str());
				Shift(number);
			}
		}
	}	
	stream.close();
	ofstream results;
	results.open("Results.txt",std::ios::out);
	results << ToString()->c_str();
	results.close();
}

TextTransform::~TextTransform(void)
{
}
