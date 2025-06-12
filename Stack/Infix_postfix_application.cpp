//
// Created by Fatma on 3/29/2025.
//
#include "Stack-Linked-List-Based/Stack_list.h"
#include <iostream>
#include <cmath>

using namespace std;

///Converting infix to postfix////
int precedence(char oper){
    if(oper=='+'||oper=='-')
        return 1;
    else if(oper=='*'||oper=='/')
        return 2;
    else if(oper=='^')
        return 3;
    return 0;
}

string Infix_Postfix (string infix){
    string postfix;
    Stack_list<char>operators;


    for (int i = 0; i < infix.size(); ++i) {
        if(isdigit(infix[i])|| isalpha(infix[i])) //rule 1
            postfix.push_back(infix[i]);
        else{
            if(infix[i]==')'){
                while (operators.peek()!='(')
                    postfix.push_back(operators.pop());
                operators.pop();
            }else if(infix[i]=='('){
                operators.push(infix[i]);
            }else{
                while ( !operators.isEmpty() &&
                precedence(operators.peek()) >=precedence(infix[i]) ) {

                    if(precedence(operators.peek())== precedence(infix[i])&&infix[i]=='^')
                        break;
                    postfix.push_back(operators.pop());

                }
                operators.push(infix[i]);
            }


        }
    }
    while (!operators.isEmpty())
        postfix+=operators.pop();

    return postfix;
}



////// Evaluating the postfix ////////
double Solving(int a ,int b , char operation){

    if(operation=='*')
        return (a*b);
    else if(operation=='+')
        return(a+b);
    else if(operation=='-')
        return(a-b);
    else if (operation=='^')
        return(pow(a,b));
    else
        return(a/b);
}

void evaluation(string postfix) {

    Stack_list<double>operands;

    for (int i = 0; i < postfix.size(); ++i) {
        if(isdigit(postfix[i]))
            operands.push(postfix[i]-'0');
        else{
            double element_1=operands.pop();
            double element_2=operands.pop();
            operands.push(Solving(element_2,element_1,postfix[i]));
        }
    }
    cout<<operands.pop();

}
