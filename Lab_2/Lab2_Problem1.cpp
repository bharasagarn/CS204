#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct node_ {
	int X;
	int Y;
	struct node_* next;
};
typedef struct node_ node;

void AddFirst(node* head, int x, int y) {
		node* newNode = new node;
		newNode->X = x;
		newNode->Y = y;
		newNode-> next = head;
		head = newNode;
}

void DelFirst(node* head) {
	node* temp = head;
	head = head->next;
	temp->next=NULL;
	delete temp;
}

void Del(node* head, int x, int y) {
	node* temp = head;
	if(temp->X==x && temp->Y==y) {
		DelFirst(head);
	}
	else {
		node * prev = head;
		temp = head->next;
		while(true) {
			if(temp->X==x && temp->Y==y) {
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

int main()
{
	int n; // no of queries
	cin >> n;
	int funcs[n];
	vector<int> coords[n];

	// taking query inputs
	for(int i=0; i<n; i++) {
		cin >> funcs[i];
		if(funcs[i]==1 || funcs[i]==3 || funcs[i]==5) {
			int x,y;
			cin >> x >> y;
			coords[i].push_back(x);
			coords[i].push_back(y);
		}
		else if(funcs[i]==4) {
			int d;
			cin >> d;
			coords[i].push_back(d);
		}
	}

	node* head = NULL;
	for(int i=0; i<n; i++) {
		if(funcs[i]==1) AddFirst(head, coords[i][0], coords[i][1]);
	}

	cout << head->X << endl;

	return 0;
}
