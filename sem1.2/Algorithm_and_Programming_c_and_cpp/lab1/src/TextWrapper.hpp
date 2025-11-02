#ifndef TEXTWRAPPER_HPP
#define TEXTWRAPPER_HPP

#include "mystring.hpp"

class TextWrapper{

	private:
	const char* consoleInput;
	char** wrappedLines;
	int maxLineLength;
	int lineCount;
	int textLength;
	int startIndex;
	char* currentLine;
	int currentLineLength;

	//helper methods(for conditions)
	bool isWordFit(int wordLength) const;
	void addCurrentLine();
	int getNextWordLength();
	void skipSpace();

    public:
	TextWrapper(const MyString& input, int maxLineLength);
	~TextWrapper();

	void wrapText();//performing full wrapping
	void printWrapped();//prints wrapped lines in bubble
};

#endif//TEXTWRAPPER_HPP

