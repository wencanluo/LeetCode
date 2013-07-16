/*Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Pascal's Triangle II Oct 29 '122949 / 7029
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

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
	vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> A, B;
		if(rowIndex < 0) return A;

		//first row
		A.push_back(1);

		for(int i=1;i<=rowIndex;i++)
		{
			B.resize(i+1);

			for(int j=0; j < B.size(); j++){
				if(j == 0){
					B[j] = A[j];
				}else if (j==B.size() - 1){
					B[j] = A[j-1];
				}else{
					B[j] = A[j-1] + A[j];
				}
			}
			A = B;
		}
		return A;
    }

    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > A;
		if(numRows <= 0) return A;

		//first row
		vector<int> T;
		T.push_back(1);
		A.push_back(T);

		for(int i=1;i<numRows;i++)
		{
			vector<int> B = A[i-1];
			vector<int> T;
			T.resize(i+1);

			for(int j=0; j < T.size(); j++){
				if(j == 0){
					T[j] = B[j];
				}else if (j==T.size() - 1){
					T[j] = B[j-1];
				}else{
					T[j] = B[j-1] + B[j];
				}
			}

			A.push_back(T);
		}
		return A;
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
	
	s.generate(5);
	//cout << s.minimumTotal(B);
	system("pause");
}
