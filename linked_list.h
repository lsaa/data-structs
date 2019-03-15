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
