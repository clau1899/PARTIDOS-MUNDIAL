#include<iostream>
using namespace std;
// se usan los datos de partidos ganados y empatados para definir equipos con puntajes iguales
int main(){
	int pais[10];//el array pais es donde guardamos los puntajes de cada pais
	pais[0]=36;// donde 0 es Brasil y su puntaje es 36
	pais[1]=25;// donde 1 es colombia y su puntaje es 25
	pais[2]=24;// donde 2 es uruguay y su puntaje es 24
	pais[3]=23;// donde 3 es argentina y su puntaje es 23
	pais[4]=23;// donde 4 es chile y su puntaje es 23
	pais[5]=21;//donde 5 es peru y su puntaje es 21
	pais[6]=21;//donde 6 es paraguay y su puntaje es 21
	pais[7]=20;//donde 7 es ecuador y su puntaje es 20
	pais[8]=10;//donde 8 es bolivia y su puntaje es 10
	pais[9]=7;//donde 9 es venezuela y su puntaje es 7
	int ganados[10];//el array ganados es el numero de partidos ganados
	ganados[0]=11;
	ganados[1]=7;
	ganados[2]=7;
	ganados[3]=7;
	ganados[4]=6;
	ganados[5]=6;
	ganados[6]=6;
	ganados[7]=6;
	ganados[8]=3;
	ganados[9]=1;
	int empatados[10];//el array empatados es el numero de partidos empatados por cada equipo
	empatados[0]=3;
	empatados[1]=4;
	empatados[2]=3;
	empatados[3]=2;
	empatados[4]=5;
	empatados[5]=3;
	empatados[6]=3;
	empatados[7]=4;
	empatados[8]=1;
	empatados[9]=4;
	int list1[5];//primeros equipos
	int list2[5];//segundos equipos
	list1[0]=8;list2[0]=3;//primer partido
	list1[1]=1;list2[1]=0;//segundo partido
	list1[2]=7;list2[2]=5;//tercer partido
	list1[3]=4;list2[3]=9;//cuarto partido
	list1[4]=6;list2[4]=2;//quinto partido
	int estados[5];//para hallar todas las combinaciones partiremos y modificaremos estados
	for(int i=0;i<5;i++)estados[i]=0;//inicializa el array estado
	int casos_favorables=0;
	while(true){
	    //INICIO DE COMPARACION
		for(int i=0;i<5;i++){
			if(estados[i]==0){pais[list1[i]]+=1;pais[list2[i]]+=1;empatados[list1[i]]+=1;empatados[list2[i]]+=1;}//si empatan
			else if(estados[i]==1){pais[list1[i]]+=3;ganados[list1[i]]++;}//si gana el primero
			else {pais[list2[i]]+=3;ganados[list2[i]]++;}//si gana el segundo
		}//se actualizo los datos segun combinacion
		int s=0;
		int g=0;
        for(int i=0;i<10;i++){
                if(pais[i]>pais[5] or (pais[i]==pais[5] and (ganados[i]>ganados[5] or (ganados[i]==ganados[5] and empatados[i]>empatados[5])))){s++;}
		//se cuenta el numero de paises que superan a peru
                else if(pais[i]==pais[5] and ganados[i]==ganados[5] and empatados[i]==empatados[5]){g++;}
		//se cuenta el numero de paises con iguales resultados que peru
        }
        s++;g--;//si consideramos a peru
        if(s<=5){
		casos_favorables++;
		cout<<endl;
		cout<<"el puesto de peru seria: "<<s<<" con una cantidad de puntos: "<<pais[5]<<" y empata con ";
		if(g==0){cout<<"ningun pais"<<endl;}
		else if(g==1){cout<<" 1 pais"<<endl;}
		else {cout<<g<<" paises"<<endl;}
		cout<<"la fecha 16 debera tener los siguientes resultados:"<<endl;
		if(estados[0]==0){cout<<"bolivia y chile empatan"<<endl;}
		else if(estados[0]==1){cout<<"gana bolivia y pierde chile"<<endl;}
    		else if(estados[0]==2){cout<<"pierde bolivia y gana chile"<<endl;}
		if(estados[1]==0){cout<<"colombia y brasil empatan"<<endl;}
		else if(estados[1]==1){cout<<"gana colombia y pierde brasil"<<endl;}
    		else if(estados[1]==2){cout<<"pierde colombia y gana brasil"<<endl;}
		if(estados[2]==0){cout<<"ecuador y peru empatan"<<endl;}
		else if(estados[2]==1){cout<<"gana ecuador y pierde peru"<<endl;}
    		else if(estados[2]==2){cout<<"pierde ecuador y gana peru"<<endl;}
		if(estados[3]==0){cout<<"argentina y venezuela empatan"<<endl;}
		else if(estados[3]==1){cout<<"argentina gana y venezuela pierde"<<endl;}
    		else if(estados[3]==2){cout<<"argentina pierde y venezuela gana"<<endl;}
		if(estados[4]==0){cout<<"paraguay y uruguay empatan"<<endl;}
		else if(estados[4]==1){cout<<"paraguay gana y uruguay pierde"<<endl; }
    		else if(estados[4]==2){cout<<"paraguay pierde y uruguay gana"<<endl; }
		cout<<endl;
        }//se da la impresion de los posibles casos favorables segun la combinacion actual
        for(int i=0;i<5;i++){
			if(estados[i]==0){pais[list1[i]]-=1;pais[list2[i]]-=1;empatados[list1[i]]-=1;empatados[list2[i]]-=1;}//si empatan
			else if(estados[i]==1){pais[list1[i]]-=3;ganados[list1[i]]--;}//si gana el primero
			else {pais[list2[i]]-=3;ganados[list2[i]]--;}//si gana el segundo
		}//los datos vuelven a ser los originales
        // FIN DE COMPARACION
        // INICIO DE CRECIMIENTO
		int y=0;
		int cant=0;
		while(estados[y]==2 and cant++<5){
			estados[y]=0;
			if(cant==5){break;}
			y++;
		}
		if(cant!=5)estados[y]++;
		else break;// el bucle termina cuando llega a la ultima combinacion;
	// FIN DE CRECIMIENTO
	}
	cout<<"\n\nnumero de casos: "<<casos_favorables<<endl;
	double casos=casos_favorables;
	cout<<"probabilidad de que pase: "<<casos/(3*3*3*3*3)<<endl;
}
