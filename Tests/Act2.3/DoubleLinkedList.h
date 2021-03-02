//Equipo 8: Fernando Cuellar Martinez A00827540, Armando Montaño Gonzalez A00827377, Alfonso Villarreal Galindo A00828725

//Clase linked list doblemente encadenada para next y prev
#ifndef  DoubleLinkedList_h
#define  DoubleLinkedList_h

#include "Node.h"

class DoubleLinkedList{
	private:
		Node *head;
    Node *tail;
		int size;
	public:
		DoubleLinkedList();
    ~DoubleLinkedList();
		void addLast(Bitacora data);
		Bitacora get(int pos);
		Bitacora set(Bitacora data, int pos);
    int getSize();
    Bitacora getTail();//esto se quitara, nada mas para ver si jala el tail
    void sort();
    void une(int ini, int mid, int fin);
    void ordenaMerge( int ini, int fin);
    void ordena();

};
//Complejidad: O(1)
DoubleLinkedList::DoubleLinkedList(){
	head = nullptr;
  tail = nullptr;
	size = 0;
}
//Complejidad: O(1)
DoubleLinkedList::~DoubleLinkedList(){

}

//Metood para anadir un nuevo nodo, dependindo las condiciones al inicio o al final
//complegidad O(n)
void DoubleLinkedList::addLast(Bitacora data){
    Node *newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        tail=head;

        //return;
    }else{
      Node *curr = head;
      while(curr->getNext() != nullptr){
			  curr = curr->getNext();
		  }
      curr->setNext(newNode);
      newNode->setPrev(curr);
      tail=newNode;
    }
    size++;
}

//Complejidad: O(n)
Bitacora DoubleLinkedList::get(int pos){
	Node *curr = head;			// Inicializar curr en head
	for (int i=1; i<=pos; i++){
		curr = curr->getNext();		// curr salta pos veces
	}
	return curr->getData();			// Regresar la informaciÃ³n
}

//Complejidad: O(n)
Bitacora DoubleLinkedList::set(Bitacora data, int pos){
	Node *curr = head;			// Inicializar curr en head
	for (int i=1; i<=pos; i++){
		curr = curr->getNext();		// curr salta pos veces
	}
	Bitacora dataAux = curr->getData();
	curr->setData(data);
	return dataAux;
}

//Complejidad: O(1)
int DoubleLinkedList::getSize(){
	return size;
}

void DoubleLinkedList::une(int ini, int mid, int fin){
  DoubleLinkedList L;
  DoubleLinkedList R;
  int f1= ((mid-ini)+1);
  int f2= (fin-mid);

  for (int i=0; i<f1; i ++) {

      L.addLast(get(i+ini));

  }
  for (int i=0; i<f2; i ++) {

      R.addLast(get(i+mid+1));

  }

  int i=0;
  int j=0;

  int pos=ini;

  while (i<f1 && j<f2) {

    if(L.get(i).ipToLong(L.get(i).getIP())<=R.get(j).ipToLong(R.get(j).getIP())){
      set(L.get(i),pos);
      i++;

    }else{
      set(R.get(j),pos);
      j++;
    }
    pos++;
  }

  while(i<f1){

    set(L.get(i),pos);
    i++;
    pos++;

  }

  while(j<f2){
    set(R.get(j),pos);
    j++;
    pos++;

  }


}

//Complejidad computacional de todo el algoritmo:O(n)
void DoubleLinkedList::ordenaMerge( int ini, int fin){
  if (ini<fin) {
    int m = (ini+fin)/2;
      //cout<<"Estoy ordenando heidipasado de lanza"<<endl;
     ordenaMerge( ini, m);
     ordenaMerge( m+1, fin);
     une( ini, m, fin);
  }
}

void DoubleLinkedList::ordena(){
 ordenaMerge(0,size-1);
}


//Complejidad: O(1)
Bitacora DoubleLinkedList::getTail(){
  return tail->getData();
}
#endif
