#include<stdio.h>
int main(){
	float actual_amount,saved_amount,discounted_amount,discount;
	printf("Enter your total shopping bill: ");
	scanf("%f", &actual_amount);
	if (actual_amount <2000 && actual_amount >500){
		{discount = (actual_amount*5) /100;
		printf("Discounted amount: %.2f\n",discount);
		}{discounted_amount = actual_amount - discount;
		printf("The discounted amount after discount is: %.2f\n", discounted_amount);}	
}
	else if (actual_amount <4000 && actual_amount >=2000){
		{discount = (actual_amount*10) /100;
		printf("Discounted amount: %.2f\n",discount);}
		{discounted_amount = actual_amount - discount;
		printf("The discounted amount after discount is: %.2f\n", discounted_amount);}	
}
	else if (actual_amount <6000 && actual_amount >=4000){
		{discount = (actual_amount*20) /100;
		printf("Discounted amount: %.2f\n",discount);}
		{discounted_amount = actual_amount - discount;
		printf("The discounted amount after discount is: %.2f\n", discounted_amount);}		
}
	else if (actual_amount >=6000){
		{discount = (actual_amount*35) /100;
		printf("Discounted amount: %.2f\n",discount);}
		{discounted_amount = actual_amount - discount;
		printf("The discounted amount after discount is: %.2f\n", discounted_amount);}		
}
    else
    {printf("TRY AGAIN");
	}
}
