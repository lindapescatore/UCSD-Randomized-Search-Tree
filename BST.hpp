#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

using std::cout;
using std::endl;

/**
 *Alexander Kissinger
 *akissing@ucsd.edu
 *cs100f
 **/

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
    deleteAll( root );
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */ // TODO
  virtual bool insert(const Data& item) {
    // If  RootNode == NULL, tree is empty
    if ( this->root == 0 )
    {
      this->root = new BSTNode<Data>( item );
      isize++;
      return 1; //Or item?
    }

    // 2. Set CurrNode = RootNode. 
    else
    {
      BSTNode<Data>* CurrNode = this->root;

      while( 1 )
      {
        /* 3. If k < CurrNode.key ...   key must go in left subtree
         *    If CurrNode.left == NULL, set  CurrNode.left = new Node(k). Done.
         *    else  set CurrNode = CurrNode.left, and go to 3.
         */
        if( item < CurrNode->data )
        {
          if( CurrNode->left == 0 )
          {
            CurrNode->left = new BSTNode<Data>( item );
            CurrNode->left->parent = CurrNode;
            isize++;
            return 1;
          }

          CurrNode = CurrNode->left;
          continue; 
        } 
    
        /* 4. else If CurrNode.key < k ...   key must go in right subtree
         *    If CurrNode.right == NULL, set  CurrNode.right = new Node(k)
         *    else  set CurrNode = CurrNode.right, and go to 3.
         */
        if( CurrNode->data < item ) 
        {
          if( CurrNode->right == 0 )
          {
            CurrNode->right = new BSTNode<Data>( item );
            CurrNode->right->parent = CurrNode;
            isize++;
            return 1;
          }

          CurrNode = CurrNode->right;
          continue; 
      	}

        //5.  else Found the key 
        break;
      }
    }
      return 0;
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */ // TODO
  iterator find(const Data& item) const {
    // 1.  If  RootNode == NULL, tree is empty (no root).  Return false
    if ( this->root == 0 )
    {
      return typename BST<Data>::iterator( 0 );
    }

    // 2. Set CurrNode = RootNode. 
    else
    {
      BSTNode<Data>* CurrNode = this->root;

      while( 1 )
      {
        /* 3.  If k < CurrNode.key ...  key must be in left subtree, 
         * if it is in the tree.
         * If CurrNode.left == NULL, return false.
         * else  set CurrNode = CurrNode.left, and go to 3.
         */

        if( item < CurrNode->data )
        {
          if( CurrNode->left == 0 )
          {
            return typename BST<Data>::iterator( 0 );
          }

          CurrNode = CurrNode->left;
          continue; 
        } 
    
        /* 4. else If CurrNode.key < k ...  key must be in right subtree,
         * if it is in the tree.
         * If CurrNode.right == NULL, return false.
         * else  set CurrNode = CurrNode.right, and go to 3.
         */
        if( CurrNode->data < item ) 
        {
          if( CurrNode->right == 0 )
          {
            return typename BST<Data>::iterator( 0 );
          }

          CurrNode = CurrNode->right;
          continue; 
        }

        //5.  else Found the key; it is in CurrNode.  Return true.  
        return typename BST<Data>::iterator( CurrNode );
      }
    }
        return typename BST<Data>::iterator( 0 );
  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
    return isize;
  }

  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
    return root == 0;
  }

  /** Return an iterator pointing to the first item in the BST.
   */ // TODO
  iterator begin() const {
    return typename BST<Data>::iterator( first( root ) );
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator( 0 );
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */
  void inorder(BSTNode<Data>* n) const {
    if(n==0) return;
    inorder(n->left);
    std::cout << *n << std::endl;
    inorder(n->right);
  }

  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  /** Last Helper-Function **/
  static BSTNode<Data>* last( BSTNode<Data>* root )
  {
    if(root == 0) return 0;
    while(root->right!= 0) root = root->right;
    return root->right;
  }

  // do a postorder traversal, deleting nodes
  static void deleteAll(BSTNode<Data>* n) {
    if (0 == n) return;
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
  }


 };


#endif //BST_HPP
