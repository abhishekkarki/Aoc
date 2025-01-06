// linkded list with different functionality
#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// class List
class List {
    private:     
        Node* head;
        Node* tail;

    public:
        // declaring the list
        List () {
            head = tail = NULL;
        }

        // push_front implementation
        void push_front(int value) { // O(1)
            Node* newNode = new Node(value);
            if (head == NULL) {
                head = tail = newNode;
                return;
            } else {
                newNode -> next = head;
                head = newNode;
            }
        }

        // print all function for printing the list
        void print_all() { // O(n)
            Node* temp = head;
            while (temp != NULL) {
                std::cout << temp -> data << " ";
                temp = temp -> next;
            }
            std::cout << std::endl;
        }

        // push_back implementation
        void push_back(int value) {
            Node* newNode = new Node(value);
            if (head == NULL) {
                head = tail = newNode;
                return;
            } else {
                tail -> next = newNode;
                tail = newNode;
            }
        }

        // pop_front implementation
        void pop_front() { // O(1)
            if (head == NULL) {
                std::cout << "list is already empty " << std::endl;
                return;
            } else {
                Node* temp = head;
                head = head -> next;
                temp -> next = NULL;
                delete temp;
            }
        }

        // pop_back implementation
        void pop_back() { // O(n)
            if (head == NULL) {
                std::cout << "The list is already empty " << std::endl;
                return;
            } else {
                Node* temp = head;
                while (temp -> next != tail) {
                    temp = temp -> next;
                }
                temp -> next = NULL;
                delete tail;
                tail = temp;
            }
        }

        // insert implementation
        void insert(int value, int position) { // O(n)
            if (position < 0) {
                std::cout << "Not a valid position" << std::endl;
                return;
            }
            if (position == 0) {
                push_front(value);
                return;
            }
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                if (temp == NULL) {
                    std::cout << "not valid position" << std::endl;
                    return;
                }
                temp = temp -> next;
            }
            Node* newNode = new Node(value);
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }

        // search implementation
        int search(int value) { // O(n)
            if (head == NULL) {
                std::cout << "The list is empty" << std::endl;
                return -1;
            } else {
                Node* temp = head;
                int index = 0;
                while (temp != NULL) {
                    if ((temp -> data) == value) {
                        return index;
                    }
                    temp = temp -> next;
                    index++;
                }
                return -1;
            }
        }

};

int main() {
    // creating list
    List ll;
    
    // pushing elements in the linked list
    ll.push_front(12);
    ll.push_front(4);
    ll.push_front(1);

    // printing the elements of the linked list
    ll.print_all();

    // pushing elements at the back of the LL
    ll.push_back(23);
    ll.push_back(123);

    ll.print_all();

    // popping the value from the front of the LL
    ll.pop_front();
    ll.print_all();

    // popping the value from the end of the LL
    ll.pop_back();
    ll.print_all();

    // inserting an element using insert function
    ll.insert(88, 0);
    ll.print_all();

    // searching an element in the LL
    std::cout << ll.search(23) << std::endl;


}