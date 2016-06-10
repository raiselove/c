#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000//通讯录中最大存储人数
//功能
enum OP
{
          EXIT,
          ADD,
          FIND,
          SHOW,
          MODIFY,
          DELE,
          EMPTY,
          SORT
};
//个人信息
typedef struct Stu
{
           char name[10];
           char sex[3];
           int age;
           char dele[12];
           char add[30];
}Stu;
//通讯录
typedef struct TongXunLu
{
           Stu stu[1000];
           int count;
}TXL,* ptxl;
void initiate(ptxl ptxl);//启动
void add(ptxl ptxl);//添加通讯录中的人，最多添加1000个
void find(ptxl ptxl);//在通讯录中查找需要查找的人，按姓名查找
void show(ptxl ptxl);//显示当前通讯录中所有人
void modify(ptxl ptxl);//修改通讯录中某一人的信息
void dele(ptxl ptxl);//删除通讯录中某一人的信息
void empty(ptxl ptxl);//清空通讯录中所有人信息
void sort(ptxl ptxl);//排序通讯录中的所有人，按名字排序的
void menu();//菜单
static int hanshu(ptxl ptxl, const char * name)
{
           int i = 0;
           for (i = 0; i < ptxl ->count; i++)
          {
                    if (strcmp(name , ptxl->stu[i].name) == 0)
                   {
                              return i;
                   }
          }
           return -1;
}
void initiate(ptxl ptxl)
{
           ptxl->count = 0;
}
void add(ptxl ptxl)
{
           if (ptxl ->count == MAX)
          {
                   printf( "电话本已满，无法添加!" );
                    return;
          }
          printf( "姓名:");
          scanf( "%s", ptxl ->stu[ptxl->count].name);
          printf( "性别:");
          scanf( "%s", ptxl ->stu[ptxl->count].sex);
          printf( "年龄:");
          scanf( "%d", &ptxl ->stu[ptxl->count].age);
          printf( "电话:");
          scanf( "%s", ptxl ->stu[ptxl->count].dele);
          printf( "住址:");
          scanf( "%s", ptxl ->stu[ptxl->count].add);
           ptxl->count++;
          printf( "添加成功!" );
}
void find(ptxl ptxl)
{
           int ret = 0;
           char name[10];
          printf( "请输入要查找人的姓名:" );
          scanf( "%s", name);
          ret = hanshu( ptxl, name);
           if (ret == -1)
          {
                   printf( "不存在要查找的人!\n" );
                    return;
          }
           else
          {
                   printf( "姓名\t性别\t年龄\t电话\t\t住址\n" );
                   printf( "%s\t%s\t%d\t%s\t%2s\n" , ptxl->stu[ret].name, ptxl->stu[ret].sex, ptxl ->stu[ret].age, ptxl->stu[ret].dele, ptxl->stu[ret].add);
          }

}
void show(ptxl ptxl)
{
           int i = 0;
          printf( "姓名\t性别\t年龄\t电话\t\t住址\n" );
           for (i = 0; i < ptxl ->count; i++)
          {
                   printf( "%s\t%s\t%d\t%s\t%2s\n" , ptxl->stu[i].name, ptxl->stu[i].sex, ptxl ->stu[i].age, ptxl->stu[i].dele, ptxl->stu[i].add);
          }
}
void modify(ptxl ptxl)
{
           int ret = 0;
           char name[10];
          printf( "请输入要修改人的姓名:" );
          scanf( "%s", name);
          ret = hanshu( ptxl, name);
           if (ret == -1)
          {
                   printf( "不存在要修改的人!\n" );
                    return;
          }
           else
          {
                   printf( "姓名:");
                   scanf( "%s", ptxl ->stu[ret].name);
                   printf( "性别:");
                   scanf( "%s", ptxl ->stu[ret].sex);
                   printf( "年龄:");
                   scanf( "%d", &ptxl ->stu[ret].age);
                   printf( "电话:");
                   scanf( "%s", ptxl ->stu[ret].dele);
                   printf( "住址:");
                   scanf( "%s", ptxl ->stu[ret].add);
          }
}
void dele(ptxl ptxl)
{
           int ret = 0;
           int j = 0;
           char name[10];
          printf( "请输入要删除的名字:" );
          scanf( "%s", name);
          ret = hanshu( ptxl, name);
           if (ret == -1)
          {
                   printf( "删除的人不存在!\n" );
                    return;
          }
           else
          {
                    for (j = 0; j < ptxl ->count - 1; j++)
                   {
                              ptxl->stu[j] = ptxl ->stu[j + 1];
                   }
          }
           ptxl->count--;
          printf( "删除成功!\n" );
}
void empty(ptxl ptxl)
{
           ptxl->count = 0;
          printf( "通讯录以清空!\n" );
}
void sort(ptxl ptxl)
{
           int i = 0;
           int j = 0;
           for (i = 0; i < ptxl ->count; i++)
          {
                    for (j = 0; j < ptxl ->count; j++)
                   {
                              if (strcmp(ptxl ->stu[j].name, ptxl->stu[j + 1].name)>0)
                             {
                                       Stu temp = ptxl ->stu[j];
                                       ptxl->stu[j] = ptxl ->stu[j + 1];
                                       ptxl->stu[j + 1] = temp;
                             }
                   }
          }
          printf( "排序成功!\n" );
}
void menu()
{
          printf( "************************************************\n" );
          printf( "****             欢迎使用通讯录             ****\n" );
          printf( "************************************************\n" );
          printf( "         【1】添加联系人\n" );
          printf( "         【2】查找联系人\n" );
          printf( "         【3】显示联系人\n" );
          printf( "         【4】修改联系人\n" );
          printf( "         【5】删除联系人\n" );
          printf( "         【6】清空联系人\n" );
          printf( "         【7】排序联系人\n" );
          printf( "         【0】退出程序   \n" );
          printf( "------------------------------------------------\n" );
}
int main()
{
           TXL txl;
           int input = 1;
          initiate(&txl);
          system( "color a");
           while (input)
          {
                   menu();
                   printf( "请输入0~7之间的选择:" );
                   scanf( "%d", &input);
                    switch (input)
                   {
                    case ADD:add(&txl);
                              break;
                    case FIND:find(&txl);
                              break;
                    case SHOW:show(&txl);
                              break;
                    case MODIFY:modify(&txl);
                              break;
                    case DELE:dele(&txl);
                              break;
                    case EMPTY:empty(&txl);
                              break;
                    case SORT:sort(&txl);
                              break;
                    case EXIT:exit(EXIT_SUCCESS );
                              break;
                   }
          }
           return 0;
}
