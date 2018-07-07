//
//  main.cpp
//  text
//
//  Created by 20161104599 on 18/7/7.
//  Copyright © 2018年 20161104599. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <String>
#include <fstream>
#include <vector>
using namespace std;
struct Student
{
    string name;
    string sex;
    string Program;
    string form;
    string Class;
    string tel;
    int f;
    double score[10];
    double min;
    double max;
    double agv;
};
struct Referee
{
    string name;
    string sex;
    string tel;
};
struct Student s[100];
struct Referee r[100];
void Sort(Student *s,int n)
{
    int i,j;
    struct Student temp;
    for(i=0;i<s[0].f;i++)
    {
        for(j=0;j<s[0].f;j++)
        {
            if(s[j].agv<s[j+1].agv)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    cout<<"平均分排序输出"<<endl;
    for(i=0;i<n;i++)
    {
       cout<<s[i].agv<<endl;
    }
    
    
}
void input(Student *s,int n )
{
    int i,j;
    for(i=0;i<n;i++)
    {
        cout<<"输入第"<<i+1<<"个学生成绩"<<endl;
        cin>>s[i].score[0];
        cin>>s[i].score[1];
        cin>>s[i].score[2];
        cin>>s[i].score[3];
        cin>>s[i].score[4];
    }
    for(i=0; i<n; i++)
    {
        s[i].max=s[i].score[0];
        for(j=0; j<5; j++)
        {
            if(s[i].score[j]>s[i].max)
            {
                s[i].max=s[i].score[j];
            }
        }
    }
    for(i=0; i<n; i++)
    {
        s[i].min=s[i].score[0];
        for(j=0; j<5; j++)
        {
            if(s[i].score[j]<s[i].min)
            {
                s[i].min=s[i].score[j];
            }
        }
    }

    for(i=0;i<n;i++)
    {
        s[i].agv=(s[i].score[0]+s[i].score[1]+s[i].score[2]+s[i].score[3]+s[i].score[4]-s[i].min-s[i].max)/3;
    }
}

int inputs(Student *s)
{
    int n;
    cout<<"请输入参赛者人数";
    cin>>n;
    s[0].f=0;
    for(int i=0; i<n; i++)
    {
        cout<<"请输入姓名：";
        cin>>s[i].name;
        cout<<"请输入性别：";
        cin>>s[i].sex;
        cout<<"请输入节目名称：";
        cin>>s[i].Program;
        cout<<"请输入表演形式：";
        cin>>s[i].form;
        cout<<"请输入班级：";
        cin>>s[i].Class;
        cout<<"请输入电话:";
        cin>>s[i].tel;
        s[0].f++;
    }
    return n;
}
void inputr(Referee *r)
{
    int i;
    for(i=0; i<5; i++)
    {
        cout<<"请输入第"<<i+1<<"号裁判的姓名:";
        cin>>r[i].name;
        cout<<"请输入第"<<i+1<<"号裁判的性别:";
        cin>>r[i].sex;
        cout<<"请输入第"<<i+1<<"号裁判的电话:";
        cin>>r[i].tel;
    }
}
void output(Student *s,int n,Referee *r)
{
    int i;
    
    for(i=0; i<n; i++)
    {
        cout<<"第"<<i+1<<"学生";
        cout<<"|姓名|性别|节目名称|表演形式|班级|学号|"<<endl;
        cout<<"       "<<s[i].name<<"     "<<s[i].sex<<"     "<<s[i].Program<<"     "<<s[i].form<<"     "<<s[i].Class<<"     "<<s[i].tel<<"     "<<endl;
        cout<<"第一个评委"<<r[0].name<<"的打分为：";
        cout<<s[i].score[0]<<endl;
        cout<<"第二个评委"<<r[1].name<<"的打分为：";
        cout<<s[i].score[1]<<endl;
        cout<<"第三个评委"<<r[2].name<<"的打分为：";
        cout<<s[i].score[2]<<endl;
        cout<<"第四个评委"<<r[3].name<<"的打分为：";
        cout<<s[i].score[3]<<endl;
        cout<<"第五个评委"<<r[4].name<<"的打分为：";
        cout<<s[i].score[4]<<endl;
        cout<<"去掉一个最低成绩为：";
        cout<<s[i].min<<endl;
        cout<<"去掉一个最高成绩为：";
        cout<<s[i].max<<endl;
        cout<<"平均分是：";
        cout<<s[i].agv<<endl;
        
    }
}

void saveStudent(Student *s,int n)
{
    int i;
    ofstream outfile;
    outfile.open("//Users//20161104599//Desktop//text//student.csv");
    outfile<<"姓名"<<','<<"性别"<<','<<"节目名称"<<','<<"节目类型"<<','<<"班级"<<','<<"电话"<<endl;
    for(i=0;i<n;i++)
    {
        outfile<<s[i].name<<',';
        outfile<<s[i].sex<<',';
        outfile<<s[i].Program<<',';
        outfile<<s[i].form<<',';
        outfile<<s[i].Class<<',';
        outfile<<s[i].tel<<endl;
    }
}
void saveReferee(Referee *r)
    {
        int i;
        ofstream outfile;
        outfile.open("//Users//20161104599//Desktop//text//referee.csv");
        outfile<<"姓名"<<','<<"性别"<<','<<"电话"<<endl;
        for(i=0;i<5;i++)
        {
            outfile<<r[i].name<<',';
            outfile<<r[i].sex<<',';
            outfile<<r[i].tel<<endl;
        }
    }
int menu()
    {
        int item;
        cout << "|-----------------------------------------|\n";
        cout << "|-------------欢迎使用系统------------------|\n";
        cout << "|-----------------------------------------|\n";
        cout << "|------      1:输入参赛者信息         -------|\n";
        cout << "|------      2:输入裁判员信息         -------|\n";
        cout << "|------      3:输入参赛员成绩         -------|\n";
        cout << "|------      4:显示参赛员信息         -------|\n";
        cout << "|------      5:参赛者成绩排序显示      -------|\n";
        cout << "|------      6:储存信息              -------|\n";
        cout << "|------      7:退出系统              -------|\n";
        do
        {
            cout<<"请输入序号（1-7）";
            cin >> item;
            
        }while(item<1||item>7);
        return item;

    }

 

int main(int argc, const char * argv[]) {
   
        while(1)
    {
        switch(menu())
        {
            case 1:
                inputs(s);
                break;
            
            case 2:
                inputr(r);
                break;
            
            case 3:
                input(s,s[0].f);
                break;
            case 4:
                output(s,s[0].f,r);
                break;
                
            case 5:
                Sort(s,s[0].f);
                break;
            case 6:
                saveStudent(s,s[0].f);
                saveReferee(r);
                break;
            
                
                
                
        }
        
    }
    }
