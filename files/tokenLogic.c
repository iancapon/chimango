#include "chimango.h"

TokenList TLINIT(){
    TokenList x;
    x.list=(token*)malloc(sizeof(token));
    x.len=0;
    return x;
}

void push(TokenList*tokens,token x){
    tokens->list[tokens->len].type=x.type;
    tokens->list[tokens->len].value=x.value;
    tokens->list=(token*)realloc(tokens->list,sizeof(token)*(tokens->len+2));
    tokens->len+=1;
}

void pushTokenWithValues(TokenList*tokens,char*type,char*value){
    tokens->list[tokens->len].type=type;
    tokens->list[tokens->len].value=reproduceString(value);
    tokens->list=(token*)realloc(tokens->list,sizeof(token)*(tokens->len+2));
    tokens->len+=1;
}

token pop(TokenList*tokens){
    token z;
    if(tokens->len>0){
        z=tokens->list[tokens->len-1];
        tokens->list=(token*)realloc(tokens->list,sizeof(token)*(tokens->len));
        tokens->len-=1;
    }else{
        z.type="Null";
        z.value="Null";
    }
    return z;
}

token top(TokenList*tokens){
    token z;
    if(tokens->len>0){
        z=tokens->list[tokens->len-1];
    }else{
        z.type="Null";
        z.value="Null";
    }
    return z;
}

void freeTokenInnerValues(token x){
    free(x.type);
    free(x.value);
}

void printToken(token x){
    printf("[%s:%s]",x.type,x.value);
}

char*reproduceString(char*word){
    int l=strlen(word);
    char*x=(char*)malloc(sizeof(char)*(l+1));
    for(int i=0; i< l;i++){
        x[i]=word[i];
    }
    x[l]=0;
    return x;
}