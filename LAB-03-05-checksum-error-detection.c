/*****************************************************************************
program name :- checksum error detection
authour name :- prashant kumar mishra
roll number :- 2447021
date of creation :- 14-09-2024
date of modification :- 14-09-2024
organization :- National institute of technology patna
******************************************************************************/

#include <stdio.h>
//#include<conio.h>

    int i,j,p;
    int size;
    int k;
    int m;
    
    int data_word[1000];
    int segments[100][100];
    int checksum[100];
    
    void xor1(int arr[],int end){
    	for(i=1;i<=end;++i){
    		if(arr[i]){
    		    arr[i]=0;
    		}else{
    		    arr[i]=1;
    		}
		}
	}

	void bin_addition(int arr1[],int arr2[],int end)
	{
		int sum=0;
		int carry=0;
		int s;
		
		for(s=end;s>0;--s){
			sum=carry+arr1[s]+arr2[s];
			arr2[s]=sum%2;
			carry=sum/2;
		}
		
		if(carry ){
			int temp[end];
			temp[end]=carry;
			for(s=end-1;s>0;--s){
				temp[s]=0;
			}
			bin_addition(temp,arr2,end);	
		}
	}
	void gen_check(int row,int col,int seg[row][col],int res[]){
		for(i=1;i<=col;++i){
			res[i]=seg[1][i];
		}
		for(i=2;i<=row;++i){
			bin_addition(seg[i-1],seg[i],col);
		}
		xor1(seg[k],col);
	}


int main() {
    
    //clrscr();
    
    printf("enter size of data word : ");
    scanf("%d",&size);
    printf("\n");
    
    printf("enter data word bit by bit : ");
    for(i=1;i<=size;++i){
        scanf("%d",&data_word[i]);
    }
    printf("\n");
    
    printf("entered data word : ");
    for(i=1;i<=size;++i){
        printf("%d ",data_word[i]);
    }
    printf("\n");
    
    while(1){
        printf("\nenter length of checksum : ");
        scanf("%d",&m);
        printf("\n\n");
        if(size%m == 0){
            break;
        }else{
            printf("enter length such that length of segments will be equal \n\n");
        }
        
    }
    k=size/m;
    p=1;
    for(i=1;i<=k;++i){
        for(j=1;j<=m;++j){
            segments[i][j]=data_word[p];
            p++;
        }
    }
    
    printf("segments of data word : ");
    for(i=1;i<=k;++i){
        printf("\n\nsegment %d : ",i);
        for(j=1;j<=m;++j){
            printf("%d ",segments[i][j]);
        }
    }
    printf("\n");
    
	gen_check(k,m,segments,checksum);
	printf("\n\nthe generated checksum is : ");
    for(i=1;i<=m;++i){
        printf("%d ",segments[k][i]);
    }
	
	
	
	
	//getch();
    return 0;
}
