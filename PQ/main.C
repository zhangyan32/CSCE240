#include <iostream>
#include "PQ.h"
using namespace std;
int main(){
	PQ pq; 
	PQ * pq2 = new PQ();
	for (int i = 1; i < 100; ++i, ++i) pq.Push(i);
	Node * p = pq.tail;
	while(p != pq.head){
		cout << p->val << endl;
		p = p->prev;
	}
	//for (int i = 0; i < 50; ++i, ++i) cout << pq.Pop() << ", ";
	for (int i = 0; i < 100; ++i, ++i) pq.Push(i * 2);
	//for (int i = 0; i < 50; ++i, ++i) cout << pq.Pop() << ", ";
	pq.Push(3);
	pq.Push(2);
	pq.Push(1);
	while(pq.head) cout<< "pop out" << pq.Pop() << endl;
	delete pq2;
}