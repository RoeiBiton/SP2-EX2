
//roei.biton33@gmail.com
//206400426

#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

using namespace std;

int main() {
    Node<double> root_node =Node(1.1);
    Tree<double> tree; // Binary tree of doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    //The tree should look like:
    /**
    *       root = 1.1
    *     /       \
    *    1.2      1.3
    *   /  \      /
    *  1.4  1.5  1.6
    */
    tree.displayTree(); //GUI Printing
  
    cout << "Pre-K traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    } //prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
        
    cout << "Post-K traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    } //prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    cout << "In-K traversal:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    } //prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    cout << "BFS traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } //prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "DFS traversal:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << node->get_value() << endl;
    } //prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
        
    cout << "same as BFS traversal:" << endl;
    for (auto node : tree)
    {
        cout << node.get_value() << endl;
    } //same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
        
    cout << "Heap:" << endl;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        cout << node->get_value() << endl;
    }

    Tree<double,3> three_ary_tree; //3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    //The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    three_ary_tree.displayTree();
    
    cout << "Run pre-order traversal on the three ary tree:" << endl;
    for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    } //prints like dfs: 1.1, 1.2, 1.5, 1.3, 1.6, 1.4

    cout << "Run post-order traversal on the three ary tree:" << endl;
    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    } //prints like dfs: 1.1, 1.2, 1.5, 1.3, 1.6, 1.4
        
    cout << "Run in-order traversal on the three ary tree:" << endl;
    for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    } //prints like dfs: 1.1, 1.2, 1.5, 1.3, 1.6, 1.4

    Node<std::string> stringRoot("This");
    Tree<std::string> treeOfStrings; // Binary tree of Strings.
    treeOfStrings.add_root(stringRoot);
    Node<std::string> node1("is");
    Node<std::string> node2("a");
    Node<std::string> node3("binary");
    Node<std::string> node4("tree");
    Node<std::string> node5("of");
    Node<std::string> node6("strings");

    treeOfStrings.add_sub_node(stringRoot, node1);
    treeOfStrings.add_sub_node(stringRoot, node2);
    treeOfStrings.add_sub_node(node1, node3);
    treeOfStrings.add_sub_node(node1, node4);
    treeOfStrings.add_sub_node(node2, node5);
    treeOfStrings.add_sub_node(node2, node6);

    treeOfStrings.displayTree();
    


    Tree<Complex> complexTree; // This is a tree of Complex numbers
    Node<Complex> rootnc1(Complex(1.0,2.0));
    Node<Complex> nc2(Complex(3.0,4.0));
    Node<Complex> nc3(Complex(5.0,6.0));
    complexTree.add_root(rootnc1);
    complexTree.add_sub_node(rootnc1, nc2);
    complexTree.add_sub_node(rootnc1, nc3);

    complexTree.displayTree();

    Node<int> root_node_int=Node(1);
    Tree<int> tree_int; // Binary tree that contains doubles.
    tree_int.add_root(root_node_int);
    Node<int> n1_ = Node(2);
    Node<int> n2_ = Node(3);
    

    tree_int.add_sub_node(root_node_int, n1_);
    tree_int.add_sub_node(root_node_int, n2_);

    tree_int.displayTree();




    return 0;
    }
