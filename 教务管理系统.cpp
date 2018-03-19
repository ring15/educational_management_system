#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<windows.h>
using namespace std;
const int N=5000;
struct Course
{
    string CourseName;
    int score;
};
struct Student{
    int Sclass;
    string Snum;
    string Sname;
    Course cour[10];
};
Student stud[100];
int Studentmath[N];
int Studentphy[N];
int Studentc[N];
class Charge
{
private:
	string Studentname;
	int Studentclass;
	string Studentnum;
	int Studentterm;
    int Studenmath; //�����ɼ�
    int Studenphy; //����ɼ�
    int Studenc;//c++
    int mathscore;
    int physcore;
    int cscore;
public:
    void NewInfo();
    void RefreshInfo();
    void DeleteInfo();
    void outputFailor(string course);
    void outputFirstFive(string course);
    void outputAverage(string course);
    void outputGradeList(string course,int c);
    void outputCourseALLPersonList(string course);
    void outputPersonGradeList(string ID);
    static int MaxNum();
};
class DBOperate
{
private:
	string Studentname;
	int Studentclass;
	string Studentnum;
    int mathscore;
    int physcore;
    int cscore;
    int stmath;
    int stphy;
    int stc;
	static long EmployeeMaxNum;
public:
	void WriteIn(int iflag);
	void ReadOut();
	void RefreshMaxNum(int iflag); //iflg=1 or -1 or 0
};
void DBOperate::WriteIn(int iflag) //���ݲ���������д��
{
	DBOperate::RefreshMaxNum(iflag);
	ofstream myf("Student.txt");
	ofstream my("choose.txt");
	Charge s;
	int MN;
	MN=s.MaxNum();
	for(int i=0;i<MN;i++)
	{
		myf<<stud[i].Sclass<<'\t'<<stud[i].Snum<<'\t'<<stud[i].Sname<<'\t';
		myf<<stud[i].cour[0].score<<'\t'<<Studentmath[i]<<'\t'<<stud[i].cour[1].score<<'\t'<<Studentphy[i]<<'\t'<<stud[i].cour[2].score<<'\t'<<Studentc[i]<<'\n';
	    my<<"������  "<<Studentmath[i]<<'\t'<<"����:  "<<Studentphy[i]<<'\t'<<"c++:  "<<Studentc[i]<<'\n';
	}
	myf.close();
	my.close();
	return;
}
void DBOperate::ReadOut() //���ݲ�������������
{
	ifstream myf("Student.txt");
	Charge e;
	int MN;
	int i;
	MN = e.MaxNum();
	for(i=0 ;i<MN;i++)
	{
		myf>>Studentclass>>Studentnum>>Studentname>>mathscore>>stmath>>physcore>>stphy>>cscore>>stc;
		stud[i].Sclass=Studentclass;
		stud[i].Snum=Studentnum;
		stud[i].Sname=Studentname;
		stud[i].cour[0].score=mathscore;
		stud[i].cour[1].score=physcore;
		stud[i].cour[2].score=cscore;
		Studentmath[i]=stmath;
		Studentphy[i]=stphy;
		Studentc[i]=stc;
	}
	myf.close();
}
void DBOperate::RefreshMaxNum(int iflag) //����ϵͳ��ѧ�������ļ��ĺ���
{
	int MaxNum = 0;
	ifstream myif("StudentMaxNUM.txt");
	myif>>MaxNum;
	myif.close();
	MaxNum =MaxNum+iflag;
	ofstream myof("StudentMaxNUM.txt");
	myof<<MaxNum;
	myof.close();
}
void Charge::outputFailor(string course)//����������
{
    int i;
    for(i=0;i<50&&stud[i].Sclass!=0;i++)
        {
            if(("����"==course)&&stud[i].cour[0].score<60)
            {
                cout<<stud[i].Sclass<<"��"<<'\t'<<stud[i].Snum<<"��"<<'\t'<<stud[i].Sname<<'\t';
                cout<<"����  "<<stud[i].cour[0].score<<'\t';
                cout<<endl;
            }
            else if(("����"==course)&&stud[i].cour[1].score<60)
            {
                cout<<stud[i].Sclass<<"��"<<'\t'<<stud[i].Snum<<"��"<<'\t'<<stud[i].Sname<<'\t';
                cout<<"����  "<<stud[i].cour[1].score<<'\t';
                cout<<endl;
            }
            else if(("c++"==course)&&stud[i].cour[2].score<60)
            {
                cout<<stud[i].Sclass<<"��"<<'\t'<<stud[i].Snum<<"��"<<'\t'<<stud[i].Sname<<'\t';
                cout<<"c++  "<<stud[i].cour[2].score<<'\t';
                cout<<endl;
            }
        }
}
void Charge::outputFirstFive(string course)//ȫ�꼶��ǰ����
{
    int i,j,k;
    Student stu[50];
    for(i=0;i<50;i++)
        for(j=i+1;j<50;j++)
        {
            if(("����"==course)){
            if(stud[i].cour[0].score<stud[j].cour[0].score)
            {stu[i]=stud[i];
            stud[i]=stud[j];
            stud[j]=stu[i];}
            for(k=0;k<5;k++)
            {
                cout<<stud[k].Sclass<<"��"<<'\t'<<stud[k].Snum<<"��"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"����  "<<stud[k].cour[0].score<<'\t';
                cout<<endl;
            }
            goto loop;
            }
            else if(("����"==course)){
            if(stud[i].cour[1].score<stud[j].cour[1].score)
            {stu[i]=stud[i];
            stud[i]=stud[j];
            stud[j]=stu[i];}
            for(k=0;k<5;k++)
            {
                cout<<stud[k].Sclass<<"��"<<'\t'<<stud[k].Snum<<"��"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"����  "<<stud[k].cour[1].score<<'\t';
                cout<<endl;
            }
            goto loop;
            }
            else if(("c++"==course)){
            if(stud[i].cour[2].score<stud[j].cour[2].score)
            {stu[i]=stud[i];
            stud[i]=stud[j];
            stud[j]=stu[i];}
            for(k=0;k<5;k++)
            {
                cout<<stud[k].Sclass<<"��"<<'\t'<<stud[k].Snum<<"��"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"c++  "<<stud[k].cour[2].score<<'\t';
                cout<<endl;
            }
            goto loop;
            }
            else goto loop;
        }
        loop:cout<<" ";
}
void Charge::outputAverage(string course)//ÿ���ƽ���ɼ�
{
    int i,j,k;
    int t,t1,t2,t3;
    int a[3]={1,2,3,};//��5����
    int b[3]={0,0,0};//ͳ��ÿ��������
    int sum[3]={0,0,0};//ͳ��ÿ��������ܺ�
    double c[3]={0,0,0},temp,mi;   //ÿ����ƽ����
    for(k=0;k<3;k++)
    {
        for(i=0;i<50;i++)
        {
            if(("����"==course)&&stud[i].Sclass==a[k])
            {
               sum[k]+=stud[i].cour[0].score;
               b[k]++;
            }
            else  if(("����"==course)&&stud[i].Sclass==a[k])
            {
               sum[k]+=stud[i].cour[1].score;
               b[k]++;
            }
            else  if(("c++"==course)&&stud[i].Sclass==a[k])
            {
                sum[k]+=stud[i].cour[2].score;
                b[k]++;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        c[i]=sum[i]/b[i];
    }
    if(c[0]<c[1])
        if(c[1]<c[2])
        {
            mi=a[0];
            temp=c[0];
            a[0]=a[2];
            c[0]=c[2];
            a[2]=mi;
            c[2]=temp;

        }
        else if(c[0]<c[2])
        {
            mi=a[0];
            temp=c[0];
            a[0]=a[1];
            c[0]=c[1];
            a[1]=a[2];
            c[1]=c[2];
            a[2]=mi;
            c[2]=temp;
        }
        else
        {
            mi=a[0];
            temp=c[0];
            a[0]=a[1];
            c[0]=c[1];
            a[1]=mi;
            c[1]=temp;
        }
    else if(c[0]<c[2])
         {
             mi=a[0];
            temp=c[0];
            a[0]=a[2];
            c[0]=c[2];
            a[2]=a[1];
            c[2]=c[1];
            a[1]=mi;
            c[1]=temp;
         }
         else if(a[1]>a[2])
         {
             mi=a[1];
             temp=c[1];
             a[1]=a[2];
             c[1]=c[2];
             a[2]=mi;
             c[2]=temp;
         }
    for(i=0;i<3;i++)
      if(c[i]!=0)
         cout<<a[i]<<"���ƽ����Ϊ:"<<c[i]<<endl;
}
void Charge::outputGradeList(string course,int c)//ĳ��ĳ��ɼ���
{
    int k;
    Student stu[50];
            if(("����"==course))
            {
            for(k=0;k<50;k++)
            {
                if(stud[k].Sclass==c)
                {
                cout<<stud[k].Sclass<<"��"<<'\t'<<stud[k].Snum<<"��"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"����  "<<stud[k].cour[0].score<<'\t';
                cout<<endl;
                }
            }
            }
            else if(("����"==course)){
            for(k=0;k<50;k++)
            {
                if(stud[k].Sclass==c){
                cout<<stud[k].Sclass<<"��"<<'\t'<<stud[k].Snum<<"��"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"����  "<<stud[k].cour[1].score<<'\t';
                cout<<endl;}
            }
            }
            else if(("c++"==course)){
            for(k=0;k<50;k++)
            {
                if(stud[k].Sclass==c){
                cout<<stud[k].Sclass<<"��"<<'\t'<<stud[k].Snum<<"��"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"c++  "<<stud[k].cour[2].score<<'\t';
                cout<<endl;}
            }
            }
}
void Charge::outputCourseALLPersonList(string course)//ѡ��������
{
    int i;
    for(i=0;i<50&&stud[i].Sclass!=0;i++)
    {   if("����"==course)
        {
            cout<<stud[i].Sclass<<'\t'<<stud[i].Snum<<'\t'<<stud[i].Sname<<'\t';
            cout<<"����"<<"--"<<stud[i].cour[0].score<<'\t';
            cout<<endl;
        }
        else if("����"==course)
        {
            cout<<stud[i].Sclass<<'\t'<<stud[i].Snum<<'\t'<<stud[i].Sname<<'\t';
            cout<<"����"<<"--"<<stud[i].cour[1].score<<'\t';
            cout<<endl;
        }
        else if("c++"==course)
        {
            cout<<stud[i].Sclass<<'\t'<<stud[i].Snum<<'\t'<<stud[i].Sname<<'\t';
            cout<<"c++"<<"--"<<stud[i].cour[2].score<<'\t';
            cout<<endl;
        }
        else break;
    }
}
void Charge::outputPersonGradeList(string ID)//ѧ���ĳɼ���
{
    int i;
    for(i=0;i<50;i++){
            if(stud[i].Snum==ID)
            {
                cout<<stud[i].Sclass<<"��"<<'\t'<<stud[i].Snum<<"��"<<'\t'<<stud[i].Sname<<'\t';
                if(Studentmath[i])
               {
                   cout<<"������  ";
                   cout<<stud[i].cour[0].score;
               }
               if(Studentphy[i])
               {
                   cout<<"���  ";
                   cout<<stud[i].cour[1].score;
               }
              if(Studentc[i])
              {
                   cout<<"c++��   ";
                   cout<<stud[i].cour[2].score;
              }
              cout<<endl;
            }
        }
}
int Charge::MaxNum() //����ϵͳ�Ѿ��洢������
{
	int MN = 0;
	ifstream myf;
	myf.open("StudentMaxNum.txt");
	myf>>MN;
	cout<<MN<<'\b';
	myf.close();
	return MN;
}
void Charge::NewInfo() //�����ѧ������
{
    DBOperate dbo;
    dbo.ReadOut();
    int flag=0;
    int i;
    int MaxNum = Charge::MaxNum();
    cout<<"��ѧ��ѧ��:";
    cin>>Studentnum;
    for(i=0;i<Charge::MaxNum();i++)
    {
        if(Studentnum==stud[i].Snum)
        {
            cout<<"��ѧ���Ѵ���!"<<endl;flag=1;break;
        }
    }
    if(flag==0)
    {
        cout<<"��ѧ������: ";
        cin>>Studentname;
        cout<<"��ѧ���༶: ";
        cin>>Studentclass;
        cout<<"������ѡ���ѧ�ڣ�1/2����";
        cin>>Studentterm;
        if(Studentterm==1)
        {
            cout<<"ѡ��γ̣�ѡ����1����ѡ����0��:";
            cout<<"������";
            cin>>Studenmath;
            cout<<"���";
            cin>>Studenphy;
            cout<<"c++��";
            cin>>Studenc;
        }
        if(Studenmath)
        {
            cout<<"��������ɼ���";
            cin>>mathscore;
            stud[MaxNum].cour[0].score=mathscore;
        }
        if(Studenphy)
        {
            cout<<"�������ɼ���";
            cin>>physcore;
            stud[MaxNum].cour[1].score=physcore;
        }
        if(Studenc)
        {
            cout<<"����c++�ɼ���";
            cin>>cscore;
            stud[MaxNum].cour[2].score=cscore;
        }
        stud[MaxNum].Snum=Studentnum;
        stud[MaxNum].Sname=Studentname;
        stud[MaxNum].Sclass=Studentclass;
        Studentmath[MaxNum]=Studenmath;
        Studentphy[MaxNum]=Studenphy;
        Studentc[MaxNum]=Studenc;
	    dbo.WriteIn(1);
        cout<<" ����³�Ա�ɹ���"<<endl;
	    return;
	}
	else return;
}
void Charge::RefreshInfo() //�޸�ѧ����Ϣ�ĺ���
{
	string cNum;
	char ch;
	DBOperate dbo;
	dbo.ReadOut();
	cout<<"��������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
	cin>>cNum;
	int MN;
	MN=Charge::MaxNum();
	for(int i=0;i<MN;i++) //���������ļ�������Ҫ�޸ĵ�ѧ������
	{
		if(stud[i].Snum == cNum)
		{
			cout<<"�Ƿ�ȷ���޸ģ���N/Y��";
			cin>>ch;
			if(ch=='Y'||ch=='y')
			{
			if(Studentmath[i])
        {
            cout<<"��������ɼ���";
            cin>>mathscore;
            stud[i].cour[0].score=mathscore;
        }
        if(Studentphy[i])
        {
            cout<<"�������ɼ���";
            cin>>physcore;
            stud[i].cour[1].score=physcore;
        }
        if(Studentc[i])
        {
            cout<<"����c++�ɼ���";
            cin>>cscore;
            stud[i].cour[2].score=cscore;
        }
            }
            else
			break;
		}
	}

	dbo.WriteIn(0);
}
void Charge::DeleteInfo() //ɾ��ѧ�����ݵĺ���
{
	char tmp;
	string cNum ;
	DBOperate dbo;
	dbo.ReadOut();
	cout<<"��������Ҫɾ����ѧ��ѧ��>�� ";
	cin>>cNum;
	int MN,i=0;
	MN = Charge::MaxNum();
	for(i=0;i<MN;i++) //���������ļ�������Ҫɾ����ѧ��
	{
		if(stud[i].Snum == cNum)
            break;
	}

	cout<<"ȷ��Ҫɾ����ѧ����Ϣ��(YΪȷ��,NΪ����)�� ";
	cin>>tmp;
	if(tmp=='Y'||tmp=='y')
	{
		if(i==MN-1)
			dbo.WriteIn(-1);
		else
		{
			for(int j=i;j<MN-1;j++)
			{ stud[j].Snum = stud[j+1].Snum; }
			dbo.WriteIn(-1);
		}
		cout<<" ɾ�������ɹ� ! "<<endl;
	}
}
char Exit()//�˳�����ϵͳ
{
 char c;
 cout<<"��ȷ��Ҫ�˳�����ô��[Y/N]:";
 cin>>c;
 return c;
}
int main()
{
 int option,n1;
 char c;
 string si,sc0;
 Charge e;
 DBOperate dbo;
 system("color 5E");
 system("cls");
 loop: cout<<endl;
 cout<<"********�� ӭ �� �� �� ѧ �� �� �� �� ϵ ͳ !********"<<endl;
 cout<<"*****  1.���ѧ����Ϣ                           *****"<<endl;
 cout<<"*****  2.�޸�ѧ����Ϣ                           *****"<<endl;
 cout<<"*****  3.ɾ��ѧ����Ϣ                           *****"<<endl;
 cout<<"*****  4.��ѯĳ�ſγ̲����������               *****"<<endl;
 cout<<"*****  5.��ѯĳ�ſγ�ȫ�꼶ǰ5��                *****"<<endl;
 cout<<"*****  6.��ѯÿ�����ĳ�ſγ�ƽ���ɼ�           *****"<<endl;
 cout<<"*****  7.��ѯĳ��ĳ�ſγ̵ĳɼ���               *****"<<endl;
 cout<<"*****  8.��ѯĳ�ſγ̵�ѡ��������               *****"<<endl;
 cout<<"*****  9.��ѯĳ�˱�ѧ�ڵĳɼ���                 *****"<<endl;
 cout<<"*****  0.�˳���ϵͳ                             *****"<<endl;
 cout<<endl;
 cout<<"�� ��ѡ��(������Ӧ����):"<<endl;
   cin>>option;
   switch(option)
   {
   case 0:
    c=Exit();
    if(c=='Y'||c=='y')
     return 0;
    else
        goto loop;
   case 1:
    system("cls");
    e.NewInfo();
    goto loop;
    case 2:
    system("cls");
    dbo.ReadOut();
    e.RefreshInfo();
    goto loop;
    case 3:
    system("cls");
    dbo.ReadOut();
    e.DeleteInfo();
    goto loop;
    break;
   case 4:
    system("cls");
    dbo.ReadOut();
    cout<<"����������Ҫ���ſγ̵Ĳ���������:"<<endl;
    cin>>sc0;
    e.outputFailor(sc0);
    goto loop;
    break;
   case 5:
    system("cls");
    dbo.ReadOut();
    cout<<"����������Ҫ���ſγ̵�ȫ�꼶��ǰ����:"<<endl;
    cin>>sc0;
    e.outputFirstFive(sc0);
    goto loop;
    break;
   case 6:
    system("cls");
    dbo.ReadOut();
    cout<<"����������Ҫ���ſγ̵�ÿ���ƽ���ɼ�:"<<endl;
    cin>>sc0;
    e.outputAverage(sc0);
    goto loop;
    break;
   case 7:
    system("cls");
    dbo.ReadOut();
    cout<<"����������Ҫ���ſγ̡��ĸ���ĳɼ���:"<<endl;
    cin>>sc0>>n1;
    e.outputGradeList(sc0,n1);
    goto loop;
    break;
   case 8:
    system("cls");
    dbo.ReadOut();
    cout<<"����������Ҫ���ſγ̵�����ѡ��������:"<<endl;
    cin>>sc0;
    e.outputCourseALLPersonList(sc0);
    goto loop;
    break;
   case 9:
    system("cls");
    dbo.ReadOut();
    cout<<"����������Ҫ�ĸ�ѧ���ĳɼ���:"<<endl;
    cin>>si;
    e.outputPersonGradeList(si);
    goto loop;
    break;
   default:
    cout<<"�����������������."<<endl;
    goto loop;
   }
   return 0;
}

