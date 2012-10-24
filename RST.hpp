#ifndef RST_HPP
#define RST_HPP
#include "BST.hpp"
#include "RSTNode.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;
template<typename Data> class RST : public BST<Data> 
{

public:
  RST() : BST<Data>() {
  srand( time( 0 ) );
  }
  virtual bool insert(const Data& item) 
  {
    // TODO: implement this function!
    // If  RootNode == NULL, tree is empty
    if ( this->root == 0 )
    {
      this->root = new RSTNode<Data>( item );
      (this->isize)++;
      return 1; //Or item?
    }

    // 2. Set CurrNode = RootNode. 
    else
    {
      RSTNode<Data>* CurrNode = (RSTNode<Data>*)this->root;
      int inserted = 0;

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
            CurrNode->left = new RSTNode<Data>( item );
            CurrNode->left->parent = CurrNode;
            CurrNode = (RSTNode<Data>*)CurrNode->left;
            (this->isize)++;
            inserted++;
            break; 
          }

          CurrNode = (RSTNode<Data>*)CurrNode->left;
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
            CurrNode->right = new RSTNode<Data>( item );
            CurrNode->right->parent = (RSTNode<Data>*)CurrNode;
            CurrNode = (RSTNode<Data>*)CurrNode->right;
            (this->isize)++;
            inserted++;
            break;
          }

          CurrNode = (RSTNode<Data>*)CurrNode->right;
          continue; 
        }

        //5.  else Found the key 
        break;
      }

      if( inserted )
      {
        /* Rotate up as needed */
        while( 1 )
        {
          /* If it has become the root, then youre done */ 
          if( CurrNode->parent == 0 )
          {
            this->root = CurrNode;
            break; 
          }
          /* Check if unbalanced */ 
          if( ((RSTNode<Data>*)CurrNode)->priority > ((RSTNode<Data>*)CurrNode->parent)->priority )
          {
            /* Check if CurrNode is it's parent's right or left node */ 
            if( CurrNode == CurrNode->parent->right)
            {
              CurrNode = rotateWithRightChild( (RSTNode<Data>*)CurrNode->parent );
              continue;
            }
            /* It's the Parent's Left */
            else
            {
              CurrNode = rotateWithLeftChild( (RSTNode<Data>*)CurrNode->parent );
              continue;
            }
          } 
          
          break;
        }
        return 1;
      }
    }
      return 0;
  }

private:

/** Perform single rotation to handle AVL case 1:
* AVL violation due to insertion in left subtree of left child.
* @return pointer to the root of the rotated subtree
*/
RSTNode<Data>* rotateWithLeftChild(RSTNode<Data>* X) {
  RSTNode<Data>* P = (RSTNode<Data>*)X->parent;
  RSTNode<Data>* L = (RSTNode<Data>*)X->left;
  X->left = L->right;
  if( L->right != 0)
    L->right->parent = X;
  L->right = X;

  X->parent = L;
  L->parent = P;

  if( P != 0 && X == P->right )
    P->right = L;
  else if( P != 0 && X == P->left )  
    P->left = L;

  return L;
}


/** Perform single rotation to handle AVL case 4:
* AVL violation due to insertion in right subtree of right child.
* @return pointer to the root of the rotated subtree
*/
RSTNode<Data>* rotateWithRightChild(RSTNode<Data>* X) {
  RSTNode<Data>* P = (RSTNode<Data>*)X->parent;
  RSTNode<Data>* R = (RSTNode<Data>*)X->right;
  X->right = R->left;
  if( R->left != 0)
    R->left->parent = X;
  R->left = X;

  X->parent = R;
  R->parent = P;

  if( P != 0 && X == P->right )
    P->right = R;
  else if( P != 0 && X == P->left )  
    P->left = R;

  return R;
}
};
#endif // RST_HPP
