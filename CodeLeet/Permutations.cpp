/*PermutationsMar 17 '125088 / 11812
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Author: Wencan Luo
Language: C++
Date: 08/03/2013
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
    void swap(vector<int> &A, int i, int j){
        int t=A[i];
        A[i] = A[j];
        A[j] = t;
    }
    
    void permuteRec(vector<int> &num, int k, vector<vector<int> > &R){
        int n = num.size();
        
        if(k==n-1){
            R.push_back(num);
            return;
        }
        
        for(int i=k;i<n;i++){
            swap(num, k, i);
            permuteRec(num, k+1, R);
            swap(num, k, i);//swap back
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > R;
        if(num.size() == 0) return R;
        
        permuteRec(num, 0, R);
        return R;
    }
};

void main(){
	Solution s;
	
	

	system("pause");
}
