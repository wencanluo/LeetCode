/*Two Sum Mar 14 '1114357 / 45486
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
    
Author: Wencan Luo
Language: C++
Date: 08/20/2013
*/
    
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	
	struct Compare{
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.first < b.first;
		}
	}compare;

    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = -1;
		int right = -1;

		int n = numbers.size();

		vector<pair<int, int>> A;
		A.resize(n);
		for(int i=0;i<n;i++){
			A[i] = make_pair(numbers[i], i+1);
		}

		sort(A.begin(), A.end(), compare);

		int i = 0;
		int j = n-1;
		while(i < j){
			int sum = A[i].first + A[j].first;
			if(sum == target){
				left = A[i].second;
				right = A[j].second;
				break;
			}else if(sum < target){
				i++;
			}else{
				j--;
			}
		}

		vector<int> r;
		if(left < right){
			r.push_back(left);
			r.push_back(right);
		}else{
			r.push_back(right);
			r.push_back(left);
		}
		return r;
    }
};

void main()
{
	Solution s;

	int a[] = {1,2,3};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));

	system("pause");
}