#include "NodeT.h"

class BST{
	public:
		BST();
		~BST();
		void add(string data, int key);
		void printGreater(int n);
    long long ipToLong(string _ip);
	private:
		NodeT *root;
		void destruye(NodeT *r);
		void greaterNvalues(NodeT *r, int n, int &i);
};
//Complejidad: O(1)
BST::BST(){
	root = nullptr;
}
//Complejidad: O(n)
BST::~BST(){
	destruye(root);
}
//Complejidad: O(n)
void BST::destruye(NodeT *r){
	if (r != nullptr){
		destruye(r->getLeft());
		destruye(r->getRight());
		delete r;
	}
}
//Complejidad: O(n)
void BST::add(string data, int key){
	NodeT *curr = root;
	NodeT *father = nullptr;
	long long ip;
	while (curr != nullptr){
		if (curr->getData() == data){
			return;
		}
		father = curr;
		if(curr->getKey()>key){
			curr=curr->getLeft();
		}else if(curr->getKey()<key){
			curr=curr->getRight();
		}else{
			ip=ipToLong(data);
			curr=(ipToLong(curr->getData()) > ip) ? curr->getRight() : curr->getLeft();
		}
	}
	if (father == nullptr){
		root = new NodeT(data,key);
	}
	else{
		if(father->getKey()>key){
			father->setLeft(new NodeT(data,key));
		}else if(father->getKey()<key){
			father->setRight(new NodeT(data,key));
		}else{
			(ipToLong(father->getData()) > ip) ? father->setRight(new NodeT(data,key)) : father->setLeft(new NodeT(data,key));
		}
	}
}
void BST::greaterNvalues(NodeT *r, int n, int &i){
	if(r != nullptr){
			greaterNvalues(r->getRight(),n,i);

			if(i<=n){
				cout << i <<"º Lugar: " << r->getData() << " - No. de Accesos: "<< r->getKey()<<endl;
				i++;

			}
    greaterNvalues(r->getLeft(),n,i);

	}
}

void BST::printGreater(int n){
  int i=1;
	greaterNvalues(root,n,i);
	cout<<"\n "<<endl;
}

//Metodo para convertir un string ip en un long
//complegidad O(n)
long long BST::ipToLong(string _ip){
  int idx = 0;
  long long datoFinal= 0, dato = 0;
  while (idx < _ip.size()){
    if (_ip[idx]!= '.' && _ip[idx]!=':'){
      dato = dato*10 + _ip[idx]-'0';
      }else{
        datoFinal = datoFinal*1000 + dato;
        dato = 0;
      }
      idx++;
  }
  datoFinal = datoFinal*10000 + dato;
  return datoFinal;
}
