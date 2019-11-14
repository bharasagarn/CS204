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

struct Node { 
   int data;
   struct Node *next; 
};

struct Node* top = NULL; 

void push(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); 
   newnode->data = val; 
   newnode->next = top; 
   top = newnode; 
}

void pop() {
   if(top==NULL)
      cout<<"Stack Underflow"<<endl;
   else {
      cout<<"Popped : "<< top->data <<endl;
      struct Node * temp = top;
      top = top->next;
      delete(temp);
   }
}

void display() {
   struct Node* ptr;
   if(top==NULL)
      cout<<"Stack empty!";
   else {   
      ptr = top; 
      cout<<"Stack has : ";
      while (ptr != NULL) { 
         cout<< ptr->data <<" "; 
         ptr = ptr->next; 
      } 
   }
   cout<<endl;
}
int main() {
     display();
     push(9);
     push(90);
     push(4);push(2);push(3);push(2132);push(49);
     pop();
     display();
     pop();
     pop();pop();pop();pop();pop();display();

      return 0;
} 
