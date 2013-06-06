/*Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
Author: Wencan Luo
Language: C++
Date: 06/05/2013
*/

#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<algorithm>

#include<map>

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(num.size() == 0) return 0;
		int res = 0;

        map<int,int> A;
		for(vector<int>::iterator it = num.begin();it<num.end();it++){
			A[*it] = 0;
		}

		for(vector<int>::iterator it = num.begin();it<num.end();it++){
			if(A[*it] == 1) continue;
			
			int v = *it;
			A[v] = 1;
			
			int count = 1;

			int k = v+1;
			while(A.find(k) != A.end()){
				A[k] = 1;
				k++;
				count++;
			}

			k = v-1;
			while(A.find(k) != A.end()){
				A[k] = 1;
				k--;
				count++;
			}

			if(count > res){
				res = count;
			}
		}

		return res;
    }
};

void main(){
	Solution s;
	
	int a[] = {100, 4, 200, 1, 3, 2};
	vector<int> vec(a, a+sizeof(a)/sizeof(a[0]));
	cout << s.longestConsecutive(vec) << endl;

	//system("pause");
}
