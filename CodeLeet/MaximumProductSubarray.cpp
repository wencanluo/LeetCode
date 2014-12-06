/*Maximum Product Subarray Total Accepted: 14505 Total Submissions: 86670 My Submissions Question Solution 
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Author: Wencan Luo
Language: C++
Date: 12/06/2014
*/

class Solution {
public:
    int Product(int A[], int i, int j){
        int P = 1;
        for(int k=i;k<=j;k++){
            P *= A[k];
        }
        return P;
    }
    
    int maxProductNonZero(int A[], int n, int i, int j){
        if(i>=n) return -1;
        if(j<i) return -1;
        if(j==i) return A[i];
        
        //count negative
        int count = 0;
        for(int k=i;k<=j;k++){
            if(A[k] < 0){
                count++;
            }
        }
        
        int first = -1;
        int last = -1;
        for(int k=i;k<=j;k++){
            if(A[k] < 0){
               first = k;
               break;
            }
        }
        
        for(int k=j;k>=i;k--){
            if(A[k] < 0){
               last = k;
               break;
            }
        }
        
        if(count%2 == 0){
            return Product(A, i, j);
        }else if(count == 1){
            return max(Product(A, i, first-1), Product(A, last+1, j));
        }else{
            int midP = Product(A, first+1, last-1);
            return max(Product(A, i, first-1)*A[first]*midP, midP*A[last]*Product(A, last+1, j));
        }
    }
    
    int maxProduct(int A[], int n) {
        if(n==0) return -1;
        if(n==1) return A[0];
        
        //split by 0
        int i=0;
        while(A[i]==0 && i<n) i++; //first non-zero
        if(i==n) return 0; //all zero
        
        int maxP = A[0];
        
        int k=i+1;
        while(k<n){
            if(A[k] == 0){
                int P = maxProductNonZero(A, n, i, k-1);
                if(P >= maxP){
                    maxP = P;
                }
                
                i=k+1;
                while(A[i]==0 && i<n) i++; //next non-zero
                k = i+1;
            }else{
                k++;
            }
        }
        
        //last one
        if(i != 0){//has 0
          int P = max(0, maxProductNonZero(A, n, i, n-1));  
          maxP = max(P, maxP);
        }else{
            maxP = max(maxP, maxProductNonZero(A, n, i, n-1));
        }
        
        return maxP;
    }
};