#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
#include <stdexcept>

// Node Structure
struct Node {
    int data;
    Node* next;

    // Constructor
    Node(int val) : data(val), next(nullptr) {}

    // Copy Constructor
    Node(const Node& other);

    // Destructor
    ~Node();
};

// Function Declarations
Node* build_linked_list(const std::vector<int>& values);
void print_linked_list(Node* head);
void delete_entire_linked_list(Node*& head);
int get_linked_list_data_item_value(Node* head, int node_number);
void delete_list_element(Node*& head, int node_number);
bool has_positive_prefix_sum(Node* head);
void pointer_jumping(Node* head);

#endif 
