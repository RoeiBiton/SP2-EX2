
#include "doctest.h"
#include "tree.hpp"

using namespace std;

// Test Node creation and basic functionality
TEST_CASE("Node creation and basic functionality") {
    //int example
    Node<int> node(5);
    CHECK(node.get_value() == 5);
    CHECK(node.getChildren().empty());
    //string example
    Node<string> node2("hagit");
    CHECK(node2.get_value() == "hagit");
    CHECK(node2.getChildren().empty());
    //double example
    Node<double> node3(2.178);
    CHECK(node3.get_value() == 2.178);
    CHECK(node3.getChildren().empty());
    //complex example
    Node<Complex> node4(Complex(2,1));
    CHECK(node4.get_value().getImag() ==1) ;
    CHECK(node4.get_value().getReal() == 2);
    CHECK(node4.getChildren().empty());
}

// Test Tree creation, adding root and adding sub nodes
TEST_CASE("Tree creation, adding root and sub nodes") {
    Tree<int> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == 1);

    Node<int> child1(2);
    Node<int> child2(3);
    tree.add_sub_node(root_node, child1);
    tree.add_sub_node(root_node, child2);

    CHECK(tree.get_root()->getChildren().size() == 2);
    CHECK(tree.get_root()->getChildren().at(0)->get_value() == 2);
    CHECK(tree.get_root()->getChildren().at(1)->get_value() == 3);
}

//Test Tree traversal methods
TEST_CASE("Tree traversal methods") {
    Tree<int> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    SUBCASE("Pre-order traversal") {
        std::vector<int> values;
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
            values.push_back(node->get_value());
        }
        std::vector<int> expected = {1, 2, 4, 5, 3, 6};
        CHECK(values == expected);
    }

    SUBCASE("Post-order traversal") {
        std::vector<int> values;
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
            values.push_back(node->get_value());
        }
        std::vector<int> expected = {4, 5, 2, 6, 3, 1};
        CHECK(values == expected);
    }

    SUBCASE("In-order traversal") {
        std::vector<int> values;
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
            values.push_back(node->get_value());
        }
        std::vector<int> expected = {4, 2, 5, 1, 6, 3};
        CHECK(values == expected);
    }

    SUBCASE("BFS traversal") {
        std::vector<int> values;
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
            values.push_back(node->get_value());
        }
        std::vector<int> expected = {1, 2, 3, 4, 5, 6};
        CHECK(values == expected);
    }

    SUBCASE("DFS traversal") {
        std::vector<int> values;
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
            values.push_back(node->get_value());
        }
        std::vector<int> expected = {1, 2, 4, 5, 3, 6};
        CHECK(values == expected);
    }
}


TEST_CASE("Heapify tree and iterate") {
    Tree<int> tree;
    Node<int> root_node(10);
    tree.add_root(root_node);
    Node<int> n1(15);
    Node<int> n2(20);
    Node<int> n3(30);
    Node<int> n4(40);
    Node<int> n5(50);
    Node<int> n6(60);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    tree.add_sub_node(n2, n6);

    std::vector<int> values;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        values.push_back(node->get_value());
    }

    std::vector<int> expected = {10, 15, 20, 30, 40, 50, 60}; // Expected min-heap order
    CHECK(values == expected);
}

TEST_CASE("Sort heap and iterate") {
    Tree<int> tree;
    Node<int> root_node(10);
    tree.add_root(root_node);
    Node<int> n1(15);
    Node<int> n2(20);
    Node<int> n3(30);
    Node<int> n4(40);
    Node<int> n5(50);
    Node<int> n6(60);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    tree.add_sub_node(n2, n6);

    tree.myHeap(); // Ensure heap is created and sorted

    std::vector<int> values;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        values.push_back(node->get_value());
    }

    std::vector<int> expected = {10, 15, 20, 30, 40, 50, 60}; // Expected sorted order
    CHECK(values == expected);
}

TEST_CASE("Tree creation, adding root and sub nodes") {
    Tree<std::string, 3> tree;
    Node<std::string> root_node("root");
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == "root");

    Node<std::string> child1("child1");
    Node<std::string> child2("child2");
    Node<std::string> child3("child3");
    Node<std::string> child4("child4");

    tree.add_sub_node(root_node, child1);
    tree.add_sub_node(root_node, child2);
    tree.add_sub_node(root_node, child3);
    CHECK_THROWS( tree.add_sub_node(root_node, child4));


    CHECK(tree.get_root()->getChildren().size() == 3);
    CHECK(tree.get_root()->getChildren().at(0)->get_value() == "child1");
    CHECK(tree.get_root()->getChildren().at(1)->get_value() == "child2");
    CHECK(tree.get_root()->getChildren().at(2)->get_value() == "child3");
}

// Test DFS traversal in a tree with int values
TEST_CASE("DFS traversal in tree with int values") {
    Tree<int> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<int> values;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        values.push_back((node)->get_value());
    }

    std::vector<int> expected = {1, 2, 4, 5, 3, 6};
    CHECK(values == expected);
}

TEST_CASE("in k>2 return just DFS"){
    Tree<std::string, 3> tree;
    Node<std::string> root_node("root");
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == "root");

    Node<std::string> child1("child1");
    Node<std::string> child2("child2");
    Node<std::string> child3("child3");
    Node<std::string> child4("child4");
    Node<std::string> child5("child5");
    Node<std::string> child6("child6");
    Node<std::string> child7("child7");

    tree.add_sub_node(root_node, child1);
    tree.add_sub_node(root_node, child2);
    tree.add_sub_node(root_node, child3);

    tree.add_sub_node(child1, child4);
    tree.add_sub_node(child2, child5);
    tree.add_sub_node(child3, child6);
    tree.add_sub_node(child6, child7);

    std::vector<string> values;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        values.push_back((node)->get_value());
    }

    std::vector<string> expected = {"root","child1","child4","child2","child5","child3","child6","child7"};
    CHECK(values == expected);
    std::vector<string> values2;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        values2.push_back((node)->get_value());
    }
    CHECK(values2 == expected);

    std::vector<string> values3;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        values3.push_back((node)->get_value());
    }
    CHECK(values3 == expected);
}

TEST_CASE("Tree Iterators") {
    // Integer Tree
    Tree<int> tree_int;
    tree_int.add_root(Node<int>(10));
    tree_int.add_sub_node(Node<int>(10), Node<int>(5));
    tree_int.add_sub_node(Node<int>(10), Node<int>(15));
    tree_int.add_sub_node(Node<int>(5), Node<int>(3));
    tree_int.add_sub_node(Node<int>(5), Node<int>(7));
    tree_int.add_sub_node(Node<int>(15), Node<int>(13));
    tree_int.add_sub_node(Node<int>(15), Node<int>(17));

    SUBCASE("Preorder Iterator - int") {
        std::vector<int> expected = {10, 5, 3, 7, 15, 13, 17};
        std::vector<int> result;
        for (auto it = tree_int.begin_pre_order(); it != tree_int.end_pre_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("Inorder Iterator - int") {
        std::vector<int> expected = {3, 5, 7, 10, 13, 15, 17};
        std::vector<int> result;
        for (auto it = tree_int.begin_in_order(); it != tree_int.end_in_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("Postorder Iterator - int") {
        std::vector<int> expected = {3, 7, 5, 13, 17, 15, 10};
        std::vector<int> result;
        for (auto it = tree_int.begin_post_order(); it != tree_int.end_post_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("DFS Iterator - int") {
        std::vector<int> expected = {10, 5, 3, 7, 15, 13, 17};
        std::vector<int> result;
        for (auto it = tree_int.begin_dfs_scan(); it != tree_int.end_dfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("BFS Iterator - int") {
        std::vector<int> expected = {10, 5, 15, 3, 7, 13, 17};
        std::vector<int> result;
        for (auto it = tree_int.begin_bfs_scan(); it != tree_int.end_bfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    // Double Tree
    Tree<double> tree_double;
    tree_double.add_root(Node<double>(10.5));
    tree_double.add_sub_node(Node<double>(10.5), Node<double>(5.3));
    tree_double.add_sub_node(Node<double>(10.5), Node<double>(15.2));
    tree_double.add_sub_node(Node<double>(5.3), Node<double>(3.1));
    tree_double.add_sub_node(Node<double>(5.3), Node<double>(7.8));
    tree_double.add_sub_node(Node<double>(15.2), Node<double>(13.6));
    tree_double.add_sub_node(Node<double>(15.2), Node<double>(17.4));

    SUBCASE("Preorder Iterator - double") {
        std::vector<double> expected = {10.5, 5.3, 3.1, 7.8, 15.2, 13.6, 17.4};
        std::vector<double> result;
        for (auto it = tree_double.begin_pre_order(); it != tree_double.end_pre_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("Inorder Iterator - double") {
        std::vector<double> expected = {3.1, 5.3, 7.8, 10.5, 13.6, 15.2, 17.4};
        std::vector<double> result;
        for (auto it = tree_double.begin_in_order(); it != tree_double.end_in_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("Postorder Iterator - double") {
        std::vector<double> expected = {3.1, 7.8, 5.3, 13.6, 17.4, 15.2, 10.5};
        std::vector<double> result;
        for (auto it = tree_double.begin_post_order(); it != tree_double.end_post_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("DFS Iterator - double") {
        std::vector<double> expected = {10.5, 5.3, 3.1, 7.8, 15.2, 13.6, 17.4};
        std::vector<double> result;
        for (auto it = tree_double.begin_dfs_scan(); it != tree_double.end_dfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("BFS Iterator - double") {
        std::vector<double> expected = {10.5, 5.3, 15.2, 3.1, 7.8, 13.6, 17.4};
        std::vector<double> result;
        for (auto it = tree_double.begin_bfs_scan(); it != tree_double.end_bfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    // String Tree
    Tree<std::string> tree_string;
    tree_string.add_root(Node<std::string>("mango"));
    tree_string.add_sub_node(Node<std::string>("mango"), Node<std::string>("apple"));
    tree_string.add_sub_node(Node<std::string>("mango"), Node<std::string>("banana"));

    SUBCASE("Preorder Iterator - string") {
        std::vector<std::string> expected = {"mango", "apple", "banana"};
        std::vector<std::string> result;
        for (auto it = tree_string.begin_pre_order(); it != tree_string.end_pre_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("Inorder Iterator - string") {
        std::vector<std::string> expected = {"apple", "mango", "banana"};
        std::vector<std::string> result;
        for (auto it = tree_string.begin_in_order(); it != tree_string.end_in_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("Postorder Iterator - string") {
        std::vector<std::string> expected = {"apple", "banana", "mango"};
        std::vector<std::string> result;
        for (auto it = tree_string.begin_post_order(); it != tree_string.end_post_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("DFS Iterator - string") {
        std::vector<std::string> expected = {"mango", "apple", "banana"};
        std::vector<std::string> result;
        for (auto it = tree_string.begin_dfs_scan(); it != tree_string.end_dfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("BFS Iterator - string") {
        std::vector<std::string> expected = {"mango", "apple", "banana"};
        std::vector<std::string> result;
        for (auto it = tree_string.begin_bfs_scan(); it != tree_string.end_bfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }
}

TEST_CASE("Heap Iterator") {
    // Test with integer type
    Tree<int> tree;
    tree.add_root(Node<int>(10));
    tree.add_sub_node(Node<int>(10), Node<int>(5));
    tree.add_sub_node(Node<int>(10), Node<int>(20));
    tree.add_sub_node(Node<int>(5), Node<int>(3));
    tree.add_sub_node(Node<int>(5), Node<int>(7));
    tree.add_sub_node(Node<int>(20), Node<int>(15));
    tree.add_sub_node(Node<int>(20), Node<int>(25));

    tree.myHeap();  // Convert the tree to a min-heap

    std::vector<int> expected_heap = {3, 5, 7, 10, 15, 20, 25};
    std::vector<int> result_heap;

    for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it) {
        result_heap.push_back(it->get_value());
    }

    CHECK(result_heap == expected_heap);
}

TEST_CASE("throws checking"){
    Node<double> root_node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 (1.2);
    Node<double> n2(1.3);
    Node<double> n3 (1.4);
    Node<double> n4 (1.5);
    Node<double> n5 (1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    //try to add tree children to binary node that already have 2 childrens
    CHECK_THROWS(tree.add_sub_node(n1, n5));
    //try to add node to nede that not in the tree
    CHECK_THROWS(tree.add_sub_node(n5, n2));
}