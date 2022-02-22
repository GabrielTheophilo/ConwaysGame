/*
    Author: Gabriel Theophilo
    github.com/GabrielTheophilo
    *12/01/2022*

*/

void regrasVive(int vizinhos, bool morre[][260], bool vive[][260], int indexX,int indexY);
void regrasMorre(int vizinhos, bool revive[][260], int indexX,int indexY);
void escreveCoordenadas(char MAPA[260][260], int* coordenadaX, int* coordenadaY, int choice);
int inicializa();
int desinicializa();

const char *texto   = {"Geração: "};
const char *fpsMark = {"TickRate: "};
const char *celulas = {"Células: "};
const char *variante = {"Variante: "};
const char *varianteConway = {"Conway's"};
const char *varianteHighLife = {"HighLife"};