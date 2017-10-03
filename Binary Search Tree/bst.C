//Purpose make a binary search tree
// =======================================================
// HW#: HW6 binary search tree
// Your name: Sean Burk
// Compiler:  g++
// File type: C file bst.C
//=======================================================
#include <iostream>
#include "bst.h"

using namespace std;

BST::BST() 
{
  root=NULL;
}
BST::~BST() 
{//removes all nodes
  while(root!=NULL)
    {
    remove(root->key);
    }
  
}
        
void BST::insert(int data) {
  root=insert(root,data);
  return;
}  
Node* BST::insert(Node* node, int data) {
  if(node==NULL)
    {//if the node is empty then we have reached a point that we can add the node 
      node=new Node(data);
    }//the rest of the function looks for the right spot
  else if(node->key>data)
    {
      node->left=insert(node->left,data);
    }
  else
    node->right=insert(node->right,data);
  return node;
}

Node* BST::search(int key) {
  if(root==NULL)//finds the key if the key is not there then returns NULL
    return NULL;
  return search(root, key);
}
Node* BST::search(Node* node, int key) {
  if(node->key==key)
    return node;
  if(node->key>key)
    {//keeps calling search as on the side of the node the key should be untill it reaches null
      if(node->left==NULL)
	return NULL;
      return search(node->left,key);
    }
  if(node->right==NULL)
    return NULL;
  return search(node->right,key);
}

void BST::inorder() {
  if(root==NULL)
    return;
  inorder(root);
  cout<<endl;
}
void BST::inorder(Node* node) {
  if(node->left!=NULL)//just prints seft middle right 
    inorder(node->left);
  cout<<node->key<<", ";
  if(node->right!=NULL)
    inorder(node->right);
  return;
}

void BST::remove(int key)
{
  root=remove(root,key);
}
Node* BST::remove(Node* node, int key)
{//if we reach the end before finding key then the key was bad and nothing needs deleting 
  if(node==NULL)
    return node;
  if(node->key>key)
    {//traverses through the tree
      node->left = remove(node->left,key);
    }
  else if(node->key<key)
    {
      node->right = remove(node->right,key);
    }
  else
    {
      if(node->left==NULL)
	{//if one node is null of the one being deleted
	  Node* temp=node->right;
	  delete node;
	  return temp;
	}
      else if(node->right==NULL)
	{//same but for the other node
	  Node* temp=node->left;
          delete node;
          return temp;
	}
      else
	{//if nither are null then it gets the leftmost node of the right side 
	  Node* temp=leftmostNode(node->right);
	  node->key=temp->key;//swaps the key
	  temp->key=key;//then deletes the one on the end 
	  node->right=remove(node->right,key);
	}
    }
  return node;
}
Node* BST::leftmostNode(Node* node)
{//keeps going left 
  if(node->left==NULL)
    return node;
  return leftmostNode(node->left);
}
