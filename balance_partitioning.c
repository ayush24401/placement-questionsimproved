#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int sumleft(int arr[],int k){
	int sum=0;
	for(int i=k-1;i>=0;i--){
		sum=sum+arr[i];
	}
	return sum;
}

int sumright(int arr[],int k,int size){
	int sum=0;
	for(int i=k+1;i<size;i++){
		sum=sum+arr[i];
	}
	return sum;
}
/*
//recursive approach
int balance_partition(int arr[],int size,int N,int min,int diff){
	
	if(min<diff){
		return N+2;
	}	

	int suml=sumleft(arr,N);
	int sumr=sumright(arr,N,size);

	int difference=suml-sumr;
	diff=abs(difference);
	if(diff<min){
		min=diff;
	}
	return balance_partition(arr,size,N-1,min,diff);
}
*/
//balanced partition optimal

int balance_part(int N){
	int a=4,d=2;
	int lastterm=4+N*2;
	int min=INT_MAX;
	int index;
	int totalsum=(N/2)*(4+lastterm);
	for(int i=1;i<=N;i++){
		int ithterm=4+(i*2); 
		int sumleft=((i/2)*(4+ithterm))-ithterm;
		int sumright=(totalsum-sumleft)-ithterm;
		int difference=abs(sumleft-sumright);
		if(difference<min){
			min=difference;
			index=i;
		}
//		if(index<i);
//			break;	
	}
	return index;
}



int v_part(int N){
	int a=4,d=2;
	int sumofNterms=(N/2)*(4*2 + 2*N+4);

	int min=sumofNterms;
	int index;
	
	for(int i=1;i<=N;i++){
		//int ithterm=4+(i*2); 
		int sumleft=(i/2)*(2*4+ (i-1)*2);
		int sumright=(N-i)/2 * (2 * (2*(i+1)+4) + 2*N+4);
		int difference=abs(sumright-sumleft);
		if(difference<min){
			min=sumright-sumleft;
			index=i;
		}
//		if(index<i);
//			break;	
	}
	return index;
}

void main(int argc, char *argv[]){
	int N = atoi(argv[1]);
	/*//creating the list
	int arr[1000];
	for(int i=0;i<N;i++){
		arr[i]=(2*i)+4;
		//printf(" %d",arr[i]);
	}
	*/
	//int partition=balance_partition(arr,N,N-1,INT_MAX,0);
	//printf("%d",partition);
	int opt=balance_part(N);
	printf("\n%d\n",opt);
	int vi=v_part(N);
	printf("%d",vi);
}
