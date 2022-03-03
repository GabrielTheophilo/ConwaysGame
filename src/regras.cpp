class Regras {
    public:
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
                case 16:
                    MAPA[coordenadaX][coordenadaY] = '3';
                    MAPA[coordenadaX+1][coordenadaY] = '3';
                    MAPA[coordenadaX+1][coordenadaY-1] = '3';
                    MAPA[coordenadaX][coordenadaY-1] = '3';
                    break;
            }
    }  
};