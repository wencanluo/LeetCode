/*Merge IntervalsMar 27 '124174 / 14847
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

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

    struct IntervalCompare{
        bool operator () (const Interval a, const Interval b){
            return a.start < b.start;
        }
    }intervalCompare;
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<Interval> A;
        if(intervals.size() == 0) return A;
        
        //sort Interval by start
        sort(intervals.begin(), intervals.end(), intervalCompare);
        
        int k=0;
        while(k<intervals.size()){
            int start = intervals[k].start;
            int end = intervals[k].end;
            
            while(k+1 < intervals.size() && end >= intervals[k+1].start){
                end = max(end, intervals[k+1].end);
                k++;
            }
            A.push_back(Interval(start, end));
            k++;
        }
        return A;
    }
};

void main(){
	Solution s;

	system("pause");
}
