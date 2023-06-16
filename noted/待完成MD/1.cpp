/*
    Name: 扫雷.v2.0 (正式版本)
    Copyright: belong to Author
    Author: Iowa_Battleship
    Date: 2017,12,21 20:38
    Description: 自制小扫雷，如发现Bug请联系我
    Coding time: 约2个半小时造出第一个测试版本(无开始界面&设置)，后面花了多少时间就没计算了 
    Bug fix log: 1.修复光标在数字上时遮盖数字的问题
                 2.修复光标在翻开的方格上无法移动的问题
                 3.修复在使用方向键操作时，能够翻开已插旗的方块 
                 4.修复有时候会出现的无法操作的问题 
                 5.修复随机模式下的地图的显示问题 
                 6.修复触发彩蛋后，重新游戏的bug 
    Optimization&Update: 1.可以使用方向键操作了！！ 
                         2.优化开始菜单和设置菜单的界面 
                         3.菜单栏操作改为使用方向键操作 
                         4.修改插旗图标，看着稍微好一些 
                         5.修改Logo（其实是为了造图方便= =）
                         6.新增一个小彩蛋 
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
    printf("          ■                              ■■■■■■■■■\n");
    printf("          ■      ■■■■■■■                  ■\n");
    printf("          ■                  ■      ■■■■■■■■■■■■■\n");
    printf("      ■■■■■              ■      ■          ■          ■\n");
    printf("          ■                  ■      ■    ■    ■    ■    ■\n");
    printf("          ■  ■              ■      ■          ■          ■\n");
    printf("          ■■    ■■■■■■■            ■    ■    ■\n");
    printf("        ■■                  ■\n");
    printf("      ■  ■                  ■            ■■■■■■■\n");
    printf("          ■                  ■            ■    ■    ■\n");
    printf("      ■  ■                  ■            ■■■■■■■\n");
    printf("        ■■      ■■■■■■■            ■    ■    ■\n");
    printf("          ■                                ■■■■■■■    V2.0\n\n");
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
        printf("①");
    if(s==2)
        printf("②");
    if(s==3)
        printf("③");
    if(s==4)
        printf("④");
    if(s==5)
        printf("⑤");
    if(s==6)
        printf("⑥");
    if(s==7)
        printf("⑦");
    if(s==8)
        printf("⑧");
    if(!s)
        printf("○");
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
                    printf("●");
                else
                    if(backgroud[i][j]==2)
                        printf("★");
                    else
                        spe_pr(i,j);
                continue;
            }
            p=backgroud[i][j];
            if(!p)
                printf("■");
            else
                if(p==1)
                    printf("□");
                else
                    if(p==2)
                        printf("☆");
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
                printf("  ■");
            else
                if(p==1)
                    printf("  □");
                else
                    if(p==2)
                        printf("  ☆");
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
                printf("□");
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
                printf("  □");
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
                printf("！");
            else
            {
                if(p)
                    printf("□");
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
                printf("  ！");
            else
            {
                if(p)
                    printf("  □");
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
    printf("剩余地雷:%d\n",now_landmine_num);
    lng_coordinate();
    work_backgroud_c_pr();
    lng_coordinate();
    printf("无效操作！！\n请重新输入操作方式（0表示掘开，1表示插旗或拔旗），再输入操作对象的坐标\n");
}
void wrong_lotto_c_pr()
{
    system("Cls");
    lng_coordinate();
    work_backgroud_c_pr();
    lng_coordinate();
    printf("无效操作！！\n请重新输入正确的坐标\n");
}
void work_normal_w_pr()
{
    system("Cls");
    printf("剩余地雷:%d\n",now_landmine_num);
    work_backgroud_w_pr();
    printf("使用方向键操作，z键挖开，x键插旗或拔旗\n");
}
void work_normal_c_pr()
{
    system("Cls");
    printf("剩余地雷:%d\n",now_landmine_num);
    lng_coordinate();
    work_backgroud_c_pr();
    lng_coordinate();
    printf("输入操作方式（0表示掘开，1表示插旗或拔旗），再输入操作对象的坐标\n");
}
void work_lotto_w_pr()
{
    system("Cls");
    work_backgroud_w_pr();
    printf("使用方向键操作，z键挖开\n");
}
void work_lotto_c_pr()
{
    system("Cls");
    lng_coordinate();
    work_backgroud_c_pr();
    lng_coordinate();
    printf("请输入坐标\n");
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
    printf("\n无效输入 请重新输入\n");
}
void begin_interface(int p)
{
    system("Cls");
    logo();
    if(p==1)
        printf("                            ->开始游戏\n");
    else
        printf("                              开始游戏\n");
    if(p==2)
        printf("                            ->设置游戏\n");
    else
        printf("                              设置游戏\n");
    if(p==3)
        printf("                            ->退出游戏\n");
    else
        printf("                              退出游戏\n");
    printf("\n                      请使用方向键选择，回车确定\n"); 
}
void site_interface(int p)
{
    system("Cls");
    printf("                                设置\n\n\n");
    if(p==1)
        printf("                              ->初级\n\n");
    else
        printf("                                初级\n\n");
    if(p==2)
        printf("                              ->中级\n\n");
    else
        printf("                                中级\n\n");
    if(p==3)
        printf("                              ->高级\n\n");
    else
        printf("                                高级\n\n");
    if(p==4)
        printf("                             ->自定义\n\n");
    else
        printf("                               自定义\n\n");
    if(p==5)
        printf("                              ->乐透\n\n");
    else
        printf("                                乐透\n\n");
    if(p==6)
        printf("                              ->随机\n\n");
    else
        printf("                                随机\n\n");
    if(p==7)
        printf("                              ->返回\n\n");
    else
        printf("                                返回\n\n");
}
void face_chose(bool p)
{
    system("Cls");
    printf("                           请选择操作方式\n\n");
    if(p)
        printf("                  ->输入坐标操作    用方向键操作\n\n");
    else
        printf("                    输入坐标操作  ->用方向键操作\n\n");
    printf("       作者建议:如果是较大的图，请使用坐标操作，因为介于我水平较低，\n");
    printf("     每次方向键操作都要刷新，如果图较大则输出慢，会对游戏体验有较大影响\n"); 
}
void tip()
{
    system("Cls");
    printf("                               小提示\n\n");
    printf("     ●表示现在所在的未翻开的方块  ★表示现在所在的方块已插旗\n");
    printf("               ○表示现在所在的方块已翻开且周围无地雷\n");
    printf("      ①②③④⑤⑥⑦⑧表示现在所在的方块已翻开且周围有1~8颗雷\n");
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
    printf("已成功选择 初级 难度，为9x9方阵，含10颗地雷\n");
    printf("请将屏幕调整至能够完美显示方阵\n");
    system("pause");
}
void face_normal()
{
    system("Cls");
    printf("已成功选择 中级 难度，为16x16方阵，含40颗地雷\n");
    printf("请将屏幕调整至能够完美显示方阵\n");
    system("pause");
}
void face_hard()
{
    system("Cls");
    printf("已成功选择 高级 难度，为30x16方阵，含99颗地雷\n");
    printf("请将屏幕调整至能够完美显示方阵\n");
    system("pause");
}
void face_customize()
{
    printf("已成功 自定义 难度，为%dx%d方阵，含%d颗地雷\n",lng,wth,landmine_num);
    printf("请将屏幕调整至能够完美显示方阵\n");
    system("pause");
}
void face_lotto()
{
    printf("已成功选择 乐透 模式，为%dx%d方阵，含%d颗地雷\n",lng,wth,landmine_num);
    printf("请将屏幕调整至能够完美显示方阵\n");
    system("pause");
}
void face_rand()
{
    printf("随机完成，为%dx%d方阵，含%d颗地雷\n",lng,wth,landmine_num);
    printf("请将屏幕调整至能够完美显示方阵\n");
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
                    printf("请输入游戏范围（以长*宽形式，长宽均小于101且大于0）以及地雷个数（小于长*宽的值）\n");
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
                        printf("请输入游戏范围（以长*宽形式，长宽均小于101且大于0）\nps：脸黑的尽量少玩 = = 当然你范围定小也行\n");
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
                            printf("为了您有更好的游戏体验，我将长宽都限制在5~40，地雷数不超过长*宽的1/6\n\n");
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
                printf("请先正确设置游戏再开始游戏!!\n");
            else
                printf("请先设置游戏再开始游戏!!\n");
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
