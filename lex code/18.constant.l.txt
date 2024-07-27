digit [0-9]+(\.[0-9]+)?
%{
int cons=0;
%}
%%
{digit}+ { cons++; printf("%s is a constant\n", yytext);  }
.|\n { }
%%
int yywrap(void) {
return 1; }
int main(void)
{
extern FILE *yyin, *yyout; 
yyin=fopen("constant.txt", "r");
yylex();
printf("Number of Constants : %d\n", cons);
fclose(yyin);  
}
