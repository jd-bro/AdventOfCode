#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool checkAdjacency(char matrix[150][150],int first,int last, int k, int l,int rows,int columns);
int main(int argc,char** argv){
	FILE *fp;
	int c;
	int num;
	int first;
	int last;
	int sum;
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
		if(num!=0){
		 bool ans = checkAdjacency(matrix,first,last,k-1,columns-1,rows,columns);
		 if(ans==true){
                          printf("Num %d\n",num);
                  sum+=num;
                  }

		}
		num=0;
		first = -1;
		last = 0;
		for(int l = 0;l<columns;l++){
		if(matrix[k][l]-'0'>=0 && matrix[k][l]-'0'<10){
		num=num*base+(matrix[k][l]-'0');
		if(first==-1){
		 first = l; 
		}
		last = l;
		}
		else if(num!=0){
		  printf("%d\n",num);
		  bool ans = checkAdjacency(matrix,first,last,k,l,rows,columns);
		  if(ans==true){
			  printf("Num %d\n",num);
		  sum+=num;
		  }
		  num=0;
		  first = -1;
		}
		}
		printf("\n");
	
	}
	printf("%d sum ",sum);
}
	bool checkAdjacency(char matrix[150][150],int first,int last, int k, int l,int rows,int columns){
		
		int lastRow=k;
                if(first-1>=0){
		first = first -1;
		} 
		
		if(k-1>=0){
		k = k-1;
		}
		if(k+2<rows){
		 lastRow = k+2;
		}
		printf("%d %d %d %d\n",k,lastRow,first,l);
		for(int i = k;i<=lastRow;i++){
		   for(int j = first;j<=l;j++){
			   
		    if(!((matrix[i][j]-'0'>=0 && matrix[i][j]-'0'<10) || matrix[i][j]=='.')) {
		    	printf("buzz %d %d  %c\n",i,j,matrix[i][j]);
			    return true;
		    }
		   }
		}
		return false;
	
	}






