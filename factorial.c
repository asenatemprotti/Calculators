#include <stdio.h> // Asenate de Melo Protti - TRO5V

int main() {
    int numero, fatorial = 1;

    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("O numero digitado eh negativo. Por favor, tente novamente.\n");
        return 0;
    }

    for (int i = 1; i <= numero; i++) {
        fatorial *= i;
    }

    printf("O fatorial de %d eh %d\n", numero, fatorial);

    return 0;
}
