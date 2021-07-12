#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <conio.h>

using namespace std;

#include "rlutil.h"
#include "funciones.h"
#include "ascii.h"
void mayortirada(int v[],int tam,int posx,int posy);

void tirada(int v[], int tam, int posx, int posy);

void tiradaprueba(int v[], int tam, int posx, int posy, int cinx, int ciny);

int juego(char vJugador[], int apost, int rondout, int punt);

int puntuacion(int sum);

void menuselec(const char* texto, int posx, int posy, bool selec);

int ingdataint(const char* texto, int posx, int posy);

void fondo(int posx, int posy, int maxx, int maxy, int COLOR);


int main(){
    char jugador[3]={},jugador2[3]={},maxjugador[3]={};

    int op, rondastot, apost, apost2, sum, genpunt, i, prepunt,newpunt;
    int y=0, punt=0, tir=1, rond=1,cont=5, mult=0, rond0=0, rondperd=0,altapunt=0, contalta=0,punt1=0,punt2=0;
    int dado[5]={},maxtirada[5]={};



    while(op != 0){

        fondo(26,9,56,18,5);
        rlutil::setConsoleTitle("20 de Gieco Tomas y Diego Olivera");
        rlutil::hidecursor();

//-----------------------------------------------------------------------------------

        menuselec("        JUEGO 20     ",30,10, y == 7);
        menuselec("-----------------------",30,11,y == 7);
        menuselec("  1 JUGADOR  ",30,12,y == 0);
        menuselec("  2 JUGADORES  ",30,13,y == 1);
        menuselec("  MODO DE PRUEBA  ",30,14,y == 2);
        menuselec("  PUNTUACION MAS ALTA  ",30,15,y == 3);
        menuselec("-----------------------",30,16,y == 7);
        menuselec("  Fin del Programa  ",30,17,y == 4);



        switch(rlutil::getkey()){
        case 14:    //Sube el cursor
            y--;
            if(y<0){
                y=4;
            }
        break;

        case 15:    //Baja el cursor
            y++;
            if(y>4){
                y=0;
            }
        break;

        case 1:
                 //ENTER
            switch(y){
            case 0:     /// MODO UN JUGADOR -----------------------------------------------------------------------

                system("cls");
                fondo(26,9,61,12,5);
                rlutil::locate(29,10);
                rlutil::setColor(rlutil::WHITE);
                cout<<"Nombre del ludopata de hoy: ";

                cargarVectorchar(jugador,3);
                rondastot=ingdataint("Cantidad de rondas a jugar: ",29,11);

                while(rond<=rondastot){

                    clrscr();
                    fondo(1,2,100,25,5);
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::locate(3,2);
                    cout<<"Cantidad de puntos apostados: ";cin>>apost;

                    while(tir<=5){

                        clrscr();
                        fondo(1,2,100,29,5);
                        rlutil::setColor(rlutil::WHITE);
                        rlutil::locate(3,2);
                        cout<<"Nombre de jugador: "; mostrarVectorChar(jugador,3);
                        cout<<"  |  ";
                        cout<<"Ronda N"<<(char)167<<rond;
                        cout<<"  |  ";
                        cout<<"Puntaje Acumulado: "<<punt;
                        gotoxy(3,4);
                        cout<<"Tirada N"<<(char)167<<tir<<endl;

                        gotoxy(3,5);

                        tirada(dado,cont,3,6);
                        maxtirada[tir-1]=maximoVector(dado,cont);


                        rlutil::locate(3,15);
                        cout<<"Maxima tirada: ";mayortirada(maxtirada,tir,17,14);
                        ponerCero(dado,5);



                        tir++;
                        cont--;
                        gotoxy(50,29);
                        if(tir<=5){
                            cout<<"Pulse cualquier tecla para la siguiente tirada";
                            getch();
                            clrscr();

                        }
                    }
                    sum=sumarVector(maxtirada,5);
                    gotoxy(3,20);
                    cout<<"Suma de puntajes: "<<sum;
                    mult=0;
                    if(sum>=20){
                        Sleep(500);
                        genpunt=puntuacion(sum);
                        gotoxy(3,22);
                        cout<<"Tirada de puntaje: ";

                        tirada(dado,5,3,24);

                        for(i=0;i<=5;i++){
                            if(dado[i]==genpunt){
                                mult++;
                            }
                        }

                        if(mult==0){
                            rond0++;
                        }

                        prepunt=apost*mult;
                        punt=punt+prepunt;

                        gotoxy(3,29);
                        cout<<"Puntuacion obtenida: "<<prepunt;
                    }

                    else{
                        gotoxy(3,20);
                        punt=punt-apost;
                        rondperd++;

                        cout<<"Habra que recuperar los puntos. Puntaje obtenido: "<<apost*(-1);

                    }


                    cont=5;
                    tir=1;
                    rond++;
                    gotoxy(52,29);
                    cout<<" Pulse cualquier tecla para la siguiente ronda";
                    getch();

                }
                clrscr();
                fondo(1,2,100,25,5);
                fondo(30,10,75,16,rlutil::LIGHTRED);
                rlutil::setColor(rlutil::WHITE);

                gotoxy(35,11);
                cout<<"Nombre de jugador: "; mostrarVectorChar(jugador,3);
                gotoxy(35,12);
                cout<<"Cantidad de rondas sin ganancia: "<<rond0<<endl;
                gotoxy(35,13);
                cout<<"Cantidad de rondas con perdida: "<<rondperd<<endl<<endl;
                gotoxy(35,15);
                cout<<"Puntaje Final: "<<punt<<endl;

                newpunt=punt;

                if(newpunt>altapunt||contalta==0){

                    copiarVectorChar(jugador,maxjugador,3);
                    altapunt=newpunt;
                    contalta++;
                }

                getch();

                rondperd=0;
                rond0=0;
                punt=0;
                rond=1;
                clrscr();

                break;
            case 1:   /// MODO 2 JUGADORES ----------------------------------------------------------------------
                clrscr();
                fondo(26,9,71,14,5);
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate(29,10);


                cout<<"Nombre del primer ludopata de hoy: ";
                cargarVectorchar(jugador,3);

                rlutil::locate(29,11);
                cout<<"Nombre del segundo ludopata de hoy: ";
                cargarVectorchar(jugador2,3);

                rondastot=ingdataint("Cantidad de rondas a jugar: ",29,12);

                while(rond<=rondastot){

                    clrscr();
                    fondo(1,2,100,25,5);
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::locate(3,2);
                    cout<<"Cantidad de puntos apostados por "; mostrarVectorChar(jugador,3);cout<<": "; cin>>apost;
                    rlutil::locate(3,3);
                    cout<<"Cantidad de puntos apostados por "; mostrarVectorChar(jugador2,3);cout<<": "; cin>>apost2;

                    punt1=juego(jugador,apost,rond,punt1);
                    punt2=juego(jugador2,apost2,rond,punt2);
                    rond++;
                }

                rond=1;

                clrscr();
                fondo(1,2,100,25,5);
                rlutil::setColor(rlutil::WHITE);

                if(punt1>punt2){
                    rlutil::locate(3,2);
                    cout<<"El mejor ludopata fue "; mostrarVectorChar(jugador,3);

                    newpunt=punt1;

                    if(newpunt>altapunt||contalta==0){

                    copiarVectorChar(jugador,maxjugador,3);
                    altapunt=newpunt;
                    contalta++;
                    }
                }
                else{
                    rlutil::locate(3,2);
                    cout<<"El mejor ludopata fue "; mostrarVectorChar(jugador2,3);

                    newpunt=punt2;

                    if(newpunt>altapunt||contalta==0){

                    copiarVectorChar(jugador2,maxjugador,3);
                    altapunt=newpunt;
                    contalta++;
                    }
                }

                punt1=0;
                punt2=0;
                getch();
                clrscr();


                break;

            case 2:   /// MODO DE PRUEBA ----------------------------------------------------------------------------------

                system("cls");
                fondo(26,9,61,12,5);
                rlutil::locate(29,10);
                rlutil::setColor(rlutil::WHITE);
                cout<<"Nombre del ludopata de hoy: ";

                cargarVectorchar(jugador,3);
                rondastot=ingdataint("Cantidad de rondas a jugar: ",29,11);

                while(rond<=rondastot){

                    clrscr();
                    fondo(1,2,100,25,5);
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::locate(3,2);
                    cout<<"Cantidad de puntos apostados: ";cin>>apost;

                    while(tir<=5){

                        clrscr();
                        fondo(1,2,100,29,5);
                        rlutil::setColor(rlutil::WHITE);
                        rlutil::locate(3,2);
                        cout<<"Nombre de jugador: "; mostrarVectorChar(jugador,3);
                        cout<<"  |  ";
                        cout<<"Ronda N"<<(char)167<<rond;
                        cout<<"  |  ";
                        cout<<"Puntaje Acumulado: "<<punt;
                        gotoxy(3,4);
                        cout<<"Tirada N"<<(char)167<<tir<<endl;

                        gotoxy(3,5);
                        cout<<"Ingrese dado: ";
                        tiradaprueba(dado,cont,3,6,17,5);
                        maxtirada[tir-1]=maximoVector(dado,cont);

                        rlutil::locate(3,13);
                        cout<<"Maxima tirada: ";mayortirada(maxtirada,tir,18,12);
                        ponerCero(dado,5);



                        tir++;
                        cont--;
                        gotoxy(52,29);
                        if(tir<=5){
                            cout<<"Pulse cualquier tecla para la siguiente tirada";
                            getch();
                            clrscr();

                        }
                    }
                    sum=sumarVector(maxtirada,5);
                    gotoxy(3,17);
                    cout<<"Suma de puntajes: "<<sum;
                    mult=0;
                    if(sum>=20){
                        Sleep(500);
                        genpunt=puntuacion(sum);
                        gotoxy(3,18);
                        cout<<"Tirada de puntaje: ";
                        gotoxy(3,19);
                        cout<<"Ingrese dado: ";


                        tiradaprueba(dado,5,3,20,17,19);

                        for(i=0;i<=5;i++){
                            if(dado[i]==genpunt){
                                mult++;
                            }
                        }

                        if(mult==0){
                            rond0++;
                        }

                        prepunt=apost*mult;
                        punt=punt+prepunt;

                        gotoxy(3,28);
                        cout<<"Puntuacion obtenida: "<<prepunt;
                    }

                    else{
                        gotoxy(3,17);
                        punt=punt-apost;
                        rondperd++;

                        cout<<"Habra que recuperar los puntos. Puntaje obtenido: "<<apost*(-1);

                    }


                    cont=5;
                    tir=1;
                    rond++;
                    gotoxy(52,29);
                    cout<<" Pulse cualquier tecla para la siguiente ronda";
                    getch();

                }
                clrscr();
                fondo(1,2,100,25,5);
                fondo(30,10,75,16,rlutil::LIGHTRED);
                rlutil::setColor(rlutil::WHITE);

                gotoxy(35,11);
                cout<<"Nombre de jugador: "; mostrarVectorChar(jugador,3);
                gotoxy(35,12);
                cout<<"Cantidad de rondas sin ganancia: "<<rond0<<endl;
                gotoxy(35,13);
                cout<<"Cantidad de rondas con perdida: "<<rondperd<<endl<<endl;
                gotoxy(35,15);
                cout<<"Puntaje Final: "<<punt<<endl;

                newpunt=punt;

                if(newpunt>altapunt||contalta==0){

                    copiarVectorChar(jugador,maxjugador,3);
                    altapunt=newpunt;
                    contalta++;
                }

                getch();

                rondperd=0;
                rond0=0;
                punt=0;
                rond=1;
                clrscr();

                break;

            case 3:   /// PUNTUACION MAS ALTA ----------------------------------------------------------------------------

                clrscr();
                fondo(1,2,100,25,5);
                rlutil::setColor(rlutil::WHITE);
                gotoxy(35,11);
                cout<<"El mayor ludopata de la sesion es: "; mostrarVectorChar(maxjugador,3);
                gotoxy(35,12);
                cout<<"Con un total de: "<<altapunt<<endl;

                gotoxy(50,25);
                cout<<" Pulse cualquier tecla para volver al menu";
                getch();
                clrscr();

                break;
            case 4:   ///Salir del programa
                    op=0;
                break;
            }
        break;
        }
    }


rlutil::setColor(rlutil::WHITE);
cout<<endl<<endl;
return 0;
}


void tirada(int v[],int tam,int posx,int posy){
int i, agregarX=posx;

cargarAleatorio(v,tam,6);

for(i=0;i<5;i++){

    if(v[i]==1){
        dado1(agregarX,posy);
        agregarX=agregarX+10;
    }
    if(v[i]==2){
        dado2(agregarX,posy);
        agregarX=agregarX+10;
    }
    if(v[i]==3){
        dado3(agregarX,posy);
        agregarX=agregarX+10;
    }
    if(v[i]==4){
        dado4(agregarX,posy);
        agregarX=agregarX+10;
    }
    if(v[i]==5){
        dado5(agregarX,posy);
        agregarX=agregarX+10;
    }
    if(v[i]==6){
        dado6(agregarX,posy);
        agregarX=agregarX+10;
    }
    gotoxy(30,20);
    //Sleep(300);
}

}

void tiradaprueba(int v[],int tam, int posx, int posy, int cinx, int ciny){
int i, agregarX=posx;

for(i=0;i<tam;i++){

    gotoxy(cinx,ciny);
    cin>>v[i];

    switch(v[i]){
    case 1:
        dado1(agregarX,posy);
        agregarX=agregarX+10;
        break;
    case 2:
        dado2(agregarX,posy);
        agregarX=agregarX+10;
        break;
    case 3:
        dado3(agregarX,posy);
        agregarX=agregarX+10;
        break;
    case 4:
        dado4(agregarX,posy);
        agregarX=agregarX+10;
        break;
    case 5:
        dado5(agregarX,posy);
        agregarX=agregarX+10;
        break;
    case 6:
        dado6(agregarX,posy);
        agregarX=agregarX+10;
        break;
    }
    gotoxy(30,20);
    //Sleep(500);


}
}

int puntuacion(int sum){

    int genpunt;
    switch(sum){
    case 20: genpunt=1; break;
    case 21: genpunt=2; break;
    case 22: genpunt=3; break;
    case 23: genpunt=4; break;
    case 24: genpunt=5; break;
    default: genpunt=6; break;
    }

    return genpunt;
}


void menuselec(const char* texto, int posx, int posy, bool selec){

    if(selec){
        rlutil::locate(posx-2,posy);
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<<texto<<endl;
    }
    else{
        rlutil::locate(posx,posy);
        rlutil::setColor(rlutil::WHITE);
        cout<<texto<<endl;
    }
}

int ingdataint(const char* pedido, int posx, int posy){

        int ingreso;
        rlutil::locate(posx,posy);
        rlutil::setColor(rlutil::WHITE);
        cout<<pedido;cin>>ingreso;

    return ingreso;
}


void fondo(int posx, int posy, int maxx, int maxy, int COLOR){

    int auxy;
    rlutil::setColor(COLOR);

    gotoxy(posx,posy-1); cout<<(char)201; //esquina superior izquierda
    gotoxy(maxx,posy-1); cout<<(char)187; //esquina superior derecha
    gotoxy(posx,maxy+1); cout<<(char)200; //esquina inferior izquierda
    gotoxy(maxx,maxy+1); cout<<(char)188; //esquina inferior derecha

    auxy=posy;

    for(posy=posy;posy<=maxy;posy++){ //linea horizontal

        gotoxy(posx,posy); cout<<(char)186;
        gotoxy(maxx,posy); cout<<(char)186;
    }

    posy=auxy;

    for(posx=posx;posx<maxx-1;posx++){ //linea vertical

        gotoxy(posx+1,posy-1); cout<<(char)205;
        gotoxy(posx+1,maxy+1); cout<<(char)205;
    }
}

int juego(char vJugador[], int apost, int rondout, int punt){

    char maxjugador[3];

    int sum, genpunt, i, prepunt,newpunt;
    int rond=rondout, tir=1, cont=5, mult=0;
    int dado[5]={},maxtirada[5]={};

    while(tir<=5){

        clrscr();
        fondo(1,2,100,25,5);
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(3,2);
        cout<<"Nombre de jugador: "; mostrarVectorChar(vJugador,3);
        cout<<"  |  ";
        cout<<"Ronda N"<<(char)167<<rond;
        cout<<"  |  ";
        cout<<"Puntaje Acumulado: "<<punt;
        gotoxy(3,4);
        cout<<"Tirada N"<<(char)167<<tir<<endl;

        gotoxy(3,5);
        tirada(dado,cont,3,6);
        maxtirada[tir-1]=maximoVector(dado,cont);

        rlutil::locate(3,13);
        cout<<"Maxima tiradas: ";mayortirada(maxtirada,tir,18,12);
        ponerCero(dado,5);

        tir++;
        cont--;
        gotoxy(52,25);
        if(tir<=5){
            cout<<"Pulse cualquier tecla para la siguiente tirada";
            getch();
            clrscr();

        }
    }
    sum=sumarVector(maxtirada,5);
    gotoxy(3,17);
    cout<<"Suma de puntajes: "<<sum;
    mult=0;
    if(sum>=20){
        Sleep(500);
        genpunt=puntuacion(sum);
        gotoxy(3,18);
        cout<<"Tirada de puntaje: ";

        tirada(dado,5,3,19);

        for(i=0;i<=5;i++){
            if(dado[i]==genpunt){
                mult++;
            }
        }

        prepunt=apost*mult;
        punt=punt+prepunt;

        gotoxy(3,25);
        cout<<"Puntuacion obtenida: "<<prepunt;
    }

    else{
        gotoxy(3,15);
        punt=punt-apost;

        cout<<"Habra que recuperar los puntos. Puntaje obtenido: "<<apost*(-1);

    }

    cont=5;
    tir=1;
    gotoxy(52,25);
    cout<<" Pulse cualquier tecla para la siguiente ronda";
    getch();


clrscr();
return punt;
}
void mayortirada(int v[],int tam,int posx,int posy){


    if(v[tam-1]==1){
        dado1(posx,posy);

    }
    if(v[tam-1]==2){
        dado2(posx,posy);

    }
    if(v[tam-1]==3){
        dado3(posx,posy);

    }
    if(v[tam-1]==4){
        dado4(posx,posy);

    }
    if(v[tam-1]==5){
        dado5(posx,posy);

    }
    if(v[tam-1]==6){
        dado6(posx,posy);

    }

}


