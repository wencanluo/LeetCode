/*3SumJan 18 '123993 / 15001
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
	
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
	vector<vector<int> > threeSum(vector<int> &num) {//n^2
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > res;

		if(num.size() < 3) return res;

		//sort
		sort(num.begin(), num.end());

		//check one by one
		vector<int>::iterator it1,it2,it3;

		for(it1=num.begin();it1<num.end()-2;it1++)
		{
			it2 = it1+1;
			it3 = num.end() - 1;
			while(it2 < it3)
			{
				if(0 == *it1 + *it2 + *it3)//adjust the pos according to the sum
				{
					vector<int> tmp;
					tmp.push_back(*it1);
					tmp.push_back(*it2);
					tmp.push_back(-*it1 - *it2);
					res.push_back(tmp);
					it2++;
					it3--;
				}
				else if(0 < *it1 + *it2 + *it3)
				{
					it3--;
				}
				else // 0 > ..
				{
					it2++;
				}
			}
		}

		//remove duplicate ones
		sort(res.begin(), res.end());
		vector< vector<int> >::iterator it;
		it = unique(res.begin(), res.end());
		res.resize(it - res.begin());

		return res;
    }

    vector<vector<int> > threeSum2(vector<int> &num) {//n^2 log(n)
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > res;

		//sort
		sort(num.begin(), num.end());

		//check one by one
		vector<int>::iterator it1,it2,it3;

		for(it1=num.begin();it1<num.end();it1++)
		{
			for(it2=it1+1;it2<num.end();it2++)
			{
				//divide and conque to find the third one
				if( true == binary_search(it2+1, num.end(), -*it1 - *it2))
				{
					vector<int> tmp;
					tmp.push_back(*it1);
					tmp.push_back(*it2);
					tmp.push_back(-*it1 - *it2);
					res.push_back(tmp);
				}
			}
		}

		//remove duplicate ones
		sort(res.begin(), res.end());
		vector< vector<int> >::iterator it;
		it = unique(res.begin(), res.end());
		res.resize(it - res.begin());

		return res;
    }

	vector<vector<int> > threeSum1(vector<int> &num) {//n^3
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > res;

		//sort
		sort(num.begin(), num.end());

		//check one by one
		vector<int>::iterator it1,it2,it3;

		for(it1=num.begin();it1<num.end();it1++)
		{
			for(it2=it1+1;it2<num.end();it2++)
			{
				for(it3=it2+1;it3<num.end();it3++)
				{
					if(0 == *it1 + *it2 + *it3)
					{
						vector<int> tmp;
						tmp.push_back(*it1);
						tmp.push_back(*it2);
						tmp.push_back(*it3);
						res.push_back(tmp);
					}
				}
			}
		}

		//remove duplicate ones
		sort(res.begin(), res.end());
		vector< vector<int> >::iterator it;
		it = unique(res.begin(), res.end());
		res.resize(it - res.begin());

		return res;
    }
};

void main()
{
	int a[] = {1};
	vector<int> num(a, a + sizeof(a)/sizeof(int));

	Solution s;
	vector<vector<int> > sum = s.threeSum(num);

	vector<vector<int> >::iterator iter;

	for(iter=sum.begin();iter<sum.end();iter++)
	{
		vector<int>::iterator it;

		for(it = (*iter).begin(); it < (*iter).end(); it++)
		{
			cout << *it << ",";
		}
		cout << endl;
	}

	system("pause");
}