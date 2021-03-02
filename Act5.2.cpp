//Equipo 8: Fernando Cuellar Martinez A00827540, Armando Montaño Gonzalez A00827377, Alfonso Villarreal Galindo A00828725

//Act 5.2 - Actividad Integral sobre el uso de códigos hash (Evidencia Competencia)
//27/11/2020
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  //LECTURA DE LOS VALORES DE IPS PARA PROCESAMIENTO Y RESUMENES
  ifstream bit("bitacoraACT5_2.txt");
  unordered_map<string, int> accesos;
  unordered_map<string, vector<string>> ipMap;
  stringstream ss;
  vector<string> ipRes;
  string line, valor, ip, resumen,mes,dia,info,hora;
  int word=1;
  char delim = ' ';

    while (getline(bit,line)){
      info = "";
      stringstream ss(line);
    	  while (getline(ss,valor,delim)){//esto es una linea nada mas, recorrido de un rengolon
            switch(word){
              case 1:
                mes=valor;
                break;
              case 2:
                dia=valor;
                break;
              case 3:
                hora=valor;
                break;
              case 4:
                ip=valor;
                ip = ip.substr(0, ip.find(':'));//Complejidad: O(n), n siendo el tamaño del string
                break;
              default:
                info+=(valor + " ");
                break;
            }
          word++;
        }
        resumen=dia+" "+mes+" "+hora+" "+info;

      ipMap[ip].push_back(resumen);
      accesos[ip]+=1;
      //cout<<"meti un valor a: "<<ip<<endl;
      word=1;
    }

  string busqueda;
  char respuesta;
  respuesta = 'S';
  while(respuesta == 'S'){
  cout << "\nIngrese la ip que desea buscar: ";
  cin>> busqueda;
  //Complejidad comutacional de O(1), peor caso O(logn)
  for (auto x : ipMap) {
    if(x.first == busqueda){
    cout<< "IP: "<< x.first <<" con "<< x.second.size() <<" accesos"<<endl;
    for(int i=0; i<x.second.size(); i++){
      cout<< "  " << i+1 << " -> " << x.second[i] <<endl;
    }
  }
  }
  cout << "\nDesea realizar otra busqueda? 'S' para Si 'N' para No: ";
  cin>> respuesta;
  }

  cout<<"\n\nSaliendo del programa exitosamente...\n";
  return 0;
}
