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
#define Mod 1000000007

string extend(string s, loo n) {
    string t = s;
    while(t.size()<n) t.append(t);
    t = t.substr(0,n);
    return t;
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // give input in text file

    loo q;
    cin>>q;
    while(q--) {
        loo n, M=0;
        cin >> n;
        vector<pair<string,string>> a;
        loop(i,0,n) {
            string s;
            cin >> s;
            if(s.size()>M) M=s.size();
            a.pb(mp(s,s));
        }
        loop(i,0,n) a[i].ff = extend(a[i].ss,M);
        sort(a.begin(), a.end());
        loop(i,n,0) {
            if(i>0 && a[i].ff==a[i-1].ff) {
                if(a[i].ss[a[i].ss.size()-1]<a[i-1].ss[a[i-1].ss.size()-1]) {
                    string temp = a[i-1].ss;
                    a[i-1].ss = a[i].ss;
                    a[i].ss = temp;
                }
            }
            cout << a[i].ss;
        }
        cout << endl;
    }

	return 0;
}