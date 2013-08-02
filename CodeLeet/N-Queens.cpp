/*N-Queens IIMar 20 '123565 / 8055
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.

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
    
    bool Check(vector<int> &A, int k){
        if(k<=0) return true;
        
        int n=A.size();
        
        for(int i=0;i<k;i++){
            if(A[k] == A[i]) return false;
            if(abs(A[k]-A[i]) == abs(k-i)) return false;
        }
        return true;
    }
    
    void Permutation(vector<int> &A, int k, int &R){
        int n=A.size();
        
        if(k==n-1){
            if(Check(A, k)){
               R++;
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
    
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int R = 0;
        if(n==0) {
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

    int R = s.totalNQueens(8);
	cout << R << endl;

	system("pause");
}
