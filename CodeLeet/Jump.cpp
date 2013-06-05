/*
Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

Author: Wencan Luo
Language: C++
Date: 11/27/2012
Solution: record the furtherst step that can reach
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(n <= 1) return true;

		int k = n-1;//last one
		for(int i=n-2;i>=0;i--)
		{
			if(A[i] + i >= k) 
			{	
				k = i;
			}
		}

		if( k == 0)
		{
			return true;
		}

		return false;
    }

	class PairCompare{
	public:
		bool operator()(pair<int,int> a, pair<int,int> b)
		{
			if( a.first <= b.first ) {
				return true;
			}

			return false;
		}
	};

	int jump(int A[], int n)//Greedy
	{
		if(n==1) return 0;

		int k=0;
		int jumps = 0;
		int curMax;
		while(k < n)
		{
			curMax = k + A[k];

			if(A[k] > 0) jumps++;
			else return -1;

			if(curMax >= n-1) return jumps;

			int tmpMax = 0;

			for(int i=k+1;i<=curMax;i++)
			{
				if(A[i]+i >= tmpMax)
				{
					k = i;
					tmpMax = A[i]+i;
				}
			}
		}

		return jumps;
	}

	int jumpBreath(int A[], int n)
	{
		if(!canJump(A,n)) return -1;

		if(n==1) return 0;

		queue< pair<int,int> > q;
		vector< bool > visted;
		visted.resize(n,false);
		q.push(make_pair(0,0));

		while(!q.empty())
		{
			pair<int,int> p = q.front();
			q.pop();
			if(p.first==n-1){return p.second;}

			visted[p.first] = true;

			for(int i=p.first+1; i <= A[p.first] + p.first && i < n; i++)
			{
				if(!visted[i])
				{
					q.push(make_pair(i,p.second+1));
				}
			}
		}

		return -1;
	}

	int jumpDag(int A[], int n) {//Shortest distance for Dag
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> s;
		s.resize(n,n+1);

		s[0] = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1; j <= i+A[i] && j < n; j++)
			{
				s[j] = min(s[j], s[i]+1);
				if(j==n-1)//reached the last one
				{
					if(s[n-1] <= n) return s[n-1];
				}
			}
			
		}
		
		if(s[n-1] > n) return -1;
		return s[n-1];
    }
};

void main()
{
	Solution s;
	int A[] = {2,3,1,1,4};
	int d = s.jump(A, sizeof(A)/sizeof(A[0]));

	cout << d << endl;
	system("pause");
}