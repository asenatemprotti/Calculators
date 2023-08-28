#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float volume (float r);

main () {
	
  float r; 
	
	printf ("Digite o valor do raio:");
	scanf ("%f", &r);
	
	volume(r);
	
	printf ("Resultado: %f\n", volume(r));
}

float volume (float r) {
	
	float volume;
	
	volume = (4 * M_PI * pow (r, 3))/3; // formula
	
	return volume;
}
