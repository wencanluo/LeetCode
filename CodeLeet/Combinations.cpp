/*Combinations Apr 18 '123948 / 9781
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Author: Wencan Luo
Language: C++
Date: 07/25/2013
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

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		if(k==0) return res;
		if(k>n) return res;

		if(k==1){
			for(int i=1;i<=n;i++){
				vector<int> tmp;
				tmp.push_back(i);
				res.push_back(tmp);
			}
			return res;
		}
		
		res = combine(n-1,k);
		vector< vector<int> > n1k1 = combine(n-1,k-1);

		for(int i=0;i<n1k1.size();i++){
			vector<int> tmp = n1k1[i];
			tmp.push_back(n);
			res.push_back(tmp);
		}

		return res;
    }
};

void main(){
	Solution s;
	
	vector<vector<int> > res = s.combine(4,2);

	for(int i=0;i<res.size();i++){
		vector<int> tmp = res[i];
		for(int j=0;j<tmp.size();j++){
			cout << tmp[j] << ",";
		}
		cout << endl;
	}

	system("pause");
}
