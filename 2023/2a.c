#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool calculateIfPossible(char* buffer);
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
	int red = 0;
	bool isSearchingForId=true;
	int blue = 0;
	int green = 0;
	bool ifPossible=true;
	fp=fopen(argv[1],"r");
	while((c=getc(fp))!=EOF){
		if(c=='\n'){
			if(buffer[0]!='\0'){
			ifPossible=calculateIfPossible(buffer);
			}
			if(ifPossible){
				printf("Id is %d\n",id);
				finalAns+=id;
			}
			isSearchingForId=true;
			id=0;
			base=10;
			ifPossible=true;
			red=0;
			blue=0;
			green=0;
			bufPos=0;
			buffer[0]='\0';
		}
		else if(ifPossible){
			if(isSearchingForId && c-'0'>=0 && c-'0'<10){
			  id=id*base+(c-'0');
			
			}

			else if(c==':'){
				isSearchingForId=false;
				buffer[0]='\0';
				bufPos=0;
			}
			else if(c==';' ){
                            ifPossible=calculateIfPossible(buffer);
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
	printf("%d\n",finalAns);
	return finalAns;
}
bool calculateIfPossible(char buffer[]){
    int num=0;
    int base=10;
    int colorPos=0;
    char color[10]={'\0'};
    for(int i =0;i<strlen(buffer)+1;i++){
      if(buffer[i]-'0'>=0 && buffer[i]-'0'<10){
         num=num*base+(buffer[i]-'0');
       }
      else if(buffer[i]==',' || buffer[i]=='\0'){
	 printf("%d %s\n",num,color);
        if(strcmp(color,"red")==0){
	 if(num>RED)
		 return false;
	}   
	else if(strcmp(color,"blue")==0){
	  if(num>BLUE)
		  return false;

	}
	else if(strcmp(color,"green")==0){
	  if(num>GREEN)
		  return false;
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
    return true;

}
