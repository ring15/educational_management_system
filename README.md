# educational_management_system

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
    int Studenmath; //高数成绩
    int Studenphy; //物理成绩
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
void DBOperate::WriteIn(int iflag) //数据操作函数—写入
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
	    my<<"高数：  "<<Studentmath[i]<<'\t'<<"大物:  "<<Studentphy[i]<<'\t'<<"c++:  "<<Studentc[i]<<'\n';
	}
	myf.close();
	my.close();
	return;
}
void DBOperate::ReadOut() //数据操作函数—读出
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
void DBOperate::RefreshMaxNum(int iflag) //更新系统中学生计数文件的函数
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
void Charge::outputFailor(string course)//不及格名单
{
    int i;
    for(i=0;i<50&&stud[i].Sclass!=0;i++)
        {
            if(("高数"==course)&&stud[i].cour[0].score<60)
            {
                cout<<stud[i].Sclass<<"班"<<'\t'<<stud[i].Snum<<"号"<<'\t'<<stud[i].Sname<<'\t';
                cout<<"高数  "<<stud[i].cour[0].score<<'\t';
                cout<<endl;
            }
            else if(("大物"==course)&&stud[i].cour[1].score<60)
            {
                cout<<stud[i].Sclass<<"班"<<'\t'<<stud[i].Snum<<"号"<<'\t'<<stud[i].Sname<<'\t';
                cout<<"大物  "<<stud[i].cour[1].score<<'\t';
                cout<<endl;
            }
            else if(("c++"==course)&&stud[i].cour[2].score<60)
            {
                cout<<stud[i].Sclass<<"班"<<'\t'<<stud[i].Snum<<"号"<<'\t'<<stud[i].Sname<<'\t';
                cout<<"c++  "<<stud[i].cour[2].score<<'\t';
                cout<<endl;
            }
        }
}
void Charge::outputFirstFive(string course)//全年级的前五名
{
    int i,j,k;
    Student stu[50];
    for(i=0;i<50;i++)
        for(j=i+1;j<50;j++)
        {
            if(("高数"==course)){
            if(stud[i].cour[0].score<stud[j].cour[0].score)
            {stu[i]=stud[i];
            stud[i]=stud[j];
            stud[j]=stu[i];}
            for(k=0;k<5;k++)
            {
                cout<<stud[k].Sclass<<"班"<<'\t'<<stud[k].Snum<<"号"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"高数  "<<stud[k].cour[0].score<<'\t';
                cout<<endl;
            }
            goto loop;
            }
            else if(("大物"==course)){
            if(stud[i].cour[1].score<stud[j].cour[1].score)
            {stu[i]=stud[i];
            stud[i]=stud[j];
            stud[j]=stu[i];}
            for(k=0;k<5;k++)
            {
                cout<<stud[k].Sclass<<"班"<<'\t'<<stud[k].Snum<<"号"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"大物  "<<stud[k].cour[1].score<<'\t';
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
                cout<<stud[k].Sclass<<"班"<<'\t'<<stud[k].Snum<<"号"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"c++  "<<stud[k].cour[2].score<<'\t';
                cout<<endl;
            }
            goto loop;
            }
            else goto loop;
        }
        loop:cout<<" ";
}
void Charge::outputAverage(string course)//每班的平均成绩
{
    int i,j,k;
    int t,t1,t2,t3;
    int a[3]={1,2,3,};//共5个班
    int b[3]={0,0,0};//统计每个班人数
    int sum[3]={0,0,0};//统计每个班分数总和
    double c[3]={0,0,0},temp,mi;   //每个班平均成
    for(k=0;k<3;k++)
    {
        for(i=0;i<50;i++)
        {
            if(("高数"==course)&&stud[i].Sclass==a[k])
            {
               sum[k]+=stud[i].cour[0].score;
               b[k]++;
            }
            else  if(("大物"==course)&&stud[i].Sclass==a[k])
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
         cout<<a[i]<<"班的平均分为:"<<c[i]<<endl;
}
void Charge::outputGradeList(string course,int c)//某科某班成绩单
{
    int k;
    Student stu[50];
            if(("高数"==course))
            {
            for(k=0;k<50;k++)
            {
                if(stud[k].Sclass==c)
                {
                cout<<stud[k].Sclass<<"班"<<'\t'<<stud[k].Snum<<"号"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"高数  "<<stud[k].cour[0].score<<'\t';
                cout<<endl;
                }
            }
            }
            else if(("大物"==course)){
            for(k=0;k<50;k++)
            {
                if(stud[k].Sclass==c){
                cout<<stud[k].Sclass<<"班"<<'\t'<<stud[k].Snum<<"号"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"大物  "<<stud[k].cour[1].score<<'\t';
                cout<<endl;}
            }
            }
            else if(("c++"==course)){
            for(k=0;k<50;k++)
            {
                if(stud[k].Sclass==c){
                cout<<stud[k].Sclass<<"班"<<'\t'<<stud[k].Snum<<"号"<<'\t'<<stud[k].Sname<<'\t';
                cout<<"c++  "<<stud[k].cour[2].score<<'\t';
                cout<<endl;}
            }
            }
}
void Charge::outputCourseALLPersonList(string course)//选修者名单
{
    int i;
    for(i=0;i<50&&stud[i].Sclass!=0;i++)
    {   if("高数"==course)
        {
            cout<<stud[i].Sclass<<'\t'<<stud[i].Snum<<'\t'<<stud[i].Sname<<'\t';
            cout<<"高数"<<"--"<<stud[i].cour[0].score<<'\t';
            cout<<endl;
        }
        else if("大物"==course)
        {
            cout<<stud[i].Sclass<<'\t'<<stud[i].Snum<<'\t'<<stud[i].Sname<<'\t';
            cout<<"大物"<<"--"<<stud[i].cour[1].score<<'\t';
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
void Charge::outputPersonGradeList(string ID)//学生的成绩单
{
    int i;
    for(i=0;i<50;i++){
            if(stud[i].Snum==ID)
            {
                cout<<stud[i].Sclass<<"班"<<'\t'<<stud[i].Snum<<"号"<<'\t'<<stud[i].Sname<<'\t';
                if(Studentmath[i])
               {
                   cout<<"高数：  ";
                   cout<<stud[i].cour[0].score;
               }
               if(Studentphy[i])
               {
                   cout<<"大物：  ";
                   cout<<stud[i].cour[1].score;
               }
              if(Studentc[i])
              {
                   cout<<"c++：   ";
                   cout<<stud[i].cour[2].score;
              }
              cout<<endl;
            }
        }
}
int Charge::MaxNum() //返回系统已经存储的人数
{
	int MN = 0;
	ifstream myf;
	myf.open("StudentMaxNum.txt");
	myf>>MN;
	cout<<MN<<'\b';
	myf.close();
	return MN;
}
void Charge::NewInfo() //添加新学生函数
{
    DBOperate dbo;
    dbo.ReadOut();
    int flag=0;
    int i;
    int MaxNum = Charge::MaxNum();
    cout<<"新学生学号:";
    cin>>Studentnum;
    for(i=0;i<Charge::MaxNum();i++)
    {
        if(Studentnum==stud[i].Snum)
        {
            cout<<"该学生已存在!"<<endl;flag=1;break;
        }
    }
    if(flag==0)
    {
        cout<<"新学生姓名: ";
        cin>>Studentname;
        cout<<"新学生班级: ";
        cin>>Studentclass;
        cout<<"请输入选择的学期（1/2）：";
        cin>>Studentterm;
        if(Studentterm==1)
        {
            cout<<"选择课程（选输入1，不选输入0）:";
            cout<<"高数：";
            cin>>Studenmath;
            cout<<"大物：";
            cin>>Studenphy;
            cout<<"c++：";
            cin>>Studenc;
        }
        if(Studenmath)
        {
            cout<<"输入高数成绩：";
            cin>>mathscore;
            stud[MaxNum].cour[0].score=mathscore;
        }
        if(Studenphy)
        {
            cout<<"输入大物成绩：";
            cin>>physcore;
            stud[MaxNum].cour[1].score=physcore;
        }
        if(Studenc)
        {
            cout<<"输入c++成绩：";
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
        cout<<" 添加新成员成功！"<<endl;
	    return;
	}
	else return;
}
void Charge::RefreshInfo() //修改学生信息的函数
{
	string cNum;
	char ch;
	DBOperate dbo;
	dbo.ReadOut();
	cout<<"请输入您要修改的学生学号：";
	cin>>cNum;
	int MN;
	MN=Charge::MaxNum();
	for(int i=0;i<MN;i++) //遍历数据文件，查找要修改的学生数据
	{
		if(stud[i].Snum == cNum)
		{
			cout<<"是否确认修改？（N/Y）";
			cin>>ch;
			if(ch=='Y'||ch=='y')
			{
			if(Studentmath[i])
        {
            cout<<"输入高数成绩：";
            cin>>mathscore;
            stud[i].cour[0].score=mathscore;
        }
        if(Studentphy[i])
        {
            cout<<"输入大物成绩：";
            cin>>physcore;
            stud[i].cour[1].score=physcore;
        }
        if(Studentc[i])
        {
            cout<<"输入c++成绩：";
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
void Charge::DeleteInfo() //删除学生数据的函数
{
	char tmp;
	string cNum ;
	DBOperate dbo;
	dbo.ReadOut();
	cout<<"请输入您要删除的学生学号>： ";
	cin>>cNum;
	int MN,i=0;
	MN = Charge::MaxNum();
	for(i=0;i<MN;i++) //遍历数据文件，查找要删除的学生
	{
		if(stud[i].Snum == cNum)
            break;
	}

	cout<<"确认要删除该学生信息？(Y为确认,N为放弃)： ";
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
		cout<<" 删除操作成功 ! "<<endl;
	}
}
char Exit()//退出操作系统
{
 char c;
 cout<<"●确定要退出程序么？[Y/N]:";
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
 cout<<"********欢 迎 来 到 教 学 事 务 管 理 系 统 !********"<<endl;
 cout<<"*****  1.添加学生信息                           *****"<<endl;
 cout<<"*****  2.修改学生信息                           *****"<<endl;
 cout<<"*****  3.删除学生信息                           *****"<<endl;
 cout<<"*****  4.查询某门课程不及格的名单               *****"<<endl;
 cout<<"*****  5.查询某门课程全年级前5名                *****"<<endl;
 cout<<"*****  6.查询每个班的某门课程平均成绩           *****"<<endl;
 cout<<"*****  7.查询某班某门课程的成绩单               *****"<<endl;
 cout<<"*****  8.查询某门课程的选修者名单               *****"<<endl;
 cout<<"*****  9.查询某人本学期的成绩单                 *****"<<endl;
 cout<<"*****  0.退出本系统                             *****"<<endl;
 cout<<endl;
 cout<<"● 请选择(输入相应数字):"<<endl;
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
    cout<<"●请问您想要哪门课程的不及格名单:"<<endl;
    cin>>sc0;
    e.outputFailor(sc0);
    goto loop;
    break;
   case 5:
    system("cls");
    dbo.ReadOut();
    cout<<"●请问您想要哪门课程的全年级的前五名:"<<endl;
    cin>>sc0;
    e.outputFirstFive(sc0);
    goto loop;
    break;
   case 6:
    system("cls");
    dbo.ReadOut();
    cout<<"●请问您想要哪门课程的每班的平均成绩:"<<endl;
    cin>>sc0;
    e.outputAverage(sc0);
    goto loop;
    break;
   case 7:
    system("cls");
    dbo.ReadOut();
    cout<<"●请问您想要哪门课程、哪个班的成绩单:"<<endl;
    cin>>sc0>>n1;
    e.outputGradeList(sc0,n1);
    goto loop;
    break;
   case 8:
    system("cls");
    dbo.ReadOut();
    cout<<"●请问您想要哪门课程的所有选修者名单:"<<endl;
    cin>>sc0;
    e.outputCourseALLPersonList(sc0);
    goto loop;
    break;
   case 9:
    system("cls");
    dbo.ReadOut();
    cout<<"●请问您想要哪个学生的成绩单:"<<endl;
    cin>>si;
    e.outputPersonGradeList(si);
    goto loop;
    break;
   default:
    cout<<"输入错误，请重新输入."<<endl;
    goto loop;
   }
   return 0;
}

