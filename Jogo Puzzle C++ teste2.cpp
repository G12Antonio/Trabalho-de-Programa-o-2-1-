#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define v 0 //definir o número 0 por "vazio"
#define p 1 //definir o número 1 por "parede"
#define s 2 //definir o número 2 por "saida"

int pontos, linha=1, coluna=1;
//linha = 1 e coluna = 1 significa que o jogador irá dar SPAWN nesta coordenada dentro do mapa ([11, 11] dentro das coordenadas de 0 a 24). Sempre mudar as coords quando quiser mudar o spawn

// criando uma matriz 25x25 para fazer o labirinto
int mapa[10][10]{ 

	1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,1,1,2,1,1,1,1,1,1,
};

//construindo o labirinto com os respectivos caracteres e estruturas
void montaFase(){
	
	int l,c;
	
	for(l=0; l<10; l++){
		
		for(c=0; c<10; c++){
			
			if(l==linha && c==coluna) printf("&"); //caracter que identifica o jogador e faz ele ser colocado em qualquer vetor da matriz (auxilia na parte de movimentação do jogador)
			else{
				if(mapa[l][c]==v) printf(" "); //caracter definindo vazio, logo, espaço livre para se movimentar
				if(mapa[l][c]==s) printf("="); //caracter definindo saída, logo, espaço exclusivo para sair e terminar o jogo
				if(mapa[l][c]==p) printf("*"); //caracter definindo parede, logo, espaço proibído para se movimentar
				
				
			}
			
		}
		printf("\n");
		
	}
	printf("\n\n");
	
}

int mapa2[10][10]{ 

	1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,1,1,2,1,1,1,1,1,1,
	
};

//construindo o labirinto com os respectivos caracteres e estruturas
void montaFase2(){
	
	int l,c;
	
	for(l=0; l<10; l++){
		
		for(c=0; c<10; c++){
			
			if(l==linha && c==coluna) printf("&"); //caracter que identifica o jogador e faz ele ser colocado em qualquer vetor da matriz (auxilia na parte de movimentação do jogador)
			else{
				if(mapa2[l][c]==v) printf(" "); //caracter definindo vazio, logo, espaço livre para se movimentar
				if(mapa2[l][c]==s) printf("="); //caracter definindo saída, logo, espaço exclusivo para sair e terminar o jogo
				if(mapa2[l][c]==p) printf("*"); //caracter definindo parede, logo, espaço proibído para se movimentar
				
				
			}
			
		}
		printf("\n");
		
	}
	printf("\n\n");
	
}


int mapa3[10][10]{ 

	1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,
	1,1,1,2,1,1,1,1,1,1,
	
};


//construindo o labirinto com os respectivos caracteres e estruturas
void montaFase3(){
	
	int l,c;
	
	for(l=0; l<10; l++){
		
		for(c=0; c<10; c++){
			
			if(l==linha && c==coluna) printf("&"); //caracter que identifica o jogador e faz ele ser colocado em qualquer vetor da matriz (auxilia na parte de movimentação do jogador)
			else{
				if(mapa3[l][c]==v) printf(" "); //caracter definindo vazio, logo, espaço livre para se movimentar
				if(mapa3[l][c]==s) printf("="); //caracter definindo saída, logo, espaço exclusivo para sair e terminar o jogo
				if(mapa3[l][c]==p) printf("*"); //caracter definindo parede, logo, espaço proibído para se movimentar
				
				
			}
			
		}
		printf("\n");
		
	}
	printf("\n\n");
	
}

//movimentação do jogador
int Fase1(){
	
	int a, i;
	int key, saiu = 0;
	
	montaFase();
	while(saiu==0){ //para definir que o jogador saiu dentro do jogo
		
		key=getch();
		
		//tecla W (cima)
		if(key=='w' || key=='W'){
			
			linha--;
			if(mapa[linha][coluna]==p) linha++;
			if(mapa[linha][coluna]==s)saiu++;
		}
		
		//tecla A (esquerda)
		if(key=='a' || key=='A'){
			
			coluna--;
			if(mapa[linha][coluna]==p) coluna++;
			if(mapa[linha][coluna]==s) saiu++;
		}
		
		//tecla S (baixo)
		if(key=='s' || key=='S'){
			
			linha++;
			if(mapa[linha][coluna]==p) linha--;
			if(mapa[linha][coluna]==s) saiu++;
		}
		
		//tecla D (direita)
		if(key=='d' || key=='D'){
			
			coluna++;
			if(mapa[linha][coluna]==p) coluna--;
			if(mapa[linha][coluna]==s) saiu++;
		}
		
		system("cls");
		montaFase(); // Mantém o mapa aberto até o jogador sair
		
	} //término da estrutura repetição While
	
	printf("Acabou. \n");
	system("pause");
	
}

//movimentação do jogador
int Fase2(){
	
	int a, i;
	int key, saiu = 0;
	
	montaFase2();
	while(saiu==0){ //para definir que o jogador saiu dentro do jogo
		
		key=getch();
		
		//tecla W (cima)
		if(key=='w' || key=='W'){
			
			linha--;
			if(mapa2[linha][coluna]==p) linha++;
			if(mapa2[linha][coluna]==s)saiu++;
		}
		
		//tecla A (esquerda)
		if(key=='a' || key=='A'){
			
			coluna--;
			if(mapa2[linha][coluna]==p) coluna++;
			if(mapa2[linha][coluna]==s) saiu++;
		}
		
		//tecla S (baixo)
		if(key=='s' || key=='S'){
			
			linha++;
			if(mapa2[linha][coluna]==p) linha--;
			if(mapa2[linha][coluna]==s) saiu++;
		}
		
		//tecla D (direita)
		if(key=='d' || key=='D'){
			
			coluna++;
			if(mapa2[linha][coluna]==p) coluna--;
			if(mapa2[linha][coluna]==s) saiu++;
		}
		
		system("cls");
		montaFase2(); // Mantém o mapa aberto até o jogador sair
		
	} //término da estrutura repetição While
	
	printf("Acabou. \n");
	system("pause");
	
}

int Fase3(){
	
	int a, i;
	int key, saiu = 0;
	
	montaFase3();
	while(saiu==0){ //para definir que o jogador saiu dentro do jogo
		
		key=getch();
		
		//tecla W (cima)
		if(key=='w' || key=='W'){
			
			linha--;
			if(mapa3[linha][coluna]==p) linha++;
			if(mapa3[linha][coluna]==s)saiu++;
		}
		
		//tecla A (esquerda)
		if(key=='a' || key=='A'){
			
			coluna--;
			if(mapa3[linha][coluna]==p) coluna++;
			if(mapa3[linha][coluna]==s) saiu++;
		}
		
		//tecla S (baixo)
		if(key=='s' || key=='S'){
			
			linha++;
			if(mapa3[linha][coluna]==p) linha--;
			if(mapa3[linha][coluna]==s) saiu++;
		}
		
		//tecla D (direita)
		if(key=='d' || key=='D'){
			
			coluna++;
			if(mapa3[linha][coluna]==p) coluna--;
			if(mapa3[linha][coluna]==s) saiu++;
		}
		
		system("cls");
		montaFase3(); // Mantém o mapa aberto até o jogador sair
		
	} //término da estrutura repetição While
	
	printf("Acabou. \n");
	system("pause");
	
}


int main(){
	
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




