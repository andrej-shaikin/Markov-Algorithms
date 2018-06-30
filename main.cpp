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
	//��������� ���� ������� ������, ������� ������ ��������
	cout<<"\n";
	for(int i=0;i<algorithm.size();i++){
		cout<<algorithm[i]<<endl;
	}
}
string alg_name(string r){
	string side;
	//���������� ������ ������� ����� ��������
	int pos=r.find("->");
	for(int i=0;i<pos;i++) side+=r[i];
	return side;
}
string alg_val(string r){
	//���������� ������, ������� ����� ���������� � �������� ������
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
	//������� ������� ��������� � ����
	algorithm.clear();
	words.clear();
}

void kol_star(){
	//���� � ��������� ���� ����(*)-������ ������, �� �� � ������ ������� ����� ���������� *
	int count=0;
	vector<string>::iterator iter;
	iter=algorithm.begin();
	while(iter!=algorithm.end()){
		string side=*iter;
		if(side.find('*')!=-1) count++;
		++iter;
	}
	if(count>0) {
		//� ������ ������ � ������ ��������� *
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
		//�������� ������(��������) �� �������
		string side=*alg_iter;
		if(side.size()==0) {
			++alg_iter;goto run;
		}
		//�������� �� �������� ������ �������� ������� ����� �������� � ��, ��� ��� ����� ��������
		//name - ��� ����� ��������
		//val - �� ��� ����� �������� name
		string name=alg_name(side);
		string val=alg_val(side);
		
		if(word.find(name)!=-1){
			//���� � ������(���������) ���� (.) �� �� ���������� � ���������� � ������ ������� ����� �� ������,
			if(val[0]=='.') {
				val.erase(val.begin());stop=true;
			}
			if(show_step) cout<<step<<" ) ";
			
			//side- �������� ���������� 
			string side=word;
			//�������, ������� �������� ������
			string start_side="[";
			string end_side="]";
			//������� ������
			side.insert(side.find(name),start_side);
			side.insert(side.find(name)+name.size(),end_side);
			if(show_step) 
				cout<<side<<" - > ";
			//������ name �� val � �������� ������
			word.replace(word.find(name),name.size(),val);
		
			string side1=word;
			string start_side1=start_side;
			string end_side1=end_side;
			//combo - ���������� ������, ������ ������ (),{},[]
			string combo=start_side1+end_side1;
			
			//���� � ������ ������ ������ ��� ������ �� ��������� � ������ ���������� ������
			if(val=="" || val==" ") side1.insert(0,combo);
			//�����, ������ ������ �� �����, ��� ������ ���� ��������
			else{
				side1.insert(side1.find(val),start_side1);
				side1.insert(side1.find(val)+val.size(),end_side1);
			}

			if(show_step) cout<<side1<<endl;
			//���������� �������� � ������ ���������
			alg_iter=algorithm.begin();step++;
			if(stop) {
				stop=false;break;
			}
			//���� �������� ����������� ������ 120 ���, �� ��������� ��������� ��� ������ �������� �� ���������(����� ���������� �������) � �����������
		if(step>120) {
			cout<<"\n\n...\nNaN";nan=true;break;
		}
	}
		//���� �������� � ������ �� �������, �� ��������� �� ��������� ������
	else ++alg_iter;}
	step--;
	if(nan) word+="...";
}

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitleA("���������� ��������� �������");
	setlocale(0,"");

	string name_file_alg;
	string word;
	bool load_algor=false,read_word=false;
	bool show_alg=false,show_word=false;
	
menu:
	cout<<"�������� ��������: \n";
	cout<<"1) ��������� ����� ; \n";
	cout<<"2) ��������� �������� ; \n";
	cout<<"3) ������������� ����� ; \n";
	cout<<"4) �������� ������� ; \n";
	cout<<"\n����� : ";
	string kin;
	//���������� ������, �� ������ ����� � ������(��������� '���������') ����� ����� ���� ������������ try catch
	int vote;cin>>kin;;cout<<endl;
	//����������� ������ � �����
	vote=atoi(kin.c_str());
	
	if(vote==4){
		if(algorithm.empty() || words.empty()) {
			if(algorithm.empty()) 
				cout<<"������ ���������� ���� ; \n";
			if(words.empty()) 
				cout<<"������ ���� ���� ;\n";
			cout<<endl;system("pause");system("cls");goto menu;
		}
			algorithm.clear();	words.clear();
			cout<<"������� ������� ������� ! \n\n";system("pause");system("cls");goto menu;
	}

	if(vote!=1 && vote!=2 && vote!=3) {
		cout<<"\n\n�� ����� ����� �� ������������ ��������.\n\n";system("pause");system("cls");goto menu;
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
			cout<<"�������� �� ��������. ��������� �������� � ��������� �������.\n\n";
		if(!read_word) cout<<"�������� ����� �� �������. ������� ����� � ��������� �������.\n\n";
			system("pause");system("cls");goto menu;
	}

	if(vote==3 && load_algor && read_word){
		kol_star();
#include "parser.h"
	}
	cout<<"\n\n";cout<<"��������� ������� ������ ? (1/0) ";cin>>vote;cout<<endl;
	
	if(vote==1) {
		system("pause");system("cls");
		load_algor=false;	read_word=false;
		clear();	goto menu;
	}

	cout<<endl;
	system("pause");
}