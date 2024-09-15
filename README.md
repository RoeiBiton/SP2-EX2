Project Description: Tree Data Structure in C++

Overview

This project is a C++ program that creates and manages a tree data structure. A template tree that show hierarchy between nodes of data, where each item can have multiple children.

Node Class:  Node<T>
The Node class holds:
A value (like int double or anything else).
A list of its children nodes (the nodes that branch out from it).
You can get the value of a node and add children to it.

Tree Class:  Tree<T, K>
The Tree class manages the whole tree. It lets you:
Add a root node (the top node of the tree).
Add children to any node.
Visit and display the tree in different ways:
Pre-order: Visit the root first, then the children (only for binary trees).
Post-order: Visit the children first, then the root (only for binary trees).
In-order: Visit left child, then root, then right child (only for binary trees).
Breadth-First Search (BFS): Visit level by level.
Depth-First Search (DFS): Go as deep as possible down one branch before backtracking.
Show the structure of the tree in a visual way (by an SFML GUI).
The tree structure includes iterators that allow you to easily traverse the tree in different orders 
(pre-order, post-order, in-order, BFS, and DFS). This makes it convenient to access each node in the tree without needing to manage the traversal logic manually.

Supports Different Data Types:

This project can work with different types of data, like numbers (double, int), text (std::string), and even custom types like complex numbers.

Demo Application:

The Demo.cpp file shows how to use the Node and Tree classes. It demonstrates:
How to create trees with different types of data.
How to add nodes and display the tree.
How to run different traversal methods and see the results.

Makefile
the Makefile create a tree file and a test file that can run and check the implementation that have been done,
so the test file is checking all the tests that been implemented and the tree file is operating the Demo.cpp file which describe the use of the tree structure.


in conclusion i want to mention that i used a guide to SFML GUI to understand how to work with it.
https://www.youtube.com/watch?v=Aaf2Y-96nsk

Project by:
Roei Biton
ID:206400426
Roei.biton33@gmail.com
