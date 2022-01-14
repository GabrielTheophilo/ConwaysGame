#include "conways_game.cpp"


int main(int argc, char **argv){
	bool morre[260][260] = {false};
    bool vive[260][260] = {true};
    bool doisvive[260][260] = {false};
    bool revive[260][260] = {false};
    bool revivenaprox[260][260] = {false};
    int contador_vivos = 0;
    
    int geracao = -1;

    srand(time(NULL));

	if(!inicializa()) return -1;

    while(!sair){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            passo++;
            geracao += 1;
            if(geracao == 0){
                int celRand = 0;
                int coluna, linha = 0;
                for(int i = 59; i<182;i++){
                    for(int j = 59; j<182;j++){
                        if(((rand()%8)==1 && MAPA[i][j]!='2')){
                            MAPA[i][j] = '1';
                        }
                    }
                }
            }
            if(geracao>=1){
                int vizinhos = 0;
                for(int i=1;i<259;i++){
                    for(int j = 1;j<259;j++){
                        revive[i][j] = revivenaprox[i][j];
                        revivenaprox[i][j] = false;

                    }
                }
                for(int i=1;i<259;i++){
                    for(int j = 1;j<259;j++){
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
                                    // b3
                                    regrasMorre(vizinhos, revive, i, j);
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
                                //s23
                                regrasVive(vizinhos,morre,vive,i,j);
                                vizinhos = 0;
                            }
                        }
                    }
                }

                for(int i = 1;i<259;i++){
                    for(int j = 1;j<259;j++){
                        if(morre[i][j]){
                            MAPA[i][j]='0';
                        }
                        if(revive[i][j]==true){
                            MAPA[i][j]='1';
                        } 
                    }
                }
            }		
            redraw = true;
        }

        else if(ev.type == ALLEGRO_EVENT_KEY_UP){
            switch(ev.keyboard.keycode)
            {
				case ALLEGRO_KEY_UP:
                    if(*FPSPointer<=150.0){
                        *FPSPointer+=1.0;
                        al_set_timer_speed(timer, 1.0/ *FPSPointer);
                    }
				    break;
				case ALLEGRO_KEY_DOWN:
                    if(*FPSPointer>=2.0){
                        *FPSPointer-=1.0;
                        al_set_timer_speed(timer, 1.0/ *FPSPointer);
                    }
                    break;
                case ALLEGRO_KEY_SPACE:
                    for(int i = 49; i<208;i++){
                        for(int j = 49; j<208;j++){
                            if(((rand()%32)==1 && MAPA[i][j]!='2')){
                                MAPA[i][j] = '1';
                            }
                        }
                    }
                    break;
                case ALLEGRO_KEY_LEFT:
                    for(int i = 0; i<259;i++){
                        for(int j = 0; j<259;j++){
                            MAPA[i][j] = '0';
                        }
                    }
                    break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            int coordenadaX = ev.mouse.x/4;
            int coordenadaY = ev.mouse.y/4;
            int random = (rand()%4);
            switch(random){
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
                    MAPA[coordenadaX+1][coordenadaY] = '1';
                    MAPA[coordenadaX-1][coordenadaY-1] = '1';
                    MAPA[coordenadaX-1][coordenadaY] = '1';
                    MAPA[coordenadaX+1][coordenadaY+1] = '1';
                    break;
            }
            
        }
        
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            break;
        }
        if(redraw && al_is_event_queue_empty(event_queue)){
            contador_vivos = 0;
            redraw = false;
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_bitmap(mapa,0,0,0);
            for(int l=1;l<259;l++){
	        	for(int p=1;p<259;p++){
                    if(MAPA[l][p]=='1'){
                        contador_vivos++;
                        al_draw_bitmap(power_up, l*4, p*4, 0);
                    }
	        	}
	        }
            al_draw_textf(font, al_map_rgb(255,0,0),330,920, 0, texto);
            al_draw_textf(font, al_map_rgb(255,0,0),620,920, 0, "%d", geracao);
            al_draw_textf(font, al_map_rgb(255,0,0),330,900, 0, fpsMark);
            al_draw_textf(font, al_map_rgb(255,0,0),620,900, 0, "%0.1f", FPS);
            al_draw_textf(font, al_map_rgb(255,0,0),330,950, 0, celulas);
            al_draw_textf(font, al_map_rgb(255,0,0),620,950, 0, "%d", contador_vivos);

            al_draw_textf(font, al_map_rgb(255,0,0),330,970, 0, variante);

            if(variante_Conway){
                al_draw_textf(font, al_map_rgb(255,0,0),620,970, 0, varianteConway);
            }
            else if(varianteHighLife){
                al_draw_textf(font, al_map_rgb(255,0,0),620,970, 0, varianteHighLife);
            }

	        al_flip_display();
		}
	}
    desinicializa();
    return 0;
}