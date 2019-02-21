#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stack>
#include "BinarySearchTree.hpp"
using namespace BinarySearchTree;

//Setting values to variables functions
    void Node::SetLeftNode(Node *_left)
    {
        left=_left;
    }
    void Node::SetRightNode(Node *_right)
    {
        right=_right;
    }
    void Node::SetKeyToNode(void *_key)
    {
        key=_key;
    }
    void Node::SetParentToNode(Node *_parent)
    {
        parent=_parent;
    }

//Getting values from variables functions
    Node *Node::GetLeftNode()
    {
        return left;
    }
    Node *Node::GetRightNode()
    {
        return right;
    }
    Node *Node::GetParentNode()
    {
        return parent;
    }
    void *Node::GetKeyFromNode()
    {
        return key;
    }

//Printing nodes functions
      void Node::PrintNode()
    {
        cout<<"key:"; if (key) cout<<*(int*)key<<endl;
        cout<<"left:"; if (left) cout<<"1"<<endl; else cout<<"0"<<endl;
        cout<<"right:"; if (right) cout<<"1"<<endl; else cout<<"0"<<endl;
        cout<<"parent:"; if (parent) cout<<"1"<<endl; else cout<<"0"<<endl;
    }
        void Node::PrintThis(int space_counter) 
    {
        if (key != nullptr)
         {
            string s;
            for (int i=0;i<space_counter;i++)
                s+="  ";
            std::cout << s << *(int*)(key) << "\n";
        }
        else
        {
            std::cout << "NO_DATA\n";
        }
        //PrintNode();
        if (left != nullptr) 
        {
            left->PrintThis(space_counter + 1);
        }

        if (right != nullptr) 
        {
            right->PrintThis(space_counter + 1);
        }
    }

//Changing alues in variables functions
    void Node::ChangeParent(Node **changingnode)
    {
        ((*changingnode)->parent)=parent;
    }
    void Node::ChangeLeft(Node **changingnode,Node *change)
    {
        (*changingnode)->left=change;
    }
    void Node::ChangeRight(Node **changingnode,Node *change)
    {
        (*changingnode)->right=change;
    }
//constructor
Tree::Tree(void *key)
{
    Node *_Node= new Node(key);
    head=_Node;
}


Node* Tree::GetHead()
{
    return head;
}

//Tree traversals functions
void Tree::InOrder(Node *help,vector<int> *keys)
{
    if(help)
    {
        if (help->GetLeftNode())   InOrder(help->GetLeftNode(),keys);
        //for(int i = 0;i < level; i++) cout<<"   ";
        keys->push_back(*(int*)(help->GetKeyFromNode()));
        if(help->GetRightNode()) InOrder(help->GetRightNode(),keys);
    }
}
void Tree::PreOrder(Node *help)     //Print and go to the left
{
    if(help)
    {
        //for(int i = 0;i < level; i++) cout<<"   ";
        cout << *(int*)(help->GetKeyFromNode())<<" ";
        if (help->GetLeftNode()) PreOrder(help->GetLeftNode());
        if(help->GetRightNode()) PreOrder(help->GetRightNode());
    }
}
vector<int*> Tree::BFS()
{
    queue<Node*> output;
    vector<int*> keys;
    Node *help;
    output.push(head);
    while(output.size() > 0)
    {
        help=output.front();
        output.pop();
        keys.push_back((int*)help->GetKeyFromNode());
        
        if(help->GetLeftNode())
        {
            output.push(help->GetLeftNode());
        }
        if (help->GetRightNode())
        {
            output.push(help->GetRightNode());
        }
    }
    return keys;
}

//Printing our tree function
void Tree::PrintTree()
{
    queue<Node*> output;
    int levelleft=0,levelright=0;
    Node *help;
    output.push(head);
    while(output.size() > 0)
    {
        help=output.front();
        output.pop();
        if (*(int*)(help->GetKeyFromNode()) < *(int*)(head->GetKeyFromNode()))
        {
            for(int i = 0;i < levelleft; i++) cout<<"*";
             cout<<*(int*)help->GetKeyFromNode();
             cout<<endl;
             //if(help->GetLeftNode() || (help->GetRightNode())) 
             levelleft++;
             if ((help->GetParentNode()->GetRightNode()) && (help->GetParentNode()->GetLeftNode()) && (help->GetParentNode()!=head) && (help==help->GetParentNode()->GetLeftNode()))
                levelleft--;
        }
        else if(*(int*)(help->GetKeyFromNode()) > *(int*)(head->GetKeyFromNode()))
        {
            for(int i = 0;i < levelright; i++) cout<<"*";
             cout<<*(int*)help->GetKeyFromNode();
             cout<<endl;
             //if(help->GetLeftNode() || (help->GetRightNode())) 
                levelright++;
             if ((help->GetParentNode()->GetRightNode()) && (help->GetParentNode()->GetLeftNode()) && (help->GetParentNode()!=head) && (help==help->GetParentNode()->GetLeftNode()))
                levelright--;
        }
        else  
        {
            cout<<*(int*)help->GetKeyFromNode()<<endl;
            levelright++;
            levelleft++;
        }
        if(help->GetLeftNode())
        {
            output.push(help->GetLeftNode());
        }
        if (help->GetRightNode())
        {
            output.push(help->GetRightNode());
        }
    }
}

//Adding new nodes to our tree functions
void  Tree::AddNodeToTree(void *_key)
{
    if (!SearchNode(_key) && (_key))
    {
        Node *New=new Node(_key);
        Node *help;
        Node *helpparent;
        //cout<<*(int*)_key<<endl;
        if(head==nullptr)
        {
            //printf("Here i was(1)");
            head=New;
        }
        else
        {
            help=head;
            //cout<<"WTF1"<<(*(int*)head->GetKeyFromNode())<<endl;
            while (help)
            {
                helpparent=help;
                //cout<<"WTF"<<(*(int*)help->GetKeyFromNode())<<endl;
                if ((*(int*)help->GetKeyFromNode()) < (*(int*)_key))
                {
                    help=help->GetRightNode();
                    //printf("Here i was(2)");
                }
                else if ((*(int*)help->GetKeyFromNode()) > (*(int*)_key))
                {
                    help=help->GetLeftNode();
                    //printf("Here i was(3)");
                }
                else return;
            }
            New->SetParentToNode(helpparent);
            if ((*(int*)helpparent->GetKeyFromNode()) < (*(int*)_key))
            {
                helpparent->SetRightNode(New);
                //printf("Here i was(4)");
            }
            else if ((*(int*)helpparent->GetKeyFromNode()) > (*(int*)_key))
            {
                helpparent->SetLeftNode(New);
                //printf("Here i was(5)");
            }
            else return;
        }
    }
}
void  Tree::AddGlobalNodeToTree(Node *ournode)
{
    int *_key=(int*)ournode->GetKeyFromNode();
        //Node *New=new Node(_key);
        Node *help;
        Node *helpparent;
        //cout<<*(int*)_key<<endl;
        if(head==nullptr)
        {
            //printf("Here i was(1)");
            head=ournode;
        }
        else
        {
            help=head;
            //cout<<"WTF1"<<(*(int*)head->GetKeyFromNode())<<endl;
            while (help)
            {
                helpparent=help;
                //cout<<"WTF"<<(*(int*)help->GetKeyFromNode())<<endl;
                if ((*(int*)help->GetKeyFromNode()) < *(_key))
                {
                    help=help->GetRightNode();
                    //printf("Here i was(2)");
                }
                else if ((*(int*)help->GetKeyFromNode()) > *(_key))
                {
                    help=help->GetLeftNode();
                    //printf("Here i was(3)");
                }
                else return;
            }
            ournode->SetParentToNode(helpparent);
            if ((*(int*)helpparent->GetKeyFromNode()) < *(_key))
            {
                helpparent->SetRightNode(ournode);
                //printf("Here i was(4)");
            }
            else if ((*(int*)helpparent->GetKeyFromNode()) > *(_key))
            {
                helpparent->SetLeftNode(ournode);
                //printf("Here i was(5)");
            }
            else return;
        }
}
void  Tree::AddCoupleNodesToTree(string input)
{        //cout<<"length"<<input.length();
    int i=0;
    while(i!=input.length())
    {
        //cout<<"Enter"<<i<<endl;
        string helpstring;
        int *helpint=new int;
        while((input[i]!=' ') && (i!=input.length()))
        {
            //cout<<"EnterSec"<<i<<endl;
            helpstring+=input[i];
            i++;
        }
        *helpint = atoi (helpstring.c_str());
        AddNodeToTree(helpint);
        //cout<<*helpint;
        if (input[i] == ' ')i++;
    }
}
void Tree::AddCoupleNodesToTree2(vector<int> help)
{
    vector<pair<int,int> > border;
    FindQueye(&border);
    for (auto & pair : border)
    {
        //cout<<pair.first<<" "<<pair.second<<endl;
        vector<int> everypair;
        for (int i=0;i<help.size();i++)
        {
            if((help[i] <= pair.second) && (help[i] >= pair.first) && (!SearchNodeInt(help[i])))
            {
                everypair.push_back(help[i]);
            }

        }
        if (everypair.size() != 0)
        {
            //reverse(everypair.begin(),everypair.end());
           /* for (int i=0;i<everypair.size()-1;i++)
                cout<<everypair[i];
            cout<<endl;*/
            Node *helpnode;
            if (everypair.size() != 0)
            helpnode=MadeTree(everypair,0,everypair.size()-1,NULL);
            AddGlobalNodeToTree(helpnode);
        }       
    }
}

//Searching nodes in tree functions
bool Tree::SearchNode(void *_key)
{
    Node *help;
    help=head;
    while(help)
    {
        if(*(int*)_key == (*(int*)help->GetKeyFromNode())) return true;
        else if(*(int*)_key < (*(int*)help->GetKeyFromNode()))
        {
            if (help->GetLeftNode())
            {
                help=help->GetLeftNode();
            }
            else return false;
        }
        else
        {
            if (help->GetRightNode())
            {
                help=help->GetRightNode();
            }
            else return false;
        }
    }
    return false;
}
bool Tree::SearchNodeInt(int _key)
{
    Node *help;
    help=head;
    while(help)
    {
        if(_key == (*(int*)help->GetKeyFromNode())) return true;
        else if(_key < (*(int*)help->GetKeyFromNode()))
        {
            if (help->GetLeftNode())
            {
                help=help->GetLeftNode();
            }
            else return false;
        }
        else
        {
            if (help->GetRightNode())
            {
                help=help->GetRightNode();
            }
            else return false;
        }
    }
    return false;
}
Node *Tree::SearchNodeAndPutOut(void *_key)
{
    Node *help;
    help=head;
    while(help)
    {
        if(*(int*)_key == (*(int*)help->GetKeyFromNode())) return help;
        else if(*(int*)_key < (*(int*)help->GetKeyFromNode()))
        {
            if (help->GetLeftNode())
            {
                help=help->GetLeftNode();
            }
            else return nullptr;
        }
        else
        {
            if (help->GetRightNode())
            {
                help=help->GetRightNode();
            }
            else return nullptr;
        }
    }
    return nullptr;
}

//helping functions
void Tree::FindMaxSmallerInRightSubTree(int key,int *ourkey,Node *help)
{
    if(help)
    {
        if (help->GetLeftNode())   FindMaxSmallerInRightSubTree(key,ourkey,help->GetLeftNode());
        if ((*(int*)(help->GetKeyFromNode()) < key ) && (*(int*)(help->GetKeyFromNode()) > *ourkey)) 
        {
            *ourkey=*(int*)(help->GetKeyFromNode());
        }
        if (help->GetRightNode()) FindMaxSmallerInRightSubTree(key,ourkey,help->GetRightNode());
    }
}
void Tree::FindMinHigherInLefttSubTree(int key,int *ourkey,Node *help)
{
    if(help)
    {
        if (help->GetLeftNode())   FindMaxSmallerInRightSubTree(key,ourkey,help->GetLeftNode());
        if ((*(int*)(help->GetKeyFromNode()) > key ) && (*(int*)(help->GetKeyFromNode()) < *ourkey)) 
        {
            *ourkey=*(int*)(help->GetKeyFromNode());
        }
        if (help->GetRightNode()) FindMaxSmallerInRightSubTree(key,ourkey,help->GetRightNode());
    }
}
Node *Tree::FindNode(void *_key)
{
    Node *help=SearchNodeAndPutOut(_key);
    Node *necessarynode;
    if(help == nullptr)
        return nullptr;
    if (help->GetRightNode() != nullptr)
        return FindMin(help->GetRightNode());
    necessarynode=help->GetParentNode();
    while(necessarynode!=nullptr && help == necessarynode->GetRightNode())
    {
        help=necessarynode;
        necessarynode=necessarynode->GetParentNode();
    }
    return necessarynode;
}
Node * Tree::FindMin(Node *min)
{
    while(min->GetLeftNode() != nullptr)
        min=min->GetLeftNode();
    return min;
}
Node * Tree::FindMax(Node *max)
{
    while(max->GetRightNode() != nullptr)
        max=max->GetRightNode();
    return max;
}

//
void Tree::AddBoards(vector<pair<int,int> > *_queye)
{
    Node *help=head;
    while(help->GetLeftNode()) help=help->GetLeftNode();
    _queye->push_back(make_pair((-20000000),*(int*)(help->GetKeyFromNode())));
    help=nullptr;
    Node *help1=head;
    while(help1->GetRightNode()) help1=help1->GetRightNode();
    _queye->push_back(make_pair(*(int*)(help1->GetKeyFromNode()),2147483647));
    help1=nullptr;
    //delete(help1);
}
void Tree::FindQueye(vector<pair<int,int> > *_queye)
{
    queue<Node*> output;
    Node *help;
    output.push(head);
    AddBoards(_queye);
    while(output.size() > 0)
    {
        help=output.front();
        output.pop();
        Node* help1,*help2;
        help1=FindMin(head);
        help2=FindMax(head);
        //cout<<*(int*)(help1->GetKeyFromNode())<<" "<<*(int*)(help2->GetKeyFromNode())<<endl;

            if (*(int*)(help->GetKeyFromNode()) < *(int*)(head->GetKeyFromNode()))
            {
                if ((help->GetLeftNode()) == nullptr) 
                    if (*(int*)(help->GetKeyFromNode()) != *(int*) (help1->GetKeyFromNode()))
                      _queye->push_back(make_pair(*(int*)(help->GetParentNode()->GetKeyFromNode()),*(int*)(help->GetKeyFromNode())));
                if (help->GetRightNode() == nullptr)
                {
                    int *newkey=new int();
                    *newkey=*(int*)head->GetKeyFromNode();
                    FindMinHigherInLefttSubTree(*(int*)(help->GetKeyFromNode()),newkey,head->GetLeftNode());
                    _queye->push_back(make_pair(*(int*)help->GetKeyFromNode(),*newkey));
                    delete(newkey);
                }
            }
            else 
            {
               if ((help->GetRightNode()) == nullptr) 
                  if (*(int*)(help->GetKeyFromNode()) != *(int*)(help2->GetKeyFromNode()))
                    _queye->push_back(make_pair(*(int*)(help->GetKeyFromNode()),*(int*)(help->GetParentNode()->GetKeyFromNode())));
                if (help->GetLeftNode() == nullptr)
                {
                    int *newkey=new int();
                    *newkey=*(int*)head->GetKeyFromNode();
                    FindMaxSmallerInRightSubTree(*(int*)(help->GetKeyFromNode()),newkey,head->GetRightNode());
                    _queye->push_back(make_pair(*newkey,*(int*)help->GetKeyFromNode()));
                    delete(newkey);
                }
            }
           if(help->GetLeftNode())
            {
                 output.push(help->GetLeftNode());
            }
            if (help->GetRightNode())
            {
                 output.push(help->GetRightNode());
            }  
    }
}
Node* Tree::MadeTree(vector<int> tree,size_t left, size_t right,Node *parent)
{
    if((left > right) || (left < 0 ) || (right>tree.size()))  
    {
        return nullptr;
    }
    if (left==right)
    {
        Node *newnode= new (Node);
        int *newkey=new (int);
        *newkey=tree[left];
        newnode->SetKeyToNode(newkey);
        newnode->SetParentToNode(parent);
        return  newnode;        
    }
    int middle=(left+right)/2;
    Node *newhead=new (Node);
    int *newkey1=new (int);
    *newkey1=tree[middle];
    if (!((newhead->GetLeftNode()) && (newhead->GetRightNode()))) 
    parent=newhead;
    newhead->SetParentToNode(parent);
    newhead->SetKeyToNode(newkey1);
    newhead->SetLeftNode(MadeTree(tree,left,middle - 1,parent));
    newhead->SetRightNode(MadeTree(tree,middle + 1,right,parent));
    //head=newhead;
    return newhead;
}

//deletting node and free tree functions
Node * Tree::DeleteNode(void *_key)
{
    Node *help=nullptr,*helpchild=nullptr,*helpanother=nullptr;
    help=SearchNodeAndPutOut(_key);
    if (help)
    {
        if((help->GetLeftNode() == nullptr)||(help->GetRightNode() == nullptr)) helpchild=help;
        else
                helpchild=FindNode(help->GetKeyFromNode());
        if(helpchild->GetLeftNode()!=nullptr)
            helpanother=helpchild->GetLeftNode();
        else
            helpanother=helpchild->GetRightNode();
        if(helpanother!=nullptr)
        {
            helpanother->ChangeParent(&helpanother);
        }
        if(helpchild->GetParentNode() == nullptr)
            head=helpanother;
        else
        {
            if (helpchild == (helpchild->GetParentNode())->GetLeftNode())
            {
                Node *helpextra=helpchild->GetParentNode();
                helpchild->ChangeLeft(&helpextra,helpanother);
            }
            else
            {
                Node *helpextra=helpchild->GetParentNode();
                helpchild->ChangeRight(&helpextra,helpanother);
            }
        }
        if(helpchild!=help)
            help->SetKeyToNode(helpchild->GetKeyFromNode());
    }
    return helpchild;
}
void Tree::Free(Node *help)
{
    if (help->GetLeftNode())
    {
        Free(help->GetLeftNode());
    }
    if (help->GetRightNode())
    {
        Free(help->GetRightNode());
    }
    delete((int*)(help->GetKeyFromNode()));
    delete help;
    help=nullptr;
}

// деструктор нормальную вставку 

int main()
{          
         Tree NewTree;
         Node *newnode;
         int *value1= new (int);
         *value1=10;
         NewTree.AddNodeToTree(value1);
         int *value2= new (int);
         *value2=5;
         NewTree.AddNodeToTree(value2);
         int *value3= new (int);
         *value3=20;
         NewTree.AddNodeToTree(value3);
         int *value4= new (int);
         *value4=15;
         NewTree.AddNodeToTree(value4);
         int *value5= new (int);
         *value5=30;
         NewTree.AddNodeToTree(value5);
         int *value6= new (int);
         *value6=25;
         NewTree.AddNodeToTree(value6);
         int *value7= new (int);
         *value7=24;
         NewTree.AddNodeToTree(value7);
         vector<pair<int,int> > newqueye;
         cout<<endl;
    
         vector <int> newtree;
         newtree.push_back(1);
         newtree.push_back(3);
         newtree.push_back(5);
         newtree.push_back(7);
         NewTree.AddCoupleNodesToTree2(newtree);
         (NewTree).GetHead()->PrintThis(0);
         
/*
        Tree NewTree;
         Node *newnode;
         int *value1= new (int);
         *value1=50;
         NewTree.AddNodeToTree(value1);
         int *value2= new (int);
         *value2=30;
         NewTree.AddNodeToTree(value2);
         int *value3= new (int);
         *value3=55;
         NewTree.AddNodeToTree(value3);
         int *value4= new (int);
         *value4=25;
         NewTree.AddNodeToTree(value4);
         int *value5= new (int);
         *value5=35;
         NewTree.AddNodeToTree(value5);
         int *value6= new (int);
         *value6=53;
         NewTree.AddNodeToTree(value6);
         vector<pair<int,int> > newqueye;
         cout<<endl;
    
         vector <int> newtree;
         newtree.push_back(10);
         newtree.push_back(15);
         newtree.push_back(30);
         newtree.push_back(37);
         newtree.push_back(53);
         newtree.push_back(60);
         newtree.push_back(62);
         NewTree.AddCoupleNodesToTree2(newtree);
         (NewTree).GetHead()->PrintThis(0);*/
/*
         Tree NewTree;
         Node *newnode;
         int *value1= new (int);
         *value1=8;
         NewTree.AddNodeToTree(value1);
         int *value2= new (int);
         *value2=3;
         NewTree.AddNodeToTree(value2);
         int *value3= new (int);
         *value3=10;
         NewTree.AddNodeToTree(value3);
         int *value4= new (int);
         *value4=1;
         NewTree.AddNodeToTree(value4);
         vector<pair<int,int> > newqueye;
         cout<<endl;
         vector <int> newtree;
         newtree.push_back(4);
         newtree.push_back(6);
         newtree.push_back(7);
         newtree.push_back(13);
         newtree.push_back(14);
         newtree.push_back(15);
         NewTree.AddCoupleNodesToTree2(newtree);
         (NewTree).GetHead()->PrintThis(0);*/
         //NewTree.PrintTree();
        /*
         vector <int> newtree;
         newtree.push_back(10);
         newtree.push_back(11);
         newtree.push_back(12);
         newtree.push_back(15);
         NewTree.AddCoupleNodesToTree2(newtree);
    
         NewTree.PrintTree();*/
        //  NewTree.Free(NewTree.GetHead()); 
}
