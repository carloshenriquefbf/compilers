%{
int token( int tk );
string trim( const char *str, const char *chars );
vector<string> tokeniza( string str );
string lexema;
%}

D  	    [0-9]
L   	[A-Za-z_]
INT	    {D}+
DOUBLE  {D}+"."{D}+([Ee][+\-]?{D}+)?
ID      {L}({L}|{D})*
CSTRING \"[^\"]*\"|\'[^\']*\'
ASM     "asm{".*"}"
SETA   "=>"
%%

"\t"       { coluna += 4; }
" "        { coluna++; }
"\n"	     { linha++; coluna = 1; }

{DOUBLE} { return token( CDOUBLE ); }
{INT}	   { return token( CINT ); }
{CSTRING} { return token( CSTRING ); }

"&&"	   { return token( AND ); }
"||"	   { return token( OR ); }
"<="	   { return token( ME_IG ); }
">="	   { return token( MA_IG ); }
"!="	   { return token( DIF ); }
"=="	   { return token( IGUAL ); }

"+="       { return token( MAIS_IGUAL ); }
"++"       { return token( MAIS_MAIS ); }

"let"      { return token( LET ); }
"const"    { return token( CONST ); }
"var"      { return token( VAR ); }
"if"       { return token( IF ); }
"else"     { return token( ELSE ); }
"for"      { return token( FOR ); }
"while"    { return token( WHILE ); }
"function" { return token( FUNCTION ); }
"return"   { return token( RETURN ); }
"true"     { return token( TRUE ); }
"false"    { return token( FALSE ); }
")"/.*"=>" { return token( PARENTESES_FUNCAO ); }
{SETA}     { return token( SETA ); }

{ASM}       {
                string lexema = string(yytext).substr(4, strlen(yytext) - 5);
                yylval.c = tokeniza( lexema );
                yylval.linha = linha;
                yylval.coluna = coluna;

                return ASM; }


{ID}       { return token( ID ); }
.          { return token( *yytext ); }

%%

vector<string> tokeniza(string str) {
    vector<string> tokens;
    string token;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            token += str[i];
        } else {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
    }

    tokens.push_back(token);

    return tokens;
}

int token( int tk ) {
  yylval.c = vector<string>{ yytext };
  coluna += strlen( yytext );

  yylval.linha = linha;
  yylval.coluna = coluna;

  return tk;
}