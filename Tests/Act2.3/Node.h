//Equipo 8: Fernando Cuellar Martinez A00827540, Armando Montaño Gonzalez A00827377, Alfonso Villarreal Galindo A00828725

//Clase Nodo con la implementacion de el next y el previo
// La complejidad de cada uno de los metodos en nodo es cte. O sea, O(1)
#include "Bitacora.h"

class Node{
  private:
  	Bitacora data;
  	Node *prev;
  	Node *next;
  public:
  	Node(Bitacora data);
		Node(Bitacora data, Node *next, Node *prev);
  	void setData(Bitacora _data);
  	void setPrev(Node *_prev);
  	void setNext(Node *_next);
  	Bitacora getData();
  	Node *getPrev();
  	Node *getNext();
};

Node::Node(Bitacora _data){
	data = _data;
	next = nullptr;
  prev = nullptr;
}

Node::Node(Bitacora data, Node *next, Node *prev){
	this->data = data;
	this->next = next;
  this->prev = prev;
}

void Node::setData(Bitacora _data){
  data = _data;
}

void Node::setPrev(Node *_prev){
  prev = _prev;
}

void Node::setNext(Node *_next){
  next = _next;
}

Bitacora Node::getData(){
  return data;
}

Node* Node::getPrev(){
  return prev;
}

Node* Node::getNext(){
  return next;
}
