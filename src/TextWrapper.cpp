#include "TextWrapper.hpp"
#include <iostream>
#include <cstring>
using namespace std;

TextWrapper::TextWrapper(const MyString& input, int maxLineLength){
    this->consoleInput = input.get_data();
    this->maxLineLength = maxLineLength;
    this->wrappedLines = nullptr;
    this->lineCount = 0;
    this->textLength = strlen(consoleInput);
    this->startIndex = 0;
    this->currentLine = new char[maxLineLength + 1];
    this->currentLineLength = 0;
}

TextWrapper::~TextWrapper(){
    if (wrappedLines) {
        for (int i = 0; i <lineCount; ++i)
            delete[] wrappedLines[i];
        delete[] wrappedLines;
    }
    delete[] currentLine;
}

//hlpr mtd: checking if next word fits in the line
bool TextWrapper::isWordFit(int wordLength) const{
    return currentLineLength + wordLength + (currentLineLength > 0 ? 1 : 0) <= maxLineLength;
}

//hlpr mtd: saving current line to wrappedLines[]
void TextWrapper::addCurrentLine(){
    currentLine[currentLineLength] = '\0';
    wrappedLines[lineCount] = new char[currentLineLength + 1];
    strcpy(wrappedLines[lineCount], currentLine);
    lineCount++;
    currentLineLength = 0;
}

//hlpr mtd: calculating next word's length
int TextWrapper::getNextWordLength(){
    int len = 0;
    while (startIndex + len < textLength && consoleInput[startIndex + len] != ' ')
        len++;
    return len;
}

//hlpr mtd: skiping a space char
void TextWrapper::skipSpace(){
    if (startIndex < textLength && consoleInput[startIndex] == ' ')
        startIndex++;
}

void TextWrapper::wrapText(){
    int maxLines = (textLength / maxLineLength) + 10;
    wrappedLines = new char*[maxLines];

    while (startIndex < textLength) {
        int wordLength = getNextWordLength();

        if (!isWordFit(wordLength)) {
            addCurrentLine();//flushing line
        }

        if (currentLineLength > 0)
            currentLine[currentLineLength++] = ' ';

        strncpy(currentLine + currentLineLength, consoleInput + startIndex, wordLength);
        currentLineLength += wordLength;
        startIndex += wordLength;
        skipSpace();
    }

    if (currentLineLength > 0) {
        addCurrentLine();
    }
}

void TextWrapper::printWrapped(){
    int bubbleWidth = 0;
    for (int i = 0; i < lineCount; ++i) {
        int len = strlen(wrappedLines[i]);
        if (len > bubbleWidth) bubbleWidth = len;
    }

    cout << " ";
    for (int i = 0; i < bubbleWidth + 2; ++i)cout << "_";
    cout << endl;

    for(int i = 0; i < lineCount; ++i){
        cout << "/ " << wrappedLines[i];
        int pad = bubbleWidth - strlen(wrappedLines[i]);
        for(int j = 0; j < pad; ++j) cout << " ";
        cout << " \\" << endl;
    }

    cout << " ";
    for(int i = 0; i < bubbleWidth + 2; ++i)cout << "_";
    cout << endl;
    cout << "     \\" << endl;
    cout << "      \\" << endl;
    cout << "        /\\_/\\  (" << endl;
    cout << "       ( ^.^ ) _)" << endl;
    cout << "         \\\"/  (" << endl;
    cout << "       ( | | )" << endl;
    cout << "      (__d b__)" << endl;
}
