/*Rotate ImageMar 18 '123674 / 8447
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

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
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        if(n == 0) return;
        
        for(int k=0;k<n/2;k++){
            for(int i=k;i<n-k-1;i++){
                int t = matrix[k][i];
                matrix[k][i] = matrix[n-i-1][k];
                matrix[n-i-1][k] = matrix[n-k-1][n-i-1];
                matrix[n-k-1][n-i-1] = matrix[i][n-k-1];
                matrix[i][n-k-1] = t;
            }
        }
    }
};

void main(){
	Solution s;
	
	

	system("pause");
}
