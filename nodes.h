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
