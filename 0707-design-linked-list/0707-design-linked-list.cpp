class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node* head; // Dummy head node
    int size;

public:
    // Constructor
    MyLinkedList() {
        head = new Node(0); // Dummy node
        size = 0;
    }

    // Get the value of the index-th node
    int get(int index) {
        if (index < 0 || index >= size) return -1;

        Node* curr = head->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    // Add a node at the head
    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    // Add a node at the tail
    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    // Add a node at the specified index
    void addAtIndex(int index, int val) {
        if (index < 0) index = 0;
        if (index > size) return;

        Node* prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }

    // Delete a node at the specified index
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        Node* prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        size--;
    }
};