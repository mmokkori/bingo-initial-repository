/*ビンゴの判定と数字を格納した配列から重複しない当選番号を抜き出す関数として作成しました。ビンゴカードの初期値、当選番号が毎回違います。
1列目には１～５，２列目には６～１０、３列目には１１～１５のように場所を指定して数字が出現します。*/

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int number(int fy[15],int z){
	
	return fy[z];
}
int hantei(int bingo[3][3]){
	int i,flag;
	flag=0;
	
	/*縦の判定*/
	i=0;
	while(flag==0&&i<=2){
		if(bingo[i][0]+bingo[i][1]+bingo[i][2]==0){
			flag=1;
		}
		i++;
	}
	/*横の判定*/
	i=0;
	while(flag==0&&i<=2){
		if(bingo[0][i]+bingo[1][i]+bingo[2][i]==0){
			flag=1;
		}
		i++;
	}
	/*斜めの判定*/
	if(flag==0){
		if(bingo[0][0]+bingo[1][1]+bingo[2][2]==0){
			flag=1;
		}
		if(bingo[2][0]+bingo[1][1]+bingo[0][2]==0){
			flag=1;
		}
	}
	
	return flag;
}
int main(void)
{
	int i,j,n,x,target,temp,z;
	int bingo[3][3];
	int fy_5[5]={1,2,3,4,5},fy_10[5]={6,7,8,9,10},fy_15[5]={11,12,13,14,15};
	int fy[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	srand((unsigned int)time(NULL));
	/*ビンゴカード作り*/
	for(i=4;i>0;i--){
			target=rand()%i;
			temp=fy_5[target];
			fy_5[target]=fy_5[i];
			fy_5[i]=temp;
		}
		
    for(i=4;i>0;i--){
			target=rand()%i;
			temp=fy_10[target];
			fy_10[target]=fy_10[i];
			fy_10[i]=temp;
		}
    for(i=4;i>0;i--){
			target=rand()%i;
			temp=fy_15[target];
			fy_15[target]=fy_15[i];
			fy_15[i]=temp;
		}
    x=0;
    for(i=0;i<=2;i++){
		
    	bingo[i][0]=fy_5[x];
    	bingo[i][1]=fy_10[x];
    	bingo[i][2]=fy_15[x];
    	x++;
	}
		
	bingo[1][1]=0;
	printf("あなたのカードです。\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%3d ",bingo[i][j]);
		}
		printf("\n");
	}
	/*ランダムな数字列を作成*/
	x=0;
	for(i=14;i>0;i--){
			target=rand()%i;
			temp=fy[target];
			fy[target]=fy[i];
			fy[i]=temp;
		}
	/*ビンゴ判定*/	
	z=0;
	while(x==0){
		
		n=fy[z];
		printf("\n出た数字 %d\n\n",n);
		for(i=0;i<=2;i++){
			for(j=0;j<=2;j++){
				if(n==bingo[i][j]){
					bingo[i][j]=0;
				}
			}
		}
		for(i=0;i<=2;i++){
			for(j=0;j<=2;j++){
				printf("%3d ",bingo[i][j]);
			}
			printf("\n");
		}
		x=hantei(bingo);
		z++;
		
	}
	printf("\nBINGO!! \n");
	
	
	
	return 0;
}