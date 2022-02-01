#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

char token;
bool error = 0;

ofstream outf ("C:/Users/alvar/Desktop/parse/Output.out");

int expr();
int term();
int factor();
int number();
int digit();
string s;
int cindex = 0;

string response;

void getToken()
{
    if (!error)
    {
        outf << response;
    }
    response.clear();
    outf << endl;
    if(s[cindex] != '\0') outf << "<gettoken> " << s[cindex] << " ";
    token = s[cindex];
    cindex++;
}

int expr()
{
    response += "<expresion> ";
    int result = term();
    while (token == '+')
    {
        getToken();
        result += term();
    }
    return result;
}

int term()
{
    response +="<termino> " ;
    int result = factor();
    while (token == '*')
    {
        getToken();
        result *= factor();
    }
    return result;
}

int factor()
{
    response += "<factor> ";
    int result;
    if (token == '(' )
    {
        getToken();
        result = expr();
        getToken();
    }
    else
        result = number();
    return result;
}

int number()
{
    response += "<numero> ";
    int result = digit();
    while (isdigit(token))
        result = 10 * result + digit();
    return result;
}

int digit()
{
    response += "<digito>";
    int result;
    if (isdigit(token)) {
        result = token - '0';
        getToken();
    }
    else
        error = true;
    return result;
}

void parse()
{
    outf << endl << "<parse>" << " ";
    getToken();
    expr();
    if (!error) outf << "el parse fue escrito correctamente." << endl;
    else outf << "hubo un error." << endl;
}

int main()
{
    ifstream inf ("C:/Users/alvar/Desktop/parse/input.txt");
    while (!inf.eof())
    {
        inf >> s;
        cindex=0;
        parse();
    }
    return 0;
}
