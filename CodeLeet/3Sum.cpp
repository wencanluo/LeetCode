/*Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
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