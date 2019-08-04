#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<sstream>
using namespace std;

int num(char c) 
{
	return ( (int)(c) - (int)'0' );
}

vector<char> int_to_char(vector<int> a)
{
	vector<char> res_c;
	vector<int> a_ = a;
	while(a_.empty()!=1)
	{
		char c;
		stringstream ss;
		ss << a_.back();
		ss >> c;
		res_c.push_back(c);
		a_.pop_back();
	}
	reverse(res_c.begin(), res_c.end());

	return res_c;
}

vector<char> add(vector<char>& a, vector<char>& b)
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
	reverse(res.begin(), res.end());

	return int_to_char(res);
}

vector<char> multiply(vector<char>& a, vector<char>& b)
{
	vector<char> res;
	res.push_back('0');

	int place = 0;
	vector<int> res_temp;
	while(b.empty()!=1)
	{
		int carry = 0;
		vector<char> a_ = a;
		while(a_.empty()!=1)
		{
			int t = num(a_.back())*num(b.back()) + carry;
			carry = t/10;
			res_temp.push_back(t%10);
			a_.pop_back();
		}
		if(carry!=0) res_temp.push_back(carry);
		reverse(res_temp.begin(), res_temp.end());
		vector<char> restemp = int_to_char(res_temp);
		for(int i=0; i<place; i++) restemp.push_back('0');
		res = add(res,restemp);
		res_temp.clear();
		b.pop_back();
		place += 1;
	}

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
	vector<char> res[n];
	for(int i=0; i<n; i++)
	{
		res[i]=multiply(A[i],B[i]);
		reverse(res[i].begin(), res[i].end());
		while(res[i].empty()!=1)
		{
			cout << res[i].back();
			res[i].pop_back();
		}
		cout << endl;
	}

	return 0;
}