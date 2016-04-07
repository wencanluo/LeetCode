/*Find Minimum in Rotated Sorted Array II Total Accepted: 9897 Total Submissions: 33830 My Submissions Question Solution 
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

Author: Wencan Luo
Language: C++
Date: 11/30/2014
*/

class Solution {
public:
    int findMinRec(vector<int> &num, int i, int j){
        //modified binary search
        if(j-i <= 0) return -1;
        if(j-i == 1) return num[i];
        if(j-i == 2) return min(num[i], num[j-1]);
        
        int begin = num[i];
        int end = num[j-1];
        if(begin < end) return begin;
        
        if(begin > end){
            int k = (i+j)/2;
            int mid = num[k];
            
            if(mid < begin){
                return findMinRec(num, i, k+1);
            }else{
                return findMinRec(num, k, j);
            }
        }
        
        if(begin == end){
            int k = (i+j)/2;
            int mid = num[k];
            
            if(mid < begin){
                return findMinRec(num, i, k+1);
            }else if(mid > begin){
                return findMinRec(num, k, j);
            }else{
                return min(findMinRec(num, i, k), findMinRec(num, k+1, j));
            }
        }
    }
    
    int findMin(vector<int> &num) {
        return findMinRec(num, 0, num.size());
    }
};