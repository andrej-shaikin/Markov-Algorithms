cout<<"������� ��� �����, � ������� ��������� ��������: ";
cin>>name_file_alg;cout<<endl;
name_file_alg+=".txt";
	ifstream fin;
	fin.open(name_file_alg);
	if(!fin.is_open()){cout<<"�� ������� ����� ���� "<<name_file_alg<<". ��������� ��� ���� � ��������� ������� �����.\n\n\n";system("pause");system("cls");goto menu;}
	
	string side;//side->��������
	while(!fin.eof()){
		getline(fin,side);
		algorithm.push_back(side);}
	cout<<endl<<"�������� ������� �������� ! \n\n";	