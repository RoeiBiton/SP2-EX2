//
// Created by Roei Biton on 02/09/2024.
//

#ifndef SP2EX2_NODE_HPP
#define SP2EX2_NODE_HPP

#include "Complex.hpp"
#include <vector>


template<typename T>
class Node {
private:
    T value;
    std::vector<Node<T> *> children;
public:

    explicit Node(T val) : value(val) {}

    ~Node() = default;

    T get_value() const { return value; }

    std::vector<Node<T> *> &getChildren() { return children; }

    void addChildren(const Node<T> &newNode) { children.push_back(new Node<T>(newNode)); }


};


#endif //SP2EX2_NODE_HPP