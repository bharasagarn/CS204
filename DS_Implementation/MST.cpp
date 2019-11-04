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

class Edge {  
    public: 
    loo s, d, w;
};  
 
class Graph {  
    public: 
    loo n, m; 
    Edge* edge;  
};  
 
Graph* createGraph(loo n, loo m) {  
    Graph* g = new Graph;  
    g->n = n;  
    g->m = m;  
    g->edge = new Edge[m];  
    return g;  
}  

class subset {  
    public: 
    loo parent;  
    loo rank;  
};  
 
loo find(subset subsets[], loo i) {
    if (subsets[i].parent != i) subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;  
}  
 
void Union(subset subsets[], loo x, loo y) {  
    loo xroot = find(subsets, x);  
    loo yroot = find(subsets, y);  
    if (subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;  
    else if (subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;   
    else {  
        subsets[yroot].parent = xroot;  
        subsets[xroot].rank++;  
    }  
}  
 
int Comp(const void* a, const void* b) {  
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->w > b1->w;  
}  

void MST(Graph* graph) {  
    loo n = graph->n;  
    Edge result[n];
    loo e = 0;
    loo i = 0;
    qsort(graph->edge, graph->m, sizeof(graph->edge[0]), Comp);   
    subset *subsets = new subset[(n*sizeof(subset))];  
    loop(v,0,n) {  
        subsets[v].parent = v;  
        subsets[v].rank = 0;  
    }   
    while (e < n-1 && i < graph->m) {
        Edge next_edge = graph->edge[i++];  
  
        loo x = find(subsets, next_edge.s);  
        loo y = find(subsets, next_edge.d);  
        if (x != y) {  
            result[e++] = next_edge;  
            Union(subsets, x, y);  
        }
    }
    cout << "Following are the edges in the constructed MST\n";  
    loop(i,0,e) cout << result[i].s + 1 << "--" << result[i].d + 1 << " == " << result[i].w << endl;  
    return;  
}  

int main()  
{ 
    cout << "Enter the number of vertices and number of edges : ";
    loo n,m;
    cin >> n >> m;
    Graph* graph = createGraph(n, m);  
    cout << "Enter the edges (v1 v2 w) : " << endl;
    loop(i,0,m) {
        loo v1,v2,wt;
        cin >> v1 >> v2 >> wt;
        graph->edge[i].s = v1-1;
        graph->edge[i].d = v2-1;
        graph->edge[i].w = wt;
    }
    MST(graph);  
  
    return 0;  
}