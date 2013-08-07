/*Multiply StringsMar 12 '123693 / 14018
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.

Author: Wencan Luo
Language: C++
Date: 08/04/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

#include<map>
//#include<unordered_set>

#include<queue>
#include<set>

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    char add(char c1, char c2, int &overflow){
        int r = c1-'0' + c2-'0' + overflow;
        if(r >= 10){
            overflow = 1;
            r -= 10;
        }else{
            overflow = 0;
        }
        
        return r+'0';
    }
    
    string add(string num1, string num2){
        string R = "";
        if(num1 == "0") return num2;
        if(num2 == "0") return num1;
        
        int i = num1.size() -1;
        int j = num2.size() -1;
        int overflow = 0;
        
        while(i >=0 && j>=0){
            char c = add(num1[i], num2[j], overflow);
            R = c + R;
            i--;
            j--;
        }
        
        while(i >= 0){
            char c = add(num1[i], '0', overflow);
            R = c + R;
            i--;
        }
        
        while(j >= 0){
            char c = add('0', num2[j], overflow);
            R = c + R;
            j--;
        }
        
        if(overflow == 1){
            R = '1' + R;
        }
        
        return R;
    }
    
    string multiply(char c1, char c2){
        int number = (c1-'0')*(c2-'0');
        stringstream ss;//create a stringstream
        ss << number;//add number to the stream
        return ss.str();//return a string with the contents of the stream
    }
    
    string multiply(string num1, char c){
        if(c=='0') return "0";
        string R = "0";
        string z = "";
        for(int i=num1.size()-1;i>=0;i--){
            string s = multiply(num1[i], c);
            s += z;
            R = add(R,s);
            z += "0";
        }
        return R;
    }
    
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = num1.size();
        int n = num2.size();
        
        if(m==0 || n==0) return "0";
        string R = "0";
        
        string z = "";
        
        for(int i=n-1;i>=0;i--){//for each digit in num2
            //multiply it to num1
            string s = multiply(num1, num2[i]);
            s += z;
            R = add(R, s);
            z += "0";
        }
        
        return R;
    }
};

void main(){
    Solution s;

	//cout << s.multiply("123",'9') << endl;

	//cout << s.add("123","0") << endl;
	cout << s.multiply("123","123") << endl;
	//int overflow = 0;
	//cout << s.add('9','1', overflow) << endl;
	//cout << s.add("9","1") << endl;
    
	system("pause");
}
