//Singly Linked Lists
struct Node {
    int value;
    unique_ptr<Node> next;
}

//Doubly-Linked Lists
struct Node {
    int value;
    Node const* prev;
    unique_ptr<Node> next;
}

//Binary Tree Node
class Node {
    public:
        Node(int v = 0):
            value{v}, left{nullptr}, right{nullptr}
        {}
        int value;
        unique_ptr<Node> left;
        unique_ptr<Node> right;
};

//Binary Search: insert Nodes
void insert(Node& current, unique_ptr<Node> newNode) {
    if (newNode -> value < current.value) {
        if (!current.left) {
            current.left = move(newNode);
        } else {
            insert(*current.left, move(newNode));
        }
    } else {
        if (!current.right){
            current.right = move(newNode);
        } else {
            insert(*current.right, move(newNode));
    }
}

//Binary Search: Printing
void print_tree(Node const& node, std::ostream& out) {
    if (node.left) print_tree(*node.left, out);

    out << node.value << '\n';

    if (node.right) print_tree(*node.right, out);
}







