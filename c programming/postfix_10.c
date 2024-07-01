#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

struct stack1{
    char arr[100];
    int top;
}*s1;
struct stack2
{
    float arr[100];
    int top;
}*s2;

int prec(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

char associ(char c) {
    if (c == '^')
        return 'R';
    return 'L';
}

void InfixToPostfix(char infix[], char postfix[]) {
    char c;
    int index = 0,l = strlen(infix), i;
    
    for (i = 0; i < l; i++) {
        c = infix[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix[index++] = c;
        } else if (c == '(') {
             s1->arr[++(s1->top)]= c;
        } else if (c == ')') {
            while (s1->top >= 0 && s1->arr[s1->top] != '(') {
                postfix[index++] = s1->arr[(s1->top)--];
            }
            (s1->top)--;
        } else {
            while (s1->top >= 0 && ((prec(c) < prec(s1->arr[s1->top])) || (prec(c) == prec(s1->arr[s1->top]) && associ(c) == 'L'))) {
                postfix[index++] = s1->arr[(s1->top)--];
            }
            s1->arr[++(s1->top)]= c;
        }
    }
    while (s1->top >= 0) {
        postfix[index++] = s1->arr[(s1->top)--];
    }
    postfix[index] = '\0';
    printf("%s\n", postfix);
}

void EvalPostfix(char postfix[]) {
    float  r, op1, op2;
    char c;
    int  i, l = strlen(postfix);
    for (i = 0; i < l; i++) {
        c = postfix[i];
        if (c >= '0' && c <= '9') {
            s2->arr[++(s2->top)] = c - '0';
        } else {
            op2 = s2->arr[(s2->top)--];
            op1 = s2->arr[(s2->top)--];
            switch (c) {
                case '+':
                    r = op1 + op2;
                    break;
                case '-':
                    r = op1 - op2;
                    break;
                case '*':
                    r = op1 * op2;
                    break;
                case '/':
                    if (op2 != 0)
                        r = op1 / op2;
                    break;
                 case '^':
                    r = pow(op1, op2);
                    break; 
            }
           s2->arr[++(s2->top)] = r;
        }
    }
    printf("The result is %f\n", s2->arr[s2->top--]);
}

int main() {
    int i;
    char infix[100], postfix[100];
    s1=(struct stack1*)malloc(sizeof(struct stack1));
    s1->top=-1;
    
    s2=(struct stack2*)malloc(sizeof(struct stack2));
    s2->top=-1;
    printf("\nEnter\n1: convert infix to postfix\n2: evaluation of postfix\n");
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d",&i);
        switch(i)
        {
            case 1:  printf("Enter the expression: ");
                     scanf("%s", infix);
                     InfixToPostfix(infix, postfix);
                     break;
            case 2:  printf("Enter the expression: ");
                     scanf("%s", infix);
                     InfixToPostfix(infix, postfix);
                     EvalPostfix(postfix);
                     break;
            default: printf("invalid choice\n");
                     free(s1);
                     free(s2);
                    return 0;
                     break;
        }
    }
    return 0;
}