#include <cstdlib>
#include <conio.h>
#include <iostream>

using namespace std;

int pontos, linha=1, coluna=1, portal1l, portal1c, portal2l, portal2c;
bool chave, botao = false;

char mapa1[75][75]{ 

};

char mapa2[75][75]{ 

};

char mapa3[75][75]{ 

};

void montaFase1();
void montaFase2();
int Fase1();
int Fase2();
int trocaFase();

int main(int argc, char *argv[])
{
  int choice;

    do{
    cout << "Main Menu\n";
    cout << "Por favor selecionar\n";
    cout << "1 - Iniciar\n";
    cout << "2 - Controles\n";
    cout<< "3 - Tutorial\n";
    cout << "4 - Sair\n";
    cout << "Selecionar: ";
    cin >> choice;

         switch(choice) {
           case 1:
             cout << "Iniciando fase 1\n";
             trocaFase();
             break;
           case 2:
             cout <<"W: o jogador anda pra cima, A: o jogador vai para esquerda, S: o jogador vai para baixo, D: o jogador vai para a direita\n";
             break;
           case 3:
             cout << "  O jogo e do estilo aventura/puzzle onde o objetivo e o jogador conseguir passar de tres fases. Em cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta fechada. \n";
             break;
           default:
             cout << "Main Menu\n";
             cout << "Por favor selecionar\n";
             cout << "1 - Iniciar\n";
             cout << "2 - Controles\n";
             cout<< "3 - Tutorial\n";
             cout << "4 - Sair\n";
             cout << "Selecionar: ";
             cin >> choice;    
         }
      } while(choice !=4);                            
    system("PAUSE");
    return EXIT_SUCCESS;
}

//construindo o labirinto com os respectivos caracteres e estruturas
void montaFase1(){
	
	int l,c;
	int comp = 25;
	
	for(l=0; l<comp; l++){
		
		for(c=0; c<comp; c++){
			
				//jogador
                if(l==linha and c==coluna){
                
					mapa1[l][c]='&';
                	cout<<mapa1[l][c]<<" ";
				
				}


                //limites do mapa
                else if(l==0 or l==comp-1 or c==0 or c==comp-1){
                	
                    mapa1[l][c]='*';
                    cout<<mapa1[l][c]<<" ";
                }
                
                //botao
                else if(l==8 and c==5){
                	
                	mapa1[l][c]='O';
                    cout<<mapa1[l][c]<<" ";
                	
				}
				
				//teletransporte 1
				else if(l==10 and c==9){
                	
                	portal1l=10;
                    portal1c=9;
                    mapa1[l][c]='>';
                    cout<<mapa1[l][c]<<" ";
                	
				}
				
				//teletransporte 2
				else if(l==10 and c==13){
                	
                	portal2l=10;
                    portal2c=13;
                    mapa1[l][c]='<';
                    cout<<mapa1[l][c]<<" ";
                	
				}
				
				//espinho
				else if(l==3 and c==3 or l==3 and c==10){
					
					mapa1[l][c]='#';
                    cout<<mapa1[l][c]<<" ";
					
				}
				
				//porta aberta
				else if(l==17 and c ==17){
					
					mapa1[l][c]='=';
                    cout<<mapa1[l][c]<<" ";
					
				}
                
                //porta fechada
                else if(l==17 and c ==18){
					
					mapa1[l][c]='D';
                    cout<<mapa1[l][c]<<" ";
					
				}
                
                //vazio
                else{
                	
                    mapa1[l][c]=' ';
                    cout<<mapa1[l][c]<<" ";
                }
       			
					
			}
			
			printf("\n");	
		}
		printf("\n\n");
		
	}

	


//movimentação do jogador
int Fase1(){
	
	int a, i, vida=3;
	int key, saiu = 0;
	
	montaFase1();
	
	
	while(saiu==0){ //para definir que o jogador está dentro do jogo e sairá se saiu != 0
	
		while(vida!=0){
		
			key=getch();
		
			//tecla W (cima)
			if(key=='w' || key=='W'){
			
				linha--; //a linha de mapa[linha][coluna] diminui, para dizer que o jogador está subindo
				if(mapa1[linha][coluna]=='*'){ //para definir que o jogador bateu em uma parede
				
					linha++; //o espaço proíbe a movimentação
				
				}
			
				if(mapa1[linha][coluna]=='D'){ //para definir que o jogador bateu em uma porta fechada
				
					linha++; //o espaço proíbe a movimentação
				
				}
			
				if(mapa1[linha][coluna]=='#'){ //para definir que o jogador bateu em um espinho
				
					linha++; //o espaço proíbe a movimentação
					vida = vida - 1; //uma vida é perdida a cada vez que o jogador bate no espinho
					botao = false; //o botão reseta para false, ou seja, a interação nunca aconteceu
					linha == 1 ; //linha de respawn do jogador
					coluna == 1; //coluna de respawn do jogador
				
				}
			
				if(mapa1[linha][coluna]=='O'){ //para definir que o jogador interagiu com o botão
				
					linha--; //lógica de permissão de movimentação
					botao == true; //lógica de ativação do botão
				
				}
			
				if(mapa1[linha][coluna]=='>'){
				
					linha=portal2l-1; //linha de localização do teletransporte 2
					coluna=portal2c; //coluna de localização do teletransporte 2
				
				}
			
				if(mapa1[linha][coluna]=='<'){
				
					linha=portal1l-1; //linha de localização do teletransporte 1
					coluna=portal1c; //coluna de localização do teletransporte 1
				
				}
			

				if(mapa1[linha][coluna]=='=')saiu++; //saída do jogador
			
			}
		
			//tecla A (esquerda)
			if(key=='a' || key=='A'){
			
				coluna--; //a coluna de mapa[linha][coluna] diminui, para dizer que o jogador está indo a esquerda
				if(mapa1[linha][coluna]=='*'){
				
					coluna++;
				
				}
			
				if(mapa1[linha][coluna]=='D'){
				
					coluna++;
				
				}
			
				if(mapa1[linha][coluna]=='#'){
				
					coluna++;
					vida = vida - 1;
					botao = false;
					linha==1;
					coluna==1;
				
				}
			
				if(mapa1[linha][coluna]=='O'){
				
					coluna--;
					botao == true;
				
				}
			
				if(mapa1[linha][coluna]=='>'){
				
					linha=portal2l;
					coluna=portal2l-1;
				
				}
			
				if(mapa1[linha][coluna]=='<'){
				
					linha=portal1l;
					coluna=portal1c-1;
				
				}
			

				if(mapa1[linha][coluna]=='=')saiu++;
			
			}
		
			//tecla S (baixo)
			if(key=='s' || key=='S'){
			
				linha++;
				if(mapa1[linha][coluna]=='*'){
				
					linha--;
				
				}
			
				if(mapa1[linha][coluna]=='D'){
				
					linha--;
				
				}
			
				if(mapa1[linha][coluna]=='#'){
				
					linha--;
					vida = vida - 1;
					botao = false;
					linha==1;
					coluna==1;
				
				}
			
				if(mapa1[linha][coluna]=='O'){
				
					linha++;
					botao == true;
				
				}
			
				if(mapa1[linha][coluna]=='>'){
				
					linha=portal2l+1;
					coluna=portal2c;
				
				}
			
				if(mapa1[linha][coluna]=='<'){
				
					linha=portal1l+1;
					coluna=portal1c;
				
				}
			

				if(mapa1[linha][coluna]=='=')saiu++;
			
			}
		
			//tecla D (direita)
			if(key=='d' || key=='D'){ //a coluna de mapa[linha][coluna] aumenta, para dizer que o jogador está indo a direita
			
				coluna++;
				if(mapa1[linha][coluna]=='*'){
				
					coluna--;
				
				}
			
				if(mapa1[linha][coluna]=='D'){
				
					coluna--;
				
				}
			
				if(mapa1[linha][coluna]=='#'){
				
					coluna--;
					vida = vida - 1;
					botao = false;
					linha==1;
					coluna==1;
				
				}
			
				if(mapa1[linha][coluna]=='O'){
				
					coluna++;
					botao == true;
				
				}
			
				if(mapa1[linha][coluna]=='>'){
				
					linha=portal2l;
					coluna=portal2l+1;
				
				}
			
				if(mapa1[linha][coluna]=='<'){
				
					linha=portal1l;
					coluna=portal1c+1;
				
				}
			

				if(mapa1[linha][coluna]=='=')saiu++;
		
			}
		
			system("cls");
			montaFase1(); // Mantém o mapa aberto até o jogador sair
			cout << "Estou me movendo: W (cima) | S (baixo) | A (esquerda) | D (direita) \n"; //Debug para identificar o print até aqui
			cout << "VIDAS = " << vida << " \n";
			
		}//término da estrutura repetição while vidas != 0
		
			if (vida > 0){
		
				cout << "Acabou o jogo. Parabéns por concluir o jogo";
				cout <<"O jogo está parando aqui\n" ;
				system("pause");
		
			}
		
			else {
				cout << "Você perdeu, você ficou com " << vida << " vidas restantes \n";
				cout <<"O jogo está parando aqui\n" ;
				system("pause");
				saiu++;
			}
		
	} //término da estrutura repetição While saiu == 0

	
	printf("Fechando o jogo. \n");
	system("pause");
	
}

//construindo o labirinto com os respectivos caracteres e estruturas
void montaFase2(){
	
	int l,c;
	int comp = 50;
	
	for(l=0; l<comp; l++){
		
		for(c=0; c<comp; c++){
			
				//Jogador
                if(l==linha and c==coluna){ 
                
					mapa2[l][c]='&';
                	cout<<mapa2[l][c]<<" ";
				
				}


                //Limites do mapa
                else if(l==0 or l==comp-1 or c==0 or c==comp-1){
                	
                    mapa2[l][c]='*';
                    cout<<mapa2[l][c]<<" ";
                }
                
                //botão
                else if(l==8 and c==5){
                	
                	mapa2[l][c]='O';
                    cout<<mapa2[l][c]<<" ";
                	
				}
				
				//teletransporte 1
				else if(l==10 and c==9){
                	
                	portal1l=10;
                    portal1c=9;
                    mapa2[l][c]='>';
                    cout<<mapa2[l][c]<<" ";
                	
				}
				
				//teletransporte 2
				else if(l==10 and c==13){
                	
                	portal2l=10;
                    portal2c=13;
                    mapa2[l][c]='<';
                    cout<<mapa2[l][c]<<" ";
                	
				}
                
                //espinho
                else if(l==3 and c==3 or l==3 and c==10){
					
					mapa2[l][c]='#';
                    cout<<mapa2[l][c]<<" ";
					
				}
				
				//porta aberta
				else if(l==17 and c ==17){
					
					mapa1[l][c]='=';
                    cout<<mapa1[l][c]<<" ";
					
				}
				
				//porta fechada
				else if(l==17 and c ==18){
					
					mapa2[l][c]='D';
                    cout<<mapa2[l][c]<<" ";
					
				}
				
                //vazio
                else{
                	
                    mapa2[l][c]=' ';
                    cout<<mapa2[l][c]<<" ";
                }
       			
					
			}
			
			printf("\n");	
		}
		printf("\n\n");
		
		
	}

	


//movimentação do jogador
int Fase2(){
	
	int a, i, vida=3;
	int key, saiu = 0;
	
	montaFase1();
	
	
	while(saiu==0){ //para definir que o jogador está dentro do jogo e sairá se saiu != 0
	
		while(vida!=0){
		
			key=getch();
		
			//tecla W (cima)
			if(key=='w' || key=='W'){
			
				linha--; //a linha de mapa[linha][coluna] diminui, para dizer que o jogador está subindo
				if(mapa2[linha][coluna]=='*'){ //para definir que o jogador bateu em uma parede
				
					linha++; //o espaço proíbe a movimentação
				
				}
			
				if(mapa2[linha][coluna]=='D'){ //para definir que o jogador bateu em uma porta fechada
				
					linha++; //o espaço proíbe a movimentação
				
				}
			
				if(mapa2[linha][coluna]=='#'){ //para definir que o jogador bateu em um espinho
				
					linha++; //o espaço proíbe a movimentação
					vida = vida - 1; //uma vida é perdida a cada vez que o jogador bate no espinho
					botao = false; //o botão reseta para false, ou seja, a interação nunca aconteceu
					linha == 1; //linha de respawn do jogador
					coluna==1; //coluna de respawn do jogador
				
				}
			
				if(mapa2[linha][coluna]=='O'){ //para definir que o jogador interagiu com o botão
				
					linha--; //lógica de permissão de movimentação
					botao == true; //lógica de ativação do botão
				
				}
			
				if(mapa2[linha][coluna]=='>'){
				
					linha=portal2l-1; //linha de localização do teletransporte 2
					coluna=portal2c; //coluna de localização do teletransporte 2
				
				}
			
				if(mapa2[linha][coluna]=='<'){
				
					linha=portal1l-1; //linha de localização do teletransporte 1
					coluna=portal1c; //coluna de localização do teletransporte 1
				
				}
			

				if(mapa1[linha][coluna]=='=')saiu++; //saída do jogador
			
			}
		
			//tecla A (esquerda)
			if(key=='a' || key=='A'){
			
				coluna--; //a coluna de mapa[linha][coluna] diminui, para dizer que o jogador está indo a esquerda
				if(mapa2[linha][coluna]=='*'){
				
					coluna++;
				
				}
			
				if(mapa2[linha][coluna]=='D'){
				
					coluna++;
				
				}
			
				if(mapa2[linha][coluna]=='#'){
				
					coluna++;
					vida = vida - 1;
					botao = false;
					linha==1;
					coluna==1;
				
				}
			
				if(mapa2[linha][coluna]=='O'){
				
					coluna--;
					botao == true;
				
				}
			
				if(mapa2[linha][coluna]=='>'){
				
					linha=portal2l;
					coluna=portal2l-1;
				
				}
			
				if(mapa2[linha][coluna]=='<'){
				
					linha=portal1l;
					coluna=portal1c-1;
				
				}
			

				if(mapa2[linha][coluna]=='=')saiu++;
			
			}
		
			//tecla S (baixo)
			if(key=='s' || key=='S'){
			
				linha++;
				if(mapa2[linha][coluna]=='*'){
				
					linha--;
				
				}
			
				if(mapa2[linha][coluna]=='D'){
				
					linha--;
				
				}
			
				if(mapa2[linha][coluna]=='#'){
				
					linha--;
					vida = vida - 1;
					botao = false;
					linha==1;
					coluna==1;
				
				}
			
				if(mapa2[linha][coluna]=='O'){
				
					linha++;
					botao == true;
				
				}
			
				if(mapa2[linha][coluna]=='>'){
				
					linha=portal2l+1;
					coluna=portal2c;
				
				}
			
				if(mapa2[linha][coluna]=='<'){
				
					linha=portal1l+1;
					coluna=portal1c;
				
				}
			

				if(mapa2[linha][coluna]=='=')saiu++;
			
			}
		
			//tecla D (direita)
			if(key=='d' || key=='D'){ //a coluna de mapa[linha][coluna] aumenta, para dizer que o jogador está indo a direita
			
				coluna++;
				if(mapa2[linha][coluna]=='*'){
				
					coluna--;
				
				}
			
				if(mapa2[linha][coluna]=='D'){
				
					coluna--;
				
				}
			
				if(mapa2[linha][coluna]=='#'){
				
					coluna--;
					vida = vida - 1;
					botao = false;
					linha==1;
					coluna==1;
				
				}
			
				if(mapa2[linha][coluna]=='O'){
				
					coluna++;
					botao == true;
				
				}
			
				if(mapa2[linha][coluna]=='>'){
				
					linha=portal2l;
					coluna=portal2l+1;
				
				}
			
				if(mapa2[linha][coluna]=='<'){
				
					linha=portal1l;
					coluna=portal1c+1;
				
				}
			

				if(mapa2[linha][coluna]=='=')saiu++;
		
			}
		
			system("cls");
			montaFase2(); // Mantém o mapa aberto até o jogador sair
			cout << "Estou me movendo: W (cima) | S (baixo) | A (esquerda) | D (direita) \n"; //Debug para identificar o print até aqui
			cout << "VIDAS = " << vida << " \n";
			
		}//término da estrutura repetição while vidas != 0
		
			if (vida > 0){
		
				cout << "Acabou o jogo. Parabéns por concluir o jogo";
				cout <<"O jogo está parando aqui\n" ;
				system("pause");
		
			}
		
			else {
				cout << "Você perdeu, você ficou com " << vida << " vidas restantes \n";
				cout <<"O jogo está parando aqui\n" ;
				system("pause");
				saiu++;
			}
		
	} //término da estrutura repetição While saiu == 0

	
	printf("Fechando o jogo. \n");
	system("pause");
	
}

//construindo o labirinto com os respectivos caracteres e estruturas
void montaFase3(){
	
	int l,c;
	int comp = 75;
	
	for(l=0; l<comp; l++){
		
		for(c=0; c<comp; c++){
			
				//Jogador
                if(l==linha and c==coluna){ 
                
					mapa3[l][c]='&';
                	cout<<mapa1[l][c]<<" ";
				
				}


                //limites do mapa
                else if(l==0 or l==comp-1 or c==0 or c==comp-1){
                	
                    mapa3[l][c]='*';
                    cout<<mapa1[l][c]<<" ";
                }
                
                //botao
                else if(l==8 and c==5){
                	
                	mapa3[l][c]='O';
                    cout<<mapa3[l][c]<<" ";
                	
				}
				
				//teletransporte 1
				else if(l==10 and c==9){
                	
                	portal1l=10;
                    portal1c=9;
                    mapa3[l][c]='>';
                    cout<<mapa3[l][c]<<" ";
                	
				}
				
				//teletransporte 2
				else if(l==10 and c==13){
                	
                	portal2l=10;
                    portal2c=13;
                    mapa3[l][c]='<';
                    cout<<mapa3[l][c]<<" ";
                	
				}
				
				//espinho
				else if(l==3 and c==3 or l==3 and c==10){
					
					mapa3[l][c]='#';
                    cout<<mapa3[l][c]<<" ";
					
				}
				
				//porta aberta
				else if(l==17 and c ==17){
					
					mapa3[l][c]='=';
                    cout<<mapa3[l][c]<<" ";
					
				}
                
                //porta fechada
                else if(l==17 and c ==18){
					
					mapa3[l][c]='D';
                    cout<<mapa3[l][c]<<" ";
					
				}
                
                //vazio
                else{
                	
                    mapa3[l][c]=' ';
                    cout<<mapa3[l][c]<<" ";
                }
       			
					
			}
			
			printf("\n");	
		}
		printf("\n\n");
		
	}

	


//movimentação do jogador
int Fase3(){
	
	int a, i, vida=3;
	int key, saiu = 0;
	
	montaFase3();
	
	
	while(saiu==0){ //para definir que o jogador está dentro do jogo e sairá se saiu != 0
	
		while(vida!=0){
		
			key=getch();
		
			//tecla W (cima)
			if(key=='w' || key=='W'){
			
				linha--; //a linha de mapa[linha][coluna] diminui, para dizer que o jogador está subindo
				if(mapa3[linha][coluna]=='*'){ //para definir que o jogador bateu em uma parede
				
					linha++; //o espaço proíbe a movimentação
				
				}
			
				if(mapa3[linha][coluna]=='D'){ //para definir que o jogador bateu em uma porta fechada
				
					linha++; //o espaço proíbe a movimentação
				
				}
			
				if(mapa3[linha][coluna]=='#'){ //para definir que o jogador bateu em um espinho
				
					linha++; //o espaço proíbe a movimentação
					vida = vida - 1; //uma vida é perdida a cada vez que o jogador bate no espinho
					botao = false; //o botão reseta para false, ou seja, a interação nunca aconteceu
					linha ==1; //linha de respawn do jogador
					coluna==1; //coluna de respawn do jogador
				
				}
			
				if(mapa3[linha][coluna]=='O'){ //para definir que o jogador interagiu com o botão
				
					linha--; //lógica de permissão de movimentação
					botao == true; //lógica de ativação do botão
				
				}
			
				if(mapa3[linha][coluna]=='>'){
				
					linha=portal2l-1; //linha de localização do teletransporte 2
					coluna=portal2c; //coluna de localização do teletransporte 2
				
				}
			
				if(mapa3[linha][coluna]=='<'){
				
					linha=portal1l-1; //linha de localização do teletransporte 1
					coluna=portal1c; //coluna de localização do teletransporte 1
				
				}
			

				if(mapa3[linha][coluna]=='=')saiu++; //saída do jogador
			
			}
		
			//tecla A (esquerda)
			if(key=='a' || key=='A'){
			
				coluna--; //a coluna de mapa[linha][coluna] diminui, para dizer que o jogador está indo a esquerda
				if(mapa3[linha][coluna]=='*'){
				
					coluna++;
				
				}
			
				if(mapa3[linha][coluna]=='D'){
				
					coluna++;
				
				}
			
				if(mapa3[linha][coluna]=='#'){
				
					coluna++;
					vida = vida - 1;
					botao = false;
					linha==1;
					coluna==1;
				
				}
			
				if(mapa3[linha][coluna]=='O'){
				
					coluna--;
					botao == true;
				
				}
			
				if(mapa3[linha][coluna]=='>'){
				
					linha=portal2l;
					coluna=portal2l-1;
				
				}
			
				if(mapa3[linha][coluna]=='<'){
				
					linha=portal1l;
					coluna=portal1c-1;
				
				}
			

				if(mapa3[linha][coluna]=='=')saiu++;
			
			}
		
			//tecla S (baixo)
			if(key=='s' || key=='S'){
			
				linha++;
				if(mapa3[linha][coluna]=='*'){
				
					linha--;
				
				}
			
				if(mapa3[linha][coluna]=='D'){
				
					linha--;
				
				}
			
				if(mapa3[linha][coluna]=='#'){
				
					linha--;
					vida = vida - 1;
					botao = false;
					linha==1;
					coluna==1;
				
				}
			
				if(mapa3[linha][coluna]=='O'){
				
					linha++;
					botao == true;
				
				}
			
				if(mapa3[linha][coluna]=='>'){
				
					linha=portal2l+1;
					coluna=portal2c;
				
				}
			
				if(mapa3[linha][coluna]=='<'){
				
					linha=portal1l+1;
					coluna=portal1c;
				
				}
			

				if(mapa3[linha][coluna]=='=')saiu++;
			
			}
		
			//tecla D (direita)
			if(key=='d' || key=='D'){ //a coluna de mapa[linha][coluna] aumenta, para dizer que o jogador está indo a direita
			
				coluna++;
				if(mapa3[linha][coluna]=='*'){
				
					coluna--;
				
				}
			
				if(mapa3[linha][coluna]=='D'){
				
					coluna--;
				
				}
			
				if(mapa3[linha][coluna]=='#'){
				
					coluna--;
					vida = vida - 1;
					botao = false;
					linha==1;
					coluna==1;
				
				}
			
				if(mapa3[linha][coluna]=='O'){
				
					coluna++;
					botao == true;
				
				}
			
				if(mapa3[linha][coluna]=='>'){
				
					linha=portal2l;
					coluna=portal2l+1;
				
				}
			
				if(mapa3[linha][coluna]=='<'){
				
					linha=portal1l;
					coluna=portal1c+1;
				
				}
			

				if(mapa3[linha][coluna]=='=')saiu++;
		
			}
		
			system("cls");
			montaFase1(); // Mantém o mapa aberto até o jogador sair
			cout << "Estou me movendo: W (cima) | S (baixo) | A (esquerda) | D (direita) \n"; //Debug para identificar o print até aqui
			cout << "VIDAS = " << vida << " \n";
			
		}//término da estrutura repetição while vidas != 0
		
			if (vida > 0){
		
				cout << "Acabou o jogo. Parabéns por concluir o jogo";
				cout <<"O jogo está parando aqui\n" ;
				system("pause");
		
			}
		
			else {
				cout << "Você perdeu, você ficou com " << vida << " vidas restantes \n";
				cout <<"O jogo está parando aqui\n" ;
				system("pause");
				saiu++;
			}
		
	} //término da estrutura repetição While saiu == 0

	
	printf("Fechando o jogo. \n");
	system("pause");
	
}


int trocaFase(){
	
	Fase1();
	system("cls");
	printf("Acabou a fase 1. Entrando na fase 2.");
	system("pause");
	Fase2();
	system("cls");
	printf("Acabou a fase 2. Entrando na fase 3.");
	system("pause");
	Fase3();
	system("cls");
	printf("Acabou o jogo.");
	
	system("pause");

}

