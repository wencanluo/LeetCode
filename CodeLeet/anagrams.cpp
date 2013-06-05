/**
Given an array of strings, return all groups of strings that are anagrams.
An anagram is a type of word play, the result of rearranging the letters of a word or phrase to produce a new word or phrase, using all the original letters exactly once;
Note: All inputs will be in lower-case.

Author: Wencan Luo
Language: C++
Date: 08/31/2012
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:

	string generate_bits(string &t)
	{
		string bits;

		for(int i=0;i<26;i++)
		{
			bits.push_back('0');
		}

		for(int i=0;i<t.size();i++)
		{
			bits[t[i]-'a']++;
		}

		return bits;
	}

	vector<string> anagrams(vector<string> &strs) {//
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, int> bitmap;
		map<string, string> stringmap;

		//add one by one to the contrainer
		vector< string >::iterator it;

		for(it = strs.begin(); it < strs.end(); it++)
		{
			//generate the anagrams list
			string t = *it;
			string bits = generate_bits(t);
			stringmap[t] = bits;

			if( bitmap[bits] != NULL)
				bitmap[bits] ++;
			else
				bitmap[bits] = 1;
		}

		vector< string > res;
		for(it = strs.begin(); it < strs.end(); it++)
		{
			string t = *it;
			if(bitmap[stringmap[t]] > 1)
				res.push_back(t);
		}

        return res;
    }

	vector<string> generate_anagrams(string t)
	{
		vector<string> res;
		int n = t.size();

		for(int i=0;i<n;i++)
		{
			string tmp = t.substr(i,n-i) + t.substr(0,i);
			res.push_back(tmp);
		}

		//center anagram
		string::reverse_iterator it;
		string ra;
		for(it = t.rbegin(); it < t.rend(); it++)
		{
			ra.push_back(*it);
		}
		res.push_back(ra);

		return res;
	}

    vector<string> anagrams_overtime(vector<string> &strs) {//
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<string> > container;

		//add one by one to the contrainer
		vector< string >::iterator it;

		for(it = strs.begin(); it < strs.end(); it++)
		{
			//generate the anagrams list
			string t = *it;
			vector<string> anas = generate_anagrams(t);

			int cit;

			bool flag = false;
			for(cit = 0; cit < container.size(); cit++)
			{
				//set the flag	
				vector<string>::iterator ait;
				for(ait = anas.begin(); ait < anas.end(); ait++)
				{
					if(find(container[cit].begin(), container[cit].end(), *ait) != container[cit].end())
					{
						container[cit].push_back(t);
						flag = true;
						break;
					}
				}

				if(flag) break;
			}

			if(!flag)//no anagrams found
			{
				vector<string> tmp;
				tmp.push_back(*it);
				container.push_back(tmp);
			}
		}

		vector< string > res;
		int cit;

		for(cit = 0; cit < container.size(); cit++)
		{
			if( container[cit].size() > 1)
			{
				int it2;
				for(it2 = 0; it2< container[cit].size(); it2++)
				{
					res.push_back(container[cit][it2]);
				}
			}
		}

        return res;
    }
};


void main()
{
	string s[] = {"cab","pug","pei","nay","ron","rae","ems","ida","mes"};

	vector<string> vc(s, s + sizeof(s)/sizeof(string));

	Solution ss;
	vector<string> res = ss.anagrams(vc);

	//res = ss.generate_anagrams("abcd");

	vector<string>::iterator it;

	for(it = res.begin(); it < res.end(); it++)
	{
		cout << *it << ", ";
	}

	system("pause");
}