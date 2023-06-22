#include<bits/stdc++.h>

using namespace std;

bool notPair(char open, char close) {
    if ((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'))
        return false;
    else return true;
}

bool BalancedParenthesesUsingStack(string exp) { //   {(3+5)*9} true  ,  (3+5)*9} false
    stack<char> st;
    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')st.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (st.empty() || notPair(st.top(), exp[i]))
                return false;
            st.pop();
        }
    }
    return st.empty();

    // (or) return st.empty()?true:false;

    /* (or)
      if (st.empty())return true;
      else return false;
     */
}