#include<bits/stdc++.h>
using namespace std;
int BracketColoring(string str  , int n , vector<int>&res)
{
	if(str.size()%2 != 0) return -1;
	int c1 = 0 , c2 = 0;
	for(int i = 0 ; i < str.size() ; i++)
	{
		if(str[i] == '(') c1++;
		else c2++;
	}
	if(c1 != c2) return -1;
	int cnt = 0;
	stack<char>S;
	int c = 0;
	for(int i = 0 ; i < n ; i++)
	{
	    if(str[i] == '(' && cnt == 0)
		{
			S.push(str[i]);
		}
		else if(str[i] == ')' && !S.empty())
		{
			res.push_back(1);
			res.push_back(1);
			S.pop();
			if(c == 0)
			{
				c = 1;
			}
			else
			{
				c = 2;
			}
		}
		else if(str[i] == ')' && S.empty())
		{
			cnt++;
		}
		else
		{
			cnt--;
			res.push_back(2);
			res.push_back(2);
			if(c == 0)
			{
				c = 1;
			}
			else
			{
				c = 2;
			}
		}
	}
	return c;
}
int main()
{
	long long t;
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
		int n;
		string str;
		cin >> n >> str;
		vector<int>res;
		int NoOfColours = BracketColoring(str , n , res);
		cout<<NoOfColours<<endl;
		for(int i = 0 ; i < n ; i++)
		{
			cout<<res[i]<<" ";
		}
	}
	

}