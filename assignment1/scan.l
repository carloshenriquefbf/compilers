%{
#include <string>

string lexema;

string removeEscapedQuotes(string str) {
    for (int i = 0; i < str.size() - 1; ++i) {
        if (
            (str[i] == '\\' && (str[i+1] == '\'' || str[i+1] == '\"'))
            || (str[i] == '\"' && str[i+1] == '\"' && isalnum(str[i+2]))
            || (str[i] == '\'' && str[i+1] == '\'' && isalnum(str[i+2]))
        ) {
            str.erase(i, 1);
        }
    }

    return str;
}

void handleRegularString(string str) {
    printf( "%d %s\n", _STRING, removeEscapedQuotes(str.substr(1, str.size() - 2)).c_str() );
}

void handleStringWithExpression(string str) {
    int start = str.find("${");
    int end = str.find("}");

    if (start == -1 || end == -1) {
        printf( "%d %s\n", _STRING2, str.substr(1, str.size() - 2).c_str() );
        return;
    }

    string preExpression = str.substr(0, start);
    string expression = str.substr(start, end - start + 1);
    string postExpression = str.substr(end + 1);

    printf( "%d %s\n", _STRING2, preExpression.substr(1).c_str() );
    printf( "%d %s\n", _EXPR, expression.substr(2, expression.length() - 3).c_str() );
    printf( "%d %s\n", _STRING2, postExpression.substr(0, postExpression.length() - 1).c_str() );
    return;
}

%}
    /* Coloque aqui definições regulares */

WS                      [ \t\n]
MAIG                    >=
MEIG                    <=
IG                      ==
DIF                     !=
FOR                     [fF][oO][rR]
IF                      [iI][fF]
INTEGER                 [0-9]
LETRA                   [A-Za-z_]
ID                      {LETRA}+({LETRA}|{INTEGER})*|\$({LETRA}|{INTEGER})*
ERROR                   {INTEGER}+|({ID}+\$)+
FLOAT                   {INTEGER}+(\.{INTEGER}+)?([Ee][+\-]?{INTEGER}+)?
COMMENT                 \/\*([^*]|\*[^\/])*\*\/)|(\/\/.*
STRING1                 \"(([^\\\"]|\\\")|(\"\")|[^\."])*\")|(\'(([^\\\']|\\')|('')|[^\.'])*\'
STRING2                 \`(.|\n)*\`

%%
    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{WS}	                { /* ignora espaços, tabs e '\n' */ }

    /* Todas as palavras reservadas devem aparecer antes do padrão do ID */
{MEIG}                  { lexema = yytext; return _MEIG; }
{MAIG}                  { lexema = yytext; return _MAIG; }
{IG}                    { lexema = yytext; return _IG; }
{DIF}                   { lexema = yytext; return _DIF; }
{FOR}                   { lexema = yytext; return _FOR; }
{IF}                    { lexema = yytext; return _IF; }
{INTEGER}               { lexema = yytext; return _INT; }
{FLOAT}                 { lexema = yytext; return _FLOAT; }
{COMMENT}               { lexema = yytext; return _COMENTARIO; }
{STRING1}               { handleRegularString(yytext); }
{STRING2}               { handleStringWithExpression(yytext); }
{ERROR}	                { printf( "Erro: Identificador invalido: %s\n", yytext); }
{ID}                    { lexema = yytext; return _ID; }

.                       { lexema = yytext; return *yytext;
                        /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */
                        }

%%

/* Não coloque nada aqui - a função main é automaticamente incluída na hora de avaliar e dar a nota. */