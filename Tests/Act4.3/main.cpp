#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <iterator>

using namespace std;

int main() {

  //LECTURA DE N,M Y LOS VALORES DE IPS PARA PROCESAMIENTO
  ifstream bit("bitacoraACT4_3(B).txt");
  unordered_map<string, int> ipMap;
  vector<vector <int> > listAdj;
  int maxFanout=0,bootMaster;
  stringstream ss;
  string line, valor, ip1,ip2;
  int dia, cont=0,cant=0, word=1, cheking=0,n,m;
  char delim = ' ';

    //Complejidad computacional: O(n+m)
    while (getline(bit,line)){
      stringstream ss(line);
      if(cont==0){
        n=stoi(line.substr(0,line.find(' ')));
        m=stoi(line.substr(line.find(' ')+1,line.length()-1));
        listAdj.resize(n);//Complejidad: O(n)
      }else if(cont>=1){
    	  while (getline(ss,valor,delim)){
          if(cont<=n){
              ipMap[valor]=cont;
          }else if(cont>n){
            switch(word){
              case 1:
                break;
              case 2:
                break;
              case 3:
                break;
              case 4:
                ip1=valor;
                ip1 = ip1.substr(0, ip1.find(':'));//Complejidad: O(n), n siendo el tamaño del string
                break;
              case 5:
                ip2=valor;
                ip2 = ip2.substr(0, ip2.find(':'));//Complejidad: O(n), n siendo el tamaño del string
                 break;
              default:
                break;
            }
          }
          word++;
        }
        if(cont>n){
          listAdj[(ipMap.at(ip1))-1].push_back((ipMap.at(ip2))-1);// Complejidad: O(1)
        }

      }
      cont++;
      word=1;
    }

  int respuesta=3;
  while(respuesta != 0){
    cout<<"-----SELECCIONA UNA OPCION-----"<<endl;
    cout<<"1.- Ver cada nodo y sus FanOuts"<<endl;
    cout<<"2.- Ver que nodos tienen el mayor FanOuts"<<endl;
    cout<<"3.- Ver presunta direccion del BootMaster"<<endl;
    cout<<"0.- Salir"<<endl;
    cin>>respuesta;
        //Complejidad: O(n)
        if(respuesta==1){
          for (auto x : ipMap) {

                cout<<"IP: "<<x.first<< " con #"<<listAdj[x.second].size()<<" FanOuts"<<endl;

          }
        }
        //Complejidad: O(n+m)
        if(respuesta==2){
          //prueba para saber si solo 2 chagnos tienen 18 atacantes
           cout<<"Nodos con mayor fan-out"<<endl;
                 //SACAR EL MAX FAN OUT
           for(int i=0;i<listAdj.size(); i++){
             if(listAdj[i].size()>maxFanout){
               maxFanout=listAdj[i].size();
               bootMaster=i;
             }
           }
           for (auto x : ipMap) {
               if(listAdj[x.second].size()==maxFanout){
                 cout<<"-> "<<x.first<<endl;
               }
           }
        }
        //Complejidad computacional: O(n+m)
       if(respuesta==3){
               //SACAR EL MAX FAN OUT
          for(int i=0;i<listAdj.size(); i++){
            if(listAdj[i].size()>maxFanout){
              maxFanout=listAdj[i].size();
              bootMaster=i;
            }
          }
          for (auto x : ipMap) {
            if(listAdj[x.second].size()==maxFanout){
              cout<<"Posible Boot Master: "<<x.first<<" --- Num. ataques: "<<maxFanout<<endl;
            }
          }
        }
        cout<<" "<<endl;
  }

  cout<<"\n\nSaliendo del programa exitosamente...\n";
  return 0;
}
