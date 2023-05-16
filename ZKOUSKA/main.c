#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vozidlo.h"


int main(void) {
	vypisPujcovy("index.csv");
	int dim = 0;
	tVozidlo* t = nactiPujcovnu("pujcovna 1;4;0", &dim);
	vypisVozidla(t, dim);
	tVozidlo* tri = triMaxSpotreba();
	printf("--------------\n");
	for (int i = 0; i < 3;i++) {
		printf("%s %s %s %5.2f\n", tri[i].model, tri[i].znacka, tri[i].spz, tri[i].spotreba);
	}
	return 0;
}