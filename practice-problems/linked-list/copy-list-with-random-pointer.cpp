// defination of Node
class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
};

NOde* copyRandomList(Node* head) {
    // if list is empty
    if (!head) return nullptr;

    // step 1: insert new nodes between the original nodes
    Node* current = head;
    while (current) {
        Node* newNode = new Node(current -> val);
        newNode -> next = current -> next;
        current -> next = newNode;
        current = newNode -> next;
    }

    // step 2: assigning the random pointers
    Node* current = head;
    while (current) {
        if (current -> random) {
            current -> next -> random = current -> random -> next;
        }
        current -> next -> next;
    }

    // step 3: detaching the lists
    Node* dummy = new Node(-1);
    Node* currentCopied = dummy;
    current = head;
    while (current) {
        currentCopied -> next = current -> next;
        currentCopied = currentCopied -> next;

        current -> next = current -> next -> next;
        current = current -> next;
    }
    return dummy -> next;
    
}