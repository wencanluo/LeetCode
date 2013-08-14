/*Letter Combinations of a Phone NumberJan 27 '124852 / 14644
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Author: Wencan Luo
Language: C++
Date: 08/13/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<stack>
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

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		static string A[] = {
			" ",
			"",
			"abc",
			"def",
			"ghi",
			"jkl",
			"mno",
			"pqrs",
			"tuv",
			"wxyz",
		};

		vector<string> r;
		int n = digits.size();
		if(n==0){
			r.push_back("");
			return r;
		}
		if(n==1){
			char c = digits[0];
			if(c >= '0' && c <= '9'){
				string dict = A[c-'0'];
				for(int i=0;i<dict.size();i++){
					string t = "";
					r.push_back(t + dict[i]);
				}
				return r;
			}
		}

		char c = digits[n-1];
		if(c >= '0' && c <= '9'){
			vector<string> left = letterCombinations(digits.substr(0, n-1));
			string t = A[c-'0'];

			for(int k=0;k<left.size();k++){
				for(int i=0;i<t.size();i++){
					r.push_back(left[k] + t[i]);
				}
			}
		}
		return r;
    }
};

void main(){
    Solution s;

	vector<string> r = s.letterCombinations("23");
	for(int i=0;i<r.size();i++){
		cout << r[i] << endl;
	}

	system("pause");
}



