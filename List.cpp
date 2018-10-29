#include <iostream>

template < typename T >
class Node
{
public:
    T data;
    Node* next;
    
    Node (T data) { this->data = data; }
    Node(){}
};

template < typename T >
class List
{
public:
    int count;
    Node<T>* head = new Node<T>;
    
    List ();
    
    void add (T data);
    void remove (int index);
    int size () { return this->count; }
    void print ();
};

template <typename T>
List<T>::List ()
{
    this->count = 0;
    this->head->next = nullptr;
    this->head->next = nullptr;
}

template < typename T >
void List<T>::add (T data)
{
    Node<T>* newNode = new Node<T>(data);
    newNode->next = nullptr;
    
    if (head->next == nullptr) { head->next = newNode; }
    else {
        Node<T>* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    
    ++List::count;
}

template <typename T>
void List<T>::remove (int index)
{
    Node<T>* temp = head;
    Node<T>* target = head;
    
    if(count < index) { std::cout << "out of index!" << std::endl; return; }
    
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
        target = target->next;
    }
    target = target->next;
    
    temp->next = target->next;
    target->next = nullptr;
    delete target;
    --List::count;
}

template <typename T>
void List<T>::print ()
{
    Node<T>* iterator;
    iterator = head;
    
    while(iterator->next != nullptr) {
        iterator = iterator->next;
        std::cout << iterator->data << " ";
    }
    std::cout << std::endl;
}

int main ()
{
    // These codes are test
    List<char> test;
    test.add ('A');
    test.print ();
    
    test.add ('B');
    test.print ();
    
    test.add ('C');
    test.print ();
    
    test.remove(5);
    test.print();
    
    test.remove(1);
    test.print();
    
    return 0;
}


