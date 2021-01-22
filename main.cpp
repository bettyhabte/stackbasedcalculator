#include <iostream>
#include <string>
#include <stack>
//includes the header files
#include "infixtopostfix.h"
#include "calculate.h"


int main()
{
	
	
	string infix;//the input infix
	cout<< "please enter the expression" <<endl;
	getline(cin, infix);//the getline gets the entire expression until you hit enter
	
	Infixtopostfix myinfixtopostfix = Infixtopostfix();//variable myinfixtopostfix type Infixtopostfix
	stack<string> postfix = myinfixtopostfix.convertinfixtopostfix(infix);//postfix stack type that was got from converting the infix
	
	Calculator  mycalculator = Calculator();//variable mycalculator type calculator
	
	cout <<"the result is:  "<< mycalculator.calculate(postfix) << endl;
}