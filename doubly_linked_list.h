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

