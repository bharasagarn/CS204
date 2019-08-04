#include<iostream>
#include<istream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

int num(char c) 
{
	return ( (int)(c) - (int)'0' );
}

vector<int> add(vector<char>& a, vector<char>& b)
{

	vector<int> res;

	/// adding the common places part ----
	int carry =0;
	while(a.empty()==0 && b.empty()==0)
	{
		int t = num(a.back()) + num(b.back()) + carry;
		carry = t/10;
		res.push_back(t%10);
		a.pop_back();
		b.pop_back();
	}

	/// adding the remaining part of larger digits number ----
	if(b.empty()==1 && a.empty()!=1)
	{
		while(a.empty()!=1)
		{
			int t = num(a.back()) + carry;
			carry = t/10;
			res.push_back(t%10);
			a.pop_back();
		}
		
	}
	else if(a.empty()==1 && b.empty()!=1) {
		while(b.empty()!=1)
		{
			int t = num(b.back()) + carry;
			carry = t/10;
			res.push_back(t%10);
			b.pop_back();
		}
	}
	if(carry!=0) res.push_back(carry);

	return res;
}


int main()
{
	int n;
	cin >> n;
	vector<char> A[n],B[n];

	/// taking inputs ----
	for(int i=0; i<n; i++)
	{
		char c;
		while(true)
		{
			cin >> c;
			A[i].push_back(c);
			if(cin.peek()=='\n' || cin.peek()==EOF) break;
		}
		while(true)
		{
			cin >> c;
			B[i].push_back(c);
			if(cin.peek()=='\n' || cin.peek()==EOF) break;
		}
	}
	

	//// printing the result -----
	vector<int> res[n];
	for(int i=0; i<n; i++)
	{
		res[i]=add(A[i],B[i]);
		while(res[i].empty()!=1)
		{
			cout << res[i].back();
			res[i].pop_back();
		}
		cout << endl;
	}
 	

	return 0;
}