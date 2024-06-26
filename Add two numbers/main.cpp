
#include <iostream>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to insert a node at the
beginning of the Singly Linked List */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node(new_data);
    /* link the old list of the new node */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
// function to linked list
void printList(Node* n)
{
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
// function that work on addition operation.
Node* addTwoLists(Node* first, Node* second)
{
    int num1 = 0, num2 = 0;
    // here we get num1 form first linked list.
    while (first->next != NULL) {
        num1 += first->data;
        num1 *= 10;
        first = first->next;
    }
    num1 += first->data;
    // here we get num2 form second linked list.
    while (second->next != NULL) {
        num2 += second->data;
        num2 *= 10;
        second = second->next;
    }
    num2 += second->data;
    // here we add both number.
    int num3 = num1 + num2;
    Node* temp = NULL;
    // Node* result=temp;
    // convert num3 into linked list.
    while (num3 != 0) {
        int last = num3 % 10;
        push(&temp, last);
        num3 = num3 / 10;
    }
    // finally return resultant linked list.
    return temp;
}
int main()
{
    Node* first = NULL;
    Node* second = NULL;
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);

    push(&second, 4);
    push(&second, 8);

    Node* ans = addTwoLists(first, second);

    cout << "Sum is : ";
    printList(ans);
    return 0;
}
