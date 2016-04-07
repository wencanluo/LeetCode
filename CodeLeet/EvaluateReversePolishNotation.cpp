/*Evaluate Reverse Polish Notation Total Accepted: 31509 Total Submissions: 157169 My Submissions Question Solution 
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

Author: Wencan Luo
Language: C++
Date: 12/06/2014
*/

#include<iostream>
using namespace std;

#include<stack>
#include <string>

class Solution {
public:
    bool isOperator(string s){
        if(s.compare("+") == 0) return true;
        if(s.compare("-") == 0) return true;
        if(s.compare("*") == 0) return true;
        if(s.compare("/") == 0) return true;
        return false;    
    }
    
    int eval(int a, int b, string op){
        if(op.compare("+") == 0) return a+b;
        if(op.compare("-") == 0) return a-b;
        if(op.compare("*") == 0) return a*b;
        if(op.compare("/") == 0) return a/b;
        return 0; 
    }
    
    int string2int(string s){
        return atoi(s.c_str());
    }
    
    int evalRPN(vector<string> &tokens) {
        stack<int> S;
        
        for(int i=0;i<tokens.size();i++){
            if(!isOperator(tokens[i])){
                //push
                S.push(string2int(tokens[i]));
            }else{
                //pop, pop, push
                int b = S.top(); S.pop();
                int a = S.top(); S.pop();
                int r = eval(a, b, tokens[i]);
                S.push(r);
            }
        }
        
        int r = S.top();
        S.pop();
        return r;
    }
};

int main(){
    Solution s;
    
    
}