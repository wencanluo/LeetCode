/*Gray CodeMay 20 '122430 / 5572
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
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
    vector<int> grayCode(int n) {//Recursive
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n==0){
			vector<int> res;
			res.push_back(0);
			return res;
		}

		if(n==1){
			vector<int> res;
			res.push_back(0);
			res.push_back(1);
			return res;
		}

		vector<int> low = grayCode(n-1);

		vector<int> res(low.begin(), low.end());

		int high = 1 << (n-1);
		for(int i=low.size()-1; i>=0; i--){
			res.push_back(low[i] + high);
		}

		return res;
    }
};

void main(){
	Solution s;
	
	vector<int> res = s.grayCode(2);
	
	system("pause");
}
