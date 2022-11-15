#include<bits/stdc++.h>
using namespace std;
#include "stack.h"
// postfix_evaluation
int postfix_evaluation(string exp){
    Stack<int>st; int tmp,a,b;
    for(int i=0;i<exp.size();i++){
        if (exp[i]==' ')continue;
        if(isdigit(exp[i]))
        {
            int x=exp[i]-'0';
            st.Push(x);
        }
        else {
            st.Pop(a);
            st.Pop(b);
            if(exp[i]=='+')tmp=b+a;
            else if(exp[i]=='-')tmp=b-a;
            else if(exp[i]=='*')tmp=b*a;
            else if(exp[i]=='/')tmp=b/a;
            else if(exp[i]=='^')tmp=pow(b,a);
            st.Push(tmp);
        }
    }
    return st.Top();
}
