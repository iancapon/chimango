#include "files/chimango.h"

char*readInput(){
    char c=getchar();
    char*text=(char*)malloc(sizeof(char)*2);
    int len=0;
    while(c!='\n'){
        text[len]=c;
        text[len+1]='\0';
        text=(char*)realloc(text,sizeof(char)*(len+2));
        c=getchar();
        len+=1;
    }
    return text;
}

int main(){
    printf("CALCULADORA SIMPLE, PONER ESPACIO ENTRE C/ TÉRMINO:\n");
    printf("> ");
    char*text=readInput();
    while(text[0]!=27){//// ESC
        TokenList tree=TLINIT();
        lexer(text,&tree);
        parser(&tree);
        printf("= %d",run(&tree));
        printf("\n> ");
        text=readInput();
    }
    return 0;
}