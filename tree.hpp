#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include <memory>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <SFML/Graphics.hpp>

template<typename T, size_t K = 2>
class Tree {
private:
    Node<T> *root;
    std::vector<Node<T> *> pre_order_nodes;
    std::vector<Node<T> *> post_order_nodes;
    std::vector<Node<T> *> in_order_nodes;
    std::vector<Node<T> *> bfs_nodes;
    std::vector<Node<T> *> dfs_nodes;
    std::vector<Node<T> *> heap_nodes;
    bool heapIsBuilt = false;

    void pre_order(Node<T> *node, std::vector<Node<T> *> &nodes) {
        if (!node) { return; }


        nodes.push_back(node);


        for (Node<T> *child: node->getChildren()) {
            pre_order(child, nodes);
        }
    }

    void in_order(Node<T>* node, std::vector<Node<T>*>& nodes) {
        if (!node) return;
        if (!node->getChildren().empty()) {
            in_order(node->getChildren().at(0), nodes);
        }
        nodes.push_back(node);
        for (size_t i = 1; i < node->getChildren().size(); ++i) {
            in_order(node->getChildren().at(i), nodes);
        }
    }

    void post_order( Node<T> *node, std::vector< Node<T> *> &nodes) {
        if (!node) return;
        for (Node<T> *child: node->getChildren()) {
            post_order(child, nodes);
        }
        nodes.push_back(node);
    }

    void bfs( Node<T> *node, std::vector< Node<T> *> &nodes) {
        if (!node) { return; }

        std::queue<Node<T> *> queue;
        queue.push(node);

        while (!queue.empty()) {
            Node<T> *currentNode = queue.front();
            queue.pop();
            nodes.push_back(currentNode);

            for (Node<T> *child: currentNode->getChildren()) {
                queue.push(child);
            }
        }
    }

    void dfs( Node<T> *node, std::vector< Node<T> *> &nodes) {
        if (!node) return;
        std::stack<Node<T> *> stack;
        stack.push(node);
        while (!stack.empty()) {
            Node<T> *currentNode = stack.top();
            stack.pop();
            nodes.push_back(currentNode);


            auto &children = currentNode->getChildren();
            for (auto it = children.rbegin(); it != children.rend(); ++it) {
                stack.push(*it);
            }
        }
    }

    void heapify(Node<T> *node) {
        if (!node) return;
        Node<T> *minimumNode = node;
        for (Node<T> *child: node->getChildren()) {
            if (child && child->get_value() < minimumNode->get_value()) {
                minimumNode = child;
            }
        }
        if (minimumNode != node) {
            std::swap(node->get_value(), minimumNode->get_value());
            heapify(minimumNode);
        }
    }

public:
    Tree() : root(nullptr) {} //define the tree as empty at the creation
    ~Tree() {
        delete_tree(root);
    }

    void add_root(const Node<T> &root_node) {
        delete_tree(root); // Clean the root if there is already 1 exist.
        root = new Node<T>(root_node);
    }

    void add_sub_node(const Node<T> &parent_node, const Node<T> &child_node) {
        Node<T> *parent = find_node(root, parent_node.get_value());
        if (parent) {
            if (parent->getChildren().size() < K) {
                parent->addChildren(child_node);
            } else {
                throw std::runtime_error("The parent have reached his limit of children, operation cant be done");
            }
        } else {
            throw std::runtime_error("The parent node is not found");
        }
    }

    Node<T> *get_root() const {
        return root;
    }

    Node<T> *find_node(Node<T> *current, T value) {
        if (!current) return nullptr;
        if (current->get_value() == value) return current;
        for (Node<T> *child: current->getChildren()) {
            Node<T> *result = find_node(child, value);
            if (result) {
                return result;
            }

        }
        return nullptr;
    }

    void delete_tree(Node<T> *node) {
        if (!node) return;
        for (Node<T> *child: node->getChildren()) {
            delete_tree(child);
        }
        delete node;
    }

    class Iterator {
    private:
        typename std::vector<Node<T> *>::iterator it;

    public:

        Iterator(typename std::vector<Node<T> *>::iterator it) : it(it) {}

        Node<T> &operator*() { return **it; }

        Node<T> *operator->() { return *it; }

        Iterator &operator++() {
            ++it;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++it;
            return tmp;
        }

        bool operator==(const Iterator &other) const { return it == other.it; }

        bool operator!=(const Iterator &other) const { return it != other.it; }
    };

    ///////

    Iterator begin_pre_order() {
        if (K == 2) {
            pre_order_nodes.clear();
            pre_order(root, pre_order_nodes);
            return Iterator(pre_order_nodes.begin());
        }
        return begin_dfs_scan();

    }

    Iterator end_pre_order() {
        if (K == 2) {
            return Iterator(pre_order_nodes.end());
        }
        return end_dfs_scan();

    }

    Iterator begin_post_order() {
        if (K == 2) {
            post_order_nodes.clear();
            post_order(root, post_order_nodes);
            return Iterator(post_order_nodes.begin());
        }
        return begin_dfs_scan();

    }

    Iterator end_post_order() {
        if (K == 2) {
            return Iterator(post_order_nodes.end());
        }
        return end_dfs_scan();
    }

    Iterator begin_in_order() {
        if (K == 2) {
            in_order_nodes.clear();
            in_order(root, in_order_nodes);
            return Iterator(in_order_nodes.begin());
        }
        return begin_dfs_scan();
    }

    Iterator end_in_order() {
        if (K == 2) {
            return Iterator(in_order_nodes.end());
        }
        return end_dfs_scan();
    }

    Iterator begin_bfs_scan() {
        bfs_nodes.clear();
        bfs(root, bfs_nodes);
        return Iterator(bfs_nodes.begin());
    }

    Iterator end_bfs_scan() {
        return Iterator(bfs_nodes.end());
    }

    Iterator begin_dfs_scan() {
        dfs_nodes.clear();
        dfs(root, dfs_nodes);
        return Iterator(dfs_nodes.begin());
    }

    Iterator end_dfs_scan() {
        return Iterator(dfs_nodes.end());
    }

    Iterator begin() {
        return begin_bfs_scan();
    }

    Iterator end() {
        return end_bfs_scan();
    }
    ///////

    void myHeap() {
        if (!root) return;
        heap_nodes.clear();
        bfs(root, heap_nodes);


        auto node_value_comparator = [](Node<T> *a, Node<T> *b) {
            return a->get_value() < b->get_value(); // Min-heap: smallest value at the top
        };


        std::make_heap(heap_nodes.begin(), heap_nodes.end(), node_value_comparator);


        std::sort_heap(heap_nodes.begin(), heap_nodes.end(), node_value_comparator);
    }

    Iterator begin_heap() {
        if (!heapIsBuilt) {
            this->myHeap();
            heapIsBuilt = true;
        }
        return Iterator(heap_nodes.begin());
    }

    Iterator end_heap() {
        if (!heapIsBuilt) {
            this->myHeap();
            heapIsBuilt = true;
        }
        return Iterator(heap_nodes.end());
    }


};

#endif
