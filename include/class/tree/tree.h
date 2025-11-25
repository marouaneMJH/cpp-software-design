#pragma once
#include <iostream>
#include <queue>


typedef enum
{
    _RED,
    _BLACK
}NodeColor;


// -----------------------------------------------------
// TreeNode Class Template
// -----------------------------------------------------
template <typename T>
class TreeNode
{
private:
    T _value;
    TreeNode<T>* _left;
    TreeNode<T>* _right;
    NodeColor _color;

public:
    // Constructors
    TreeNode(T val);
    TreeNode(T val, TreeNode<T>* left, TreeNode<T>* right);

    // Accessors
    T getValue() const;
    void setValue(T val);
    void setColor(NodeColor color);

    TreeNode<T>* getLeft() const;
    TreeNode<T>* getRight() const;

    // Child management
    bool hasLeftChild() const;
    bool hasRightChild() const;
    bool hasChildren() const;

    bool addLeftChild(T value);
    bool addRightChild(T value);

    bool removeLeftChild();
    bool removeRightChild();

    // Destructor
    ~TreeNode();
};

// -----------------------------------------------------
// Tree Class Template
// -----------------------------------------------------
template <typename T>
class Tree
{
private:
    TreeNode<T>* _root;

    // Helpers (private recursive functions)
    TreeNode<T>* _find(TreeNode<T>* node, T value);
    void _printPreOrder(TreeNode<T>* node) const;
    void _printPostOrder(TreeNode<T>* node) const;
    int _countNodes(TreeNode<T>* node) const;
    int _getHeight(TreeNode<T>* node) const;
    void _clear(TreeNode<T>* node);

public:
    Tree();
    Tree(T val);
    ~Tree();

    void setRoot(T value);
    T getRootValue() const;

    bool isEmpty() const;

    TreeNode<T>* find(T value);

    void addChild(T value); // Insert as binary tree (first available place)
    void printPreOrder() const;
    void printPostOrder() const;
    void printLevelOrder() const;

    int countNodes() const;
    int getHeight() const;
};

// -----------------------------------------------------
// Implementation of TreeNode
// -----------------------------------------------------
template <typename T>
TreeNode<T>::TreeNode(T val) : _value(val), _left(nullptr), _right(nullptr),_color(_RED) {}

template <typename T>
TreeNode<T>::TreeNode(T val, TreeNode<T>* left, TreeNode<T>* right)
    : _value(val), _left(left), _right(right),_color(_RED) {}

template <typename T>
T TreeNode<T>::getValue() const { return _value; }

template <typename T>
void TreeNode<T>::setValue(T val) { _value = val; }

template <typename T>
void TreeNode<T>::setColor(NodeColor color) { _color = color; }

template <typename T>
TreeNode<T>* TreeNode<T>::getLeft() const { return _left; }

template <typename T>
TreeNode<T>* TreeNode<T>::getRight() const { return _right; }

template <typename T>
bool TreeNode<T>::hasLeftChild() const { return _left != nullptr; }

template <typename T>
bool TreeNode<T>::hasRightChild() const { return _right != nullptr; }

template <typename T>
bool TreeNode<T>::hasChildren() const { return _left != nullptr || _right != nullptr; }

template <typename T>
bool TreeNode<T>::addLeftChild(T value)
{
    if (_left == nullptr)
    {
        _left = new TreeNode<T>(value);
        return true;
    }
    return false;
}

template <typename T>
bool TreeNode<T>::addRightChild(T value)
{
    if (_right == nullptr)
    {
        _right = new TreeNode<T>(value);
        return true;
    }
    return false;
}

template <typename T>
bool TreeNode<T>::removeLeftChild()
{
    if (_left != nullptr)
    {
        delete _left;
        _left = nullptr;
        return true;
    }
    return false;
}

template <typename T>
bool TreeNode<T>::removeRightChild()
{
    if (_right != nullptr)
    {
        delete _right;
        _right = nullptr;
        return true;
    }
    return false;
}

template <typename T>
TreeNode<T>::~TreeNode()
{
    delete _left;
    delete _right;
}

// -----------------------------------------------------
// Implementation of Tree
// -----------------------------------------------------
template <typename T>
Tree<T>::Tree() : _root(nullptr) {}

template <typename T>
Tree<T>::Tree(T value)
{
    _root = new TreeNode<T>(value);
}

template <typename T>
Tree<T>::~Tree()
{
    _clear(_root);
}

template <typename T>
void Tree<T>::setRoot(T value)
{
    if (_root != nullptr)
        _clear(_root);
    _root = new TreeNode<T>(value);
}


template <typename T>
T Tree<T>::getRootValue() const
{
    if (_root == nullptr)
        throw std::runtime_error("Tree is empty");
    return _root->getValue();
}

template <typename T>
bool Tree<T>::isEmpty() const
{
    return _root == nullptr;
}

template <typename T>
TreeNode<T>* Tree<T>::_find(TreeNode<T>* node, T value)
{

    if (node == nullptr)
        return nullptr;
    
    // Set Node as treated
    node->setColor(_BLACK);
    
    if (node->getValue() == value)
        return node;

    TreeNode<T>* found = _find(node->getLeft(), value);
    if (found != nullptr)
        return found;

    return _find(node->getRight(), value);
}

template <typename T>
TreeNode<T>* Tree<T>::find(T value)
{
    return _find(_root, value);
}

template <typename T>
void Tree<T>::addChild(T value)
{
    TreeNode<T>* newNode = new TreeNode<T>(value);
    if (_root == nullptr)
    {
        _root = newNode;
        return;
    }

    // Breadth-first insertion (first free spot)
    std::queue<TreeNode<T>*> q;
    q.push(_root);

    while (!q.empty())
    {
        TreeNode<T>* current = q.front();
        q.pop();


        if (current->addLeftChild(value))
            return;
        else if (current->addRightChild(value))
            return;
        else
        {
            if (current->getLeft() != nullptr)
                q.push(current->getLeft());
            if (current->getRight() != nullptr)
                q.push(current->getRight());
        }
    }
}

template <typename T>
void Tree<T>::_printPreOrder(TreeNode<T>* node) const
{
    if (node == nullptr)
        return;
    std::cout << node->getValue() << " ";
    _printPreOrder(node->getLeft());
    _printPreOrder(node->getRight());
}

template <typename T>
void Tree<T>::_printPostOrder(TreeNode<T>* node) const
{
    if (node == nullptr)
        return;
    _printPostOrder(node->getLeft());
    _printPostOrder(node->getRight());
    std::cout << node->getValue() << " ";
}

template <typename T>
void Tree<T>::printPreOrder() const
{
    _printPreOrder(_root);
    std::cout << std::endl;
}

template <typename T>
void Tree<T>::printPostOrder() const
{
    _printPostOrder(_root);
    std::cout << std::endl;
}

template <typename T>
void Tree<T>::printLevelOrder() const
{
    if (_root == nullptr)
        return;

    std::queue<TreeNode<T>*> q;
    q.push(_root);

    while (!q.empty())
    {
        TreeNode<T>* current = q.front();
        q.pop();

        std::cout << current->getValue() << " ";

        if (current->getLeft() != nullptr)
            q.push(current->getLeft());
        if (current->getRight() != nullptr)
            q.push(current->getRight());
    }

    std::cout << std::endl;
}

template <typename T>
int Tree<T>::_countNodes(TreeNode<T>* node) const
{
    if (node == nullptr)
        return 0;
    return 1 + _countNodes(node->getLeft()) + _countNodes(node->getRight());
}

template <typename T>
int Tree<T>::countNodes() const
{
    return _countNodes(_root);
}

template <typename T>
int Tree<T>::_getHeight(TreeNode<T>* node) const
{
    if (node == nullptr)
        return 0;
    int leftH = _getHeight(node->getLeft());
    int rightH = _getHeight(node->getRight());
    return 1 + ((leftH > rightH) ? leftH : rightH);
}

template <typename T>
int Tree<T>::getHeight() const
{
    return _getHeight(_root);
}

template <typename T>
void Tree<T>::_clear(TreeNode<T>* node)
{
    if (node == nullptr)
        return;
    _clear(node->getLeft());
    _clear(node->getRight());
    delete node;
}
