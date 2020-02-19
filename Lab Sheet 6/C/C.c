#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char expr[5000006] , S[5000006];
int top=-1;

int isOperand(char C){
    if(C >= '0' && C <= '9') return 1;
	if(C >= 'a' && C <= 'z') return 1;
	if(C >= 'A' && C <= 'Z') return 1;
	return 0;
}

int  isOperator(char C){
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '%') return 1;
	return 0;
}

int GetOperatorWeight(char op){
    if(op =='/' ||op =='*' || op =='%') return 2;
    if(op =='-' || op =='+') return 1;
}

int HasHigherPrecedence(char op1 , char op2){
    int w1 = GetOperatorWeight(op1);
    int w2 = GetOperatorWeight(op2);
    if(w1==w2) return 1;
    return w1>w2 ? 1:0;
}

int main(){
    gets(expr);
    for(int i=0;i<strlen(expr);i++){
        if(isOperator(expr[i])){
            while(top!=-1 && S[top] !='(' && HasHigherPrecedence(S[top] , expr[i]) ){
                printf("%c",S[top--]);
            }
            S[++top] = expr[i];
        }
        else if(isOperand(expr[i])) printf("%c",expr[i]);
        else if(expr[i]=='(') S[++top] = expr[i];
        else if(expr[i]==')'){
            while(top!=-1 && S[top]!='('){
                printf("%c",S[top--]);
            }
            top--;
        }
    }
    while(top!=-1) printf("%c",S[top--]);
    return 0;
}