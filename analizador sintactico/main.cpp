//CURSO : COMPILADORES GRUPO : CCOMP8-1
//ALUMNO : ALVARO DIEGO DURAND MANRIQUE
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>
using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::istringstream;
using std::stringstream;
constexpr int CHAR_LENGTH = 1;
using std::cout; using std::cin;
using std::endl; using std::string;
bool worldEvents = false;
bool porsiaca=false;
int x1=1,x2=1,x3=1,x4=1,x5=1,x6=1,x7=1,x8=1;
int cont_glob=1,cont_glob1=1;
void s1(string s){
	for(int i=0;i<s.size();i++){
		if(s=="and"||s=="or"||s=="not"||s=="div"||s=="mod"||s=="in"){
			x1++;
			cont_glob++;
			break;
		}
	}
}
	
void s2(string s){
	for(int i=0;i<s.size();i++){
		if(s=="array"||s=="downto"||s=="function"||s=="of"||s=="repeat"||s=="until"||s=="begin"||s=="else"||s=="goto"||s=="packed"
		   ||s=="set"||s=="var"||s=="case"||s=="end"||s=="if"||s=="procedure"||s=="then"||s=="while"||s=="const"||s=="file"
		   ||s=="label"||s=="program"||s=="to"||s=="with"||s=="do"||s=="for"||s=="nil"||s=="record"||s=="type"){
			x2++;
			cont_glob++;
			break;
		}
	}	
}
	
void s3(string s){
	for(int i=0;i<s.size();i++){
		if(s=="*"||s=="/"|s=="^"||s=="%"||s=="+"||s=="-"||s=="="||s==">"||s=="<"||s=="<="||s==">="||s==":="){
			x3++;
			break;
		}
	}
}
		
void s4(string s){
	for(int i=0;i<s.size();i++){
		if(s=="("||s==")"||s=="["||s=="]"||s==":"||s==";"||s==","){
			x4++;
			break;
		}
	}
}
			
void s5(string s){
	int tam=s.size();
	for(int i=0;i<tam;i++){
		if((s[0]==39)&&(s[tam-1]==39)){
			if(!(s[i]==39&&s[i+1]==39)){
				x5++;
				break;
			}
		}
	}
}

void s6(string s){
	int tam=s.size();
	int cont=0;
	for(int i=0;i<tam;i++){if(s[i]=='.'){cont++;}}
	for(int i=0;i<tam;i++){
		if(s[i]>=48&&s[i]<=57){
			if((cont<2)&&(s[i+1]>=48&&s[i+1]<=57)||((s[i+1]=='.')&&(s[i+2]>=48&&s[i+2]<=57))||(s[i+1]=='e')||tam==1){
				x6++;
				break;
			}
		}
	}
}

void s7(string s){
	int tam=s.size();
	for(int i=0;i<tam;i++){
		if(((s[0]=='{')&&(s[tam-1]=='}'))||(((s[0]=='(')&&(s[1]=='*'))&&((s[tam-2]=='*')&&(s[tam-1]==')')))){
			x7++;
			break;
		}
	}
}

void s8(string s){
	int tam=s.size();
	for(int i=0;i<tam;i++){
		if((s[0]>=65&&s[0]<=90)||(s[0]>=97&&s[0]<=122)){
			if((cont_glob<2)&&(s[i+1]>=48&&s[i+1]<=57)||(s[i+1]>=65&&s[i+1]<=90)||(s[i+1]>=97&&s[i+1]<=122)){
				x8++;
				break;
			}
		}
	}
	
}

////////////////////////////////////////////////////////////////////////////////////////
void OPERADOR(string s){
	for(int i=0;i<s.size();i++){
		if(s=="and"||s=="or"||s=="not"||s=="div"||s=="mod"||s=="in"){
			//cout<<"-------------------- "<<endl;
			cout<<" OPERADOR ------------ "<<"<"<<s<<">"<<endl;
			worldEvents = true;
			cont_glob1++;
			break;
		}
	}
}

void RESERVADA(string s){
	for(int i=0;i<s.size();i++){
		if(s=="array"||s=="downto"||s=="function"||s=="of"||s=="repeat"||s=="until"||s=="begin"||s=="else"||s=="goto"||s=="packed"
		   ||s=="set"||s=="var"||s=="case"||s=="end"||s=="if"||s=="procedure"||s=="then"||s=="while"||s=="const"||s=="file"
		   ||s=="label"||s=="program"||s=="to"||s=="with"||s=="do"||s=="for"||s=="nil"||s=="record"||s=="type"){
			//cout<<"-------------------- "<<endl;
			cout<<" PALABRA RESERVADA --- "<<"<"<<s<<">"<<endl;
			worldEvents = true;
			cont_glob1++;
			break;
		}
	}
	
}

void OPERADOR1(string s){
	for(int i=0;i<s.size();i++){
		if(s=="*"||s=="/"|s=="^"||s=="%"||s=="+"||s=="-"||s=="="||s==">"||s=="<"||s=="<="||s==">="||s==":="){
			//cout<<"-------------------- "<<endl;
			cout<<" OPERADOR ------------ "<<"<"<<s<<">"<<endl;
			worldEvents = true;
			break;
		}
	}
}
	
void DELIMITADOR(string s){
	for(int i=0;i<s.size();i++){
		if(s=="("||s==")"||s=="["||s=="]"||s==":"||s==";"||s==","){
			//cout<<"-------------------- "<<endl;
			cout<<" DELIMITADOR --------- "<<"<"<<s<<">"<<endl;
			worldEvents = true;
			break;
		}
	}
	
}

void STRING(string s){
	int tam=s.size();
	for(int i=0;i<tam;i++){
		if((s[0]==39)&&(s[tam-1]==39)){
			if(!(s[i]==39&&s[i+1]==39)){
				//cout<<"-------------------- "<<endl;
				cout<<" CARACTER ------------ "<<"<"<<s<<">"<<endl;
				worldEvents = true;
				break;
			}
		}
	}
	
}

void NUMERO(string s){
	int tam=s.size();
	int cont=0;
	for(int i=0;i<tam;i++){
		if(s[i]=='.'){
			cont++;
		}
	}
	for(int i=0;i<tam;i++){
		if(s[i]>=48&&s[i]<=57){
			if((cont<2)&&(s[i+1]>=48&&s[i+1]<=57)||((s[i+1]=='.')&&(s[i+2]>=48&&s[i+2]<=57))||(s[i+1]=='e')||tam==1){
				//cout<<"-------------------- "<<endl;
				cout<<" NUMERO -------------- "<<"<"<<s<<">"<<endl;
				worldEvents = true;
				break;
			}
		}
	}
}

void COMENTARIO(string s){
	int tam=s.size();
	for(int i=0;i<tam;i++){
		if(((s[0]=='{')&&(s[tam-1]=='}'))||(((s[0]=='(')&&(s[1]=='*'))&&((s[tam-2]=='*')&&(s[tam-1]==')')))){
			//cout<<"-------------------- "<<endl;
			cout<<" COMENTARIO ---------- "<<"<"<<s<<">"<<endl;
			worldEvents = true;
			break;
		}
	}
	
}

void IDENTIFICADOR(string s){
	int tam=s.size();
	for(int i=0;i<tam;i++){
		if((s[0]>=65&&s[0]<=90)||(s[0]>=97&&s[0]<=122)){
			if((cont_glob1<2)&&(s[i+1]>=48&&s[i+1]<=57)||(s[i+1]>=65&&s[i+1]<=90)||(s[i+1]>=97&&s[i+1]<=122)){
				//cout<<"-------------------- "<<endl;
				cout<<" IDENTIFICADOR ------- "<<"<"<<s<<">"<<endl;
				worldEvents = true;
				break;
			}
		}
	}
	
}

int aea=1;
void check(string s){
	int tam=s.size();
	for(int i=0;i<tam;i++){
		if(s[i]==10){
			aea++;
		}
	}
}
	
int main(){
	FILE * archivo;
	long medida;
	char * texto;
	archivo = fopen ("prueba5.txt", "r");
	fseek (archivo , 0 , SEEK_END);
	medida = ftell (archivo);
	rewind (archivo);
	texto = (char*) malloc (sizeof(char)*medida);
	fread(texto, medida+1, 1, archivo);
	string text;
	fclose(archivo);
	int i=0;
	while(texto[i]!='\0'){
		text.push_back(texto[i]);
		i++;
	}

	for(int j=0;j<i-18;j++){	
		cout <<text[j];
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	cout<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	cout<<endl;
	cout<<"ANALIZADOR LEXICO"<<endl;
	cout<<"<TOKENTYPE> ------ <TOKENTYPE> "<<endl;
	cout<<endl;
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	string space_delimiter = " ";
	vector<string> words{};	
	size_t pos = 0;
	while ((pos = text.find(space_delimiter)) != string::npos) {
		words.push_back(text.substr(0, pos));
		text.erase(0, pos + space_delimiter.length());
	}
	cout<<words.size()<<endl;
	
	
	
	for(int i=1;i<words.size();i++){
		check(words[i]);
		if(!(aea>1)){
			//cout<<words[i]<<" ---- "<<words[i].size()<<"-----"<<i<<endl;
			
			/*cout<<"---------------------------"<<endl;
			cout<<"la palabra es : "<<words[i]<<endl;
			cout<<"x1 antes : "<<x1<<endl;
			cout<<"x2 antes : "<<x2<<endl;
			cout<<"x3 antes : "<<x3<<endl;
			cout<<"x4 antes : "<<x4<<endl;
			cout<<"x5 antes : "<<x5<<endl;
			cout<<"x6 antes : "<<x6<<endl;
			cout<<"x7 antes : "<<x7<<endl;
			cout<<"x8 antes : "<<x8<<endl;*/
			
			s1(words[i]);
			s2(words[i]);
			s3(words[i]);
			s4(words[i]);
			s5(words[i]);
			s6(words[i]);
			s7(words[i]);
			s8(words[i]);
			
			/*cout<<"x1 despues : "<<x1<<endl;
			cout<<"x2 despues : "<<x2<<endl;
			cout<<"x3 despues : "<<x3<<endl;
			cout<<"x4 despues : "<<x4<<endl;
			cout<<"x5 despues : "<<x5<<endl;
			cout<<"x6 despues : "<<x6<<endl;
			cout<<"x7 despues : "<<x7<<endl;
			cout<<"x8 despues : "<<x8<<endl;*/
			int x_total=x1+x2+x3+x4+x5+x6+x7+x8;
			//cout<<"x total es : "<<x_total<<endl;
			if(x_total==8){
			//cout<<"-------------------- "<<endl;
			cout<<" MAL ENTRADA --------- : "<<"<"<<words[i]<<">"<<endl;
			}
			else{
			OPERADOR(words[i]);
			RESERVADA(words[i]);	
			OPERADOR1(words[i]);
			DELIMITADOR(words[i]);
			STRING(words[i]);
			NUMERO(words[i]);
			COMENTARIO(words[i]);
				if(cont_glob1<2){IDENTIFICADOR(words[i]);}
			
			}
			x1=1,x2=1,x3=1,x4=1,x5=1,x6=1,x7=1,x8=1,cont_glob1=1;
		}
		aea=1;
	}
	cout<<"-------------------- "<<endl;
	cout<<words[40][0]<<endl;
	char c = words[40][0]; // narrowing on C
	int a = c;
	cout<<a;
}
	
