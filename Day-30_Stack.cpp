/*
150. Evaluate Reverse Polish Notation
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.

SUBMISSION IN C++

*/

class Solution {
public:
    unordered_set<string>st={"+", "-", "*", "/"};
    stack<int>v;
    void call(string ss)
    {
        int b=v.top();
        v.pop();
        int a=v.top();
        v.pop();

        switch(ss[0])
        {
            case '+':
            v.push(a+b);
            break;
            case '-':
            v.push(a-b);
            break;
            case '*':
            v.push(a*b);
            break;
            case '/':
            v.push(a/b);
            break;
        }
    }
    int evalRPN(vector<string>& tokens) {

        for (auto s : tokens) {
            if(st.count(s)>0)
            {
                call(s);
            }
            else
            {
                v.push(stoi(s));
            }
        }

        return v.top();
    }
};

