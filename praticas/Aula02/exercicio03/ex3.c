#include <stdio.h>
int contador = 10;//variavel global

int main(){
    int contador = 5;//variavel local

    printf("valorde contador dentro de main:%d\n",contador);
    return 0;
}