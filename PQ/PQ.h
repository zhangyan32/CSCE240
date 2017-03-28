#include <cstddef>
#include <iostream>

using namespace std;
class Node{
public:
	int val; 
	Node* left; 
	Node* right; 
	Node* parent; 
	Node* prev;
	Node(int n ){
		val = n; 
		left = NULL;
		right = NULL;
		parent = NULL;
		prev = NULL;
	}
};
class PQ {
public:
	Node * head; 
	Node * tail;
	void Push(int n);
	int Pop();
	void shiftUp();
	void shiftDown();
	void swap(Node*, Node* );
	PQ(){
		cout << "call PQ constructor" << endl;
		head = NULL;
		tail = NULL;
	}
	~PQ(){

		while(head){
			cout << "deleting" << head->val << endl;
			Pop();
		} 
	}
};
