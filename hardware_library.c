#include "hardware_library.h"

int R(int registrador,int index, int size){
	FILE *arquivo = fopen(FILE_PATH, "rb");
	registrador = registrador * 2;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

	fseek(arquivo, registrador, SEEK_SET);

	unsigned short conteudo;
	fread(&conteudo, sizeof(unsigned short), 1, arquivo);

	int resultado = 0;

	for (int i = index; i < size + index; i++){
		resultado |= ((conteudo & (1<<i))>>index);
	}

    fclose(arquivo);

	return resultado;
}

void W(int registrador,int index, int conteudo, int size){
	FILE *arquivo = fopen(FILE_PATH, "rb+");
	registrador = registrador * 2;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

	fseek(arquivo, registrador, SEEK_SET);

	unsigned short resultado;
	
	fread(&resultado, sizeof(unsigned short),1, arquivo);

	unsigned short aux = resultado;


	
	//Arruma parte principal
	resultado &= conteudo << index;
	resultado |= conteudo << index;

	//Parte Baixa
	int aux1 = 0;
	for (int i = 0; i < index; i++){
		aux1 += (1<<i);
	}
	resultado |= aux & aux1;

	// Parte Alta
	aux = ((aux >> (index + size))<<(index + size));	
	resultado |= aux;

	//unsigned short teste = 4639;


	fseek(arquivo, registrador, SEEK_SET);
	fwrite(&resultado, sizeof(unsigned short), 1, arquivo);

    fclose(arquivo);
}

void changeString(char *c){
	FILE *arquivo = fopen("registers.bin", "rb+");
	
	fseek(arquivo, 8 , SEEK_SET);
	fwrite(c,sizeof(char),24,arquivo);

	fclose(arquivo);
}