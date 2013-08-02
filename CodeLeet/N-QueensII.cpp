/*N-QueensMar 20 '122965 / 9262
The n-queens puzzle is the problem of placing n queens on an n*n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

Author: Wencan Luo
Language: C++
Date: 08/02/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<map>
//#include<unordered_set>

#include<queue>
#include<set>

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    void swap(vector<int> &A, int i, int j){
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    
    vector<string> getMap(vector<int> &A){
        vector<string> M;
        int n = A.size();
        string s = "";
        s.resize(n, '.');
        
        for(int i=0;i<n;i++){
            string t = s;
            t[A[i]] = 'Q';
            M.push_back(t);
        }
        
        return M;
    }
    
    bool Check(vector<int> &A, int k){
        if(k<=0) return true;
        
        int n=A.size();
        
        for(int i=0;i<k;i++){
            if(A[k] == A[i]) return false;
            if(abs(A[k]-A[i]) == abs(k-i)) return false;
        }
        return true;
    }
    
    void Permutation(vector<int> &A, int k, vector<vector<string> > &R){
        int n=A.size();
        
        if(k==n-1){
            if(Check(A, k)){
                R.push_back(getMap(A));
            }
            return;
        }
        
        for(int i=k;i<n;i++){
            swap(A,k,i);
            //check A
            if(Check(A, k)){
                Permutation(A, k+1, R);
            }
            
            swap(A,k,i);//swap back
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > R;
        if(n==0) {
            vector<string> t;
            t.push_back("");
            R.push_back(t);
            return R;
        }
        
        vector<int> A;
        A.resize(n);
        
        for(int i=0;i<n;i++){
            A[i] = i;
        }
        
        //generate all the permutations
    	Permutation(A, 0, R);

        return R;
    }
};

void main(){
	Solution s;

    vector<vector<string> > R = s.solveNQueens(8);
	cout << R.size() << endl;

    /*for(int i=0;i<R.size();i++){
        vector<string> M = R[i];
        for(int j=0;j<M.size();j++){
            cout << M[j] << endl;
        }
        cout << endl;
    }*/
 
	system("pause");
}
