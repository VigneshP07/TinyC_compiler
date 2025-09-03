#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.yy.c"

int yywrap(){
    return 1;
}

typedef struct _node{
    char *token;
    char *lexeme;
    //int value;
    struct _node *next;
}node;
typedef node *symboltable;

symboltable addtotbl(symboltable T,char* tok,char *id){
    symboltable p=T;
    while(p!=NULL){
        if(strcmp(p->token,tok)==0 && strcmp(p->lexeme,id)==0){
            //p->value++;
            return T;
        }
        p=p->next;
    }
    symboltable newnode=NULL;
    newnode=(node*)malloc(sizeof(node));
    int n=strlen(tok);
    newnode->token=(char*)malloc((n+1)*sizeof(char));
    strcpy(newnode->token,tok);
    n=strlen(id);
    newnode->lexeme=(char*)malloc((n+1)*sizeof(char));
    strcpy(newnode->lexeme,id);
    //newnode->value=1;
    newnode->next=NULL;
    if(T==NULL){
        T=newnode;
    }
    else{
        p=T;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newnode;
    }
    return T;
}

void printtbl(symboltable T){
    symboltable p=T;
    while(p!=NULL){
        printf("    %s  ( %s )\n",p->lexeme,p->token);
        p=p->next;
    }
}

int main(){
    int nextok;
    symboltable stream=NULL;
    char* Tokens[5]={"Keyword","Identifier","Constant","String-Literal","Punctuator"};
    while((nextok=yylex())){
        switch(nextok){
            case KEYWORD:
                printf("<Keyword , %s >\n",yytext);
                stream=addtotbl(stream,Tokens[0],yytext);
                break;
            case IDENTIFIER:
                printf("<Identifier , %s >\n",yytext);
                stream=addtotbl(stream,Tokens[1],yytext);
                break;
            case INTCONST:
                printf("<Integer Constant , %s >\n",yytext);
                stream=addtotbl(stream,Tokens[2],yytext);
                break;
            case FLOATCONST:
                printf("<Floating Constant , %s >\n",yytext);
                stream=addtotbl(stream,Tokens[2],yytext);
                break;
            case CHARCONST:
                printf("<Character Constant , %s >\n",yytext);
                stream=addtotbl(stream,Tokens[2],yytext);
                break;
            case STR_LITERAL:
                printf("<String Literal , %s >\n",yytext);
                stream=addtotbl(stream,Tokens[3],yytext);
                break;
            case PUNCT:
                printf("<Punctuator , %s >\n",yytext);
                stream=addtotbl(stream,Tokens[4],yytext);
                break;
            case SINGCOMM:
                printf(" Single Line Comment => %s \n",yytext);
                break;
            case MULTCOMM:
                printf(" Multi Line Comment => %s \n",yytext);
                break;
            default:
                printf("<Invalid token , %s >\n",yytext);
                exit(0);
                break;
        }
    }
    printf("\n\n");
    if(stream!=NULL){
        printf("Symbol Table:\n");
        printtbl(stream);
    }
    else{
        printf("Symbol Table is empty./n");
    }    
    return 0;
}