#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h>
using namespace std;
struct khelari
{
    long long tim;
    char name[10];
    long long moves;
}mem[10];
char cong[6][80]={
    "   cccc    ooo    n     n    gggg     ooo  ",
    "  c       o   o   nn    n   g    g   o   o ",
    " c        o   o   n n   n   g        o   o ",
    " c        o   o   n  n  n   g  ggg   o   o ",
    "  c       o   o   n   n n   g    g   o   o ",
    "   cccc    ooo    n    nn    gggg     ooo  "
};
char congrev[6][80]={
   "111    1111   1111 11111 1111    11111   11",
   "11 1111111 111 111  1111 111 1111 111 111 1",
   "1 11111111 111 111 1 111 111 11111111 111 1",
   "1 11111111 111 111 11 11 111 11   111 111 1",
   "11 1111111 111 111 111 1 111 1111 111 111 1",
   "111    1111   1111 1111  1111    11111   11"
};

char boa[30][32]={
    "###############################",
    "#     #########################",
    "#     ##################      #",
    "#     #######            #### #",
    "### ######### ############### #",
    "#   # ###        #          # #",
    "#     ### ################### #",
    "# ####### ################### #",
    "# #   ### ################### #",
    "#   #   # #####               #",
    "####### # ##### ###############",
    "# ##### #  #### ###############",
    "#       ## #### ########    ###",
    "# ######## #### ######## ## ###",
    "# #######  #### ##     # ## ###",
    "#      ## ##### ##     # ## ###",
    "###### ## ##### ##     # ## ###",
    "#    # ## ##### ######## ## ###",
    "# #  #    #####          ## ###",
    "###  ### ################## ###",
    "#     ## ################## ###",
    "# ### ## ################## ###",
    "# # # ## ################## ###",
    "# # # ## ################## ###",
    "# # # ## #      #####   ### ###",
    "#   # ## # #### ##    # ### ###",
    "#   # ###  ####    ####       #",
    "###############################",
};
void instruc(void)
{
    cout << "Instructions : " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "|                                                |" << endl;
    cout << "|  It's a game about a mouse                     |" << endl;
    cout << "|  Now he is very hungry                         |" << endl;
    cout << "|  So, Mr.M has announced a competition for this |" << endl;
    cout << "|  Atleast one and maximum 10 person can compete |" << endl;
    cout << "|  this event                                    |" << endl;
    cout << "|  Who wins this competition gets nothing.       |" << endl;
    cout << "|                                                |" << endl;
    cout << "|                                                |" << endl;
    cout << "|  Press 'W','A','S','D' to navigate             |" << endl;
    cout << "|  Game starts from 'H' and finishes at 'C'      |" << endl;
    cout << "|  You will be marked as 'x'                     |" << endl;
    cout << "|  Your position will be at 'H'                  |" << endl;
    cout << "|                                                |" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl << endl << endl << "Press any key to continue " << endl;
    getch();
}
void prinboa(int x)
{
    printf("\t-----%s-----\n",mem[x].name);
    for(int i=0;i<28;i++)
        printf("%s\n",boa[i]);
}
void congo(void)
{
    for(int loop=0;loop<10;loop++)
    {
        system("cls");
        for(int i=0;i<6;i++)
            cout << congrev[i] << endl;
        Sleep(100);
        system("cls");
        for(int i=0;i<6;i++)
            cout << cong[i] << endl;
    }
    printf("\n\n           Congratulations! '%s' you will get\n\n\n\t\t\tnothing for this",mem[0].name);
    Sleep(1000);
}
void gameon(int i)
{
    char co[100];
    red:
    system("cls");
    cout << endl << endl << endl << endl;
    printf("'%s' if you are ready to play please type 'enter' then press enter key\n\n\n\n\t\t",mem[i].name);
    gets(co);
    if(strcmp(co,"enter")!=0)
        goto red;
    int locx=0;
    int locy=1;
    char move;
    long long sta=time(NULL),fin;
    long long coun=0;
    double ti;
    while(1)
    {
        boa[0][1]='H';
        boa[26][30]='C';
        boa[locx][locy]='x';
        system("cls");
        prinboa(i);
        if(locy==30)
        {
            fin=time(NULL);
            mem[i].tim=difftime(fin,sta);
            mem[i].moves=coun;
            break;
        }
        coun++;
        move=getch();
        if(move=='a')
        {
            if(boa[locx][locy-1]!='#' && locx>=0 && locx<=29 && locy-1>=0 && locy-1<=30)
            {
                boa[locx][locy]=' ';
                boa[locx][--locy]=='x';
            }
            else
                printf("\a");
        }
        else if(move=='w')
        {
            if(boa[locx-1][locy]!='#' && locx-1>=0 && locx-1<=29 && locy>=0 && locy<=30)
            {
                boa[locx][locy]=' ';
                boa[--locx][locy]=='x';
            }
            else
                printf("\a");
        }
        else if(move=='s')
        {
            if(boa[locx+1][locy]!='#' && locx+1>=0 && locx+1<=29 && locy>=0 && locy<=30)
            {
                boa[locx][locy]=' ';
                boa[++locx][locy]=='x';
            }
            else
                printf("\a");
        }
        else if(move=='d')
        {
            if(boa[locx][locy+1]!='#' && locx>=0 && locx<=29 && locy+1>=0 && locy+1<=30)
            {
                boa[locx][locy]=' ';
                boa[locx][++locy]=='x';
            }
            else
                printf("\a");
        }
        else
            printf("\a");
    }
}
int player(void)
{
    system("cls");
    int n;
    cout << "Single player or multiplayer selection : " << endl << endl << endl << endl;
    aga:
    cout << "Press a number between 1 to 10 : ";
    cin >> n;
    if(n<1 || n>10)
        goto aga;
    else
    {
        printf("\nMax 10 charecter\n");
        for(int i=0;i<n;i++)
        {
            cout << endl << "Enter player " << i+1 << "'s name : ";
            scanf("%s",mem[i].name);
        }
    }
    cout << endl << endl;
    Sleep(1000);
    system("cls");
    return n;
}
void endgame(void)
{
    cout << endl << endl << endl << "Press any key to continue " << endl;
    getch();
}
bool comtim(khelari lhs,khelari rhs)
{
     return lhs.tim<rhs.tim;
}
bool commov(khelari lhs,khelari rhs)
{
    return lhs.moves<rhs.moves;
}
void prinres(int n)
{
    system("cls");
    cout << "Final result : " <<endl <<endl <<endl;
    cout << "   Name                  Time      Moves" <<endl;
    cout << "||-----------------------------------------||" << endl;
    for(int i=0;i<n;i++)
        printf("|| %c%c%c%c%c%c%c%c%c%c       %7lld    %7lld     ||\n",mem[i].name[0],mem[i].name[1],mem[i].name[2],mem[i].name[3],mem[i].name[4],mem[i].name[5],mem[i].name[6],mem[i].name[7],mem[i].name[8],mem[i].name[9],mem[i].tim,mem[i].moves);
    cout << "||-----------------------------------------||" << endl;
    cout << endl << endl << "Note : First result is sorted according to time then moves " << endl;
    cout << endl << "Press any key to continue " << endl;
    getch();
}
int main()
{
    instruc();
    int n=player();
    for(int i=0;i<n;i++)
        gameon(i);
    sort(mem,mem+n,comtim);
    sort(mem,mem+n,commov);
    prinres(n);
    congo();
    endgame();
    return 0;
}
