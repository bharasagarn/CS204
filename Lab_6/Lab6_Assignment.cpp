#include<bits/stdc++.h>
using namespace std;
typedef long long int loo;

#define loop(i,begin,end) for(__typeof(end)i=(begin)-((begin)>(end));i!=(end)-((begin)>(end));i+=1-2*((begin)>(end)))
#define rep(r) for(auto i=1; i<=r; ++i)
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

loo maxpos(vector<loo> a) {
    loo mx = a[0], pos=0;
    loop(i,1,a.size()) {
        if(a[i]>mx) {
            mx = a[i];
            pos = i;
        }
    }
    return pos;
}

loo find(vector<loo> a, loo id) {
    loop(i,0,a.size()) {
        if(a[i]==id) return i;
    }
    return -1;
}

int main()
{
	loo users=0;
    vector<loo> usrs, rechrg, outpt;
    loo n,q;
    cin >> n;
    cin >> q;
    while(q--) {
        loo op;
        cin >> op;
        if(op==1) {
            loo id, rech;
            cin >> id >> rech;
            loo pos = find(usrs, id);
            if(pos!=-1) {
                rechrg[pos]+=rech;
            }
            else {
                usrs.pb(id);
                rechrg.pb(rech);
            }
        }
        else if(op==2) {
            if(usrs.size()==0) outpt.pb(-1);
            else {
                loo pos = maxpos(rechrg);
                outpt.pb(usrs[pos]);
            }
        }
    }
    loop(i,0,outpt.size()) {
        if(outpt[i]==-1) cout << "No data available." << endl;
        else cout << outpt[i] << endl;
    }

	return 0;
}