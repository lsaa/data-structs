template <class ty>
class AVL : public btree<ty> {
public:
    AVL();
    AVLnode<ty>* root;

    void remove(AVLnode<ty>*);
    void insert(ty);

    void rotateLeft(AVLnode<ty>*);

    void rotateRight(AVLnode<ty>*);

    //int height(AVLnode<ty>*);

    void updateHeightFrom(AVLnode<ty>*, AVLnode<ty>*);
    void updateHeightFrom(AVLnode<ty>*);
    void checkBalanceFrom(AVLnode<ty>*, ty);

    int bal(AVLnode<ty>*);

    void inorder();
    void inorder(AVLnode<ty>*);
};

template <class ty>
AVL<ty>::AVL() {
    root = NULL;
}

template <class ty>
void AVL<ty>::rotateRight(AVLnode<ty>* x) {
    AVLnode<ty>* z;
    z = x->left;
    x->left = z->right;
    z->right = x;
    updateHeightFrom(x);
}

template <class ty>
void AVL<ty>::rotateLeft(AVLnode<ty>* y) {

    AVLnode<ty>* z;
    AVLnode<ty>* x = y->right;
    z = y->right;
    y->right = z->left;
    z->left = y;

    updateHeightFrom(y);
}

template <class ty>
void AVL<ty>::insert(ty a) {
    AVLnode<ty>* x = root;
    AVLnode<ty>* y = NULL;

    while (x != NULL) {
        y = x;
        if (a < x->value)
            x = x->left;
        else
            x = x->right;
    }

    AVLnode<ty>* novo = new AVLnode<ty>();
    novo->father = y;
    novo->value = a;

    if (y == NULL)
        root = novo;
    else if (a < y->value)
        y->left = novo;
    else
        y->right = novo;

    if (root != novo) {
        updateHeightFrom(novo->father, novo);
        checkBalanceFrom(novo, novo->value);
    }
}

template <class ty>
int AVL<ty>::bal(AVLnode<ty>* n) {

    if (!n)
        return 0;

    int nright, nleft;
    if (!n->right)
        nright = -1;
    else
        nright = n->right->height;

    if (!n->left)
        nleft = -1;
    else
        nleft = n->left->height;

    return (nright - nleft);
}

template <class ty>
void AVL<ty>::checkBalanceFrom(AVLnode<ty>* n, ty k) {
    int bl = bal(n);
    if (-1 <= bl && bl <= 1) {
        if (n != root)
            checkBalanceFrom(n->father, k);
    } else { //Fixup
        printf("Imbalanced at %d %d\n", n->value, k);

        if (bl > 1) {
            if (bal(n->right) > 0)
                rotateLeft(n);
            else {
                rotateRight(n->left);
                rotateLeft(n);
            }
        } else if (bl < -1) {
            if (bal(n->left) < 0) {
                rotateRight(n->left);
                rotateLeft(n);
            }else {
                rotateLeft(n);
            }
        }
        if (n != root)
            checkBalanceFrom(n->father, k);
    }
}

template <class ty>
void AVL<ty>::updateHeightFrom(AVLnode<ty>* n, AVLnode<ty>* p) {
    n->height = p->height + 1;
    if (n != root)
        updateHeightFrom(n->father, n);
}

template <class ty>
void AVL<ty>::updateHeightFrom(AVLnode<ty>* n) {
    int a, b;
    if (n->left)
        a = n->left->height;
    else
        a = -1;

    if (n->right)
        b = n->right->height;
    else
        b = -1;

    if (a > b)
        n->height = a + 1;
    else
        n->height = b + 1;

    if (n != root)
        updateHeightFrom(n->father, n);
}

template <class ty>
void AVL<ty>::inorder(AVLnode<ty>* x) {
    if (x != NULL) {
        inorder(x->left);
        printf("%d ", x->value);
        inorder(x->right);
    }
}

template <class ty>
void AVL<ty>::inorder() {
    AVLnode<ty>* x = root;
    if (x != NULL) {
        inorder(x->left);
        printf("%d ", x->value);
        inorder(x->right);
    }
}
