%{
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

string lexema;

int token;

void E();
void F();
void T();
void E_linha();
void T_linha();
void G();
void G_linha();
void H();
void H_linha();
void S();
void C();
void A();

void erro( string, int );
void casa( int );

enum { ID = 256, NUM, PRINT, STRING, POWER, FAT, MAX, DTOS, MDC };

map<int,string> nome_tokens = {
  { ID, "identificador" },
};
%}

WS	    [ \n\t]
DIGITO	[0-9]
LETRA	[A-Za-z_]

NUM	{DIGITO}+("."{DIGITO}+)?
ID	{LETRA}({LETRA}|{DIGITO})*

STRING                 \"(([^\\\"]|\\\")|(\"\")|[^\."])*\")|(\'(([^\\\']|\\')|('')|[^\.'])*\'

%%

{WS}  		{ }
{NUM} 		{ lexema = yytext; return NUM; }
{STRING}    { lexema = yytext; return STRING; }
"print" 	{ lexema = yytext; return PRINT; }
"^"         { lexema = yytext; return POWER; }
"!"         { lexema = yytext; return FAT; }
"max"       { lexema = yytext; return MAX; }
"dtos"      { lexema = yytext; return DTOS; }
"mdc"      { lexema = yytext; return MDC; }
{ID}		{ lexema = yytext; return ID; }

.		    { lexema = yytext; return yytext[0]; }

%%

int next_token() {
  return yylex();
}

void print( string s ) {
  cout << s << " ";
}

string nome_token( int token ) {
  if( nome_tokens.find( token ) != nome_tokens.end() )
    return nome_tokens[token];
  else {
    string r;

    r = token;
    return r;
  }
}

void E() {
  T();
  E_linha();
}

void E_linha() {
  switch( token ) {
    case '+' : casa( '+' ); T(); printf("+ "); E_linha(); break;
    case '-' : casa( '-' ); T(); printf("- "); E_linha(); break;
  }
}

void T() {
  G();
  T_linha();
}

void T_linha() {
  switch( token ) {
    case '*' : casa( '*' ); G(); printf("* "); T_linha(); break;
    case '/' : casa( '/' ); G(); printf("/ "); T_linha(); break;
  }
}

void G() {
  H();
  G_linha();
}

void G_linha() {
  switch( token ) {
    case POWER: casa( POWER ); G(); printf("power # "); G_linha(); break;
    case FAT : casa( FAT ); G(); printf("fat # "); G_linha(); break;
  }
}

void H() {
  F();
  H_linha();
}

void H_linha() {
  switch( token ) {
    case MAX: casa( MAX ); H(); printf("max # "); H_linha(); break;
    case DTOS : casa( DTOS ); H(); printf("dtos # "); H_linha(); break;
    case MDC : casa( MDC ); H(); printf("mdc # "); H_linha(); break;
  }
}

void F() {
  switch( token ) {
    case '-' : {
      string temp = lexema;
      casa( '-' );
      print( "0" );
      T();
      print( "-");
      }
      break;
    case '+' : {
      string temp = lexema;
      casa( '+' );
      T();
      }
      break;
    case ID : {
      string temp = lexema;
      casa( ID );
      print( temp +  " @" );
      }
      break;
    case NUM : {
      string temp = lexema;
      casa( NUM );
      print( temp );
      }
      break;
    case '(':
      casa( '(' );
      E();
      if (token == ',') {
        casa( ',' );
        E();
      }
      casa( ')' );
      break;
    case STRING: {
      string temp = lexema;
      casa( STRING );
      print( temp );
      }
      break;
  }
}

void A() {
  string temp = lexema;
  switch( token ) {
    case ID:
      casa( ID );
      print( temp );
      casa( '=' );
      E();
      print( "=" );
      print( "^");
      break;
    default:
      E();
  }
}

void C() {
  switch (token){
    case PRINT:
      casa(PRINT);
      E();
      casa(';');
      print( "print #" ) ;
      break;
    default:
      A();
      casa(';');
  }
}

void S() {
  if (token == ID || token == PRINT) {
      C();
      S();
  }
}

void casa( int esperado ) {
  if( token == esperado )
    token = next_token();
  else {
    cout << "Esperado " << nome_token( esperado ) << "; encontrado "
         << nome_token( token ) << endl;

    exit( 1 );
  }
}

void erro( string msg, int token ) {
  printf( "%s %d\n", msg.c_str(), token );
  exit( 1 );
}

int main() {
  token = next_token();
  S();
  cout << endl;

  return 0;
}