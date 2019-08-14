#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
typedef long long int loo;

vector<char> stack;

void push(char c)
{
	stack.push_back(c);
}

char pop()
{
	stack.pop_back();
}

void check(vector<char>& seq)
{
	loo n = seq.size();
	loo mods = 0, i;
	for(i=0; i<n; ++i)
	{
		// if(seq[i]!='(' || seq[i]!='{' || seq[i]!='[' || seq[i]!='<' || seq[i]!='|' || seq[i]!=')' || seq[i]!='}' || seq[i]!=']' || seq[i]!='>'){
		// 	mods=1;
		// 	break;
		// }
		if(seq[i]=='(' || seq[i]=='{' || seq[i]=='[' || seq[i]=='<' || seq[i]=='|' || seq[i]==')' || seq[i]=='}' || seq[i]==']' || seq[i]=='>')
		{
			if(seq[i]=='(' || seq[i]=='{' || seq[i]=='[' || seq[i]=='<')
				push(seq[i]);
			if(seq[i]=='|' && mods==0){
				mods=1;
				push(seq[i]);
				continue;
			}
			if((seq[i]==')' || seq[i]=='}' || seq[i]==']' || seq[i]=='>') && stack.size()==0){
				mods=1;
				break;
			}
			if(seq[i]==')'){
				if(stack.back()=='(') pop();
				else{
					break;
				}
			}
			if(seq[i]=='}'){
				if(stack.back()=='{') pop();
				else{
					break;
				}
			}
			if(seq[i]==']'){
				if(stack.back()=='[') pop();
				else{
					break;
				}
			}
			if(seq[i]=='>'){
				if(stack.back()=='<') pop();
				else{
					break;
				}
			}
			if(seq[i]=='|' && mods==1){
				if(stack.back()=='|'){
					pop();
					mods=0;
				} 
				else break;
			}
		}
		else {
			mods=1;
			break;
		}
		
	}
	if(i==n && mods==0 && stack.size()==0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main()
{
	loo q;
	cin >> q;
	vector<char> seq[q];
	for(size_t i=0; i<q; ++i)
	{
		while(true)
		{
			char c;
			cin >> c;
			seq[i].push_back(c);
			if(cin.peek()=='\n' || cin.peek()==EOF) break;
		}
	}
	for(size_t i=0; i<q; ++i)
	{
		check(seq[i]);
	}

	return 0;
}