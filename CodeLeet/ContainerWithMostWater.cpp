/*Container With Most WaterJan 9 '125559 / 12736
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

Author: Wencan Luo
Language: C++
Date: 08/15/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

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
	int maxArea_slant(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
		if(n <= 1) return 0;

		int area = 0;

		int i=0;
		int j=n-1;
		area = (j-i)*(height[i] + height[j])/2;

		bool bigger; //true: left, false: right
		if(height[i] > height[j]){
			bigger = true;
			j--;
		}else{
			bigger = false;
			i++;
		}
		
		while(i < j){
			if(bigger){
				if(height[j] > height[i]){
					int t = (j-i)*(height[i] + height[j])/2;
					area = max(area, t);
					bigger = false;
					i++;
				}else{
					j--;
				}
			}else{
				if(height[i] > height[j]){
					int t = (j-i)*(height[i] + height[j])/2;
					area = max(area, t);
					bigger = true;
					j--;
				}else{
					i++;
				}
			}
		}

		return area;
    }

    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
		if(n <= 1) return 0;

		int area = 0;

		int i=0;
		int j=n-1;
		int h = 0;

		while(i < j){
			h = min(height[i], height[j]);
			area = max(area, (j-i)*h);

			if(height[i] > height[j]){
				j--;
			}else{
				i++;
			}
		}

		return area;
    }
};

void main()
{
	Solution s;

	system("pause");
}

