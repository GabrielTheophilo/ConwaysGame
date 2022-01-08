# Conway's Game of Life 🚀
![Conway's Game](https://i.imgur.com/WhBDIgS.png)

<h2>Hey, if you are looking for the README in ENGLISH, please visit the README_EN-US.md file, it has all the information you need. Have a great day</h2>

https://pt.wikipedia.org/wiki/Jogo_da_vida

O jogo da vida de Conway (Conway's Game of Life) é um jogo simples que captura a imaginação de milhares de pessoas desde a década de 70, quando foi inventado. Sua proposta é simples: O jogo não é jogado por um jogador. O espaço entre a tela do seu computador e a cadeira compreende o lugar do observador deste jogo. Um tabuleiro, uma malha, ou um cenário é colocado na tela, e a partir dela sorteamos aleatóriamente onde os habitantes desse pequeno universo vão nascer.
Eles, assim como nós, são seres sociais, e não gostam nem um pouco de solidão. Porém, se a vizinhança começa a ficar muito lotada... bom... digamos que eles resolvam partir dali.
E é assim que funciona:
1. Se uma célula tiver 1 ou 0 vizinhos, ela morre de solidão
2. Se a célula viva tiver exatamente 2 ou 3 vizinhos, ela continua viva
3. Se uma célula morta tiver 3 vizinhos, surge uma célula viva
4. Se uma célula viva tiver mais de 3 vizinhos, ela morre de superlotação

Como rodar o jogo:

-Você pode baixar os binários do projeto e executar em sua máquina acessando a página de [Releases](https://github.com/GabrielTheophilo/ConwaysGame/releases/tag/v0.0.1-alpha) e baixando o arquivo release.zip contendo o executável e os arquivos necessários para rodar o programa

-Você pode compilar a partir da fonte, e rodar o executável gerado a partir disso

Como compilar o programa:
1. Baixe a biblioteca [Allegro5](https://liballeg.org/) e adicione-a ao PATH de sua máquina
2. Clone o repositório:
```console
foo@bar:~$ git clone https://github.com/GabrielTheophilo/ConwaysGame.git
```
3. Entre na pasta criada
```console
foo@bar:~$ cd ConwaysGame
```
4. Com o compilador instalado, invoque o comando
```console
foo@bar:~$ gcc -o conwaysgame.exe conways_game.cpp -lallegro -lallegro_image -lallegro_font -lallegro_ttf
```
5. O executável deve aparecer na pasta que foi clonada
6. Se houver problema na execução, coloque na mesma pasta do executável as DLL's da biblioteca allegro > libstdc++-6.dll, libwinpthread-1.dll e libgcc_s_seh-1

**TO DO's**:
1. Editar a fonte
2. Criar um makefile
3. Adicionar menu inicial
4. Modularizar os sprites e regras em objetos
5. Integrar todas as variantes num programa só, após criar o menu

**Screenshots**
![Conway's](https://i.imgur.com/dNhyYSJ.png)