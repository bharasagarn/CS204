#include<bits/stdc++.h>
using namespace std;
typedef long long int loo;

#define loop(i,begin,end) for(__typeof(end)i=(begin)-((begin)>(end));i!=(end)-((begin)>(end));i+=1-2*((begin)>(end)))
#define rep(r) for(auto i=1; i<=r; ++i)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define v(name,type,size) vector<type> name(size
#define vloo vector<loo>
#define p0(a) cout << #a << endl
#define mod(a) a%1000000007
#define pb(l) push_back(l)
#define ppb pop_back()
#define ff first
#define ss second
#define input(a) for(auto &i: a) cin >> i;
#define prnt(v) for(auto it: v) cout << it << " ";
#define mt make_tuple
#define mp make_pair
#define eb emplace_back
#define INF 1000000000
#define M 1000000007
#define MX 1000000

class Stack {
    loo top;

public:
    loo s[MX];
    Stack() { top=-1; }
    void push(loo x);
    loo pop(); 
    loo peek(); 
    bool isEmpty();
};

void Stack::push(loo x) { 
    if (top >= (MX-1)) { 
        cout << "Stack full!!!";  
    } 
    else { 
        top++;
        s[top] = x; 
    } 
} 
  
loo Stack::pop() { 
    if (top < 0) { 
        cout << "Stack empty!!! ";
        return 0;
    } 
    else { 
        loo x = s[top];
        top--;
        return x; 
    } 
} 
loo Stack::peek() { 
    if (top < 0) { 
        cout << "Stack empty!!! "; 
        return 0; 
    } 
    else { 
        loo x = s[top];
        return x; 
    } 
} 
  
bool Stack::isEmpty() { 
    return (top < 0); 
}


int main()
{
	class Stack st;
    // cout << "created" << endl;
    loop(i,0,20) st.push((i+1)*(2*i-1));
    // cout << "all pushed" << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;
    while(!st.isEmpty()) cout << st.pop() << endl;
    cout << st.pop() << endl;
    // cout << "not exited" << endl;

	return 0;
}