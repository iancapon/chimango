#include "chimango.h"

typedef struct bp{
    char*type;
    int value;
} bp;
typedef struct bpList{
    bp*list;
    int len;
} bpList;

bpList BLINIT(){
    bpList x;
    x.list=(bp*)malloc(sizeof(bp));
    x.len=0;
    return x;
}

void pushBP(bpList*bindPowers,char*type,int value){
    bindPowers->list[bindPowers->len].type=type;
    bindPowers->list[bindPowers->len].value=value;
    bindPowers->list=(bp*)realloc(bindPowers->list,sizeof(bp)*(bindPowers->len+2));
    bindPowers->len+=1;
}

int bindPower(token x){
    bpList lookup=BLINIT();
    pushBP(&lookup,"()",0);
    pushBP(&lookup,"+-",1);
    pushBP(&lookup,"*/",2);////////////     QUIZAS TENGA QUE LIBERAR ESTO
    /////////
    int z=0;
    for(int i=0; i< 2; i++){
        if(strcmp(lookup.list[i].type,x.value)>0){
            z=lookup.list[i].value;
            break;
        }
    }
    free(lookup.list);
    return z;
}

void parser(TokenList*tokens){
    TokenList stack=TLINIT();
    TokenList output=TLINIT();
    for(int i=0; i< tokens->len;i++){
        if(strcmp(tokens->list[i].type,"expr")==0 || strcmp(tokens->list[i].type,"int")==0){
            push(&output,tokens->list[i]);
        }else{
            if(strcmp(tokens->list[i].type,"infOp")==0){
                if(bindPower(top(&stack)) <= bindPower(tokens->list[i])){
                    push(&stack,tokens->list[i]);
                }else {
                    while(bindPower(top(&stack)) > bindPower(tokens->list[i])){
                        push(&output,pop(&stack));
                    }
                    push(&stack,tokens->list[i]);
                }
            }
            else if(strcmp(tokens->list[i].type,"brack")==0){
                if(strcmp(tokens->list[i].value,"(")==0){
                    push(&stack,tokens->list[i]);
                }else if(strcmp(tokens->list[i].value,")")==0){
                    while(strcmp(top(&stack).value,"(")!=0){
                        push(&output,pop(&stack));
                    }
                    pop(&stack);
                    //freeToken(pop(&stack));
                    //freeToken(tokens->list[i]);
                }
            }
        }
    }
    while(stack.len>0){
        push(&output,pop(&stack));
    }
    free(stack.list);
    free(tokens->list);
    tokens->list=output.list;
    tokens->len=output.len;
}