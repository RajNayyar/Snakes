//
//  main.cpp
//  snakes4
//
//  Created by Rajpreet on 18/02/18.
//  Copyright © 2018 Rajpreet. All rights reserved.
//

//
//  main.cpp
//  snake2
//
//  Created by Rajpreet on 17/02/18.
//  Copyright © 2018 Rajpreet. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

int foodx=10,foody=11;
char fooddata='F';

char arr[20][20];

struct node
{
    char data;
    struct node* next;
    int x;
    int y;
}*head,*temp;
struct food
{
    int m,n;
    char value='F';
};

void addNode(int tailx, int taily)
 {
 temp=head;
 while(temp->next!=NULL)
 {
 temp=temp->next;
 }
 struct node* freshnode=new node;
 freshnode->next=NULL;
 freshnode->x=tailx;
 freshnode->y=taily;
 freshnode->data='o';
 temp->data='O';
 temp->next=freshnode;
 }
 

void resetArray()
{int i,j;
    temp=head;
    for(i=0;i<=19;i++)
    {
        for(j=0;j<=19;j++)
        {
            arr[i][j]='1';
        }
    }
    arr[foodx][foody]=fooddata;
}


void initArray()
{
    resetArray();
    char a,b;
    temp=head;
    while(temp!=NULL)
    {
        a=temp->x;
        b=temp->y;
        arr[a][b]=temp->data;
        temp=temp->next;
    }
}

void display()
{
    initArray();
    //cout<<endl;
    fflush(stdout);
    int i,j;
    //system("cls");
    for(i=-1;i<=20;i++)
    {
        for(j=-1;j<=20;j++)
        {
            if(i>=0 && i<=19 && j>=0 && j<=19)
            {
              if(arr[i][j]!='1')
                {
                    cout<<arr[i][j]<<" ";
                }
                else
                {
                    cout<<"  ";
                }
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}

void move(int m,int n,char dir)
{
    int tailx = 0,taily = 0;
    temp=head;
    if( (arr[(temp->x)+m][(temp->y)+n]=='1' || arr[(temp->x)+m][(temp->y)+n]=='F') && (temp->y)+n!=-1 && (temp->x)+m!=20 && (temp->x)+m!=-1 && (temp->y)+n!=20)   //&& arr[(temp->x)+m][(temp->y)+n]!=arr[temp->next->x][temp->next->y]  && (temp->y)+n!=-1 && (temp->x)+m!=20 && (temp->x)+m!=-1 && (temp->y)+n!=20)
    {
        char a=temp->x,c;
        char b=temp->y,d;
        temp->x=(temp->x)+m;
        temp->y=(temp->y)+n;
        temp=temp->next;
        while(temp!=NULL)
        {
            if(temp->next==NULL)
            {
                tailx=temp->x;
                taily=temp->y;
            }
            c=temp->x;
            d=temp->y;
            temp->x=a;
            temp->y=b;
            temp=temp->next;
            a=c;
            b=d;
        }
        if(head->x==foodx && head->y==foody)
        {
            addNode(tailx,taily);
            printf("working\n");
            foodx=rand()%20;
            foody=rand()%20;
        }
        display();
        printf("working first if\n");
    }
    

    else if((/*arr[(temp->x)+m][(temp->y)+n]!='1'  ||*/ (temp->y)+n==-1 || ((temp->y)+m==20 && (temp->y)+m==-1) || (temp->y)+n==20))
    {
        if(m==-1)
        {
            char a=temp->x,c;
            char b=temp->y,d;
            temp->x=19;
            temp->y=(temp->y)+n;
            temp=temp->next;
            while(temp!=NULL)
            {
                if(temp->next==NULL)
                {
                    tailx=temp->x;
                    taily=temp->y;
                }
                c=temp->x;
                d=temp->y;
                temp->x=a;
                temp->y=b;
                temp=temp->next;
                a=c;
                b=d;
            }
            printf("working second first if\n");
            display();
        }
        else if(n==-1)
        {
            char a=temp->x,c;
            char b=temp->y,d;
            temp->y=19;
          //a
        temp->x=(temp->x)+m;
            temp=temp->next;
            while(temp!=NULL)
            {
                if(temp->next==NULL)
                {
                    tailx=temp->x;
                    taily=temp->y;
                }
                c=temp->x;
                d=temp->y;
                temp->x=a;
                temp->y=b;
                
                temp=temp->next;
                a=c;
                b=d;
            }
            printf("working second second if\n");
            display();
        }
        else if(m==1)
        {
            char a=temp->x,c;
            char b=temp->y,d;
            temp->x=0;
            temp->y=(temp->y)+n;
            temp=temp->next;
            while(temp!=NULL)
            {
                if(temp->next==NULL)
                {
                    tailx=temp->x;
                    taily=temp->y;
                }
                c=temp->x;
                d=temp->y;
                temp->x=a;
                temp->y=b;
                
                temp=temp->next;
                a=c;
                b=d;
            }
            printf("working second third if\n");
            display();
        }
        else if(n==1)
        {
            char a=temp->x,c;
            char b=temp->y,d;
           //d
            temp->x=temp->x+m;
            temp->y=0;
            temp=temp->next;
            while(temp!=NULL)
            {
                if(temp->next==NULL)
                {
                    tailx=temp->x;
                    taily=temp->y;
                }
                c=temp->x;
                d=temp->y;
                temp->x=a;
                temp->y=b;
                
                temp=temp->next;
                a=c;
                b=d;
            }
            printf("working second fourth if\n");
            display();
        }
}
else
{
    temp=head->next;;
    while(temp!=NULL)
    {
        if(head->x == temp->x && head->y == temp->y)
        {
            printf("\n\n\nGAME OVER!!!!!");
        }
        else
        {
            temp=temp->next;
        }
    }
}
}


int main() {
    int i;
    int a=3;
    int b=3;
    head=new node;
    head->next=NULL;
    head->data='@';
    head->x=a;
    head->y=b;
    temp=head;
    for(i=0;i<5;i++)
    {
        struct node *freshnode=new node;
        freshnode->data='O';
        b++;
        freshnode->x=a;
        freshnode->y=b;
        freshnode->next=NULL;
        temp->next=freshnode;
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        temp->data='o';
    }
    resetArray();
    temp=head;
    display();
    char n;
    
    while(1)
    {
        cin>>n;
        switch(n){
            case'w':
                move(-1,0,n);
                break;
            case'a':
                move(0,-1,n);
                break;
            case's':
                move(1,0,n);
                break;
            case'd':
                move(0,1,n);
                break;
            default:
                continue;
        }
    }
}





