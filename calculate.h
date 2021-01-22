#ifndef CALCULATE_H_EXIST
#define CALCULATE_H_EXIST


#include <iostream>
#include <string>
#include <stack>

using namespace std;



class Calculator
{
	public:
	int calculate(stack<string> &postfix);//calculate accepts the  postfix type stack
	int evaluate(string token, stack<int> &mystack);
	bool isoperator(string token);
};
#endif