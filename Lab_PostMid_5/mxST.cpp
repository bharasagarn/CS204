#include<bits/stdc++.h>
using namespace std;
typedef long long int loo;
typedef long double ld;

#define loop(i,begin,end) for(__typeof(end)i=(begin)-((begin)>(end));i!=(end)-((begin)>(end));i+=1-2*((begin)>(end)))
#define rep(r) for(auto i=1; i<=r; ++i)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define n(name,type,size) nector<type> name(size
#define nloo nector<loo>
#define p0(a) cout << #a << endl
#define mod(a) a%1000000007
#define pb(l) push_back(l)
#define ppb pop_back()
#define ff first
#define ss second
#define input(a) for(auto &i: a) cin >> i;
#define subsetnt(n) for(auto it: n) cout << it << " ";
#define mt make_tuple
#define mp make_pair
#define eb emplace_back
#define INF 1000000000
#define M 1000000007

class Edge {  
    public: 
    loo a, b;
    ld w;
}; 

class Graph {
	public:
	loo n,m;
	Edge* edge;
	};
	Graph* createGraph(loo n, loo m){
	Graph* graph = new Graph;
	graph->n = n;
	graph->m = m;
	graph->edge = new Edge[m];
	return graph;
}

class subset{
	public:
	loo parent;
	loo rank;
};

loo find(subset subs[], loo i){
	if (subs[i].parent != i) subs[i].parent = find(subs, subs[i].parent);
	return subs[i].parent;
}
void Union(subset subs[], loo x, loo y){
	loo xroot = find(subs, x);
	loo yroot = find(subs, y);
	if (subs[xroot].rank < subs[yroot].rank) subs[xroot].parent = yroot;
	else if (subs[xroot].rank > subs[yroot].rank) subs[yroot].parent = xroot;
	else{
		subs[yroot].parent = xroot;
		subs[xroot].rank++;
	}
}

int Comp(const void* a, const void* b){
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return a1->w > b1->w;
}

void MST(Graph* graph){
	loo n = graph->n;
	loo ans=1;
	loo e = 0;
	loo i = 0;
	qsort(graph->edge, graph->m, sizeof(graph->edge[0]), Comp);
	subset *subs = new subset[(n*sizeof(subset))];
	loop(i,0,n) {
		subs[i].parent = i;
		subs[i].rank = 0;
	}
	while (e < n-1 && i < graph->m){
		Edge next_edge = graph->edge[i++];
		loo x = find(subs, next_edge.a);
		loo y = find(subs, next_edge.b);
		if (x != y) {
			ans *= (-next_edge.w);
			ans %= M;
			Union(subs, x, y);
		}
	}
	cout<<ans;
	return;
}

int main(){
	loo n,m;
	cout << "Enter the number of vertices and number of edges : ";
	cin>>n>>m;
	Graph* graph = createGraph(n, m);
	loo j,k,l;
	cout << "Enter the edges (v1 v2 w) : " << endl;
	loop(i,0,m) {
		cin>>j>>k>>l;
		graph->edge[i].a = j;
		graph->edge[i].b = k;
		graph->edge[i].w = -(l);
	}
	cout << "The weight of required graph is "<< endl;
	MST(graph);
	cout << endl;
	return 0;
}