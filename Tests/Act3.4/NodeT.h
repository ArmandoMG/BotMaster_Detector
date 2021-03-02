#ifndef  NodeT_h
#define  NodeT_h
class NodeT{
  private:
  	int key;
    string data;
  	NodeT *left;
  	NodeT *right;
  public:
  	NodeT(string data, int key);
		NodeT(string data, int key, NodeT *left, NodeT *right);
    string getData();
    void setKey(int key);
    int getKey();
  	void setData(string data);
  	void setLeft(NodeT *left);
  	void setRight(NodeT *right);
  	NodeT* getLeft();
  	NodeT* getRight();
};

NodeT::NodeT(string data, int key){
  this->key=key;
	this->data = data;
	this->right = nullptr;
  this->left = nullptr;
}

NodeT::NodeT(string data, int key, NodeT *right, NodeT *left){
  this->key=key;
	this->data = data;
	this->right = right;
  this->left = left;
}

void NodeT::setKey(int key){
  this->key = key;
}

int NodeT::getKey(){
  return key;
}

void NodeT::setData(string data){
  this->data = data;
}

void NodeT::setLeft(NodeT *left){
  this->left = left;
}

void NodeT::setRight(NodeT *right){
  this->right = right;
}

string NodeT::getData(){
  return data;
}

NodeT* NodeT::getLeft(){
  return left;
}

NodeT* NodeT::getRight(){
  return right;
}

#endif
