#include <stdio.h>


int main (int argc, char* argv[]){
	int w, flut=0;
	scanf("%d",&w);
	
	for(int i=0;i<w/2;++i){
		if(((w/2)+flut)%2 == 0 && ((w/2)-flut)%2 == 0 && ((w/2)+flut) + ((w/2)-flut) == w){
			printf("YES");
			return 0;
		}
		flut++;
	}
	printf("NO"); 

	return 0;
}
