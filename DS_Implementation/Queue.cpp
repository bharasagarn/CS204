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

class Queue  {  
public:
    loo front, rear, size;  
    loo max_size;  
    loo* arr;
};  

Queue* create(loo max_size) {  
    Queue* queue = new Queue(); 
    queue->max_size = max_size;  
    queue->front = queue->size = 0;  
    queue->rear = max_size - 1; 
    queue->arr = new loo[(queue->max_size * sizeof(loo))]; 
    return queue;  
}  
    
bool isFull(Queue* queue) { return (queue->size == queue->max_size); }  
   
bool isEmpty(Queue* queue) { return (queue->size == 0); }  
 
void enqueue(Queue* queue, loo item) { 
    if (isFull(queue)) {
        cout << "Queue full!!" << endl;
        return;
    }  
    queue->rear = (queue->rear + 1)%queue->max_size;  
    queue->arr[queue->rear] = item;  
    queue->size = queue->size + 1;  
}  
 
loo dequeue(Queue* queue)  {  
    if (isEmpty(queue)) {
        cout << "Queue empty!!" << endl;
        return 0;
    }  
    loo item = queue->arr[queue->front];  
    queue->front = (queue->front + 1)%queue->max_size;  
    queue->size = queue->size - 1;  
    return item;  
}  
 
loo front(Queue* queue)  
{  
    if (isEmpty(queue)) {
        cout << "Queue empty!!" << endl;
        return 0;
    } 
    return queue->arr[queue->front];  
}  
  
loo rear(Queue* queue)  
{  
    if (isEmpty(queue)) {
        cout << "Queue empty!!";
        return 0;
    }  
    return queue->arr[queue->rear];  
}

int main()
{
	Queue* q = create(10000000);
    loop(i,0,12) enqueue(q,2*i - 1);
    if(!isFull(q)) cout << "Not full" << endl;
    while(!isEmpty(q)) cout << dequeue(q) << endl;
    cout << rear(q) << endl;

	return 0;
}