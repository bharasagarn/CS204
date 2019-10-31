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

bool checkBipartite(vector<vloo>& adj, loo source, vloo& color, set<loo>& d, loo n) {
    // cout << color[0] << endl;
    color[source-1]=1;
    d.erase(source);
    queue<loo> q;
    q.push(source);
    while(!(q.empty())) {
        loo a = q.front();
        q.pop();
        // cout << a << " <-- a " << endl;
        loop(i,0,adj[a-1].size()) {
            if(color[adj[a-1][i]-1]==-1) {
                color[adj[a-1][i]-1] = 1 - color[a-1]; // if source=0 then adjacent=1 and vice-versa
                d.erase(adj[a-1][i]);
                q.push(adj[a-1][i]);
                // cout << "coloured " << adj[a-1][i] << " with color " << 1-color[a-1] << endl;
            }
            else if(color[adj[a-1][i]-1]==color[a-1]) return false;
        }
    }
    // cout << "size of d " << d.size() << endl;
    // cout << "d front : " << *d.begin() << endl; 
    return true;
}

int main()
{
	loo n,m;
    cin >> n >> m;
    vector<vloo> adj(2*n);
    loo c = 0; // count of pseudo nodes created
    loo pseudo = n+1;
    loop(i,0,m) {
        loo a,b,w;
        cin >> a >> b >> w;
        if(w%2==0) {
            adj[a-1].pb(pseudo);
            adj[pseudo-1].pb(a);
            adj[b-1].pb(pseudo);
            adj[pseudo-1].pb(b);
            c++;
            pseudo++;
        }
        else {
            adj[a-1].pb(b);
            adj[b-1].pb(a);
        }
    }
    // }
    bool f = true;
    set<loo> d;
    loop(i,0,n+c) d.insert(i+1);
    // cout << "input done" << endl;
    vloo color(n+c,-1); // will be either 0 or 1
    while(f && d.size()!=0) f=checkBipartite(adj,*d.begin(),color,d,n+c);
    // if(checkBipartite(adj)) cout << "YES" << endl;
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;

	return 0;
}