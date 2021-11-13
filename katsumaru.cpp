#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    printf("Black Jack ...\n\n");
    
    srand((unsigned int) time(NULL));
    int data[1000];
    //int data2[1000];
    int b;

    do{
        int a,i=1,sum=0,sum2=0;
        
        data[0]=rand()%13+1;
        if(data[0]>10){
            data[0]=10;
        } else if(data[0]==1){
            data[0]=11;
        }
        sum+=data[0];

        do{
            data[i]=rand()%13+1;
            printf("your cards are %d",data[0]);
            for(int j=1;j<=i;j++){
                printf(" and %d",data[j]);
                if(data[j]>10){
                    data[j]=10;
                } else if(data[j]==1&&sum2+11<=21){
                    data[j]=11;
                }
                sum+=data[j];
            }
            printf("\ntotal point is %d\n",sum);
            printf("\n");
            if(sum>22){
                printf("total point is over 21");
                break;
            }
        //    do{
                printf("if you want to hit, please push 1.\n"
                        "if you want to stand, please push 2.\n");
                scanf("%d",&a);
        //    }while(a!=1&&a!=2);
            i++;
            sum2=sum;
            sum=data[0];
        }while(a==1);

        if(sum2==21){
            printf("\nyour score is %d\n",sum2);
            printf("Black Jack!!!!\n\n");
        } else if (sum2>21){
            printf("try again\n\n");
        }
        
        printf("if you play one more time, please push 1.:");
        scanf("%d",&b);

    }while(b==1);

    return 0;
}