/*Permutation SequenceMar 28 '123090 / 10604
The set [1,2,3,�,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

Author: Wencan Luo
Language: C++
Date: 07/31/2013
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

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		string R;
        string A;
		for(int i=1;i<=n;i++){
			A.push_back('0' + i);
		}

		long L = 1;
		for(int i=1;i<n;i++){
			L *= i;
		}

		int m = n-1;
		while(m >= 1){
			int j = k/L + ((k%L==0)?0:1) - 1;
			R.push_back(A[j]);
			A.erase(A.begin() + j);
			k = (k%L == 0) ? L : (k%L);
			L /= m;
			m--;
		}

		//last one
		R.push_back(A[0]);
		return R;
    }
};

void main(){
	Solution s;

	cout << s.getPermutation(3,1) << endl;
	cout << s.getPermutation(3,2) << endl;
	cout << s.getPermutation(3,3) << endl;
	cout << s.getPermutation(3,4) << endl;
	cout << s.getPermutation(3,5) << endl;
	cout << s.getPermutation(3,6) << endl;
	system("pause");
}
