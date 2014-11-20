#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<conio.h>
void rotateArray(int *,int);
void dispArr(int *,int);
void gen2(int *);
void swapAdd(int *);
void main(void){
int arrTest[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
while(1){
	char dir;
	clrscr();
	gen2(&arrTest[0][0]);
	dispArr(&arrTest[0][0],4);
	dir =getch();
	switch (dir){
	case 'd':
		swapAdd(&arrTest[0][0]);
		break;
	case 'w':
		rotateArray(&arrTest[0][0],1);
		swapAdd(&arrTest[0][0]);
		rotateArray(&arrTest[0][0],1);
		rotateArray(&arrTest[0][0],1);
		rotateArray(&arrTest[0][0],1);
		break;
	case 'a':
		rotateArray(&arrTest[0][0],1);
		rotateArray(&arrTest[0][0],1);
		swapAdd(&arrTest[0][0]);
		rotateArray(&arrTest[0][0],1);
		rotateArray(&arrTest[0][0],1);
		break;
	case 's':
		rotateArray(&arrTest[0][0],1);
		rotateArray(&arrTest[0][0],1);
		rotateArray(&arrTest[0][0],1);
		swapAdd(&arrTest[0][0]);
		rotateArray(&arrTest[0][0],1);
		break;
	default :
		exit(0);
	}
}
}
void swapAdd(int * arrPtr){
	int arr[4][4];
	int i=0,j=0,k=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			arr[i][j]=*arrPtr;
			arrPtr++;
		}
	}
	arrPtr--;
	dispArr(&arr[0][0],4);
	for(i=3;i>=0;i--){
		for(j=3;j>=0;j--){
			for(k=j-1;k>=0;k--){
				if(arr[i][k]!=0){
					if(arr[i][j]==arr[i][k]){
						arr[i][j] *=2;
						arr[i][k]=0;
					}
					else{
						if(arr[i][j]==0){
							arr[i][j]=arr[i][k];
							arr[i][k]=0;
						}
					}
					break;
				}
			}
		}
	}
	for(i=3;i>=0;i--){
		for(j=3;j>=0;j--){
			*arrPtr=arr[i][j];
			arrPtr--;
		}
	}
}
void gen2(int * arrPtr){
	int randNum ;
	int * arrOrgin=arrPtr;
	do{
		randNum =random(16);
		arrPtr=arrOrgin;
		arrPtr+=randNum;
	}while(*arrPtr!=0);
	*arrPtr=2;
}
void rotateArray(int * arrPtr,int rounds){
	int arr[4][4];
	int i=0,j=0,k;
	for (k=0;k<rounds;k++){
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				arr[j][3-i]=*arrPtr;
				arrPtr++;
			}
		}

   }
	for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				--arrPtr;
				*arrPtr=arr[3-i][3-j];
			}
		}
}
void dispArr(int * arrPtr,int n){
	int row,col;
	clrscr();
	for(row=0;row<n;row++){
		for(col=0;col<n;col++){
			gotoxy((col+1)*10,(row+1)*4);
			printf("%d",*arrPtr);
			arrPtr++;

		}
	}
}
