#pragma once

typedef struct vozidlo {
	char znacka[20];
	char model[20];
	char spz[20];
	float spotreba;
}tVozidlo;

void vypisPujcovy(char* jmSoub);
tVozidlo* nactiPujcovnu(char* pujcovna, int* dim);
void vypisVozidla(tVozidlo* pole, int dim);
tVozidlo* triMaxSpotreba();