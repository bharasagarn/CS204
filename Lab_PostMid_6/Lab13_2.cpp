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

loo N = 1e7 + 19;
vector<vector<string>> hashTable(N,vector<string>(0));

loo hash_func(string s) {
    const loo p = 53;
    const loo m = 1e7 + 19;
    loo val = 0;
    loo p_raised = 1;
    for (char c : s) {
        val = (val + (c - 'A' + 1) * p_raised) % m;
        p_raised = (p_raised * p)%m;
    }
    return val;
}

void hash_insert(string key) {
    loo slot = hash_func(key);
    hashTable[slot].pb(key);
}

bool hash_search(string key){
    loo slot = hash_func(key);
    if(hashTable[slot].size()==0) return false;
    loop(i,0,hashTable[slot].size()) {
        if(hashTable[slot][i]==key){
            return true;
        }
    }
    return false;
}

int main() {
	loo n;
    cin >> n;
    vector<string> s;
    // cout << 1 << endl;
    loop(i,0,n) {
        string k;
        cin >> k;
        string r = k;
        reverse(r.begin(), r.end());
        if(r!=k) {
            hash_insert(k);
            s.pb(k);
        }
    }
    loop(i,0,s.size()) {
        string r = s[i];
        reverse(r.begin(), r.end());
        if(hash_search(r)) {
            cout << "YES" << endl;
            exit(0);
        }
    }
    cout << "NO" << endl;

	return 0;
}