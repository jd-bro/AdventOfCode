#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool isSafe(int arr[],int count,int currCount);
int *createNewArray(int arr[],int k, int count);
int main(int argc, char** argv){

	FILE *fp;
	char c;
	int base=10;
	int *arr;
	int sum=0;
	fp = fopen(argv[1],"r");
	while((c=getc(fp))!=EOF){
		int count=0;
		arr = (int *) malloc(100*sizeof (int));
 	  while(c!='\n'){
              int num=0;
  	      while(c-'0'>=0 && c-'0'<10){
	        num = num*base + (c-'0');
		c=getc(fp);
	      }
	      arr[count] = num;
	      count++;
	      if(c!='\n')
	      	c=getc(fp);
	  
	  }
	  bool flag = isSafe(arr,count,count);
	   
	  if(flag==true){
		  sum++;
	  }else{
     	   for(int i = 0;i<count;i++){
	   printf("%d ",arr[i]);
	   } 	  
	  printf("unsafe\n");
	  }
	  free(arr);


	}
	printf("result %d\n",sum);



}

bool isSafe(int arr[],int count,int currCount){
if(currCount-count>1)
	return false;
	char order = 's';
 for(int i = 0;i<count;i++){
           printf("%d ",arr[i]);
           }

bool flag = true;
          int bad_level=0;
	  if(count==currCount-1){
	   bad_level=1;
	  }
          for(int i = 0;i<count-1;i++){
           if((arr[i]-arr[i+1]) >= 1 && (arr[i]-arr[i+1])<=3){
              if(order=='i'){
		 if(bad_level==0){
		  bad_level=1;
		  int *arr1 = createNewArray(arr,i,count);
		  int *arr2 = createNewArray(arr,i+1,count);
                  if(i>0){
	          int *arr3 = createNewArray(arr,i-1,count);
		  if((isSafe(arr1,count-1,currCount) || isSafe(arr2,count-1,currCount) || isSafe(arr3,count-1,currCount))){
				return true;	  
				  }
		  else{
		  return false;
		  }
		  }else{
		  if((isSafe(arr1,count-1,currCount) || isSafe(arr2,count-1,currCount))){
                               return true;

                 }
                 else{
                 return false;
                 }

		  
		  }
		  }
		 else{
                 flag=false;
		 }
              }
              order='d';

           }else if((arr[i+1]-arr[i]) >= 1 && (arr[i+1]-arr[i])<=3){
              if(order=='d'){
		 if(bad_level==0){
	         bad_level=1;
		 int *arr1 = createNewArray(arr,i,count);
                  int *arr2 = createNewArray(arr,i+1,count);
                     if(i>0){
                  int *arr3 = createNewArray(arr,i-1,count);
                  if((isSafe(arr1,count-1,currCount) || isSafe(arr2,count-1,currCount) || isSafe(arr3,count-1,currCount))){
                                return true;
                                  }
                  else{
                  return false;
                  }
                  }else{
                  if((isSafe(arr1,count-1,currCount) || isSafe(arr2,count-1,currCount))){
                               return true;

                 }
                 else{
                 return false;
                 }


                  }
 

		  }
		  else{
                 flag=false;
		 }
              }
              order='i';


           }else
	   
             if(bad_level==0){
                 bad_level=1;
                 int *arr1 = createNewArray(arr,i,count);
                  int *arr2 = createNewArray(arr,i+1,count);
                 if(i>0){
                  int *arr3 = createNewArray(arr,i-1,count);
                  if((isSafe(arr1,count-1,currCount) || isSafe(arr2,count-1,currCount) || isSafe(arr3,count-1,currCount))){
                                return true;
                                  }
                  else{
                  return false;
                  }
                  }else{
                  if((isSafe(arr1,count-1,currCount) || isSafe(arr2,count-1,currCount))){
                               return true;

                 }
                 else{
                 return false;
                 }


                  }
     
	     }
                  else{
                 flag=false;
                 }
	   
	   
	   
	   



	   
          }
	  return flag;

}

int *createNewArray(int arr[],int k, int count){
	int *arr2 = (int *) malloc(100*sizeof (int));
	int s = 0;
	for(int i = 0;i<count && i+s<count;i++){
	 if(i!=k){
	   arr2[i]=arr[i+s];
	 }else{
          s=1;
	  arr2[i] = arr[i+s];
	   
	 }
	
	}
	return arr2;

}
