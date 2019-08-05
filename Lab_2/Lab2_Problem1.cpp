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

loo DelFirst() {
	if(head==NULL) return -1;
	else {
		node* temp = head;
		head = head->next;
		temp->next=NULL;
		delete temp;
		return 0;
	}
}

loo Del(loo x, loo y) {
	if(head==NULL) return -1;
	else {
		node* temp = head;
		if(temp->X==x && temp->Y==y) {
			DelFirst();
			return 0;
		}
		else {
			node * prev = head;
			temp = head->next;
			while(temp!=NULL) {
				if(temp->X==x && temp->Y==y) {
					prev->next=temp->next;
					temp->next=NULL;
					delete temp;
					return 0;
				}
				else {
					prev = temp;
					temp = temp->next;
				}
			}
		}
	}
	return -1;
}

vector<int> points[2];
int search(float d)
{
	if(head==NULL) return -1;
	else {
		node* temp = head;
		while(temp!=NULL) {
			float dist = sqrt((temp->X*temp->X) + (temp->Y*temp->Y));
			if(dist<=d) {
				points[0].push_back(temp->X);
				points[1].push_back(temp->Y);
				temp = temp->next;
			}
			else temp=temp->next;
		}
	}
	if(points[0].size()==0) return -1;
}

loo search(loo x, loo y)
{
	if(head==NULL) return -1;
	else {
		node* temp = head;
		while(temp!=NULL) {
			if(temp->X==x && temp->Y==y) return 0;
			else temp=temp->next;
		}
		return -1;
	}
	return -1;
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
			int a = DelFirst();
			cout << a << endl;
		}
		else if(funcs[i]==3) {
			int a = Del(coords[i][0],coords[i][1]);
			cout << a << endl;
		}
		else if(funcs[i]==4) {
			int a = search(coords[i][0]);
			if(a==-1) cout << a << endl;
			else {
				while(!points[0].empty()) {
					cout << "(" << points[0].back() << "," << points[1].back() << ")" << " ";
					points[0].pop_back();
					points[1].pop_back();
				}
				cout << endl;
			}
		}
		else if(funcs[i]==5) {
			int a = search(coords[i][0],coords[i][1]);
			if(a==0) cout << "True" << endl;
			else cout << "False" << endl;
		}
		else if(funcs[i]==6) {
			cout << length() << endl;
		}
	}

	return 0;
}