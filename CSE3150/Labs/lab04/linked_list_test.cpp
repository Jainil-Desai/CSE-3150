#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

TEST_CASE("Linked List Functionality Tests") {
    // This will display the test progress in the terminal
    Node* head = build_linked_list({-1, 1, 1});
    print_linked_list(head);  // This will print -1->1->1->
    
    // For the second line in the output
    Node* head2 = build_linked_list({-1, 1, 3});
    print_linked_list(head2);  // This will print -1->1->3->
    
    // For the third line in the output
    Node* head3 = build_linked_list({-1, 1});
    print_linked_list(head3);  // This will print -1->1->
    
    // Clean up
    delete_entire_linked_list(head);
    delete_entire_linked_list(head2);
    delete_entire_linked_list(head3);
    
    SUBCASE("Build and Print Linked List") {
        std::vector<int> values = {1, 2, 3, 4, 5};
        Node* head = build_linked_list(values);

        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        print_linked_list(head);

        std::cout.rdbuf(old);

        std::string output = buffer.str();
        CHECK(output == "1 -> 2 -> 3 -> 4 -> 5 -> nullptr\n");

        delete_entire_linked_list(head);
    }

    SUBCASE("Move Constructor") {
        Node original(10);
        Node moved(std::move(original));

        CHECK(moved.data == 10);
        CHECK(original.next == nullptr); // Original should be empty
    }

    SUBCASE("Move Assignment Operator") {
        Node original(20);
        Node assigned(5);

        assigned = std::move(original);

        CHECK(assigned.data == 20);
        CHECK(original.next == nullptr); // Original should be empty
    }

    SUBCASE("Retrieve Node Value") {
        std::vector<int> values = {10, 20, 30, 40};
        Node* head = build_linked_list(values);

        CHECK(get_linked_list_data_item_value(head, 0) == 10);
        CHECK(get_linked_list_data_item_value(head, 2) == 30);

        CHECK_THROWS_AS(get_linked_list_data_item_value(head, 10), std::out_of_range);

        delete_entire_linked_list(head);
    }

    SUBCASE("Delete Specific Node") {
        std::vector<int> values = {1, 2, 3, 4, 5};
        Node* head = build_linked_list(values);

        delete_list_element(head, 2);

        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        print_linked_list(head);

        std::cout.rdbuf(old);

        std::string output = buffer.str();
        CHECK(output == "1 -> 2 -> 4 -> 5 -> nullptr\n");

        delete_entire_linked_list(head); 
    }

    SUBCASE("Prefix Sum Check") {
        std::vector<int> values = {1, 2, 3, 4};
        Node* head = build_linked_list(values);
        CHECK(has_positive_prefix_sum(head) == true);
        delete_entire_linked_list(head);

        std::vector<int> neg_values = {-1, -2, -3};
        head = build_linked_list(neg_values);
        CHECK(has_positive_prefix_sum(head) == false);
        delete_entire_linked_list(head);
    }

    SUBCASE("Pointer Jumping") {
        std::vector<int> values = {1, 2, 3, 4, 5};
        Node* head = build_linked_list(values);

        pointer_jumping(head);

        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        print_linked_list(head);
        std::cout.rdbuf(old);

        std::string output = buffer.str();
        CHECK(output == "1 -> 3 -> 5 -> nullptr\n");

        delete_entire_linked_list(head);
    }
}