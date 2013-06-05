#include <iostream>

#include <vector>
using namespace std;

class Solution
{
public:
	int binary_search(vector<int> v, int a)
	{
		int ret = -1;

		int n = v.size();
		int begin = 0;
		int end = n-1;
		int mid;
		
		while(begin <= end)
		{
			mid = (begin+end)/2;

			if(v[mid] == a)
			{
				ret = mid;
				break;
			}
			else if(v[mid] < a)//a is in the right side
			{
				begin = mid+1;
			}
			else//v[mid] > a
			{
				end = mid-1;
			}
		}
		
		return ret;
	}
};

void main()
{
	int a[] = {0,1,2,3,4,5,6,7};
	vector<int> v(a,a+sizeof(a)/sizeof(a[0]));

	Solution s;
	cout << s.binary_search(v,8)<<endl;

	system("pause");
}