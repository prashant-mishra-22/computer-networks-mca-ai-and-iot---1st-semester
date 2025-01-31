/*****************************************************************************
program name :- crc bits
authour name :- prashant kumar mishra
roll number :- 2447021
date of creation :- 12-09-2024
date of modification :- 12-09-2024
organization :- National institute of technology patna
******************************************************************************/

#include <stdio.h>
#include <conio.h>

//variables declarations 
int i;
int j;
int fcs;
int hpower;

//arrays declarations 
int data_word[100];
int g_p[100];
int crc[100];
int res[100];
int temp1[100];
int temp2[100];


//function declarations 

//zor functionality
void zor(int arr1[],int arr2[],int res[],int fcs){
	for(i=1;i<=fcs;i++){
		res[i-1]=arr1[i]^arr2[i];//performing zor bit by bit 
	}
}


//crc generation
void generate_crc(int data_word[],int hpower,int g_p[],int fcs,int crc[]){
	for(i=hpower+1;i<=hpower+fcs;++i){//adding fcs bits at end of data word 
		data_word[i]=0;
	}
	for(j=0;j<=hpower;++j){//crc loop
		if(j==0){//first iteration logic
			for(i=0;i<=fcs;++i){
				temp1[i]=data_word[i];
			}
			zor(temp1,g_p,crc,fcs);			
		}else{//after first iteration logic
			for(i=0;i<fcs;++i){
				temp1[i]=crc[i];
			}
			temp1[fcs]=data_word[j+fcs];
			if(temp1[0]){
				zor(temp1,g_p,crc,fcs);
			}else{
				for(i=0;i<=fcs;++i){
					temp2[i]=0;
				}
				zor(temp1,temp2,crc,fcs);
			}
				
		}
	}	
}

//main function
void main(){
	
	
	//clrscr();
	

	// taking input of polynomial highest power 

	printf("enter highest power of polynomial : ");
	scanf("%d",&hpower);
	printf("\n");
	
	//taking input of polynomial 

	printf("\nenter the polynomialto be divided : ");
	for(i=0;i<=hpower;++i){
		printf("\ncoefficient of x^%d : ",hpower-i);
		scanf("%d",&data_word[i]);
	}
	printf("\n");
	
	//printing polynomial

	printf("\nentered polynomial is : ");
	for(i=0;i<=hpower;++i){
		if(data_word[i] && i!=hpower){
			if(i==hpower-1 && !data_word[hpower]){
				printf("x^%d ",hpower-i);
			}else{
				printf("x^%d + ",hpower-i);			
			}
		}else if(data_word[i] && i==hpower){
			printf("%d\n",1);
		}
	}
	printf("\n");

	//taking input of fcs

	printf("\nenter fcs of generator polynomial :");
	scanf("%d",&fcs);
	printf("\n");
	
	//taking input of generator polynomial 

	printf("\nenter the genarator polynomialto be used : ");
	for(i=0;i<=fcs;++i){
		printf("\ncoefficient of x^%d : ",fcs-i);
		scanf("%d",&g_p[i]);

	}
	printf("\n");

	//printing generator polynomial 

	printf("\nentered generator polynomial is : ");
	for(i=0;i<=fcs;++i){
		if(g_p[i] && i!=fcs){
			if(i==fcs-1 && !g_p[fcs]){
				printf("x^%d ",fcs-i);
			}else{
				printf("x^%d + ",fcs-i);			
			}
		}else if(g_p[i] && i==fcs){
			printf("%d\n",1);
		}
	}
	printf("\n");

	//genarating crc bits 

	generate_crc(data_word,hpower,g_p,fcs,crc);

	//printing crc bits 

	printf("obtained crc bits/remainder is : ");
	for(i=0;i<fcs;i++){
	 printf("%d",crc[i]);
	}
	printf("\n");

	















	//getch();
}
	


