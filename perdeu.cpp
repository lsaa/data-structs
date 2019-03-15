#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

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
class BSTnode {
public:
    BSTnode();
	~BSTnode();
    ty value;
    BSTnode<ty>* father;
    BSTnode<ty>* left;
    BSTnode<ty>* right;

    bool isRight();
    bool isLeft();
    bool isLeaf();
    bool isHalf();
	BSTnode<ty>* getOnlyChild();
    BSTnode<ty>* brother();
};

template <class ty>
BSTnode<ty>::~BSTnode() {
	free(this);
}

template <class ty>
BSTnode<ty>::BSTnode() {
    father = NULL;
    left = NULL;
    right = NULL;
}

template <class ty>
bool BSTnode<ty>::isRight() {
    if (father != NULL) {
        if (father->right == this)
            return true;
    }
    return false;
}

template <class ty>
bool BSTnode<ty>::isLeft() {
    if (father != NULL) {
        if (father->left == this)
            return true;
    }
    return false;
}

template <class ty>
BSTnode<ty>* BSTnode<ty>::brother() {
    if (father != NULL) {
        if (father->left == this)
            return father->right;
        return father->left;
    }
    return NULL;
}

template <class ty>
bool BSTnode<ty>::isLeaf() {
    return (left == NULL && right == NULL);
}

template <class ty>
bool BSTnode<ty>::isHalf() {
    return (left == NULL || right == NULL);
}

template <class ty>
BSTnode<ty>* BSTnode<ty>::getOnlyChild() {
	if (left)
		return left;
	else
		return right;
}
template <class ty>
class BST {
public:
    BST();
    BSTnode<ty>* root;

    BSTnode<ty>* search(ty);
    BSTnode<ty>* search(BSTnode<ty>*, ty);

    BSTnode<ty>* minimum();
    BSTnode<ty>* minimum(BSTnode<ty>*);

    BSTnode<ty>* maximum();
    BSTnode<ty>* maximum(BSTnode<ty>*);

    BSTnode<ty>* successor();
    BSTnode<ty>* successor(BSTnode<ty>*);

    BSTnode<ty>* predecessor();
    BSTnode<ty>* predecessor(BSTnode<ty>*);

    void insert(ty);
    void insert(BSTnode<ty>*, ty);

    void remove(BSTnode<ty>*);

    void inorder();
    void inorder(BSTnode<ty>*);

    void preorder();
    void preorder(BSTnode<ty>*);

    void postorder();
    void postorder(BSTnode<ty>*);

	ty minAt(ty);

	BSTnode<ty>* pred_not_in_tree(ty);
	void pred_not_in_tree(BSTnode<ty>*, ty);
};

template <class ty>
BST<ty>::BST() {
    root = NULL;
}

template <class ty>
BSTnode<ty>* BST<ty>::search(BSTnode<ty>* current, ty a) {
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
BSTnode<ty>* BST<ty>::minimum(BSTnode<ty>* current) {
    while (current != NULL) {
        if (current->left == NULL) {
            return current;
        }
        current = current->left;
    }
    return current;
}

template <class ty>
BSTnode<ty>* BST<ty>::maximum(BSTnode<ty>* current) {
    while (current != NULL) {
        if (current->right == NULL) {
            return current;
        }
        current = current->right;
    }
    return current;
}

template <class ty>
BSTnode<ty>* BST<ty>::search(ty a) {
    BSTnode<ty>* current = root;
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
BSTnode<ty>* BST<ty>::minimum() {
    BSTnode<ty>* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            return current;
        }
        current = current->left;
    }
    return current;
}

template <class ty>
BSTnode<ty>* BST<ty>::maximum() {
    BSTnode<ty>* current = root;
    while (current != NULL) {
        if (current->right == NULL) {
            return current;
        }
        current = current->right;
    }
    return current;
}

template <class ty>
void BST<ty>::insert(ty a) {
	BSTnode<ty>* x = root;
    BSTnode<ty>* y = NULL;

    while (x != NULL) {
        y = x;
        if (a <= x->value)
            x = x->left;
        else
            x = x->right;
    }

    BSTnode<ty>* novo = new BSTnode<ty>();
    novo->father = y;
    novo->value = a;

    if (y == NULL)
        root = novo;
    else if (a <= y->value)
        y->left = novo;
    else
		y->right = novo;
}

template <class ty>
void BST<ty>::insert(BSTnode<ty>* x, ty a) {
    BSTnode<ty>* y = NULL;

    while (x != NULL) {
        y = x;
        if (a <= x->value)
            x = x->left;
        else
            x = x->right;
    }

    BSTnode<ty>* novo = new BSTnode<ty>();
    novo->father = y;
    novo->value = a;

    if (y == NULL)
        root = novo;
    else if (a <= y->value)
        y->left = novo;
    else
        y->right = novo;
}


template <class ty>
void BST<ty>::remove(BSTnode<ty>* toDelete) {
    if (toDelete == NULL)
        return;

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
        if (toDelete->father == NULL) {
            root = toDelete->getOnlyChild();
            root->father = NULL;
            return;
        }

        if (toDelete->isRight()) {
            toDelete->father->right = toDelete->getOnlyChild();
        } else {
            toDelete->father->left = toDelete->getOnlyChild();
        }

    // Two Children
    } else {
        BSTnode<ty>* suc = successor(toDelete);
        toDelete->value = suc->value;
        remove(suc);
    }
}

template <class ty>
void BST<ty>::inorder(BSTnode<ty>* x) {
    if (x != NULL) {
        inorder(x->left);
        printf("%d ", x->value);
        inorder(x->right);
    }
}

template <class ty>
void BST<ty>::inorder() {
    BSTnode<ty>* x = root;
    if (x != NULL) {
        inorder(x->left);
        printf("%d ", x->value);
        inorder(x->right);
    }
}

template <class ty>
BSTnode<ty>* BST<ty>::successor() {
    BSTnode<ty>* x = root;

    if (x->right != NULL)
        return minimum(x->right);

    BSTnode<ty>* y = x->father;

    while (y != NULL && x == y->right) {
        x = y;
        y = y->father;
    }

    return y;
}

template <class ty>
BSTnode<ty>* BST<ty>::successor(BSTnode<ty>* x) {
    if (x->right != NULL)
        return minimum(x->right);

    BSTnode<ty>* y = x->father;

    while (y != NULL && x == y->right) {
        x = y;
        y = y->father;
    }

    return y;
}

template <class ty>
void BST<ty>::preorder(BSTnode<ty>* x) {
    if (x != NULL) {
        printf(" %d", x->value);
        preorder(x->left);
        preorder(x->right);
    }
}

template <class ty>
void BST<ty>::preorder() {
    BSTnode<ty>* x = root;
    if (x != NULL) {
        printf("%d", x->value);
        preorder(x->left);
        preorder(x->right);
    }
}

template <class ty>
void BST<ty>::postorder(BSTnode<ty>* x) {
    if (x != NULL) {
        postorder(x->left);
        postorder(x->right);
        printf("%d ", x->value);
    }
}

template <class ty>
void BST<ty>::postorder() {
    BSTnode<ty>* x = root;
    if (x != NULL) {
        postorder(x->left);
        postorder(x->right);
        printf("%d ", x->value);
    }
}

template <class ty>
BSTnode<ty>* BST<ty>::predecessor() {
    BSTnode<ty>* x = root;
	if (x == NULL)
		return NULL;

    if (x->left != NULL)
        return maximum(x->left);

    BSTnode<ty>* y = x->father;

    while (y != NULL && x == y->left) {
        x = y;
        y = y->father;
    }

    return y;
}

template <class ty>
BSTnode<ty>* BST<ty>::predecessor(BSTnode<ty>* x) {
	if (x == NULL)
		return NULL;

    if (x->right != NULL)
        return maximum(x->left);

    BSTnode<ty>* y = x->father;

    while (y != NULL && x == y->left) {
        x = y;
        y = y->father;
    }

    return y;
}

template <class ty>
BSTnode<ty>* BST<ty>::pred_not_in_tree(ty a) {
	BSTnode<ty>* x = root;
	BSTnode<ty>* tmp = NULL;

	while (x != NULL) {
		if (x->value >= a) {
			x = x->left;
		} else {
			x = x->right;
			tmp = x;
		}
	}

	if (tmp)
		return tmp;
	else
		return NULL;
}

template <class ty>
ty BST<ty>::minAt(ty a) {
	BSTnode<ty>* x = root;

	ty ans = 0;
	while (x != NULL) {
		if (x->value > ans && x->value < a)
			ans = x->value;
		if (x->value >= a)
			x = x->left;
		else
			x = x->right;
	}

	return ans;
}

std::string a, dmp;
int n, i, casos;
BSTnode<int>* tmp;

using namespace std;

int main (void) {
	casos = 0;
	string cmds;
	while (scanf("%d", &n) != EOF) {
        getline(cin, dmp);
		casos++;
		BST<int> arv;
		printf("Caso %d:\n", casos);
		for (int j = 0; j < n; j++) {
            getline(cin, cmds);

            if (cmds == "PRE") {
				if (arv.root == NULL)
					printf("0");
				else 
                	arv.preorder();
                printf("\n");
            } else if (cmds == "IN") {
				if (arv.root == NULL)
					printf("0");
				else 
                	arv.inorder();
                printf("\n");
            } else if (cmds == "POST") {
				if (arv.root == NULL)
					printf("0");
				else 
                	arv.postorder();
                printf("\n");
            } else {
                stringstream s(cmds);
                s >> a >> i;
                if (a == "A") {
                    arv.insert(i);
                } else if (a == "B") {
                    arv.remove(arv.search(i));
                } else {
                    int tmpi = arv.minAt(i);
                    printf("%d\n", tmpi);
                }
            }
        }
	}
}
