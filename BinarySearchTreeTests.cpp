#include <iostream>
#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "BinarySearchTree.hpp"
using namespace BinarySearchTree;
namespace  {
    TEST(TestsBinarySearchTree,TestAddNodeToTree1)
    {
        Tree NewTree;
        int *value= new (int);
        *value=5;
        NewTree.AddNodeToTree(value);
        ASSERT_EQ(5,*(int*)NewTree.GetHead()->GetKeyFromNode());
        Node *help=NewTree.GetHead();
        NewTree.Free(help);
    }
    TEST(TestsBinarySearchTree,TestFindMaxSmallerInRightSubTree)
    {
         Tree NewTree;
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
         int *ourkey=new (int);
         *ourkey=10;
         NewTree.FindMaxSmallerInRightSubTree(*value7,ourkey,NewTree.GetHead()->GetRightNode());
         ASSERT_EQ(20,*ourkey);
         NewTree.Free(NewTree.GetHead());
         delete(ourkey);
    }
    TEST(TestsBinarySearchTree,TestFindMinHigherInLefttSubTree)
    {
         Tree NewTree;
         int *value1= new (int);
         *value1=10;
         NewTree.AddNodeToTree(value1);
         int *value2= new (int);
         *value2=5;
         NewTree.AddNodeToTree(value2);
         int *value3= new (int);
         *value3=3;
         NewTree.AddNodeToTree(value3);
         int *value4= new (int);
         *value4=2;
         NewTree.AddNodeToTree(value4);
         int *value5= new (int);
         *value5=4;
         NewTree.AddNodeToTree(value5);
         int *ourkey=new (int);
         *ourkey=11;
         NewTree.FindMinHigherInLefttSubTree(*value5,ourkey,NewTree.GetHead()->GetLeftNode());
         ASSERT_EQ(5,*ourkey);
         NewTree.Free(NewTree.GetHead());
         delete(ourkey);
    }
    TEST(TestsBinarySearchTree,TestAddNodeToTree2)
    {
         Tree NewTree;
         int *value1= new (int);
         *value1=6;
         NewTree.AddNodeToTree(value1);
         int *value2= new (int);
         *value2=3;
         NewTree.AddNodeToTree(value2);
         int *value3= new (int);
         *value3=10;
         NewTree.AddNodeToTree(value3);
         int *value4= new (int);
         *value4=10;
         NewTree.AddNodeToTree(value4);
         ASSERT_EQ(6,*(int*)NewTree.GetHead()->GetKeyFromNode());
         ASSERT_EQ(10,*(int*)(NewTree.GetHead()->GetRightNode()->GetKeyFromNode()));
         ASSERT_EQ(3,*(int*)(NewTree.GetHead()->GetLeftNode()->GetKeyFromNode()));
         Node *help=NewTree.GetHead();
         NewTree.Free(help);
         delete (value4);
    }
    TEST(TestsBinarySearchTree,TestAddNodeToTree3)
    {
        Tree NewTree;
        int *value1= nullptr;
        NewTree.AddNodeToTree(value1);
    }
    TEST(TestsBinarySearchTree,DeleteNode)
    {
        Tree NewTree;
        int *value1= new (int);
        *value1=6;
        NewTree.AddNodeToTree(value1);
        int *value2= new (int);
        *value2=3;
        NewTree.AddNodeToTree(value2);
        int *value3= new (int);
        *value3=10;
        NewTree.AddNodeToTree(value3);
        ASSERT_EQ(6,*(int*)NewTree.GetHead()->GetKeyFromNode());
        ASSERT_EQ(10,*(int*)(NewTree.GetHead()->GetRightNode()->GetKeyFromNode()));
        ASSERT_EQ(3,*(int*)(NewTree.GetHead()->GetLeftNode()->GetKeyFromNode()));
        //delete((NewTree.DeleteNode(value3))->GetKeyFromNode());
        delete(NewTree.DeleteNode(value3));
        ASSERT_EQ(nullptr,(NewTree.GetHead()->GetRightNode()));
        Node *help=NewTree.GetHead();
        NewTree.Free(help);
        delete (value3);
    }
    TEST(TestsBinarySearchTree,AddCoupleNodesToTree)
    {
        Tree NewTree;
        string newstring="3 5 7 9";
        NewTree.AddCoupleNodesToTree(newstring);
        ASSERT_EQ(3,*(int*)NewTree.GetHead()->GetKeyFromNode());
        ASSERT_EQ(5,*(int*)(NewTree.GetHead()->GetRightNode()->GetKeyFromNode()));
        ASSERT_EQ(nullptr,(NewTree.GetHead()->GetLeftNode()));
        ASSERT_EQ(7,*(int*)(NewTree.GetHead()->GetRightNode()->GetRightNode()->GetKeyFromNode()));
        NewTree.Free(NewTree.GetHead());
    }
    TEST(TestsBinarySearchTree,SearchNode)
    {
        Tree NewTree;
        int *value1= new (int);
        *value1=6;
        NewTree.AddNodeToTree(value1);
        int *value2= new (int);
        *value2=3;
        NewTree.AddNodeToTree(value2);
        int *value3= new (int);
        *value3=10;
        NewTree.AddNodeToTree(value3);
        int *value4= new (int);
        *value4=2;
        ASSERT_EQ(1,NewTree.SearchNode(value3));
        ASSERT_EQ(0,NewTree.SearchNode(value4));
        NewTree.Free(NewTree.GetHead());
        delete (value4);
    }
    TEST(TestsBinarySearchTree,SearchNode2)
    {
        Tree NewTree;
        int *value1= new (int);
        *value1=6;
        NewTree.AddNodeToTree(value1);
        int *value2= new (int);
        *value2=3;
        NewTree.AddNodeToTree(value2);
        int *value3= new (int);
        *value3=10;
        NewTree.AddNodeToTree(value3);
        int *value5= new (int);
        *value5=5;
        ASSERT_EQ(0,NewTree.SearchNode(value5));
        NewTree.Free(NewTree.GetHead());
        delete (value5);
    }
    TEST(TestsBinarySearchTree,SearchNodeANdPutItOut)
    {
        Tree NewTree;
        int *value1= new (int);
        *value1=6;
        NewTree.AddNodeToTree(value1);
        int *value2= new (int);
        *value2=3;
        NewTree.AddNodeToTree(value2);
        int *value3= new (int);
        *value3=10;
        NewTree.AddNodeToTree(value3);
        int *value4= new (int);
        *value4=2;
        ASSERT_EQ((NewTree.GetHead()->GetLeftNode()->GetLeftNode()),(NewTree.SearchNodeAndPutOut(value4)));
        NewTree.Free(NewTree.GetHead());
        delete (value4);
    }
    TEST(TestsBinarySearchTree,FindMin)
    {
        Tree NewTree;
        int *value1= new (int);
        *value1=6;
        NewTree.AddNodeToTree(value1);
        int *value2= new (int);
        *value2=3;
        NewTree.AddNodeToTree(value2);
        int *value3= new (int);
        *value3=10;
        NewTree.AddNodeToTree(value3);
        int *value4= new (int);
        *value4=2;
        NewTree.AddNodeToTree(value4);
        Node *help=NewTree.GetHead();
        ASSERT_EQ(NewTree.GetHead()->GetLeftNode()->GetLeftNode(),NewTree.FindMin(help));
        NewTree.Free(help);
    }
    TEST(TestsBinarySearchTree,TestBFS)
    {
        Tree NewTree;
        int *value1= new (int);
        *value1=6;
        NewTree.AddNodeToTree(value1);
        int *value2= new (int);
        *value2=3;
        NewTree.AddNodeToTree(value2);
        int *value3= new (int);
        *value3=10;
        NewTree.AddNodeToTree(value3);
        int *value4= new (int);
        *value4=2;
        NewTree.AddNodeToTree(value4);
        vector<int> exp={6,3,10,2};
        vector<int*> keys=NewTree.BFS();
        for (int i=0;i<keys.size();i++) ASSERT_EQ(exp[i],*keys[i]);
        Node *help=NewTree.GetHead();
        NewTree.Free(help);
    }
}
//g++ -std=c++11 -stdlib=libc++  BinarySearchTreeTests.cpp BinarySearchTree.cpp BinarySearch_main.cpp -lgtest -lpthread -o BinarySearchTests
//valgrind --leak-check=full --leak-resolution=high ./BinarySearchTests

