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