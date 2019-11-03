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

void ShortestPaths(vloo G[], loo n, vloo d[]) {
    loop(i,0,n) {
        loop(j,0,n) {
            d[i].pb(G[i][j]);
            if(i==j) d[i][j]=0; // initialized ditance matrix
        }
    }
    loop(k,0,n) {
        loop(i,0,n) {
            loop(j,0,n) {
                if(d[i][k] < INF && d[k][j] < INF) // to avoid transitions using paths that don't exist
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

int main()
{
    cout << "Enter the number of vertices and number of edges (v e) : ";
    loo m,n;
    cin >> n >> m;
    cout << "Enter edges with the corresponding weights (v1 v2 w) : " << endl;
    vloo G[n];
    loop(i,0,n)
        loop(j,0,n)
            G[i].pb(INF);
    loop(i,0,m) {
        loo v1,v2,w;
        cin >> v1 >> v2 >> w;
        G[v1-1][v2-1] = w;
        G[v2-1][v1-1] = w;
    }
    vloo dist[n];
    ShortestPaths(G,n,dist);
    cout << "The shortest paths between every pair of vertices is shown in the matrix below : " << endl;
    loop(i,0,n) {
        loop(j,0,n) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}