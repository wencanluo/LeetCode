/*Largest Rectangle in HistogramApr 23 '124213 / 13587
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.



Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].



The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

Maximal Rectangle Apr 24 '122415 / 8797
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.


Author: Wencan Luo
Language: C++
Date: 07/17/2013
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
	int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int n = matrix.size();
		if(n<=0) return 0;
		int m = matrix[0].size();
		if(m<=0) return 0;

        vector<vector<int> > A;
		A.resize(n);

		for(int i=0;i<n;i++){
			A[i].resize(m,0);
		}

		//initialize the histogram
		for(int j=0;j<m;j++){
			int count = 0;
			for(int i=0;i<n;i++){
				if( '1' == matrix[i][j] ){
					count++;
				}else{
					count = 0;
				}

				A[i][j] = count;
			}
		}
		
		int maxArea = -1;
		for(int i=0;i<n;i++){
			int area = largestRectangleArea(A[i]);
			if(maxArea < area){
				maxArea = area;
			}
		}

		return maxArea;
    }

    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
		if(n==0) return 0;

		int maxArea = -1;
		
		stack<int> S;

		S.push(0);

		for(int i=1;i<height.size();i++){
			if(height[i] >= height[i-1]){//in
				S.push(i);
			}else{//out
				int k = -1;
				while(!S.empty() && height[S.top()] > height[i]){
					k = S.top();
					S.pop();

					int area = (i-k)*height[k];
					if(maxArea < area){
						maxArea = area;
					}
				}
				if( k == -1) k = i;
				height[k] = height[i];
				S.push(k);
			}
		}

		while(!S.empty()){
			int k = S.top();
			S.pop();

			int area = (n-k)*height[k];
			if(maxArea < area){
				maxArea = area;
			}
		}

		return maxArea;
    }
};

int main(){
	Solution s;
	
	//int a[] = {2,1,5,6,2,3};
	int a[] = {2,1,2};

	vector<int> v(a, a + sizeof(a)/sizeof(a[0]));

	cout << s.largestRectangleArea(v);

	system("pause");
    return 0;
}
