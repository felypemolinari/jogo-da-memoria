#include <iostream>
#include <time.h>
#include <cstdlib>


using namespace std;

int main()
{
    cout << "___  ___ _____ ___  ___ _____ ______  _____   ___" << endl;
    cout << "|  \/  ||  ___||  \/  ||  _  || ___ \|_   _| / _ \ "  << endl;
    cout << "| .  . || |__  | .  . || | | || |_/ /  | |  / /_\ \ " << endl;
    cout << "| |\/| ||  __| | |\/| || | | ||    /   | |  |  _  |" << endl;
    cout << "| |  | || |___ | |  | |\ \_/ /| |\ \  _| |_ | | | |"<< endl;
    cout << "\_|  |_/\____/ \_|  |_/ \___/ \_| \_| \___/ \_| |_/"<< endl;

    /// Definir Matriz Principal

    int matrizPrincipal[4][4];
    int numeroAleatorio;

    int valor = 1;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            matrizPrincipal[i][j] = valor;
            valor++;

            if(valor > 8){
                valor = 1;
            }
        }
    }

   /*for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << matrizPrincipal[i][j] << " ";
        }
        cout << endl;
    }*/

    /// Matriz Gabarito

    int matrizGabarito[4][4];

    /*srand(time(NULL));
    int escolhaGabarito = rand() % 4 + 1;*/
    int escolhaGabarito = 1;

    switch (escolhaGabarito) {
        case 1: //Sem Modificação
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizPrincipal[i][j];
                }
            }

            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    cout << matrizGabarito[i][j] << " ";
                }
                cout << endl;
            }

            break;
        case 2: //Transposta
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizPrincipal[j][i];
                }
            }
            /*for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    cout << matrizGabarito[i][j] << " ";
                }
                cout << endl;
            }*/

            break;
        case 3: //Invertida por linha
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizPrincipal[4 - 1 - i][j];
                }
            }

            /*for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    cout << matrizGabarito[i][j] << " ";
                }
                cout << endl;
            }*/

            break;
        default: //Invertida por coluna
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizPrincipal[i][4 - 1 -j];
                }
            }

            /*for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    cout << matrizGabarito[i][j] << " ";
                }
                cout << endl;
            }*/

            break;
    }

    /// Matriz Jogo

    int matrizJogo[4][4];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matrizJogo[i][j] = 0;

        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << matrizJogo[i][j] << " ";
        }
        cout << endl;
    }


    /// Jogadas

    int totalPares = 8;
    int totalJogadas = 8 * 3;
    int paresDescobertos = 0;
    int jogadasRealizadas = 0;
    int linha1, coluna1, linha2, coluna2;
    string resposta;
    int matrizCartaVirada[4][4] = {0};

    do{

        cout << "Digite números de 0 à 3 " << endl;

        cout << "Digite as duas primeiras cordenas [linha][coluna]: ";
        cin >> linha1 >> coluna1;

        while(linha1 < 0 || linha1 > 3 || coluna1 < 0 || coluna1 > 3){
            cout << "Valor Invalido, Insira Novamente:" << endl;
            cout << "Digite as duas primeiras cordenas [linha][coluna]: ";
            cin >> linha1 >> coluna1;
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                matrizCartaVirada[linha1][coluna1] = matrizGabarito[linha1][coluna1];
                cout << matrizCartaVirada[i][j] << " ";
            }
        cout << endl;
        }

        cout << endl;

        cout << "Digite as duas segundas cordenas [linha][coluna]: ";
        cin >> linha2 >> coluna2;

        while(linha2 < 0 || linha2 > 3 || coluna2 < 0 || coluna2 > 3){
            cout << "Valor Invalido, Insira Novamente:" << endl;
            cout << "Digite as duas primeiras cordenas [linha][coluna]: ";
            cin >> linha2 >> coluna2;
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                matrizCartaVirada[linha2][coluna2] = matrizGabarito[linha2][coluna2];
                cout << matrizCartaVirada[i][j] << " ";
            }
        cout << endl;
        }

        cout << endl;

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(matrizGabarito[linha1][coluna1] == matrizGabarito[linha2][coluna2]){
                    matrizJogo[linha1][coluna1] = matrizGabarito[linha1][coluna1];
                    matrizJogo[linha2][coluna2] = matrizGabarito[linha2][coluna2];
                    cout << matrizJogo[i][j] << " ";
                } else {
                    cout << matrizJogo[i][j] << " ";
                }
            }
            cout << endl;
        }

        if(matrizGabarito[linha1][coluna1] == matrizGabarito[linha2][coluna2]){
            resposta = "ACERTOU!";
            cout << resposta;
            paresDescobertos++;
            cout << "Pares Descobertos: " << paresDescobertos << endl;
        } else {
            resposta = "ERROU! TENTE NOVAMENTE!";
            cout << resposta;
        }

    cout << endl;

    if(resposta == "ACERTOU!"){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << matrizJogo[i][j] << " ";
            }
            cout << endl;
        }
        system("read 0 -p");
        system("clear");

           for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    cout << matrizJogo[i][j] << " ";
        }
        cout << endl;
     }
        jogadasRealizadas++;
        cout << "Jogadas Realizadas: " << jogadasRealizadas << endl;
    }

    matrizCartaVirada[linha1][coluna1] = {0};
    matrizCartaVirada[linha2][coluna2] = {0};
    matrizCartaVirada[linha1][coluna1] = matrizJogo[linha1][coluna1];
    matrizCartaVirada[linha2][coluna2] = matrizJogo[linha2][coluna2];

    } while (jogadasRealizadas < totalJogadas && paresDescobertos < totalPares);



    return 0;
}
