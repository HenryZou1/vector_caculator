#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define max 9 //the max numbr of interger a vector can have
#define line_max 2048 // max charater per line 



int main()
{
	int i = 0, vector_set = 0, vector_size = 0;
	int exit = 0;
	char line[line_max];
	char * word;
	double vector;
	struct vector vect;
	struct vector norm;
	while(1){
		
		fgets(line, sizeof(line), stdin);
		if(feof(stdin) )
			return exit;
		if (line[0]=='\n')
			continue;
		
			word = strtok (line, " ");
		
		 if (vector_set == 0 ){
			 if(validSize(word)){
				sscanf(word,"%d\n", &vect.length);
				if (vect.length == 0)
					return exit;
				vector_set =1;
				word = strtok (NULL, " ");
				
			 }
			else {
				fprintf(stderr,"Bad input \n");
				exit = 1;
				continue;
			}
		
		}
		
	
		while(word != NULL && i< vect.length){
		
		if (validDouble(word)){
			sscanf(word, "%lf", &vect.data[i]);
			
			i++;
			
		}
		else{ 
			fprintf(stderr,"Bad input\n");
			vector_set =0;
			exit = 1;
			i = 0;
			break;
		}
		word = strtok (NULL, " ");
		
		}
		
		if(i == vect.length){
			vector_set = 0;
			i=0;
			printf("Vector: ");
			displayVector(vect);
			norm = normalizeVector(vect);
			printf("Normalized: ");
			displayVector(norm);
			printf("\n");
		}
		
	}
   return 0;
}
