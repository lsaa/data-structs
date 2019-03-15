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

    btrnode<ty>* getRoot();
    void setRoot(btrnode<ty>*);
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
        if (a <= x->value) 
            x = x->left;
        else
            x = x->right;
    }
    
    btrnode<ty>* novo = new btrnode<ty>();
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
        }

        if (toDelete->isRight()) {
            toDelete->father->right = toDelete->getOnlyChild();
        } else {
            toDelete->father->left = toDelete->getOnlyChild();
        }

    // Two Children 
    } else {
        btrnode<ty>* suc = successor(toDelete);
        toDelete->value = suc->value;
        remove(suc);
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
btrnode<ty>* btree<ty>::getRoot() {
    return root;
}

template <class ty>
void btree<ty>::setRoot(btrnode<ty>* a) {
    root = a;
}
