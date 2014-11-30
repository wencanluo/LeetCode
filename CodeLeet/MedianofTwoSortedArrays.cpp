/*Median of Two Sorted ArraysMar 28 '116654 / 33995
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Author: Wencan Luo
Language: C++
Date: 08/15/2013
*/

#include<iostream>
using namespace std;
#include<climits>

#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<stack>
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

class Solution {
public:
    int binarySearch(int A[], int begin, int end, int V){
       if(begin >= end) return -1;
       if(begin +1 == end){
           if(A[begin] == V) return begin;
    	   if(A[begin] < V) return end;
		   if(A[begin] > V) return begin;
           return end;
       }
       
       int mid = 0;
       while(begin < end){
		   mid = (begin+end)/2;
           if(A[mid] == V) return mid;
           if(A[mid] < V){
               begin = mid+1;
           }else{
			   end = mid;
		   }
       }
       
       return begin;
    }
	
	int findSortedArraysK(int A[], int m, int B[], int n, int K) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(m==0 && n==0) return 0;
		if(m==0) return B[K];
		if(n==0) return A[K];
		if(m+n <= K) return 0;

		int *pA = A;
		int *pB = B;
		if(A[0] > B[0]){
			pA = B;
			pB = A;
			int t = m;
			m = n;
			n = t;
		}

		if(pA[m-1] <= pB[0]){
			if(K >= m){
				return pB[K-m];
			}else{
				return pA[K];
			}
		}

		if(pA[0] > pB[n-1]){
			if(K >= n){
				return pA[K-n];
			}else{
				return pB[K];
			}
		}

		int begin = 0;
		int end = m;

		int k = 0;
		int mid = 0;
		while(begin < end){
			mid = (begin+end)/2;
			k = binarySearch(pB, 0, n, pA[mid]);
			if(k >= n){
				if(mid + n <= K){
					return pA[K-n];
				}else{
					end = mid;
				}
			}else if(k == 0){
				if(mid >= K){
					return pA[K];
				}else{
					begin = mid+1;
				}
			}else{
				if(mid+k == K){
					return min(pA[mid], pB[k]);
				}else if(mid+k < K){
					begin = mid+1;
				}else{
					end = mid;
				}
			}
		}
		
		//not found in pA
		mid = (begin+end)/2;
		return pB[K-mid];
    }

    double findMedianSortedArrays_Ologmlogn(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if((m+n)%2==0){
			return findSortedArraysK(A, m, B, n, (m+n)/2)/2. + findSortedArraysK(A, m, B, n, (m+n)/2-1)/2.;
		}else{
			return findSortedArraysK(A, m, B, n, (m+n)/2);
		}
		
		return 0;
    }
    
    int findSortedArraysKRec(int A[], int aB, int aE, int B[], int bB, int bE, int K) {
        if(aB == aE && bB == bE){
            return 0;
        }
        
        int aM = (aB + aE)/2;
        int bM = (bB + bE)/2;

        if(A[aM] == B[bM]){
             if(aM+bM+1 == K){
                return A[aM];
            }else if(aM+bM+1 < K){
                
            }else{
                
            }
        }else if(A[aM] > B[bM]){
            
        }else{
            
        }
        
        return 0;
    }
            
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if((m+n)%2==0){
    		return findSortedArraysKRec(A, 0, m, B, 0, n, (m+n)/2)/2. + findSortedArraysKRec(A, 0, m, B, 0, n, (m+n)/2-1)/2.;
		}else{
			return findSortedArraysKRec(A, 0, m, B, 0, n, (m+n)/2);
		}
        
		return 0;
    }
};

void main(){
    Solution s;

	int a[] = {2};
	int b[] = {1,3};
	int m = sizeof(a)/sizeof(a[0]);
	int n = sizeof(b)/sizeof(b[0]);
    
	cout<< s.findMedianSortedArrays(a, m, b, n) << endl;
	for(int i=0;i<10;i++){
		//cout<< s.findSortedArraysK(a, m, b, n, i) << endl;
	}

	system("pause");
}

