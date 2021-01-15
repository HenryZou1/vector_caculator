#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "assign2funcs.h"
int validDouble( char  input []){
	int i;
	for (i = 0; i < strlen(input)-1; i++){
		
		if((i ==0 && (input[i]== '+' ||input [i] == '-'))||input[i]=='.'){ // if it is a . or +- is on the first index then character is good continue loop
			
			continue;
		}
		
		if(!isdigit(input[i])){// chacter is not a digit return 0
			return 0;
		}
			
	}
	return 1;
}
int validSize( char  input []){
	int i;
	
	for (i = 0; i < strlen(input)-1; i++){
	
		if(!isdigit(input[i])){//not a number
			
			return 0;
		}
			
	}
	i = atoi(input);
	
	if(i > 9 || i <0) // keep length between 0-9
		return 0;
	return 1;
}

void displayVector(struct vector input){
	int i;
	printf("[ ");
	for (i = 0; i < input.length; i++){
		printf("%.3f",input.data[i]);//display vector with 3 digit after decimial
		if(i != input.length-1)
			printf(", ");
			
	}
	printf(" ]");
}

double caculateNormalize(struct vector input){
	int i=0;
	double n = 0.0;//caculate the normalization
	for (i = 0; i < input.length; i++){
		n += pow(input.data[i],2);
	}
	n = sqrt(n);
	return n;

}

struct vector  normalizeVector(struct vector input){
	int i=0;
	double n ;
	struct vector norm;
	n = caculateNormalize(input);//caculate the normalization 
	norm.length = input.length;
	for (i = 0; i < input.length; i++){
		norm.data[i]=input.data[i]/n;
	
	}
	//return the normalized array
	return norm;

}