/*****************************************************************************
program name :- hamming distance
authour name :- prashant kumar mishra
roll number :- 2447021
date of creation :- 11-09-2024
date of modification :- 12-09-2024
organization :- National institute of technology patna
******************************************************************************/

#include <stdio.h>
//#include <conio.h>

// variable declarations
	int i,j;
	int data1[100];
	int data2[100];
	int data_length;
	int hamming_dist,result;
//minimum hamming distance logic 	
int fxor(int arr1[],int arr2[],int size){
	result =0;
	for(i=0;i<data_length;i++){
		if(arr1[i]!=arr2[i]){
			result++;
		}
	}
	return result;
}

int main(){
    //input of data length
	printf("enter data word length : ");
	scanf("%d",&data_length);
	printf("\n");
	
	//input of data 1
	printf("\nenter data word 1 bit by bit : ");
	for(i=0;i<data_length;i++){
		scanf("%d",&data1[i]);
	}
	printf("\n");
	
	//input of data 2
	printf("\nenter data word 2 bit by bit : ");
	for(i=0;i<data_length;i++){
		scanf("%d",&data2[i]);
	}
	printf("\n");
	
	//enterd data 1
	printf("\nentered data word 1 : ");
	for(i=0;i<data_length;i++){
		printf("%d ",data1[i]);
	}
	printf("\n");
	
	//enterd data 1
	printf("\nentered data word 2 : ");
	for(i=0;i<data_length;i++){
		printf("%d ",data2[i]);
	}
	printf("\n");
	
	
	//resultant hamming distance
	hamming_dist=fxor(data1,data2,data_length );
	printf("\n minimum hamming distance for the given data words is : %d",hamming_dist);
	//clrscr();
	return 0;
}

