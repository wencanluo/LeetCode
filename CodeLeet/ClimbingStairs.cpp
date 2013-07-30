/*Climbing StairsApr 3 '125183 / 9882
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Author: Wencan Luo
Language: C++
Date: 07/29/2013
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
 
class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return 0;
		if(n==1) return 1;
		if(n==2) return 2;

		int Fn,Fn1=1,Fn2=2;

		for(int i=3;i<=n;i++){
			Fn=Fn1+Fn2;
			Fn1=Fn2;
			Fn2=Fn;
		}
		return Fn;
    }
};

void main(){
	Solution s;
	
	//cout << s.simplifyPath("/a/./b/../../c/") << endl;
	cout << s.climbStairs(4) << endl;

	system("pause");
}
