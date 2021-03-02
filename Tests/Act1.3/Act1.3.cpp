//Actividad 1.3 Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales (Evidencia Competencia)
//Actividad en la cual se planea ordenar un archivo con diferentes entradas de registo mediante el mes y dia
//tener la capacidad de buscar un rango de registros mediante la introduccion de fechas inicio y fin ademas
//de mostrarlos y escribir un archivo con todos los registros ordenados correspondientes de bitacora.txt
//Equipo 8: Fernando Cuellar Martinez A00827540, Armando Montaño Gonzalez A00827377, Alfonso Villarreal Galindo A00828725

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
#include "Bitacora.h"

//Funcion que busca el primero dato especifco en el rango del vector mediante opcion binaria
//Complegidad computacional: O(logn)
int busqBinariaLower(vector<Bitacora> &v, int dato){
	int aux, ini = 0, fin = v.size()-1, mit;

	while (ini < fin){
		mit = (ini+fin)/2;
		if (v[mit].getFecha() >= dato && v[mit-1].getFecha()<dato){
      return mit;
    }else if(v[mit].getFecha() >= dato){
      fin=mit-1;
    }else{
      ini=mit+1;
    }
  }
  return ini;
}

//Funcion que busca el ultimo dato especifico en el rango del vector mediante opcion binaria
//Complegidad computacional: O(logn)
int busqBinariaUpper(vector<Bitacora> &v, int dato){
	int aux, ini = 0, fin = v.size()-1, mit;

	while (ini <= fin){
		mit = (ini+fin)/2;
    if (v[mit].getFecha() <= dato && v[mit+1].getFecha()>dato){
      return mit;
    } if (v[mit].getFecha() <= dato && (mit+1) > v.size()){
      return mit + 1;
    }
    else if(v[mit].getFecha() > dato){
      fin=mit-1;
    }else{
      ini=mit+1;
    }
  }
  return ini; //+1
}

// funcion que sirve para unir los vectores previamente ordenados por la funcion ordenaMerge
// se pone de parametro un vector de entros y uno auxiliar un inicio y un fin para poder identificar los vectores, retorna la cant de ordenamientos realizados
//Complejidad computacional: O(n)
int merge(vector<Bitacora> &vect, vector<Bitacora> &aux,  int ini, int fin){
	int mit=(ini+fin)/2;
	int i = ini, j=mit+1,k=ini;
	int cont=0;
	while(i<=mit && j<=fin){
		cont++;
		if(vect[i].getFecha() <= vect[j].getFecha()){
			aux[k++]=vect[i++];
		}else{
			aux[k++]=vect[j++];
		}
	}
	while(i<=mit){
		aux[k++]=vect[i++];
	}
	while(j<=fin){
		aux[k++]=vect[j++];
	}
	for(int z=ini; z<=fin; z++){
		vect[z]=aux[z];
	}
	return cont;
}

//Funcion que sirve para odenar el vector proporcionado con la metodologia MergeSort
//MergeSort, Complejidad computacional: O(nlogn)
int ordenaMerge(vector<Bitacora> &vect, vector<Bitacora> &aux, int ini, int fin){

	int cont=0;
	if(ini<fin){
		int mit=(ini+fin)/2;
		cont+=ordenaMerge(vect,aux,ini,mit);
		cont+=ordenaMerge(vect,aux,mit+1,fin);
		cont+=merge(vect,aux,ini,fin);
	}
	return cont;
}

//Funcion que retorna el numero del mes de acuerdo a la estrada de un string
//Complejidad computacional: O(1)
int month2num(string mes){
  if(mes=="Jan"){
		return 1;
	}
  if(mes=="Feb"){
		return 2;
	}
  if(mes=="Mar"){
		return 3;
	}
  if(mes=="Abr"){
		return 4;
	}
  if(mes=="May"){
		return 5;
	}
	if(mes=="Jun"){
		return 6;
	}
	if(mes=="Jul"){
		return 7;
	}
	if(mes=="Aug"){
		return 8;
	}
	if(mes=="Sep"){
		return 9;
	}
	if(mes=="Oct"){
		return 10;
	}
  if(mes=="Nov"){
		return 11;
	}
  if(mes=="Dec"){
		return 12;
	}
  return 1;
}

//Main
int main() {

  ifstream bit("bitacora.txt");
  stringstream ss;
  string line, valor, mes, info;
  int dia, cont=1;
  char delim = ' ';
  vector<Bitacora> bitacora;

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
        default:
          info+=(valor + " ");
        break;
				}
	      cont++;
	  }
	  bitacora.push_back(Bitacora(mes, dia, info)); //vector con objetos de tipo Bitacora
	  cont=1;
  }

  vector<Bitacora> aux(bitacora.size());
  ordenaMerge(bitacora,aux,0,bitacora.size());
  ofstream archivo;  // objeto de la clase ofstream
  //pedirle el nombre al usuario del txt
  string nombrearchivo;
  cout<<"Escribe le nombre del archivo para guardar los registros ordenados agregando al final .txt: ";
  cin>>nombrearchivo;
  cout<< "\n";
  archivo.open(nombrearchivo);
    for ( int i=1; i<=bitacora.size(); i ++) {
      archivo << bitacora[i].getMesStr()<<" "<<bitacora[i].getDia()<<" "<<bitacora[i].getInfo()<<endl;
    }
  archivo.close();

  //Empieza  la parte de busqueda

  int inf=0,sup=0,fechaInf,fechaSup,numMes,conta,diaini,diafin;
  string respuesta, mesini,mesfin;
  respuesta="S";

  while (respuesta == "S") {

  cout << "Introduzca su fecha de inicio en el formato: mes dia (Jun 3), tome en cuenta el formato de 3 letras en el mes: ";
  cin>>mes>>dia;//Introduce Fecha de entrada
  mesini=mes;
  diaini=dia;
  numMes=month2num(mes);
  fechaInf=(numMes*100)+dia;//Cambiandolo a formato numerico
  cout<< "\n";
  cout << "Introduzca su fecha de fin en el formato: mes dia (Jun 4), tome en cuenta el formato de 3 letras en el mes: ";
  cin>>mes>>dia;//Introduce Fecha de salida
  mesfin=mes;
  diafin=dia;
  numMes=month2num(mes);
  fechaSup=(numMes*100)+dia;
  cout<< "\n";

  cout << "Registros encontrados: " << endl << endl;

  conta=0;

	//busqueda de los indices mediante busqBinaria
  inf=busqBinariaLower(bitacora, fechaInf);
  sup=busqBinariaUpper(bitacora, fechaSup);

  for(int i=inf;i<=sup;i++){
    if (bitacora[i].getDia()!=bitacora[i+1].getDia()){
      bitacora[i].show();
      cout<< "\n";
     }else{
      bitacora[i].show();
    }
    conta ++;
  }

  cout<< endl << "Cantidad de registos encontrados entre " << mesini << "/"<< diaini <<" y "<< mesfin << "/"<< diafin  <<": "<<conta << endl;
  cout << endl << "Desea realizar otra busqueda? (Presione 'S' para si, 'N' para No): ";
  cin>>respuesta;
  cout<< "\n";

  }
}
