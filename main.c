#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUD_N 30
#define N 6
/**************************
** �ļ���:test6
** ������:������
** �� ��:2020.10.28
** �޸��ˣ�������
** �� ��:����ϵͳ3.0  ����ǿ�佡׳����³����
**------------------------
*************************/
int Menu_choose(int judge);
void Readscore(int score[][N],long num[],int n,int m,char name[][30],int bpscore[][N],long bpnum[],char bpname[][30],int sum[],float aver[]);//��������
void Shuchu(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//������˳���������
void Datasort_1(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//���ִܷӸߵ���������
void Datasort_2(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//���ִܷӵ͵���������
void Numpai(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//��ѧ�Ŵ�С��������
void Namepai(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//���������ֵ��С��������
void Numsearch(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//ѧ�Ų���
void Namesearch(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m);//��������
void Scoresort(int score[][N],int n,int m);//�ȼ�����
void Swapl(long *x,long *y);//long�ͱ�������
void Swapi( int*x,int *y);//int�ͱ�������
void Swapf( float*x,float *y);//float�ͱ�������
void Sumaver(int score[][N],int i,int m);//���ѧ���ֺܷ�ƽ���֣��������Ʒ�����
void lessonaver(int score[][N],int n,int m);//��������ֺܷ�ƽ����
int main()
{
    printf("������Number:200320718\nsubject No.6-program No.1\n");
    int a,n,m,ret,i,judge=0;
    int  score[STUD_N][N],bpscore[STUD_N][N];
    char name[STUD_N][30],bpname[STUD_N][30];
    long num[STUD_N],bpnum[STUD_N];
    int sum[STUD_N]={0};
    float aver[STUD_N]={0};
    do
    {
        a=Menu_choose(judge);
        switch (a)//����ѡ���Ӧʹ�ò�ͬ����
        {
        case 1:
            printf("��������ѧ������(������30��)\n");
            ret=scanf("%d",&n);
            while(ret!=1||n<1||n>30)
            {
                printf("��������ȷ������\n");
                fflush(stdin);
                ret=scanf("%d",&n);
            }//��׳��
            printf("������γ���\n");
            ret=scanf("%d",&m);
            while(ret!=1||m<1||m>6)
            {
                printf("��������ȷ�γ�����\n");
                fflush(stdin);
                ret=scanf("%d",&m);
            }//��׳��
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
                printf("ѧ��Ϊ%ld��ͬѧ%s",bpnum[i],bpname[i]);
                Sumaver(score,i,m);
            }
            break;
        case 5:
            Datasort_1(num,name,score,sum,aver,n,m);
            printf("���ִܷӸߵ������ţ�\n");
            Shuchu(num,name,score,sum,aver,n,m);
            break;
        case 6:
            Datasort_2(num,name,score,sum,aver,n,m);
            printf("���ִܷӵ͵������ţ�\n");
            Shuchu(num,name,score,sum,aver,n,m);
            break;
        case 7:
            Numpai(num,name,score,sum,aver,n,m);
            printf("��ѧ�Ŵ�С�������ţ�\n");
            Shuchu(num,name,score,sum,aver,n,m);
            break;
        case 8:
            Namepai(num,name,score,sum,aver,n,m);
            printf("���������ֵ��С�������ţ�\n");
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
** ������:Menu_choose
** �� ��:��
** �����a--ѡ��
** ��������:��ӡ�˵�ѡ��
************************************/
int Menu_choose(int judge)
{
    int a=12;
    printf("\n\n1��Input record\n2��List record\n");
    printf("3. Calculate total and average score of course\n");
    printf("4. Calculate total and average score of every student\n");
    printf("5. Sort in descending order by score\n");
    printf("6. Sort in ascending order by score\n");
    printf("7. Sort in ascending order by StudentID\n");
    printf("8�� Sort in dictionary order by name\n");
    printf("9. Search by StudentID\n");
    printf("10. Search by name\n");
    printf("11.Statistic analysis\n");
    printf("0. Exit\n");
    printf("Please enter your choice:\n\n");
    scanf("%d",&a);
    while(a!=0&&a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7&&a!=8&&a!=9&&a!=10&&a!=11)//ȷ��������������
    {
        printf("��������ȷ�ı��\n");
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
            printf("����¼��ɼ�");
            return 12;
    }
}

/**********************************
** ������:Readscore
** �� ��:score num n name bpscore bpnum bpname
** score:ѧ����������score[n]
** num:ѧ��ѧ������num[n]
** n:ѧ������
** name:ѧ������
** bpscore bpnum bpname:��Ӧ����
** �������
** ��������:����ѧ��ѧ�ż���Ӧ����
************************************/
void Readscore(int score[][N],long num[],int n,int m,char name[][30],int bpscore[][N],long bpnum[],char bpname[][30],int sum[],float aver[])
{
    int i,j;
    for(i=0; i<n; i++)
    {
        printf("��%dλѧ����ѧ��Ϊ\n",i+1);
        scanf("%ld",&num[i]);
        printf("��ѧ��������Ϊ��\n");
        scanf("%s",name[i]);
        printf("��ѧ���ĸ��Ƴɼ�Ϊ��(�Իس����)\n");
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
** ������:Datasort_1
** �� ��:sum num n
** sum:ѧ����������sum[n]
** num:ѧ��ѧ������num[n]
** n:ѧ������
** �������
** ��������:���ΰ��ɼ��ɸߵ�������
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
** ������:Datasort_2
** �� ��:sum num n
** sum:ѧ����������sum[n]
** num:ѧ��ѧ������num[n]
** n:ѧ������
** �������
** ��������:���ΰ��ɼ��ɵ͵�������
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
** ������:Numpai
** �� ��:score num n
** score:ѧ����������score[n]
** num:ѧ��ѧ������num[n]
** n:ѧ������
** �������
** ��������:���ΰ�ѧ���ɵ͵�������
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
** ������:Namepai
** �� ��:score num n
** score:ѧ����������score[n]
** num:ѧ��ѧ������num[n]
** n:ѧ������
** �������
** ��������:���ΰ��ֵ�˳������
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
** ������:Numsearch
** �� ��:score num n find name
** name:����
** score:ѧ����������score[n]
** num:ѧ��ѧ������num[n]
** n:ѧ������
** find����Ҫ���ҵ�ѧ��
** �������
** ��������:
ͨ�������ѧ�Ų�����Ӧ��ѧ��,�������ɼ�
************************************/
void Numsearch(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m)
{
    int i,j,k,jet=0;
    long need=0;
    printf("��������Ҫ���ҵ�ѧ��\n");
    scanf("%ld",&need);
    for(i=0; i<n; i++)
    {
        if(need==num[i])
        {
            k=i;
            jet=1;
        }
    }
    if(jet){printf("ѧ��Ϊ%ld��ѧ��Ϊ%s������ƿ��Գɼ�Ϊ��",need,name[k]);
    for(j=0; j<m; j++)
    {
        printf("%4d",score[k][j]);
    }
    printf("\n���ܷ���ƽ���ֱַ�Ϊ%d %.2f������Ϊ%d\n",sum[k],aver[k],k+1);}
    else
        printf("�޸�ѧ��ѧ��\n");
}

/**********************************
** ������:Namesearch
** �� ��:score num n
** score:ѧ����������score[n]
** num:ѧ��ѧ������num[n]
** n:ѧ������
** find2:Ѱ������
** �������
** ��������:���ΰ�ѧ���ɵ͵�������strcmp(find2,name[i])==0
************************************/
void Namesearch(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m)
{
    int i,j,k,jet=1;
    char need[30];
    printf("��������Ҫ���ҵ�����\n");
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
        printf("ѧ��Ϊ%ld��ѧ��Ϊ%s������ƿ��Գɼ�Ϊ��",num[k],name[k]);
        for(j=0; j<m; j++)
        {
            printf("%4d",score[k][j]);
        }
        printf("\n���ܷ���ƽ���ֱַ�Ϊ%d %.2f������Ϊ%d\n",sum[k],aver[k],k+1);
    }
    else
        printf("�޸�����ѧ��\n");
}

/**********************************
** ������:Scoresort
** �� ��:score num n
** score:ѧ����������score[n]
** num:ѧ��ѧ������num[n]
** n:ѧ������
** �������
** ��������:���ݳɼ����з��࣬���������ٷֱ�
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
        printf("��%d�ſγ���:\n",j+1);
        printf("��������ȼ�(90-100��)������Ϊ%d,ռ��������%.2f%%\n",counter[j][0],a[j][0]);
        printf("�������õȼ�(80-89��)������Ϊ%d,ռ��������%.2f%%\n",counter[j][1],a[j][1]);
        printf("�����еȵȼ�(70-79��)������Ϊ%d,ռ��������%.2f%%\n",counter[j][2],a[j][2]);
        printf("���ڼ���ȼ�(60-69��)������Ϊ%d,ռ��������%.2f%%\n",counter[j][3],a[j][3]);
        printf("���ڲ�����ȼ�(0-59��)������Ϊ%d,ռ��������%.2f%%\n",counter[j][4],a[j][4]);
    }
}
void Swapl(long *x,long *y)//long�������������
{
    long temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void Swapi( int*x,int *y)//int�ͱ�������
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void Swapf( float*x,float *y)//float�ͱ�������
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
    printf("  �ܷ�Ϊ%d��ƽ����Ϊ%.2f\n",sum,aver);
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
        printf("��%d�ƵĿγ̵��ܷ���ƽ���ֱַ�Ϊ%4d��%.2f\n",j+1,sum,aver);
    }
}
void Shuchu(long num[],char name[][30],int score[][N],int sum[],float aver[],int n,int m)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        printf("ѧ��Ϊ%ld��ѧ��Ϊ%s",num[i],name[i]);
        printf("����Ƴɼ��ֱ�Ϊ");
        for(j=0; j<m; j++)
        {
            printf("%4d",score[i][j]);
        }
        printf("\n���ܳɼ�Ϊ%d,ƽ����Ϊ%.2f\n",sum[i],aver[i]);
    }
}
