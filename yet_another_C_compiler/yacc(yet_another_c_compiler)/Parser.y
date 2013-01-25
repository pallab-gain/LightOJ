%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <assert.h>	
  #include "Symbol.h"
  extern char*	yytext;
  extern int line_count;


  void yyerror(const char *str){
        fprintf(stderr,"%s at line no %d\n",str,line_count);
        fprintf(stderr,"LAST TOKEN [ %s ]\n",yytext);
  }
%}

%token INTVALUE FLOATVALUE
%token IDENTIFIER
%token DO ELSE FLOAT FOR IF INT RETURN VOID WHILE FUN CONST STRING PRINT MAIN
%token EQ GRE LSE NE OR AND
%left '>' '<' '=' NE EQ GRE LSE OR AND
%left '+' '-'
%left '*' '/' '%' 


%%
prog:
	stmnt prog 
	| stmnt		
	;
stmnt:
	inline_declr	/*line 34*/
	| function_declr /* function declear korber por, then function'er scope ses hoile sob variable undeclear kore dibo */
			/* #line 93 */
	;
inline_declr:
	';'
	| type IDS ';'	{ add_type_details(); }
 	| assign_op ';'  
	| PRINT '(' Expression ')' ';' {		
		fprintf(asm_body_commands,"\t\tpush dword [_v_%s_lev%d",symbols[$3].name,$3);
		if(symbols[$3].type==INT){
			fprintf(asm_body_commands,"]\n\t\tpush dword fmtInt \t;print integer\n");
			fprintf(asm_body_commands,"\t\tcall printf\n\t\tadd esp, 8\n");
		}
		else{
			fprintf(asm_body_commands," +4]\n\t\tpush dword fmtFlo \t;print float\n");
			fprintf(asm_body_commands,"\t\tcall printf\n\t\tadd esp, 15\n");
		}

		fprintf(asm_body_commands,"\t\tpush dword _newline\n\t\tpush dword fmtStr\n\t\tcall printf\n\t\tadd esp, 8\n\n");
	}
	;
type:
	INT { $$=INT;setType(INT); }
	| FLOAT	{ $$=FLOAT;setType(FLOAT); }
	| STRING { $$=STRING;setType(STRING); }
	;
IDS:
	IDENTIFIER	{ 
		addList($1); 
	}
	| IDENTIFIER ',' IDS 	{ 
		addList($1); 
	}
	;
assign_op:
	IDENTIFIERLIST '=' Expression{
		checktype($1,$3);
		add_assign_details(); 
		$$=$3;
	}
	;
IDENTIFIERLIST:
	IDENTIFIERLIST	'=' IDENTIFIER {
		checktype($1,$3);
		addList1($3);
		$$=$3;
	}
	| IDENTIFIER {
		$$=$1; addList1($1); 
	}
	;	
	
Expression:
	| '(' Expression ')'		{ $$=add_symbol1($2,$2,'=');addList1($$); }
	| Expression '+' Expression 	{ checktype($1,$3); $$=add_symbol1($1,$3,'+');addList1($$); }
	| Expression '-' Expression 	{ checktype($1,$3); $$=add_symbol1($1,$3,'-');addList1($$); }
	| Expression '*' Expression 	{ checktype($1,$3); $$=add_symbol1($1,$3,'*');addList1($$); }
	| Expression '/' Expression 	{ checktype($1,$3); $$=add_symbol1($1,$3,'/');addList1($$); }
	| Expression '%' Expression 	{ checktype($1,$3); $$=add_symbol1($1,$3,'%');addList1($$); }				
	| Expression '>' Expression 	{ checktype($1,$3); $$=add_symbol1($1,$3,'>');addList1($$); }
	| Expression '<' Expression 	{ checktype($1,$3); $$=add_symbol1($1,$3,'<');addList1($$); }
	| Expression EQ Expression 	{ checktype($1,$3); $$=add_symbol2($1,$3,EQ);addList1($$); }
	| Expression GRE Expression 	{ checktype($1,$3); $$=add_symbol2($1,$3,GRE);addList1($$); }
	| Expression LSE Expression 	{ checktype($1,$3); $$=add_symbol2($1,$3,LSE);addList1($$); }
	| Expression NE Expression 	{ checktype($1,$3); $$=add_symbol2($1,$3,NE);addList1($$); }
	| Expression OR Expression 	{ checktype($1,$3); $$=add_symbol2($1,$3,OR);addList1($$); }
	| Expression AND Expression 	{ checktype($1,$3); $$=add_symbol2($1,$3,AND);addList1($$); }
	| INTVALUE	{ 
				addList($1);  $$=$1; 
				fprintf(asm_body_const,"_c_lev%d:\tdd\t%d ; integer\n",$1,symbols[$1].ivalue); 				
	}
	| FLOATVALUE	{ 
				addList($1);  $$=$1; 
				fprintf(asm_body_const,"_c_lev%d:\tdq\t%f ; float\n",$1,symbols[$1].fvalue); 				
	}
	| IDENTIFIER	{ 
			 addList1($1); $$=$1; 
	}
	| function_call	{ addList1($1); $$=$1; }
	;	

function_declr:
	type IDENTIFIER '(' param_list ')' '{' func_statement ret_stmnt  '}'	{
		if($1!=$8){
			printf("#. return type mitchmtch at line %d\n",line_count);
			exit(0);
		}
		add_function_details($2,$1);
		clearScope($2,$8);		
		
	}
	| VOID IDENTIFIER '(' param_list ')' '{' func_statement RETURN ';' '}' {
		add_function_details($2,(VOID));
		clearScope($2,$8);
	}
	| INT MAIN '(' VOID ')' '{' func_statement ret_stmnt  '}'	{

	}
	;
param_list:
	VOID	
	| type IDENTIFIER {	
		add_param_type($2,$1);
	}
	| type IDENTIFIER ',' param_list {
		add_param_type($2,$1);
	}	
	;			
func_statement:
	func_body
	| /*empty */
	;
func_body:
	body func_body 
	| body
 	;
body:
	inline_declr
	| commands	
	; 	
function_call:
	IDENTIFIER '(' ')' {
		check_valid($1);
	}
	| IDENTIFIER '(' params ')' {
		check_valid($1);
	}
	;
params:
	types ',' params {$$=$1; addParam($1);  }
	| types	{$$=$1; addParam($1); }
	;		
types:
	INTVALUE	{
		fprintf(asm_body_const,"_c_lev%d:\tdd\t%d ; integer\n",$1,symbols[$1].ivalue); 
		$$=$1;
	}
	| FLOATVALUE	{
		fprintf(asm_body_const,"_c_lev%d:\tdq\t%f ; float\n",$1,symbols[$1].fvalue); 	
		$$=$1;
	}
	| IDENTIFIER	{	
		$$=$1;		
	}
	;	
	
commands:
	IF '(' condition_stmnt ')' condition_body	{    }
	| IF '(' condition_stmnt ')' condition_body ELSE condition_body	{  }
	| WHILE '(' condition_stmnt ')' condition_body	{   }
	| DO condition_body WHILE '(' condition_stmnt ')' ';' {  }
	| FOR '(' condition_stmnt ';' condition_stmnt ';' condition_stmnt ')' condition_body { }
	;	
condition_stmnt:
	Expression	{ $$=$1;}
	| assign_op	{ $$=$1;}
	; 
condition_body:
	'{' func_body '}' 
	;		
 	
ret_stmnt:
	RETURN INTVALUE ';'	{ 
		fprintf(asm_body_const,"_c_lev%d:\tdd\t%d ; integer\n",$2,symbols[$2].ivalue); 
		$$=(INT);
	}
	| RETURN FLOATVALUE ';' {
		fprintf(asm_body_const,"_c_lev%d:\tdq\t%f ; float\n",$2,symbols[$2].fvalue); 
		$$=(FLOAT);
	}
	| RETURN IDENTIFIER ';' { 	
		$$=(symbols[$2].type);
	}
	| RETURN STRING ';'{$$=(STRING);}
	;
		
%% 
int main(){
	clearSymbol();
	#ifdef YYDEBUG
		//yydebug=1;
	#endif
	asm_body_var = fopen("body_var.in","w");
	asm_body_const = fopen("body_const.in","w");
	asm_body_commands = fopen("body_commands.in","w");
	int var = yyparse();
	printGreet(var);
	fprintf(asm_body_const,"_newline:\tdb \"\", 0Ah; string");
	fprintf(asm_body_const,"\n\n\t\tSECTION .bss\n");
	
	write_body_var();
	fprintf(asm_body_var,"\n\n\t\tSECTION .text\n\t\tglobal	main\n\t\textern\tprintf\nmain:\n\n\n");
	
	fclose(asm_body_var);
	fclose(asm_body_const);
	fclose(asm_body_commands);
	system("cat header.in body_const.in body_var.in body_commands.in footer.in > output.asm");
	return 0;
}
