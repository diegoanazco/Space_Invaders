#include <allegro.h>
#include <stdlib.h>
#include <time.h>
#include "inicia.h"
#include "diseno.h"
#include "disparos.h"

#define ANCHO 600
#define ALTO 400
bool NAVE:: temporizador(int j)
{
    tick++;
    if(tick == 5)
    {
        tick = 0;
        return true;
    }
    return false;
}
bool limites(struct NAVE E[], int &dir)
{
    for(int i =0; i< 55; i++)
    {
        if(E[i].x > 520 || E[i].x < 50)
        {
            dir = -1*dir;
            return true;
        }
    }
    return false;
}

void mover_enemigos(struct NAVE E[], int &mov, int &dir)
{
    for(int i=0; i<55 ; i++) E[i].x += dir;
    if(++mov == 2) mov = 0;
    if(limites(E,dir))
    {
            for(int j=0;j<55;j++) E[j].y += 10;
    }
}


void NAVE::inicia(char* ruta_nave, char* ruta_bala, int _ancho_b, int _alto_b,int _ancho_p, int _alto_p, int _x, int _y, int _dir_bala, int _tipo, int _vida)
{
    x = _x;
    y = _y;
    n_disp = 0 ; max_disp = 2;
    img_nav = load_bitmap(ruta_nave, NULL);
    img_bala = load_bitmap(ruta_bala,NULL);
    tick=0;
    ancho_b = _ancho_b; alto_b = _alto_b;
    ancho_p = _ancho_p; alto_p = _alto_p;
    dir_bala = _dir_bala;
    tipo = _tipo;
    vida = _vida;
    exp_enem = load_bitmap("Recursos/pum_enemigo.bmp",NULL);
}

void NAVE:: pinta(BITMAP* buffer, int ix, int iy)
{
     masked_blit(img_nav,buffer,ix*ancho_p,iy*alto_p,x,y,ancho_p,alto_p);
}

void NAVE:: mueve()
{
    if(key[KEY_LEFT]) x -=5;
    if(key[KEY_RIGHT]) x +=5;
}

void NAVE:: dispara(struct Balas disparos[], BITMAP* buffer)
{
    if(tipo)
    crear_bala(n_disp, max_disp, disparos,x,y,dir_bala);
    pintar_bala(n_disp , max_disp , disparos , buffer , img_bala,ancho_b,alto_b);
    elimina_bala(n_disp , max_disp , disparos , ANCHO , ALTO);
}

void acomoda_enemigos(struct NAVE E[])
{
    int indice = -1;
    int _tipo =0;
    for(int i=0; i<5 ;i++)
    {
        _tipo++;
        if(_tipo == 4) _tipo = 1;
        for(int j=0; j<11 ; j++)
        {
            indice++;
            E[indice].inicia("Recursos/enemigos.bmp","Recursos/Bala_enem.bmp", 6, 12, 25,20, 140+j*30, 100+i*24,8,_tipo,1);
        }
    }
}
void pintar_enemigo(struct NAVE E[], BITMAP* buffer,int mov)
{
    int indice = -1;
    for(int i=0; i<5 ;i++)
    {
        for(int j=0; j<11 ; j++)
        {
            indice++;
            if(E[indice].vida > 0)
            E[indice].pinta(buffer,0,E[indice].tipo-1);
        }
    }

}

void explosion1(struct NAVE E, BITMAP* buffer)
{
    BITMAP* parche = create_bitmap(25,20);
    clear_to_color(parche, 0x000000);
    blit(parche,buffer,0,0,E.x,E.y,25,20);
    masked_blit(E.exp_enem, buffer,0,0,E.x-10, E.y, 41,34);
}

void explosion2(struct NAVE N, BITMAP*buffer)
{
    BITMAP* parche = create_bitmap(30,20);
    clear_to_color(parche, 0x000000);
    for(int j =0; j<6;j++)
    {
        for(int i=1; i<=2;i++)
        {
            blit(parche,buffer,0,0,N.x,N.y,30,20);
            masked_blit(N.img_nav,buffer,i*30,0,N.x,N.y,30,20);
            blit(buffer, screen, 0,0,0,0, ANCHO,ALTO);
            rest(50);
        }
    }
}


void crear_bala_enemigo(struct NAVE E[], int &azar)
{

    if(E[azar].n_disp == 0)
    {
        azar = rand()%55;
        while(E[azar].vida == 0) azar = rand()%55;
    }

}

int main(){

    srand(time(NULL));
    inicia_allegro(ANCHO,ALTO);
    BITMAP *buffer = create_bitmap(ANCHO, ALTO);
    NAVE N;
    N.inicia("Recursos/nave.bmp","Recursos/Bala2.bmp", 6, 12, 30,20, ANCHO/2, ALTO-50, -8,0,3);
    NAVE E[60];
    acomoda_enemigos(E);
    Balas disparos[N.max_disp];
    Balas disp_E[E[0].max_disp];
    int azar = rand()%55;
    int mov = 0, dir = -5, vel_juego = 10;

    while (!key [KEY_ESC]){

        clear_to_color(buffer,0x00000);
        if(E[0].temporizador(vel_juego))
            mover_enemigos(E,mov,dir);


        N.pinta(buffer,0,0);
        N.mueve();
        if (key[KEY_SPACE] && N.temporizador(10))
        crear_bala(N.n_disp,N.max_disp,disparos,N.x,N.y,N.dir_bala);
        N.dispara(disparos, buffer);

        for(int i = 0; i<55; i++)
        {
            if(elimina_bala_objeto(N,E[i],disparos))
            {
                explosion1(E[i],buffer);
            }
        }

        pintar_enemigo(E,buffer,mov);
        crear_bala_enemigo(E,azar);
        E[azar].dispara(disp_E,buffer);
        if(elimina_bala_objeto(E[azar], N, disp_E))
        {
            explosion2(N,buffer);
        }
        if(E[0].temporizador(10)) if(++mov == 2) mov = 0;
        if(N.vida == 0)
            break;
        blit(buffer,screen, 0,0 , 0,0 ,ANCHO,ALTO);
        rest(20);
    }
	return 0;
}
END_OF_MAIN();




