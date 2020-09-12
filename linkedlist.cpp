#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int d){
		data = d;
		next = NULL;
	}
};

void insertAthead(Node* &head, int data){
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}
void print(Node* head){
	while(head != NULL){
		cout << head->data <<"->";
		head = head->next;
	}
	cout << endl;
}

void insertInMiddle(Node* &head, int d, int p){
	int i = 1;
	Node* temp = head;
	while(i < p){
		temp = temp->next;
		i++;
	}

	Node* t = new Node(d);
	t->next = temp->next;
	temp->next = t;

}
void insertAtTail(Node* &head, int d){
	if(head == NULL)
	{
		head = new Node(d);
		return;
	}
	Node* tail = head;
	while(tail-> next != NULL)
		tail = tail->next;
	tail->next = new Node(d);
}

void reverselist(Node* &prev, Node * &cur){
	if(prev == NULL || cur == NULL)
		return;
	reverselist(cur, cur->next);
	cur->next = prev;
	return;
}

Node* take_input(){
	int d;	cin >> d;
	Node* head;
	do
		insertAthead(head, d);
		while(cin >> d);
	return head;
}

ostream& operator<<(ostream &os, Node* head){
	print(head);
	return os;
}
istream& operator >> (istream &is, Node* &head){
	head = take_input();
	return is;
}

Node* midpoint(Node* head){
	if(head == NULL || head->next == NULL)
		return head;
	Node* slow = head;
	Node* fast = head->next;


	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Node* head = take_input();
	
	Node* mid = midpoint(head);
	cout << mid->data;
	

	/*
	Node* head = NULL;
	insertAthead(head, 4);
	insertAthead(head, 2);
	insertAthead(head, 1);
	insertAthead(head, 0);
	print(head);
	insertInMiddle(head, 3, 3);
	print(head);
	insertAtTail(head, 5);
	print(head);

	Node* tail = head;
	while(tail->next != NULL)
		tail = tail->next;
	reverselist(head, head->next);

	head->next = NULL;
	
	
	print(tail);
	*/
	
	return 0;
}
