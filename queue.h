template <class ty>
class queue {
public:
    dlinode<ty>* start;
    dlinode<ty>* end;
    queue();
    void insertAtEnd(ty);
    ty* removeFromEnd();
    dlinode<ty>* getEnd();
    void setEnd(dlinode<ty>*);
    ty* operator[](int);
    ty* get(int);
    void setStart(dlinode<ty>*);
    dlinode<ty>* getStart();
    void insertAtStart(ty);
    ty* removeFromStart();
    bool isEmpty();
    void print();
	void erase(dlinode<ty>*);
	int size();
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
    if (end)
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
ty* queue<ty>::get(int i) {
    if (!isEmpty()) {
        dlinode<ty>* cNode = getStart();
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
ty* queue<ty>::operator[](int i) {
    return get(i);
}

template <class ty>
ty* queue<ty>::removeFromStart() {
    if (isEmpty())
        return NULL;

    dlinode<ty>* old = new dlinode<ty>(*start);
    start = start->next;
    if (start)
        start->prev = NULL;
    return &old->value;
}

template <class ty>
void queue<ty>::erase(dlinode<ty>* e) {
	if (e == start) {
		removeFromStart();
		return;
	} else if (e == end) {
		removeFromEnd();
		return;
	}

	e->prev->next = e->next;
	e->next->prev = e->prev;
}

template <class ty>
int queue<ty>::size() {
	int r = 0;
	dlinode<ty>* cn = start;
	while (cn) {
		r++;
		cn = cn->next;
	}
	return r;
}
