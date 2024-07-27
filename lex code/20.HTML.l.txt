%{
int tags;
%}
%%
"<"[^>]*>  { tags++; printf("%s \n", yytext); }
.|\n { }
%%
int yywrap(void) {
return 1; }
int main(void)
{
extern FILE *yyin, *yyout; 
yyin=fopen("tag.txt", "r");

yylex();
printf("\n Number of html tags: %d",tags);
fclose(yyin);  
}
