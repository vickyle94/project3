#include <string>
#include <iostream>
#include "project3header.h"
using std::cout; using std::endl;


//constructor
Automaton::Automaton(int rule){
    //call setRule
    setRule(rule);
    //establish seed: *(1s) centered by many blanks(0's) by
    resetFirstGen();
}

//embeds thisGen into returnString with length displayWidth long
string Automaton::toStringCurrentGen(){
    string returnString = "";
    if (thisGen.length() < displayWidth) {
        //thisGen must be centered
        int spacesRequired = 0;
        spacesRequired = (displayWidth - thisGen.length())/2;
        for (int i = 0; i < spacesRequired; i++){
            returnString = returnString + extremeBit;
        }
        returnString = returnString + thisGen;
        for (int i = 0; i <= spacesRequired; i++){
            returnString = returnString + extremeBit;
        }
        return returnString;
    }  
    else if (thisGen.length() > displayWidth) {
        //thisGen must be truncated
        int charsRemovedForEachSide;
        charsRemovedForEachSide = (thisGen.length() - displayWidth)/2;
        returnString = thisGen;
        returnString.erase(0, charsRemovedForEachSide);
        returnString.erase(returnString.length() - charsRemovedForEachSide, charsRemovedForEachSide);
        return returnString;
    } else {
        //if thisGen length == displayWidth
        returnString = thisGen;
        return returnString;
    }
}


//mutators
bool Automaton::setRule(int newRule) {
    //sanitize input 
    if (newRule < 0 || newRule > 255 ) {
        return false;
    }
    int i = 0;
    //initialize mask variable with 128
    int mask  = 128;
    while (mask > 0) {
        //perform ANDing of two numbers
        //check whether result of ANDing is 0 or not
        if ((newRule & mask) == 0) {
            rule[i] = false;
        } else {
            rule[i] = true;
        }
        //right shift mask variable by 1 
        mask = mask >> 1;
        i++;
    }
    return true;
}
        
bool Automaton::setDisplayWidth(int width){
    //make sure width is an odd number 
    for (int i = 0; i < Automaton::MAX_DISPLAY_WIDTH; i++){
        if (i % 2 != 0){
            displayWidth = width;
            return true;
        }
    }
    return false;
}


void Automaton::resetFirstGen(){
    //set thisGen to "*"
    thisGen = "*";
    //set extremebit to " "
    extremeBit = " ";
}

void Automaton::propagateNewGeneration(){
    int index;
    string newGen = "";
    // copy nextGen to thisGen to complete cycle
    string nextGen = thisGen;
    // pad thisGen with four extremeBits
    nextGen = extremeBit + extremeBit + nextGen + extremeBit + extremeBit;
    // apply rule to create nextGen
    for (int i = 0; i < nextGen.length(); i++) {
        if (i == 0 || i == nextGen.length()-1){
            continue;
        }
        index = convertCharactersToIndex(nextGen[i - 1], nextGen[i], nextGen[i + 1]);
        if (rule[index]) {
            newGen = newGen + "*"; 
        } else {
            newGen = newGen + " ";
        }        
    } 

    thisGen = newGen;

    //changing extremeBit
    if (extremeBit == "*") {
        if (rule[0]) {
            extremeBit = "*";
        } else {
            extremeBit = " ";
        } 
    } 
    else if (extremeBit == " ") {
        if (rule[7]) {
            extremeBit = "*";
        } else {
            extremeBit = " ";
        }
    }
}

//helper function 
int convertCharactersToIndex(char left, char center, char right){
    int runningTotal = 0;
    int index;
    int convertedLeft;
    int convertedCenter;
    int convertedRight;
    if (left == '*') {
        convertedLeft = 1;
    } else {
        convertedLeft = 0;
    }
    if (center == '*') {
        convertedCenter = 1;
    } else {
        convertedCenter = 0;
    }
    if (right == '*') {
        convertedRight = 1;
    } else {
        convertedRight = 0;
    }
    runningTotal = (convertedLeft * 4) + (convertedCenter * 2) + (convertedRight * 1);
    //7 represents max index of rule
    index = 7 - runningTotal;
    return index;
}

bool Automaton::setThisGen(string newGen){
    thisGen = newGen;
    return true;
}


