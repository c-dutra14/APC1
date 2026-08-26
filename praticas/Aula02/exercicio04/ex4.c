#include <stdio.h>

#define PI 3.14159
const float gravidade = 9.8;
float raio = 2.0;

int main (){
    float area = PI * raio * raio;
    printf("area do circulo: %.2f\n",area);

    //#const e define criam constantes de formas diferentes

    return 0;
}