%{
int com=0;
%}
%s COMMENT
%%
"/*" {BEGIN COMMENT;}
<COMMENT>"*/" {BEGIN 0; com++;}
<COMMENT>\n {com++;}
<COMMENT>. {;}
\/\/.* {; com++;}
.|\n {fprintf(yyout,"%s",yytext);}
%%
void main(){
extern FILE *yyin, *yyout; 
yyin=fopen("commentin.txt", "r"); 
yyout=fopen("commentout.txt", "w"); 
yylex();
printf("\n number of comments are = %d\n",com);
}
int yywrap()
{
return 1;
}
