//clock angle

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float clock_angle(int hour, int min){
	
	if(hour<0 || hour>12 || min<0 || min>60){	
		printf("Invalid Input\n");
		return -1;
	}

	//how much hour hand has moved from 0 degree
	float hr=hour*30 + min*0.5; //since in 1 min hour hand moves 0.5 degree
	float mn=min*6;

	float result=fabs(hr-mn);
	if (result>180){
		result=(360-result);
	}

	return result;
}

//bonus que
float min_sec_angle(int hour,int min,int sec){
	if(hour>12 ||hour<0 || min>60 || min<0 || sec<0 ||sec >60){
		printf("Invalid Input\n");
		return -1;
	}

	float hr=hour*30 + 0.5*min + (1/120)*sec;
	float mn=6*min + 0.1*sec;
	float sc= 6*sec;

	float result=fabs(mn-sc);
	if(result>180){
		result=360-result;
	}  

	return result;
}

void main(int argc, char *argv[]){
	int hour=atoi(argv[1]);
	int min=atoi(argv[2]);
	int sec=atoi(argv[3]);
	float angle = clock_angle(hour,min);
	printf("%.2f\n",angle);
	float min_sec=min_sec_angle(hour,min,sec);
	printf("%.2f\n",min_sec);
}



