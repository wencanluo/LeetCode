/*
Maximum Gap Total Accepted: 4169 Total Submissions: 17343 My Submissions Question Solution 
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Author: Wencan Luo
Language: C++
Date: 01/06/2015
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:

	int getMax(vector<int> &num){
		if(num.size()<1) return -1;
		int max=num[0];
		
		for(int i=0;i<num.size();i++){
			if(num[i] > max){
				max = num[i];
			}
		}
		
		return max;
	}
	
	int getMin(vector<int> &num){
		if(num.size()<1) return -1;
		int min=num[0];
		
		for(int i=0;i<num.size();i++){
			if(num[i] < min){
				min = num[i];
			}
		}
		
		return min;
	}
	
    int maximumGap(vector<int> &num) {
        if(num.size() < 2) return 0;
        
        int max = getMax(num);
        int min = getMin(num);
        if(max == min) return 0;
        
      	int N = num.size();
        
        double d = (max-min)/(double)(N-1);
        
        vector<int> Max;
        Max.resize(N, -1);
        
        vector<int> Min;
        Min.resize(N, -1);
        
        for(int i=0;i<N;i++){
        	int k = floor((num[i]-min)/d);
        	
        	//update Max
        	Max[k] = Max[k] > num[i] ? Max[k] : num[i];
        	
        	//update Min
        	if(Min[k] == -1){
        		Min[k] = num[i];
        	} else {
        		Min[k] = Min[k] < num[i] ? Min[k] : num[i];
        	}
        }
        
        int r = floor(d);
        int i=1,j=0;
        while(i<N){
            i=j+1;
            while(Min[i] == -1 && i<N) {
                i++;
            }
            
            if(i>=N) break;
            
        	if( (Min[i] - Max[j]) >= r){
        		r = Min[i] - Max[j];
        	}
        	
        	j=i;
        }
        
        return r;
    }
};

int main()
{
	
	int a[] = {1,3,6,9};
	vector<int> v(a, a+4);
	
	Solution s;
	cout << s.maximumGap(v) << endl;
	
	return 0;
}