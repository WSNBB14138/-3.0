#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUD_N 30
#define N 6
/**************************
** 文件名:test6
** 创建人:晁鑫涛
** 日 期:2020.10.28
** 修改人：晁鑫涛
** 描 述:教务系统3.0  已增强其健壮性与鲁棒性
**------------------------
*************************/
int Menu_choose(int judge);
void Readscore(int score[][N],long num[],int n,int m,char name[][30],int bpscore[][N],long bpnum[],char bpname[][30],int sum[],float aver[]);//读入数据
void Shuchu(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//按已有顺序输出数据
void Datasort_1(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//按总分从高到低来排序
void Datasort_2(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//按总分从低到高来排序
void Numpai(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//按学号从小到大来排
void Namepai(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//按姓名在字典从小到大来排
void Numsearch(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//学号查找
void Namesearch(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//姓名查找
void Scoresort(int score[][N],int n,int m);//等级分类
void Swapl(long *x,long *y);//long型变量交换
void Swapi( int*x,int *y);//int型变量交换
void Swapf( float*x,float *y);//float型变量交换
void Sumaver(int score[][N],int i,int m);//输出学生总分和平均分（不含各科分数）
void lessonaver(int score[][N],int n,int m);//输出各科总分和平均分
int main()
{
    printf("晁鑫涛Number:200320718\nsubject No.6-program No.1\n");
    int a,n,m,ret,i,judge=0;
    int  score[STUD_N][N],bpscore[STUD_N][N];
    char name[STUD_N][30],bpname[STUD_N][30];
    long num[STUD_N],bpnum[STUD_N];
    int sum[STUD_N]={0};
    float aver[STUD_N]={0};
    do
    {
        a=Menu_choose(judge);
        switch (a)//依据选项对应使用不同函数
        {
        case 1:
            printf("请输入总学生个数(不超过30人)\n");
            ret=scanf("%d",&n);
            while(ret!=1||n<1||n>30)
            {
                printf("请输入正确的人数\n");
                fflush(stdin);
                ret=scanf("%d",&n);
            }//健壮性
            printf("请输入课程数\n");
            ret=scanf("%d",&m);
            while(ret!=1||m<1||m>6)
            {
                printf("请输入正确课程门数\n");
                fflush(stdin);
                ret=scanf("%d",&m);
            }//健壮性
            Readscore(score,num,n,m,name,bpscore,bpnum,bpname,sum,aver);
            judge=1;
            break;
        case 2:
            Shuchu(num,name,score,sum,aver,n,m);
            break;
        case 3:
            lessonaver(score,n,m);
            break;
        case 4:
            for(i=0;i<n;i++)
            {
                printf("学号为%ld的同学%s",bpnum[i],bpname[i]);
                Sumaver(score,i,m);
            }
            break;
        case 5:
            Datasort_1(num,name,score,sum,aver,n,m);
            printf("按总分从高到低来排：\n");
            Shuchu(num,name,score,sum,aver,n,m);
            break;
        case 6:
            Datasort_2(num,name,score,sum,aver,n,m);
            printf("按总分从低到高来排：\n");
            Shuchu(num,name,score,sum,aver,n,m);
            break;
        case 7:
            Numpai(num,name,score,sum,aver,n,m);
            printf("按学号从小到大来排：\n");
            Shuchu(num,name,score,sum,aver,n,m);
            break;
        case 8:
            Namepai(num,name,score,sum,aver,n,m);
            printf("按姓名在字典从小到大来排：\n");
            Shuchu(num,name,score,sum,aver,n,m);
            break;
        case 9:
            Datasort_1(num,name,score,sum,aver,n,m);
            Numsearch(num,name,score,sum,aver,n,m);
            break;
        case 10:
            Datasort_1(num,name,score,sum,aver,n,m);
            Namesearch(num,name,score,sum,aver,n,m);
            break;
        case 11:
            Scoresort(score,n,m);
            break;
        }
    }
    while(a!=0);
    return 0;
}
/**********************************
** 函数名:Menu_choose
** 输 入:无
** 输出：a--选项
** 功能描述:打印菜单选项
************************************/
int Menu_choose(int judge)
{
    int a=12;
    printf("\n\n1．Input record\n2．List record\n");
    printf("3. Calculate total and average score of course\n");
    printf("4. Calculate total and average score of every student\n");
    printf("5. Sort in descending order by score\n");
    printf("6. Sort in ascending order by score\n");
    printf("7. Sort in ascending order by StudentID\n");
    printf("8． Sort in dictionary order by name\n");
    printf("9. Search by StudentID\n");
    printf("10. Search by name\n");
    printf("11.Statistic analysis\n");
    printf("0. Exit\n");
    printf("Please enter your choice:\n\n");
    scanf("%d",&a);
    while(a!=0&&a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7&&a!=8&&a!=9&&a!=10&&a!=11)//确保输入的所给编号
    {
        printf("请输入正确的编号\n");
        fflush(stdin);
        scanf("%d",&a);
    }
    if(a==1||a==0)
    {
        return a;
    }
    else
    {
        if(judge)
            return a;
        else
            printf("请先录入成绩");
            return 12;
    }
}

/**********************************
** 函数名:Readscore
** 输 入:score num n name bpscore bpnum bpname
** score:学生分数数组score[n]
** num:学生学号数组num[n]
** n:学生人数
** name:学生名字
** bpscore bpnum bpname:相应备份
** 输出：无
** 功能描述:读入学生学号及对应分数
************************************/
void Readscore(int score[][N],long num[],int n,int m,char name[][30],int bpscore[][N],long bpnum[],char bpname[][30],int sum[],float aver[])
{
    int i,j;
    for(i=0; i<n; i++)
    {
        printf("第%d位学生的学号为\n",i+1);
        scanf("%ld",&num[i]);
        printf("该学生的姓名为：\n");
        scanf("%s",name[i]);
        printf("该学生的各科成绩为：(以回车间隔)\n");
        for(j=0; j<m; j++)
        {
            scanf(" %d",&score[i][j]);
        }
    }
    for(i=0; i<n; i++)
    {
        bpnum[i]=num[i];
        for(j=0; j<30; j++)
        {
            bpname[i][j]=name[i][j];
        }
        for(j=0; j<m; j++)
        {
            bpscore[i][j]=score[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            sum[i]+=score[i][j];
        }
        aver[i]=(float)sum[i]/m;
    }
}

/**********************************
** 函数名:Datasort_1
** 输 入:sum num n
** sum:学生分数数组sum[n]
** num:学生学号数组num[n]
** n:学生人数
** 输出：无
** 功能描述:依次按成绩由高到低排序
************************************/
void Datasort_1(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m)
{
    int i,j,k;
    char op[30];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(sum[j]>sum[i])
            {
                Swapi(&sum[j],&sum[i]);
                Swapl(&num[j],&num[i]);
                Swapf(&aver[j],&aver[i]);
                strcpy(op,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],op);
                for(k=0;k<m;k++)
                {
                    Swapi(&score[j][k],&score[i][k]);
                }
            }
        }
    }

}
/**********************************
** 函数名:Datasort_2
** 输 入:sum num n
** sum:学生分数数组sum[n]
** num:学生学号数组num[n]
** n:学生人数
** 输出：无
** 功能描述:依次按成绩由低到高排序
************************************/
void Datasort_2(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m)
{
    int i,j,k;
    char op[30];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(sum[j]<sum[i])
            {
                Swapi(&sum[j],&sum[i]);
                Swapl(&num[j],&num[i]);
                Swapf(&aver[j],&aver[i]);
                strcpy(op,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],op);
                for(k=0;k<m;k++)
                {
                    Swapi(&score[j][k],&score[i][k]);
                }
            }
        }
    }

}
/**********************************
** 函数名:Numpai
** 输 入:score num n
** score:学生分数数组score[n]
** num:学生学号数组num[n]
** n:学生人数
** 输出：无
** 功能描述:依次按学号由低到高排序
************************************/
void Numpai(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m)
{
    int i,j,k;
    char op[30];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(num[j]<num[i])
            {
                Swapi(&sum[j],&sum[i]);
                Swapl(&num[j],&num[i]);
                Swapf(&aver[j],&aver[i]);
                strcpy(op,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],op);
                for(k=0;k<m;k++)
                {
                    Swapi(&score[j][k],&score[i][k]);
                }
            }
        }
    }

}

/**********************************
** 函数名:Namepai
** 输 入:score num n
** score:学生分数数组score[n]
** num:学生学号数组num[n]
** n:学生人数
** 输出：无
** 功能描述:依次按字典顺序排序
************************************/
void Namepai(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m)
{
    int i,j,k;
    char op[30];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(strcmp(name[j],name[i])<0)
            {
                Swapi(&sum[j],&sum[i]);
                Swapl(&num[j],&num[i]);
                Swapf(&aver[j],&aver[i]);
                strcpy(op,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],op);
                for(k=0;k<m;k++)
                {
                    Swapi(&score[j][k],&score[i][k]);
                }
            }
        }
    }

}
/**********************************
** 函数名:Numsearch
** 输 入:score num n find name
** name:姓名
** score:学生分数数组score[n]
** num:学生学号数组num[n]
** n:学生人数
** find：需要查找的学号
** 输出：无
** 功能描述:
通过输入的学号查找相应的学号,姓名及成绩
************************************/
void Numsearch(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m)
{
    int i,j,k,jet=0;
    long need=0;
    printf("请输入你要查找的学号\n");
    scanf("%ld",&need);
    for(i=0; i<n; i++)
    {
        if(need==num[i])
        {
            k=i;
            jet=1;
        }
    }
    if(jet){printf("学号为%ld的学生为%s，其各科考试成绩为：",need,name[k]);
    for(j=0; j<m; j++)
    {
        printf("%4d",score[k][j]);
    }
    printf("\n其总分与平均分分别为%d %.2f，排名为%d\n",sum[k],aver[k],k+1);}
    else
        printf("无该学号学生\n");
}

/**********************************
** 函数名:Namesearch
** 输 入:score num n
** score:学生分数数组score[n]
** num:学生学号数组num[n]
** n:学生人数
** find2:寻找姓名
** 输出：无
** 功能描述:依次按学号由低到高排序strcmp(find2,name[i])==0
************************************/
void Namesearch(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m)
{
    int i,j,k,jet=1;
    char need[30];
    printf("请输入你要查找的姓名\n");
    getchar();
    scanf("%s",need);
    for(i=0; i<n; i++)
    {
        if((strcmp(need,name[i])==0))
        {
            k=i;
            jet=0;
        }
    }
    if(jet==0)
    {
        printf("学号为%ld的学生为%s，其各科考试成绩为：",num[k],name[k]);
        for(j=0; j<m; j++)
        {
            printf("%4d",score[k][j]);
        }
        printf("\n其总分与平均分分别为%d %.2f，排名为%d\n",sum[k],aver[k],k+1);
    }
    else
        printf("无该姓名学生\n");
}

/**********************************
** 函数名:Scoresort
** 输 入:score num n
** score:学生分数数组score[n]
** num:学生学号数组num[n]
** n:学生人数
** 输出：无
** 功能描述:依据成绩进行分类，并算出各类百分比
************************************/
void Scoresort(int score[][N],int n,int m)
{
    int counter[m][5],i,j;  float a[m][5];
    for(j=0; j<m; j++)
    {
        for(i=0; i<5; i++)
        {
            counter[j][i]=0;
        }
        for(i=0; i<n; i++)
        {
            if(score[i][j]>=90&&score[i][j]<=100)
                counter[j][0]++;
            else if(score[i][j]>=80&&score[i][j]<90)
                    counter[j][1]++;
            else if(score[i][j]>=70&&score[i][j]<80)
                    counter[j][2]++;
            else if(score[i][j]>=60&&score[i][j]<70)
                    counter[j][3]++;
            else if(score[i][j]>=0&&score[i][j]<60)
                    counter[j][4]++;
        }
        for(i=0; i<5; i++)
        {
        a[j][i]=((float)counter[j][i]/n*100);
        }
}
    for(j=0;j<m;j++)
    {
        printf("第%d门课程中:\n",j+1);
        printf("处于优秀等级(90-100分)的人数为%d,占总人数的%.2f%%\n",counter[j][0],a[j][0]);
        printf("处于良好等级(80-89分)的人数为%d,占总人数的%.2f%%\n",counter[j][1],a[j][1]);
        printf("处于中等等级(70-79分)的人数为%d,占总人数的%.2f%%\n",counter[j][2],a[j][2]);
        printf("处于及格等级(60-69分)的人数为%d,占总人数的%.2f%%\n",counter[j][3],a[j][3]);
        printf("处于不及格等级(0-59分)的人数为%d,占总人数的%.2f%%\n",counter[j][4],a[j][4]);
    }
}
void Swapl(long *x,long *y)//long型数组变量交换
{
    long temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void Swapi( int*x,int *y)//int型变量交换
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void Swapf( float*x,float *y)//float型变量交换
{
    float temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void Sumaver(int score[][N],int i,int m)
{
    int j,sum=0;
    float aver;
    for(j=0; j<m; j++)
    {
        sum+=score[i][j];
    }
    aver=(float)sum/m;
    printf("  总分为%d，平均分为%.2f\n",sum,aver);
}
void lessonaver(int score[][N],int n,int m)
{
    int i,j,sum=0;
    float aver;
    for(j=0; j<m; j++)
    {
        for(i=0; i<n; i++)
        {
            sum+=score[i][j];
        }
        aver=(float)sum/n;
        printf("第%d科的课程的总分与平均分分别为%4d与%.2f\n",j+1,sum,aver);
    }
}
void Shuchu(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        printf("学号为%ld的学生为%s",num[i],name[i]);
        printf("其各科成绩分别为");
        for(j=0; j<m; j++)
        {
            printf("%4d",score[i][j]);
        }
        printf("\n其总成绩为%d,平均分为%.2f\n",sum[i],aver[i]);
    }
}
