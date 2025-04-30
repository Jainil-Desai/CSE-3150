#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lab9.h"
#include "./doctest.h"

TEST_CASE("Basic circular linked list build and print") {
    vector<string> names = {"zero", "one", "two", "three", "four", "five"};
    LinkedList L1;
    L1.SERVER_buildCircularLinkedList(names);
    L1.SERVER_printLinkedList();
    L1.CLIENT_printLinkedList();
    L1.SERVER_deleteCircularLinkedList();
    L1.CLIENT_printLinkedList();
}

TEST_CASE("Empty list test") {
    vector<string> names = {};
    LinkedList L2;
    L2.SERVER_buildCircularLinkedList(names);
    L2.SERVER_printLinkedList();      
    L2.CLIENT_printLinkedList();      
    L2.SERVER_deleteCircularLinkedList();  
    L2.CLIENT_printLinkedList();      
}

TEST_CASE("Single node list test") {
    vector<string> names = {"solo"};
    LinkedList L3;
    L3.SERVER_buildCircularLinkedList(names);
    L3.SERVER_printLinkedList();      
    L3.CLIENT_printLinkedList();
    L3.SERVER_deleteCircularLinkedList();
    L3.CLIENT_printLinkedList();     
}
