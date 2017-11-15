shared_ptr<Node> Node::clone_subtree(Node *parent=nullptr)
{
  const Node *const_this = const_cast<const Node *>(this);

  switch (getTotalItems()) {

      case 1:
         make:shared(const_this.pair(0), const_cast<Node*>(parent))
         break;
 

      case 2:
         make:shared(const_this.pair(0), const_this.pair(1), const_cast<Node*>(parent))
         break;
 

      case 3:
         make:shared(const_this.pair(0), const_this.pair(1), const_this.pair(2), const_cast<Node*>(parent))
         break;
 
  }
}
