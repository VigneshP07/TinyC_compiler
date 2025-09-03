#include<stdio.h>
#include"y.tab.c"

void yyerror(char *s) {
    printf("Error: %s\n",s);
}

TreeNode* createNode(char* name,char* val,int n,TreeNode** child){
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    newnode->name=strdup(name);
    newnode->val=strdup(val);
    newnode->n_child=n;
    newnode->child_nodes=(TreeNode**)malloc(sizeof(TreeNode*)*n);
    int i;
    for(i=0;i<n;i++){
        newnode->child_nodes[i]=child[i];
    }
    return newnode;
}

void printTree(TreeNode* root,int h){
    int i;
    for(i=0;i<h;i++){
        printf("    ");
    }
    printf("%s\n",root->name);
    for(i=0;i<root->n_child;i++){
        printTree(root->child_nodes[i],h+1);
    }
}

int main(){
    printf("Parse actions: \n");
    if(yyparse()==0){
        printf("\n\n-----------------------------------------------Parsing successfull-----------------------------------------------\n");
        printf("Parse Tree:\n");
        printTree(root,0);
    }
    else{
        printf("\n\n--------------------------------------------------Parsing failed-------------------------------------------------\n");
    }
    return 0;
}