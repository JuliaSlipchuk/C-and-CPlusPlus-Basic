#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Node
{
    public:
    int value;
    Node* leftChild;
    Node* rightChild;
    Node(int val)
    {
        this->value = val;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};
class BinaryTree
{
public:
    Node* root;
    BinaryTree(Node* root)
    {
        this->root = root;
    }
    Node* insert(Node* node, int val)
    {
        if (node == nullptr)
            return new Node(val);
        else if (val < node->value)
            node->leftChild = insert(node->leftChild, val);
        else if (val > node->value)
            node->rightChild = insert(node->rightChild, val);
        return node;
    }
};
class InOrder : public BinaryTree
{
public:
    InOrder(Node* node) : BinaryTree(node) {}
    void InOrderGo(Node* node)
    {
        if (node != nullptr)
        {
            InOrderGo(node->leftChild);
            cout << node->value << " ";
            InOrderGo(node->rightChild);
        }
    }
    static void HelpForOperator(vector<Node*> &vector, Node* node)
    {
        if (node != nullptr)
        {
            HelpForOperator(vector, node->leftChild);
            vector.push_back(node);
            HelpForOperator(vector, node->rightChild);
        }
    }
    Node* operator [] (int index)
    {
        vector<Node*> nodes;
        Node* node = this->root;
        InOrder::HelpForOperator(nodes, node);
        for (int i = 0; i < nodes.size(); i++)
        {
            if (i == index)
            {
                return nodes[i];
            }
        }
        throw "Element of this index does not exist";
    }
};
ostream& operator << (ostream &os, InOrder &iO)
{
    Node* node = iO.root;
    iO.InOrderGo(node);
    return os;
}
class PreOrder : public BinaryTree
{
public:
    PreOrder(Node* node) : BinaryTree(node) {}
    void PreOrderGo(Node* node)
    {
        if (node != nullptr)
        {
            PreOrderGo(node->leftChild);
            PreOrderGo(node->rightChild);
            cout << node->value << " ";
        }
    }
    static void HelpForOperator(vector<Node*> &vector, Node* node)
    {
        if (node != nullptr)
        {
            vector.push_back(node);
            HelpForOperator(vector, node->leftChild);
            HelpForOperator(vector, node->rightChild);
        }
    }
    Node* operator [] (int index)
    {
        vector<Node*> nodes;
        Node* node = this->root;
        InOrder::HelpForOperator(nodes, node);
        for (int i = 0; i < nodes.size(); i++)
        {
            if (i == index)
            {
                return nodes[i];
            }
        }
        throw "Element of this index does not exist";
    }
};
ostream& operator << (ostream &os, PreOrder &pO)
{
    Node* node = pO.root;
    pO.PreOrderGo(node);
    return os;
}
class PostOrder : public BinaryTree
{
public:
    PostOrder(Node* node) : BinaryTree(node) {}
    void PostOrderGo(Node* node)
    {
        if (node != nullptr)
        {
            cout << node->value << " ";
            PostOrderGo(node->leftChild);
            PostOrderGo(node->rightChild);
        }
    }
    static void HelpForOperator(vector<Node*> &vector, Node* node)
    {
        if (node != nullptr)
        {
            HelpForOperator(vector, node->leftChild);
            HelpForOperator(vector, node->rightChild);
            vector.push_back(node);
        }
    }
    Node* operator [] (int index)
    {
        vector<Node*> nodes;
        Node* node = this->root;
        InOrder::HelpForOperator(nodes, node);
        for (int i = 0; i < nodes.size(); i++)
        {
            if (i == index)
            {
                return nodes[i];
            }
        }
        throw "Element of this index does not exist";
    }
};
ostream& operator << (ostream &os, PostOrder &pO)
{
    Node* node = pO.root;
    pO.PostOrderGo(node);
    return os;
}


int main()
{

    Node* root1 = new Node(3);
    InOrder* inOrder = new InOrder(root1);
    Node* root2 = new Node(3);
    PreOrder* preOrder = new PreOrder(root2);
    Node* root3 = new Node(3);
    PostOrder* postOrder = new PostOrder(root3);

    try
    {
        inOrder->insert(inOrder->root, 5);
        inOrder->insert(inOrder->root, 6);
        inOrder->insert(inOrder->root, 1);
        cout << "\n Inorder: ";
        cout << *inOrder;

        preOrder->insert(preOrder->root, 5);
        preOrder->insert(preOrder->root, 6);
        preOrder->insert(preOrder->root, 1);
        cout << "\n Preorder: ";
        cout << *preOrder;

        postOrder->insert(postOrder->root, 5);
        postOrder->insert(postOrder->root, 6);
        postOrder->insert(postOrder->root, 1);
        cout << "\n PostOrder: ";
        cout << *postOrder;
    }
    catch (exception &e)
    {
        cout << e.what();
    }

    return 0;
}
