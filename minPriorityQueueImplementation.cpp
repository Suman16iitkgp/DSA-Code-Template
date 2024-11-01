class Node{
public:
    int w;
};


class Compare{
public:
    bool operator()(Node& a, Node& b){
        return a.w < b.w;            // for min Priority Queue
        return a.w > b.w;            // for max Priority Queue
    }
};


int main() {
    priority_queue<Node, vector<Node>, Compare> pq;
    return;
}