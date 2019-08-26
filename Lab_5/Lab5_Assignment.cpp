#include<bits/stdc++.h>
using namespace std;
typedef long long int loo;
#define loop(i,a,b) for(size_t i=a; i<b; ++i)
#define MAX 1000
#define EMPTY -1

loo find(vector<char> a, char e)
{
	loop(i,0,a.size()) {
		if(a[i]==e) return i;
	}
	return -1;
}

loo num(char c)
{
	return ( (loo)(c) - (loo)'0' );
}

string toString(loo a)
{
	stringstream ss;
	ss << a;
	string s;
	ss >> s;
	return s;
}

string cToString(char x)
{
    string s(1, x);
    return s;
}

loo toInt(string s)
{
    stringstream ss;
    ss << s;
    loo a;
    ss >> a;
    return a;
}

loo prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

void toPostfix(string s, vector<char> var, vector<loo> var_val ,vector<string>& post)
{
	stack<char> st;
    st.push('N');
    loo l = s.length();
    loo i = 0;
    while(i<s.size())
    {
        if(s[i]>='0' && s[i]<='9') {
        	loo p = 0;
        	p = (num(s[i]));
        	i++;
        	while(s[i]>='0' && s[i]<='9' && i<s.size()) {
        		p = (p*10 + num(s[i]));
        		i++;
        	}
        	post.push_back(toString(p));
        }
        else if(isalpha(s[i])) {
        	loo pos = find(var, s[i]);
        	// if(pos==-1) {}
        	post.push_back(toString(var_val[pos]));
        	i++;
        }
        else if(s[i] == '(') {
        	if(s[i+1]=='-') {
        		i+=2;
        		loo p = (num(s[i]));
	        	i++;
	        	while(s[i]>='0' && s[i]<='9' && i<s.size()) {
	        		p = (p*10 + num(s[i]));
	        		i++;
	        	}
	        	string res = "-" + toString(p);
	        	post.push_back(res);
	        	i++;
        	}
        	else {
        		st.push('(');
        		i++;
        	}	
        }
        else if(s[i] == ')')
        {
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                post.push_back(cToString(c));
            }
            if(st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
            i++;
        }
        else{
            while(st.top() != 'N' && prec(s[i])<=prec(st.top()))
            {
            	if(s[i]=='^' && st.top()=='^') break;
                char c = st.top();
                st.pop();
                post.push_back(cToString(c));
            }
            st.push(s[i]);
            i++;
        }

    }
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        post.push_back(cToString(c));
    }
}

typedef struct tree {
	string value;
	tree* left, *right;
} node;

bool isOperator(string c)
{
    if (c == "+" || c == "-" ||
            c == "*" || c == "/" ||
            c == "^")
        return true;
    return false;
}

node* newNode(string s)
{
	node* temp = new node;
	temp->left = temp->right = NULL;
	temp->value = s;
	return temp;
}

node* constructTree(vector<string> p)
{
	stack<node *> st;
	node *t, *r, *l;
	loop(i,0,p.size())
	{
		if(!isOperator(p[i])) {
			t = newNode(p[i]);
			st.push(t);
		}
		else {
			t = newNode(p[i]);
			r = st.top();
			st.pop();
			l = st.top();
			st.pop();
			t->right = r;
			t->left = l;
			st.push(t);
		}
	}
	t = st.top();
	st.pop();

	return t;
}

loo calculate(loo a, loo b, string s)
{
	if(s=="+") return a+b;
	if(s=="-") return a-b;
	if(s=="*") return a*b;
	if(s=="/") return a/b;
	if(s=="^") return (loo)pow(a,b);
}

loo solve(node* t) {
	if(t==NULL) return 0;
	else {
		if(!isOperator(t->value)) {
			string val = t->value;
			if(val[0]=='-') {
				string val1 = val.substr(1,val.size()-1);
				return ((loo)toInt(val1))*(-1);
			}
			else {
				return (loo)toInt(val);
			}
		} 
		loo a = solve(t->left);
		loo b = solve(t->right);
		return calculate(a,b,t->value);
	}
}

int main()
{
	loo q;
	cin >> q;
	loo n[q];
	vector<string> a[q];
	loop(i,0,q) {
		cin >> n[i];
		loop(j,0,n[i]) {
			string s;
			cin >> s;
			a[i].push_back(s);
		}
	}
	loop(i,0,q) {
		vector<char> var;
		vector<loo> var_val;
		loop(j,0,n[i]) {
			vector<string> p;
			if(isalpha(a[i][j][0])) {
				if(a[i][j].size()==1) {
					loo pos = find(var,a[i][j][0]);
					if(pos==-1) cout << "CANT BE EVALUATED" <<	endl;
					else cout << var_val[pos] << endl;
				}
				else if(a[i][j][1]=='=') {
					loo pos = find(var, a[i][j][0]);
					if(pos==-1) {
						var.push_back(a[i][j][0]);
						string li = a[i][j].substr(2,a[i][j].size()-1);
						toPostfix(li, var, var_val, p);
						node* exTree = constructTree(p);
						var_val.push_back(solve(exTree));
					}
					else {
						string li = a[i][j].substr(2,a[i][j].size()-1);
						toPostfix(li, var, var_val, p);
						node* exTree = constructTree(p);
						var_val[pos] = solve(exTree);
					}
					
				}
				else {
				toPostfix(a[i][j],var, var_val, p);
				node* exTree = constructTree(p);
				cout << solve(exTree) << endl;
				}
			}
			else {
				toPostfix(a[i][j],var, var_val, p);
				node* exTree = constructTree(p);
				cout << solve(exTree) << endl;
			}
		}
	}



	return 0;
}