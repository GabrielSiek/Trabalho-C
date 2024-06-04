#ifndef _HARDWARE_LIBRARY_H
#define _HARDWARE_LIBRARY_H

#include <stdio.h>

#define FILE_PATH "registers.bin"

int R(int registrador,int index, int size);
void W(int registrador,int index, int conteudo, int size);
void changeString(char *c);

#endif