// |----------------------------------|
// |      AUTORES DO PROJETO:         |
// |----------------------------------|
// | - FELYPE MOLINARI                |
// | - NÍCOLAS FRANCISCO TEIXEIRA     |
// |----------------------------------|

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    /// Matriz Principal.

    int matrizPrincipal[4][4]; // Definimos a matriz principal.
    int valor = 1; // Variável de controle para os pares.

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            matrizPrincipal[i][j] = valor;
            valor++;

            if(valor > 8){
                valor = 1;
            }
        }
    }

    /// Matriz Gabarito.

    int matrizGabarito[4][4]; // Definimos matriz gabarito.
    int escolhaGabarito; // Variável de controle para a escolha dos números.

    // Processo de escolha.
    srand(time(NULL));
    escolhaGabarito = rand() % 4 + 1;

    // Switch case para a definição de matriz.
    switch (escolhaGabarito) {
        case 1: // Sem Modificação.
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizPrincipal[i][j];
                }
            }

            break;
        case 2: // Transposta.
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizPrincipal[j][i];
                }
            }

            break;
        case 3: // Invertida por linha.
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizPrincipal[4 - 1 - i][j];
                }
            }

            break;
        case 4: // Invertida por coluna.
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    matrizGabarito[i][j] = matrizPrincipal[i][4 - 1 -j];
                }
            }

            break;
    }

    /// Matriz Jogo.

    int matrizJogo[4][4]; // Definimos matriz jogo.

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matrizJogo[i][j] = 0;

        }
    }

    /// Jogadas.

    int totalPares = 8; // Contagem dos pares.
    int totalJogadas = 8 * 3; // Contagem total de jogadas.
    int paresDescobertos = 0; // Contagem de valores descobertos.
    int jogadasRealizadas = 0; // Contagem de jogadas realizadas.
    int matrizCartaVirada[4][4] = {0}; // Definimos uma matriz para virar as cartas.
    int matrizVerifPosi[4][4] = {0}; // Definimos uma matriz para verificar as posições.
    int linha1, coluna1, linha2, coluna2; // Armazenamento de dados do usuário.


    // Do...While loop para controle de repetição do código.
    do{
        cout <<
            "___  ___ _____ ___  ___ _____ ______ __   __  _____   ___  ___  ___ _____            \n"
            "|  \\/  ||  ___||  \\/  ||  _  || ___ \\\\ \\ / / |  __ \\ / _ \\ |  \\/  ||  ___|   \n"
            "| .  . || |__  | .  . || | | || |_/ / \\ V /  | |  \\// /_\\ \\| .  . || |__         \n"
            "| |\\/| ||  __| | |\\/| || | | ||    /   \\ /   | | __ |  _  || |\\/| ||  __|        \n"
            "| |  | || |___ | |  | |\\ \\_/ /| |\\ \\   | |   | |_\\ \\| | | || |  | || |___      \n"
            "\\_|  |_/\\____/ \\_|  |_/ \\___/ \\_| \\_|  \\_/    \\____/\\_| |_/\\_|  |_/\\____/ \n"
        << endl;

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << matrizJogo[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Digite números de 0 à 3: " << endl;

        cout << "Digite as duas primeiras coordenadas [linha][coluna]: ";
        cin >> linha1 >> coluna1;

        // Verificar se o valor está dentro do desejado(0 à 3).
        while(linha1 < 0 || linha1 > 3 || coluna1 < 0 || coluna1 > 3){
            cout << "Valor inválido, insira novamente:" << endl;
            cout << "Digite as duas primeiras coordenadas [linha][coluna]: ";
            cin >> linha1 >> coluna1;
        }

        // Verificar se o valor já foi achado anteriormente.
        while(matrizGabarito[linha1][coluna1] == matrizVerifPosi[linha1][coluna1]){
            cout << "Valor já foi inserido e validado. " << endl;
            cout << "Digite as duas primeiras coordenadas novamente [linha][coluna]: ";
            cin >> linha1 >> coluna1;
        }

        // For para aparecer o valor achado pelas coordenadas.
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                matrizCartaVirada[linha1][coluna1] = matrizGabarito[linha1][coluna1];
                cout << matrizCartaVirada[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;

        cout << "Digite as duas segundas coordenadas [linha][coluna]: ";
        cin >> linha2 >> coluna2;

        // Verificar se as primeiras coordenadas são iguais as segundas.
        while(linha1 == linha2 && coluna1 == coluna2){
            cout << "Numeros inválidos" << "\n" << "Insira a segunda coordenada novamente: " << endl;
            cin >> linha2 >> coluna2;
        }

        // Verificar se o valor está dentro do desejado.
        while(linha2 < 0 || linha2 > 3 || coluna2 < 0 || coluna2 > 3){
            cout << "Valor inválido, insira novamente:" << endl;
            cout << "Digite as duas segundas coordenadas [linha][coluna]: ";
            cin >> linha2 >> coluna2;
        }

        // Verificar se o valor já foi achado anteriormente.
        while(matrizGabarito[linha2][coluna2] == matrizVerifPosi[linha2][coluna2]){
            cout << "Valor já foi inserido e validado. " << endl;
            cout << "Digite as duas segundas coordenadas novamente [linha][coluna]: ";
            cin >> linha2 >> coluna2;
        }

        // For para aparecer o valor achado pelas coordenadas.
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                matrizCartaVirada[linha2][coluna2] = matrizGabarito[linha2][coluna2];
                cout << matrizCartaVirada[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;

        // For para atribuir os valores à matriz jogo.
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){

                // Estrutura de seleção para confirmar se os resultados são iguais.
                if(matrizGabarito[linha1][coluna1] == matrizGabarito[linha2][coluna2]){
                    matrizJogo[linha1][coluna1] = matrizGabarito[linha1][coluna1];
                    matrizJogo[linha2][coluna2] = matrizGabarito[linha2][coluna2];
                }
            }
        }

        cout << endl;

        // Estrutura de seleção para exibição do texto do resultado.
        if(matrizGabarito[linha1][coluna1] == matrizGabarito[linha2][coluna2]){
            cout << "ACERTOU!" << endl;
            paresDescobertos++;
        } else {
            cout << "ERROU! TENTE NOVAMENTE!" << endl;
        }

        cout << endl;

        system("PAUSE");
        system("CLS");

        // Mensagens do total de jogadas realizadas e pares descobertos.
        jogadasRealizadas++;
        cout << "Jogadas Realizadas: " << jogadasRealizadas << endl;
        cout << "Pares Descobertos: " << paresDescobertos << endl;

        // Reatribuição dos valores.
        matrizCartaVirada[linha1][coluna1] = matrizJogo[linha1][coluna1];
        matrizCartaVirada[linha2][coluna2] = matrizJogo[linha2][coluna2];

        matrizVerifPosi[linha1][coluna1] = matrizJogo[linha1][coluna1];
        matrizVerifPosi[linha2][coluna2] = matrizJogo[linha2][coluna2];

    } while (jogadasRealizadas < totalJogadas && paresDescobertos < totalPares);

    // Estrutura de seleção para mostar o resultado final.
    if(paresDescobertos == totalPares){
        cout <<
            " _   _  _____  _____  _____  _____ ______ __   __ _         \n"
            "| | | ||_   _|/  __ \\|_   _||  _  || ___ \\\\ \\ / /| |    \n"
            "| | | |  | |  | /  \\/  | |  | | | || |_/ / \\ V / | |      \n"
            "| | | |  | |  | |      | |  | | | ||    /   \\ /  | |       \n"
            "\\ \\_/ / _| |_ | \\__/\\  | |  \\ \\_/ /| |\\ \\   | |  |_|\n"
            " \\___/  \\___/  \\____/  \\_/   \\___/ \\_| \\_|  \\_/  (_)\n"
        << endl;
    }
    else{
        cout <<
            "______  _____ ______  _____   ___   _____     \n"
            "|  _  \\|  ___||  ___||  ___| / _ \\ |_   _|  \n"
            "| | | || |__  | |_   | |__  / /_\\ \\  | |    \n"
            "| | | ||  __| |  _|  |  __| |  _  |  | |      \n"
            "| |/ / | |___ | |    | |___ | | | |  | |      \n"
            "|___/  \\____/ \\_|    \\____/ \\_| |_/  \\_/ \n"
        << endl;
    }

    return 0;

}
