#include <iostream>
#include <unistd.h> // Biblioteca para dormir.
#include <cstdlib> // Fun��o para system. Neste caso � usado para limpar terminal.

using namespace std;
char matrjogador1 [10][10] = {}; //Matriz jogador 1
char matrjogador2 [10][10] = {}; //Matriz jogador 2
int barcosJogador1[10][10] = {}; // Matriz para rastrear barcos do jogador 1
int barcosJogador2[10][10] = {}; // Matriz para rastrear barcos do jogador 2

void coordtabuleiro(){
cout << "  0 1 2 3 4 5 6 7 8 9 " << endl;
}
void esperarEnter() {
    cout << "Pressione Enter para continuar...";
    cin.ignore();
    cin.get();
}


void inicializarTabuleiros() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrjogador1[i][j] = 'A'; // A para representar �gua
            matrjogador2[i][j] = 'A'; // A para representar �gua
        }
    }
}

void imprimirmatriz1(){
    for(int i = 0; i<10; i++){
            cout << i <<" ";
        for(int j = 0; j<10; j++){
            cout << matrjogador1[i][j] << " ";
        }
        cout << endl;
    }
}


bool atirar(char matr[][10], int linha, int coluna, int barcos[][10]) {
    while (linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10 || matr[linha][coluna] == 'X' || matr[linha][coluna] == ' '){
        if (linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10){
            cout << "Coordenadas invalidas, tente novamente." << endl;
        } else {
        cout << "Impossivel atirar nessas coordenadas, tente novamente." << endl;
        }
        cout << "Digite novas coordenadas (linha e coluna de 0 a 9): " << endl;
        cin >> linha >> coluna;
    }

    if (matr[linha][coluna] == 'X' || matr[linha][coluna] == ' '){
        cout << "Impossivel atirar nessa coordenada, tente novamente!" <<endl;
        return false;
    }

    else if (matr[linha][coluna] == 'B') {
        int barcoAtingido = barcos[linha][coluna];
        if (barcoAtingido >= 1) {
            //cout << "Voc� acertou um barco de tamanho " << barcoAtingido << "!" << endl;
            matr[linha][coluna] = 'X'; // 'X' representa um acerto no barco
                return true; // Retorna true se o tiro acertou
        }
    } else {
        matr[linha][coluna] = ' '; // ' ' representa �gua
        return false; // Retorna false se o tiro n�o acertou
    }
}

void adicionarBarco1(char matr[][10], bool opcoesEscolhidasJogador1[], int tamanhoBarco1) {
    int linha = 0, coluna = 0;
    string posicao;
 bool posicaovh = false; // Inicializa como falso para entrar no loop

    do {
    while (!posicaovh){ // Vai continuar pedindo a posi��o caso ela n�o seja true.
        cout << "Qual � a posi��o do barco (Vertical(V),Horizontal(H))?" << endl;
        cin >> posicao;
    if (posicao == "V" || posicao == "v" || posicao == "vertical" || posicao == "Vertical" || posicao == "VERTICAL" || posicao == "H" || posicao == "h" || posicao == "horizontal" || posicao == "Horizontal" || posicao == "HORIZONTAL") {
        posicaovh = true; // Define como verdadeiro se a posi��o for v�lida.
    } else {
        //Vai sempre retornar como falso e n�o vai sair do loop.
        cout << "Posi��o inv�lida, tente novamente." << endl;
    }
}
        cout << "Qual � a linha que voc� deseja adicionar o barco?" << endl;
        cin >> linha;

        cout << "Qual � a coluna que voc� deseja adicionar o barco?" << endl;
        cin >> coluna;

        // Verifica se as linhas/colunas est�o dentro da matriz
        if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {

            bool posicaoValida = true;

            if ((posicao == "V" || posicao == "v" || posicao == "vertical" || posicao == "Vertical" || posicao == "VERTICAL") && (linha + tamanhoBarco1 <= 10)) {
            // Verifica se a posi��o est� ocupada (Linha)
            for (int i = linha; i < linha + tamanhoBarco1; i++) {
                if (i >= 10 || matr[i][coluna] != 'A') {
                    posicaoValida = false;
                    break;
                }
            }

            // Adiciona o barco se a posi��o for v�lida
            if (posicaoValida) {
                for (int i = linha; i < linha + tamanhoBarco1; i++) {
                    matr[i][coluna] = 'B'; // 'B' representa o barco
                }
            } else if (linha + tamanhoBarco1 > 10) { // Se ultrapassar os limites, adicione na dire��o oposta
                for (int i = linha; i >= linha - tamanhoBarco1; i--) {
                    if (i >= 0) { // Verifica se i � um �ndice v�lido para a matriz
                        matr[i][coluna] = 'B'; // 'B' representa o barco na dire��o oposta
                    }
                }
            } else {
                cout << "Imposs�vel adicionar o barco nessa posi��o, tente novamente." << endl;
                posicaoValida = false; //Retorna posi��o valida a falso, ou seja, pecorrer� o c�digo at� que seja colocado uma popsi��o valida.
            }

            }else if ((posicao == "H" || posicao == "h" || posicao == "horizontal" || posicao == "Horizontal" || posicao == "HORIZONTAL") && (coluna + tamanhoBarco1 <= 10)) {
            // Verifica se a posi��o est� ocupada (Coluna)
            for (int j = coluna; j < coluna + tamanhoBarco1; j++) {
                if (j >= 10 || matr[linha][j] != 'A') {
                    posicaoValida = false;
                    break;
                }
            }

            // Adiciona o barco se a posi��o for v�lida
            if (posicaoValida) {
                for (int j = coluna; j < coluna + tamanhoBarco1; j++) {
                    matr[linha][j] = 'B'; // 'B' representa o barco
                }
            } else if (coluna + tamanhoBarco1 > 10) { // Se ultrapassar os limites, adicione na dire��o oposta
                for (int j = coluna; j >= coluna - tamanhoBarco1; j--) {
                    if (j >= 0) { // Verifica se j � um �ndice v�lido para a matriz
                        matr[linha][j] = 'B'; // 'B' representa o barco na dire��o oposta
                    }
                }
            } else {
                cout << "Imposs�vel adicionar o barco nessa posi��o, tente novamente." << endl;
                posicaoValida = false;
            }
        }else {
                cout << "O barco ultrapassou os limites da matriz!" << endl;
                posicaoValida = false;
            }

        if (posicaoValida) {
            break;
        }
    } else {
        cout << "Coordenadas fora do tabuleiro." << endl;
    }
} while (true);
}

void adicionarBarco2(char matr[][10], bool opcoesEscolhidas[], int tamanhoBarco2) {
int linha2 = 0, coluna2 = 0;
    string posijogador2;

    do {
        cout << "Qual � a posi��o do barco (Vertical(V),Horizontal(H))?" << endl;
        cin >> posijogador2;

        cout << "Qual � a linha que voc� deseja adicionar o barco?" << endl;
        cin >> linha2;

        cout << "Qual � a coluna que voc� deseja adicionar o barco?" << endl;
        cin >> coluna2;

        // Verifica se as linhas/colunas est�o dentro da matriz
        if (linha2 >= 0 && linha2 < 10 && coluna2 >= 0 && coluna2 < 10) {
            bool posicaoValida2 = true;

            if ((posijogador2 == "V" || posijogador2 == "v" || posijogador2 == "vertical" || posijogador2 == "Vertical" || posijogador2 == "VERTICAL") && (linha2 + tamanhoBarco2 <= 10)) {
                // Verifica se a posi��o est� ocupada
                for (int a = linha2; a < linha2 + tamanhoBarco2; a++) {
                    if (matr[a][coluna2] != 'A') {
                        posicaoValida2 = false;
                        break;
                    }
                }

                // Adiciona o barco se a posi��o for v�lida
                if (posicaoValida2) {
                    for (int a = linha2; a < linha2 + tamanhoBarco2; a++) {
                        matr[a][coluna2] = 'B'; // 'B' representa o barco
                    }
                } else {
                    cout << "Imposs�vel adicionar o barco nessa posi��o, tente novamente." << endl;
                    posicaoValida2 = false;
                }
            } else if ((posijogador2 == "H" || posijogador2 == "h" || posijogador2 == "horizontal" || posijogador2 == "Horizontal" || posijogador2 == "HORIZONTAL") && (coluna2 + tamanhoBarco2 <= 10)) {
                // Verifica se a posi��o est� ocupada
                for (int b = coluna2; b < coluna2 + tamanhoBarco2; b++) {
                    if (matr[linha2][b] != 'A') {
                        posicaoValida2 = false;
                        break;
                    }
                }

                // Adiciona o barco se a posi��o for v�lida
                if (posicaoValida2) {
                    for (int b = coluna2; b < coluna2 + tamanhoBarco2; b++) {
                        matr[linha2][b] = 'B'; // 'B' representa o barco
                    }
                } else {
                    cout << "Imposs�vel adicionar o barco nessa posi��o, tente novamente." << endl;
                    posicaoValida2= false;
                }
            } else {
                cout << "O barco ultrapassou os limites da matriz!" << endl;
                posicaoValida2 = false;
            }

            if (posicaoValida2) {
                break;
            }
        } else {
            cout << "Coordenadas fora do tabuleiro." << endl;
        }
    } while (true);

}
void imprimirmatriz2(){
for (int a = 0; a<10; a++){
         cout << a << " ";
    for (int b = 0; b<10; b++){
    cout << matrjogador2[a][b] << " ";

}
cout<<endl;
}
}
// Fun��o limpar terminal
    void limparterminal(){
    system("cls");
    }

int main()
{
    limparterminal();
    cout << "Seja bem-vindo ao Jogo da Batalha Naval. " << endl;
    bool programarodando = true;
    while(programarodando){
        int opcao;

    sleep(2);
    limparterminal();

        cout << R"(
        1- Iniciar jogo
        2- Regras
        3- Sair)" << endl;
        cin >> opcao;

        switch(opcao){  //Switch usado para a executar as op��es abaixo.
    case 1:
        {

        cout << "Nome do jogador 1: " << endl;
        string nomejoga1;
        cin >>nomejoga1;

        cout << "Nome do jogador 2: " << endl;
        string nomejoga2;
        cin >>nomejoga2;

        inicializarTabuleiros(); //Inicializa os valores das matrizes para que seja devolvido o A.
        cout << "Tabuleiro do jogador 1: " << nomejoga1 << endl;
        coordtabuleiro();
        imprimirmatriz1();
        cout << "" << endl;
        cout << "Tabuleiro do jogador 2: " << nomejoga2 << endl;
        coordtabuleiro();
        imprimirmatriz2();
        esperarEnter();
        cout << "" << endl;

                bool vezJogador1 = true;
                bool opcoesEscolhidasJogador1[5] = {false}; //Inicialmente nenhuma op��o foi escolhida
                bool opcoesEscolhidasJogador2[5] = {false}; //Inicialmente nenhuma op��o foi escolhida
                int opcaobarcos2;

                //Fun��o utilizada para os 10 barcos(jogador1/jogador2)
                for(int x = 0; x<10; x++){

                //Condi��o usada para que a atribui��o de barcos seja de maneira alternada pelos jogadores.
                        if(vezJogador1){

                    limparterminal();
                    cout << "Na fase inicial do jogo, cada jogador dever� posicionar os seus barcos na matriz. " << endl;
                    cout << "Os barcos disponiveis s�o de tamanhos: 5,4,3,3,2" << endl;
                    cout << R"(
                            1- Barco de tamanho 2
                            2- Barco de tamanho 3
                            3- Barco de tamanho 3
                            4- Barco de tamanho 4
                            5- Barco de tamanho 5
                            )" <<endl;

                        cout << " JOGADOR 1: " << nomejoga1 << endl;
                        int opcaobarcos;

                        do{
                            cout << "Qual � o tamanho do barco que voc� deseja adicionar ? " << endl;
                            cin >> opcaobarcos;

                            if (opcaobarcos < 1 || opcaobarcos > 5){
                                cout << "Op��o inv�lida. Escolha uma op��o de 1 a 5." << endl;
                            }
                            // Verifica se a op��o j� foi escolhida anteriormente
                            else if (opcoesEscolhidasJogador1[opcaobarcos - 1]) {
                                cout << "Essa op��o j� foi escolhida. Escolha outra op��o." << endl;
                            } else {
                                opcoesEscolhidasJogador1[opcaobarcos - 1] = true; // Marca a op��o como escolhida
                                break; // Sai do loop se a op��o for v�lida
                            }
                        } while(true);


                    // Condi��o para que seja adiconado os barcos na matriz
                    if (opcaobarcos == 1) {
                    adicionarBarco1(matrjogador1, opcoesEscolhidasJogador1, 2);
                     } else if (opcaobarcos == 2){
                    adicionarBarco1(matrjogador1,opcoesEscolhidasJogador1,3);
                    } else if (opcaobarcos == 3){
                    adicionarBarco1(matrjogador1,opcoesEscolhidasJogador1,3);
                    } else if (opcaobarcos == 4){
                    adicionarBarco1(matrjogador1,opcoesEscolhidasJogador1,4);
                    } else if (opcaobarcos == 5){
                    adicionarBarco1(matrjogador1,opcoesEscolhidasJogador1,5);
                    }

                    coordtabuleiro();
                    imprimirmatriz1(); // Vai imprimir a matriz de acordo que seja colocado os barcos.
                    esperarEnter();
                    vezJogador1 = false;


                }else{

                     limparterminal();
                    cout << "Na fase inicial do jogo, cada jogador dever� posicionar os seus barcos na matriz. " << endl;
                    cout << "Os barcos disponiveis s�o de tamanhos: 5,4,3,3,2" << endl;
                    cout << R"(
                            1- Barco de tamanho 2
                            2- Barco de tamanho 3
                            3- Barco de tamanho 3
                            4- Barco de tamanho 4
                            5- Barco de tamanho 5
                            )" <<endl;

                     cout << " JOGADOR 2: " << nomejoga2 << endl;

                    do{
                    cout << "Qual barco voc� deseja adicionar primeiro? " << endl;
                    cin >> opcaobarcos2;

                        if (opcaobarcos2 < 1 || opcaobarcos2 > 5){
                            cout << "Op��o inv�lida. Escolha uma op��o de 1 a 5." << endl;
                            }
                    // Verifica se a op��o j� foi escolhida anteriormente
                            else if (opcoesEscolhidasJogador2[opcaobarcos2 - 1]) {
                                cout << "Essa op��o j� foi escolhida. Escolha outra op��o." << endl;
                            } else {
                                opcoesEscolhidasJogador2[opcaobarcos2 - 1] = true; // Marca a op��o como escolhida
                                break; // Sai do loop se a op��o for v�lida
                            }
                    } while(true);

                    if (opcaobarcos2 == 1) {
                    adicionarBarco2(matrjogador2,opcoesEscolhidasJogador2,2);
                    } else if (opcaobarcos2 == 2){
                    adicionarBarco2(matrjogador2,opcoesEscolhidasJogador2,3);
                    } else if (opcaobarcos2 == 3){
                    adicionarBarco2(matrjogador2,opcoesEscolhidasJogador2,3);
                    } else if (opcaobarcos2 == 4){
                    adicionarBarco2(matrjogador2,opcoesEscolhidasJogador2,4);
                    } else if (opcaobarcos2 == 5){
                    adicionarBarco2(matrjogador2,opcoesEscolhidasJogador2,5);
                    }else {
                        cout << "Coordenadas fora do tabuleiro." << endl;
                    }

                    coordtabuleiro();
                    imprimirmatriz2(); // Vai imprimir a matriz de acordo que seja colocado os barcos.
                    esperarEnter();
                    vezJogador1 = true;
                }
                }

        limparterminal();
        cout <<"Tabuleiro 1: " << nomejoga1 << endl;
        coordtabuleiro();
        imprimirmatriz1(); // Vai imprimir a matriz j� atualizada com as posi��es dos barcos.
        sleep(2);
        esperarEnter();

        limparterminal();
        cout <<"Tabuleiro 2: " << nomejoga2 << endl;
        coordtabuleiro();
        imprimirmatriz2(); // Vai imprimir a matriz j� atualizada com as posi��es dos barcos.
        sleep(2);
        esperarEnter();

        limparterminal();

        //Ciclo usado para os tiros dos jogadores.
        bool fimdoJogo= false;
        while(!fimdoJogo){
        int linhatiro, colunatiro;

        // Verifica de quem � a vez e solicitar coordenadas para o tiro
        if (vezJogador1) {

        cout << "Tabuleiro do Jogador 1:" << endl;
        coordtabuleiro();
        imprimirmatriz1();
        sleep(1);

        cout << "JOGADOR 1 - Onde voc� deseja atirar? (linha coluna): ";
        cin >> linhatiro >> colunatiro;

        // Realiza o tiro no tabuleiro do jogador 2
        bool acertou = atirar(matrjogador2, linhatiro, colunatiro, barcosJogador2);

        if (acertou) {
            cout << "Jogador 1 acertou um barco do Jogador 2!" << endl;
        } else {
            cout << "Jogador 1 errou o tiro." << endl;
        }

        esperarEnter();
        limparterminal();
    } else {
        cout << "Tabuleiro do Jogador 2:" << endl;
        coordtabuleiro();
        imprimirmatriz2();
        sleep(1);

        cout << "JOGADOR 2 - Onde voc� deseja atirar? (linha coluna): ";
        cin >> linhatiro >> colunatiro;

        // Realizar o tiro no tabuleiro do jogador 1
        bool acertou = atirar(matrjogador1, linhatiro, colunatiro, barcosJogador1);

        if (acertou) {
            cout << "Jogador 2 acertou um barco do Jogador 1!" << endl;
        } else {
            cout << "Jogador 2 errou o tiro." << endl;
        }

        esperarEnter();
        limparterminal();
    }

    // Verifica se algum jogador venceu
    bool jogador1perdeu = true;
    bool jogador2perdeu = true;

    for (int i = 0; i<10; i++){
        for (int j = 0; j<10; j++){
            if (matrjogador1[i][j] == 'B'){
                jogador1perdeu = false; //Se for encontrado um barco, retorna False e o jogo continua.
                break;
            }
        }
    }

    for (int a = 0; a<10; a++){
        for (int b = 0; b<10; b++){
            if (matrjogador2[a][b] == 'B'){
                jogador2perdeu = false; //Se for encontrado um barco, retorna False e o jogo continua.
                break;
            }
        }
    }


    // Verifica se algum jogador venceu e encerra o jogo se sim
    if (jogador1perdeu) {
        limparterminal();
        cout << "Jogador 2 venceu. Parab�ns " << nomejoga2 << "!" << endl;
        esperarEnter();
        fimdoJogo = true; // Termina o jogo
    }
    else if (jogador2perdeu) {
        limparterminal();
        cout << "Jogador 1 venceu. Parab�ns " << nomejoga1 << "!" << endl;
        esperarEnter();
        fimdoJogo = true; // Termina o jogo
    }

    // Alterna a vez do pr�ximo jogador para o pr�ximo ciclo
    vezJogador1 = !vezJogador1;

        }
        break;
        }


    case 2:
        {
            //Regras do jogo
           cout << "Regras do jogo: " << endl;
           cout << R"(
PREPARA��O:
1 - Cada jogador possui um tabuleiro (matriz de 10x10).
2 - Barcos s�o colocados nos tabuleiros dos jogadores antes do in�cio do jogo.
3 - Os barcos t�m diferentes tamanhos (2 a 5 de comprimento) e s�o posicionados vertical ou horizontalmente no tabuleiro.
4 - Os jogadores n�o veem o tabuleiro um do outro.)

JOGO:
1 - Os jogadores alternam jogadas para tentar acertar os barcos do oponente atirando em diferentes lugares do tabuleiro.
2 - Cada jogador indica uma coordenada de tiro (linha e coluna) para atacar uma espa�o no tabuleiro do oponente.
3 - Se um tiro atinge um espa�o onde est� localizado um barco do oponente, � um acerto ('X').
4 - Se um tiro n�o atinge nenhum barco, � um tiro na �gua (' ').
5 - Os jogadores marcam os tiros dados no tabuleiro do oponente para acompanhar o progresso.

VENCEDOR:
1 - O jogo termina quando todos os barcos de um jogador forem destru�dos.
2 - O jogador que destruir todos os barcos do oponente primeiro � o vencedor.

OBSERVA��O:
1 - Os barcos n�o podem se sobrepor(lateral ou diagonalmente).
2 - Quando todos os segmentos de um barco forem atingidos ('X'), o barco � afundado.
3 - O primeiro jogador a afundar todos os barcos do oponente vence.")" << endl;

cout << "" << endl;
sleep(2);
esperarEnter();
            break;
        }

    case 3:
        {
            //Sair do jogo
            cout << "Obrigado por ter jogado, espero que tenha gostado." << endl;
            sleep(3);
            programarodando = false;
            break;
        }
        }
    }
    return 0;
}
