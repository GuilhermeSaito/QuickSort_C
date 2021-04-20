#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Imprimir (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  } 
  printf ("\n");
}

void swap (int* vec, int i, int j)
{
	int temp = vec[i];
	vec[i] = vec[j];
	vec [j] = temp;
}

int Intercala (int* vec, int l, int r)
{
	int pivot = vec[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
		if (vec[j] <= pivot)
		{
			i++;
			swap (vec, i, j);
		}
	swap (vec, i + 1, r);
	return  i + 1;
}

int QuickFind (int *vetor, int esq, int dir, int k) {
  	if (dir >= esq)
	{
		int p = Intercala (vetor, esq, dir);
		if (p == k)
			return vetor[p];
		else if (p > k)
			QuickFind (vetor, esq, p - 1, k);
		else
			QuickFind (vetor, p + 1, dir, k);
	}
}

/*Função principal.*/
int main (int argc, char *argv[]) {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int i;
   
   //int tamanho = 10;
   //int *vetor = (int *)malloc(tamanho * sizeof(int));
   //for (i = 0; i < tamanho; i++) {
   //   vetor[i] = rand() % (tamanho+1);
   //}
   
   int tamanho = 8;
   int vetor[] = {7, 1, 3, 10, 17, 2, 21, 9};
  	// 7, 1, 3, 2	, 9	, 10, 21, 17
	// 1, 2		, 3, 7
	// 		

   Imprimir (vetor, tamanho);
   start = clock();
   int pos = 4;
   printf("O elemento procurado na posição %d é %d\n", pos, QuickFind(vetor, 0, tamanho-1, pos));
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   //free (vetor);
   return 0;
}
