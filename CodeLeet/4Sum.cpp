/*
4Sum
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a = b = c = d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
	
Author: Wencan Luo
Language: C++
Date: 08/29/2012

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

class Solution {
public:

	class SumPair
	{
	public:
		int sum;
		int first;
		int second;
		SumPair(int sum, int a, int b): sum(sum), first(a), second(b)
		{
		}

	};

	bool SumPairCheck(SumPair a, SumPair b)
	{
		if(a.first == b.first || a.second == b.second || a.first == b.second || a.second == b.first) return true;
		return false;
	}

	struct SumPairCompare{
		bool operator()(SumPair a, SumPair b)
		{
			if( a.sum < b.sum ) {
				return true;
			}else if(a.sum == b.sum){
				if( a.first < b.first ){
					return true;
				}else if(a.first == b.first ){
					return (a.second < b.second);
				}
			}

			return false;
		}
	}sumPairCompare;

	vector<vector<int> > fourSum(vector<int> &num, int target) {//n^2 log n, worst case n^3
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > res;

		if(num.size() < 4) return res;

		//compute sum1, sum2
		sort(num.begin(), num.end());
		vector<SumPair> sum1;

		int it1, it2;
		for(it1 = 0; it1 < num.size()-1; it1++)
		{
			for(it2 = it1+1; it2 < num.size(); it2++)
			{
				sum1.push_back(SumPair(num[it1]+num[it2],it1,it2)); 
			}
		}

		
		sort(sum1.begin(), sum1.end(), sumPairCompare);

		//remove duplicate sum

		//sort sum
		//for(it1=0;it1<sum1.size();it1++) cout << sum1[it1].sum << ", ";

		//sort the problem sum1 + sum2 == target
		int its1, its2;

		its1 = 0;
		its2 = sum1.size() - 1;

		while(its1 < its2)
		{			
			if(sum1[its1].sum + sum1[its2].sum == target)
			{
				int its3 = its2;
				while(!SumPairCheck(sum1[its1], sum1[its3]) && sum1[its1].sum + sum1[its3].sum == target)//add it to res
				{
					vector<int> tmp;
					tmp.push_back(num[sum1[its1].first]);
					tmp.push_back(num[sum1[its1].second]);
					tmp.push_back(num[sum1[its3].first]);
					tmp.push_back(num[sum1[its3].second]);
					sort(tmp.begin(),tmp.end());
					if(find(res.begin(),res.end(), tmp) == res.end()) 
						res.push_back(tmp);
					its3--;
				}
				
				its1++;
			}
			else if(sum1[its1].sum + sum1[its2].sum < target)
			{
				//move right
				its1++;
			}
			else
			{
				//move left
				its2--;
			}
		}
		
		return res;
    }

	vector<vector<int> > fourSum_n3(vector<int> &num, int target) {//n^3
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > res;

		if(num.size() < 4) return res;

		//sort
		sort(num.begin(), num.end());

		//check one by one
		vector<int>::iterator it1, it2, it3, it4;

		for(it1=num.begin();it1<num.end()-3;it1++)
		{
			for(it2=it1+1;it2<num.end()-2;it2++)
			{
				it3 = it2+1;
				it4 = num.end() - 1;
				while(it3 < it4)
				{
					if(target == *it1 + *it2 + *it3 + *it4)
					{
						vector<int> tmp;
						tmp.push_back(*it1);
						tmp.push_back(*it2);
						tmp.push_back(*it3);
						tmp.push_back(*it4);
						res.push_back(tmp);
						it3++;
						it4--;
					}
					else if(target < *it1 + *it2 + *it3 + *it4)
					{
						it4--;
					}
					else // 0 > ..
					{
						it3++;
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
	freopen("log.txt","w",stdout);

	//int a[] = {-5,-4,-3,-2,-1,0,0,1,2,3,4,5};
	vector<int> num;
	int target = 0;
	
	for(int n = 4; n < 100; n++)
	{
		num.clear();
		for(int i=0; i < n; i++)
		{
			num.push_back(i);
			num.push_back(-i);
		}

		clock_t t_begin, t_end;
		Solution s;

		t_begin = clock();
		vector<vector<int> > sum = s.fourSum(num, target);
		t_end = clock();

		/*vector<vector<int> >::iterator iter;
		for(iter=sum.begin();iter<sum.end();iter++)
		{
			vector<int>::iterator it;

			for(it = (*iter).begin(); it < (*iter).end(); it++)
			{
				cout << *it << ",";
			}
			cout << endl;
		}*/

		cout << n << "\t" << sum.size() << "\t" << ((float)t_end - (float)t_begin)/1000000.0F<< endl;
	
	}

	system("pause");
}