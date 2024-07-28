#include <stdio.h>
#include <stdlib.h>

void printSort(int* array, int n){
        system("clear");
        for(int i=0;i<n;++i) printf("[%d]=%d.\n", i+1, array[i]);
}

void heapSort(int* array, int n){
	

}

int main (int argc, char* argv[]){
        if (argc < 3) {
                fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
                return 1;
        }

        FILE *file = fopen(argv[2], "r");
        if(file == NULL) {
                perror("Error opening file");
                return 1;
        }

        int i = 0, n = atoi(argv[1]), num;
        int array[n];

        while(fscanf(file, "%d", &num) == 1){
                array[i] = num;
                i++;
        }

	fclose(file);
	return 0;
}

