#ifndef INICIA_H_INCLUDED
#define INICIA_H_INCLUDED
#include <allegro.h>

void inicia_allegro(int ANCHO_ , int ALTO_){
   allegro_init();
   install_keyboard();

   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO_, ALTO_, 0, 0);
}

//int inicia_audio(int izquierda, int derecha);

#endif // INICIA_H_INCLUDED
