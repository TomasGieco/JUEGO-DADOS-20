#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <conio.h>


using namespace std;

#include "rlutil.h"
#include "funciones.h"

void menuselec(const char* texto, int posx, int posy, bool selec);

int ingdataint(const char* texto, int posx, int posy);

void fondo(int posx, int posy, int maxx, int maxy, int COLOR);


int main(){
    char ingreso[3]={};
    int dado[6]={},maxtirada[6]={};
    char nombjug;
    int op, rondastot, apost;
    int y=0, punt=0, tir=1, rond=1;

    do{

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

        case 1:     //ENTER
            switch(y){
            case 0:     /// MODO UN JUGADOR

                system("cls");
                fondo(26,9,61,12,5);
                rlutil::locate(29,10);
                rlutil::setColor(rlutil::WHITE);
                cout<<"Nombre del ludopata de hoy: ";

                nombjug=cargarVectorchar(ingreso,3);
                rondastot=ingdataint("Cantidad de rondas a jugar: ",29,11);

                system("cls");

                while(rond<=rondastot){

                    clrscr();
                    fondo(1,2,100,25,5);
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::locate(3,2);
                    cout<<"Cantidad de puntos apostados: ";cin>>apost;
                    //punt=punt+apost; ///ACOMODAR DESPUES EL ACUMULADOR

                    clrscr();
                    fondo(1,2,100,25,5);
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::locate(3,2);
                    cout<<"Nombre de jugador: "; mostrarVectorChar(ingreso,3);
                    //rlutil::locate(27,2);
                    cout<<"  |  ";
                    //rlutil::locate(30,2);
                    cout<<"Ronda N"<<(char)167<<rond;
                    //rlutil::locate(41,2);
                    cout<<"  |  ";
                    //rlutil::locate(44,2);
                    cout<<"Puntaje Acumulado: "<<punt;
                    while(tir<=6){
                        gotoxy(3,4);
                        cout<<"Tirada N"<<(char)167<<tir<<endl;
                        cargarAleatorio(dado,6,6);
                        mostrarVector(dado,6);
                        maxtirada[tir-1]=maximoVector(dado,6);

                        rlutil::locate(3,7);
                        cout<<"Maximas tiradas: "<<maxtirada[tir-1];
                        ponerCero(dado,6);





                        tir++;
                        gotoxy(50,25);
                        if(tir<=6){
                            cout<<"Pulse cualquier tecla para la siguiente tirada";
                            getch();
                        }
                    }
                    tir=1;
                    rond++;
                    gotoxy(50,25);
                    cout<<" Pulse cualquier tecla para la siguiente ronda";
                    getch();


                }
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
    }while(op != 0);


rlutil::locate(0,300);
cout<<endl<<endl;
return 0;
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


