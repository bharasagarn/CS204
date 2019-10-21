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

loo bfs(vector<vloo> g, vector<vector<bool>>& visited, loo x, loo y, loo c,  loo m, loo n){

    loo res=1;
    visited[x][y]=1;

    if(x<m-1 && !visited[x+1][y] && g[x+1][y]==c) res+=bfs(g,visited,x+1,y,c,m,n);
    if(y<n-1 && !visited[x][y+1] && g[x][y+1]==c) res+=bfs(g,visited,x,y+1,c,m,n);
    if(x>0 && !visited[x-1][y] && g[x-1][y]==c) res+=bfs(g,visited,x-1,y,c,m,n);
    if(y>0 && !visited[x][y-1] && g[x][y-1]==c) res+=bfs(g,visited,x,y-1,c,m,n);
    return res;
}

loo findlargestComponent(vector<vloo> g, vector<vector<bool>>& visited, loo m, loo n){
    loo t=0;
    loo mx=0;

    loop(i,0,m) {
        loop(j,0,n) {
            if(!visited[i][j] && g[i][j]==1) {
                t=bfs(g,visited,i,j,g[i][j],m,n);
                if(t>mx) mx=t;
            }
        }
    }
    return mx;
}

int main(){
    loo m,n,k;
    cin >> m >> n >> k;
    vector<vloo> g;
    vector<vector<bool>> visited;
    g.resize(m, vloo(n,0));
    visited.resize(m, vector<bool>(n,false));

    loop(i,0,k) {
        loo x,y;
        cin >> x >> y;
        g[x][y]=1;
    }

    // loop(i,0,m)
    //  loop(j,0,n)
    //      cin >> g[i][j];

    cout << findlargestComponent(g,visited,m,n) << endl;

    return 0;
}

