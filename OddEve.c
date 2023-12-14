#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int comp_bat();
int user_bat();

void main()
{
    printf("To choose odd enter O\nTo choose even enter E\n");
    char user_start;
    scanf("%s",&user_start);

    printf("Only enter numbers upto 6\nEnter number for toss\n");
    int user_toss;
    scanf("%d",&user_toss);

    while(user_toss>6)//SO USER DOESN'T ENTER NUMBER GREATER THAN 6
    {
        printf("Invalid entry. Please only enter letters till 6.\n");
        scanf("%d",&user_toss);
    }

    int comp_toss= (rand())%6+1;
    int sum_toss=user_toss+comp_toss;
    printf("Computer throw = %d\n",comp_toss);
    int user_total, comp_total, comp_choice=2, user_choice=2;
    
    if(((user_start=='e'||user_start=='E')&&sum_toss%2==0)||((user_start=='O'||user_start=='o')&&sum_toss%2==1))//IF USER WINS TOSS
    {
        printf("Enter 1 to bat first, 0 to ball\n");
        scanf("%d",&user_choice);        
    }
    else//IF COMPUTER WINS TOSS
    {
        comp_choice=(rand())%2;
    }

    if(user_choice==1||comp_choice==0)//IF USER CHOOSES TO BAT OR COMPUTER TO BALL FIRST
    {
        user_total=user_bat(-1);
        comp_total=comp_bat(user_total);
    }
    else//IF COMPUTER CHOOSES TO BAT OR USER TO BALL FIRST
    {
        comp_total=comp_bat(-1);
        user_total=user_bat(comp_total);
    }

    
    if(comp_total>user_total)
    printf("Computer wins");
    else if(comp_total<user_total)
    printf("User wins");
    else
    printf("Draw");
}

int user_bat(int comp_total)
{
    printf("\nUser is batting\n");
    int user_total=0;
    int user_throw;
    int comp_throw;
    
    for(;;)
    {
        printf("Enter number\n");
        scanf("%d",&user_throw);

        while(user_throw>6)//SO USER DOESN'T ENTER NUMBER GREATER THAN 6
        {
            printf("Invalid entry. Please only enter letters till 6.\n");
            scanf("%d",&user_throw);
        }

        comp_throw= (rand())%6+1;
        printf("Computer throw : %d\n",comp_throw);

        if(user_throw==comp_throw)
        {
            printf("User is out\n");
            break;
        }
        if((user_total>comp_total)&&(comp_total!=-1))
        break;


        user_total+=user_throw;
    }
    printf("User total : %d\n",user_total);
return user_total;
}

int comp_bat(int user_total)
{
    printf("\nComputer is batting\n");
    int comp_total=0;
    int user_throw;
    int comp_throw;
    
    for(;;)
    {
        printf("Enter number\n");
        scanf("%d",&user_throw);

        while(user_throw>6)//SO USER DOESN'T ENTER NUMBER GREATER THAN 6
        {
            printf("Invalid entry. Please only enter letters till 6.\n");
            scanf("%d",&user_throw);
        }

        comp_throw=(rand())%6+1;
        printf("Computer throw : %d\n",comp_throw);

        if(user_throw==comp_throw)
        {
            printf("Computer is out\n");
            break;
        }
        if((comp_total>user_total)&&(user_total!=-1))
        break;


        comp_total+=comp_throw;
    }
    printf("Computer total : %d\n",comp_total);
return comp_total;
}