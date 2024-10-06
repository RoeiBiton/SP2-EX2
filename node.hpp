/**
 * Created by Roei Biton
 * Gmail: roei.biton33@gmail.com
 * */
#ifndef NODE_HPP
#define NODE_HPP
#include "Complex.hpp"
#include <vector>

/**
 * @brief A class template representing a node in for a tree structure.
 * 
 * @tparam T The type of value stored in the node.
 */
template <typename T>
class Node {
private:
    T value;
    std::vector<Node<T>*> children;

public:
    /**
     * @brief Constructor to initialize the node with a value.
     * 
     * @param val The value to be stored in the node.
     */
    explicit Node(T val) : value(val) {}

    /**
     * @brief Destructor for the Nod.
     * 
     * This destructor does not perform any specific cleanup since children nodes
     * are managed separately.
     */
    ~Node() {}

    /**
    * @brief Getter function to retrieve the value stored in the node.
    *
    * @return The value stored in the node.
    */
    T get_value() const { return value; }

    /**
    * @brief Getter function to retrieve the children of the node.
    *
    * @return The value stored in the node.
    */
    std::vector<Node<T> *> &getChildren() { return children; }

    /**
    * @brief function that add children to node.
    *
    */

    void addChildren(const Node<T> &newNode) {
        children.push_back(new Node<T>(newNode));
    }
};



#endif // NODE_HPP
