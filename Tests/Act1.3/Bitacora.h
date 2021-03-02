#ifndef  Bitacora_h
#define  Bitacora_h

#include <string>
//Classe bitacora donde se crearan los atricutos
class Bitacora{
	private:
	    string mes, info;
	    int dia;
	public:
		Bitacora();
		Bitacora(string _mes, int _dia, string _info);
		void setMes(string _mes);
		void setDia(int _dia);
		void setInfo(string _info);
		int getMes();
    string getMesStr();
		int getDia();
    int getFecha();
		string getInfo();
		void show();
};
Bitacora::Bitacora(){
	mes=" ";
	dia=0;
	info=" ";
}
Bitacora::Bitacora(string _mes, int _dia, string _info){
	mes=_mes;
	dia=_dia;
	info=_info;
}
void Bitacora::setMes(string _mes){
	mes=_mes;
}
void Bitacora::setDia(int _dia){
	dia=_dia;
}
void Bitacora::setInfo(string _info){
	info=_info;
}
//obtener el numero deacuerdo al mes
int Bitacora::getMes(){
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
string Bitacora::getMesStr(){
  return mes;
}
int Bitacora::getDia(){
	return dia;
}
string Bitacora::getInfo(){
	return info;
}
//Obtener la cantidad numerica de un mes para ordenar
int Bitacora::getFecha(){
  return (getMes()*100)+dia;//
}
void Bitacora::show(){
	//Oct 9 10:32:24 423.2.230.77:6166 Failed password for illegal user guest
	cout << mes << " " << dia << " " << info << endl;
}
#endif
