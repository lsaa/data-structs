#include <stdio.h>
#include <iostream>
#include <iomanip>

template <class ty>
struct dlinode {
    ty value;
    dlinode<ty>* next;
    dlinode<ty>* prev;
};

template <class ty>
struct linode {
    ty value;
    linode<ty>* next;
};

template <class ty>
class btrnode {
public:
    btrnode();
    ty value;
    btrnode<ty>* father;
    btrnode<ty>* left;
    btrnode<ty>* right;

    bool isRight();
    bool isLeft();
    bool isLeaf();
    bool isHalf();
    btrnode<ty>* brother();
};

template <class ty>
btrnode<ty>::btrnode() {
    father = NULL;
    left = NULL;
    right = NULL;
}

template <class ty>
bool btrnode<ty>::isRight() {
    if (father != NULL) {
        if (father->right == this)
            return true;
    }
    return false;
}

template <class ty>
bool btrnode<ty>::isLeft() {
    if (father != NULL) {
        if (father->left == this)
            return true;
    }
    return false;
}

template <class ty>
btrnode<ty>* btrnode<ty>::brother() {
    if (father != NULL) {
        if (father->left == this)
            return father->right;
        return father->left;
    }
    return NULL;
}

template <class ty>
bool btrnode<ty>::isLeaf() {
    return (left == NULL && right == NULL);
}

template <class ty>
bool btrnode<ty>::isHalf() {
    return (left == NULL || right == NULL);
}
template <class ty>
class list {
    linode<ty>* start;
public:
    list();
    ty* operator[](int);
    ty* get(int);
    void setStart(linode<ty>*);
    linode<ty>* getStart();
    void insertAtStart(ty);
    ty* removeFromStart();
    bool isEmpty();
    void print();
	void inc(ty);
};

template <class ty>
list<ty>::list() {
    start = NULL;
}

template <class ty>
linode<ty>* list<ty>::getStart() {
    if (!isEmpty())
        return start;
    return NULL;
}

template <class ty>
void list<ty>::setStart(linode<ty>* v) {
    start = v;
}

template <class ty>
bool list<ty>::isEmpty() {
    return (start == NULL);
}

template <class ty>
void list<ty>::insertAtStart(ty v) {
    if (!isEmpty()) {
        linode<ty> *tmp = new linode<ty>;
        tmp->value = v;
        tmp->next = getStart();
        setStart(tmp);
    } else {
        linode<ty> *tmp = new linode<ty>;
        tmp->value = v;
        tmp->next = NULL;
        setStart(tmp);
    }
}

template <class ty>
ty* list<ty>::get(int i) {
    if (!isEmpty()) {
        linode<ty>* cNode = getStart();
        int j = 0;
        do {
            if (i == j)
                return &cNode->value;
            cNode = cNode->next;
            j++;
        } while (cNode != NULL);
        return NULL;
    } else {
        return NULL;
    }
}

template <class ty>
void list<ty>::print() {
    if (isEmpty()) {
        printf("[]");
    } else {
        printf("[");
        linode<ty>* cNode = getStart();
        while (cNode != NULL) {
            if (cNode->next == NULL) {
                std::cout << cNode->value;
            } else {
                std::cout << cNode->value << ", ";
            }
            
            cNode = cNode->next;
        }
        printf("]\n");
    }
}

template <class ty>
ty* list<ty>::operator[](int i) {
    return get(i);
}

template <class ty>
ty* list<ty>::removeFromStart() {
    if (isEmpty()) 
        return NULL;

    linode<ty>* old = getStart();
    setStart(getStart()->next);
    return &old->value;
}

template <class ty>
void list<ty>::inc(ty idx) {
	linode<ty>* cNode = getStart();
	int i = 0;
	while (i != idx) {
		cNode = cNode->next;
		i++;
	}
	cNode->value = cNode->value + 1;
}
template <class ty>
class dlist {
    dlinode<ty>* start;
public:
    dlist();
    ty operator[](int);
    ty get(int);
    void setStart(dlinode<ty>*);
    dlinode<ty>* getStart();
    void insertAtStart(ty);
    ty* removeFromStart();
    bool isEmpty();
    void print();
};

template <class ty>
dlist<ty>::dlist() {
    start = NULL;
}

template <class ty>
dlinode<ty>* dlist<ty>::getStart() {
    if (!isEmpty())
        return start;
    return NULL;
}

template <class ty>
void dlist<ty>::setStart(dlinode<ty>* v) {
    start = v;
}

template <class ty>
bool dlist<ty>::isEmpty() {
    return (start == NULL);
}

template <class ty>
void dlist<ty>::insertAtStart(ty v) {
    if (!isEmpty()) {
        dlinode<ty> *tmp = new dlinode<ty>;
        tmp->value = v;
        tmp->next = getStart();
        tmp->prev = NULL;
        setStart(tmp);
    } else {
        dlinode<ty> *tmp = new dlinode<ty>;
        tmp->value = v;
        tmp->next = NULL;
        tmp->prev = NULL;
        setStart(tmp);
    }
}

template <class ty>
ty dlist<ty>::get(int i) {
    if (!isEmpty()) {
        dlinode<ty>* cNode = getStart();
        int j = 0;
        do {
            if (i == j)
                return cNode->value;
            cNode = cNode->next;
            j++;
        } while (cNode != NULL);
        return -1;
    } else {
        return -1;
    }
}

template <class ty>
void dlist<ty>::print() {
    if (isEmpty()) {
        printf("[]");
    } else {
        printf("[");
        dlinode<ty>* cNode = getStart();
        while (cNode != NULL) {
            if (cNode->next == NULL) {
                std::cout << cNode->value;
            } else {
                std::cout << cNode->value << ", ";
            }
            
            cNode = cNode->next;
        }
        printf("]\n");
    }
}

template <class ty>
ty dlist<ty>::operator[](int i) {
    return get(i);
}

template <class ty>
ty* dlist<ty>::removeFromStart() {
    if (isEmpty()) 
        return NULL;

    dlinode<ty>* old = getStart();
    setStart(getStart()->next);
    getStart()->prev = NULL;
    return &old->value;
}

template <class ty>
class queue {
    dlinode<ty>* start;
    dlinode<ty>* end;
public:
    queue();
    void insertAtEnd(ty);
    ty* removeFromEnd();
    dlinode<ty>* getEnd();
    void setEnd(dlinode<ty>*);
    ty operator[](int);
    ty get(int);
    void setStart(dlinode<ty>*);
    dlinode<ty>* getStart();
    void insertAtStart(ty);
    ty* removeFromStart();
    bool isEmpty();
    void print();
};

template<class ty>
queue<ty>::queue() {
    start = NULL;
    end = NULL;
}

template <class ty>
dlinode<ty>* queue<ty>::getEnd() {
	return end;
}

template <class ty>
void queue<ty>::setEnd(dlinode<ty>* v) {
    end = v;
}

template <class ty>
void queue<ty>::insertAtEnd(ty v) {
    if (!isEmpty()) {
        dlinode<ty> *tmp = new dlinode<ty>;
        tmp->value = v;
        tmp->next = NULL;
        tmp->prev = getEnd();
        tmp->prev->next = tmp;
        setEnd(tmp);
    } else {
        dlinode<ty> *tmp = new dlinode<ty>;
        tmp->value = v;
        tmp->next = NULL;
        tmp->prev = NULL;
        setStart(tmp);
        setEnd(tmp);
    }
}

template <class ty>
ty* queue<ty>::removeFromEnd() {
    if (this->isEmpty()) 
        return NULL;

    dlinode<ty>* old = new dlinode<ty>(*getEnd());
    setEnd(getEnd()->prev);
	getEnd()->next = NULL;
    return &(old->value);
}

template <class ty>
dlinode<ty>* queue<ty>::getStart() {
    if (!isEmpty())
        return start;
    return NULL;
}

template <class ty>
void queue<ty>::setStart(dlinode<ty>* v) {
    start = v;
}

template <class ty>
bool queue<ty>::isEmpty() {
    return (start == NULL);
}

template <class ty>
void queue<ty>::insertAtStart(ty v) {
    if (!isEmpty()) {
        dlinode<ty> *tmp = new dlinode<ty>;
        tmp->value = v;
        tmp->next = getStart();
        tmp->prev = NULL;
        setStart(tmp);
    } else {
        dlinode<ty> *tmp = new dlinode<ty>;
        tmp->value = v;
        tmp->next = NULL;
        tmp->prev = NULL;
        setStart(tmp);
		setEnd(tmp);
    }
}

template <class ty>
ty queue<ty>::get(int i) {
    if (!isEmpty()) {
        dlinode<ty>* cNode = getStart();
        int j = 0;
        do {
            if (i == j)
                return cNode->value;
            cNode = cNode->next;
            j++;
        } while (cNode != NULL);
        return -1;
    } else {
        return -1;
    }
}

template <class ty>
void queue<ty>::print() {
    if (isEmpty()) {
        printf("[]");
    } else {
        printf("[");
        dlinode<ty>* cNode = getStart();
        while (cNode != NULL) {
            if (cNode->next == NULL) {
                std::cout << cNode->value;
            } else {
                std::cout << cNode->value << ", ";
            }
            
            cNode = cNode->next;
        }
        printf("]\n");
    }
}

template <class ty>
ty queue<ty>::operator[](int i) {
    return get(i);
}

template <class ty>
ty* queue<ty>::removeFromStart() {
    if (isEmpty()) 
        return NULL;

    dlinode<ty>* old = getStart();
    setStart(getStart()->next);
    getStart()->prev = NULL;
    return &old->value;
}


template <class ty>
class stack : public list<ty> {
public:
	void push(ty);
	ty* pop();
};

template <class ty>
void stack<ty>::push(ty v) {
	this->insertAtStart(v);
}

template <class ty>
ty* stack<ty>::pop() {
	return this->removeFromStart();
}
template <class ty>
class btree {
public:
    btree();
    btrnode<ty>* root;

    btrnode<ty>* search(ty);
    btrnode<ty>* search(btrnode<ty>*, ty);

    btrnode<ty>* minimum();
    btrnode<ty>* minimum(btrnode<ty>*);

    btrnode<ty>* maximum();
    btrnode<ty>* maximum(btrnode<ty>*);

    btrnode<ty>* successor();
    btrnode<ty>* successor(btrnode<ty>*);

    void insert(ty);
    void insert(btrnode<ty>*, ty);

    void remove(btrnode<ty>*);

    void inorder();
    void inorder(btrnode<ty>*);

    void preorder();
    void preorder(btrnode<ty>*);

    void postorder();
    void postorder(btrnode<ty>*);
	
	void printtr(btrnode<ty>*, int);
};

template <class ty>
btree<ty>::btree() {
    root = NULL;
}

template <class ty>
btrnode<ty>* btree<ty>::search(btrnode<ty>* current, ty a) {
    int steps = 0;
    while (current != NULL) {
        if (current->value == a) {
            return current;
        } else if (current->value > a)
            current = current->left;
        else
            current = current->right;
        steps++;
    }
    return NULL;
}

template <class ty>
btrnode<ty>* btree<ty>::minimum(btrnode<ty>* current) {
    while (current != NULL) {
        if (current->left == NULL) {
            return current;
        }
        current = current->left;
    }
    return current;
}

template <class ty>
btrnode<ty>* btree<ty>::maximum(btrnode<ty>* current) {
    while (current != NULL) {
        if (current->right == NULL) {
            return current;
        }
        current = current->right;
    }
    return current;
}

template <class ty>
btrnode<ty>* btree<ty>::search(ty a) {
    btrnode<ty>* current = root;
    int steps = 0;
    while (current != NULL) {
        if (current->value == a) {
            return current;
        } else if (current->value > a)
            current = current->left;
        else
            current = current->right;
        steps++;
    }
    return NULL;
}

template <class ty>
btrnode<ty>* btree<ty>::minimum() {
    btrnode<ty>* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            return current;
        }
        current = current->left;
    }
    return current;
}

template <class ty>
btrnode<ty>* btree<ty>::maximum() {
    btrnode<ty>* current = root;
    while (current != NULL) {
        if (current->right == NULL) {
            return current;
        }
        current = current->right;
    }
    return current;
}

template <class ty>
void btree<ty>::insert(ty a) {
	btrnode<ty>* x = root;
    btrnode<ty>* y = NULL;

    while (x != NULL) {
        y = x;
        if (a < x->value) 
            x = x->left;
        else
            x = x->right;
    }
    
    btrnode<ty>* novo = new btrnode<ty>();
    novo->father = y;
    novo->value = a;

    if (y == NULL) 
        root = novo;
    else if (a < y->value) 
        y->left = novo;
    else
		y->right = novo;
}

template <class ty>
void btree<ty>::insert(btrnode<ty>* x, ty a) {
    btrnode<ty>* y = NULL;

    while (x != NULL) {
        y = x;
        if (a < x->value) 
            x = x->left;
        else
            x = x->right;
    }
    
    btrnode<ty>* novo = new btrnode<ty>();
    novo->father = y;
    novo->value = a;

    if (y == NULL) 
        root = novo;
    else if (a < y->value) 
        y->left = novo;
    else
        y->right = novo;
}

template <class ty>
void btree<ty>::remove(btrnode<ty>* toDelete) {
    // Leaf Node
    if (toDelete->isLeaf()) {
        if (toDelete->father == NULL) {
            root = NULL;
            return;
        }

        if (toDelete->isRight())
            toDelete->father->right = NULL;
        else
            toDelete->father->left = NULL;
    // Single Child
    } else if (toDelete->isHalf()) {
        1;
    // Two Children 
    } else {
        1;
    }
}

template <class ty>
void btree<ty>::inorder(btrnode<ty>* x) {
    if (x != NULL) {
        inorder(x->left);
        printf("%d ", x->value);
        inorder(x->right);
    }
}

template <class ty>
void btree<ty>::inorder() {
    btrnode<ty>* x = root;
    if (x != NULL) {
        inorder(x->left);
        printf("%d ", x->value);
        inorder(x->right);
    }
}

template <class ty>
btrnode<ty>* btree<ty>::successor() {
    btrnode<ty>* x = root;
    
    if (x->right != NULL)
        return minimum(x->right);

    btrnode<ty>* y = x->father;

    while (y != NULL && x == y->right) {
        x = y;
        y = y->father;
    }

    return y;
}

template <class ty>
btrnode<ty>* btree<ty>::successor(btrnode<ty>* x) {
    if (x->right != NULL)
        return minimum(x->right);

    btrnode<ty>* y = x->father;

    while (y != NULL && x == y->right) {
        x = y;
        y = y->father;
    }

    return y;
}

template <class ty>
void btree<ty>::preorder(btrnode<ty>* x) {
    if (x != NULL) {
        printf("%d ", x->value);
        preorder(x->left);
        preorder(x->right);
    }
}

template <class ty>
void btree<ty>::preorder() {
    btrnode<ty>* x = root;
    if (x != NULL) {
        printf("%d ", x->value);
        preorder(x->left);
        preorder(x->right);
    }
}

template <class ty>
void btree<ty>::postorder(btrnode<ty>* x) {
    if (x != NULL) {
        postorder(x->left);
        postorder(x->right);
        printf("%d ", x->value);
    }
}

template <class ty>
void btree<ty>::postorder() {
    btrnode<ty>* x = root;
    if (x != NULL) {
        postorder(x->left);
        postorder(x->right);
        printf("%d ", x->value);
    }
}

template <class ty>
void btree<ty>::printtr(btrnode<ty>* p, int indent)
{
    if(p != NULL) {

        if(p->right) {
            printtr(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->value << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            printtr(p->left, indent+4);
        }
    }
}

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

    btree<int> arv;

    arv.insert(5);
    arv.insert(1);
    arv.insert(2);
    arv.insert(6);
    arv.insert(6);
	arv.printtr(arv.root, 0);
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
    btrnode<int>* sObj = arv.search(sVal);
    if (sObj != NULL) 
        printf("Found %d\n", sObj->value);
    else 
        printf("%d Not in tree\n", sVal);

    tof(arv.search(5) != NULL);
}


