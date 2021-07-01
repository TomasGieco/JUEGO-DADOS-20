#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <conio.h>


using namespace std;

#include "rlutil.h"
#include "funciones.h"

int puntuacion(int sum);

void menuselec(const char* texto, int posx, int posy, bool selec);

int ingdataint(const char* texto, int posx, int posy);

void fondo(int posx, int posy, int maxx, int maxy, int COLOR);


int main(){
    char ingreso[3]={};
    char nombjug;

    int op, rondastot, apost, sum, genpunt, i, prepunt;
    int y=0, punt=0, tir=1, rond=1,cont=5, mult=0, rond0=0, rondperd=0;
    int dado[5]={},maxtirada[5]={};


    while(op != 0){

        //recuadro(26, 9, 40, 20, 0, 14);
        fondo(26,9,56,18,5);
        rlutil::setConsoleTitle("20 de Gieco Tomas y Diego Olivera");
        rlutil::hidecursor();

//-----------------------------------------------------------------------------------

        menuselec("        JUEGO 20     ",30,10, y == 7);
        menuselec("-----------------------",30,11,y == 7);
        menuselec("  1 JUGADOR  ",30,12,y == 0);
        menuselec("  2 JUGADORES  ",30,13,y == 1);
        menuselec("  PUNTUACION MAS ALTA  ",30,14,y == 2);
        menuselec("  MODO DE PRUEBA  ",30,15,y == 3);
        menuselec("-----------------------",30,16,y == 7);
        menuselec("  Fin del Programa  ",30,17,y == 4);



        switch(rlutil::getkey()){
        case 14:    //Sube el cursor
            y--;
            if(y<0){
                y=0;
            }
        break;

        case 15:    //Baja el cursor
            y++;
            if(y>4){
                y=4;
            }
        break;

        case 1:
                 //ENTER
            switch(y){
            case 0:     /// MODO UN JUGADOR

                system("cls");
                fondo(26,9,61,12,5);
                rlutil::locate(29,10);
                rlutil::setColor(rlutil::WHITE);
                cout<<"Nombre del ludopata de hoy: ";

                cargarVectorchar(ingreso,3);
                rondastot=ingdataint("Cantidad de rondas a jugar: ",29,11);

                system("cls");

                while(rond<=rondastot){

                    clrscr();
                    fondo(1,2,100,25,5);
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::locate(3,2);
                    cout<<"Cantidad de puntos apostados: ";cin>>apost;

                    while(tir<=5){

                        clrscr();
                        fondo(1,2,100,25,5);
                        rlutil::setColor(rlutil::WHITE);
                        rlutil::locate(3,2);
                        cout<<"Nombre de jugador: "; mostrarVectorChar(ingreso,3);
                        cout<<"  |  ";
                        cout<<"Ronda N"<<(char)167<<rond;
                        cout<<"  |  ";
                        cout<<"Puntaje Acumulado: "<<punt;
                        gotoxy(3,4);
                        cout<<"Tirada N"<<(char)167<<tir<<endl;

                        gotoxy(3,5);

                        cargarAleatorio(dado,5,6);
                        mostrarVector(dado,cont);
                        maxtirada[tir-1]=maximoVector(dado,cont);

                        rlutil::locate(3,7);
                        cout<<"Maximas tiradas: "<<maxtirada[tir-1];
                        ponerCero(dado,5);



                        tir++;
                        cont--;
                        gotoxy(50,25);
                        if(tir<=5){
                            cout<<"Pulse cualquier tecla para la siguiente tirada";
                            getch();
                            clrscr();

                        }
                    }
                    sum=sumarVector(maxtirada,5);
                    gotoxy(3,8);
                    cout<<"Suma de puntajes: "<<sum;
                    mult=0;
                    if(sum>=20){

                        genpunt=puntuacion(sum);
                        gotoxy(3,9);
                        cout<<"Tirada de puntaje ";

                        gotoxy(3,10);
                        cargarAleatorio(dado,5,6);
                        mostrarVector(dado,5);

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

                        cout<<"Puntuacion obtenida: "<<prepunt;
                    }



                    else{
                        gotoxy(3,9);
                        punt=punt-apost;
                        rondperd++;

                        cout<<"Habra que recuperar los puntos. Puntaje obtenido: "<<apost*(-1);

                    }



                    cont=5;
                    tir=1;
                    rond++;
                    gotoxy(50,25);
                    cout<<" Pulse cualquier tecla para la siguiente ronda";
                    getch();

                }
                clrscr();
                fondo(1,2,100,25,5);
                fondo(30,10,75,16,rlutil::LIGHTRED);
                rlutil::setColor(rlutil::WHITE);

                gotoxy(35,11);
                cout<<"Nombre de jugador: "; mostrarVectorChar(ingreso,3);
                cout<<endl;
                gotoxy(35,12);
                cout<<"Cantidad de rondas sin ganancia: "<<rond0<<endl;
                gotoxy(35,13);
                cout<<"Cantidad de rondas con perdida: "<<rondperd<<endl<<endl;
                gotoxy(35,15);
                cout<<"Puntaje Final: "<<punt<<endl;


                getch();

                rondperd=0;
                rond0=0;
                punt=0;
                rond=1;
                clrscr();
                break;
            case 1:   /// MODO 2 JUGADORES
                break;

            case 2:   /// PUNTUACION MAS ALTA
                break;

            case 3:   /// MODO DE PRUEBA
                break;
            case 4:   ///Salir del programa
                    op=0;
                break;
            }
        break;

        }
    }


rlutil::locate(0,300);
cout<<endl<<endl;
return 0;
}




int puntuacion(int sum){

    int genpunt;
    switch(sum){
    case 20:
        genpunt=1;
    break;
    case 21:
        genpunt=2;
    break;
    case 22:
        genpunt=3;
    break;
    case 23:
        genpunt=4;
    break;
    case 24:
        genpunt=5;
    break;
    case 25:
        genpunt=6;
    break;
    default:
        genpunt=6;
    break;
    }

    return genpunt;
}


void menuselec(const char* texto, int posx, int posy, bool selec){
    if(selec){
        rlutil::locate(posx-2,posy);
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<<texto<<endl;
        rlutil::setColor(rlutil::WHITE);
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

    int auxx,auxy;
    rlutil::setColor(COLOR);

    gotoxy(posx,posy-1); cout<<(char)201; //esquina superior izquierda
    gotoxy(maxx,posy-1); cout<<(char)187; //esquina superior derecha
    gotoxy(posx,maxy+1); cout<<(char)200; //esquina inferior izquierda
    gotoxy(maxx,maxy+1); cout<<(char)188; //esquina inferior derecha

    auxy=posy;
    auxx=posx;

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


