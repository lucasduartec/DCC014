/**************************************************************************************************
 * Implementation of the TAD Node
 **************************************************************************************************/

#include <list>

using namespace std;

// Definição da classe nó

class TreeNode
{

private:
    TreeNode *father;
    TreeNode *topChild;
    TreeNode *leftChild;
    TreeNode *downChild;
    TreeNode *rightChild;

public:
    // Construtor
    TreeNode();

    // Destrutor
    ~TreeNode();

    // Getters
    TreeNode *getFather();
    TreeNode *getTopChild();
    TreeNode *getLeftChild();
    TreeNode *getDownChild();
    TreeNode *getRightChild();

    // Setters
    void setFather(TreeNode *node);
    void setTopChild(TreeNode *node);
    void setLeftChild(TreeNode *node);
    void setDownChild(TreeNode *node);
    void setRightChild(TreeNode *node);
};

// Construtor
TreeNode::TreeNode(){};

// Destrutor
TreeNode::~TreeNode()
{
    this->father = nullptr;
    this->topChild = nullptr;
    this->leftChild = nullptr;
    this->downChild = nullptr;
    this->rightChild = nullptr;
};

// Getters
TreeNode *TreeNode::getFather()
{
    return this->father;
}

TreeNode *TreeNode::getTopChild()
{
    return this->topChild;
}

TreeNode *TreeNode::getLeftChild()
{
    return this->leftChild;
}

TreeNode *TreeNode::getDownChild()
{
    return this->downChild;
}

TreeNode *TreeNode::getRightChild()
{
    return this->rightChild;
}

// Setters

void TreeNode::setFather(TreeNode *node)
{
    this->father = node;
}

void TreeNode::setTopChild(TreeNode *node)
{
    this->topChild = node;
}

void TreeNode::setLeftChild(TreeNode *node)
{
    this->leftChild = node;
}

void TreeNode::setDownChild(TreeNode *node)
{
    this->downChild = node;
}

void TreeNode::setRightChild(TreeNode *node)
{
    this->rightChild = node;
}