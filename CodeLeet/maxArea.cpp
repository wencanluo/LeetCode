/*
Container With Most Water
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

See http://slientcode.blogspot.com/2012/04/container-with-most-water.html
Area(i,j) = Min(Ai, Aj) * (j-i);
The min of (Ai, Aj) decides the area of the container. For k, i<k<j, Area (i, k) < Area(i, j) if Ai < Aj: i.e. all Area(i,k) can be ruled out.

Author: Wencan Luo
Language: C++
Date: 09/03/2012
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int> &height)//O(n)
	{
		int res = 0;
		int i=0;
		int j = height.size()-1;

		while(i != j)
		{
			res = max(res, min(height[i], height[j])*(j-i));
			if(height[i] <= height[j])
			{
				i++;
			}
			else
			{
				j--;
			}
		}

		return res;
	}

    int maxArea_n2(vector<int> &height) {//n^2, max( min(x,y)*(i_y - i_x)
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int res = 0;
        for(int i=0;i<height.size();i++)
		{
			for(int j=i+1;j<height.size();j++)
			{
				res = max(res, min(height[i],height[j])*(j-i));
			}
		}
		return res;
    }
};

void main()
{
	int a[] = {3,2,1,3};
	vector<int> num(a, a + sizeof(a)/sizeof(int));

	Solution s;
	int area = s.maxArea(num);

	cout << area << endl;

	system("pause");
}