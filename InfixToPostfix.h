//Muhamed_sayEd74
#include<bits/stdc++.h>
using namespace std;

// InfixToPostfix
int Priority(char c){
    if (c == '-' || c == '+')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return 0;
}
string postfix;
void infix_to_postfix(string exp){
    stack<char> stk;
    postfix = "";
    //---------------------------
    for (int i = 0; i < exp.length(); i++){
        if (exp[i] == ' ') continue;

        if (isdigit(exp[i]) || isalpha(exp[i]))
            postfix += exp[i];
        else if (exp[i] == '(')
            stk.push('(');
        else if (exp[i] == ')'){
            while (stk.top() != '('){
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else{
            while (!stk.empty() && Priority(exp[i]) <= Priority(stk.top())){
                postfix += stk.top();
                stk.pop();
            }
            stk.push(exp[i]);
        }
    }

    while (!stk.empty()){
        postfix += stk.top();
        stk.pop();
    }
}