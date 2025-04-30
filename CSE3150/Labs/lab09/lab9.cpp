#include "lab9.h"

Node::Node(string name) : name{name} {
    cout << "Node constructor [" << name << "] at " << this << endl;
}

Node::~Node() {
    cout << "Node [" << name << "] destructor" << endl;
}

void LinkedList::SERVER_buildCircularLinkedList(const vector<string> &names) {
    if (names.empty())
        return;

    list_root = make_shared<Node>(names[0]);
    shared_ptr<Node> current_node = list_root;
    nodes.push_back(list_root);

    for (size_t i = 1; i < names.size(); ++i) {
        auto newNode = make_shared<Node>(names[i]);
        current_node->next = newNode;
        nodes.push_back(newNode);
        current_node = newNode;
    }

    current_node->next = list_root;

    for (const auto& node : nodes) {
        weak_nodes.push_back(weak_ptr<Node>(node));
    }
}

void LinkedList::SERVER_deleteCircularLinkedList() {
    nodes.clear();
    list_root = nullptr;
}

void LinkedList::SERVER_printLinkedList() {
    if (!list_root)
        return;

    auto current = list_root;
    cout << "\nServer printing: \n";
    for (size_t i = 0; i < 6; ++i) {
        cout << "[" << current->name << "] : use_count: " << current.use_count()
             << " address: " << current.get()
             << " next (from shared_ptr): " << current->next.get() << endl;

        current = current->next;
    }
}

void LinkedList::CLIENT_printLinkedList() {
    if (weak_nodes.empty()) {
        cout << "Client after linked list deleted:\n-----------------------------\n[Nothing]" << endl;
        return;
    }

    cout << "Client printing: \n";
    for (const auto& weak : weak_nodes) {
        auto node = weak.lock();
        if (!node) {
            cout << "Yipes! shared_ptr not available\n";
        } else {
            cout << "[" << node->name << "] : use_count: " << node.use_count()
                 << " address: " << node.get() << endl;
        }
    }
}

