#include <bits/stdc++.h>
#include <locale.h>
#include <stdbool.h>
#define SIZE 16
using namespace std;


int main(void){
    int tabuleiro1[SIZE][SIZE], tabuleiro2[SIZE][SIZE], i, j, x, y, navio, casas, menu = 5, entrar = 0 ,voltar = 0;
    string player1, player2;
    setlocale(LC_ALL,"Portuguese");
    
    for(i = 0 ; i < SIZE ; i++){
        for(j = 0 ; j < SIZE ; j++){
            tabuleiro1[i][j] = 0;
            tabuleiro2[i][j] = 0;
        }
    }

    //TELA INICIAL DO JOGO.
    system("clear || cls");

    cout << " ================================================== " << endl << endl << endl;
    cout << "                  GUERRA NOS MARES                  " << endl << endl << endl;
    cout << " ================================================== " << endl << endl << endl;

    cout << "Pressione ENTER para iniciar : ";
    cin.ignore();

    system("clear || cls");

    //MENU

    while(menu != 1){
        cout << "MENU INICIAL" << endl << endl;
        cout << "SELECIONE UMA OPCAO \n1. JOGAR \n2. SOBRE" << endl << endl;
        cout << "OPCAO: ";
        cin >> menu;
        if(menu == 1){
            continue;
        }
        else if(menu == 2){
            system("clear || cls");
            cout << "\n\nGUERRA NOS MARES \nVERSÃO 2020 \n\n\nDESENVOLVIDO POR: DAVI QUEIROZ ALBUQUERQUE \n\n";
            cout << "\n\nPressione qualquer tecla para voltar ao menu : ";
            cin >> voltar;
            menu = 5;
            system("clear || cls");
        }
        else if(menu != 1 && menu != 2){
            cout << "OPCAO NAO VALIDA / TENTE NOVAMENTE : ";
        }
    }

    system("clear || cls");

    //Pede o nome dos jogadores.

    cout << "Digite o nome dos dois jogadores (sem espaços): \nJogador 1 : ";
    cin >> player1;
    cout << "Jogador 2 : ";
    cin >> player2;

    system("clear || cls");
    //Preparando o jogo e o tabuleiro.
    cout << "JOGADOR: " << player1 << endl;
    cout << "EMBARCACOES: \n\n1. Corveta (1x2) \n2. Submarino (1x3) \n3. Fragata (1x3)" << endl;
    cout << "4. Destroyer (1x4) \n5. Cruzador (1x5) \n6. Porta-Avioes (2x6)" << endl << endl;

    
    //Tabuleiro do 1º jogador.
    int ships1[6] = {1, 1, 1, 1, 1, 1};
    cout << "------------------------- JOGADOR 1 -------------------------" << endl;
    cout << endl << "Instale suas embarcacoes digitando suas coordenadas (X , Y) : " << endl << endl;
    for(i = 1 ; i <= 6 ; i++){
        cout << "Navio: ";
        cin >> navio;
        if(navio > 6 || navio < 0){
            while(navio > 6 || navio < 0){
                cout << "DIGITE UM INDICE VALIDO: ";
                cin >> navio;
                cout << endl;
            }
        }
        if(ships1[navio - 1] == 0){
            while(ships1[navio - 1] == 0){
                cout << "TIPO DE EMBARCACAO JA ESCOLHIDA / TENTE NOVAMENTE: ";
                cin >> navio;
                cout << endl;
            }
        }
        if(navio == 1){
            casas = 2;
        }
        else if(navio == 2 || navio == 3){
            casas = 3;
        }
        else if(navio == 4){
            casas = 4;
        }
        else if(navio == 5){
            casas = 5;
        }
        else if(navio == 6){
            casas = 12;
        }

        ships1[navio - 1] = 0;

        for(j = 1 ; j <= casas ; j++){
            printf("%2d. X = ", j);
            cin >> x;
            cout << "    Y = ";
            cin >> y;
            tabuleiro1[x][y] = navio;
        }
        cout << endl;
    }
    cout << endl;
    system("clear || cls");
    
    //Mostra ao segundo jogador as embarcações.
    cout << "JOGADOR: " << player2 << endl << endl;
    cout << "EMBARCACOES: \n\n1. Corveta (1x2) \n2. Submarino (1x3) \n3. Fragata (1x3)" << endl;
    cout << "4. Destroyer (1x4) \n5. Cruzador (1x5) \n6. Porta-Avioes (2x6)" << endl << endl;

    //Tabuleiro do 2º jogador.
    int ships2[6] = {1, 1, 1, 1, 1, 1};
    cout << "------------------------- JOGADOR 2 -------------------------" << endl;
    cout << endl << "Instale suas embarcacoes digitando suas coordenadas (X , Y) : " << endl << endl;
    for(i = 1 ; i <= 6 ; i++){
        cout << "Navio: ";
        cin >> navio;
        if(navio > 6 || navio < 0){
            while(navio > 6 || navio < 0){
                cout << "DIGITE UM INDICE VALIDO: ";
                cin >> navio;
            }
        }
        if(ships2[navio - 1] == 0){
            while(ships2[navio - 1] == 0){
                cout << "TIPO DE EMBARCACAO JA ESCOLHIDA / TENTE NOVAMENTE: ";
                cin >> navio;
            }
        }
        if(navio == 1){
            casas = 2;
        }
        else if(navio == 2 || navio == 3){
            casas = 3;
        }
        else if(navio == 4){
            casas = 4;
        }
        else if(navio == 5){
            casas = 5;
        }
        else if(navio == 6){
            casas = 12;
        }

        ships2[navio - 1] = 0;

        for(j = 1 ; j <= casas ; j++){
            printf("%2d. X = ", j);
            cin >> x;
            cout << "    Y = ";
            cin >> y;
            tabuleiro2[x][y] = navio;
        }
        cout << endl;
    }
    cout << endl;
    system("clear || cls");

    int cont[3] = {0, 29, 29}, jogador, n = 0, continua;
    bool vencedor = false;

    //Loop onde o jogo irá acontecer.

    while(!vencedor){

        system("clear || cls");
        
        jogador = (n % 2) + 1; //Alterna entre os jogadores.
        cout << "JOGADOR : " << jogador;
        if(jogador == 1) cout << " " << player1 << endl;
        else if(jogador == 2) cout << " " << player2 << endl;
        cout << "---------------- MAPA DE ATAQUE ---------------" << endl << endl;

        /*
        Imprime o mapa de ataque para cada jogador.
        LEGENDA:
        [ - ] = coordenada livre
        [ # ] = tiro no mar 
        [ X ] = tiro certo
        */

        if(jogador == 1){
            for(i = 1 ; i <= 15 ; i++){
                for(j = 1 ; j <= 15 ; j++){
                    if(tabuleiro2[i][j] >= 0){
                        cout << " [ - ] ";
                    }
                    else if(tabuleiro2[i][j] == -1){
                        cout << " [ # ] ";
                    }
                    else if(tabuleiro2[i][j] == -2){
                        cout << " [ X ] ";
                    }
                }
                cout << endl;
            }
        }
        else if(jogador == 2){
            for(i = 1 ; i <= 15 ; i++){
                for(j = 1 ; j <= 15 ; j++){
                    if(tabuleiro1[i][j] >= 0){
                        cout << " [ - ] ";
                    }
                    else if(tabuleiro1[i][j] == -1){
                        cout << " [ # ] ";
                    }
                    else if(tabuleiro1[i][j] == -2){
                        cout << " [ X ] ";
                    }
                }
            cout << endl;
            }
        }

        cout << "LEGENDA:" << endl;
        cout << "[ - ] = coordenada livre" << endl;
        cout << "[ # ] = tiro no mar" << endl;
        cout << "[ X ] = tiro certo" << endl << endl;

        //Pede as coordenadas de ataque.
        cout << "ATAQUE : \nX = ";
        cin >> x;
        cout << "\nY = ";
        cin >> y;
        cout << endl;

        //Procura a coordenada e reconhece se ela já foi utilizada, possui embarcação ou se o tiro será no mar.

        //Quando o jogador 1 ataca.
        if(jogador == 1){
            //Coordenada já escolhida.
            if(tabuleiro2[x][y] <= -1){
                cout << "TIRO INVÁLIDO / COORDENADA JÁ FOI ESCOLHIDA" << endl;
                while(tabuleiro2[x][y] <= -1){
                    cout << "Digite novamente: ";
                    cin >> x >> y;
                }
            }

            //Possui embarcação e mostra qual foi acertada.
            else if(tabuleiro2[x][y] > 0){
                if(jogador == 1){
                    cout << "ACERTOU: " << tabuleiro2[x][y] << endl;
                    tabuleiro2[x][y] = -2;
                    cont[2]--;
                }
            }

            //Tiro no mar.
            else if(tabuleiro2[x][y] == 0){
                if(jogador == 1){
                    cout << "ERROU: TIRO NO MAR" << endl;
                    tabuleiro2[x][y] = -1;
                }
            }
        }

        //Quando o jogador 2 ataca.
        else if(jogador == 2){
            //Coordenada já escolhida.
            if(tabuleiro1[x][y] <= -1){
                cout << "TIRO INVÁLIDO / COORDENADA JÁ FOI ESCOLHIDA" << endl;
                while(tabuleiro1[x][y] <= -1){
                    cout << "Digite novamente: ";
                    cin >> x >> y;
                }
            }

            //Possui embarcação e mostra qual foi acertada.
            else if(tabuleiro1[x][y] > 0){
                if(jogador == 1){
                    cout << "ACERTOU: " << tabuleiro1[x][y] << endl;
                    tabuleiro1[x][y] = -2;
                    cont[1]--;
                }
            }

            //Tiro no mar.
            else if(tabuleiro1[x][y] == 0){
                if(jogador == 1){
                    cout << "ERROU: TIRO NO MAR" << endl;
                    tabuleiro1[x][y] = -1;
                }
            }
        }
        if(cont[1] == 0 || cont[2] == 0){
            vencedor = true;
        }

        if(vencedor == true){
            continue;
        }

        //Imprime o mapa atualizado.
        if(jogador == 1){
            for(i = 1 ; i <= 15 ; i++){
                for(j = 1 ; j <= 15 ; j++){
                    if(tabuleiro2[i][j] >= 0){
                        cout << " [ - ] ";
                    }
                    else if(tabuleiro2[i][j] == -1){
                        cout << " [ # ] ";
                    }
                    else if(tabuleiro2[i][j] == -2){
                        cout << " [ X ] ";
                    }
                }
                cout << endl;
            }
        }
        else if(jogador == 2){
            for(i = 1 ; i <= 15 ; i++){
                for(j = 1 ; j <= 15 ; j++){
                    if(tabuleiro1[i][j] >= 0){
                        cout << " [ - ] ";
                    }
                    else if(tabuleiro1[i][j] == -1){
                        cout << " [ # ] ";
                    }
                    else if(tabuleiro1[i][j] == -2){
                        cout << " [ X ] ";
                    }
                }
            cout << endl;
            }
        }

        continua = 0;
        while(continua != 5){
            cout << "Digite 5 para o próximo jogador atacar... ";
            cin >> continua;
        }
        n++; //Avança para o próximo jogador.
    }

    system("clear || cls"); //Limpa a tela.

    //Imprime o vencedor e o mapa de cada um dos jogadores.
    if(cont[2] == 0){
        cout << "GANHADOR : JOGADOR 1 !!!!!" << endl;
    }
    else if(cont[1] == 0){
        cout << "GANHADOR : JOGADOR 2 !!!!!" << endl;
    }

    //Mapa JOGADOR 1
    cout << " ---------------  MAPA JOGADOR 1  --------------- " << endl << endl;
    for(i = 1 ; i <= 15 ; i++){
        for(j = 1 ; j <= 15 ; j++){
            if(tabuleiro1[i][j] >= 0){
                cout << " [ " << tabuleiro1[i][j] << " ] ";
            }
            else if(tabuleiro1[i][j] == -1){
                cout << " [ # ] ";
            }
            else if(tabuleiro1[i][j] == -2){
                cout << " [ X ] ";
            }
        }
        cout << endl;
    }

    //Mapa JOGADOR 2
    cout << " ---------------  MAPA JOGADOR 2  --------------- " << endl << endl;
    for(i = 1 ; i <= 15 ; i++){
        for(j = 1 ; j <= 15 ; j++){
            if(tabuleiro2[i][j] >= 0){
                cout << " [ " << tabuleiro2[i][j] << " ] ";
            }
            else if(tabuleiro2[i][j] == -1){
                cout << " [ # ] ";
            }
            else if(tabuleiro2[i][j] == -2){
                cout << " [ X ] ";
            }
        }
        cout << endl;
    }

    return 0;
}
