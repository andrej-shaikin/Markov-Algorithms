cout<<"Введите имя файла, в котором находится слово(-a) : ";
string name_file_word;
cin>>name_file_word;cout<<endl;
name_file_word+=".txt";
ifstream wfin;
wfin.open(name_file_word);
if(!wfin.is_open()){cout<<"Не удалось найти файл "<<name_file_word<<". Проверьте имя файл и повторите попытку позже.\n\n\n";system("pause");system("cls");goto menu;}
	
	string side;//side->побочная
	while(!wfin.eof()){
	getline(wfin,side);
	if(side.size()!=0) words.push_back(side);
	side.erase();}
	cout<<endl<<"Слово успешно загружена ! \n\n";