/*Decode Ways Jun 25 '124495 / 17001
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Author: Wencan Luo
Language: C++
Date: 07/18/2013
*/

#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<algorithm>

#include<map>
//#include<unordered_set>

#include<queue>
#include<set>
#include<stack>

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

class Solution {
public:

	bool checkLetter(char a, char b){
		switch(a){
		case '0':
			return false;
		case '1':
			return true;
		case '2':
			if (b <= '6')return true;
			return false;
		default:
			return false;
		}

		return false;
	}

    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> A;
		int n = s.size();
		if(n==0) return 0;
		if(s[0] == '0') return 0;

		A.resize(n+1, 0);
		A[0] = 1;
		A[1] = 1;

		for(int i=1;i<n;i++){
			if(checkLetter(s[i-1], s[i])){
				if(s[i] != '0'){
					A[i+1] = A[i] + A[i-1];
				}else{
					A[i+1] = A[i-1];
				}
			}else{
				if(s[i] != '0'){
					A[i+1] = A[i];
				}
			}
		}

		return A[n];
    }
};

void main(){
	Solution s;
	
	cout << s.numDecodings("227") << endl;
	cout << s.numDecodings("10") << endl;
	cout << s.numDecodings("100") << endl;
	cout << s.numDecodings("102") << endl;
	cout << s.numDecodings("123") << endl;
	cout << s.numDecodings("00") << endl;
	cout << s.numDecodings("000") << endl;
	
	system("pause");
}
