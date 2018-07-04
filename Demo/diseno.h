#ifndef DISENO_H_INCLUDED
#define DISENO_H_INCLUDED
#include <allegro.h>

void imprimir_fondo(BITMAP*fondo, BITMAP* buffer)
{
    masked_blit(fondo,buffer,0,0,0,0,600,600);
}
#endif
