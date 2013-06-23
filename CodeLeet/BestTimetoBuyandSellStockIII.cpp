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
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxgain;
		if(prices.size() == 0) return 0;

		maxgain = 0;

		for(int i=0;i<prices.size()-1;i++){
			if(prices[i+1] > prices[i]){
				maxgain = maxgain + prices[i+1] - prices[i];
			}
		}
		
		return maxgain;
    }
};

void main(){
	
	int a[] = {1,2,1,2,3,4};
	vector<int> v(a,a+sizeof(a)/sizeof(a[0]));

	Solution s;

	cout << s.maxProfit(v);

	system("pause");
}
