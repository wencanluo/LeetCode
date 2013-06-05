/*Sum Root to Leaf NumbersFeb 193538 / 9970
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

Author: Wencan Luo
Language: C++
Date: 06/05/2013
*/

#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<algorithm>

class Solution {
public:

	void PrintMatrix(vector<vector<int>> A){
		for(int i=0;i<A.size();i++){
			for(int j=0;j<A.size();j++){
				cout << A[i][j];
			}
			cout << endl;
		}
	}

	bool checkPalindrome(string s, int i, int j){
		for(int k=i; k < (j+i)/2; k++){
			if(s[k] != s[i+j-k-1]) {
				return false;
			}
		}

		return true;
	}

	void MultipleVectors(vector<vector<string>> &left, vector<vector<string>> &right, vector<vector<string>> &res){
		for(vector<vector<string>>::iterator it1 = left.begin(); it1 < left.end(); it1++){
			for(vector<vector<string>>::iterator it2 = right.begin(); it2 < right.end(); it2++){
				vector<string> tmp(it1->begin(), it1->end());
				tmp.insert(tmp.end(), it2->begin(), it2->end());
				res.push_back(tmp);
			}
		}
	}

	vector<vector<string>> RecusivePartition(string s,  int i, int j) {
		vector<vector<string>> res;
		if(i > j-1) return res;
		if(i==j-1){
			vector<string> tmp;
			tmp.push_back(s.substr(i,j-i));
			res.push_back(tmp);
			return res;
		}

		if(checkPalindrome(s, i, j)){
			vector<string> tmp;
			tmp.push_back(s.substr(i,j-i));
			res.push_back(tmp);
		}

		for(int k=i+1;k<j;k++){
			vector<vector<string>> left;// = RecusivePartition(s, i, k);
			if(checkPalindrome(s, i, k))
			{
				vector<string> tmp;
				tmp.push_back(s.substr(i,k-i));
				left.push_back(tmp);

				vector<vector<string>> right = RecusivePartition(s, k, j);
				MultipleVectors(left, right, res);
			}
		}
		
		return res;
    }

    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<string>> vec = RecusivePartition(s, 0, s.size());	
		return vec;
    }

	void CheckPalindromeN2_2(string s, vector< vector<int> > &A){
		int n = s.size();

		for(int i=0;i<n-1;i++){
			int j = i;
			while(j >= 0 && 2*i-j+1 < n && s[j] == s[2*i-j+1] )
			{
				A[2*j][2*(2*i-j+1)+1] = 0;
				j--;
			}
		}

		for(int i=0;i<n-2;i++){
			int j = i;
			while(j >= 0 && 2*i-j+2 < n && s[j] == s[2*i-j+2] )
			{
				A[2*j][2*(2*i-j+2)+1] = 0;
				j--;
			}
		}
	}

	void CheckPalindromeN2(string s, vector< vector<int> > &A){
		int n = s.size();

		for(int i=0;i<n-1;i++){
			int j = i;
			while(j >= 0 && 2*i-j+1 < n && s[j] == s[2*i-j+1] )
			{
				A[j][2*i-j+1+1] = 1;
				j--;
			}
		}

		for(int i=0;i<n-2;i++){
			int j = i;
			while(j >= 0 && 2*i-j+2 < n && s[j] == s[2*i-j+2] )
			{
				A[j][2*i-j+2+1] = 1;
				j--;
			}
		}
	}

	int minCut(string s){
		int n = s.size();
		if(n==1) return 0;

		vector< vector<int> > A;
		A.resize(n+1);
		for(vector< vector<int> >::iterator it = A.begin(); it < A.end(); it++){
			it->resize(n+1);

			for(vector<int>::iterator it2 = it->begin(); it2 < it->end(); it2++){
				*it2 = n+1;
			}
		}

		//link A with B
		for(int i=0;i<n;i++){
			A[i][i+1] = 1;
		}

		CheckPalindromeN2(s, A);

		/*for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				A[i][j] = checkPalindrome(s, i, j+1) ? 0 : A[i][j];
			}
		}*/
		
		//PrintMatrix(A);

		//if( A[0][n-1] != n) return 0;

		vector<int> D;
		D.resize(n+1);
		for(int i=0;i<n+1;i++){
			D[i] = A[0][i];
		}
		D[0] = 0;

		//Shortest path for the dag
		for(int i=0;i<n+1;i++){
			for(int j=i+1;j<n+1;j++){
				if(A[i][j] != n+1){
					if(D[j] > D[i] + A[i][j]){
						D[j] = D[i] + A[i][j];
					}
				}
			}
		}

		/*for(int i=0;i<n+1;i++){
			cout << D[i];
		}
		cout << endl;*/

		return D[n]-1;
		//return A[0][2*n-1];
	}

	int minCut2(string s){
		int n = s.size();
		if(n==1) return 0;

		//cout << n << endl;

		vector< vector<int> > A;
		A.resize(2*n);
		for(vector< vector<int> >::iterator it = A.begin(); it < A.end(); it++){
			it->resize(2*n);

			for(vector<int>::iterator it2 = it->begin(); it2 < it->end(); it2++){
				*it2 = 2*n;
			}
		}

		//link A with A'
		for(int i=0;i<2*n;i = i + 2){
			A[i][i+1] = 0;
		}

		//link A' to B
		for(int i=0;i<2*(n-1);i = i + 2){
			A[i+1][i+2] = 1;
		}

		CheckPalindromeN2(s, A);

		/*for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				A[i][j] = checkPalindrome(s, i, j+1) ? 0 : A[i][j];
			}
		}*/
		
		//PrintMatrix(A);

		//if( A[0][n-1] != n) return 0;

		/*vector<int> D;
		D.resize(2*n);
		for(int i=0;i<2*n;i++){
			D[i] = A[0][i];
		}
		D[0] = 0;
		*/

		//Shortest path for the dag
		for(int i=0;i<2*n;i++){
			for(int j=i+1;j<2*n;j++){
				if(A[i][j] != 2*n){
					//if(D[i] + A[i][j] < D[j]){
					//	D[j] = D[i] + A[i][j];
					//}
					if(A[0][i] + A[i][j] < A[0][j]){
						A[0][j] = A[0][i] + A[i][j];
					}
				}
			}
		}

		/*for(int i=0;i<2*n;i++){
			cout << D[i];
		}
		cout << endl;*/

		//return D[2*n-1];
		return A[0][2*n-1];
	}

	int minCut_power2n(string s) { //2^n
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> res = partition(s);
		int minCount = s.size();
		for(vector<vector<string>>::iterator it = res.begin(); it < res.end(); it++){
			if(it->size() < minCount){
				minCount = it->size();
			}
		}
		return minCount - 1;
    }
};


void main(){
	Solution s;
	//vector<vector<string>> res = s.partition("ababbbabbaba");
	//s.PrintVector(res);

	//cout << s.minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
	//cout << s.minCut("aa") << endl;
	//cout << s.minCut("abaa") << endl;
	cout << s.minCut("ab") << endl;
	//cout << s.minCut("aa") << endl;

	system("pause");
}
