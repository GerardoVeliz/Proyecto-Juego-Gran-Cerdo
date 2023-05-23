#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
//definiciones de funcion
/*void  jorge(int &maxtiro ,int  acu){

if (acu>maxtiro ){
    maxtiro=acu;
}
}*/


void mostrar_menu(){
    cout<<endl;
    cout<<"X-------------------------------------------------------------X"<<endl;
    cout<<"|         "<<" BIENVENIDO AL GRAN CERDO"<<"                           |"<<endl;
 cout<<"x-------------------------------------------------------------x"<<endl;
    cout<<"|         "<<"1 - JUGAR"<<"                                           |"<<endl;
    cout<<"|         "<<"2 - ESTADISTICAS"<<"                                    |"<<endl;
    cout<<"|         "<<"3 - CERDITOS"<<"                                        |"<<endl;
 cout<<"X-------------------------------------------------------------X"<<endl;
    cout<<"|         "<<"0 - SALIR"<<"                                           |"<<endl;
     cout<<"x-------------------------------------------------------------x"<<endl;
    cout<<endl;
}
///ES UN ACUMULADOR DE TRUFAS DE LAS RONDAS, SUMA LAS TRUFAS EN EL VECTOR DE RONDAS Y TE LO RETORNA
int acu_trufas(int trufas[5]){
    int acu=0;
    for(int i=0;i<5;i++){
        acu+=trufas[i];
    }
    return acu;
}
/// ESTA FUNCION BUSCA EL MAXIMO EN EL VECTOR DE 5 RONDA, LUEGO RETORNA CUAL FUE EL MAXIMO DE LAS RONDAS
int hallar_maximo(int vec[5]){
    int i,maximo=0;
    maximo=vec[0];
    for(i=1;i<5;i++){
        if(vec[i]>maximo){
            maximo=vec[i];
        }
    }
    return maximo;
}
/// ESTA FUNCION ES PARA MOSTRAR LA INTERFAZ QUE VA A VER EL USUARIO , PARA QUE INGRESE SUS NOMBRES LO GUARDO EN UN STRING
void Ingreso_nombres(){
    string jugador1,jugador2;
       cout<<"X-------------------------------------------------------------X"<<endl;
    cout<<"INGRESAR EL NOMBRE DEL JUGADOR UNO : ";
        cin>>jugador1;
        cin.ignore();
           cout<<"X-------------------------------------------------------------X"<<endl;
        cout<<"INGRESAR EL NOMBRE DEL JUGADOR DOS : ";
        cin>>jugador2;
        cout<<endl<<" PREPARATE PARA JUGAR AL GRAN CERDO! "<<endl;
        cout<<"X-------------------------------------------------------------X"<<endl;
        cout<<"SE SORTEARAN LOS DADOS PARA INDICAR QUE JUGADOR EMPIEZA PRIMERO"<<endl<<endl;
          cout<<"X-------------------------------------------------------------X"<<endl;
}
///MENSAJE
void mensaje(){
      cout<<"X-------------------------------------------------------------X"<<endl;
    cout<<"SE SORTEARAN LOS DADOS PARA INDICAR QUE JUGADOR EMPIEZA PRIMERO"<<endl;
    cout<<"X-------------------------------------------------------------X"<<endl;
}
///FUNCION DE LOS DADOS,GENERAA UN NUMERO RANDOM
int tirada(){
  return (rand() % 6)+1;
}
///SUMA DOS VARIBLES
int sumar(int n1, int n2){
    int resultado;
    resultado = n1+n2;
    return resultado;
}
/// ESTA FUNCION DEVUELVE TRUE O FALSE SI LOS DOS INT SON IGUALES
bool empatar(int a, int b){
    if(a==b){
        return true;
    }
    else{
        return false;
    }

}
///ESTA FUNCION MUESTRA EL CUADRO DE RESUMEN  CADA VEZ QUE TERMINA UN JUGADOR , ME PIDE A=NRO DE RONDA QUE LO SACO DEL X DEL FOR , LANZ=LANZAMIENTOS,TRUFAS DE LA RONDA QUE LO SACA DEL VECTOR EN EL INDICE A-1, Y EL NOMBRE DEL PRIMER JUGADOR
void mensaje_cuadro(int a, int lanz, int trufas[5],string primer){
    cout<<"RESUMEN DE "<<primer<<endl;
    cout<<"+---------------------------+"<<endl;
    cout<<"| RONDAS #"<<a<<"                 |"<<endl;
    cout<<"| TRUFAS DE LA RONDA: "<<trufas[a-1]<<"    |"<<endl;
    cout<<"| LANZAMIENTOS: "<<lanz-1<<"           |"<<endl;
    cout<<"+---------------------------+"<<endl;
}
///ESTA FUNCION ME MUESTRA UN MINI RESUMEN POR CADA TIRO , DE CUANTAS TRUFAS TIENE CADA JUGADOR EN EN TOTAL DE TODAS LAS RONDA.
void mensaje_trufas_acu(int trufas_primer[5], int trufas_segundo[5],string primer, string segundo){
    int acu1=0,acu2=0;
    cout << endl ;
    cout<<"X------------------------------------------------------------------------------------------------------------X"<<endl;
    cout<<"                                                "<<"GRAN CERDO"<<endl;
    cout<<"X------------------------------------------------------------------------------------------------------------X"<<endl;
    cout<<primer<<": ";
    for(int i=0;i<5;i++){
        acu1+=trufas_primer[i];
    }
    cout<<acu1<<" trufas acumuladas";
    cout<<"           "<<segundo<<": ";
    for(int i=0;i<5;i++){
        acu2+=trufas_segundo[i];
    }
    cout<<acu2<<" trufas acumuladas"<<endl<<endl;
}
///CUADRO FINAL SE MUESTRA EL FINAL DE TODAS LAS RONDAS CUENTA LOS PDV Y DETERMINA QUIEN GANA
void cuadro_final(int trufas_primer[5], int trufas_segundo[5], string primer, string segundo,int oinks1,int oinks2,int lanzj1,int lanzj2,int PDV[2], int maxtiro1, int maxtiro2){
    int acu1=0,acu2=0;
    acu1=acu_trufas(trufas_primer);//ACA GUARDO ELTOTAL DE TODAS LAS TRUFAS DEL JUGADOR 1
    acu2=acu_trufas(trufas_segundo);// ACA GUARDO EL TOTAL DE TRUFAS DEL JUGADOR 2

    cout<<"GRAN CERDO"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"HITO                     "<<primer<<"                           "<<segundo<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Mas trufas en total      ";
    if(acu1>acu2){ // COMPARO LA CANTIDAD DE LAS TRUFAS DE CADA JUGADOR
        cout<<"5 PDV ("<<acu1<<" trufas)";// LE SUMO 5 PDV AL MAYOR
        PDV[0]+=5;// Y LO GUARDO EN EL VECTOR DE PDV EL INDICE 0 ESPARA EL JUGADOR 1 ACUMULO AHI LOS PDV
    }
    else{
            if(acu1<acu2){// PREGUNTO OTRA VEZ PORQUE , EN ESTE CASO EL JUGADOR 1 NO GANO NINGUN PDV
            cout<<"0 PDV ("<<acu1<<" trufas)";// MUESTRA LAS 0 PDV DEL JUGADOR 1
            }
            else{
                cout<<"5 PDV ("<<acu1<<" trufas)";// LO MISMO QUE AL PRINCIPIO
                PDV[0]+=5;
            }
    }
    cout<<"              ";
    if(acu2>acu1){
        cout<<"5 PDV ("<<acu2<<" trufas)"<<endl;
        PDV[1]+=5;
    }
    else{
            if(acu2<acu1){ // PORQUE PREGUNTA DOS VECES
            cout<<"0 PDV ("<<acu2<<" trufas)"<<endl;
            }
            else{
                cout<<"5 PDV ("<<acu2<<" trufas)"<<endl;
                PDV[1]+=5;
            }
    }
    cout<<"Cada 50 trufas           ";
    cout<<acu1/50<<" PDV ("<<(acu1/50)*50<<" trufas)               ";// ACA MUESTROS LOS PDV DE CADA50 DIVIDO EL ACU/50 ESO DA LOS PDV , Y EL OTRO SON LAS TRUFAS
    PDV[0]+=(acu1/50);// ACAACUMULO LOS PDV EN EL VECTOR DE PDV
    cout<<acu2/50<<" PDV ("<<(acu2/50)*50<<" trufas)"<<endl;
    PDV[1]+=(acu2/50);
    cout<<"Oinks                    ";
    cout<<oinks1*2<<" PDV ("<<oinks1<<" oinks)                ";// MUESTROS LOS PDV DE OINK , CADA OINK VALE 2 PDV, MULTIPLICO LOS OINK*2
    PDV[0]+=(oinks1*2);//ACUMULO EN EL VECTOR DE PDV
    cout<<oinks2*2<<" PDV ("<<oinks2<<" oinks)"<<endl;
    PDV[1]+=(oinks2*2);
    cout<<"Cerdo codicioso          ";// RONDA CON MAYOR CANTIDAD DE LANZAMIENTOS, COMPARO
    if(lanzj1>lanzj2){
        cout<<"3 PDV ("<<lanzj1<<" lanzamientos)"; // COMPARO Y ACUMULO
        PDV[0]+=3;
    }
    else{
        if(lanzj1<lanzj2){
            cout<<"0 PDV ("<<lanzj1<<" lanzamientos)";
        }
        else{
            cout<<"3 PDV ("<<lanzj1<<" lanzamientos)";
            PDV[0]+=3;
        }
    }
    cout<<"         ";
    if(lanzj2>lanzj1){
        cout<<"3 PDV ("<<lanzj2<<" lanzamientos)"<<endl;
        PDV[1]+=3;
    }
    else{
        if(lanzj2<lanzj1){
            cout<<"0 PDV ("<<lanzj2<<" lanzamientos)"<<endl;
        }
        else{
            cout<<"3 PDV ("<<lanzj2<<" lanzamientos)"<<endl;
            PDV[1]+=3;
        }
    }
    /*
    cout<<"jorge      ";
    if (maxtiro1>maxtiro2){
        cout<<"1PDV ("<<maxtiro1<<" trufas)"<<endl;
        PDV[0]+=1;}
     else{
        if(maxtiro1<maxtiro2){
            cout<<"0 PDV ("<<maxtiro1<<" lanzamientos)"<<endl;
        }
         else{
            cout<<"1 PDV ("<<maxtiro1<<" lanzamientos)";
            PDV[0]+=1;
        }
    }

    if (maxtiro2>maxtiro1){
        cout<<"1PDV ("<<maxtiro2<<" trufas)"<<endl;
        PDV[1]+=1;}
     else{
        if(maxtiro2<maxtiro1){
            cout<<"0 PDV ("<<maxtiro2<<" lanzamientos)"<<endl;
        }
         else{
            cout<<"1 PDV ("<<maxtiro2<<" lanzamientos)";
            PDV[1]+=1;
        }
    }*/


    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"TOTAL                    ";
    cout<<PDV[0]<<" PDV                       "<<PDV[1]<<" PDV"<<endl;// MUESTRO LOS PDV DE LOS DOS
}
///ESTA FUNCION DEFINE QUIEN ARRANCA PRIMERO , DEFINE QUIEN ES EL JUGADOR 1 Y QUIEN ES EL JUGADOR 2
void quien_arranca(bool empate, string player1, string player2, string &primero, string &segundo){
    srand (time(0));
    empate=false;// EL BOOL ESTE SIRVE PARA QUE SI LOS DADOS SON IGUALES SE PASE A TRUE Y ENTRE EN OTRO TIRO
    int dado1,dado2,suma1,suma2;
    do{
                cout<<" EL JUGADOR "<<player1<<" TIRO LOS DADOS :";
                dado1= tirada();
                dado2= tirada();
                suma1=dado1+dado2;
                cout<<endl<<"      OBTUVO: "<<suma1<<" DE PUNTAJE "<<endl;
                cout<<" EL JUGADOR "<<player2<<" TIRO LOS DADOS: ";
                dado1= tirada();
                dado2= tirada();
                suma2=dado1+dado2;
                cout<<endl<<"      OBTUVO: "<<suma2<<" DE PUNTAJE  "<<endl;
                empate = empatar(suma1,suma2);// USAMOS FUNCION EMPATAR QUE RETORNA UN TRUE O FALSE , SI LOS PARAMETROS SON IGUALES O NO
                if(empate==true){ // SI ES TRUE SE VUELVEN A TIRAR LOS DADOS , ACA ENTRA AL WHILE QUE SE ACTIVA CON EMPATE EN TRUE
                cout<<"----------------------------------------------------"<<endl;
                cout<<"AMBOS JUGADORES EMPATARON SE VUELVE A TIRAR DE NUEVO"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                }

            }while(empate==true); // SE EJECUTA MIENTRAS EMPATE ESTE EN TRUE

            if(suma1>suma2){// ACA COMPARA PARA VER QUIEN EMPIEZA Y DEFINE QUIEN ESE EL JUGADOR 1 Y QUIEN ES JUGADOR 2
                primero=player1;
                segundo=player2;
            }
            else{
                primero=player2;
                segundo=player1;
            }
}
//TIROS CON DOS DADOS!!
///ESTA FUNCION , RELIZA UN CLASIFICACION DE TIRO , EN ESTE CASO EL TIRO TIPO C , EN DONDE SALGA UN AS EN CUALQUIERA DADO, PIERDO  LAS TRUFAS DE LA  RONDA.
void PuntoC(int n1,int n2,int trufas[5],int i,bool &oink,bool &turno){
    if((n1!=n2) && (n1 == 1 || n2 == 1))
        {
        cout<<endl<< "PIERDES TODAS LAS TRUFAS ACUMULADAS DE LA RONDA " <<endl;
        cout<<"!PIERDES TU TURNO!"<<endl;
        trufas[i-1]=0;
        turno=true;// LA VARIABLE TURNO , EN REALIDAD ES CORTA TURNO , XQ LA USAMOS PARA CORTAR LA RONDA Y QUE PASE AL OTRO JUAGADOR
        oink=false;
        }
}
///ESTA FUNCION , RELIZA UN CLASIFICACION DE TIRO , EN ESTE CASO TIRO TIPO D, EN EL CUAL SI SACO DOS ASES , PIERDO TODAS LAS TRUFAS ACUMULADAS DE TODAS LAS RONDAS
void PuntoD(int n1,int n2,int trufas[5],int i,bool &oink,bool &turno,bool &barro){
    if( (n1==n2) && (n1==1) ){
        oink=false;
        cout<<endl<<"|TE HUNDISTE EN EL BARRO|"<<endl;
        cout<<endl<< "PIERDES TODAS LAS TRUFAS ACUMULADAS HASTA EL MOMENTO " <<endl;
        cout<<"!PIERDES TU TURNO!"<<endl;
        for(int x=0;x<5;x++){//PONEMOS EN 0 EL VECTOR DE TRUFAS
            trufas[x]=0;
        }
        turno=true;// SE ACTIVA EL CORTA TURNO
        barro=true;// SE ACTIVA EL BOOL DE BARRO , ESTE ACTIVA LOS TRES DADOS
    }
}
///ESTA FUNCION , RELIZA UN CLASIFICACION DE TIRO , EN ESTE CASO TIRO A, EN EL QUE SI LOS DADOS SON DISTINTOS Y NO SON ASES ,SE SUMAN LOS VALORES
void PuntoA(int n1, int n2, int trufas[5], int x,bool &oink,bool &turno , int &acu){
    if( (n1!=n2) && (n1!=1 && n2!=1) )
        {
            turno=false;// ESTE NO CORTA LA RONDA
            oink=false;
            trufas[x-1]+=n1+n2;
            acu =n1+n2;
            cout<<endl<<"¡SUMASTE: " <<n1+n2<<" TRUFAS! "<<endl;
        }
}
///ESTA FUNCION , RELIZA UN CLASIFICACION DE TIRO, EN ESTE CASO B, EL TIRO OINK, SI LOS DADOS SON DISTINTOS DE AS , Y LOS DOS SON IGUALES , SUMA LOS DOS DADOS Y LOS DUPLICA, Y HACE LA TIRADA OBLIGATORIA
void PuntoB(int n1,int n2,int trufas[5],int x,bool &oink,bool &turno,bool &barro,int &cont_oink,int &lanzamiento,int &acu){
    if((n1==n2) && (n1!=1 && n2!=1))
        {
        //turno=true;
        oink=true;
        trufas[x-1]+=(n1+n2)*2;
        acu=(n1+n2)*2;
        cout<<endl<<"HICISTE UN OINK! DUPLICASTE LAS TRUFAS OBTENIDAS EN EL LANZAMIENTO "<<endl;
        cout<<endl<<"¡SUMASTE:  " <<(n1+n2)*2<<" TRUFAS! "<<endl;//SUMA Y DUPLICA LOS DADOS
        cont_oink++;// ESTE ES PARA LOS HITOS VA CONTANDO LOS OINK
        }
    while(oink==true){// EL OINK EN TRUE ACTIVA LA TIRADA OBLIGATORIA Y CLASIFICA TAMBIEN ESTE TIRO , PUEDE SALIR OTRO OINK Y HAY QUE HACER OTRA TIRADA OBLIGATORIA

        cout<<endl<<"TIRABA OBLIGATORIA"<<endl;
        cout<<"---------------"<<endl;
        cout<<endl<<"LANZAMIENTO #"<<lanzamiento++<<endl<<endl;
        n1=tirada();
        n2=tirada();
        cout<<"Obtuvo "<<n1<<" y "<<n2<<endl;
        PuntoC(n1,n2,trufas,x,oink,turno);
        //PuntoD(n1,n2,trufas,x,oink,turno,barro);
        //PUNTO D // LO PONGO MANUAL
        if( (n1==n2) && (n1==1) ){
        oink=false;
        turno=true;//CORTA TURNO
        barro=true;//ACTIVA BARRO Y ACTIVA LOS TRES DADOS
        cout<<endl<<"|TE HUNDISTE EN EL BARRO|"<<endl;
        cout<<endl<< "PIERDES TODAS LAS TRUFAS ACUMULADAS HASTA EL MOMENTO " <<endl;
        cout<<"!PIERDES TU TURNO!"<<endl;
        for(int x=0;x<5;x++){//PIERDE TODAS LAS TRUFAS DEL VECTOR
            trufas[x]=0;
        }
        }
        PuntoA(n1,n2,trufas,x,oink,turno, acu);
        //PUNTO B// LO HAGO MANUAL TIENDE A CICLO INFINITO CON FUNCION
        if((n1==n2) && (n1!=1 && n2!=1))
        {
        turno=true;
        oink=true;
        trufas[x-1]+=(n1+n2)*2;
        acu=(n1+n2)*2;
        cout<<endl<<"HICISTE UN OINK! DUPLICASTE LAS TRUFAS OBTENIDAS EN EL LANZAMIENTO "<<endl;
        cout<<endl<<"¡SUMASTE:  " <<(n1+n2)*2<<" TRUFAS! "<<endl;
        cont_oink++;
        }
        //PuntoD(n1,n2,trufas,x,oink,turno,barro);
        //PuntoC(n1,n2,trufas,x,oink,turno);
    }
}
///ESTA FUNCION ES LA QUE CORTA LAS RONDA , SI TURNO ES TRUE , Y LA QUE PREGUNTA SI DESEA SEGUIR TIRANDO , CUANDO TURNO ES FALSE Y SEGUIR ES TRUE
void Continuar(bool &turno,bool &seguir){
    if(turno==true){
        seguir=false;
    }
    else{
    cout<<endl<<"DESEA SEGUIR JUGANDO S(1)/N(0)"<<endl;
    cin>>seguir;
    }
}
///ESTA FUNCION PREGUNTA , SI LAS TRUFAS ACUMULADAS DE LA RONDA , LLEGARON A 50 , O SI EL BOOL DE BARRO SE ACTIVO , ME RETORNA TRUE O FALSE .
bool dados_triples(int primer[5],int segundo[5],bool barro1,bool barro2){
    int acu1=0,acu2=0;
    for(int i=0;i<5;i++){
        acu1+=primer[i];
        acu2+=segundo[i];
    }
    if( (acu1>=50 && acu2>=50) || (barro1==true || barro2==true)){
        return true;
    }
    else{
        return false;
    }
}
//FUNCIONES DE TRES DADOS
///AL IGUAL QUE LA DE DOS DADOS , SI PIERDE TODAS LAS TRUFAS DE LA RONDA Y CORTA EL TURNO DE JUGADOR
void PuntoC3(int n1,int n2, int n3, int trufas[5],int i,bool &oink,bool &turno){
    if((n1!=n2 && n2!=n3 && n1!=n3) && (n1 == 1 || n2 == 1 || n3==1))
        {
        cout<<endl<< "PIERDES TODAS LAS TRUFAS ACUMULADAS DE LA RONDA " <<endl;
        cout<<"!PIERDES TU TURNO!"<<endl;
        trufas[i-1]=0;
        turno=true;
        oink=false;
        }
}
///ESTA FUNCION PREGUNTA SI LOS DADOS DAN LA CONDICION PARA HUNDIRSE EN EL BARRO,( DOS ASES, Y UNO DISTINTO DE AS)
void PuntoD3(int n1,int n2,int n3,int trufas[5],int trufasotro[5],int i,bool &oink,bool &turno,bool &barro){// EL VECTOR TRUFAS ES EL VECTOR DEL J1 Y EL VECTOR TRUFASOTRO ES DE L J2
    if( (n1==1 && n2==1 && n3!=1) || (n1==1 && n2!=1 && n3==1) ||(n1!=1 && n2==1 && n3==1) ){// ESTO ES ME HUNDO EN EL BARRO NORMAL
        oink=false;
        cout<<endl<<"|TE HUNDISTE EN EL BARRO|"<<endl;
        cout<<endl<< "PIERDES TODAS LAS TRUFAS ACUMULADAS HASTA EL MOMENTO " <<endl;
        cout<<"!PIERDES TU TURNO!"<<endl;
        for(int x=0;x<5;x++){//ESTE FOR PONE EN CERO EL VECTOR TRUFAS
            trufas[x]=0;// PIERDO TODAS LAS TRUFAS DE HASTA EL MOMENTO
        }
        turno=true;//CORTA EL TURNO
        barro=true;//ACTIVA EL BOOL DE BARRO
    }
        //EL OTRO CASO,ES QUE SI TENGO TODOS MIS DADOS CON ASES
    if(n1==1 && n2==1 && n3==1){//PREGUNTO SI TODOS SON ASES , SI ES ASI LAS TRUFAS QUE TENIA SE LAS TENGO QUE PASAR AL OTRO JUGADOR
        oink=false;
        int acu1=0;
        acu1= acu_trufas(trufas);//GUARDO EN ACU1 , LA SUMA DE EL VECTOR DE TRUFAS , CON LA FUNCION QUE RETORNA ESO
        cout<<endl<<"|TE HUNDISTE EN EL BARRO|"<<endl;
        cout<<endl<< "PIERDES TODAS LAS TRUFAS ACUMULADAS HASTA EL MOMENTO Y SE LE OTORGAN AL OTRO JUGADOR" <<endl;
        cout<<"!PIERDES TU TURNO!"<<endl;
        trufasotro[i-1]+=acu1;// PASO LA CANTIDAD DE TRUFAS AL OTRO JUGADOR, Y LA GUARDO EN EL INDICE QUE MAIN TIENE EN EL FOR , OSEA EN LA RONDA CORRESPONDIENTE
        for(int x=0;x<5;x++){
            trufas[x]=0;// PONGO EN CERO EL VECTOR
        }
        turno=true;//CORTA TURNO ES TRUE
        barro=true;
    }
}
///ESTA FUNCION CLASIFICA SI EL TIRO ES TIPO A , QUE TODOS LOS DADOS SEAN DISTINTOS Y QUE NO SEAN ASES
void PuntoA3(int n1,int n2,int n3,int trufas[5],int x,bool &oink,bool &turno,int &acu){

    if( (n1!=n2 && n2!=n3 && n1!=n3) && (n1!=1 && n2!=1 && n3!=1) )
        {
            turno=false;
            oink=false;
            trufas[x-1]+=(n1+n2+n3);// LE RESTA UNO AL INDICE DEL VECTOR XQ EL FOR DE MAIN EMPIEZA EN 1
            cout<<endl<<"¡SUMASTE: " <<n1+n2+n3<<" TRUFAS! "<<endl;
            acu=n1+n2+n3;
        }
    if( ((n1==n2 && n3!=n2) || (n1==n3 && n2!=n3) || (n2==n3 && n1!=n2)) && (n1!=1 && n2!=1 && n3!=1) ){// LA OTRA OPCION ES QUE  DOS DADOS SEAN IGUALES Y UNO DISTINTOS Y A LA VEZ , TODOS DISTINTOS DE AS
        turno=false;
            oink=false;
            trufas[x-1]+=(n1+n2+n3);
            acu=n1+n2+n3;
            cout<<endl<<"¡SUMASTE: " <<n1+n2+n3<<" TRUFAS! "<<endl;
    }
}
/// ESTA FUNCION CLASIFICA EL TIRO EN TIPO B, EN EL QUE TODOS LOS DADOS TIENEN QUE SER IGUALES Y DISTINTOS DE AS ,
void PuntoB3(int n1, int n2 , int n3 , int trufas[5], int trufasotro[5] , int x , bool &oink , bool &turno, bool &barro,int &cont_oink,int &lanzamiento,int &acu){
    if ((n1==n2 && n2==n3) && (n1!=1 && n2!=1 && n3!=1) ){
        //turno=false;
        oink=true ;// ACTIVA EL TIRO OBLIGATORIO
        trufas[x-1]+=(n1+n2+n3)* 2 ;//GUARDO EN MI VECTOR DE TRUFAS , LA SUMA DUPLICADA DE LOS DADOS
        acu=(n1+n2+n3)* 2;
        cout<<endl<<"HICISTE UN OINK! DUPLICASTE LAS TRUFAS OBTENIDAS EN EL LANZAMIENTO "<<endl;
        cout<<endl<<"¡SUMASTE: " <<(n1+n2+n3)*2<<" TRUFAS! "<<endl;
        cont_oink++;// CONTADOR DE OINK ME SIRVE PARA LOS HITOS
        }
    while(oink==true){// ACA ENTRA AL CICLO DE LA TIRADA OBLIGATORIA
        cout<<endl<<"TIRABA OBLIGATORIA"<<endl;
   cout<<"X-------------------------------------------------------------X"<<endl;
        cout<<endl<<"LANZAMIENTO #"<<lanzamiento++<<endl<<endl;
        n1=tirada();
        n2=tirada();
        n3=tirada();
        cout<<"OBTUVO:  "<<n1<<" , "<<n2<< " Y " << n3 << endl;

        PuntoC3(n1, n2,n3, trufas,x, oink, turno);
        PuntoD3( n1, n2,n3, trufas,trufasotro, x, oink, turno, barro);
        PuntoA3(n1,n2,n3,trufas, x, oink , turno, acu);
        //PUNTO B// LO HAGO MANUAL PORQUE TIENDE A ROMPERSE SI USO MI FUNCION DENTRODE MI FUNCION (CICLO INFINITO)
        if ((n1==n2 && n2==n3) && (n1!=1 && n2!=1 && n3!=1) ){
        //turno=false;
        oink=true ;
        trufas[x-1]+=(n1+n2+n3)* 2 ;
        acu=(n1+n2+n3)* 2;
        cout<<endl<<"HICISTE UN OINK! DUPLICASTE LAS TRUFAS OBTENIDAS EN EL LANZAMIENTO "<<endl;
        cout<<endl<<"¡SUMASTE " <<(n1+n2+n3)*2<<" TRUFAS! "<<endl;
        cont_oink++; // CONTADOR DE OINK PARA LOS HITOS
        }
        }
}
// ESTA FUNCION MUESTRA  POR PANTALLA SI ALGUNO GANO O SI EMPATARON
void mostrar_ganador(int PDV[2],string primero,string segundo,int &pdv_max,string &nombre_max,string &nom_estadistica,int &pdv_estadistica){
    cout<<endl;
    if(PDV[0] > PDV[1]){//PDV[0] ES EL JUGADOR1 ,Y PDV [1] ES EL JUGADOR2
       cout<<"GANADOR: "<<primero<<" CON "<<PDV[0]<<" DE VICTORIA "<<endl;
        pdv_max=PDV[0];// LA VARIABLE PDV_MAX ES PARA DESP COMPARAR CON LA DE ESTADISTICAS Y VER SI SUPERA , PARA PONERLA COMO NUEVO RECORD O ESTADISTICA
        nombre_max=primero;// guardo el nombre para mostrarlo en estadisticas
       }
    else{
        if(PDV[1]>PDV[0]){//caso contrario
            cout<<"GANADOR: "<<segundo<<" con "<<PDV[1]<<" de victoria"<<endl;
            pdv_max=PDV[1];
        nombre_max=segundo;
        }
        else{
            cout<<"AMBOS JUGADORES EMPATARON CON "<<PDV[0]<<" DE VICTORIA"<<endl; // el caso de que empaten
            pdv_max=PDV[0];
        nombre_max=primero;
        }
    }

    if(pdv_max>pdv_estadistica){ // aca va guardar en estadisticas en el caso que sea mayor al valor ya guardado en la vaiable
        pdv_estadistica=pdv_max;
        nom_estadistica=nombre_max;
    }
}
void poner_encero(int trufas_primer[5],int trufas_segundo[5],int &oinks1,int &oinks2,int &trufas1,int &trufas2,int PDV[2]){// pone todos lo contadores y vectores en 0 es por si el usuario quiere volver a jugar
    for(int i=0;i<5;i++){
        trufas_primer[i]=0;
        trufas_segundo[i]=0;
    }
    PDV[0]=PDV[1]=0;
    oinks1=oinks2=trufas1=trufas2=0;
}
