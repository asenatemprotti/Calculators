#include <stdio.h> // Asenate de Melo Protti - TRO5V

int main() {
    int num;
    int soma = 0;
    int contador = 0;

    printf("Insira uma sequencia de numeros inteiros positivos. Digite um nnmero negativo para encerrar.\n");

    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &num);

        if (num < 0) {
            break;
        }

        soma += num;
        contador++;
    }

    if (contador > 0) {
        float media = (float) soma / contador;
        printf("A media dos numeros positivos inseridos eh: %.2f\n", media);
    } else {
        printf("Nenhum numero positivo foi inserido.\n");
    }

    return 0;
}
