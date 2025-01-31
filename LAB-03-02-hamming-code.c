/*****************************************************************************
program name :- hamming code
authour name :- prashant kumar mishra
roll number :- 2447021
date of creation :- 11-09-2024
date of modification :- 12-09-2024
organization :- National institute of technology patna
******************************************************************************/

#include <stdio.h>
#include <math.h>

//variable declaration

int i,j;
int data_word[100];
int code_word[100];
int length;
int ham_bit_req;
int result ;


//funtion defination and implementation

//required bit calculation
int bit_req(int size){
    result=0;
    while(pow(2,result)<(size+result+1)){
        result++;
    }
    return result;
}

//initializing code word 
void init_code(int arr1[],int arr2[],int l,int hr){
    j=1;
    for(i=1;i<=l+hr;i++){
        if(i==1 || i==2 || i==4 || i==8){
            arr2[i]=0;
            
        }else {
            arr2[i]=arr1[j];
            j++;
            
        }
    }
}

//encoding codeword
void encode(int arr[]){
    arr[1]=arr[3]^arr[5]^arr[7]^arr[9]^arr[11];
    arr[2]=arr[3]^arr[6]^arr[7]^arr[10]^arr[11];
    arr[4]=arr[5]^arr[6]^arr[7]^arr[12];
    arr[8]=arr[9]^arr[10]^arr[11]^arr[12];
}

int main() {
	
    // data word size input
    printf("enter data word length : ");
    scanf("%d",&length);
    printf("\n");
    
    // data word input 
    printf("\nenter data word bit by bit : ");
    for(i=1;i<=length;i++){
        scanf("%d",&data_word[i]);
    }
    printf("\n");
    
    //entered data word 
    printf("\nentered data word : ");
    for(i=1;i<=length;i++){
        printf("%d  ",data_word[i]);
    }
    printf("\n");
    
    //calculate bits needed 
    ham_bit_req=bit_req(length);
    printf("\nreducdancy bit required = %d \n",ham_bit_req);
    
    //initialization of code word 
    init_code(data_word,code_word,length,ham_bit_req);
    printf("\nrequired code word to be encoded with r bits : ");
    for(i=1;i<=length+ham_bit_req;i++){
        if(i==1 || i==2 || i==4 || i==4){
            printf("r%d ",i);
        }
        else{
            printf("%d ",code_word[i]);
        }
    }
    printf("\n");
    
    //encoding code word with bits 
    encode(code_word);
    printf("\nequired code word : ");
    for(i=1;i<=length+ham_bit_req;i++){
        printf("%d ",code_word[i]);
    }
    printf("\n");
    
    

    return 0;
}

