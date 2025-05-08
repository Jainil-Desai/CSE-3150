#include "TimedSharedPtr.h"
#include <iostream>
#include <thread>

struct Node {
    Node(int v) : val(v) {}
    int val;
};

int main() {
    {
        TimedSharedPtr<Node> myNode(new Node(7), 100);
        TimedSharedPtr<Node> myOtherNode = myNode;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "myNode.get() address: <" << myNode.get() << ">\n";
        std::cout << "myNode.use_count(): " << myNode.use_count() << "\n";
        std::cout << "myOtherNode.use_count(): " << myOtherNode.use_count() << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        std::cout << "myNode.get() address: <" << myNode.get() << ">\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        std::cout << "The ptr should have expired:\n";
        if (!myNode.get()) std::cout << "myNode.get() address: <Yeo! Expired 0>\n";
    }

    std::cout << "-----------\n";

    {
        TimedSharedPtr<int> p(new int(42), 200);
        std::cout << p.get() << "\n";
        std::cout << "p.use_count(): " << p.use_count() << "\n";

        TimedSharedPtr<int> q = p;
        std::cout << "p.use_count(): " << p.use_count() << "\n";
        std::cout << "q.use_count(): " << q.use_count() << "\n";
    }

    return 0;
}
