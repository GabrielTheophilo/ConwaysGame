/*
    Author: Gabriel Theophilo
    github.com/GabrielTheophilo
    *12/01/2022*

*/
#include "allegro.h" 

void regrasVive(int vizinhos, bool morre[][260], bool vive[][260], int indexX,int indexY);
void regrasMorre(int vizinhos, bool revive[][260], int indexX,int indexY);
void escreveCoordenadas(char MAPA[260][260], int* coordenadaX, int* coordenadaY, int choice);
int inicializa();
int desinicializa();


char MAPA[260][260];

const char *texto   = {"Geração: "};
const char *fpsMark = {"TickRate: "};
const char *celulas = {"Células: "};
const char *variante = {"Variante: "};
const char *varianteConway = {"Conway's"};
const char *varianteHighLife = {"HighLife"};

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
int SCREEN_W = 1000;
int SCREEN_H = 1000;

float FPS = 12.0;
float *FPSPointer = &FPS;

bool redraw  = true;
bool sair    = false;
bool variante_Conway =  false;
bool variante_HighLife = false;
bool highres = false;
bool statusmenu = false;