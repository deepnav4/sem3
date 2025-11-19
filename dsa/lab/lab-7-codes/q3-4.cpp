#include<bits/stdc++.h>
using namespace std;

// Q3:  Implement 
//         a) Infix to Prefix conversion 
//         b) Prefix to Postfix conversion
//         c) Infix to Postfix conversion
//         d) Postfix to Prefix conversion
// Q4: Implement evaluation of Postfix expression.

int precedence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

void infixToPostfix(string infix, string &postfix){
    stack<char> st;
    for(char ch : infix){
        if(isalnum(ch)){
            postfix += ch;
        }
        else if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            st.pop(); // pop the '('
        }
        else{
            while(!st.empty() && precedence(st.top()) >= precedence(ch)){
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
}

void infixToPrefix(string infix, string &prefix){
    reverse(infix.begin(), infix.end());
    for(int i = 0; i < infix.size(); i++){
        if(infix[i] == '(') infix[i] = ')';
        else if(infix[i] == ')') infix[i] = '(';
    }
    string postfix;
    infixToPostfix(infix, postfix);
    reverse(postfix.begin(), postfix.end());
    prefix = postfix;
}

void postfixToInfix(string postfix, string &infix){
    stack<string> st;
    for(char ch : postfix){
        if(isalnum(ch)){
            st.push(string(1, ch));
        }
        else{
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string expr = "(" + op1 + ch + op2 + ")";
            st.push(expr);
        }
    }
    infix = st.top();
}