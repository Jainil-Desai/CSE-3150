#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

TEST_CASE("Linked List Functionality Tests") {
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

        delete_list_element(head, 0);
        buffer.str("");
        buffer.clear();
        std::cout.rdbuf(buffer.rdbuf());
        print_linked_list(head);
        std::cout.rdbuf(old);

        output = buffer.str();
        CHECK(output == "2 -> 4 -> 5 -> nullptr\n");

        delete_entire_linked_list(head); 
    }

    SUBCASE("Delete Entire Linked List") {
        std::vector<int> values = {1, 2, 3};
        Node* head = build_linked_list(values);

        delete_entire_linked_list(head);

        CHECK(head == nullptr);
    }
}
