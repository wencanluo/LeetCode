/*Find Peak Element Total Accepted: 763 Total Submissions: 2554 My Submissions Question Solution 
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Author: Wencan Luo
Language: C++
Date: 12/05/2014
*/

class Solution {
public:
    int findPeakElementRec(const vector<int> &num, int i, int j) {
        if(j-i+1 == 0) return -1;
        if(j-i+1 == 1) return i;
        if(j-i+1 == 2){
            if(num[i] < num[j]) return j;
            return i;
        }
        
        if(num[i] > num[i+1]) return i;
        if(num[j] > num[j-1]) return j;
        
        int mid = (i+j)/2;
        if(num[mid] > num[mid-1] && num[mid] > num[mid+1]) return mid;
        
        if(num[mid] <= num[i]){
            return findPeakElementRec(num, i, mid);
        }
        
        if(num[mid] <= num[j]){
            return findPeakElementRec(num, mid, j);
        }

        if(num[mid] < num[mid+1]){
            return findPeakElementRec(num, mid, j);
        }
        
        if(num[mid] < num[mid-1]){
            return findPeakElementRec(num, i, mid);
        }
        
        return -1;
    }
    
    int findPeakElement(const vector<int> &num) {
        return findPeakElementRec(num, 0, num.size()-1);
    }
    
    int findPeakElement_On(const vector<int> &num) {
        int N = num.size();
        
        if(N == 0) return -1;
        if(N == 1) return 0;
        
        for(int i=0;i<N;i++){
            if(i==0){
                if(num[0] > num[1]) return 0;
            }
            else if(i==N-1){
                if(num[N-1] > num[N-2]) return N-1;
            }else{
                if(num[i] > num[i-1] && num[i] > num[i+1]) return i;   
            }
        }
    }
};