#include <iostream>
#include <cstdio>
//#include <cstdlib>
#include <cstring>
//#include <algorithm>
//#include <ctime>
//#include <bits/stdc++.h>
using namespace std;
char sid[1000][11],name[1000][11];
int cid[1000],score[1000][5],index_t=-1;
bool removed[1000];
void print_menu(){
    printf("Welcome to Student Performance Management System (SPMS).\n\n");
    printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
}
int Rank(int n){
    int cnt=0;
    for(int i=0;i<=index_t;++i)
        if(!removed[i] && score[i][4]>score[n][4]) ++cnt;
    return cnt+1;
}
void add(){
    const char* msg[2]={"Please enter the SID, CID, name and four scores. Enter 0 to finish.","Duplicated SID."};
    while(1){
        printf("%s\n",msg[0]);
        ++index_t;
        int i=index_t;
        removed[i]=score[i][4]=0;
        scanf("%s",sid[i]);
        if(strlen(sid[i])==1){ --index_t; return; }
        scanf("%d%s",&cid[i],name[i]);
        for(int j=0;j<4;++j) scanf("%d",&score[i][j]),score[i][4]+=score[i][j];
        for(int j=0;j<i;++j)
            if(!removed[j] && !strcmp(sid[i],sid[j]) ){ printf("%s\n",msg[1]); --index_t; break; }
    }
}
void DQ(bool isd){
    const char* msg[]={"Please enter SID or name. Enter 0 to finish.","student(s) removed."};
    char str[11];
    while(1){
        printf("%s\n",msg[0]);
        scanf("%s",str);
        if(!strcmp(str,"0")) break;
        int cnt=0;
        for(int i=0;i<=index_t;++i){
            if(!removed[i])
                if(!strcmp(str,sid[i]) || !strcmp(str,name[i])){
                    if(isd){
                        ++cnt;
                        removed[i]=1;
                    }
                    else{
                        printf("%d %s %d %s",Rank(i),sid[i],cid[i],name[i]);
                        for(int j=0;j<4;++j) printf(" %d",score[i][j]);
                        printf(" %d %.2f\n",score[i][4],1.0*score[i][4]/4);
                    }
                }
        }
        if(isd) printf("%d student(s) removed.\n",cnt);
    }
}
void stat(){
    const char* subject[]={"Chinese","Mathematics","English","Programming"};
    const char* msg[]={"failed all subjects:","passed 1 or more subjects:",
    "passed 2 or more subjects:","passed 3 or more subjects:","passed all subjects:"};
    printf("Please enter class ID, 0 for the whole statistics.\n");
    int c;
    scanf("%d",&c);
    int s[4]={0},ps[4]={0},fs[4]={0};
    int pscnt[5]={0};
    for(int i=0;i<=index_t;++i)
        if(!removed[i] && (!c || cid[i]==c)){
            int cnt=0;
            for(int j=0;j<4;++j){
                s[j]+=score[i][j];
                if(score[i][j]>=60) ++ps[j],++cnt;
                else ++fs[j];
            }
            ++pscnt[cnt];
        }
    for(int i=0;i<4;++i){
        printf("%s\n",subject[i]);
        printf("Average Score: %.2f\n",1.0*s[i]/(ps[i]+fs[i])+1e-5);
        printf("Number of passed students: %d\n",ps[i]);
        printf("Number of failed students: %d\n\n",fs[i]);
    }
    printf("Overall:\n");
    for(int i=4;i>=0;--i){
        int a=0;
        if(i) for(int j=4;j>=i;--j) a+=pscnt[j];
        else a=pscnt[0];
        printf("Number of students who %s",msg[i]);
        printf(" %d\n",a);
    }
    printf("\n");
}
int main()
{
    //freopen("..\\file\\input_ascii.txt","r",stdin);
    //freopen("..\\file\\output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    while(1){
        int choice;
        print_menu();
        scanf("%d",&choice);
        if(!choice) break;
        else if(choice==1) add();
        else if(choice==2) DQ(1);
        else if(choice==3) DQ(0);
        else if(choice==4) printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
        else stat();
    }
    //printf("\nTime used = %lf\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

