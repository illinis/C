#include <stdio.h>
#include <stdlib.h>

void BuildStringFromMatrix(int* matrix, int nr, int nc, char* output){
	int n = 0;	
}

int main(int argc, char* argv[]){

	return 0;
}



/*
 * 	voodo
 *
 *	00 01 02 0n
 *	10 11 12 1n
 *	20 21 22 2n
 *	n0 n1 n2 nn
 *
 *
 *	right mov 	-> ++
 *	down mov 	-> ovf
 *	left mov	-> --
 *	up mov		-> !ovf
 *
 *	hit corner 	-> right-left mov 	-> nr change
 *			-> down-up mov		-> nc change
 *
 *
 * */
