#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (vetor[i] > vetor[i+1]) {
       return 0;
    }
  }
  return 1;
}

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
	vec[j] = temp;
}

int Particione (int* vec, int l, int r)
{
	int pivot = vec[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
		if (vec[j] <= pivot)
		{
			i++;
			swap (vec, i, j);
		}
	// Colocando o pivo entre os menores (a esquerda dele) e os maiores (a direita), essa separacao foi feita no for de cima.
	swap (vec, i + 1, r);
	return i + 1;
}

int Particione2 (int* vec, int l, int r)
{                                        
	int pivotPos = (rand() % (r - l)) + l;
	swap (vec, pivotPos, r);      
                                         	
	int pivot = vec[r];              	
	int i = l - 1;                   	
	for (int j = l; j < r; j++)      
		if (vec[j] <= pivot)     
		{                     
			i++;       
			swap (vec, i, j);
		}
	swap (vec, i + 1, r);
	return i + 1;                  
}

void QuickSort (int* vec, int l, int r)
{
	if (r > l)
	{
		int p = Particione (vec, l, r);
		QuickSort (vec, l, p - 1);
		QuickSort (vec, p + 1, r);
	}
}

void QuickSort2 (int* vec, int l, int r)
{
	if (r > l)
	{
		int p = Particione (vec, l, r);
		QuickSort2 (vec, l, p - 1);
		QuickSort2 (vec, p + 1, r);
	}
}

/*Função principal.*/
int main (int argc, char *argv[]) {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int i;
   int tamanho = 10000000;
   int *vetor = (int *)malloc(tamanho * sizeof(int));
   int *vetor2 = (int *)malloc(sizeof(int) * tamanho);
   for (i = 0; i < tamanho; i++) {
      vetor[i] = rand() % (tamanho+1);
      vetor2[i] = rand() % (tamanho + 1);
   }
   //Imprimir (vetor, tamanho);
   start = clock();
   QuickSort (vetor, 0, tamanho-1);
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Tempo de execução (Quick-Sort): %lf\n", elapsed_time);
   if (!Verifica_Ordenacao(vetor, tamanho)) {
      printf("Erro: a ordenação não está correta!\n");
   }
   //Imprimir (vetor, tamanho);
   
   start = clock();
   QuickSort2 (vetor2, 0, tamanho - 1);
   end = clock();
   elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
   printf("\n\nQuickSort2: %lf\n", elapsed_time);
   
   free (vetor);
   free (vetor2);

   return 0;
}
