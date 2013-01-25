%{
    #include <stdio.h>
    #include <assert.h>
    #include <stdlib.h>
    #include "Parser.tab.h"
    #include "Symbol.h"

    char * yytext;
    int line_count=1;
%}

%%
do	{ return (DO);		}
else	{ return (ELSE);	}
for	{ return (FOR);		}
if	{ return (IF);		}
int	{ return (INT);		}
float	{ return (FLOAT);	}
return	{ return (RETURN);	}
void	{ return (VOID);	}
while	{ return (WHILE);	}
print   { return (PRINT);	}
main	{ return (MAIN);	}

[a-zA-Z]+[a-zA-Z0-9]* { 
			int tmp= lookUp(yytext);
			if(tmp==-1){
				symbols[symbolctr].name= (char * )strdup(yytext);		
				tmp=symbolctr;
				++symbolctr;
			}
			yylval=tmp;			
			return (IDENTIFIER); 
		      }
[0-9]+	{  
		symbols[symbolctr].name=(char *)strdup(yytext); 
		symbols[symbolctr].type=(INT);
		sscanf(yytext,"%d",&symbols[symbolctr].ivalue);
		symbols[symbolctr].symboltype = (CONST);
		symbols[symbolctr].decleared = 1;
		yylval=symbolctr;
		++symbolctr;
		return (INTVALUE); 
	}
[0-9]+"."[0-9]+ {  
		symbols[symbolctr].name=(char *)strdup(yytext); 
		symbols[symbolctr].type=(FLOAT);
		sscanf(yytext,"%f",&symbols[symbolctr].fvalue);
		symbols[symbolctr].symboltype = (CONST);
		symbols[symbolctr].decleared = 1;
		yylval=symbolctr;
		++symbolctr;
		return (FLOATVALUE); 
	}

"=="	{ return	(EQ);	}
">="	{ return	(GRE);	}
"<="	{ return	(LSE);	}
"!="	{ return	(NE);	}
"||"	{ return	(OR);	}
"&&"	{ return	(AND);	}

","	{ return	',';	}
"="	{ return	'=';	}
"<"	{ return	'<';	}
">"	{ return	'>';	}
"+"	{ return	'+';	}
"-"	{ return	'-';	}
"*"	{ return	'*';	}
"/"	{ return	'/';	}
";"	{ return	';';	}
"("	{ return	'(';	}
")"	{ return	')';	}
"{"	{ return	'{';	}
"}"	{ return	'}';	}
"["	{ return	'[';	}
"]"	{ return	']';	}


"\n"	{ line_count++;	}
"/*"	{
		char ch;
		for ( ; (ch=input())>0 ; ){
		    	if( ch=='*' ){
		    		ch=input();
		    		if(ch=='/' || ch==-1 ){
		    			break;
		    		}
		    		if(ch=='\n')line_count++;	
		    	}
		    	else if(ch=='\n')line_count++;
		}
	}
"//"	{
		char ch;
		for ( ; (ch=input())>0 ; ){
			if(ch=='\n'){
				line_count++;
				break;
			}
		}	
	}	
[ \t]	{ ; }
. 	{	printf("Bad token %s \n",yytext);  }

%%

