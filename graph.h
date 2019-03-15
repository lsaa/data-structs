template <class ty>
class graph {
public:
    graph(int);
    int size;
    list<ty>* adj;
    void connect(int, int);
    int shortest(int, int);
};

template <class ty>
graph<ty>::graph(int a) {
    size = a;
    adj = new list<ty>[size];
}

template <class ty>
void graph<ty>::connect(int a, int b) {
    adj[a].insertAtStart(b);
    adj[b].insertAtStart(a);
}

template <class ty>
int graph<ty>::shortest(int start, int goal) {
    if (start == goal)
        return 0;

    int dist[size];
    for (int i = 0; i < size; i++)
        dist[i] = -1;

    queue<ty> q;

    dist[start] = 0;
    q.insertAtEnd(start);

    while (q.isEmpty() != true) {
        ty* cptr = q.removeFromStart();
        linode<ty>* current = adj[*cptr].getStart();
        while (current != NULL) {
            if (dist[current->value] == -1){
                dist[current->value] = dist[*cptr] + 1;
                if (current->value == goal)
                    break;
                q.insertAtEnd(current->value);
            }
            current = current->next;
        }
    }

    return dist[goal];
}