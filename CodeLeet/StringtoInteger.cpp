/*String to Integer (atoi)Dec 27 '117157 / 32836
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
Author: Wencan Luo
Language: C++
Date: 08/18/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>

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
	bool isWhiteSpace(char c){
		if(c == ' ') return true;
		if(c == '\t') return true;
		return false;
	}

	bool isDigit(char c){
		if(c >= '0' && c<= '9') return true;
		return false;
	}

	bool checkRange(const char *str, const char* m){
		if(str == NULL) return false;

		int i = 0;
		while(isDigit(str[i])){
			i++;
		}

		int j=0;
		while(isDigit(m[j])){
			j++;
		}

		if(i<j) return false;
		if(i>j) return true;

		i = 0;
		while(isDigit(str[i])){
			if(str[i] > m[i]){ 
				return true;
			}else if(str[i] < m[i]){ 
				return false;
			}

			i++;
		}

		return false;
	}

    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int k=0;
		if(str[k] == '\0') return 0;

		while(isWhiteSpace(str[k]))k++;
		if(str[k] == '\0') return 0;

		bool negative = false;
		if(str[k] == '+'){
			k++;
		}else if(str[k] == '-'){
			k++;
			negative = true;
		}
		if(negative){
			if(checkRange(str+k, "2147483648")) return -2147483648;
		}else{
			if(checkRange(str+k, "2147483647")) return 2147483647;
		}
		
		int r = 0;
		while(str[k] && isDigit(str[k])){
			r = r*10 + str[k] - '0';
			k++;
		}


		if(negative) r = -r;
		return r;
    }
};

void main(){
	Solution s;

	cout << s.atoi("-123") << endl;

	system("pause");
}
