#ifndef ASCII_H_INCLUDED
#define ASCII_H_INCLUDED

void dado1(int x,int y);
void dado2(int x,int y);
void dado3(int x,int y);
void dado4(int x,int y);
void dado5(int x,int y);
void dado6(int x,int y);

void dado1 (int x,int y){
    int ancho=8,alto=4;
    for(int i=x;i<=x+ancho;i++){
        {gotoxy(i,y);
        cout<<(char)205;}
        }

gotoxy(x,y);
cout<<(char)201;
gotoxy(ancho+x,y);
cout<<(char)187;

    for(int i=y;i<y+alto;i++){
        gotoxy(x,i+1);
        cout<<(char)186;
        gotoxy(x+ancho,i+1);
        cout<<(char)186;
    }
    for(int i=x;i<=x+ancho;i++){
        gotoxy(i,y+alto);
        cout<<(char)205;
    }
gotoxy(x,y+alto);
cout<<(char)200;
gotoxy(x+ancho,y+alto);
cout<<(char)188;
gotoxy(x+ancho/2,y+alto/2);
cout<<(char)4;
}

void dado2 (int x,int y){
    int ancho=8,alto=4;
    for(int i=x;i<=x+ancho;i++){
        {gotoxy(i,y);
        cout<<(char)205;}
        }
gotoxy(x,y);
cout<<(char)201;
gotoxy(ancho+x,y);
cout<<(char)187;

    for(int i=y;i<y+alto;i++){
        gotoxy(x,i+1);
        cout<<(char)186;
        gotoxy(x+ancho,i+1);
        cout<<(char)186;
    }
    for(int i=x;i<=x+ancho;i++){
        gotoxy(i,y+alto);
        cout<<(char)205;
    }
gotoxy(x,y+alto);
cout<<(char)200;
gotoxy(x+ancho,y+alto);
cout<<(char)188;
gotoxy(x+2,y+alto/2);
cout<<(char)4;
gotoxy(x+6,y+alto/2);
cout<<(char)4;
}

void dado3 (int x,int y){
    int ancho=8,alto=4;
    for(int i=x;i<=x+ancho;i++){
        {gotoxy(i,y);
        cout<<(char)205;}
        }
gotoxy(x,y);
cout<<(char)201;
gotoxy(ancho+x,y);
cout<<(char)187;

    for(int i=y;i<y+alto;i++){
        gotoxy(x,i+1);
        cout<<(char)186;
        gotoxy(x+ancho,i+1);
        cout<<(char)186;
    }
    for(int i=x;i<=x+ancho;i++){
        gotoxy(i,y+alto);
        cout<<(char)205;
    }
gotoxy(x,y+alto);
cout<<(char)200;
gotoxy(x+ancho,y+alto);
cout<<(char)188;
gotoxy(x+2,y+alto-1);
cout<<(char)4;
gotoxy(x+6,y+alto-1);
cout<<(char)4;
gotoxy(x+ancho/2,y+1);
cout<<(char)4;
}

void dado4 (int x,int y){
    int ancho=8,alto=4;
    for(int i=x;i<=x+ancho;i++){
        {gotoxy(i,y);
        cout<<(char)205;}
        }
gotoxy(x,y);
cout<<(char)201;
gotoxy(ancho+x,y);
cout<<(char)187;

    for(int i=y;i<y+alto;i++){
        gotoxy(x,i+1);
        cout<<(char)186;
        gotoxy(x+ancho,i+1);
        cout<<(char)186;
    }
    for(int i=x;i<=x+ancho;i++){
        gotoxy(i,y+alto);
        cout<<(char)205;
    }
gotoxy(x,y+alto);
cout<<(char)200;
gotoxy(x+ancho,y+alto);
cout<<(char)188;
gotoxy(x+2,y+alto-1);
cout<<(char)4;
gotoxy(x+2,y+alto-3);
cout<<(char)4;
gotoxy(x+6,y+alto-1);
cout<<(char)4;
gotoxy(x+6,y+alto-3);
cout<<(char)4;
}

void dado5 (int x,int y){
    int ancho=8,alto=4;
    for(int i=x;i<=x+ancho;i++){
        {gotoxy(i,y);
        cout<<(char)205;}
        }
gotoxy(x,y);
cout<<(char)201;
gotoxy(ancho+x,y);
cout<<(char)187;

    for(int i=y;i<y+alto;i++){
        gotoxy(x,i+1);
        cout<<(char)186;
        gotoxy(x+ancho,i+1);
        cout<<(char)186;
    }
    for(int i=x;i<=x+ancho;i++){
        gotoxy(i,y+alto);
        cout<<(char)205;
    }
gotoxy(x,y+alto);
cout<<(char)200;
gotoxy(x+ancho,y+alto);
cout<<(char)188;
gotoxy(x+2,y+alto-1);
cout<<(char)4;
gotoxy(x+2,y+alto-3);
cout<<(char)4;
gotoxy(x+6,y+alto-1);
cout<<(char)4;
gotoxy(x+6,y+alto-3);
cout<<(char)4;
gotoxy(x+ancho/2,y+alto/2);
cout<<(char)4;
}


void dado6 (int x,int y){
    int ancho=8,alto=4;
    for(int i=x;i<=x+ancho;i++){
        {gotoxy(i,y);
        cout<<(char)205;}
        }
gotoxy(x,y);
cout<<(char)201;
gotoxy(ancho+x,y);
cout<<(char)187;

    for(int i=y;i<y+alto;i++){
        gotoxy(x,i+1);
        cout<<(char)186;
        gotoxy(x+ancho,i+1);
        cout<<(char)186;
    }
    for(int i=x;i<=x+ancho;i++){
        gotoxy(i,y+alto);
        cout<<(char)205;
    }
gotoxy(x,y+alto);
cout<<(char)200;
gotoxy(x+ancho,y+alto);
cout<<(char)188;
gotoxy(x+ancho-6,y+alto/2);
cout<<(char)4;
gotoxy(x+ancho-2,y+alto/2);
cout<<(char)4;
gotoxy(x+2,y+alto-1);
cout<<(char)4;
gotoxy(x+2,y+alto-3);
cout<<(char)4;
gotoxy(x+6,y+alto-1);
cout<<(char)4;
gotoxy(x+6,y+alto-3);
cout<<(char)4;
}


#endif // ASCII_H_INCLUDED
