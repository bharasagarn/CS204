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

loo binarySearch(vector<string> arr, string x) {
    loo n = arr.size();
    loo l = 0 ; 
    loo r = n-1; 
    while (l<=r) { 
        loo m = l + (r - l) / 2; 
        loo res; 
        if (x == (arr[m])) 
            res = 0;
            if (res == 0) 
                return m; 
            if (x > (arr[m])) 
                l = m+1;
            else
                r = m-1; 
    }
    return -1; 
}

int main() {
	loo n;
    cin >> n;
    vector<string> s;
    loop(i,0,n) {
        string t;
        cin >> t;
        string r = t;
        reverse(r.begin(), r.end());
        if(t!=r) {
            s.pb(t);
        }
    }
    sort(s.begin(), s.end());
    loop(i,0,s.size()) {
        string r = s[i];
        reverse(r.begin(), r.end());
        if(binarySearch(s, r)!=-1) {
            cout << "YES" << endl;
            exit(0);
        }
    }
    cout << "NO" << endl;

	return 0;
}