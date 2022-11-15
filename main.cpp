//Muhamed_sayEd74
#include<bits/stdc++.h>
using namespace std;
#include "stack.h"
#include "InfixToPostfix.h"
#include "PostfixEvaluation.h"
int main()
{
    string exp="5 3 + 8 2 - *";
    int result= postfix_evaluation(exp);
    cout<<result;
}