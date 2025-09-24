/*
Doubly Linked List
*/
#include <iostream>

using namespace std;

template <class T1>
struct Node
{
    T1 _data;
    Node<T1>* _next = nullptr;
    Node<T1>* _prev = nullptr;
};

template <class T1>
void addNode(Node<T1>**, T1);

template <class T1>
void printList(Node<T1>*);

template <class T1>
void deleteList(Node<T1>*);

int main(int argc, char* argv[])
{
    Node<int>* head = nullptr;

    // head->_data = 42;
    addNode(&head, 42);
    addNode(&head, 15);
    addNode(&head, 23);

    printList(head);
    cout << endl;

    deleteList(head);
    return 0;
}

template <class T1>
void addNode(Node<T1>** h, T1 data)
{
    
    Node<T1>* newNode = new Node<T1>({data, nullptr, nullptr});
    
    // Node<T1> node1 = {data, nullptr, nullptr};
    // Node<T1>* newNode = &node1;
    ;
    cout << "Creating: " << newNode << endl;

    Node<T1>* curNode = *h;
    if(curNode == nullptr)
    {
        *h = newNode;
        return;
    } 

    while(curNode->_next != nullptr)
    {
        curNode = curNode->_next;
    }

    curNode->_next = newNode;
    newNode->_prev = curNode;
}

template <class T1>
void printList(Node<T1>* head)
{
    // Node<T1>* curNode = head;
    // while(curNode != nullptr)
    // {
    //     cout << curNode->_data << " ";
    //     curNode = curNode->_next;
    // }
    if (head == nullptr) return;

    printList(head->_next);
    cout << head->_data << " ";
    
    // cout << endl;
}

template <class T1>
void deleteList(Node<T1>* head)
{
    if (head == nullptr) return;

    deleteList(head->_next);
    cout << "Deleting: " << head << endl;
    delete head;
}