/*Best Time to Buy and Sell Stock Oct 30 '123981 / 9069
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

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
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low, high, maxgain;
		if(prices.size() == 0) return 0;

		low=high=prices[0];
		maxgain = 0;

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
		}
		
		return maxgain;
    }
};

void main(){
	
	int a[] = {1,2,3,4};
	vector<int> v(a,a+sizeof(a)/sizeof(a[0]));

	Solution s;

	cout << s.maxProfit(v);

	system("pause");
}
