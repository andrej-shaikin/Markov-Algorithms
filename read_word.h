cout<<"������� ��� �����, � ������� ��������� �����(-a) : ";
string name_file_word;
cin>>name_file_word;cout<<endl;
name_file_word+=".txt";
ifstream wfin;
wfin.open(name_file_word);
if(!wfin.is_open()){cout<<"�� ������� ����� ���� "<<name_file_word<<". ��������� ��� ���� � ��������� ������� �����.\n\n\n";system("pause");system("cls");goto menu;}
	
	string side;//side->��������
	while(!wfin.eof()){
	getline(wfin,side);
	if(side.size()!=0) words.push_back(side);
	side.erase();}
	cout<<endl<<"����� ������� ��������� ! \n\n";