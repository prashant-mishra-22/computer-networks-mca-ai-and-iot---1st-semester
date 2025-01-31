/*****************************************************************************
program name :- crc error detection
authour name :- prashant kumar mishra
roll number :- 2447021
date of creation :- 12-09-2024
date of modification :- 12-09-2024
organization :- National institute of technology patna
******************************************************************************/

#include <stdio.h>
//#include <conio.h>

//variables declarations
int i;
int j;
int fcs;
int size;
int error;

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
void generate_crc(int data_word[],int size,int g_p[],int fcs,int crc[]){
	for(i=size;i<size+fcs;++i){//adding fcs bits at end of data word
		data_word[i]=0;
	}
	for(j=0;j<size;++j){//crc loop
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

//crc encoding to send data
void crc_encoding(int data_word[],int size,int crc[],int fcs){
	for(i=0;i<fcs;++i){
		data_word[size+i]=crc[i];
	}
}

//transmission of data
void transmission(int data_word[],int error){
		if(error>-1){
			data_word[error]= (1^data_word[error]);
		}


}

//error checking at recivers end
int checking(int data_word[],int size,int g_p[],int fcs,int crc[]){
	for(j=0;j<size;++j){//crc loop
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
	for(i=0;i<fcs;++i){
		if(crc[i]!=0){
			return 0;
		}
	}
	return 1;
	
}

//main function
void main(){
	
	
	//clrscr();
	

	// taking input of polynomial highest power 

	printf("enter the  data word length : ");
	scanf("%d",&size);
	printf("\n");
	//taking input of polynomial 
	
	printf("\nenter the data word bit by bit : ");
	for(i=0;i<size;++i){
		scanf("%d",&data_word[i]);
	}
	printf("\n");
	
	//printing polynomial

	printf("\nentered data word is : ");
	for(i=0;i<size;++i){
		printf("%d ",data_word[i]);		
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

	generate_crc(data_word,size,g_p,fcs,crc);

	//printing crc bits 

	printf("obtained crc bits/remainder is : ");
	for(i=0;i<fcs;++i){
	 printf("%d",crc[i]);
	}
	printf("\n");
	
	//printing actual transmitted data 
	crc_encoding(data_word,size,crc,fcs);
	size=size+fcs;
	printf("\n actual transmitted data :- ");
	for(i=0;i<size;++i){
		printf("%d ",data_word[i]);
	}
	printf("\n");

    printf("\nenter the bit position to invert the bit : ");
	scanf("%d",&error);
	printf("\n");
	
	//transmitting the encode message 	
	transmission(data_word,error-1);
	printf("\n recieved data at reciever end :- ");
	for(i=0;i<size;++i){
		printf("%d ",data_word[i]);
	}
	
	//error check at the reciver end 
	i=checking(data_word,size,g_p,fcs,crc);
	if(i){
		printf("\nthere is no error in the recievd code \n");
	}else{
		printf("\nthere is an error detected in the recived code\n");
	}












	//getch();
}
	

