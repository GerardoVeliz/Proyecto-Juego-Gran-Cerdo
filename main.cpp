#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
#include "funciones.h"
int main(){
	system("COLOR 5F");
    srand (time(0));
    setlocale(LC_ALL, "");
    int opcion;
    int suma1,suma2,dado1,dado2,dado3,con=0;
    bool empate=false;
    int i,j;
    int lanzamiento1=1, lanzamiento2=1;
    bool seguir1=false, seguir2=false, turno1=false,turno2=false;
    int trufas_primer[5]={}, trufas_segundo[5]={};
    bool oink=false;
    bool barro1=false,barro2=false;
    bool tres_dados;
    int trufas1,trufas2;
    int veclanzamiento_j1[5]={},veclanzamiento_j2[5]={},maxj1,maxj2;
    int cont_oink1=0,cont_oink2=0;
    int vec_pdv[2]={},ganador,pdv_estadistica=0;
    string nombre_estadistica, nombre_ganador;
    string primero,segundo;
    string jugador1,jugador2;
    int acu =0, maxtiro=0, acu2=0, maxtiro2=0;
    //funcion mostrar menu
    do{
        switch(opcion){
        case 1:
        	   cout<<"X-------------------------------------------------------------X"<<endl;
        	   cout << endl ;
            cout<<"	INGRESAR EL NOMBRE DEL JUGADOR UNO : ";
            cin>>jugador1;
            cin.ignore();
               cout<<"X-------------------------------------------------------------X"<<endl;
               cout << endl ;
            cout<<"	INGRESAR EL NOMBRE DEL JUGADOR DOS : ";
            cin>>jugador2;
            mensaje();
            //SORTEO DE JUGADORES
            quien_arranca(empate, jugador1, jugador2,primero,segundo);
            j=1;
            cout<<endl;
            cout << "	Precione enter para continuar ... "; // ESTA ES LA PAUSA
            cin.ignore();
            cin.get();
            for(i=1;i<=5;i++){
                //JUGADOR 1
                   cout<<"X-------------------------------------------------------------X"<<endl;
                cout<<endl<<"TURNO DE "<<primero<<endl;
                 cout<<"X-------------------------------------------------------------X"<<endl;
                turno1=false;
                do{
                    cout<<endl<<"LANZAMIENTO #"<<lanzamiento1++<<endl<<endl;
                    dado1=tirada();
                    dado2=tirada();
                    cout<<"OBTUVO "<<dado1<<" y "<<dado2<<endl;


                    //PUNTO A
                    PuntoA(dado1,dado2,trufas_primer,i,oink,turno1,acu);
                    //PUNTO B
                    PuntoB(dado1,dado2,trufas_primer,i,oink,turno1,barro1,cont_oink1,lanzamiento1, acu);
                    //PUNTO C
                    PuntoC(dado1,dado2,trufas_primer,i,oink,turno1);
                    //PUNTO D
                    PuntoD(dado1,dado2,trufas_primer,i,oink,turno1,barro1);
                    void jorge(int &maxtiro, int  acu); // aca pregunto por el maximo de tiros
                    //PREGUNTAR SI AMBOS LLEGARON A MAS DE 50 TRUFAS
                    trufas1=acu_trufas(trufas_primer);
                    trufas2=acu_trufas(trufas_segundo);
                    //GUARDO LOS LANZAMIENTO EN EL VECTOR
                    veclanzamiento_j1[i-1]=lanzamiento1;
                    //aca pregunto para ver si estamos en 3 dados y empieza todas las tiradas
                    if((trufas1>=50 && trufas2>=50) && (barro1==false)){
                        cout<<endl<<"COMIENZA EL JUEGO CON 3 DADOS"<<endl;
                        for(j=i;j<=5;j++){
                        //JUGADOR 1
                        cout<<endl<<"TURNO DE "<<primero<<endl;
                        cout<<"----------------"<<endl;
                        turno1=false;
                        lanzamiento1=lanzamiento2=1;
                        do{
                        cout<<endl<<"LANZAMIENTO #"<<lanzamiento1++<<endl<<endl;
                        dado1=tirada();
                        dado2=tirada();
                        dado3=tirada();
                        cout<<"Obtuvo "<<dado1<<" y "<<dado2<<" y "<<dado3<<endl;
                        //PUNTO A
                        PuntoA3(dado1,dado2,dado3,trufas_primer,j,oink,turno1,acu);
                        //PUNTO B
                        PuntoB3(dado1,dado2,dado3,trufas_primer,trufas_segundo,j,oink,turno1,barro1,cont_oink1,lanzamiento1 , acu);
                        //PUNTO C
                        PuntoC3(dado1,dado2,dado3,trufas_primer,j,oink,turno1);
                        //PUNTO D
                        PuntoD3(dado1,dado2,dado3,trufas_primer,trufas_segundo,j,oink,turno1,barro1);
                        void jorge(int &maxtiro, int  acu);
                        //GUARDO LOS LANZAMIENTO EN EL VECTOR
                        veclanzamiento_j1[j-1]=lanzamiento1;
                        Continuar(turno1,seguir1);
                        }while(seguir1==true);
                        mensaje_cuadro(j, lanzamiento1, trufas_primer, primero);
                        cout<<endl;
                        cout << "Precione enter para continuar ... ";
                        cin.ignore();
                        cin.get();

                        //JUGADOR 2
                        cout<<endl<<"TURNO DE "<<segundo<<endl;
                        cout<<"----------------"<<endl;
                        turno2=false;
                        lanzamiento1=lanzamiento2=1;
                        do{
                        cout<<endl<<"LANZAMIENTO #"<<lanzamiento2++<<endl<<endl;
                        dado1=tirada();
                        dado2=tirada();
                        dado3=tirada();
                        cout<<"Obtuvo "<<dado1<<" y "<<dado2<<" y "<<dado3<<endl;
                        //PUNTO A
                        PuntoA3(dado1,dado2,dado3,trufas_segundo,j,oink,turno2, acu);
                        //PUNTO B
                        PuntoB3(dado1,dado2,dado3,trufas_segundo,trufas_primer,j,oink,turno2,barro2,cont_oink2,lanzamiento2, acu);
                        //PUNTO C
                        PuntoC3(dado1,dado2,dado3,trufas_segundo,j,oink,turno2);
                        //PUNTO D
                        PuntoD3(dado1,dado2,dado3,trufas_segundo,trufas_primer,j,oink,turno2,barro2);
                        void jorge(int &maxtiro2, int  acu);
                        //GUARDO LOS LANZAMIENTO EN EL VECTOR
                        veclanzamiento_j2[j-1]=lanzamiento2;
                        Continuar(turno2, seguir2);
                        }while(seguir2==true);
                        mensaje_cuadro(j, lanzamiento2, trufas_segundo, segundo);
                        cout<<endl;
                        cout << "Precione enter para continuar ... ";
                        cin.ignore();
                        cin.get();
                        //cortar aca el juego con el if =5;
                        if(j==5){
                            break;
                        }

                        }
                    }
                    //aca termina juego con 3 dados  sale del if de 3 50 trufas o barro
                    if(j==5){
                    cout<<endl<<"----SALIO DEL WHILE DE 3----"<<endl;
                    }

                    Continuar(turno1,seguir1);
                }while(seguir1==true);
                mensaje_trufas_acu(trufas_primer, trufas_segundo, primero, segundo);
                mensaje_cuadro(i, lanzamiento1, trufas_primer, primero);

                cout<<endl;
                cout << "Precione enter para continuar ... ";
                cin.ignore();
                cin.get();
                if(j==5){
                    break;
                }
                //JUEGO CON 3 DADOS
                while(barro1==true){ // aca es el comienzo de los tres dados SOLO SI BARRO ESTA EN TRUE
                    cout<<endl<<"COMIENZA EL JUEGO CON 3 DADOS"<<endl;
                    barro1=false;
                    for(j=i;j<=5;j++){
                    //JUGADOR 2
                    cout<<endl<<"TURNO DE "<<segundo<<endl;
                    cout<<"----------------"<<endl;
                    turno2=false;
                    lanzamiento1=lanzamiento2=1;
                    do{
                        cout<<endl<<"LANZAMIENTO #"<<lanzamiento2++<<endl<<endl;
                        dado1=tirada();
                        dado2=tirada();
                        dado3=tirada();
                        cout<<"Obtuvo "<<dado1<<" y "<<dado2<<" y "<<dado3<<endl;
                        //PUNTO A
                        PuntoA3(dado1,dado2,dado3,trufas_segundo,j,oink,turno2, acu);
                        //PUNTO B
                        PuntoB3(dado1,dado2,dado3,trufas_segundo,trufas_primer,j,oink,turno2,barro2,cont_oink2,lanzamiento2,acu);
                        //PUNTO C
                        PuntoC3(dado1,dado2,dado3,trufas_segundo,j,oink,turno2);
                        //PUNTO D
                        PuntoD3(dado1,dado2,dado3,trufas_segundo,trufas_primer,j,oink,turno2,barro2);
                        //GUARDO LOS LANZAMIENTO EN EL VECTOR
                        veclanzamiento_j2[j-1]=lanzamiento2;
                        void jorge(int &maxtiro2, int  acu);

                        Continuar(turno2, seguir2);
                    }while(seguir2==true);
                    mensaje_cuadro(j, lanzamiento2, trufas_segundo, segundo);
                    cout<<endl;
                    cout << "Precione enter para continuar ... ";
                    cin.ignore();
                    cin.get();
                    //cortar aca el juego con el if =5;
                    if(j==5){
                        break;
                    }
                    //JUGADOR 1
                    cout<<endl<<"TURNO DE "<<primero<<endl;
                    cout<<"----------------"<<endl;
                    turno1=false;
                    do{
                        cout<<endl<<"LANZAMIENTO #"<<lanzamiento1++<<endl<<endl;
                        dado1=tirada();
                        dado2=tirada();
                        dado3=tirada();
                        cout<<"Obtuvo "<<dado1<<" y "<<dado2<<" y "<<dado3<<endl;
                        //PUNTO A
                        PuntoA3(dado1,dado2,dado3,trufas_primer,j+1,oink,turno1,acu);
                        //PUNTO B
                        PuntoB3(dado1,dado2,dado3,trufas_primer,trufas_segundo,j+1,oink,turno1,barro1,cont_oink1,lanzamiento1,acu);
                        //PUNTO C
                        PuntoC3(dado1,dado2,dado3,trufas_primer,j+1,oink,turno1);
                        //PUNTO D
                        PuntoD3(dado1,dado2,dado3,trufas_primer,trufas_segundo,j+1,oink,turno1,barro1);
                        void jorge(int &maxtiro1, int  acu);
                        //GUARDO LOS LANZAMIENTO EN EL VECTOR
                        veclanzamiento_j1[j]=lanzamiento1;
                        Continuar(turno1,seguir1);
                    }while(seguir1==true);
                    mensaje_cuadro(j+1, lanzamiento1, trufas_primer, primero);
                    cout<<endl;
                    cout << "Precione enter para continuar ... ";
                    cin.ignore();
                    cin.get();

                    }



                }
                //aca termina juego con 3 dados
                if(j==5){
                cout<<endl<<"----SALIO DEL WHILE DE 3----"<<endl;
                break;
                }

                //JUGADOR 2
                cout<<endl<<"TURNO DE "<<segundo<<endl;
                cout<<"----------------"<<endl;
                turno2=false;
                do{
                    cout<<endl<<"LANZAMIENTO #"<<lanzamiento2++<<endl<<endl;
                    dado1=tirada();
                    dado2=tirada();
                    cout<<"Obtuvo "<<dado1<<" y "<<dado2<<endl;
                    //PUNTO A
                    PuntoA(dado1,dado2,trufas_segundo,i,oink,turno2,acu);
                    //PUNTO B
                    PuntoB(dado1,dado2,trufas_segundo,i,oink,turno2,barro2,cont_oink2,lanzamiento2,acu);
                    //PUNTO C
                    PuntoC(dado1,dado2,trufas_segundo,i,oink,turno2);
                    //PUNTO D
                    PuntoD(dado1,dado2,trufas_segundo,i,oink,turno2,barro2);
                    //PREGUNTAR SI AMBOS LLEGARON A MAS DE 50 TRUFAS
                    trufas1=acu_trufas(trufas_primer);
                    trufas2=acu_trufas(trufas_segundo);
                    //GUARDO LOS LANZAMIENTO EN EL VECTOR
                    veclanzamiento_j2[i-1]=lanzamiento2;
                    if((trufas1>=50 && trufas2>=50) && (barro2==false)){
                        cout<<endl<<"COMIENZA EL JUEGO CON 3 DADOS"<<endl;
                        for(j=i;j<=5;j++){
                        //JUGADOR 2
                        cout<<endl<<"TURNO DE "<<segundo<<endl;
                        cout<<"----------------"<<endl;
                        turno2=false;
                        lanzamiento1=lanzamiento2=1;
                        do{
                        cout<<endl<<"LANZAMIENTO #"<<lanzamiento2++<<endl<<endl;
                        dado1=tirada();
                        dado2=tirada();
                        dado3=tirada();
                        cout<<"Obtuvo "<<dado1<<" y "<<dado2<<" y "<<dado3<<endl;
                        //PUNTO A
                        PuntoA3(dado1,dado2,dado3,trufas_segundo,j,oink,turno2,acu);
                        //PUNTO B
                        PuntoB3(dado1,dado2,dado3,trufas_segundo,trufas_primer,j,oink,turno2,barro2,cont_oink2,lanzamiento2,acu);
                        //PUNTO C
                        PuntoC3(dado1,dado2,dado3,trufas_segundo,j,oink,turno2);
                        //PUNTO D
                        PuntoD3(dado1,dado2,dado3,trufas_segundo,trufas_primer,j,oink,turno2,barro2);
                        //GUARDO LOS LANZAMIENTO EN EL VECTOR
                        veclanzamiento_j2[j-1]=lanzamiento2;

                        Continuar(turno2, seguir2);
                        }while(seguir2==true);
                        mensaje_cuadro(j, lanzamiento2, trufas_segundo, segundo);
                        cout<<endl;
                        cout << "Precione enter para continuar ... ";
                        cin.ignore();
                        cin.get();
                        //cortar aca el juego con el if =5;
                        if(j==5){
                            break;
                            }

                        //JUGADOR 1
                        cout<<endl<<"TURNO DE "<<primero<<endl;
                        cout<<"----------------"<<endl;
                        turno1=false;
                        lanzamiento1=lanzamiento2=1;
                        do{
                        cout<<endl<<"LANZAMIENTO #"<<lanzamiento1++<<endl<<endl;
                        dado1=tirada();
                        dado2=tirada();
                        dado3=tirada();
                        cout<<"Obtuvo "<<dado1<<" y "<<dado2<<" y "<<dado3<<endl;
                        //PUNTO A
                        PuntoA3(dado1,dado2,dado3,trufas_primer,j+1,oink,turno1,acu);
                        //PUNTO B
                        PuntoB3(dado1,dado2,dado3,trufas_primer,trufas_segundo,j+1,oink,turno1,barro1,cont_oink1,lanzamiento1,acu);
                        //PUNTO C
                        PuntoC3(dado1,dado2,dado3,trufas_primer,j+1,oink,turno1);
                        //PUNTO D
                        PuntoD3(dado1,dado2,dado3,trufas_primer,trufas_segundo,j+1,oink,turno1,barro1);
                        //GUARDO LOS LANZAMIENTO EN EL VECTOR
                        veclanzamiento_j1[j]=lanzamiento1;


                        Continuar(turno1,seguir1);
                        }while(seguir1==true);
                        mensaje_cuadro(j+1, lanzamiento1, trufas_primer, primero);
                        cout<<endl;
                        cout << "Precione enter para continuar ... ";
                        cin.ignore();
                        cin.get();


                        }
                    }
                    if(j==5){
                            break;
                            }
                    Continuar(turno2,seguir2);

                }while(seguir2==true);

                mensaje_trufas_acu(trufas_primer, trufas_segundo, primero, segundo);
                mensaje_cuadro(i, lanzamiento2, trufas_segundo, segundo);
                cout<<endl;
                cout << "Precione enter para continuar ... ";
                cin.ignore();
                cin.get();
                if(j==5){
                            break;
                            }
                //JUEGO CON 3 DADOS
                while(barro2==true){
                    cout<<endl<<"COMIENZA EL JUEGO CON 3 DADOS"<<endl;
                    barro2=false;
                    for(j=i+1;j<=5;j++){
                    //JUGADOR 1
                    cout<<endl<<"TURNO DE "<<primero<<endl;
                    cout<<"----------------"<<endl;
                    turno1=false;
                    lanzamiento1=lanzamiento2=1;
                    do{
                        cout<<endl<<"LANZAMIENTO #"<<lanzamiento1++<<endl<<endl;
                        dado1=tirada();
                        dado2=tirada();
                        dado3=tirada();
                        cout<<"Obtuvo "<<dado1<<" y "<<dado2<<" y "<<dado3<<endl;
                        //PUNTO A
                        PuntoA3(dado1,dado2,dado3,trufas_primer,j,oink,turno1,acu);
                        //PUNTO B
                        PuntoB3(dado1,dado2,dado3,trufas_primer,trufas_segundo,j,oink,turno1,barro1,cont_oink1,lanzamiento1,acu);
                        //PUNTO C
                        PuntoC3(dado1,dado2,dado3,trufas_primer,j,oink,turno1);
                        //PUNTO D
                        PuntoD3(dado1,dado2,dado3,trufas_primer,trufas_segundo,j,oink,turno1,barro1);
                        //GUARDO LOS LANZAMIENTO EN EL VECTOR
                        veclanzamiento_j1[j-1]=lanzamiento1;



                        Continuar(turno1,seguir1);
                    }while(seguir1==true);
                    mensaje_cuadro(j, lanzamiento1, trufas_primer, primero);
                    cout<<endl;
                    cout << "Precione enter para continuar ... ";
                    cin.ignore();
                    cin.get();
                    //cortar aca el juego con el if =5;
                    if(j==5){
                        break;
                    }
                    //JUGADOR 2
                    cout<<endl<<"TURNO DE "<<segundo<<endl;
                    cout<<"----------------"<<endl;
                    turno2=false;
                    do{
                        cout<<endl<<"LANZAMIENTO #"<<lanzamiento2++<<endl<<endl;
                        dado1=tirada();
                        dado2=tirada();
                        dado3=tirada();
                        cout<<"Obtuvo "<<dado1<<" y "<<dado2<<" y "<<dado3<<endl;
                        //PUNTO A
                        PuntoA3(dado1,dado2,dado3,trufas_segundo,j,oink,turno2,acu);
                        //PUNTO B
                        PuntoB3(dado1,dado2,dado3,trufas_segundo,trufas_primer,j,oink,turno2,barro2,cont_oink2,lanzamiento2,acu);
                        //PUNTO C
                        PuntoC3(dado1,dado2,dado3,trufas_segundo,j,oink,turno2);
                        //PUNTO D
                        PuntoD3(dado1,dado2,dado3,trufas_segundo,trufas_primer,j,oink,turno2,barro2);
                        //GUARDO LOS LANZAMIENTO EN EL VECTOR
                        veclanzamiento_j2[j-1]=lanzamiento2;

                        Continuar(turno2, seguir2);
                    }while(seguir2==true);
                    mensaje_cuadro(j, lanzamiento2, trufas_segundo, segundo);
                    }



                }
                //aca termina juego con 3 dados
                if(j==5){
                cout<<endl<<"----SALIO DEL WHILE DE 3----"<<endl;
                }
                //CORTA SI TERMINO LA RONDA DE 3 DADOS
                if(j==5){
                    break;
                }
                //PONER EN CERO LANZAMIENTOS
                lanzamiento1=lanzamiento2=1;
            }
            //agregar los lanzamientos maximos
            maxj1 = hallar_maximo(veclanzamiento_j1);// HALLARMAXIMO BUSCA EL MAYOR EN EL VECTOR DE LANZAMIENTOS
            maxj2 = hallar_maximo(veclanzamiento_j2);// IDEM , PERO DEL VECTOR DE LANZAMIENTOS 2
            mensaje_trufas_acu(trufas_primer, trufas_segundo, primero, segundo);// ESTE MUETRA EL RESUMEN DE TODAS LAS TRUFAS QUE TENGO EN TOTAL
            cuadro_final(trufas_primer, trufas_segundo, primero, segundo,cont_oink1,cont_oink2,maxj1,maxj2,vec_pdv,maxtiro,maxtiro2);// DETERMINA LOS PDV
            mostrar_ganador(vec_pdv,primero,segundo,ganador,nombre_ganador,nombre_estadistica,pdv_estadistica);// MUESTRA EL GANADOR
            poner_encero(trufas_primer,trufas_segundo,cont_oink1,cont_oink2,trufas1,trufas2,vec_pdv);// PONE EN CERO LOS CONTADORES Y VECTORES POR SI EL USUARIO QUIERE VOLVER A JUGAR
            break;
        case 2:
            cout<<endl<<"EL JUGADOR QUE OBTUVO MAS TIEMPO DE VICTORIA FUE : : "<<nombre_estadistica<<" con "<<pdv_estadistica<<" PDV"<<endl<<endl;
            break;
        case 3:
        	   cout<<"X-------------------------------------------------------------X"<<endl;
            cout<<"|	    GRUPO LOS CERDITOS NINJA			      |" << endl;
              cout<<"X-------------------------------------------------------------X"<<endl;
            cout<<"| APELLIDO Y NOMBRE      |            LEGAJO  		      |"<<endl;
              cout<<"X-------------------------------------------------------------X"<<endl;
            cout<<"|  Veliz, Gerardo                      17111		      |"<<endl;
            cout<<"|  Ordo�ez, Javier                     26040		      |"<<endl;
            cout<<"|  Gregorio, Maria Sol                 24280		      |"<<endl;
            cout<<"|  Yparraguirre Yauri, Les             25947		      |"<<endl;
               cout<<"X-------------------------------------------------------------X"<<endl;
            break;
        default:
            if(con==0){
                con=1;
            }
            else{
                cout<<endl<<"INGRESE UNA OPCION CORRECTA"<<endl;
            }
            break;
        }
        mostrar_menu();
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
    }while(opcion!=0);

    return 0;
}
