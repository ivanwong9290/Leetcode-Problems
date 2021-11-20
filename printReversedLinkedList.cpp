#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'reversePrint' function below.
 *
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void reversePrint(SinglyLinkedListNode* llist) {
    if (llist == nullptr) {
        return;
    }
    
    // Instantiate some pointers for tracking
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* curr = llist;
    SinglyLinkedListNode* next = nullptr;
    
    // While-loop for reversing link
    while(curr != nullptr){
        // Save the current memory address for forward traversal (save (node i)->next = node i+1) before breaking link
        next = curr->next;
        // Reverse link to point backward, thus breaking the forward link
        curr->next = prev;
        // Make node i-1 = node i and node i = node i+1
        prev = curr;
        curr = next;
    }
    
    // prev is now the head of its own linked list pointing backwards, run backward traversal until head of forward linked list
    while(prev != nullptr){
        cout << prev->data << endl;
        prev = prev->next;
    }
    return;
}

int main()