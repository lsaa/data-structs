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
    btrnode<ty>* getOnlyChild();
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
btrnode<ty>* btrnode<ty>::getOnlyChild() {
    if (left)
        return left;
    return right;
}

template <class ty>
class AVLnode : public btrnode<ty> {
public:
    AVLnode();
    ty value;
    AVLnode<ty>* father;
    AVLnode<ty>* left;
    AVLnode<ty>* right;
    int height;

    //AVLnode<ty>* brother();
    //AVLnode<ty>* getOnlyChild();
};

template <class ty>
AVLnode<ty>::AVLnode() {
    left = NULL;
    right = NULL;
    father = NULL;
    height = 0;
}