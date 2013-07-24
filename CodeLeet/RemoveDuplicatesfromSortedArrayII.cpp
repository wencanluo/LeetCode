/*Remove Duplicates from Sorted Array IIApr 19 '123204 / 7955
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

Author: Wencan Luo
Language: C++
Date: 07/23/2013
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
 
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n==0) return 0;

        int k=1;
		int count = 1;
		for(int i=1;i<n;i++){
			if(A[i] == A[i-1]){
				count++;
				if(count <= 2){
					A[k] = A[i];
					k++;
				}
			}else{
				count = 1;
				A[k] = A[i];
				k++;
			}
		}

		return k;
    }
};

int main(){
	Solution s;
    
	int a[] = {1,1,1,2,2,2,3,3,4};
	int n= s.removeDuplicates(a, sizeof(a)/sizeof(a[0]));

	for(int i=0;i<n;i++){
		cout << a[i] << ",";
	}
	cout << endl;

	system("pause");
    return 0;	
}
