#include <string>
#include <iostream>
#include "project3header.h"
using std::cout; using std::endl;

//show four different sample runs of width 79, giving 100 generations per run
//Show runs for rules 4, 126 and 131, and one of your choice


int main (){
    cout << convertCharactersToIndex(1, 1, 1) << endl;
    cout << convertCharactersToIndex(1, 1, 0) << endl;
    cout << convertCharactersToIndex(1, 0, 1) << endl;
    cout << convertCharactersToIndex(1, 0, 0) << endl;
    cout << convertCharactersToIndex(0, 1, 1) << endl;
    cout << convertCharactersToIndex(0, 1, 0) << endl;
    cout << convertCharactersToIndex(0, 0, 1) << endl;
    cout << convertCharactersToIndex(0, 0, 0) << endl;
   


    Automaton test1(2);
    test1.testRulePrint();

    Automaton test8(30);
    test8.testRulePrint();
    
    Automaton test9(40);
    test9.testRulePrint();

    Automaton test10(50);
    test10.testRulePrint();

    cout << "*********************" << endl;
    cout << "  *****************  " << endl;
    cout << "    *************    " << endl;
    cout << "      *********      " << endl;
    cout << "        *****        " << endl;
    cout << "          *          " << endl;

    test1.setDisplayWidth(21);
    cout << test1.toStringCurrentGen() << endl;

    Automaton test2(2);
    test2.setDisplayWidth(21);
    test2.setThisGen("*  **   ***********   **  *");
    cout << test2.toStringCurrentGen() << endl;

    Automaton test3(2);
    cout << "*******" << endl;
    test3.setDisplayWidth(7);
    test3.setThisGen("*******");
    cout << test3.toStringCurrentGen() << endl;

    Automaton test4(30);
    test4.setDisplayWidth(79);
    cout << test4.toStringCurrentGen() << endl;
    for (int i = 0; i < 79; i++) {
        test4.propagateNewGeneration();
        cout << test4.toStringCurrentGen() << endl;
    }


    

}



void Automaton::testRulePrint(){
    for (int i = 0; i < 8; i++) {
        cout << rule[i];
    }
    cout << endl;
}




//display 


// int main()
// {
//    int rule, k;

//    // get rule from user 
//    do
//    {
//       cout << "Enter Rule (0 - 255): ";
//       cin >> rule;
//    } while (rule < 0 || rule > 255);

//    // create automaton with this rule and single central dot
//    Automaton 
//       aut(rule);

//    // now show it
//    cout << "   start"  << endl;
//    for (k = 0; k < 100; k++)
//    {

//       cout << aut.toStringCurrentGen() << endl;
//       aut.propagateNewGeneration();
//    }
//    cout << "   end"  << endl;
   
//    return 0;
// }