#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct token{
    char*type;
    char*value;
} token;
typedef struct TokenList{
    token*list;
    int len;
} TokenList;

//////////////////// tokenLogic.c
TokenList TLINIT();
void push(TokenList*tokens,token x);
void pushTokenWithValues(TokenList*tokens,char*type,char*value);
token pop(TokenList*tokens);
token top(TokenList*tokens);
void freeTokenInnerValues(token x);
void printToken(token x);
char*reproduceString(char*word);

//////////////////// lexer.c
void lexer(char*text,TokenList*tokens);

//////////////////// parser.c
void parser(TokenList*tokens);

//////////////////// RunSimpleCalculator.c
int run(TokenList*tokens);