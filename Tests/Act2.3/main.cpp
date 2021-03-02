//Equipo 8: Fernando Cuellar Martinez A00827540, Armando Montaño Gonzalez A00827377, Alfonso Villarreal Galindo A00828725

/*
Instrucciones de Uso:

Esperar a que el programa acabe de ordenar (Entre 30-40 segundos, pero dependiendo de la computadora puede llegar hasta 1 minuto).
Una vez acabe de ordenar, nombrar el archivo (agregando .txt al final del nombre deseado). Una vez que acabe de meter los datos al archivo (alrededor de 5 segundos), dar el rango de ip (XXX.XXX.XXX:XXXX, se recomienda usar una IP de la base de datos para evitar errores de formato).
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Bitacora.h"
#include "DoubleLinkedList.h"

//Main
int main() {

  ifstream bit("bitacora.txt");
  stringstream ss;
  string line, valor, mes, info, ip, hora, ipinicio, ipfin;
  int dia, cont=1;
  char delim = ' ';
  long long ip1, ip2;
  vector<Bitacora> bitacora; // hacer la linklist
  DoubleLinkedList listaBitacora; //creando la doble lista
  //Bitacora bitInfo;

  while (getline(bit,line)) {
    //info es todo lo demas hay que declararlo como string
    info = "";
    stringstream ss(line);
	  while (getline(ss,valor,delim)){
	    switch(cont){
	    	case 1:
	        mes=valor;
					break;
	      case 2:
	        dia=stoi(valor);
					break;
        case 3:
	        hora=valor;
				  break;
        case 4:
	        ip=valor;
				  break;
        default:
          info+=(valor + " ");
        break;
				}
	      cont++;
	  }
	  //bitacora.addLast_back(Bitacora(mes, dia, hora, ip, info)); //vector con objetos de tipo Bitacora, esto luego se quitara

    listaBitacora.addLast(Bitacora(mes, dia, hora, ip, info));
	  cont=1;
  }
  //checar que hace el iptolong, checar que se imprima todo sorteado
  cout<<"Ordenando..."<<endl;
  listaBitacora.ordena();
  cout<<"Ordenamiento terminado..."<<endl;
 // for (int i = 0; i < listaBitacora.getSize()-1; i++){
 //   listaBitacora.get(i).show();
 // }

  ofstream archivo;  // objeto de la clase ofstream
  //pedirle el nombre al usuario del txt
  string nombrearchivo;
  cout<<"Escribe el nombre del archivo para guardar los registros ordenados agregando al final .txt: ";
  cin>>nombrearchivo;
  cout<< "\n";
  archivo.open(nombrearchivo);
    for (int i = 0; i < listaBitacora.getSize(); i++) {
      archivo << listaBitacora.get(i).getMesStr()<< " " << listaBitacora.get(i).getDia() << " " << listaBitacora.get(i).getHora()<< " " << listaBitacora.get(i).getFecha()<< " " << listaBitacora.get(i).getIP()<< " " << listaBitacora.get(i).getInfo() <<  endl;
    }
  archivo.close();

  char respuesta = 'S';
  Bitacora checkip;
  while(respuesta =='S'){
  cout<<"Escribe el inicio del rango de IP: ";
  cin >> ipinicio;
  ip1 = checkip.ipToLong(ipinicio);
  cout<<"Escribe el fin del rango de IP: ";
  cin >> ipfin;
  ip2 = checkip.ipToLong(ipfin);

  //Busqueda Secuencial, Complejidad: O(n)
  for (int i = 0; i < listaBitacora.getSize(); i++) {
      if (listaBitacora.get(i).ipToLong(listaBitacora.get(i).getIP()) >= ip1 && listaBitacora.get(i).ipToLong(listaBitacora.get(i).getIP()) <= ip2){

        cout << listaBitacora.get(i).getMesStr()<< " " << listaBitacora.get(i).getDia() << " " << listaBitacora.get(i).getHora()<< " " << listaBitacora.get(i).getIP()<< " " << listaBitacora.get(i).getInfo() <<  endl;

      }

    }
  cout<< "\n";
  cout<<"Deseas realizar otra busqueda, teclea 'S' para SI o 'N' para NO : ";
  cin >> respuesta;
  cout<< "\n";
  }
}
