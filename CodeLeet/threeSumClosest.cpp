/*3Sum Closest
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

	int threeSumClosest(vector<int> &num, int target) {//n^2
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int res = 0;

		if(num.size() < 3) return 0;

		sort(num.begin(),num.end());

		vector<int>::iterator it1,it2,it3;
		res = num[0] + num[1] + num[2];
		for(it1=num.begin();it1<num.end()-2;it1++)
		{
			it2 = it1 + 1;
			it3 = num.end() - 1;

			while(it2 < it3)
			{
				int sum = *it1 + *it2 + *it3;
				if( sum  == target)//closer
				{
					return target;
				}
				else if(sum < target)
				{
					if(abs(res-target) >= abs(sum - target))
					{
						res = sum;
					}
					
					it2++;
				}
				else
				{
					if(abs(res-target) >= abs(sum - target))
					{
						res = sum;
					}

					it3--;
				}
			}
		}

        return res;
    }   

	int threeSumClosest1(vector<int> &num, int target) {//n^3
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int res = 0;

		if(num.size() < 3) return 0;

		vector<int>::iterator it1,it2,it3;
		res = num[0] + num[1] + num[2];
		for(it1=num.begin();it1<num.end();it1++)
		{
			for(it2=it1+1;it2<num.end();it2++)
			{
				for(it3=it2+1;it3<num.end();it3++)
				{
					int sum = *it1 + *it2 + *it3;
					if( abs(sum - target ) <= abs(res - target))
					{
						res = sum;
					}
				}
			}

		}


        return res;
    }   
};

void main()
{
	int a[] = {-3,-2,-5,3,-4};
	int target = -1;

	vector<int> num(a, a + sizeof(a)/sizeof(int));

	Solution s;
	int sum = s.threeSumClosest(num, target);

	cout << sum << endl;

	system("pause");
}