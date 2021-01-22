#include <iostream>
#include <stack>
#include <string>
#include <math.h>

#include "calculate.h"

using namespace std;

int Calculator::calculate(stack<string> &postfix)
{
	stack<int> mystack;
	
	while(!postfix.empty())
	{
		string token = postfix.top();
		postfix.pop();//pops the token from the top of
		
		//checks if the token is an operator
		
		if(isoperator(token))
		{
			int result;
			
			result = evaluate(token, mystack);
			//then push back the result onto mystack
			mystack.push(result);
		}
		
		
		
		//if the token is number, then push onto the mystack
		//mystack will have only numbers
		else
		{
			mystack.push(atoi(token.c_str()));
		}
	}
	
	
	
	return mystack.top();
	
	
}




//pops the left and rightvalues from mystack
//then evaluate the operator
int Calculator::evaluate( string token,  stack<int> &mystack)
{
	int leftvalue, rightvalue, result;
	
	rightvalue = mystack.top();
	mystack.pop();
	
	leftvalue = mystack.top();
	mystack.pop();
	
	
	
	if( token == "+")
	{
		return(leftvalue + rightvalue);
	}
	else if(token == "-")
	{
		return(leftvalue - rightvalue);
		
	}
	else if(token == "*")
	{
		return( leftvalue * rightvalue);
		
	}
	else if(token == "/")
	{
		if(rightvalue ==  0)
		{
			throw "division by zero condition!";
		}
		else
		{
		return(leftvalue / rightvalue);
		}
		
	}
	else
	{
		throw "invalid expression";
	}
	
}


//checks if the operator is one of "+-*/"
//if the operator is one of the list, then returns true, if not returns false
bool Calculator::isoperator(string token)
{
	//string oper = "+-*/";//initializes the operators
	string oper[] = {"+","-","*","/"};

	for(int i=0; i<4; i++)
	{
		
		if(token==oper[i])
		{
			return true;
		}
	}
	
	return false;
}