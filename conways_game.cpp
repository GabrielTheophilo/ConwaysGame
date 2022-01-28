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
#include <clocale>
#include "conways_game.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>  
#include <allegro5/allegro_ttf.h>    
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;



enum MYKEYS
{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

float FPS = 12.0;
float *FPSPointer = &FPS;
int SCREEN_W = 1000;
int SCREEN_H = 1000;


ALLEGRO_COLOR *cor = NULL;  
ALLEGRO_FONT *font = NULL;       
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *mapa = NULL;
ALLEGRO_BITMAP *pacman = NULL;
ALLEGRO_BITMAP *pacman_left = NULL;
ALLEGRO_BITMAP *power_up = NULL;
ALLEGRO_BITMAP *power_up1 = NULL;
ALLEGRO_BITMAP *power_up2 = NULL;
ALLEGRO_BITMAP *mainmenu = NULL;
ALLEGRO_BITMAP *wall = NULL;

int *timer1;
int contador = 0;   
int passo    = 0;
bool redraw  = true;
bool sair    = false;
bool variante_Conway =  false;
bool variante_HighLife = false;
bool highres = false;
bool statusmenu = false;


void escreveCoordenadas(char MAPA[260][260], int coordenadaX, int coordenadaY, int choice){
        switch(choice){
            case 0:
                MAPA[coordenadaX][coordenadaY] = '1';
                MAPA[coordenadaX-1][coordenadaY] = '1';
                MAPA[coordenadaX+1][coordenadaY-1] = '1';
                MAPA[coordenadaX-1][coordenadaY+1] = '1';
                MAPA[coordenadaX+1][coordenadaY+1] = '1';
                break;
            case 1:
                MAPA[coordenadaX][coordenadaY] = '1';
                MAPA[coordenadaX-1][coordenadaY] = '1';
                MAPA[coordenadaX][coordenadaY+1] = '1';
                break;
            case 2:
                MAPA[coordenadaX][coordenadaY] = '1';
                MAPA[coordenadaX+1][coordenadaY] = '1';
                MAPA[coordenadaX-1][coordenadaY-1] = '1';
                break;
            case 3:
                MAPA[coordenadaX][coordenadaY] = '1';
                MAPA[coordenadaX+1][coordenadaY] = '1';
                MAPA[coordenadaX-1][coordenadaY-1] = '1';
                MAPA[coordenadaX-1][coordenadaY] = '1';
                break;
            case 4:
                MAPA[coordenadaX][coordenadaY] = '1';
                MAPA[coordenadaX-1][coordenadaY] = '1';
                MAPA[coordenadaX-2][coordenadaY] = '1';
                MAPA[coordenadaX-1][coordenadaY-2] = '1';
                MAPA[coordenadaX][coordenadaY-1] = '1';
                break;
            case 5:
                //quadrado
                MAPA[coordenadaX][coordenadaY] = '1';
                MAPA[coordenadaX-1][coordenadaY] = '1';
                MAPA[coordenadaX][coordenadaY+1] = '1';
                MAPA[coordenadaX-1][coordenadaY+1] = '1';
                //lado direito
                MAPA[coordenadaX+1][coordenadaY-3] = '1';
                MAPA[coordenadaX+1][coordenadaY-4] = '1';
                MAPA[coordenadaX+1][coordenadaY-5] = '1';
                MAPA[coordenadaX+2][coordenadaY-5] = '1';
                MAPA[coordenadaX+3][coordenadaY-4] = '1';
                MAPA[coordenadaX+3][coordenadaY-5] = '1';
                //lado esquerdo
                MAPA[coordenadaX-2][coordenadaY-3] = '1';
                MAPA[coordenadaX-2][coordenadaY-4] = '1';
                MAPA[coordenadaX-2][coordenadaY-5] = '1';
                MAPA[coordenadaX-3][coordenadaY-5] = '1';
                MAPA[coordenadaX-4][coordenadaY-4] = '1';
                MAPA[coordenadaX-4][coordenadaY-5] = '1';
                break;
            case 6:
                MAPA[coordenadaX][coordenadaY] = '1';
                MAPA[coordenadaX-1][coordenadaY] = '1';
                MAPA[coordenadaX-1][coordenadaY+1] = '1';
                MAPA[coordenadaX-1][coordenadaY+2] = '1';
                MAPA[coordenadaX-1][coordenadaY+3] = '1';
                MAPA[coordenadaX-1][coordenadaY+4] = '1';
                MAPA[coordenadaX][coordenadaY+1] = '1';
                MAPA[coordenadaX][coordenadaY+2] = '1';
                MAPA[coordenadaX][coordenadaY+3] = '1';
                MAPA[coordenadaX][coordenadaY+4] = '1';
                break;
            case 7:
                MAPA[coordenadaX][coordenadaY] = '1';
                MAPA[coordenadaX-1][coordenadaY] = '1';
                MAPA[coordenadaX-2][coordenadaY] = '1';
                MAPA[coordenadaX-1][coordenadaY-2] = '1';
                MAPA[coordenadaX][coordenadaY-1] = '1';
                break;
            case 8:
                MAPA[coordenadaX][coordenadaY-4] = MAPA[coordenadaX][coordenadaY-3] = '1';
                MAPA[coordenadaX+1][coordenadaY-4] = MAPA[coordenadaX+1][coordenadaY-3] = '1';
                MAPA[coordenadaX-2][coordenadaY+8] = MAPA[coordenadaX-2][coordenadaY+9] = '1';
                MAPA[coordenadaX-1][coordenadaY+7] = MAPA[coordenadaX-1][coordenadaY+11] = '1';
                MAPA[coordenadaX][coordenadaY+6] = MAPA[coordenadaX][coordenadaY+12] = '1';
                MAPA[coordenadaX+1][coordenadaY+6] = MAPA[coordenadaX+1][coordenadaY+10] = MAPA[coordenadaX+1][coordenadaY+12] = MAPA[coordenadaX+1][coordenadaY+13] = '1';
                MAPA[coordenadaX+2][coordenadaY+6] = MAPA[coordenadaX+2][coordenadaY+12] = '1';
                MAPA[coordenadaX+3][coordenadaY+7] = MAPA[coordenadaX+3][coordenadaY+11] = '1';
                MAPA[coordenadaX+4][coordenadaY+8] = MAPA[coordenadaX+4][coordenadaY+9] = '1';
                MAPA[coordenadaX-4][coordenadaY+20] = '1';
                MAPA[coordenadaX-3][coordenadaY+18] = MAPA[coordenadaX-3][coordenadaY+20] = '1';
                MAPA[coordenadaX-2][coordenadaY+16] = MAPA[coordenadaX-2][coordenadaY+17] = '1';
                MAPA[coordenadaX-1][coordenadaY+16] = MAPA[coordenadaX-1][coordenadaY+17] = '1';
                MAPA[coordenadaX][coordenadaY+16] = MAPA[coordenadaX][coordenadaY+17] = '1';
                MAPA[coordenadaX+1][coordenadaY+18] = MAPA[coordenadaX+1][coordenadaY+20] = '1';
                MAPA[coordenadaX+2][coordenadaY+20] = '1';
                MAPA[coordenadaX-2][coordenadaY+30] = MAPA[coordenadaX-2][coordenadaY+31] = '1';
                MAPA[coordenadaX-1][coordenadaY+30] = MAPA[coordenadaX-1][coordenadaY+31] = '1';
                break;
        }
    
}

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

void regrasMorre(int vizinhos, bool revive[][260], int indexX,int indexY){
    if(variante_Conway == true){
        if(vizinhos==3){
            revive[indexX][indexY]=true;
        }
    }
    if(variante_HighLife == true){
        if(vizinhos==3||vizinhos==6){
            revive[indexX][indexY]=true;
        }
    }
}

void regrasVive(int vizinhos, bool morre[][260], bool vive[][260], int indexX,int indexY){
    if(variante_Conway == true){
        if(vizinhos == 2 || vizinhos == 3){
            morre[indexX][indexY]=false;
            vive[indexX][indexY]=true;
        }
        if(vizinhos==1 || vizinhos==0||vizinhos==4||vizinhos==5||vizinhos==6||vizinhos==7||vizinhos==8){
            morre[indexX][indexY]=true;
        }
    }
    if(variante_HighLife == true){
        if(vizinhos == 2 || vizinhos == 3){
            morre[indexX][indexY]=false;
            vive[indexX][indexY]=true;
        }
        if(vizinhos==1 || vizinhos==0){
            morre[indexX][indexY]=true;
        }
    }
}

int inicializa(){
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

    mainmenu = al_load_bitmap("recursos/conways_menu.bmp");
    if(!mainmenu){
        cout << "Falha ao carregar o menu!" << endl;
        return 0;
    }

    wall = al_load_bitmap("recursos/wall.bmp");
    if(!wall){
        cout << "Falha ao carregar a parede!" << endl;
        return 0;
    }

    mapa = al_load_bitmap("recursos/map.bmp");
    if(!mapa){
        cout << "Falha ao carregar o mapa!" << endl;
        al_destroy_display(display);
        return 0;
    }
    al_draw_bitmap(mapa,0,0,0);

    power_up = al_load_bitmap("recursos/cell.bmp");
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
    font = al_load_ttf_font("recursos/VT323-Regular.ttf", 26, 0);  
    
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

