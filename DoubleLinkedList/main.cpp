#include <iostream>
#include "Iterator.h"

int main()
{
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2);
    Node<int>* node3 = new Node<int>(3);
    Node<int>* node4 = new Node<int>(4);
    Node<int>* node5 = new Node<int>(5);

    node1->previous = nullptr;
    node1->next = node2;

    node2->previous = node1;
    node2->next = node3;

    node3->previous = node2;
    node3->next = node4;

    node4->previous = node3;
    node4->next = node5;

    node5->previous = node4;
    node5->next = nullptr;



    Iterator<int> iter(node3);

    std::cout << *iter << std::endl;
    iter--;
    std::cout << *iter << std::endl;
    --iter;
    std::cout << *iter << std::endl;

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

}

