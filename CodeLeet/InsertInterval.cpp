/*Insert IntervalMar 27 '123940 / 13994
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Author: Wencan Luo
Language: C++
Date: 08/01/2013
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> A;
		if(intervals.size() == 0){
			A.push_back(newInterval);
			return A;
		}

		int k = 0;
		for(int i=0; i<intervals.size();i++){
			if(intervals[i].end < newInterval.start){
				A.push_back(intervals[i]);
				k++;
			}else{
				break;
			}
		}

		if(k<intervals.size() && intervals[k].start < newInterval.start){
			newInterval.start = intervals[k].start;
		}		

		for(int i=k; i<intervals.size();i++){
			if(intervals[i].start <= newInterval.end){
				k++;
				continue;
			}
		}

		if(k>0){
			if(intervals[k-1].end > newInterval.end){
				newInterval.end = intervals[k-1].end;
			}
		}
		
		A.push_back(newInterval);

		//search the end
		for(int i=k; i<intervals.size();i++){
			A.push_back(intervals[i]);
		}

		return A;
    }
};

void main(){
	Solution s;

	system("pause");
}
