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

struct Edge { 
    int src, dest; 
}; 

struct Graph { 
    loo V, E; 
    struct Edge* edge; 
};

struct subset { 
    loo parent; 
    loo rank; 
};

loo find(struct subset subsets[], loo i) { 
    if(subsets[i].parent != i) subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent; 
}

struct Graph* createGraph(loo V, loo E) { 
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) ); 
    graph->V = V; 
    graph->E = E; 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) ); 
    return graph; 
}

void Union(struct subset subsets[], loo x, loo y) { 
    loo xroot = find(subsets, x); 
    loo yroot = find(subsets, y);
    // make the higher rank subset as parent of the union set
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot;
    // incase of same ranks, take any one as parent while increasing its rank by 1
    else { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
}

loo isCycle(struct Graph* graph) { 
    loo V = graph->V; 
    loo E = graph->E;  
    struct subset *subsets = (struct subset*)malloc(V*sizeof(struct subset)); 
  
    loop(v,0,V) { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    } 
    loop(e,0,E) { 
        loo x = find(subsets, graph->edge[e].src); 
        loo y = find(subsets, graph->edge[e].dest); 
        if (x == y) return 1;
        Union(subsets, x, y); 
    } 
    return 0; 
} 


int main() {
	loo V,E;
    cin >> V >> E;
    struct Graph* g = createGraph(V,E);
    loop(i,0,E) {
        loo s,d;
        cin >> s >> d;
        g->edge[i].src = s;
        g->edge[i].dest = d;
    }
    if(isCycle(g)) cout << "yes, cycle." << endl;
    else cout << "no cycle." << endl;

	return 0;
}