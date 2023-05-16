#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "vozidlo.h"
#define N 1000

void vypisPujcovy(char* jmSoub) {
	FILE* f = fopen(jmSoub, "r");
	if (f == NULL) {
		printf("CHYBA CTENI");
		return 1;
	}
	char buf[N];
	fgets(buf, N, f);
	while (fgets(buf, N, f)) {
		printf("%s\n", buf);
	}
	fclose(f);
}
tVozidlo* nactiPujcovnu(char* pujcovna, int* dim) {
	char* str = strchr(pujcovna, ';');
	int pocet = atoi(str + 1);
	str = strchr(str+1, ';');
	int off = atoi(str+1);
	FILE* f = fopen("data.bin", "rb");
	if (f == NULL) {
		printf("CHYBA CTENI");
		return NULL;
	}
	fseek(f, off, SEEK_SET);
	char buf[N];
	tVozidlo* t = malloc(sizeof(tVozidlo) * pocet);
	int res = fread(t, sizeof(tVozidlo), pocet, f);
	if (res != pocet) {
		printf("CHYBA NACITANI FILU");
		return NULL;
	}
	*dim = pocet;
	fclose(f);
	return t;
}
void vypisVozidla(tVozidlo* pole, int dim) {
	for (int i = 0; i < dim; i++) {
		printf("%s %s %s %5.2f\n", pole[i].model, pole[i].znacka, pole[i].spz, pole[i].spotreba);
	}
}

int compare(void const* a, void const* b) {
	tVozidlo t1 = *(tVozidlo*)a;
	tVozidlo t2 = *(tVozidlo*)b;

	if (t1.spotreba > t2.spotreba) {
		return -1;
	}
	else if (t1.spotreba < t2.spotreba) {
		return 1;
	}
	else {
		return 0;
	}

}

tVozidlo* triMaxSpotreba() {
	FILE* f = fopen("data.bin", "rb");
	if (f == NULL) {
		printf("CHYBA CTENI");
		return NULL;
	}
	char buf[N];
	tVozidlo* v = NULL;
	int i = 0;
	tVozidlo act;
	while (fread(&act, sizeof(tVozidlo), 1, f) == 1) {
		i++;
		v = realloc(v, sizeof(tVozidlo) * (i + 1));
		v[i - 1] = act;
	}
	qsort(v, i, sizeof(tVozidlo), compare);
	tVozidlo* pol = malloc(sizeof(tVozidlo) * 3);
	if (pol == NULL) {
		free(v);
		printf("CHYBA");
		return 1;
	}
	for (int j = 0; j < 3; j++) {
		pol[j] = v[j];
	}
	free(v);
	fclose(f);
	return pol;
}
