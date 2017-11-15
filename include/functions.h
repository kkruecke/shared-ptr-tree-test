#ifndef functions_h_
#define functions_h_

#include "include/node.h"
#include "include/level-order-display.h"

template<class Key> std::shared_ptr<Node<Key>> buildTree(Key k1, Key k2, Key k3)
{
  std::shared_ptr<Node<Key>> tree;

  Key min, mid, max;

  if (k1 < k2) {

     min = k1;
     max = k2;
  } else {

     min = k2;
     max = k1;
  }

  if (k3 < min) {

     mid = min;
     min = k3;

  } else if (k3 < max) {

     mid = k3;  

  } else {

     mid = max;
     max = k3;
  }

  tree = std::make_shared<Node<Key>>(mid);   

  tree->left =  std::make_shared<Node<Key>>(min);   

  tree->right =  std::make_shared<Node<Key>>(max);   

  return tree;
}

template<class Key, class Functor> void levelOrderTraverse(const std::shared_ptr<Node<Key>>& root, Functor f) 
{
   if (root == nullptr) return;
   
   // pair of: 1. Node pointer and 2. level of tree.
   std::queue<std::pair<const Node<Key>*, int>> q; 

   auto level = 1;

   q.push(std::make_pair(root.get(), level));

   while (!q.empty()) {

        std::pair<const Node<Key> *, int> pair_ = q.front();

        const Node<Key> *current = pair_.first;

        int tree_level = pair_.second;

        f(current, tree_level); // For example: print out all the keys_values in current.
         
        if (!current->isLeaf()) {
            
            q.push(std::make_pair(current->leftChild().get(), tree_level + 1));  
            q.push(std::make_pair(current->rightChild().get(), tree_level + 1));  
        }
        q.pop(); 
   }
}

template<class Key> void print_tree(const std::shared_ptr<Node<Key>>& root_ptr)
{
  levelOrderDisplay<Key> tree_printer(root_ptr, std::cout); 

  levelOrderTraverse(root_ptr, tree_printer);

  std::cout << std::flush;
}

#endif
