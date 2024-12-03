#include<stdio.h>
#include<stdbool.h>

int main(int argc,char** argv){
	printf("Reading file : %s\n",argv[1]);
        FILE *file;
	FILE *fp;
	int c;
	int temp = 0;
	fp=fopen(argv[1],"r");
	int sum = 0;
          bool firstFound = false;
          bool lastFound = false;
          int first = 0;
          int last = 0;

	while((c=getc(fp))!=EOF){
	   if(c=='\n'){
	     firstFound=false;
	     lastFound=false;
	     sum+=first*10+last;
	     first=0;
	     last=0;
	   }else{
	     int numVal = c-'0';
	     if(numVal<10){
	       if(firstFound==false){
	         first = numVal;
		 last = numVal;
		 firstFound = true;
		 lastFound = true;
	       }
	       else{
	         last = numVal;
	       }
	     } 
	  }
	}	
       printf("%d\n",sum);
}
