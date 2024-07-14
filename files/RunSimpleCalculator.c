#include "chimango.h"

int compute(int x, int y, char*op){
    if(strcmp(op,"+")==0){
        return x+y;
    }
    else if(strcmp(op,"-")==0){
        return x-y;
    }
    else if(strcmp(op,"*")==0){
        return x*y;
    }
    else if(strcmp(op,"/")==0){
        if(y!=0){
            return x/y;
        }else{
            printf("\n∞ .. infinity\n");
        }
    }
    return 0;
}

int run(TokenList*tokens){
    int z=0;
    int*stack=(int*)malloc(sizeof(int));
    int l=0;
    for(int i=0; i< tokens->len;i++){
        if(strcmp(tokens->list[i].type,"int")==0){
            stack[l]=atoi(tokens->list[i].value);
            stack=(int*)realloc(stack,sizeof(int)*(l+2));
            l+=1;
        }else if(strcmp(tokens->list[i].type,"infOp")==0){
            stack[l-2]=compute(stack[l-2],stack[l-1],tokens->list[i].value);
            z=stack[l-2];
            stack=(int*)realloc(stack,sizeof(int)*(l-1));
            l-=1;
        }
    }
    free(stack);
    return z;
}