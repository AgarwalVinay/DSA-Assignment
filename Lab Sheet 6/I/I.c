#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[5000005];
int st=-1;

typedef struct node{
    char data;
    struct node* left , *right;
}node;

void print(node * root){
    if(root){
        if(!(root->data>='0' && root->data<='9')){
        printf("(");
        print(root->left);
        printf("%c",root->data);
        print(root->right);
        printf(")");
        }
        else{
        print(root->left);
        printf("%c",root->data);
        print(root->right);
    }
    }
    
}

int evaluate(node * root){
    if(root){
        int res;
        int l = evaluate(root->left);
        int r =evaluate(root->right);

        if (root->data =='+') res = l+r;
        else if (root->data =='*') res = l*r;
        else if (root->data =='/') res = l/r;
        else if (root->data =='-') res = l-r;
        else res =(root->data) -'0';
        return res;
    }
    return 0;
}

int main(){
    scanf("%s",s);
    node * stack[50000];
    node * root = NULL;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0' && s[i]<='9'){
            node * newnode= (node*) malloc(sizeof(node));
            newnode->data =s[i];
            newnode->left = NULL;
            newnode->right =NULL;
            stack[++st] = newnode;
        }
        else{
            node *newnode =(node*) malloc(sizeof(node));
            newnode->data =s[i];
            newnode->right = stack[st--];
            newnode->left = stack[st--];
            stack[++st] = newnode;
        }
    }
    root =stack[0];
    printf("%d\n",evaluate(root));
    print(root);
    return 0;
}