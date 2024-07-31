// kpnsk
#include<stdio.h>
#include<stdlib.h>

#define PROPERTIES 2 

int max(int a, int b){
  return (a > b) ? a : b;
}

int knapsack(int** items, int maxWeight, int n){
  int** table = (int **) malloc((n+1)*sizeof(int *));
  for(int i=0;i<=n;++i) table[i] = (int *) malloc((maxWeight+1)*sizeof(int));

  for(int i=0;i<=n;++i){
    for(int w=0;w<=maxWeight;++w){
      if(i == 0 || w == 0) table[i][w] = 0;
      else if (items[i-1][0] <= w) table[i][w] = max((items[i-1][1] + table[i-1][w-items[i-1][0]]), table[i-1][w]);
      else table[i][w] = table[i-1][w];
    }
  }

  int maxValue = table[n][maxWeight];
  
	for(int i=0;i<=n;++i) free(table[i]);
  free(table); 

  return maxValue;
}

void output(int solutionValue, int solutionWeight, int optimal, int maxWeight){
  if(solutionWeight > maxWeight) printf("Solucao inviavel.\n");
  else if(solutionValue == optimal) printf("Solucao otima.\n");
  else printf("Solucao viavel mas nao otima.\n");
}

int main(int argc, char* argv[]){
	int maxWeight = 0, n;
	scanf("%d %d", &maxWeight, &n);

	int** items = (int **) malloc(n*sizeof(int *));
	for(int i=0;i<n;++i) items[i] = (int *) malloc(PROPERTIES*sizeof(int));

	for(int i=0;i<n;++i) scanf("%d %d", &items[i][0], &items[i][1]);
 
  int solutionValue = 0, solutionWeight = 0, binary;
	for(int i=0;i<n;++i) {
    scanf("%d", &binary);
    if(binary) {
      solutionWeight += items[i][0];
      solutionValue += items[i][1];
    }
  }
  
  output(solutionValue, solutionWeight, knapsack(items, maxWeight, n), maxWeight);

	for(int i=0;i<n;++i) free(items[i]);
	free(items);

	return 0;
}
