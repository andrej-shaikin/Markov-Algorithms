system("pause");system("cls");
cout<<"Показать шаги выполнения алгоритма ? (1/0) ";cin>>vote;
if(vote==1) show_step=true;
else show_step=false;
system("pause");system("cls");
vector<string>::iterator iter_c;
iter_c=words.begin();
cout<<"\t\Алгоритм\n";
show_algor();cout<<endl;
if(show_step) cout<<"\n";
for(int i=0;i<10;i++) cout<<"---";
cout<<endl<<endl;;
while(iter_c!=words.end()){
	word=*iter_c;
	string in_time=word;
	run_algor(word);
	if(in_time[0]=='*' || in_time[0]==' ') in_time.erase(in_time.begin());
	if(!nan) cout<<"\nИсходное слово: "<<in_time<<endl;		
	if(!nan) cout<<"\nПереработанное слово: ";
	for(int i=0;i<word.size();i++){
		if(word[i]=='*' || word[i]=='$') continue;
		else cout<<word[i];}
	cout<<endl;
	if(!nan) cout<<"\nАлгоритм выполнен за "<<step;
	if(step==1) cout<<" шаг !\n";
	if(2<=step && step<=4) cout<<" шага !\n\n";
	if(step>4 && step<120) cout<<" шагов !\n\n";
	if(nan) cout<<"\nДанный алгоритм не имеет конечного решения !\n\n";
	for(int i=0;i<10;i++) cout<<"---";
	cout<<endl;
	cout<<"\n\n";
	step=1;
++iter_c;word.erase();}
cout<<"\n\n\n";