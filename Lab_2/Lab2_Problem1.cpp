#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long int loo;

struct node_ {
	loo X;
	loo Y;
	struct node_* next;
};
typedef struct node_ node;
node* head = NULL;

void AddFirst(loo x, loo y) {
		node* newNode = (node*)malloc(sizeof(node));
		newNode->X = x;
		newNode->Y = y;
		newNode->next = head;
		head = newNode;
}

void DelFirst() {
	if(head==NULL) cout << -1 << endl;
	else {
		node* temp = head;
		head = head->next;
		temp->next=NULL;
		delete temp;
	}
}

void Del(loo x, loo y) {
	loo bin = 0;
	if(head==NULL) {
		bin=-1;
		cout << -1 << endl;
	}
	else {
		node* temp = head;
		if(temp->X==x && temp->Y==y) {
			bin = 1;
			DelFirst();
		}
		else {
			node * prev = head;
			temp = head->next;
			while(temp!=NULL) {
				if(temp->X==x && temp->Y==y) {
					bin = 1;
					prev->next=temp->next;
					temp->next=NULL;
					delete temp;
				}
				else {
					prev = temp;
					temp = temp->next;
				}
			}
		}
	}
	if(bin==0) cout << -1 << endl;
}

void search(float d)
{
	loo c = 0;
	loo bin = 0;
	if(head==NULL){
		bin = -1;
		cout << -1 << endl;
	}
	else {
		node* temp = head;
		while(temp!=NULL) {
			float dist = sqrt((temp->X*temp->X) + (temp->Y*temp->Y));
			if(dist<=d) {
				bin = 1;
				c++;
				temp = temp->next;
			}
			else temp=temp->next;
		}
	}
	if(bin==0) cout << -1 << endl;
	if(bin==1) cout << c << endl;
}

void search(loo x, loo y)
{
	loo bin = 0;
	if(head==NULL) {
		bin = -1;
		cout << "False";
	}
	else {
		node* temp = head;
		while(temp!=NULL) {
			if(temp->X==x && temp->Y==y) {
				bin = 1;
				cout << "True" << endl;
				break;
			}
			else temp=temp->next;
		}
	}
	if(bin==0) cout << "False" << endl;
}

loo length()
{
	loo count = 0;
	if(head==NULL) return 0;
	else {
		node* temp = head;
		while(temp!=NULL) {
			count++;
			temp = temp->next;
		}
	}
	return count;
}

int main()
{
	loo n; // no of queries
	cin >> n;
	loo funcs[n];
	loo coords[n][2];

	// taking query inputs
	for(loo i=0; i<n; i++) {
		cin >> funcs[i];
		if(funcs[i]==1 || funcs[i]==3 || funcs[i]==5) {
			loo x,y;
			cin >> x >> y;
			coords[i][0]=x;
			coords[i][1]=y;
		}
		else if(funcs[i]==4) {
			loo d;
			cin >> d;
			coords[i][0]=d;
		}
	}

	for(loo i=0; i<n; i++) {
		if(funcs[i]==1) AddFirst(coords[i][0], coords[i][1]);
		else if(funcs[i]==2) {
			DelFirst();
		}
		else if(funcs[i]==3) {
			Del(coords[i][0],coords[i][1]);
		}
		else if(funcs[i]==4) {
			search(coords[i][0]);
		}
		else if(funcs[i]==5) {
			search(coords[i][0],coords[i][1]);
		}
		else if(funcs[i]==6) {
			cout << length() << endl;
		}
	}

	return 0;
}