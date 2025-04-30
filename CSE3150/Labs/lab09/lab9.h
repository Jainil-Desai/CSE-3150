#ifndef LAB9_H
#define LAB9_H

#include "./doctest.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

struct Node {
    string name;
    Node(string name);
    shared_ptr<Node> next; // Not weak!
    ~Node();
};

class LinkedList {
public:
    void SERVER_buildCircularLinkedList(const vector<string> &names);
    void SERVER_deleteCircularLinkedList();
    void SERVER_printLinkedList();
    void CLIENT_printLinkedList();

private:
    shared_ptr<Node> list_root; // First node, same lifecycle
    vector<shared_ptr<Node>> nodes;
    vector<weak_ptr<Node>> weak_nodes; // For CLIENT simulation
};

#endif
