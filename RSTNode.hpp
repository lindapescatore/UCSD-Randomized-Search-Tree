#ifndef RSTNODE_HPP
#define RSTNODE_HPP
#include "BSTNode.hpp"
#include <cstdlib>
#include <ctime>

template <typename Data>
class RSTNode : public BSTNode<Data> {
public:
int priority;
  
  RSTNode(Data const & d) : BSTNode<Data>(d) {
    // TODO: implement this constructor!
    priority = rand(); 
  }

};
#endif // RSTNODE_HPP
