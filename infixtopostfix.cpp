#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;
#include "infixtopostfix.h"



stack<string> Infixtopostfix::convertinfixtopostfix(string infix)
{
	stack<string> operators;
	stack<string> output;//postfix
	
	istringstream input(infix);//the istringstream type called input which takes the infix
	
	
	string token;
	
	while(!input.eof())
	{
		input>>token;
		
		//if(oper.find(token)!=string::npos)//check if the token is operator
		if(isoperator(token))
		{
			
			bool keepgoing = true;
			while(keepgoing)
			{
				//<<operators.top();
				if(!operators.empty())//checks if the operators stack is not empty, then check the precedence of the token and the operator on stack
				{
					
					
					if(precedence(token, operators.top()))//check if the token has less precedence from the token that is on the top of the stack
					{
						
						string temp = operators.top();//incicates the top of the stack has a token
						operators.pop();//pops the operator that is on the top of the stack
						output.push(temp);//pushes the operator onto the output that was on the top of the opoerators
						
						
					}
					
					else//if the token has higher precedence than the operator on the top of the operators
					{
						operators.push(token);//push the token onto the operators stack
						keepgoing =false;
					}
					
				}
				else//if the operators stack is empty, then
				{
					operators.push(token);//push the token onto the operators stack
					keepgoing = false;
				}
				
			}
			//operator.push(infix[i]);//after it checks the precedence of the operator
			
		}
		
		else if(token=="(")//checks if the token is open parenthesis
		{
			operators.push(token);//pushes onto theoperators stack
		}
		else if(token==")")//checks if the token is close parenthesis, then discard it if it is
		{
			//it is going to pop all the operators,
			//and push all the operators from the operators stack onto the output  until it gets to the open parenthesis
			bool keepgoing = true;
			while(keepgoing)
			{
				if((operators.top()).compare("(")==0)//checks if the top on the operators stack is open parenthesis, then
				{
					
					operators.pop();//pop the open parenthesis and discard it
					keepgoing = false;
				}
				else//if the top is not open parenthesis, then
				{
					//pop all the operators and push them onto the output stack
					string temp = operators.top();
					operators.pop();
					output.push(temp);
					
				}
				
			}
		}
		else //if it is not a parenthesis or an operator then it is a number
		{
			output.push(token);//push the token onto the output
			
		}
		
	}//end while loop
	
	//after all the tokens from the infix is read, pop all the operators from the operators stack and then push onto the output stack
	while(!operators.empty())
	{
		string temp = operators.top();//take the token on the top(indicates the top of the stack)
		operators.pop();
		output.push(temp);
	}
	
	
	//reverse the output to get the postfix
	stack<string> newoutput;
	while(!output.empty())
	{
		newoutput.push(output.top());
		output.pop();
	}
	
	
	
	
	//create a stack to copy the newoutput
	stack<string> copyoutput = newoutput;
	//prints out the postfix
	cout << "the postfix is: ";
	while (!copyoutput.empty())
	{
		cout<<copyoutput.top()<<"  " ;
		copyoutput.pop();
	}
	
	cout<<endl;
	
	return newoutput;
	
	
	
}//end function
bool Infixtopostfix::isoperator(string token)
{
	//string oper[] = "+-*/";//initializes the operators
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

bool Infixtopostfix::precedence(string operator1, string operator2)
{
	int precedence1;
	int precedence2;
	
	if(operator1=="+" || operator1=="-")//checks if  operator1 is "+" or "-"
	{
		precedence1 = 1;//operator1 gets lower precedence
	}
	else if(operator1=="*" || operator1=="/")//checks if  operator1 is "*" or "/"
	{
		precedence1 = 2;//operator1 gets higher precedence than "+" and "-"
	}
	
	
	if(operator2=="+" || operator2=="-")//checks if operator2 is "+" or "-"
	{
		precedence2 = 1;//operator2 gets lower precedence
	}
	else if(operator2=="*" ||operator2=="/")//checks if operator2 is "*" or "/"
	{
		precedence2 = 2;//operator2 gets higher precedence
	}
	else if(operator2 =="(")//checks if operator2 is open parenthesis
	{
		precedence2=0;//operator2 gets the lowest precedence
	}
	
	
	if(precedence1<precedence2)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}