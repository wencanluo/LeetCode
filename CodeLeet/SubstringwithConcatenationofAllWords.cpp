/*Substring with Concatenation of All WordsFeb 24 '125071 / 18608
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

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
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> r;
        if(S== "") return r;
		int n = L.size();
		if(n==0) return r;

		//construct a map
		map<string, int> M;
		map<string, int> A;
		for(int i=0;i<n;i++){
			string t = L[i];
			if(M.find(t) == M.end()){
				M[t] = 1;
			}else{
				M[t]++;
			}
		}

		int count = 0;
		int m = L[0].size();
		for(int i=0;i<=int(S.size())-n*m;i++){
			string t = S.substr(i, m);
			if(M.find(t) == M.end()){//reset A
				continue;
			}

			A.clear();
			count = 0;

			for(int j=i;j<S.size();j+=m){
				string t = S.substr(j, m);
				
				if(A.find(t) == A.end()){
					A[t] = 1;
				}else{
					A[t]++;
				}
				if(A[t] <= M[t]){
					count++;
				}else{
					break;
				}
			}
			if(count == n){
				r.push_back(i);
			}
		}
		
		return r;
    }
};

void main(){
	Solution s;
	
	char a[2][2] = {"a", "a"};
	vector<string> v;
	for(int i=0;i<2;i++){
		v.push_back(a[i]);
	}

	vector<int> r = s.findSubstring("aa", v);
	for(int i=0;i<r.size();i++){
		cout << r[i] << ",";
	}

	system("pause");
}
