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
