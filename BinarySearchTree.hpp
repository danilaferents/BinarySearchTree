#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp
#include <stdio.h>
using namespace std;
namespace BinarySearchTree
{
    class Node
    {
        private:
        void *key;
        Node *left;
        Node *right;
        Node *parent;
        public:

        //constructors
        Node(void *_key) : key(_key), left(nullptr), right(nullptr), parent(nullptr) {}
        Node() : key(nullptr), left(nullptr), right(nullptr), parent(nullptr){}

        //Setting values to variables functions
        void SetLeftNode(Node *_left);
        void SetRightNode(Node *_right);
        void SetKeyToNode(void *_key);
        void SetParentToNode(Node *_parent);

        //Getting values from variables functions
        Node *GetLeftNode();
        Node *GetRightNode();
        Node *GetParentNode();
        void *GetKeyFromNode();

        //Printing nodes functions
        void PrintNode();
        void PrintThis(int space_counter); 

        //Changing alues in variables functions
        void ChangeParent(Node **changingnode);
        void ChangeLeft(Node **changingnode,Node *change);
        void ChangeRight(Node **changingnode,Node *change);
    }; 

    class Tree
    {
        private:
        Node *head;
        public:

        //constructors
        Tree() : head(nullptr) {}
        Tree(void *key);

        //Get head from the tree functions
        Node* GetHead();

        //Adding new nodes to our tree functions
        void AddCoupleNodesToTree(string input);
        void AddCoupleNodesToTree2(vector <int>);
        void AddGlobalNodeToTree(Node*);
        void AddNodeToTree(void *_key);

        //Tree traversals functions
        void InOrder(Node *help,vector<int>*);
        vector<int*> BFS();
        void PreOrder(Node *help);

        //Printing our tree function
        void PrintTree();

        //Searching nodes in tree functions
        Node *SearchNodeAndPutOut(void *_key);
        bool SearchNode(void *_key);
        bool SearchNodeInt(int _key);

        //helping functions
        void FindMaxSmallerInRightSubTree(int key,int *ourkey,Node *help); 
        void FindMinHigherInLefttSubTree(int key,int *ourkey,Node *help);
        Node * FindNode(void *_key); //help to find deleting node when node has two sons
        Node * FindMin(Node *min); //finding the smallest node in all tree
        Node * FindMax(Node *max); //finding the biggest node in all tree

        void FindQueye(vector<pair<int,int> > *_queye); //finding borders to every node to  add new 
        void AddBoards(vector<pair<int,int> > *_queye); //finding nodes to the smallest and biggest nodes
        Node* MadeTree(vector<int> tree,size_t left, size_t right,Node*); //Function makes balanced tree from vector

        //deletting node and free tree functions
        Node *DeleteNode(void *_key);
        void Free(Node *help);

        //destructors
        ~Tree();
        
    };
}
#endif
