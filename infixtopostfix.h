#ifndef INFIXTOPOSTFIX_H_EXIST
#define INFIXTOPOSTFIX_H_EXIST

#include <iostream>
#include <string>

using namespace std;

class Infixtopostfix
{
	private:
	string infix;
	string token;
	string operator1, operator2;
	public:
	stack<string> convertinfixtopostfix(string);//function convertinfixtopostfix returns string on stack
	bool precedence(string, string);//boolean type function
	bool isoperator(string);
};
#endif