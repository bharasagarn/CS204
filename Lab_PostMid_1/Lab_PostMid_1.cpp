#include<bits/stdc++.h>
using namespace std;
typedef long long int loo;
typedef long double ld;

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

void swap(ld *a, ld *b) 
{ 
    ld temp = *a; 
    *a = *b; 
    *b = temp; 
} 

loo partition(ld arr[], loo l, loo r, ld x) 
{ 
    loo i;
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
    i = l; 
    loop(j,l,r) { 
        if (arr[j] <= x) { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
}

ld findMedian(ld arr[], loo n) 
{ 
    sort(arr, arr+n);
    return arr[n/2];
}

ld med_kth(ld arr[], loo l, loo r, loo k) 
{ 
    loo n = r-l+1; 
    loo i;
    ld median[(n+4)/5];
    for(i=0; i<n/5; i++)
        median[i] = findMedian(arr+l+i*5, 5); 
    if (i*5 < n)
    { 
        median[i] = findMedian(arr+l+i*5, n%5);  
        i++; 
    }     

    ld medOfMed = (i == 1)? median[i-1]: 
                             med_kth(median, 0, i-1, i/2); 
    loo pos = partition(arr, l, r, medOfMed); 

    if (pos-l == k-1) {
        if(n%2==0) return arr[pos];
        else return arr[pos+1];
    }
    if (pos-l > k-1)  return med_kth(arr, l, pos-1, k); 

    return med_kth(arr, pos+1, r, k-pos+l-1); 
} 

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    loo q;
    cin>>q;
    while(q--) {
        loo n;
        cin >> n;
        vloo a[2];
        loop(i,0,n) {
            loo x,y;
            cin >> x >> y;
            a[0].pb(x);
            a[1].pb(y);
        }
        ld dist[n];
        loop(i,0,n)
            dist[i] = sqrt(a[0][i]*a[0][i] + a[1][i]*a[1][i]);
        cout << med_kth(dist,0,n-1,n/2) << endl;
    }

	return 0;
}