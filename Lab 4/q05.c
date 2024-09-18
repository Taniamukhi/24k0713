#include<stdio.h>
int main(){
	int customer_id,units,net_amount;
	float charges,surcharge,elec_bill;
	char name[20];
	printf("Customer ID=");
	scanf("%d", &customer_id);
	printf("Enter Name=");
	scanf("%s", &name);
	printf("Enter units consumed=");
	scanf("%d", &units);
	if(units<=199)
	{
		charges=16.0;
		elec_bill=units*charges;
	}
	else if(units>=200&&units<300)
	{
		charges=20.10;
		elec_bill=units*charges;
	}
	else if(units>=300&&units<500)
	{
		charges=27.10;
		elec_bill=units*charges;
	}
	else
	{
		charges=35.90;
		elec_bill=units*charges;
	}
	if(elec_bill>1800)
	{
		surcharge=elec_bill*0.15;
		
	}
          net_amount=elec_bill+surcharge;
	printf("Amount Charges @Rs%f per unit=%f\n",charges,elec_bill);
	printf("Surcharge Amount=%f\n",surcharge);
	
	printf("Net Amount paid by the customer=%d\n",net_amount);
} 