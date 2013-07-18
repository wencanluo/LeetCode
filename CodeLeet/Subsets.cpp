/*SubsetsApr 18 '124106 / 10620
Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Subsets II Jun 25 '123080 / 8630
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

Author: Wencan Luo
Language: C++
Date: 07/17/2013
*/

#include <iostream>
#include <algorithm>

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getSubSet(vector<int> &A, int i){
		vector<int> tmp;
		
		for(int k=0;k<A.size() && i > 0;k++){
			if( (i&1) == 1){
				tmp.push_back(A[k]);
			}
			i >>= 1;
		}

		return tmp;
	}

    vector<vector<int> > subsets_permutation(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> A(S.begin(), S.end());

		sort(A.begin(), A.end());

		int n = A.size();

		vector< vector<int> > res;

		for(int i=0;i< (1<<n);i++){
			vector<int> tmp = getSubSet(A, i);
			res.push_back(tmp);
		}

		return res;
    }

	vector<vector<int> > subsetsRec(vector<int> &A, int k){
		vector<vector<int> > res;
		if(k < 0) return res;

		if(k==0) {
			vector<int> tmp;
			res.push_back(tmp);

			tmp.push_back(A[0]);
			res.push_back(tmp);
			return res;
		}

		vector<vector<int> > left = subsetsRec(A, k-1);

		for(int i=0;i<left.size();i++){
			vector<int> subleft = left[i];
			res.push_back(subleft);

			subleft.push_back(A[k]);
			res.push_back(subleft);
		}

		return res;
	}

	vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> A(S.begin(), S.end());
		sort(A.begin(), A.end());

		return subsetsRec(A, A.size()-1);
    }

	void getCount(vector<int> A, vector<int> &B, vector<int> &C){//get count of unique numbers in a sorted array
		int n=A.size();

		int count = 1;

		for(int i=0;i<n-1;i++){
			if(A[i] == A[i+1]) {
				count++;
			}else{
				B.push_back(A[i]);
				C.push_back(count);
				count = 1;
			}
		}

		if(A[n-2] == A[n-1]){
			B.push_back(A[n-2]);
			C.push_back(count);
		}else{
			B.push_back(A[n-1]);
			C.push_back(1);
		}
	}

	vector<vector<int> > subsetsWithDupRec(vector<int> &A, vector<int> &C, int k){
		vector<vector<int> > res;
		if(k < 0) return res;

		if(k==0) {
			vector<int> tmp;
			res.push_back(tmp);

			for(int i=0;i<C[0];i++){
				tmp.push_back(A[0]);
				res.push_back(tmp);
			}

			return res;
		}

		vector<vector<int> > left = subsetsWithDupRec(A, C, k-1);

		for(int i=0;i<left.size();i++){
			vector<int> subleft = left[i];
			res.push_back(subleft);

			for(int j=0;j<C[k];j++){
				subleft.push_back(A[k]);
				res.push_back(subleft);
			}
		}

		return res;
	}

	vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> A(S.begin(), S.end());
		sort(A.begin(), A.end());
		
		vector<int> B;
		vector<int> C;
		getCount(A, B, C);
	
		return subsetsWithDupRec(B, C, B.size()-1);
    }
};

void main()
{
	int ab = 1 & 1;
	cout << ab;

	Solution s;

	int a[] = {1,1,2,2};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));

	//vector<int> c = s.getCount(v);
	vector<int> B;
	vector<int> C;
	s.getCount(v, B, C);

	vector<vector<int> > res = s.subsetsWithDup(v);

	system("pause");
}