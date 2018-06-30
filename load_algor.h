cout<<"Введите имя файла, в котором находится алгоритм: ";
cin>>name_file_alg;cout<<endl;
name_file_alg+=".txt";
	ifstream fin;
	fin.open(name_file_alg);
	if(!fin.is_open()){cout<<"Не удалось найти файл "<<name_file_alg<<". Проверьте имя файл и повторите попытку позже.\n\n\n";system("pause");system("cls");goto menu;}
	
	string side;//side->побочная
	while(!fin.eof()){
		getline(fin,side);
		algorithm.push_back(side);}
	cout<<endl<<"Алгоритм успешно загружен ! \n\n";	