//Equipo 8: Fernando Cuellar Martinez A00827540, Armando Montaño Gonzalez A00827377, Alfonso Villarreal Galindo A00828725

/*
Instrucciones de Uso:

Esperar a que el programa acabe de ordenar (Entre 30-40 segundos, pero dependiendo de la computadora puede llegar hasta 1 minuto).
Una vez acabe de ordenar, nombrar el archivo (agregando .txt al final del nombre deseado). Una vez que acabe de meter los datos al archivo (alrededor de 5 segundos), dar el rango de ip (XXX.XXX.XXX:XXXX, se recomienda usar una IP de la base de datos para evitar errores de formato).
*/
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

#include "BST.h"

//Main
int main() {

  ifstream bit("bitacoraOrdenada.txt");
  stringstream ss;
  string line, valor, mes, info, ip, hora, ipAnt;
  int dia, cont=1,cant=0, cheking=0;
  char delim = ' ';
  BST ipTree; //creando el arbol

  while (getline(bit,line)) {
     cheking++;
    //info es todo lo demas hay que declararlo como string
    info = "";
    if(cant>0){
      ipAnt=ip;
    }
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
          ip = ip.substr(0, ip.size()-5);
          if(cant==0){
            ipAnt=ip;
          }
				  break;
        default:
          info+=(valor + " ");
        break;
				}
	      cont++;

	  }
    if(ipAnt!=ip){
      ipTree.add(ipAnt,cant);
      cant=1;
    }else{
      cant++;
    }
	  cont=1;
  }
  ipTree.add(ipAnt,cant);
  cout<<""<<endl;
  ipTree.printGreater(5);

  return 0;
}
