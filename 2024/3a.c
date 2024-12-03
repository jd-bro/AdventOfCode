#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int main(int argc,char** argv){
 

	FILE *fp;
	char c;
	char *buf;
	char *buf2;
	buf = malloc(20*sizeof(char));
	buf2 = malloc(10*sizeof(char));
	fp=fopen(argv[1],"r");
	int size=0;
	int num1=0;
	int num2=0;
	int base=10;
	int size2=0;
	bool validFirst=false;
	bool validSecond=false;
	bool gotFirst=false;
	int sum=0;
	bool isEnabled=true;
	bool inValidParantheses=false;
        bool gotValidProduct = false;
	while((c=getc(fp))!=EOF){
	     if(c=='d' && size2==0){
               buf2[0]='d';
               size2++;
              }
	     else if(c=='o' && size2==1){
               buf2[1]='o';
               size2++;
              }
	     else if(c=='n' && size2==1){
               buf2[2]='n';
               size2++;
              }
	     else if(c=='\'' && size2==2){
               buf2[3]='\'';
               size2++;
              }
	     else if(c=='t' && size2==3){
               buf2[4]='t';
               size2++;
              }
	      else if(c=='(' && size2==4){
               buf2[5]='(';
               size2++;
              }
	       else if(c=='(' && size2==2){
               buf2[2]='(';
               size2++;
              }

	      else if(c==')' && size2==5){
		printf("disabled\n");
	       isEnabled=false;
	       free(buf2);
	       buf2 = malloc(10*sizeof(char));
	       size2=0;
              }
	      else if(c==')' && size2==3){
               isEnabled=true;
               free(buf2);
               buf2 = malloc(10*sizeof(char));
               size2=0;
              }








		else if(c=='m' && size==0){
	       buf[0]='m';
	       size++;
	      }
              else if(c=='u' && size==1 && buf[0]=='m'){
	      buf[1]='u';
	      size++;
	      }
	    else if(c=='l' && size==2 && buf[1]=='u'){
              buf[2]='l';
              size++;
              } 
	    else if(c=='(' && size==3 && buf[2]=='l'){
	     buf[3]='(';
	     size++;
	     inValidParantheses=true;
	    }
	      else if(c-'0'>=0 && c-'0'<10 && inValidParantheses && gotFirst==false){
	        num1=num1*10+(c-'0');
		validFirst=true;
	    }
	      
	      else if(c==',' && inValidParantheses && validFirst){
		      gotFirst=true;
	    }
	     else if(c-'0'>=0 && c-'0'<10 && inValidParantheses && gotFirst){
                num2=num2*10+(c-'0');
                validSecond=true;
            }
	      else if(c==')' && size==4 && buf[3]=='('){
	       if(validFirst && validSecond && inValidParantheses){
		printf("%d %d\n",num1,num2);
		if(isEnabled)
	       	   sum+=num1*num2;
	       }

            free(buf);
            validFirst=false;
            validSecond=false;
	    gotFirst=false;
            inValidParantheses=false;
            size=0;
            num1=0;
            num2=0;
            buf = malloc(20*sizeof(char));
	    }
	      else{
	    free(buf);
	    validFirst=false;
	    validSecond=false;
	    gotFirst=false;
	    inValidParantheses=false;
	    size=0;
	    num1=0;
	    num2=0;
	    buf = malloc(20*sizeof(char));
	    
	    }

	
	
	
	}
	printf("sum %d",sum);


}
