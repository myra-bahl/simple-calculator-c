#include <stdio.h>
#include <stdlib.h>

void display_menu(void) {
    printf("\n===== SIMPLE CALCULATOR =====\n");
    printf("1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division (/)\n5. Modulus (%%)\n6. Exit\n");
    printf("==============================\nEnter your choice: ");
}

float get_number(const char *prompt) { float n; printf("%s", prompt); scanf("%f", &n); return n; }
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { if (b==0){printf("Error: Cannot divide by zero!\n");return 0;} return a/b; }
int modulus(int a, int b) { if (b==0){printf("Error: Cannot perform modulus with zero!\n");return 0;} return a%b; }

int main() {
    int choice; float num1, num2, result; int running = 1;
    printf("Welcome to Simple Calculator!\n");
    while (running) {
        display_menu(); scanf("%d", &choice);
        if (choice==6){printf("\nGoodbye!\n");running=0;continue;}
        if (choice<1||choice>5){printf("\nInvalid choice!\n");continue;}
        num1=get_number("Enter first number: "); num2=get_number("Enter second number: ");
        switch(choice){
            case 1: result=add(num1,num2); printf("\nResult: %.2f + %.2f = %.2f\n",num1,num2,result); break;
            case 2: result=subtract(num1,num2); printf("\nResult: %.2f - %.2f = %.2f\n",num1,num2,result); break;
            case 3: result=multiply(num1,num2); printf("\nResult: %.2f * %.2f = %.2f\n",num1,num2,result); break;
            case 4: result=divide(num1,num2); if(num2!=0) printf("\nResult: %.2f / %.2f = %.2f\n",num1,num2,result); break;
            case 5: printf("\nResult: %d %% %d = %d\n",(int)num1,(int)num2,modulus((int)num1,(int)num2)); break;
        }
    }
    return 0;
}
