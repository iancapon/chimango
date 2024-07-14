#include "chimango.h"

char*tokenType(char*value){
    if(strrchr("+-*/",value[0])){
        return "infOp";
    }else if(strrchr("0123456789",value[0])){
        return "int";
    }
    else if(strrchr(" ",value[0])){
        return "space";
    }
    else if(strrchr("()",value[0])){
        return "brack";/// parentes
    }
    return "expr";
}

char charType(char value){
    if(strrchr("+-*/",value)){
        return 'o';////inf op
    }else if(strrchr("0123456789",value)){
        return 'i';//// int
    }
    else if(strrchr(" ",value)){
        return 's';//// space
    }
    else if(strrchr("()",value)){
        return 'b';/// parentes
    }
    else if(strrchr("\n",value)){
        return 'n';/// newline
    }
    return 'e'; ///// expr
}

void lexer(char*text,TokenList*tokens){
    char*word=(char*)malloc(sizeof(char)*2);
    int wl=0;
    //word[wl]=text[0];
    for(int i=0; i< strlen(text)+1; i++){
        if(text[i]!=' ' && text[i]!='\0' ){
            word[wl]=text[i];
            word[wl+1]='\0';
            word=(char*)realloc(word,sizeof(char)*(wl+2));
            wl+=1;
        }
        else{
            pushTokenWithValues(tokens,tokenType(word),word);
            wl=0;
        }
    }
    free(word);
}