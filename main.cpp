#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "nodes.h"

#include "linked_list.h"
#include "doubly_linked_list.h"
#include "queue.h"
#include "stack.h"
#include "binary_tree.h"

#define tof(X) printf(X ? "True\n" : "False\n")

int main(void) {
    queue<int> mylist;
    mylist.insertAtStart(10);
    mylist.insertAtEnd(1);
    mylist.insertAtEnd(100);
    mylist.insertAtStart(1);
    mylist.print();
    printf("%d\n", *mylist.removeFromEnd());
    mylist.print();

	stack<char> mystack;
	mystack.push('a');
	mystack.push('b');
	mystack.push('c');

	while (mystack.getStart() != NULL) 
		printf("%c\n", *mystack.pop());

	list<int> capacitytest;
	for (int i = 1; i < 11; i++) 
		capacitytest.insertAtStart(i);

	while (capacitytest.getStart() != NULL) 
		printf("%d\n", *capacitytest.removeFromStart());
		
    printf("\nTREE\n");

    BST<int> arv;

    arv.insert(5);
    arv.insert(1);
    arv.insert(2);
    arv.insert(6);
    arv.insert(6);

	arv.remove(arv.search(2));
	arv.remove(arv.search(6));

	BSTnode<int>* a = arv.pred_not_in_tree(6);
	if (a)
		printf("%d\n", a->value);
	else
		printf("0\n");
	printf("\n");


    if (arv.root != NULL) {
		arv.preorder();
        printf("\n");
        arv.inorder();
        printf("\n");
		arv.postorder();
        printf("\n");
        printf("MINIMUM: %d\n", arv.minimum()->value);
        printf("MAXIMUM: %d\n", arv.maximum()->value);
    }

    int sVal = 1601;
    BSTnode<int>* sObj = arv.search(sVal);
    if (sObj != NULL) 
        printf("Found %d\n", sObj->value);
    else 
        printf("%d Not in tree\n", sVal);

    tof(arv.search(5) != NULL);
}


