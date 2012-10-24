#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

/**
 *Alexander Kissinger
 *akissing@ucsd.edu
 *cs100f
 **/

using std::cout;
using std::endl;
template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
  BSTNode<Data>* successor() {

    // X has a right child
    if( right != 0 )
      return this->right;

    // X has no right child, and has no parent
    if( parent == 0)
        return 0;

    // X has no right child, and is the left child of its parent
    if( this->parent->left != 0 && this->data == this->parent->left->data )
      return this->parent;

    // X has no right child, and is the right child of its parent
    if( this->parent->right!= 0 && this->data == this->parent->right->data )
      return 0;

    return 0;
  }

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP