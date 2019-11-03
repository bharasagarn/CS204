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

class Graph { 
    loo n;
    vloo *adj;
public: 
    Graph(loo n);
    void addEdge(loo v, loo w);
    void DFS1(loo s, bool visited[]);
    void DFS2(loo v);
    void printList(); 
}; 
  
Graph::Graph(loo n) {  // constructor of graph
    this->n = n; 
    adj = new vloo[n]; 
} 
  
void Graph::addEdge(loo v, loo w) { 
    adj[v-1].pb(w-1);
    adj[w-1].pb(v-1);
}

void Graph::printList() {
    loop(i,0,n) {
        cout << i << " : ";
        loop(j,0,adj[i].size()) cout << adj[i][j] << " ";
        cout << endl;
    }
}

void Graph::DFS1(loo v, bool visited[]) {
    visited[v] = true;
    cout << v+1 << " ";
    loop(i,0,adj[v].size()) {
        if(!visited[adj[v][i]]) DFS1(adj[v][i], visited);
    }
}
  
void Graph::DFS2(loo s) {
    bool *visited = new bool[n];
    loop(i,0,n) visited[i] = false; 
    DFS1(s-1,visited);
}

int main()
{
	loo n,m,s;
    cout << "Enter number of vertices and number of edges : ";
    cin >> n >> m;
    cout << "Enter the edges : " << endl;
    Graph g(n);
    loop(i,0,m) {
        loo x,y;
        cin >> x >> y;
        g.addEdge(x,y);
    }
    // g.printList();
    cout << "Enter the source vertex to start DFS : ";
    cin >> s;
    cout << "Following is the DFS " << "starting from vertex " << s << " : " << endl;
    g.DFS2(s);
    cout << endl;

	return 0;
}