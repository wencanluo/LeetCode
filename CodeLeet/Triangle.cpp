/*Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Author: Wencan Luo
Language: C++
Date: 07/03/2013
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


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(triangle.size() < 1) return 0;

        vector<int> A;
		vector<int> B;

		A.resize(triangle.size(), 0);
		B.resize(triangle.size(), 0);
		A[0] = triangle[0][0];

		for(int i=1; i<triangle.size(); i++){
			vector<int> T = triangle[i];
			for(int j=0; j < T.size(); j++){
				if(j == 0){
					B[j] = A[j] + T[j];
				}else if (j==T.size() - 1){
					B[j] = A[j-1] + T[j];
				}else{
					B[j] = min(A[j], A[j-1]) + T[j];
				}
			}
			//copy B to A
			A = B;
		}

		int minSum = A[0];
		for(int i=0; i<A.size(); i++){
			if(A[i] <= minSum){
				minSum = A[i];
			}
		}

		return minSum;
    }
};

void main(){
	Solution s;

	int row1[] = {-1};
	int row2[] = {2,3};
	int row3[] = {1,-1,-3};

	vector<int> A1 (row1, row1 + sizeof(row1) / sizeof(int) );
	vector<int> A2 (row2, row2 + sizeof(row2) / sizeof(int) );
	vector<int> A3 (row3, row3 + sizeof(row3) / sizeof(int) );

	vector< vector<int> > B;
	B.push_back(A1);
	B.push_back(A2);
	B.push_back(A3);
	
	cout << s.minimumTotal(B);
	system("pause");
}
