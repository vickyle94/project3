#ifndef PROJECT3HEADER_H
#define PROJECT3HEADER_H
#include <string>
#include <stdlib.h>
using namespace std;

//prototype for class automaton
class Automaton
{
public:

   void testRulePrint();
   static const int MAX_DISPLAY_WIDTH = 121;

   Automaton(int rule);
   string toStringCurrentGen();
   bool setRule(int newRule);      // change rule set
   void resetFirstGen();
   bool setDisplayWidth(int width);
   void propagateNewGeneration();
   bool setThisGen(string newGen);


private:
   static const int RULES_SIZE = 8;
   bool rule[RULES_SIZE];
   string thisGen;
   string extremeBit; // bit, "*" or " ", implied everywhere "outside"
   int displayWidth;  // an odd number so it can be perfectly centered

};


int convertCharactersToIndex(char left, char center, char right);

#endif
