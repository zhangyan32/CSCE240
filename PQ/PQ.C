#include "PQ.h"
#include <cstddef>
#include <iostream>

using namespace std;
void PQ::Push(int n){
	if (!head){
		head = new Node(n);
		tail = head;
		return;
	}
	if (head == tail){
		tail = new Node(n);
		tail->prev = head;
		tail->parent = head;
		head->left = tail;
		shiftUp();
		return;
	}
	if (tail->parent->left == tail){
		tail->parent->right = new Node(n);
		Node * old_tail = tail;
		tail->parent->right->parent = tail->parent;
		tail = tail->parent->right;
		tail->prev = old_tail;
		shiftUp();
		return;
	}

	Node * p = tail;
	Node * old_tail = tail;

	while (p != head and p->parent->right == p){
		p = p->parent;
	}
	if (p == head){
		while(p->left) p = p->left; 
		p->left = new Node(n);
		p->left->parent = p;
		tail = p->left;
	}
	else{
		p = p->parent->right;
		while(p->left) p = p->left; 
		p->left = new Node(n);	
		p->left->parent = p;
		tail = p->left;	
	}
	tail->prev = old_tail;
	shiftUp();
	return;
}

void PQ::swap(Node* child, Node* parent){
	int temp = child->val; 
	child->val = parent->val;
	parent->val = temp; 
	return; 			
	
}

void PQ::shiftUp(){
	Node * p = tail;
	while(p->parent && p->val > p->parent->val){
		swap(p, p->parent);
		p = p->parent;
	} 
}

int PQ::Pop(){
	if (!head){
		return -1;
	}
	if (head == tail){
		int data = head->val;
		delete head; 
		head = NULL;
		tail = NULL;
		
		return data;
	}
	int data = head->val;
	head->val = tail->val;
	Node * temp = tail;
	tail = tail->prev;
	if (temp == temp->parent->left) temp->parent->left = NULL;
	else temp->parent->right = NULL;
	delete temp;
	shiftDown();
	return data;
}

void PQ::shiftDown(){
	Node * p = head;
	while(p != NULL){
		if (p->left != NULL && p->right != NULL){
			if (p->left->val <= p->val && p->right->val <= p->val) break;
			else if (p->left->val > p->val && p->left->val >= p->right->val){
				swap(p, p->left);
				p = p->left;	
			} 
			else if (p->right->val > p->val && p->right->val > p->left->val){
				swap(p, p->right);
				p = p->right;
			} 
			else{
			}		
		}
		else if (p->right == NULL && p->left != NULL && p->val < p->left->val){
			swap(p, p->left);
			p = p->left;
		}  
		else{
			break;
		}	
	} 
}
