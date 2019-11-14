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

struct node {
    loo data;
    struct node* right;
    struct node* left;
};

struct node* create(loo key) {
    struct node *nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data=key;
    nnode->right=NULL;
    nnode->left=NULL;
    return nnode;
}

void insert(struct node *root,int key) {
    queue<struct node*> q;
    q.push(root);
    while(!q.empty()) {
        struct node *temp=q.front();
        q.pop();
        if(!temp->left) {
            temp->left=create(key);
            break;
        }
        else q.push(temp->left);
        if(!temp->right) {
            temp->right=create(key);
            break;
        }
        else q.push(temp->right);
    }
}

void deleteDeepest(struct node* root,struct node* d_node) {
    queue<struct node*> q;
    q.push(root);
    struct node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else q.push(temp->right);
        }
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else q.push(temp->left);
        }
    }
}

struct node* deletek(struct node *root,int key) {
    if(root==NULL) {
     return root;
    }
    if(root->left==NULL && root->right==NULL) {
        if(root->data==key) return NULL;
        else return root;
    }
    queue<struct node*> q;
    q.push(root);
    struct node* temp;
    struct node* key_node = NULL;
    while(!q.empty()) {
        temp=q.front();
        q.pop();
        if(temp->data==key) key_node=temp;
        if(temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    if(key_node!=NULL) {
        loo x=temp->data;
        deleteDeepest(root,temp);
        key_node->data=x;
    }
    return root;
}
void inorder(struct node *temp) {
    if(temp==NULL)
        return;
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}


int main()
{
    struct node *root=create(1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    insert(root,6);
    insert(root,7);
    inorder(root);
    cout<<endl;
    deletek(root,1);
    inorder(root);


    return 0;
}
