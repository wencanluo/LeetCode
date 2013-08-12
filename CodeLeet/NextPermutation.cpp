/*Next PermutationFeb 25 '124235 / 11932
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

Author: Wencan Luo
Language: C++
Date: 08/11/2013
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
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=num.size();
		if(n <=1) return;
		
		int i;
		for(i=n-1;i>0;i--){
			if(num[i] > num[i-1]) break;
		}

		if(i==0){//reverse(num)
			reverse(num.begin(), num.end());
		}else{
			//find
			int t = num[i-1];
			int k=0;
			for(k=n-1;k>=i;k--){
				if(num[k] > t) break;
			}
			
			//swap, t, k
			num[i-1] = num[k];
			num[k] = t;

			//swap num (i, n-1)
			reverse(num.begin() + i, num.end());
		}
    }
};

void main(){
	Solution s;
	
	int a[] = {2,4,3,1};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));

	s.nextPermutation(v);

	for(int i=0;i<v.size();i++){
		cout << v[i] << ",";
	}
	cout << endl;
	
	system("pause");
}
