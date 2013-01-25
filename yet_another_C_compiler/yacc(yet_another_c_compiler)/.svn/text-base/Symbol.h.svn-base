#include "Parser.tab.h"

FILE *asm_body_var;
FILE *asm_body_const;
FILE *asm_body_commands;
FILE *asm_body_fun;

int lastType;
int symbolctr;
int listctr;
int functionctr;
int list[10000];
int scopectr;
int scopestart[10000];
int scopeend[10000];
int if_start;
int param_cnt;
int param_list[50];
char *tmp_buffer[100];
int bufferctr;

extern int line_count;

struct Symbol{
	char *name;
	int ivalue;
	float fvalue;
	int type; // int,float,string

	int symboltype; // constant, variable, function
	int decleared;
	int pointedto;

}symbols[10000];
struct Function{
	int param_count;
	int param_address[50];
}functions[10000];

static void checktype(int address1, int address2){
	if( symbols[address1].type!=symbols[address2].type ){
		printf("#.type mitchmatch at line %d\n",line_count);
		exit(0);
	}
}
//add symbol to expression
static int add_symbol1( int address1, int address2, char opcode){
	int tmp = symbolctr;
	symbols[tmp].name= (char *)strdup("EXPR");
	switch( opcode ){
		case '+':
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue+symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				symbols[tmp].type=FLOAT;
//				symbols[tmp].fvalue=symbols[address1].fvalue+symbols[address2].fvalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			break;

		case '-':
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue-symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				symbols[tmp].type=FLOAT;
//				symbols[tmp].fvalue=symbols[address1].fvalue-symbols[address2].fvalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			break;
		case '*':
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue*symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				symbols[tmp].type=FLOAT;
//				symbols[tmp].fvalue=symbols[address1].fvalue*symbols[address2].fvalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			break;
		case '/':
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				if(symbols[address2].ivalue==0){
//					printf("#. math error divided by zero at line %d\n",line_count);
//					exit(0);
//				}
//				symbols[tmp].ivalue=symbols[address1].ivalue/symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				symbols[tmp].type=FLOAT;
//				if(symbols[address2].fvalue==0){
//					printf("#. math error divided by zero at line %d\n",line_count);
//					exit(0);
//				}
//				symbols[tmp].fvalue=symbols[address1].fvalue/symbols[address2].fvalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			break;
		case '%':
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				if(symbols[address2].ivalue==0){
//					printf("#. math error module by zero at line %d\n",line_count);
//					exit(0);
//				}
//				symbols[tmp].ivalue=symbols[address1].ivalue%symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				printf("#. math error don't support module of floating point %d\n",line_count);
				exit(0);
			}
			break;		
		case '>':
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue>symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].fvalue>symbols[address2].fvalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			break;
		case '<':
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue<symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].fvalue<symbols[address2].fvalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			break;
		case '=':
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue=symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].fvalue=symbols[address2].fvalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			break;

		default:
			break;
	}
//	printf("%s %d %f %d\n",symbols[tmp].name,symbols[tmp].ivalue,symbols[tmp].fvalue,symbols[tmp].decleared);
	++symbolctr;
return tmp;
}
//add symbol to expression
static int add_symbol2( int address1, int address2, int opcode){
	int tmp = symbolctr;
	symbols[tmp].name= (char *)strdup("EXPR");
	switch( opcode ){
		case EQ:
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue==symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].fvalue==symbols[address2].fvalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			break;	
		case GRE:
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue>=symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].fvalue>=symbols[address2].fvalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			break;	
		case LSE:
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue<=symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].fvalue<=symbols[address2].fvalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			break;	
		case NE:
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue!=symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].fvalue!=symbols[address2].fvalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			break;	
		case OR:
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue||symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				printf("#. math error don't support [ OR OPERATION ] between floating point %d\n",line_count);
				exit(0);
			}
			break;	
		case AND:
			if(symbols[address1].type==INT){
				symbols[tmp].type=INT;
//				symbols[tmp].ivalue=symbols[address1].ivalue&&symbols[address2].ivalue;
				symbols[tmp].decleared=1;
				symbols[tmp].symboltype=CONST;
			}
			else{
				printf("#. math error don't support [ AND OPERATION ] between floating point %d\n",line_count);
				exit(0);
			}
			break;	
		
		default:
			break;
	}
	++symbolctr;
return tmp;
}
static void add_assign_details(){
	int from = list[listctr-1];
	int tmp = symbols[ from ].type;
	--listctr;
	for( --listctr; listctr>=0; --listctr){
		if( tmp==INT ){
//			symbols[ list[listctr] ].ivalue = symbols[from].ivalue;
			if( symbols[from].symboltype==CONST ){
				fprintf(asm_body_commands,"\t\tmov eax ,[_c_lev%d] ; integer\n",from);
			}
			else{
				fprintf(asm_body_commands,"\t\tmov eax ,[_v_%s_lev%d] ; variable\n",symbols[from].name,from);
			}
		}
		else{
//			symbols[ list[listctr] ].fvalue = symbols[from].fvalue;
			if( symbols[from].symboltype==CONST){
				fprintf(asm_body_commands,"\t\tmov eax ,[_c_lev%d] ; integer\n",from);	
			}
			else{
				fprintf(asm_body_commands,"\t\tmov eax ,[_v_%s_lev%d] ; variable\n",symbols[from].name,from);	
			}
		}
		fprintf(asm_body_commands,"\t\tmov [_v_%s_lev%d], eax\n\n",symbols[list[listctr]].name,list[listctr]);
	}
	listctr=0;
}

static void add_type_details(){
	for( --listctr; listctr>=0; --listctr){
		symbols[ list[listctr] ].type=lastType;
//		printf("%d %s \n",listctr,symbols[ list[listctr] ].name);		
		if( symbols[ list[listctr] ].decleared ){
			printf("#. [ %s ] already decleared at line %d\n",symbols[ list[listctr] ].name,line_count);
			exit(0);
		}
		
		symbols[ list[listctr] ].decleared=1;
	}

	listctr=0;
}

static void add_function_details(int address, int type){
	if( symbols[ address ].decleared ){
		printf("#. [ %s ] already decleared at line %d\n",symbols[ address ].name,line_count);
		exit(0);
	}
	symbols[ address ].type=type;
	symbols[ address ].decleared=1;
	symbols[ address ].symboltype=FUN;
	symbols[ address ].pointedto = functionctr++;		
}
static void add_param_type(int address, int type){
	if( symbols[ address ].decleared ){
		printf("#. [ %s ] already decleared at line %d\n",symbols[ address ].name,line_count);
		exit(0);
	}
	symbols[ address ].type=type;
	symbols[ address ].decleared=1;		
	int at = functionctr;
	int cnt = functions[ at ].param_count;

	functions[ at ].param_address[ cnt ] = address; 
	functions[ at ].param_count++;
}
static void clearScope( int from, int to){
	//from ta function name . so funcion name'er ag porjonto
	for( ;to>from; --to ){
		if( symbols[to].type!=CONST)
			symbols[ to ].decleared = 0;
	}
}
static void addParam(int address){
	if( !symbols[ address ].decleared ){
		printf("#. [ %s ] not decleared at line %d\n",symbols[ address ].name,line_count);
		exit(0);
	}
	param_list[param_cnt++]=address;
}
//address of that function
static void check_valid(int address){
	int at = symbols[address].pointedto,i;
	if( !symbols[address].decleared ){
		printf("#. [ %s ] not decleared at line %d\n",symbols[ address ].name,line_count);
		exit(0);
	}
	if( functions[at].param_count!= param_cnt ){
		printf("#. parameter mitchmatch at line %d [ required %d arguments, passed %d\n",line_count, 
			functions[at].param_count, param_cnt
		);
		exit(0);
	}
	for(i=0;i<param_cnt;++i){
		if( symbols[ param_list[ i ] ].type != symbols[ functions[at].param_address[i] ].type ){
			printf("#. parameter type mitchmatch at line %d [ < required, get > < %s , %s >]\n",line_count,
				symbols[ functions[at].param_address[i] ].type==INT ? "int" : "float" ,
				symbols[ param_list[ i ] ].type==INT ?"int" : "float"
			 );
			exit(0);
		}
	}
	
	param_cnt=0;
}
static void addList(int address ){
	list[ listctr ] = address;
	++listctr;
}
// for assign operation
static void addList1(int address){
	if( !symbols[ address ].decleared ){
		printf("#. [ %s ] not decleared at line %d\n",symbols[ address ].name,line_count);
		exit(0);
	}
	
	list[ listctr ] = address;
	++listctr;
}
static void setType(int type){
	lastType=type;
}
static void setScope(int address){
	scopestart[scopectr++]=address;
}
static void unsetScope(){
	int st = scopestart[scopectr-1];
	for( ;st<10000; ++st){
		if(symbols[st].type!=CONST){
			symbols[st].decleared=0;
		}
	}
	--scopectr;
}
static void clearSymbol(){
	int i;
	symbolctr=listctr=scopectr=functionctr=0;
	for(i=0;i<10000;++i){
		symbols[i].ivalue=0;
		symbols[i].fvalue=0;
		symbols[i].type=0;
		symbols[i].symboltype=0;
		symbols[i].decleared=0;
	}
}

static int lookUp(char *s){
	int i;
	for(i=0; i<symbolctr;++i){
		if( strcmp(symbols[i].name,s)==0 && symbols[i].decleared==1 )return i;
	}
	return -1; // not found
}
static void write_body_var(){
	int i;
	for(i=0; i<symbolctr;++i){
		if(symbols[i].symboltype!=CONST){
			fprintf(asm_body_var,"_v_%s_lev%d:\t",symbols[i].name,i);
			if(symbols[i].type=INT){
				fprintf(asm_body_var,"resd 1 \t ; integer\n");
			}
			else{
				fprintf(asm_body_var,"resq 1 \t ; float\n");		
			}
		}
	}
}
static void showTable(){
	int i,j,at;
	puts("NAME	IVALUE	FVALUE		TYPE	SYMBOLTYPE	DECLEARED");
	for(i=0;i<symbolctr;++i){
		printf("%d %s\t%d\t%f\t%d\t%d\t%d ",i,symbols[i].name,symbols[i].ivalue,symbols[i].fvalue,symbols[i].type,symbols[i].symboltype,symbols[i].decleared);
		if( symbols[i].symboltype==FUN ){
			at = symbols[i].pointedto ;
			//printf("[ %d %d\n", at,functions[at].param_count);
			for(j=0;j< functions[ at ].param_count; ++j ){
				printf("[%s %d] ", symbols[ functions[at].param_address[j] ].name, symbols[ functions[at].param_address[j] ].type);
			}
		}
		printf("\n");
	}
}

static void printGreet(int allok){
	puts("\n\n:***********************************************:");
	if(!allok){
		puts("|\t\t Congrats, NO ERROR!!!\t\t|");
		puts("|\t\tassemly code => output.asm \t|");
	}
	else{
		puts("|\t\t CODE HAS ERROR(S)!!!\t\t|");
	}
	puts("'***********************************************'\n\n");			
/*
	if( !allok ){
		showTable();
	}
*/
}

	


