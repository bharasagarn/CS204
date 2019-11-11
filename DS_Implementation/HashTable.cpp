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

const loo N = 1000;
vector<vloo> hashTable(N, vloo(0));

loo hash_func(loo key) {
    return key%N;
}

void hash_insert(loo key) {
    loo slot = hash_func(key);
    hashTable[slot].pb(key);
}

void hash_search(loo key) {
    loo slot = hash_func(key);
    if(hashTable[slot].size()==0) cout << "Key not found." << endl;
    else {
        bool f = false;
        loop(i,0,hashTable[slot].size()) {
            if(hashTable[slot][i]==key) {
                f = true;
                cout << "Key found in hashtable in slot " << slot << " at position " << i << "." << endl;
                break;
            }
        } 
        if(!f) cout << "Key not found." << endl;   
    }
}

void hash_delete(loo key) {
    loo slot = hash_func(key);
    if(hashTable[slot].size()==0) cout << "Key not present in table." << endl;
    else {
        bool f = false;
        loop(i,0,hashTable[slot].size()) {
            if(hashTable[slot][i]==key) {
                f = true;
                hashTable[slot].erase(hashTable[slot].begin()+i);
                cout << "Key successfully deleted from table." << endl;
                break;
            }
        } 
        if(!f) cout << "Key not present in table." << endl;
    }
}

int main() {
	cout << "Enter the number of elements to insert : ";
    loo n;
    cin >> n;
    cout << "Enter the elements to be inserted : ";
    loop(i,0,n) {
        loo t;
        cin >> t;
        hash_insert(t);
    }
    string s = "a";
    while(s!="end") {
        cout << "Enter operation to perform (search key, insert key, delete key, end) : ";
        cin >> s;
        if(s=="search") {
            loo k;
            cin >> k;
            hash_search(k);
        }
        else if(s=="insert") {
            loo k;
            cin >> k;
            hash_insert(k);
        }
        else if(s=="delete") {
            loo k;
            cin >> k;
            hash_delete(k);
        }
        else if(s=="end") {
            cout << "Programs ends here." << endl;
            break;
        }
        else cout << "Invalid operation!!" << endl;
    }

	return 0;
}