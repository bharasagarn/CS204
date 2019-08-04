#include<iostream>
#include <string>
#include<vector>
#include<cstdlib>

using namespace std;

int num(char c)
{
	return ( (int)(c) - (int)'0' );
}

vector<int> subtract(vector<char>& a, vector<char>& b)
{
	vector<int> res;

	//subtracting the common places part ----
	int bin_a = 0;
	int borrow = 0;
	
	if(a.size()==b.size())
	{
		for(int i=0; i<a.size(); i++)
		{
			if(num(a.at(i))>num(b.at(i)))
			{
				bin_a = 1;
				break;
			}
			else if(num(a.at(i))<num(b.at(i)))
			{
				bin_a = 2;
				break;
			}
		}
	}

	     // case : when a = b ----
	if(a.size()==b.size() && bin_a==0)
	{
		res.push_back(0);
		return res;
	}

	     // case : when a > b -----
	if( (a.size()>b.size()) || (bin_a==1) )
	{

		while(b.empty()!=1)
		{
			if( (num(a.back())-borrow)>=num(b.back()) )
			{
				res.push_back( num(a.back()) - borrow - num(b.back()) );
				borrow = 0;
				a.pop_back();
				b.pop_back();
			} 
			else
			{
				res.push_back( (num(a.back())-borrow)+10 - num(b.back()) );
				borrow = 1;
				a.pop_back();
				b.pop_back();
			}
			
		}
		while(a.empty()!=1)
		{
			if(num(a.back())==0 && borrow==1)
			{
				res.push_back(9);
				borrow = 1;
				a.pop_back();
			}
			else{
				res.push_back( num(a.back())-borrow );
				borrow = 0;
				a.pop_back();
			}
			
		}

		return res;
	}


	
	     // case : when a < b ------
	if( (a.size()<b.size()) || (bin_a==2) )
	{
		while(a.empty()!=1)
		{
			if( (num(b.back())-borrow)>=num(a.back()) )
			{
				res.push_back( num(b.back()) - borrow - num(a.back()) );
				borrow = 0;
				a.pop_back();
				b.pop_back();
			} 
			else
			{
				res.push_back( (num(b.back())-borrow)+10 - num(a.back()) );
				borrow = 1;
				a.pop_back();
				b.pop_back();
			}
		}
		while(b.empty()!=1)
		{
			if(num(b.back())==0 && borrow==1)
			{
				res.push_back(9);
				borrow = 1;
				b.pop_back();
			}
			else{
				res.push_back( num(b.back())-borrow );
				borrow = 0;
				b.pop_back();
			}
		}
		
		return res;
	}

	return res;
}

int main()
{

	// taking inputs -----
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
		res[i]=subtract(A[i],B[i]);
		while(res[i].empty()!=1)
		{
			cout << res[i].back();
			res[i].pop_back();
		}
		cout << endl;
	}


	return 0;
}