
//Binary Search Question
//Similar to Allocate Book Problem
//https://www.spoj.com/problems/AGGRCOW/


#include <bits/stdc++.h>
using namespace std;


bool checkValidation(int mid, vector<int>&v, int n, int c)
{
	int i = 0, j = i+1;
	int cnt = 1;
	while(j < n && cnt != c)
	{
		if( (v[j] - v[i]) < mid  )
		{
			j++;
		}

		else
		{
			i = j; j = i+1; cnt++;
		}
		
	}
	if(cnt == c)
		return true;
	else
		return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, c;
		cin >> n >> c;
		vector<int>v(n);
		
		int mx = INT_MIN, mn = INT_MAX;
		for(int i = 0; i<n; i++)
		{
			int temp;  cin >> temp;
			if(temp > mx) mx = temp;

			if(temp < mn) mn = temp;

			v[i] = temp;
		}
		sort(v.begin(), v.end());
		
		int res = 0;

		int st = 1, end = (mx - mn);
		while(st <= end)
		{
			int mid = st + (end - st)/2;
			if(checkValidation(mid, v, n, c))
			{
				res = mid;
				st = mid+1;
			}
			else
			{
				end = mid-1;
			}

		}
		cout << res << endl;

	}
    return 0;
}

