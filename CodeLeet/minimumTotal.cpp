/*
TriangleOct 30 '12
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

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
Date: 1/14/2013
Solution: 

*/

#include <iostream>
using namespace std;

#include <vector>

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(triangle.size() == 0) return 0;

		vector< vector<int> > t;
		t.resize( triangle.size() );
		
		for(int i=0;i<triangle.size();i++)
		{
			vector<int> row = triangle[i];
			t[i].resize(i+1);

			if(i==0)//first row
			{
				t[i][0] = row[0];
				continue;//skip the first one
			}

			for(int j=0;j<row.size();j++)
			{
				//get the min( (i-1,j-1), (i-1, j) )
				if(j-1 < 0)
				{
					t[i][j] = t[i-1][j] + triangle[i][j];
				}
				else if (j > i-1)
				{
					t[i][j] = t[i-1][j-1] + triangle[i][j];
				}
				else
				{
					t[i][j] = min(t[i-1][j-1], t[i-1][j]) + triangle[i][j];
				}
			}
		}
		
		int n = triangle.size();
		int min_sum = t[n-1][0];
		for(int i=1;i<t[n-1].size();i++)
		{
			if(t[n-1][i] < min_sum) min_sum = t[n-1][i]; 
		}
		return min_sum;
    }
};

void main()
{
	Solution s;
	vector< vector<int> > a;

	vector<int> a1;
	a1.push_back(2);
	a.push_back(a1);

	vector<int> a2;
	a2.push_back(3);
	a2.push_back(4);
	a.push_back(a2);

	cout << s.minimumTotal(a) << endl;
	
	system("pause");
}