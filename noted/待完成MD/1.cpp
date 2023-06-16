/*
    Name: ɨ��.v2.0 (��ʽ�汾)
    Copyright: belong to Author
    Author: Iowa_Battleship
    Date: 2017,12,21 20:38
    Description: ����Сɨ�ף��緢��Bug����ϵ��
    Coding time: Լ2����Сʱ�����һ�����԰汾(�޿�ʼ����&����)�����滨�˶���ʱ���û������ 
    Bug fix log: 1.�޸������������ʱ�ڸ����ֵ�����
                 2.�޸�����ڷ����ķ������޷��ƶ�������
                 3.�޸���ʹ�÷��������ʱ���ܹ������Ѳ���ķ��� 
                 4.�޸���ʱ�����ֵ��޷����������� 
                 5.�޸����ģʽ�µĵ�ͼ����ʾ���� 
                 6.�޸������ʵ���������Ϸ��bug 
    Optimization&Update: 1.����ʹ�÷���������ˣ��� 
                         2.�Ż���ʼ�˵������ò˵��Ľ��� 
                         3.�˵���������Ϊʹ�÷�������� 
                         4.�޸Ĳ���ͼ�꣬������΢��һЩ 
                         5.�޸�Logo����ʵ��Ϊ����ͼ����= =��
                         6.����һ��С�ʵ� 
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<ctime>
using namespace std;
const int limit_long=110;
int backgroud[limit_long][limit_long],landmine[limit_long][limit_long],lng,wth,landmine_num,now_landmine_num,true_landmine_num,nune_check;
int walk_x[8]={1,-1,0,0,1,-1,1,-1},walk_y[8]={0,0,1,-1,1,-1,-1,1};
int now_begin,now_site,now_x,now_y,l_lng,l_wth,l_landmine_num;
bool visit_landmine[limit_long][limit_long],game_over,if_site,if_lotto,choose_way,if_egg;
void clear_all()
{
    if(if_egg)
    {
        lng=l_lng;
        wth=l_wth;
        landmine_num=l_landmine_num;
    }
    if_egg=0;
    now_x=now_y=1;
    memset(backgroud,0,sizeof(backgroud));
    memset(landmine,0,sizeof(landmine));
    memset(visit_landmine,0,sizeof(visit_landmine));
}
void lng_coordinate()
{
    int i;
    for(i=0;i<=lng;i++)
    {
        if(i)
            printf("%4d",i);
        else
            printf("    ");
    }
    printf("\n");
}
void logo()
{
    printf("          ��                              ������������������\n");
    printf("          ��      ��������������                  ��\n");
    printf("          ��                  ��      ��������������������������\n");
    printf("      ����������              ��      ��          ��          ��\n");
    printf("          ��                  ��      ��    ��    ��    ��    ��\n");
    printf("          ��  ��              ��      ��          ��          ��\n");
    printf("          ����    ��������������            ��    ��    ��\n");
    printf("        ����                  ��\n");
    printf("      ��  ��                  ��            ��������������\n");
    printf("          ��                  ��            ��    ��    ��\n");
    printf("      ��  ��                  ��            ��������������\n");
    printf("        ����      ��������������            ��    ��    ��\n");
    printf("          ��                                ��������������    V2.0\n\n");
    printf("                                           by Iowa_Battle\n");
}
int re()
{
    char c=getchar();
    int x=0;
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
int calculate(int x,int y)
{
    int s=0,i,j;
    for(i=x-1;i<=x+1;i++)
        for(j=y-1;j<=y+1;j++)
            if((i!=x||j!=y)&&landmine[i][j])
                s++;
    return s;
}
void calculate_w_pr(int x,int y)
{
    int s=0,i,j;
    for(i=x-1;i<=x+1;i++)
        for(j=y-1;j<=y+1;j++)
            if((i!=x||j!=y)&&landmine[i][j])
                s++;
    if(s)
        printf("%2d",s);
    else
        printf("  ");
}
void spe_pr(int x,int y)
{
    int s=0,i,j;
    for(i=x-1;i<=x+1;i++)
        for(j=y-1;j<=y+1;j++)
            if((i!=x||j!=y)&&landmine[i][j])
                s++;
    if(s==1)
        printf("��");
    if(s==2)
        printf("��");
    if(s==3)
        printf("��");
    if(s==4)
        printf("��");
    if(s==5)
        printf("��");
    if(s==6)
        printf("��");
    if(s==7)
        printf("��");
    if(s==8)
        printf("��");
    if(!s)
        printf("��");
}
void calculate_c_pr(int x,int y)
{
    int s=0,i,j;
    for(i=x-1;i<=x+1;i++)
        for(j=y-1;j<=y+1;j++)
            if((i!=x||j!=y)&&landmine[i][j])
                s++;
    if(s)
        printf("%4d",s);
    else
        printf("    ");
}
void work_backgroud_w_pr()
{
    int i,j,p;
    for(i=1;i<=wth;i++)
    {
        for(j=1;j<=lng;j++)
        {
            if(i==now_x&&j==now_y)
            {
                if(!backgroud[i][j])
                    printf("��");
                else
                    if(backgroud[i][j]==2)
                        printf("��");
                    else
                        spe_pr(i,j);
                continue;
            }
            p=backgroud[i][j];
            if(!p)
                printf("��");
            else
                if(p==1)
                    printf("��");
                else
                    if(p==2)
                        printf("��");
                    else
                        calculate_w_pr(i,j);
        }
        printf("\n");
    }
}
void work_backgroud_c_pr()
{
    int i,j,p;
    for(i=1;i<=wth;i++)
    {
        printf("%4d",i);
        for(j=1;j<=lng;j++)
        {
            p=backgroud[i][j];
            if(!p)
                printf("  ��");
            else
                if(p==1)
                    printf("  ��");
                else
                    if(p==2)
                        printf("  ��");
                    else
                        calculate_c_pr(i,j);
        }
        printf("%4d",i);
        printf("\n");
    }
}
void over_win_w_pr()
{
    int i,j,p;
    for(i=1;i<=wth;i++)
    {
        for(j=1;j<=lng;j++)
        {
            p=landmine[i][j];
            if(p)
                printf("��");
            else
                calculate_w_pr(i,j);
        }
        printf("\n");
    }
}
void over_win_c_pr()
{
    int i,j,p;
    lng_coordinate();
    for(i=1;i<=wth;i++)
    {
        printf("%4d",i);
        for(j=1;j<=lng;j++)
        {
            p=landmine[i][j];
            if(p)
                printf("  ��");
            else
                calculate_c_pr(i,j);
        }
        printf("%4d",i);
        printf("\n");
    }
    lng_coordinate();
}
void over_defeat_w_pr(int x,int y)
{
    int i,j,p;
    for(i=1;i<=wth;i++)
    {
        for(j=1;j<=lng;j++)
        {
            p=landmine[i][j];
            if(i==x&&j==y)
                printf("��");
            else
            {
                if(p)
                    printf("��");
                else
                    calculate_w_pr(i,j);
            }
        }
        printf("\n");
    }
}
void over_defeat_c_pr(int x,int y)
{
    int i,j,p;
    lng_coordinate();
    for(i=1;i<=wth;i++)
    {
        printf("%4d",i);
        for(j=1;j<=lng;j++)
        {
            p=landmine[i][j];
            if(i==x&&j==y)
                printf("  ��");
            else
            {
                if(p)
                    printf("  ��");
                else
                    calculate_c_pr(i,j);
            }
        }
        printf("%4d",i);
        printf("\n");
    }
    lng_coordinate();
}
void wrong_normal_c_pr()
{
    system("Cls");
    printf("ʣ�����:%d\n",now_landmine_num);
    lng_coordinate();
    work_backgroud_c_pr();
    lng_coordinate();
    printf("��Ч��������\n���������������ʽ��0��ʾ�򿪣�1��ʾ�������죩��������������������\n");
}
void wrong_lotto_c_pr()
{
    system("Cls");
    lng_coordinate();
    work_backgroud_c_pr();
    lng_coordinate();
    printf("��Ч��������\n������������ȷ������\n");
}
void work_normal_w_pr()
{
    system("Cls");
    printf("ʣ�����:%d\n",now_landmine_num);
    work_backgroud_w_pr();
    printf("ʹ�÷����������z���ڿ���x����������\n");
}
void work_normal_c_pr()
{
    system("Cls");
    printf("ʣ�����:%d\n",now_landmine_num);
    lng_coordinate();
    work_backgroud_c_pr();
    lng_coordinate();
    printf("���������ʽ��0��ʾ�򿪣�1��ʾ�������죩��������������������\n");
}
void work_lotto_w_pr()
{
    system("Cls");
    work_backgroud_w_pr();
    printf("ʹ�÷����������z���ڿ�\n");
}
void work_lotto_c_pr()
{
    system("Cls");
    lng_coordinate();
    work_backgroud_c_pr();
    lng_coordinate();
    printf("����������\n");
}
void work_dig(int x,int y)
{
    int i,xx,yy;
    if(calculate(x,y))
    {
        visit_landmine[x][y]=1;
        backgroud[x][y]=-1;
        return;
    }
    for(i=0;i<8;i++)
    {
        xx=x+walk_x[i];
        yy=y+walk_y[i];
        if(xx<=wth&&xx>0&&yy<=lng&&yy>0&&!landmine[xx][yy]&&!backgroud[xx][yy]&&!visit_landmine[xx][yy])
        {
            visit_landmine[xx][yy]=1;
            backgroud[xx][yy]=-1;
            nune_check--;
            if(!calculate(xx,yy))
                work_dig(xx,yy);
        }
    }
}
void work_flag(int x,int y,bool p)
{
    if(!backgroud[x][y])
    {
        if(p)
            true_landmine_num--;
        now_landmine_num--;
        backgroud[x][y]=2;
    }
    else
        if(backgroud[x][y]==2)
        {
            if(p)
                true_landmine_num++;
            now_landmine_num++;
            backgroud[x][y]=0;
        }
        else
            if(choose_way)
            {
                if(if_lotto)
                    wrong_lotto_c_pr();
                else
                    wrong_normal_c_pr();
            }
}
void wrong_in()
{
    printf("\n��Ч���� ����������\n");
}
void begin_interface(int p)
{
    system("Cls");
    logo();
    if(p==1)
        printf("                            ->��ʼ��Ϸ\n");
    else
        printf("                              ��ʼ��Ϸ\n");
    if(p==2)
        printf("                            ->������Ϸ\n");
    else
        printf("                              ������Ϸ\n");
    if(p==3)
        printf("                            ->�˳���Ϸ\n");
    else
        printf("                              �˳���Ϸ\n");
    printf("\n                      ��ʹ�÷����ѡ�񣬻س�ȷ��\n"); 
}
void site_interface(int p)
{
    system("Cls");
    printf("                                ����\n\n\n");
    if(p==1)
        printf("                              ->����\n\n");
    else
        printf("                                ����\n\n");
    if(p==2)
        printf("                              ->�м�\n\n");
    else
        printf("                                �м�\n\n");
    if(p==3)
        printf("                              ->�߼�\n\n");
    else
        printf("                                �߼�\n\n");
    if(p==4)
        printf("                             ->�Զ���\n\n");
    else
        printf("                               �Զ���\n\n");
    if(p==5)
        printf("                              ->��͸\n\n");
    else
        printf("                                ��͸\n\n");
    if(p==6)
        printf("                              ->���\n\n");
    else
        printf("                                ���\n\n");
    if(p==7)
        printf("                              ->����\n\n");
    else
        printf("                                ����\n\n");
}
void face_chose(bool p)
{
    system("Cls");
    printf("                           ��ѡ�������ʽ\n\n");
    if(p)
        printf("                  ->�����������    �÷��������\n\n");
    else
        printf("                    �����������  ->�÷��������\n\n");
    printf("       ���߽���:����ǽϴ��ͼ����ʹ�������������Ϊ������ˮƽ�ϵͣ�\n");
    printf("     ÿ�η����������Ҫˢ�£����ͼ�ϴ���������������Ϸ�����нϴ�Ӱ��\n"); 
}
void tip()
{
    system("Cls");
    printf("                               С��ʾ\n\n");
    printf("     ���ʾ�������ڵ�δ�����ķ���  ���ʾ�������ڵķ����Ѳ���\n");
    printf("               ���ʾ�������ڵķ����ѷ�������Χ�޵���\n");
    printf("      �٢ڢۢܢݢޢߢ��ʾ�������ڵķ����ѷ�������Χ��1~8����\n");
    system("pause"); 
}
void chose()
{
    int p;
    face_chose(choose_way=1);
    while(1)
    {
        while(1)
        {
            p=getch();
            while(p!=224)
            {
                if(p==13)
                    break;
                p=getch();
            }
            if(p==13)
                break;
            p=getch();
            if(p==75||p==77||p==13)
                break;
        }
        if(p==75&&!choose_way)
            choose_way=1;
        if(p==77&&choose_way)
            choose_way=0;
        if(p==13)
            break;
        face_chose(choose_way);
    }
}
void face_easy()
{
    system("Cls");
    printf("�ѳɹ�ѡ�� ���� �Ѷȣ�Ϊ9x9���󣬺�10�ŵ���\n");
    printf("�뽫��Ļ�������ܹ�������ʾ����\n");
    system("pause");
}
void face_normal()
{
    system("Cls");
    printf("�ѳɹ�ѡ�� �м� �Ѷȣ�Ϊ16x16���󣬺�40�ŵ���\n");
    printf("�뽫��Ļ�������ܹ�������ʾ����\n");
    system("pause");
}
void face_hard()
{
    system("Cls");
    printf("�ѳɹ�ѡ�� �߼� �Ѷȣ�Ϊ30x16���󣬺�99�ŵ���\n");
    printf("�뽫��Ļ�������ܹ�������ʾ����\n");
    system("pause");
}
void face_customize()
{
    printf("�ѳɹ� �Զ��� �Ѷȣ�Ϊ%dx%d���󣬺�%d�ŵ���\n",lng,wth,landmine_num);
    printf("�뽫��Ļ�������ܹ�������ʾ����\n");
    system("pause");
}
void face_lotto()
{
    printf("�ѳɹ�ѡ�� ��͸ ģʽ��Ϊ%dx%d���󣬺�%d�ŵ���\n",lng,wth,landmine_num);
    printf("�뽫��Ļ�������ܹ�������ʾ����\n");
    system("pause");
}
void face_rand()
{
    printf("�����ɣ�Ϊ%dx%d���󣬺�%d�ŵ���\n",lng,wth,landmine_num);
    printf("�뽫��Ļ�������ܹ�������ʾ����\n");
    system("pause");
}
void site()
{
    int p;
    site_interface(now_site=1);
    while(1)
    {
        while(1)
        {
            p=getch();
            while(p!=224)
            {
                if(p==13)
                    break;
                p=getch();
            }
            if(p==13)
                break;
            p=getch();
            if(p==72||p==80||p==13)
                break;
        }
        if(p==72&&now_site!=1)
            now_site--;
        if(p==80&&now_site!=7)
            now_site++;
        if(p==13)
            break;
        site_interface(now_site);
    }
    if(now_site==1)
    {
        lng=wth=9;
        landmine_num=10;
        face_easy();
        if_lotto=0;
    }
    else
        if(now_site==2)
        {
            lng=wth=16;
            landmine_num=40;
            face_normal();
            if_lotto=0;
        }
        else
            if(now_site==3)
            {
                lng=30;
                wth=16;
                landmine_num=99;
                face_hard();
                if_lotto=0;
            }
            else
                if(now_site==4)
                {
                    system("Cls");
                    printf("��������Ϸ��Χ���Գ�*����ʽ�������С��101�Ҵ���0���Լ����׸�����С�ڳ�*���ֵ��\n");
                    lng=re();
                    wth=re();
                    landmine_num=re();
                    while(lng<=0||wth<=0||landmine_num<=0||lng>100||wth>100||landmine_num>lng*wth)
                    {
                        wrong_in();
                        lng=re();
                        wth=re();
                        landmine_num=re();
                    }
                    face_customize();
                    if_site=1;
                    if_lotto=0;
                }
                else
                    if(now_site==5)
                    {
                        system("Cls");
                        printf("��������Ϸ��Χ���Գ�*����ʽ�������С��101�Ҵ���0��\nps�����ڵľ������� = = ��Ȼ�㷶Χ��СҲ��\n");
                        lng=re();
                        wth=re();
                        while(lng<=0||wth<=0||lng>100||wth>100||(lng==1&&wth==1))
                        {
                            wrong_in();
                            lng=re();
                            wth=re();
                        }
                        landmine_num=lng*wth-1;
                        face_lotto();
                        if_site=1;
                        if_lotto=1;
                    }
                    else
                        if(now_site==6)
                        {
                            system("Cls");
                            printf("Ϊ�����и��õ���Ϸ���飬�ҽ�����������5~40����������������*���1/6\n\n");
                            lng=5+rand()%36;
                            wth=5+rand()%36;
                            landmine_num=1+rand()%((lng*wth)/6);
                            face_rand();
                            if_lotto=0;
                        }
    begin_interface(now_begin=1);
}
void begin_in()
{
    int p,s=0;
    while(1)
    {
        while(1)
        {
            p=getch();
            while(p!=224)
            {
                if(p==13)
                    break;
                p=getch();
            }
            if(p==13)
                break;
            p=getch();
            if(p==72||p==80||p==13)
                break;
        }
        if(p==72&&now_begin!=1)
            now_begin--;
        if(p==72&&now_begin==1)
            s++;
        else
            s=0;
        if(p==80&&now_begin!=3)
            now_begin++;
        begin_interface(now_begin);
        if(p==13)
        {
            if(now_begin==1)
                break;
            if(now_begin==2)
                site();
            if(now_begin==3)
            {
                game_over=1;
                break;
            }
        }
        if(s==10)
        {
            if_egg=1;
            l_lng=lng;
            l_wth=wth;
            l_landmine_num=landmine_num;
            break;
        }
    }
}
int main()
{
    srand(time(NULL));
    int i,x,y,p;
    while(1)
    {
        clear_all();
        begin_interface(now_begin=1);
        begin_in();
        if(game_over)
            break;
        if(if_egg)
        {
            lng=33;
            wth=13;
            landmine_num=116;
        }
        while(lng<=0||wth<=0||landmine_num<=0||lng>100||wth>100||landmine_num>lng*wth)
        {
            system("Cls");
            if(if_site)
                printf("������ȷ������Ϸ�ٿ�ʼ��Ϸ!!\n");
            else
                printf("����������Ϸ�ٿ�ʼ��Ϸ!!\n");
            system("pause");
            begin_interface(now_begin=1);
            begin_in();
            if(game_over)
                break;
        }
        if(game_over)
            break;
        true_landmine_num=now_landmine_num=landmine_num;
        nune_check=lng*wth;
        if(if_egg)
        {
            for(i=1;i<=13;i++)
                landmine[i][6]=1;
            for(i=4;i<=8;i++)
                landmine[4][i]=1;
            for(i=10;i<=15;i++)
                landmine[2][i]=landmine[7][i]=landmine[12][i]=1;
            for(i=2;i<=12;i++)
                landmine[i][16]=1;

            for(i=22;i<=30;i++)
                landmine[1][i]=1;
            for(i=2;i<=7;i++)
                landmine[i][26]=1;
            for(i=20;i<=32;i++)
                landmine[3][i]=1;
            for(i=4;i<=6;i++)
                landmine[i][20]=landmine[i][32]=1;
            for(i=23;i<=29;i++)
                landmine[9][i]=landmine[11][i]=landmine[13][i]=1;
            for(i=10;i<=12;i+=2)
                landmine[i][23]=landmine[i][26]=landmine[i][29]=1;
            landmine[6][8]=1;
            landmine[7][7]=1;
            landmine[8][5]=1;
            landmine[9][4]=1;
            landmine[11][4]=1;
            landmine[12][5]=1;
            landmine[5][23]=1;
            landmine[7][23]=1;
            landmine[5][29]=1;
            landmine[7][29]=1; 
        }
        else
        {
            for(i=1;i<=landmine_num;i++)
            {
                x=1+rand()%wth;
                y=1+rand()%lng;
                while(landmine[x][y])
                {
                    x=1+rand()%wth;
                    y=1+rand()%lng;
                }
                landmine[x][y]=1;
            }
        }
        if(if_egg)
            choose_way=0;
        else
            chose();
        if(choose_way)
        {
            if(if_lotto)
                work_lotto_c_pr();
            else
                work_normal_c_pr();
            while(1)
            {
                if(nune_check==landmine_num)
                {
                    system("Cls");
                    printf("YOU WIN!!\nCongratulations!!\n");
                    over_win_c_pr();
                    system("pause");
                    break;
                }
                if(if_lotto)
                    p=0;
                else
                    p=re();
                x=re();
                y=re();
                if(backgroud[x][y]==-1||(p!=0&&p!=1)||x<1||x>wth||y<1||y>lng||(backgroud[x][y]==2&&!p))
                {
                    if(if_lotto)
                        wrong_lotto_c_pr();
                    else
                        wrong_normal_c_pr();
                    continue;
                }
                if(!landmine[x][y])
                {
                    if(!p)
                    {
                        visit_landmine[x][y]=1;
                        backgroud[x][y]=-1;
                        nune_check--;
                        work_dig(x,y);
                    }
                    else
                        work_flag(x,y,0);
                    if(if_lotto)
                        work_lotto_c_pr();
                    else
                        work_normal_c_pr();
                }
                else
                    if(!p)
                    {
                        system("Cls");
                        printf("Defeat!!\n");
                        over_defeat_c_pr(x,y);
                        system("pause");
                        break;
                    }
                    else
                    {
                        work_flag(x,y,1);
                        if(if_lotto)
                            work_lotto_c_pr();
                        else
                            work_normal_c_pr();
                    }
                if(nune_check==landmine_num)
                {
                    system("Cls");
                    printf("YOU WIN!!\nCongratulations!!\n");
                    over_win_c_pr();
                    system("pause");
                    break;
                }
            }
        }
        else
        {
            if(!if_egg)
                tip();
            if(if_lotto)
                work_lotto_w_pr();
            else
                work_normal_w_pr();
            while(1)
            {
                if(nune_check==landmine_num)
                {
                    system("Cls");
                    printf("YOU WIN!!\nCongratulations!!\n");
                    over_win_w_pr();
                    system("pause");
                    break;
                }
                while(1)
                {
                    while(1)
                    {
                        p=getch();
                        while(p!=224)
                        {
                            if(p=='z'||p=='x')
                                break;
                            p=getch();
                        }
                        if(p=='z'||p=='x')
                            break;
                        p=getch();
                        if(p==72||p==80||p==75||p==77||p=='z'||p=='x')
                            break;
                    }
                    if(p=='z')
                    {
                        p=0;
                        break;
                    }
                    if(p=='x')
                    {
                        p=1;
                        break;
                    }
                    if(p==72&&now_x>1)
                        now_x--;
                    if(p==80&&now_x<wth)
                        now_x++;
                    if(p==75&&now_y>1)
                        now_y--;
                    if(p==77&&now_y<lng)
                        now_y++;
                    if(if_lotto)
                        work_lotto_w_pr();
                    else
                        work_normal_w_pr();
                }
                if(backgroud[now_x][now_y]==-1||(backgroud[now_x][now_y]==2&&!p))
                    continue;
                if(!landmine[now_x][now_y])
                {
                    if(!p)
                    {
                        visit_landmine[now_x][now_y]=1;
                        backgroud[now_x][now_y]=-1;
                        nune_check--;
                        work_dig(now_x,now_y);
                    }
                    else
                        work_flag(now_x,now_y,0);
                    if(if_lotto)
                        work_lotto_w_pr();
                    else
                        work_normal_w_pr();
                }
                else
                    if(!p)
                    {
                        system("Cls");
                        printf("Defeat!!\n");
                        over_defeat_w_pr(now_x,now_y);
                        system("pause");
                        break;
                    }
                    else
                    {
                        work_flag(now_x,now_y,1);
                        if(if_lotto)
                            work_lotto_w_pr();
                        else
                            work_normal_w_pr();
                    }
                if(nune_check==landmine_num)
                {
                    system("Cls");
                    printf("YOU WIN!!\nCongratulations!!\n");
                    over_win_w_pr();
                    system("pause");
                    break;
                }
            }
        }
    }
    printf("\n                       Thank you for your play");
    return 0;
}
