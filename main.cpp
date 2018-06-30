#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

vector<string>algorithm;
vector<string>words;

int step=1;
bool show_step=false;
bool stop=false;
bool nan=false;

void show_algor(){
	//используя цикл выводим вектор, который хранит алгоритм
	cout<<"\n";
	for(int i=0;i<algorithm.size();i++){
		cout<<algorithm[i]<<endl;
	}
}
string alg_name(string r){
	string side;
	//возвращает строку которую нужно заменить
	int pos=r.find("->");
	for(int i=0;i<pos;i++) side+=r[i];
	return side;
}
string alg_val(string r){
	//возвращает строку, которую нужно подставить в исходную строку
	string side;
	int pos=0;
	for(int i=0;i<r.size();i++){
		if(r[i]=='-' && r[i+1]=='>') {
			pos=(i+1)+1;break;
		}
	}
	for(int i=pos;i<r.size();i++) 
		side+=r[i];
	return side;
}

void clear(){
	//очищает вектора алгоритма и слов
	algorithm.clear();
	words.clear();
}

void kol_star(){
	//если в алгоритме есть знак(*)-пустой символ, то он в начале каждого слова подставить *
	int count=0;
	vector<string>::iterator iter;
	iter=algorithm.begin();
	while(iter!=algorithm.end()){
		string side=*iter;
		if(side.find('*')!=-1) count++;
		++iter;
	}
	if(count>0) {
		//в каждой строке в начала вставляем *
		for(int i=0;i<words.size();i++){
			words[i].insert(0,1,'*');
		}
	}
}

void run_algor(string &word){
	vector<string>::iterator alg_iter;
	alg_iter=algorithm.begin();
run:
	while(alg_iter!=algorithm.end()){
		//получаем строка(алгоритм) из вектора
		string side=*alg_iter;
		if(side.size()==0) {
			++alg_iter;goto run;
		}
		//получаем из исходной строки значение которое нужно изменить и то, чем его нужно заменить
		//name - что нужно заменить
		//val - на что будет заменена name
		string name=alg_name(side);
		string val=alg_val(side);
		
		if(word.find(name)!=-1){
			//если в строке(алгоритме) есть (.) то он выполнится и завершится и заодно удалить точку из строки,
			if(val[0]=='.') {
				val.erase(val.begin());stop=true;
			}
			if(show_step) cout<<step<<" ) ";
			
			//side- побочная переменная 
			string side=word;
			//символы, которые выделяют замену
			string start_side="[";
			string end_side="]";
			//вставка скобок
			side.insert(side.find(name),start_side);
			side.insert(side.find(name)+name.size(),end_side);
			if(show_step) 
				cout<<side<<" - > ";
			//замена name на val в исходной строке
			word.replace(word.find(name),name.size(),val);
		
			string side1=word;
			string start_side1=start_side;
			string end_side1=end_side;
			//combo - комбинация скобок, идущих подряд (),{},[]
			string combo=start_side1+end_side1;
			
			//если в начале пустой символ или пробел то вставляем в строку комбинацию скобок
			if(val=="" || val==" ") side1.insert(0,combo);
			//иначе, ставим скобки на места, где строка была изменена
			else{
				side1.insert(side1.find(val),start_side1);
				side1.insert(side1.find(val)+val.size(),end_side1);
			}

			if(show_step) cout<<side1<<endl;
			//перемещаем итератор в начало алгоритма
			alg_iter=algorithm.begin();step++;
			if(stop) {
				stop=false;break;
			}
			//если алгоритм выполняется больше 120 раз, то программа посчитает что данный алгоритм не корректен(имеет бескончное решение) и остановится
		if(step>120) {
			cout<<"\n\n...\nNaN";nan=true;break;
		}
	}
		//если алгоритм в строке не подошел, то переходим на следующею строку
	else ++alg_iter;}
	step--;
	if(nan) word+="...";
}

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitleA("Нормальные алгорифмы Маркова");
	setlocale(0,"");

	string name_file_alg;
	string word;
	bool load_algor=false,read_word=false;
	bool show_alg=false,show_word=false;
	
menu:
	cout<<"Выберите действие: \n";
	cout<<"1) Загрузить слово ; \n";
	cout<<"2) Загрузить алгоритм ; \n";
	cout<<"3) Преоброзовать слово ; \n";
	cout<<"4) Очистить вектора ; \n";
	cout<<"\nВыбор : ";
	string kin;
	//используем строку, тк ввести можно и символ(программа 'сломается') также можно было использовать try catch
	int vote;cin>>kin;;cout<<endl;
	//преобразуем строку в число
	vote=atoi(kin.c_str());
	
	if(vote==4){
		if(algorithm.empty() || words.empty()) {
			if(algorithm.empty()) 
				cout<<"Вектор алгоритмов пуст ; \n";
			if(words.empty()) 
				cout<<"Вектор слов пуст ;\n";
			cout<<endl;system("pause");system("cls");goto menu;
		}
			algorithm.clear();	words.clear();
			cout<<"Вектора успешно очищены ! \n\n";system("pause");system("cls");goto menu;
	}

	if(vote!=1 && vote!=2 && vote!=3) {
		cout<<"\n\nВы ввели номер не существующей операции.\n\n";system("pause");system("cls");goto menu;
	}
	if(vote==1){
#include "read_word.h"
	read_word=true;system("pause");system("cls");goto menu;
	}
	
	if(vote==2){
#include "load_algor.h"
	load_algor=true;system("pause");system("cls");goto menu;
	}
	
	if(!load_algor || !read_word) {
		if(!load_algor) 
			cout<<"Алгоритм не загружен. Загрузите алгоритм и повторите попытку.\n\n";
		if(!read_word) cout<<"Исходное слово не введено. Введите слово и повторите попытку.\n\n";
			system("pause");system("cls");goto menu;
	}

	if(vote==3 && load_algor && read_word){
		kol_star();
#include "parser.h"
	}
	cout<<"\n\n";cout<<"Запустить завново машину ? (1/0) ";cin>>vote;cout<<endl;
	
	if(vote==1) {
		system("pause");system("cls");
		load_algor=false;	read_word=false;
		clear();	goto menu;
	}

	cout<<endl;
	system("pause");
}