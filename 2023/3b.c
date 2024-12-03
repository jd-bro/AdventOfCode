#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int checkAdjacency(char matrix[150][150],int first,int last, int k, int l,int rows,int columns);
int main(int argc,char** argv){
	FILE *fp;
	int c;
	int num;
	int first;
	int last;
	int sum=0;
	int i=0;
	int j =0;
	int rows = 0;
	int columns = 0;
	char matrix[150][150]={'\0'};
	int base = 10;
	fp = fopen(argv[1],"r");
	while((c=getc(fp))!=EOF){
		if(c!='\n'){
			matrix[i][j]=c;
			j++;
		}
		else{
			columns = j;
			i++;
			j=0;
		}


	}
	rows = i;
	printf("Rows %d Columns %d",rows,columns);
	for(int k = 0;k<rows;k++){
		num=0;
		first = -1;
		last = 0;
		for(int l = 0;l<columns;l++){
			if(matrix[k][l]=='*'){
				int ans = checkAdjacency(matrix,first,last,k,l,rows,columns);
				if(ans>0){
					sum+=ans;
				}
				num=0;
				first = -1;
			}
		}
		printf("\n");

	}
	printf("%d sum ",sum);
}
int checkAdjacency(char matrix[150][150],int first,int last, int k, int l,int rows,int columns){

	int lastRow=k;
	int firstRow=k;
	int num=0;
	int base = 10;
	int count=0;
	int result=1;
	int firstIndex=-1;
	if(first-1>=0){
		first = first -1;
	} 

	if(k-1>=0){
		firstRow = k-1;
	}
	if(k+1<rows){
		lastRow = k+1;
	}
	printf("%d %d %d %d\n",firstRow,lastRow,firstIndex,l);
	for(int i = firstRow;i<=lastRow;i++){
		if(num>0){
			if(firstIndex<=l+1 && l<=columns-1){
				if(count<2){
					count++;
					result=result*num;
					
				}
				else{
					return -1;
				}
			}
		}
		num=0;
		firstIndex=-1;


		for(int j = 0;j<columns;j++){


			if((matrix[i][j]-'0'>=0 && matrix[i][j]-'0'<10)) {
				num=num*base+(matrix[i][j]-'0');
				if(firstIndex==-1){
					firstIndex=j;
				}
			}
			else{
				if(num>0){
					printf("%d %d %d zzz\n",firstIndex,l,j);
					if(firstIndex<=l+1 && l<=j){	      
						if(count<2){
							printf("%d num",num);

							count++;
							result=result*num;
							printf("%d result",result);
						
						}
						else{  
							count=0;
							result=1;
							return -1;
						}
					}
						num=0;
						firstIndex=-1;
					
				}
			num=0;
			firstIndex=-1;
			}
		}
	}
	if(count<2){
	return -1;}
	return result;

}






