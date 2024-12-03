#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int calculateIfPossible(char* buffer);
#define RED 12
#define BLUE 14
#define GREEN 13
int main(int argc,char** argv){
	FILE *fp;
	int c;
	int finalAns = 0;
	int id=0;
	int base=10;
	char buffer[1000]={'\0'};
	int bufPos = 0;
	bool isSearchingForId=true;
	int ifPossible=0;
	fp=fopen(argv[1],"r");
	while((c=getc(fp))!=EOF){
		if(c=='\n'){
			if(buffer[0]!='\0'){
			ifPossible+=calculateIfPossible(buffer);
			}
			isSearchingForId=true;
			id=0;
			base=10;
			bufPos=0;
			buffer[0]='\0';
		}
		else{
			if(isSearchingForId && c-'0'>=0 && c-'0'<10){
			  id=id*base+(c-'0');
			
			}

			else if(c==':'){
				isSearchingForId=false;
				buffer[0]='\0';
				bufPos=0;
			}
			else if(c!=' '){
			  buffer[bufPos]=c;
			  buffer[bufPos+1]='\0';
			  bufPos++;
			}
	        printf("%s\n",buffer);
		}
	}
	printf("%d\n",ifPossible);
	return finalAns;
}
int calculateIfPossible(char buffer[]){
    int num=0;
    int base=10;
    int colorPos=0;
    int maxRed=0;
    int maxBlue=0;
    int maxGreen=0;
    char color[10]={'\0'};
    for(int i =0;i<strlen(buffer)+1;i++){
      if(buffer[i]-'0'>=0 && buffer[i]-'0'<10){
         num=num*base+(buffer[i]-'0');
       }
      else if(buffer[i]==',' || buffer[i]=='\0' || buffer[i]==';'){
	 printf("%d %s\n",num,color);
        if(strcmp(color,"red")==0){
	 if(num>maxRed)
		 maxRed=num;
	}   
	else if(strcmp(color,"blue")==0){
	  if(num>maxBlue)
		  maxBlue=num;

	}
	else if(strcmp(color,"green")==0){
	  if(num>maxGreen)
		  maxGreen=num;
	}
	num=0;
	base=10;
	colorPos=0;
	color[0]='\0';
      
      }else if(buffer[i]-'0'>=10 || buffer[i]-'0'<0){
        color[colorPos]=buffer[i];
	color[colorPos+1]='\0';
	colorPos++;
      }
    
    }
    printf("%d\n",maxRed*maxBlue*maxGreen);
    return maxRed*maxBlue*maxGreen;

}
