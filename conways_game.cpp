/*
        Bem vindo ao jogo da vida
 - Arquivos necessários para a compilação -
Necessário(Se modif.) |                        Incluído
 ------------------------------------------------------
 Mapa                 |                        map2.bmp
 Personagem           |                            .bmp
 Power Up/Sprite      |                   power_up2.bmp
 Fonte(Qlqr TTF serve)|                             ---
FLAGS NECESSÁRIAS PARA O COMPILADOR/LINKADOR -> -lallegro -lallegro_image -lallegro_font -lallegro_ttf
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>   //Importação das funções de FONTE do allegro -> usar junto com 'allegro_ttf.h' para carregar fontes ttf(TrueType Font) 
#include <allegro5/allegro_ttf.h>    //Ao importar esses dois arquivos, adicionar as flags -lallegro_font -lallegro_ttf ao linkador
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


float FPS = 3;
int SCREEN_W = 500;
int SCREEN_H = 550;
const int QUAD_SIZE = 20;

enum MYKEYS
{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

//matriz definindo mapa do jogo: 1 representa paredes, 0 representa corredor
char MAPA[52][52] =
{
    "222222222222222222222222222222222222222222222222222",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "200000000000000000000000000000000000000000000000002",
    "222222222222222222222222222222222222222222222222222"
};

int andou[26][26] = {0};
int andouCorpo[26][26] = {0};
int passo = 0;

ALLEGRO_COLOR *cor = NULL;        // Ponteiro de COR para a fonte
ALLEGRO_FONT *font = NULL;        // Ponteiro de FONTE para inicializar o objeto
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *mapa = NULL;
ALLEGRO_BITMAP *pacman = NULL;
ALLEGRO_BITMAP *pacman_left = NULL;
ALLEGRO_BITMAP *power_up = NULL;
ALLEGRO_BITMAP *power_up1 = NULL;
ALLEGRO_BITMAP *power_up2 = NULL;

int i = 15, j = 12;   //posicao inicial do Pacman na matriz
int q = 20;           //tamanho de cada celula no mapa
int posy = i*q;
int posx = j*q;
int tamanho = 2;
int tamanho_corpo = 1;
int contador = 0;     //contador de tempo
int HRand, WRand;     
int HRand1, WRand1;   
int HRand2, WRand2;   
int *timer1;

bool key[4] = { false, false, false, false };
bool redraw = true;
bool sprite = false;
bool power_up_tamanho = true;
bool sair = false;
bool cima, baixo, esq, dir;

void CLEAR(){                   
    system("CLS");		//limpar tela
}

int inicializa() {
    
    if(!al_init())
    {
        cout << "Falha ao carregar Allegro" << endl;
        return 0;
    }

    if(!al_install_keyboard())
    {
        cout << "Falha ao inicializar o teclado" << endl;
        return 0;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
    {
        cout << "Falha ao inicializar o temporizador" << endl;
        return 0;
    }

    if(!al_init_image_addon())
    {
        cout <<"Falha ao iniciar al_init_image_addon!" << endl;
        return 0;
    }
    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        cout << "Falha ao inicializar a tela" << endl;
        al_destroy_timer(timer);
        return 0;
    }

    mapa = al_load_bitmap("map2.bmp");
    if(!mapa)
    {
        cout << "Falha ao carregar o mapa!" << endl;
        al_destroy_display(display);
        return 0;
    }
    al_draw_bitmap(mapa,0,0,0);

    pacman = al_load_bitmap("VERDE.bmp");
    if(!pacman)
    {
        cout << "Falha ao carregar o pacman!" << endl;
        
        al_destroy_display(display);
        return 0;
    }
    pacman_left = al_load_bitmap("VERMELHO.bmp");
    if(!pacman_left)
    {
        cout << "Falha ao carregar o pacman!" << endl;
        al_destroy_display(display);
        return 0;
    }
    al_draw_bitmap(pacman,posx,posy,0);
    power_up = al_load_bitmap("MeatSmall3.bmp");
    if(!power_up)
    {
        cout << "Falha ao carregar o power_up" << endl;
        al_destroy_display(display);
        return 0;
    }

    power_up1 = al_load_bitmap("MeatSmall.bmp");
    if(!power_up1)
    {
        cout << "Falha ao carregar o power_up" << endl;
        al_destroy_display(display);
        return 0;
    }
	power_up2 = al_load_bitmap("MeatSmall4.bmp");
    if(!power_up2)
    {
        cout << "Falha ao carregar o power_up" << endl;
        al_destroy_display(display);
        return 0;
    }

    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        cout << "Falha ao criar a fila de eventos" << endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return 0;
    }
    al_init_font_addon();    // INICIALIZAR AS FUNÇÕES DE FONTE 
    al_init_ttf_addon();     // INICIALIZAR ESTE ADDON -APÓS- INICIALIZAR O font_addon
    font = al_load_ttf_font("Starjedi.ttf", 26, 0);  // carrega arquivo ttf para formato da fonte
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);

    return 1;
}

int main(int argc, char **argv)
{
	bool morre[52][52] = {false};
    bool vive[52][52] = {true};
    bool doisvive[52][52] = {false};
    bool revive[52][52] = {false};
    bool revivenaprox[52][52] = {false};
    srand(time(NULL));
	if(!inicializa()) return -1;
    int geracao = -1;

    while(!sair)
    {
        
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            passo++;
            geracao += 1;
            if(geracao == 0){
                int celRand = 0;
                int coluna, linha = 0;
                for(int i = 1; i<51;i++){
                    for(int j = 1; j<51;j++){
                        if(((rand()%2)==1 && MAPA[i][j]!='2')){
                            MAPA[i][j] = '1';
                        }
                    }
                }
                for(int i = 0;i<52;i++){
                    for(int j = 0;j<52;j++){
                        if(j==51){
                            cout << MAPA[j][i];
                            cout << '\n';
                             
                        }
                        else{
                            cout << MAPA[j][i] << " ";
                        }
                        
                    }
                }
            }
            
            if(geracao>=1){
                int vizinhos = 0;
                for(int i=1;i<51;i++){
                    for(int j = 1;j<51;j++){
                        revive[i][j] = revivenaprox[i][j];
                        revivenaprox[i][j] = false;

                    }
                }
                for(int i=1;i<51;i++){
                    for(int j = 1;j<51;j++){
                        if(MAPA[i][j]=='0'){
                            if(MAPA[i+1][j]=='1'){
                                    vizinhos++;
                                    }
                                    if(MAPA[i+1][j+1]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i+1][j-1]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i-1][j+1]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i-1][j]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i-1][j-1]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i][j+1]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i][j-1]=='1'){
                                        vizinhos++;
                                    }
                                    if(vizinhos==3){
                                        revive[i][j]=true;
                                    }
                                    vizinhos = 0;
                        }
                            if(MAPA[i][j]=='1'){
                                if(vive){
                                    if(MAPA[i+1][j]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i+1][j+1]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i+1][j-1]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i-1][j+1]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i-1][j]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i-1][j-1]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i][j+1]=='1'){
                                        vizinhos++;
                                    }
                                    if(MAPA[i][j-1]=='1'){
                                        vizinhos++;
                                    }
                                    if(vizinhos>3){
                                        morre[i][j]=true;
                                        vive[i][j]=false;
                                    }

                                    //if(vizinhos==3){
                                    //    
                                    //    vive[i][j] = false;
                                    //    revivenaprox[i][j]=true;
                                    //    
                                    //}
                                    if(vizinhos == 2){
                                        morre[i][j]=false;
                                        vive[i][j]=true;
                                        //int rando = rand() % 8;
                                        //switch(rando){
                                        //    case 0:
                                        //        MAPA[i][j-1]='1';
                                        //        break;
                                        //    case 1:
                                        //        MAPA[i][j+1]='1';
                                        //        break;
                                        //    case 2:
                                        //        MAPA[i+1][j+1]='1';
                                        //        break;
                                        //    case 3:
                                        //        MAPA[i+1][j-1]='1';
                                        //        break;
                                        //    case 4:
                                        //        MAPA[i-1][j]='1';
                                        //        break;
                                        //    case 5:
                                        //        MAPA[i-1][j-1]='1';
                                        //        break;
                                        //    case 6:
                                        //        MAPA[i-1][j+1]='1';
                                        //        break;
                                        //    case 7:
                                        //        MAPA[i+1][j]='1';
                                        //        break;
                                        //}
                                    }
                                    if(vizinhos==1 || vizinhos==0){
                                        morre[i][j]=true;
                                    }
                                    vizinhos = 0;
                                }
                        }
                    }
                }

                for(int i = 1;i<51;i++){
                    for(int j = 1;j<51;j++){
                        if(morre[i][j]){
                            MAPA[i][j]='0';
                        }
                        if(revive[i][j]==true){
                            MAPA[i][j]='1';
                        }
                        
                    }
                }
                for(int i = 0;i<52;i++){
                    for(int j = 0;j<52;j++){
                        if(j==51){
                            cout << MAPA[j][i] << endl;
                        }
                        else{
                            cout << MAPA[j][i] << " ";
                        }
                        
                    }
                }
            }
            
        //sortear novas coordenardas para 'a' (comida padrão)
            //if(MAPA[i][j] == '1') 	//localiza o 'a' na matriz
			//{ 
            //}
        //sortear novas coordenardas para 'b' (comida especial 1)			
            redraw = true;
            
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }


        if(redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = false;
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_bitmap(mapa,0,0,0);
			//al_draw_bitmap(power_up, HRand*q, WRand*q, 0);		    //redesenha comida nas coordenardas aleatorias


            for(int l=1;l<51;l++){
				for(int p=1;p<51;p++){
                    if(MAPA[l][p]=='1'){
                        al_draw_bitmap(power_up, l*10, p*10, 0);
                    }
				}
			}
			al_flip_display();
		}
	}

    al_destroy_bitmap(mapa);
    al_destroy_bitmap(pacman);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}
