/*3 Sum Closest Jan 18 '125687 / 14868
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
    
Author: Wencan Luo
Language: C++
Date: 08/29/2012	
*/
	
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=num.size();
        if(n<=2) return 0;
		
		int sum = 0;
		int closestSum = num[0] + num[1] + num[2];

		sort(num.begin(), num.end());

		for(int i=0;i<n;i++){
			int j = i + 1;
			int k = n-1;

			while(j < k){
				sum = num[i] + num[j] + num[k];
				if(abs(sum-target) < abs(closestSum - target)){
					closestSum = sum;
				}

				if(sum == target) return target;
				if(sum < target){
					j++;
				}else{
					k--;
				}
			}
		}
		return closestSum;
    }
};

void main()
{
	Solution s;

	int a[] = {1,2,3};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));

	cout << s.threeSumClosest(v, 0);

	system("pause");
}