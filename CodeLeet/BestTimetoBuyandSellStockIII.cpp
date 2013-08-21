/*Best Time to Buy and Sell Stock III Nov 7 '123023 / 9463
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Author: Wencan Luo
Language: C++
Date: 06/23/2013
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
	vector<int> maxProfitLeft(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> r;

		int n=prices.size();
        int low, high, maxgain;
		if(n == 0) return r;
		r.resize(n);

		low=high=prices[0];
		maxgain = 0;
		r[0] = 0;

		for(int i=1;i<prices.size();i++){
			if(prices[i] < low){
				low = prices[i];
				high = prices[i];
			}

			if(prices[i] > high){
				high = prices[i];

				if(high-low > maxgain){
					maxgain = high-low;
				}
			}

			r[i] = maxgain;
		}
		
		return r;
    }

	vector<int> maxProfitRight(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> r;

		int n=prices.size();
        int low, high, maxgain;
		if(n == 0) return r;
		r.resize(n);

		low=high=prices[n-1];
		maxgain = 0;
		r[n-1] = 0;

		for(int i=n-2;i>=0;i--){
			if(prices[i] > high){
				low = prices[i];
				high = prices[i];
			}

			if(prices[i] < low){
				low = prices[i];

				if(high-low > maxgain){
					maxgain = high-low;
				}
			}

			r[i] = maxgain;
		}
		
		return r;
    }

	int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxgain = 0;
		int n = prices.size();
		if(n == 0) return 0;

		vector<int> left = maxProfitLeft(prices);
		vector<int> right = maxProfitRight(prices);

		for(int i=0;i<n;i++){
			maxgain = max(maxgain, left[i] + right[i]);
		}

		return maxgain;
    }
};

void main(){
	
	int a[] = {8,3,6,2,8,8,8,4,2,0,7,2,9,4,9};
	vector<int> v(a,a+sizeof(a)/sizeof(a[0]));

	Solution s;

	cout << s.maxProfit(v);

	system("pause");
}
