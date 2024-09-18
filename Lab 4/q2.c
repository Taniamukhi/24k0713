#include <stdio.h>

 int main()

{

   int operand1;
   printf("Enter operand1:");
   scanf(" %d", &operand1);

  int operand2;
   printf("Enter operand2:");
   scanf(" %d", &operand2);

   char operator;
   printf("Enter operator(+,-,*,/)\n");
   scanf("  %c", &operator);
   
   int result;

   switch(operator){

        case '+':
                result= operand1 + operand2; 
                printf(" %d + %d = %d ", operand1, operand2, result);
                break;

       
        case '-':
         
               result= operand1 - operand2;
               printf(" %d - %d = %d ", operand1, operand2, result);
                break;

       
        case '*':
         
                result= operand1 * operand2;
                printf(" %d * %d = %d ", operand1, operand2, result);
                break;

      
        case '/':

               result= operand1 / operand2;
               printf(" %d / %d = %d ", operand1, operand2, result);
                break;

       default:
          
               printf("invalid operator");

}

      return 0;

}





       



   