/*Spiral MatrixMar 25 '123265 / 12039
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5]

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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=matrix.size();
		vector<int> res;
		if(m==0) return res;

		int n = matrix[0].size();
		if(n==0) return res;

		int maxk = 0;
		if(n<m){
			maxk = n/2 + ((n%2 == 0)?0:1);
		}else{
			maxk = m/2 + ((m%2 == 0)?0:1);
		}

		for(int k=0;k<maxk;k++){
			for(int j=k;j<=n-k-1;j++){
				res.push_back(matrix[k][j]);
			}

			for(int i=k+1;i<m-k-1;i++){
				res.push_back(matrix[i][n-k-1]);
			}

			for(int j=n-k-1;j>=k;j--){
				if(m-k-1 == k) continue;
				res.push_back(matrix[m-k-1][j]);
			}

			for(int i=m-k-2;i>k;i--){
				if(n-k-1 == k) continue;
				res.push_back(matrix[i][k]);
			}
		}

		return res;
    }

	vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int> > A;
		if(n<=0) return A;

		A.resize(n);
		for(int i=0;i<n;i++){
			A[i].resize(n);
		}

        int m=n;
		int maxk = n/2 + ((n%2 == 0)?0:1);
		
		int p = 1;
		for(int k=0;k<maxk;k++){
			for(int j=k;j<=n-k-1;j++){
				A[k][j] = p;
				p++;
			}

			for(int i=k+1;i<m-k-1;i++){
				A[i][n-k-1] = p;
				p++;
			}

			for(int j=n-k-1;j>=k;j--){
				if(m-k-1 == k) continue;
				A[m-k-1][j] = p;
				p++;
			}

			for(int i=m-k-2;i>k;i--){
				if(n-k-1 == k) continue;
				A[i][k] = p;
				p++;
			}
		}

		return A;
    }
};

void main(){
	Solution s;

	int a[] = {1};
	int b[] = {5,6,7,8};

	vector<int> va(a, a+sizeof(a)/sizeof(a[0]));
	vector<int> vb(b, b+sizeof(b)/sizeof(b[0]));

	vector< vector<int> > V;
	V.push_back(va);
	//V.push_back(vb);

	vector<int> v = s.spiralOrder(V);
	for(int i=0;i<v.size();i++){
		cout << v[i] << ",";
	}
	cout << endl;
	system("pause");
}
