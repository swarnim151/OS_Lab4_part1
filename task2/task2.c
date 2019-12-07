#include <stdio.h>
#include <stdlib.h>

typedef int (*Operation) (int a, int b);
int add (int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main (void)
{
	Operation operator[4];
	char operation[10];
  int operation_num;
	
	operator[0] = &add;
	operator[1] = &subtract;
	operator[2] = &multiply;
	operator[3] = &divide;
  
  int a = 6;
  int b = 3;
  int result;
  
  while(1){
    printf("Operand 'a' : %d | Operand 'b' : %d Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3: divide | 4 : exit):", 
           a, b);
    scanf("%s", operation);
    operation_num = atoi(operation);
    while (operation_num > 4) {
      printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3: divide | 4 : exit):");
      scanf("%s", operation); 
      operation_num = atoi(operation);
    }
		if (operation_num == 4){
			printf("Quit Program.\n");
			break;
		}
		result = (*operator[operation_num])(a, b);
		printf("x = %d\n", result);
	}
	return 0;
}

int add (int a, int b) { 
  printf ("Adding 'a' and 'b'\n"); 
  return a + b; 
}

int subtract (int a, int b) { 
  printf ("Subtracting 'b' from 'a'\n"); 
  return a - b; 
}

int multiply (int a, int b) { 
  printf ("Multiplying 'a' and 'b'\n"); 
  return a * b; 
}

int divide (int a, int b) { 
  printf ("Dividing 'a' by 'b'\n"); 
  return a / b; 
}