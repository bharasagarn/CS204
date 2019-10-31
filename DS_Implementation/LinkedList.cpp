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

class Node  
{  
    public: 
    loo data;  
    Node *next;  
};  

void pushFront(Node** head_ref, loo new_data)  
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;  
}  

void insertAfter(Node* prev_node, loo new_data) {
    if (prev_node == NULL)  {  
        cout<<"Given prev_node is NULL!!";  
        return;  
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;  
}  

void append(Node** head_ref, loo new_data)  
{
    Node* new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)  {  
        *head_ref = new_node;  
        return;  
    }
    while (last->next != NULL) last = last->next;  
    last->next = new_node;  
    return;  
}  

void printList(Node *node)  {  
    while (node != NULL) {  
        cout << node->data << " ";  
        node = node->next;  
    }
    cout << endl;
}

void deleteNode(struct Node **head_ref, loo key) {
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) { 
        *head_ref = temp->next;
        free(temp);
        return; 
    }
    while (temp != NULL && temp->data != key) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) {
        cout << "Key not found!!" << endl;
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteNodeAt(struct Node **head_ref, loo position) {
    if (*head_ref == NULL) {
        cout << "List empty!!" << endl;
        return;
    }
   struct Node* temp = *head_ref;
    if (position == 0) { 
        *head_ref = temp->next;
        free(temp);
        return; 
    }
    for (loo i=0; temp!=NULL && i<position-1; i++) temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        cout << "Position overflow!!" << endl;
        return;
    }
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main()
{
	Node* head = NULL;
    loop(i,0,9) append(&head, i+1);
    pushFront(&head, 11);
    insertAfter(head->next->next, 22);
    printList(head);
    deleteNode(&head, 22);
    deleteNode(&head, 13);
    printList(head);
    deleteNodeAt(&head, 4);
    printList(head);

	return 0;
}