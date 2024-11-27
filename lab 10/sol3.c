#include <stdio.h>

#define Max_temperature 30.0

void checktemperature(float temperature){
	 static int exceedcount =0.00;
	 
	 if(temperature>Max_temperature){
	 	exceedcount++;
	 	printf("The temperatur %.2f has exceeded the limit!!", temperature);
	 	
	 }
	 else 
	   printf("The temperature %.2f is within the limit!!", temperature);
	   
	   
	printf("\n\nThe limit has been exceeded %d times!!", exceedcount);
}
	 
int main(){
    float  temperature;
	char choice;
	
	do{
	printf("Enter the temperature : ");
	scanf("%f", &temperature);
	
	checktemperature(temperature);
	
	printf("\n\nDo you to continue to check temperature: ");
	scanf(" %c", &choice);
	
     }while(choice== 'y' || choice=='Y');
	
}

