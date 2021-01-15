#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "assign2funcs.h"
// complied with 	gcc  assign2main.c assign2funcs.c -lm -o Assignment2



int main()
{
	int i = 0, vector_set = 0, vector_size = 0;
	int exit = 0;
	char line[line_max];
	char * word;
	double vector;
	 struct vector vect;
	 struct vector normal;
	 
	while(1){
		
		fgets(line, sizeof(line), stdin);
		if(feof(stdin) )//if end of file exit with exit code
			return exit;
		if (line[0]=='\n') // if empty line skip line read again
			continue;
		
			word = strtok (line, " "); // get first token
		
		 if (vector_set == 0 ){// check to see if input is a vector length or vector data
			 if(validSize(word)){// check to see it is a valid size for vector 0-9 
				sscanf(word,"%d\n", &vect.length); 
				if (vect.length == 0)// exit if length = 0
					return exit;
				vector_set =1; // set vector flag so it does not vector length until finished
				word = strtok (NULL, " "); // get next token
				
			 }
			else {
				fprintf(stderr,"Bad input \n");
				exit = 1;
				continue;
			}
		
		}
		
	
		while(word != NULL && i< vect.length){ // parse line until number of data equals vector length or no more tokens in line
		
		if (validDouble(word)){//check to see if data is valid
			sscanf(word, "%lf", &vect.data[i]);
			
			i++;
			
		}
		else{ // bad input so reset everything and break from while loop
			fprintf(stderr,"Bad input\n");
			vector_set =0;
			exit = 1;
			i = 0;
			break;
		}
		word = strtok (NULL, " ");
		
		}
		
		if(i == vect.length){// vector finished reading so reset everything and print everything
			vector_set = 0;
			i=0;
			printf("VECTOR: ");
			displayVector(vect);
			normal = normalizeVector(vect);
			printf(" NORMALIZED: ");
			displayVector(normal);
			printf("\n");
		}
		
	}
   return 0;
}
