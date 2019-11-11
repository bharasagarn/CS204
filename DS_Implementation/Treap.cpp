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

typedef struct node {
    loo key,pr;
    struct node *right,*left;
} treapnode;

treapnode* createnode(loo key) {
    treapnode* t = new treapnode;
    t->key = key;
    t->pr = rand()%100;
    t->left = NULL;
    t->right = NULL;
    return t;
}

treapnode* LRotate(treapnode* x) {
    treapnode* y = x->right;
    treapnode* z = y->left;
    y->left = x;
    x->right = z;
    return y;
}

treapnode* RRotate(treapnode* y) {
    treapnode* x = y->left;
    treapnode* z = x->right;
    x->right = y;
    y->left = z;
    return x;
}

treapnode* insertKey(treapnode* root, loo key) {
    if(root==NULL) return createnode(key);
    if(root->key > key) {
        root->left = insertKey(root->left,key);
        if(root->left->pr > root->pr) root = RRotate(root); // HOT property maintenance
    }
    else {
        root->right=insertKey(root->right,key);
        if(root->right->pr > root->pr) root = LRotate(root); // HOT property maintenance
    }
    return root;
}

treapnode* deleteKey(treapnode* root, loo key) {
    if(root==NULL) return root;
    if(root->key > key) root->left = deleteKey(root->left,key);
    else if(root->key < key) root->right = deleteKey(root->right,key);

    // reached a node having only one child
    else if(root->left==NULL) {
        treapnode* temp = root->right;
        delete(root);
        root = temp;
    }
    else if(root->right==NULL) {
        treapnode* temp = root->left;
        delete(root);
        root = temp;
    }

    // at internal node rotate to bring higher pr node 
    // upwards and move key node toward a leaf node
    else if(root->right->pr > root->left->pr) {
        root = LRotate(root);                  
        root->left = deleteKey(root->left,key);
    }
    else {
        root = RRotate(root);
        root->right = deleteKey(root->right,key);
    }
    return root;
}

treapnode* searchKey(treapnode* root, loo key) {
    if(root==NULL || root->key==key) return root;
    else if(root->key > key) return searchKey(root->left,key);
    else return searchKey(root->right,key);
}

void inorderTrav(treapnode* root) {
    if(root) {
        inorderTrav(root->left);
        cout << "key : " << root->key << " having priority : " << root->pr;
        cout << " || Left child : ";
        if(root->left) cout << root->left->key;
        else cout << "NULL";
        cout << " | Right child : ";
        if(root->right) cout << root->right->key;
        else cout << "NULL";
        cout << endl;
        inorderTrav(root->right);
    }
}

int main()
{
	treapnode* treaproot = NULL;
    loo n;
    cout << "Enter number of keys to be inserted : ";
    cin >> n;
    cout << "Enter the keys to be inserted : ";
    loop(i,0,n) {
        loo x;
        cin >> x;
        treaproot = insertKey(treaproot,x);
    }
    string s = "a";
    while(s!="end") {
        cout << "Enter the operation to be performed on the treap (search,delete,inordertraverse,insert) : " << endl;
        cin >> s;
        if(s=="search") {
            loo k;
            cin >> k;
            if(searchKey(treaproot,k)) cout << "Key " << k << " found." << endl;
            else cout << "Key not found." << endl;
        }
        else if(s=="delete") {
            loo k;
            cin >> k;
            treaproot = deleteKey(treaproot,k);
            cout << "Key deleted from treap." << endl;
        }
        else if(s=="inordertraverse") {
            inorderTrav(treaproot);
        }
        else if(s=="insert") {
            loo k;
            cin >> k;
            treaproot = insertKey(treaproot,k);
            cout << "New key inserted successfully." << endl;
        }
        else cout << "Invalid operation!!" << endl;
    }

	return 0;
}