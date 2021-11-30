//nth fibonacci number
#include<stdio.h>
#include<stdlib.h>

long int fibonacci1(int n){
	long int fibnumbers[100];
	fibnumbers[0]=0;
	fibnumbers[1]=1;

	int i;
	for(i=2;i<=n;i++){
		fibnumbers[i]=fibnumbers[i-1]+fibnumbers[i-2];
	}

	return fibnumbers[n];
}

//bonus que
int fibeven(int n){
	int fibeven[100];
	int fib[10000];
	fib[0]=0;fib[1]=1;
	fibeven[0]=0;
	int i=1,j=2;

	while(i<=n){
		fib[j]=fib[j-1]+fib[j-2];
		if(fib[j]%2==0){
			fibeven[i]=fib[j];
			i++;
		}
		j++;
	}

	return fibeven[n];
}


void main(){
	//fibnumbers[0]=0;
	//fibnumbers[1]=1;
	printf("%ld\n",fibonacci1(13));
	printf("%ld\n",fibonacci1(21));
	printf("%ld\n",fibonacci1(31));
	printf("%ld\n",fibonacci1(47));
	printf("%ld\n",fibonacci1(61));
	printf("%ld\n",fibonacci1(85));

	//bonus
	printf("output for fibEven\n");
	printf("n=3->%d\n",fibeven(3));
	printf("n=10->%d\n",fibeven(10));
	//printf("%d\n",fibeven(22));
	//printf("%d\n",fibeven(26));

}