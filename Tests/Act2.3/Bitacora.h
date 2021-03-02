//Equipo 8: Fernando Cuellar Martinez A00827540, Armando Montaño Gonzalez A00827377, Alfonso Villarreal Galindo A00828725

#ifndef  Bitacora_h
#define  Bitacora_h

#include <string>
//Classe bitacora donde se crearan los atricutos
class Bitacora{
	private:
	    string mes, hora, ip, info;
	    int dia;
	public:
		Bitacora();
		Bitacora(string _mes, int _dia, string _hora, string _ip, string _info);
		void setMes(string _mes);
		void setDia(int _dia);
    void setHora(string _hora);
    void setIP(string _ip);
		void setInfo(string _info);
		int getMes();
    string getMesStr();
		int getDia();
    string getHora();
    int getFecha();
    string getIP();
		string getInfo();
    long long ipToLong(string _ip);
		void show();
};
Bitacora::Bitacora(){
	mes=" ";
	dia=0;
  hora= " ";
  ip = " ";
	info=" ";
}
Bitacora::Bitacora(string _mes, int _dia, string _hora, string _ip, string _info){
	mes=_mes;
	dia=_dia;
  hora = _hora;
  ip = _ip;
	info=_info;
}
//complegidad O(1)
void Bitacora::setMes(string _mes){
	mes=_mes;
}
//complegidad O(1)
void Bitacora::setDia(int _dia){
	dia=_dia;
}
//complegidad O(1)
void Bitacora::setInfo(string _info){
	info=_info;
}
//complegidad O(1)
string Bitacora::getHora(){
	return hora;
}
//obtener el numero deacuerdo al mes
//complegidad O(1)
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
//complegidad O(1)
string Bitacora::getMesStr(){
  return mes;
}
//complegidad O(1)
int Bitacora::getDia(){
	return dia;
}
//complegidad O(1)
string Bitacora::getInfo(){
	return info;
}
//Obtener la cantidad numerica de un mes para ordenar
//complegidad O(1)
int Bitacora::getFecha(){
  return (getMes()*100)+dia;//
}
void Bitacora::show(){
  //complegidad O(1)
	//Oct 9 10:32:24 423.2.230.77:6166 Failed password for illegal user guest
	cout << mes << " " << dia << " " << hora << " " << ip << " " << info  << endl;
}

//Metodo para convertir un string ip en un long
//complegidad O(n)
long long Bitacora::ipToLong(string _ip){
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

//complegidad O(1)
string Bitacora::getIP(){
  return ip;
}

//complegidad O(1)
void Bitacora::setIP(string _ip){
  ip=_ip;
}

//complegidad O(1)
void Bitacora::setHora(string _hora){
  hora=_hora;
}


#endif
