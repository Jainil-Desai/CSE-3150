#include "linked_list.h"
#include <iostream>
#include <stdexcept>

Node::Node(const Node& other) {
    data = other.data;
    next = other.next ? new Node(*other.next) : nullptr;
}

Node::~Node() {
    delete next;
}

Node* build_linked_list(const std::vector<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int value : values) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void print_linked_list(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

void delete_entire_linked_list(Node*& head) {
    if (head) {
        delete head;
        head = nullptr;
    }
}

int get_linked_list_data_item_value(Node* head, int node_number) {
    Node* current = head;
    int count = 0;

    while (current) {
        if (count == node_number) {
            return current->data;
        }
        current = current->next;
        count++;
    }
    throw std::out_of_range("Node number out of range");
}

void delete_list_element(Node*& head, int node_number) {
    if (!head) return;

    if (node_number == 0) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 0; current && i < node_number - 1; i++) {
        current = current->next;
    }

    if (!current || !current->next) throw std::out_of_range("Node number out of range");

    Node* temp = current->next;
    current->next = current->next->next;
    temp->next = nullptr;
    delete temp;
}

bool has_positive_prefix_sum(Node* head) {
    int sum = 0;
    while (head) {
        sum += head->data;
        if (sum <= 0) return false;
        head = head->next;
    }
    return true;
}

void pointer_jumping(Node* head) {
    while (head && head->next) {
        head->next = head->next->next; // Skip every other node
        head = head->next;
    }
}
