#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void clearBuffer(char* buffer,int size);
int checkIfBufContains(char* buffer,int pos);
void shiftBuffer(char* buffer,int size);
int getRemaining(char* buffer,int pos,bool firstFound,bool lastFound,int first,int last);
int main(int argc,char** argv){
	printf("Reading file : %s\n",argv[1]);
	FILE *file;
	FILE *fp;
	int c;
	fp=fopen(argv[1],"r");
	int sum = 0;
	bool firstFound = false;
	bool lastFound = false;
	int first = 0;
	int last = 0;
	char buffer[6]={'\0'};
	int bufPos = 0;
	//clearBuffer(buffer,5);
	while((c=getc(fp))!=EOF){
		if(c=='\n'){
			printf("Buffer now is %s\n",buffer);
			printf("Buffer pos is %d\n",bufPos);
			printf("First Found is %d\n",firstFound);
			printf("Last Found is %d\n",lastFound);
			printf("first is %d\n",first);
			printf("last is %d\n",last);
			int y =  getRemaining(buffer,bufPos,firstFound,lastFound,first,last);
			printf("y is %d\n",y);
			if(!firstFound){
				sum+=y;
			}
			else{
				sum+=first*10+y;
			}

			firstFound=false;
			lastFound=false;
			first=0;
			last=0;
			bufPos=0;
			buffer[0]='\0';
		} else {
			// int numVal = c-'0';
			//printf("%d\n",numVal);
			//if(numVal>=0 && numVal<10){
			// if(firstFound==false){
			//first = numVal;
			// last = numVal;
			// firstFound = true;
			// lastFound = true;
			// bufPos=0;
			// clearBuffer(buffer,6);
			// }
			//else{
			//last = numVal;
			//clearBuffer(buffer,0);
			//bufPos=0;
			// }
			if(bufPos<5){
				if(buffer[bufPos]=='\0'){
					buffer[bufPos]=c;
					buffer[bufPos+1]='\0';
				}
				int val = checkIfBufContains(buffer,bufPos);
				if(val>0 && !firstFound){
					first=val;
					last=val;
					firstFound=true;
					lastFound=true;
					shiftBuffer(buffer,bufPos+1);
				}else if(val>0 && firstFound){
					last=val;
					shiftBuffer(buffer,bufPos+1);

				}else if(buffer[bufPos+1]=='\0'){
					bufPos++;
				}
				else{
					shiftBuffer(buffer,bufPos+1);
					//bufPos=0;
				}



			}
			else{
				shiftBuffer(buffer,bufPos+1);	     
				bufPos=bufPos-1;
				buffer[bufPos]=c;
				buffer[bufPos+1]='\0';
				int val = checkIfBufContains(buffer,bufPos);
				if(val>0 && !firstFound){
					first=val;
					last=val;
					firstFound=true;
					lastFound=true;
					shiftBuffer(buffer,bufPos+1);
				}else if(val>0 && firstFound){
					last=val;
					shiftBuffer(buffer,bufPos+1);
				}else{
					shiftBuffer(buffer,bufPos+1);

				}
				printf("%s Heree\n",buffer);
			}
		}


		}


		printf("%d\n",sum);
	}
	int getRemaining(char buffer[],int pos,bool firstFound,bool lastFound,int first,int last){
		bool flag = false;
		if(!firstFound){
			flag = true;
		}                             
		for(int i =0;i<pos+1;i++){
			if(buffer[i]-'0' >0 && buffer[i]-'0'<10){
				printf("%d\n",buffer[i]-'0');
				printf("%d\n",firstFound);
				if(firstFound==false){
					first = buffer[i]-'0';		 
					last = buffer[i]-'0';
					firstFound=true;
					lastFound=true;
				}
				else{
					last = buffer[i]-'0';
				}
				printf("Firt %d lAst %d \n",first,last);
			}else{
				char temp[6]={'\0'};
				strncpy(temp,buffer+i,pos);
				int x = checkIfBufContains(temp,pos);
				printf("X is %d\n",x);
				if(x>0 && x<10){
					if(firstFound==false){
						first = x;		 
						last=x;
						firstFound=true;
						lastFound=true;
					}
					else{
						last=x;
					}
				}
			}

		}
		if(flag){
			return first*10+last;
		}
		else{
			return last;
		}
	}
	void clearBuffer(char buffer[],int size){
		buffer[0]='\0';
	}
	void shiftBuffer(char buffer[],int size){
		for(int i =1;i<size;i++){
			buffer[i-1]=buffer[i];
		}
		buffer[size-1]='\0';
	}

	int checkIfBufContains(char buffer[],int pos){
		char temp2[5]={'\0'};
		char temp3[6]={'\0'};
		char temp1[4]={'\0'};	  
		if(buffer[0]-'0'<10 & buffer[0]-'0'>=0)
			return buffer[0]-'0'; 
		strncpy(temp1,buffer,	3);
		strncpy(temp2,buffer,4);
		strncpy(temp3,buffer,5);
		printf("%s   %s    %s \n",temp1,temp2,temp3);
		if(strcmp(temp1,"one")==0){
			return 1;
		}
		else if(strcmp(temp1,"two")==0){
			return 2;
		}else if(strcmp(temp3,"three")==0){
			return 3;
		}
		else if(strcmp(temp2,"four")==0){
			return 4;
		}
		else if(strcmp(temp2,"five")==0){
			return 5;
		}
		else if(strcmp(temp1,"six")==0){
			return 6;
		}
		else if(strcmp(temp3,"seven")==0){
			return 7;
		}
		else if(strcmp(temp3,"eight")==0){
			return 8;
		}
		else if(strcmp(temp2,"nine")==0){
			return 9;
		}


		return 0;
	}
