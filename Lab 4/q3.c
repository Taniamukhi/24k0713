#include <stdio.h>

 int main()

{

   char character;
   printf("Enter character");
   scanf(" %c", &character);

   if(character>=65&&character<=90){

        printf("The character is capital alphabet");

}

        else if (character>=97&&character<=122)

{

       printf("The character is small alphabet");

}

       else if  (character>=32&&character<=47 || character>=58&&character<=64 || character>=91&&character<=96)

{

      printf("The character is special character");

}

       else if (character>=48&&character<=57)

{

       printf("The character is digit");

}

       else

          printf("Invalid character");

}
 
