/*
        Welcome to the game of life

      - Files necessary for compiling -
Necessary(If modified)|      Included on resources folder
 ------------------------------------------------------
 Mapa                 |                        map.bmp
 Personagem           |                       cell.bmp
 Font(Any ttf will do)|              VT323-Regular.ttf
FLAGS NECESSARY FOR THE COMPILER/LINKER -> -lallegro -lallegro_image -lallegro_font -lallegro_ttf

To execute this program without spawning the command prompt(on windows), use this flag also -> -mwindows

        Author: GabrielTheophilo @ github.com/GabrielTheophilo
*/
//#include <clocale>
#include "conways_game.h"
#include "allegro.h" 
#include "regras.cpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;



enum MYKEYS
{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};






int menu(){
    
    ALLEGRO_EVENT event;
    al_draw_bitmap(mainmenu,0,0,0);
    al_flip_display();
    al_wait_for_event(event_queue, &event);
    if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.button == 1){
        int coordenadaX = event.mouse.x;
        int coordenadaY = event.mouse.y;
        if(coordenadaX<500){
            variante_Conway = true;
        }
        else if(coordenadaX>500){
            variante_HighLife = true;
        }
        return 1;
    }
    else{
        return 0;
    }
}



int encheMatriz(char MAPA[260][260]){
    for(int i=0; i<259;i++){
        for(int j=0; j<259;j++){
            MAPA[i][j] = '0';
        }
    }
}

int inicializa(){
    encheMatriz(MAPA);
    if(!al_init()){
        cout << "Falha ao carregar Allegro" << endl;
        return 0;
    }

    if(!al_install_keyboard()){
        cout << "Falha ao inicializar o teclado" << endl;
        return 0;
    }
    if(!al_install_mouse()){
        cout << "Falha ao inicializar o mouse" << endl;
        return 0;
    }
    
    timer = al_create_timer(1.0 / FPS);
    if(!timer){
        cout << "Falha ao inicializar o temporizador" << endl;
        return 0;
    }

    if(!al_init_image_addon()){
        cout <<"Falha ao iniciar al_init_image_addon!" << endl;
        return 0;
    }

    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display){
        cout << "Falha ao inicializar a tela" << endl;
        al_destroy_timer(timer);
        return 0;
    }

    mainmenu = al_load_bitmap("resources/conways_menu.bmp");
    if(!mainmenu){
        cout << "Falha ao carregar o menu!" << endl;
        return 0;
    }

    wall = al_load_bitmap("resources/wall.bmp");
    if(!wall){
        cout << "Falha ao carregar a parede!" << endl;
        return 0;
    }

    mapa = al_load_bitmap("resources/map.bmp");
    if(!mapa){
        cout << "Falha ao carregar o mapa!" << endl;
        al_destroy_display(display);
        return 0;
    }
    al_draw_bitmap(mapa,0,0,0);

    power_up = al_load_bitmap("resources/cell.bmp");
    if(!power_up){
        cout << "Falha ao carregar o power_up" << endl;
        al_destroy_display(display);
        return 0;
    }

    event_queue = al_create_event_queue();
    if(!event_queue){
        cout << "Falha ao criar a fila de eventos" << endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return 0;
    }

    al_init_font_addon();    
    al_init_ttf_addon();    
    font = al_load_ttf_font("resources/VT323-Regular.ttf", 26, 0);  
    
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);
    
    while(statusmenu!=true){
        statusmenu = menu();
    }
    return 1;
}



int desinicializa(){
    al_destroy_bitmap(mapa);
    al_destroy_bitmap(pacman);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
}