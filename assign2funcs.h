#ifndef assign2funcs
#define assign2funcs
#define max 9 //the max numbr of interger a vector can have
#define line_max 2048 // max charater per line 
struct vector{
	int length;
	double data[max];
};
int validDouble( char  input []);
int validSize( char  input []);
void displayVector(struct vector input);
double caculateNormalize(struct vector input);
struct vector  normalizeVector(struct vector input);
#endif