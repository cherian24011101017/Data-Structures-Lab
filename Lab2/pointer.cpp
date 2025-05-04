#include<cstdio>
#include<cstdlib>
#include<cmath>

void palindrome(int* num){

   int* original = (int*)malloc(sizeof(int));
   int* reversed = (int*)malloc(sizeof(int));
   int* temp = (int*)malloc(sizeof(int));
   *original = *num;
   *reversed = 0;
   *temp = *num;
   while(*temp > 0)
   {
      *reversed = (*reversed * 10) + (*temp % 10);
      *temp /= 10;
   }
   if(*original == *reversed){

      free(original);
      free(reversed);
      free(temp);
      printf("\n%d is a palindrome", *num);
   }
   else{

      free(original);
      free(reversed);
      free(temp);
      printf("\n%d is not a palindrome", *num);
   }
}
void armstrongnumber(int* num){

   int* original = (int*)malloc(sizeof(int));
   int* sum = (int*)malloc(sizeof(int));
   int* temp = (int*)malloc(sizeof(int));
   int* digits = (int*)malloc(sizeof(int));
   *original = *num;
   *sum = 0;
   *temp = *num;
   *digits = 0;
   while (*temp > 0){

      *digits += 1;
      *temp /= 10;
   }
   *temp = *num;
   while(*temp > 0){

      *sum += pow(*temp  % 10 ,*digits);
      *temp /= 10;
   }
   if (*original == *sum){

      free(original);
      free(sum);
      free(temp);
      free(digits);
      printf("\n%d is an armstrong number", *num);
   }
   else{

      free(original);
      free(sum);
      free(temp);
      free(digits);
      printf("\n%d is not an armstrong number", *num);
   }
}
void perfectnumber(int* num){

   int* original = (int*)malloc(sizeof(int));
   int* sum = (int*)malloc(sizeof(int));
   int* i = (int*)malloc(sizeof(int));
   *original = *num;
   *sum = 0;
   for(*i = 1; *i <= (*original / 2) ;(*i)++){

      if((*original % *i) == 0 ){

         *sum += *i;
      }
   }
   if(*original == *sum){

      free(original);
      free(i);
      free(sum);
      printf("\n%d is a perfect number", *num);
   }
   else{

      free(original);
      free(i);
      free(sum);
      printf("\n%d is not a perfect number", *num);
   }
}
int main(){

   int* num = (int*)malloc(sizeof(int));
   int* option = (int*)malloc(sizeof(int));
   do{

      printf("\n1. Palindrome\n2. Armstrong Number\n3. Perfect Number\n4. Exit\nEnter 1, 2, 3 or 4: ");
      scanf("%d", &*option);
      switch (*option){

      case 1:

         printf("\nEnter the number to be checked: ");
         scanf("%d", &*num);
         palindrome(num);
         break;
      case 2:

         printf("\nEnter the number to be checked: ");
         scanf("%d", &*num);
         armstrongnumber(num);
         break;
      case 3:

         printf("\nEnter the number to be checked: ");
         scanf("%d", &*num);
         perfectnumber(num);
         break;
      }
   }
   while (*option != 4);
}
