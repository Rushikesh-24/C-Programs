#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAX 50
char infix[MAX];
char postfix[MAX];
char stack[MAX];
long int lstack[MAX];
float fstack[MAX];
int top= -1;

int IsFull(){
    return top==MAX-1;
}
int IsEmpty(){
    return top== -1;
}
void Push(char savepoint){
    if(IsFull()){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=savepoint;
}
char Pop(){
    if(IsEmpty()){
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}
char Peek(){
    if(IsEmpty()){
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top];
}
void PreDisplay(char symbol,char postfix[],int k){
    printf("%-10c",symbol);
    for(int i=0;i<=top;i++)
        printf("%c",stack[i]);
    printf("\t\t");
    for(int i=0;i<k;i++)
        printf("%c",postfix[i]);
    printf("\n");
}
int WhiteSpace(char symbol){
    return symbol==' ' || symbol=='\t';
}

int InstackPriority(char ch){
    switch(ch){
        case '^':
        return 3;
        case '*':case '/':case '%':
        return 2;
        case '+':case '-':
        return 1;
        default:
        return 0;
    }
}
int SymbolPriority(char ch){
    switch(ch){
        case '^':
        return 4;
        case '*':case '/':case '%':
        return 2;
        case '+':case '-':
        return 1;
        default:
        return 0;
    }
}
void InfixToPostfix() {
    int k=0;
    char symbol,next;
    printf("Symbol\tStack\t\tPostfix\n");
    for(int i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(!WhiteSpace(symbol)){
            switch(symbol){
                case '(':
                Push(symbol); 
                break;
                case ')':
                while((next=Pop())!='(')
                    postfix[k++]=next;
                break;
                case '+':case '-':case '*':case '/':case '%':case '^':
                    while (top!= -1 && SymbolPriority(Peek())>=InstackPriority(symbol))
                        postfix[k++]=Pop();
                    Push(symbol);
                    break;
                default: 
                    postfix[k++]=symbol;
            }
            PreDisplay(symbol,postfix,k);
        }
    }
    while(top!= -1){
        postfix[k++]=Pop();
        PreDisplay(' ',postfix,k);
    }
    postfix[k]='\0';
}
void DisplayEvaluation(char ch,int top) {
    printf("%-10c",ch);
    for(int i=0;i<=top;i++)
        printf("%ld,",lstack[i]);
    if(top>=2)
        printf("\t\t");
    else
        printf("\t\t\t");
    for(int i=0;i<=top;i++)
        printf("%.2f,",fstack[i]);
    printf("\n");
}
void Collecting() {
    int uchars[256]={0}; 
    char ch;
    int val;
    for(int i=0;i<strlen(postfix);i++) {
        ch=postfix[i];
        if(isalpha(ch) && !uchars[(unsigned char)ch]){
            printf("Enter the value of %c: ",ch);
            scanf("%d",&val);
            uchars[(unsigned char)ch]=val;
        }
    }
    for(int i=0;i<strlen(postfix);i++) {  
        ch=postfix[i];
        if(isalpha(ch)){ 
            lstack[i] = uchars[(unsigned char)ch];
            fstack[i] = (float)uchars[(unsigned char)ch];
        }
    } 
}
void Evaluation() {
    top=-1;
    char ch;
    int a,b;
    float fa, fb;
    printf("Symbol\tLong Int Stack\t\tFloat Stack\n");
    for(int i=0;i<strlen(postfix);i++) {
        ch=postfix[i];
        if(isalpha(ch)){
            lstack[++top]=lstack[i];
            fstack[top]=fstack[i];
        }
        else{
            a=lstack[top--];
            b=lstack[top--];
            fb=fstack[top+1];
            fa=fstack[top+2];
            switch(ch){
                case '+':
                    lstack[++top]=a+b;
                    fstack[top]=(float)(fa+fb);
                    break;
                case '-':
                    lstack[++top]=a-b;
                    fstack[top]=(float)(fa-fa);
                    break;
                case '*':
                    lstack[++top]=a*b;
                    fstack[top]=(float)(fa*fb);
                    break;
                case '/':
                    lstack[++top]=a/b;
                    fstack[top]=(float)fa/fb;
                    break;
                case '%':
                    lstack[++top]=a%b;
                    fstack[top]=(float)(a%b);
                    break;
                case '^':
                    lstack[++top]=(int)pow(a,b);
                    fstack[top]=(float)pow(fa,fb);
                    break;
            }
        }
        DisplayEvaluation(ch,top);
    }
    printf("Final Result:Long int: %ld,Float: %.2f\n", lstack[top], fstack[top]);
}
int main() {
    printf("Enter Infix Expression: ");
    scanf("%s",infix);
    InfixToPostfix();
    printf("\nThe Postfix Expression is: %s\n", postfix);
    Collecting();
    Evaluation();
}