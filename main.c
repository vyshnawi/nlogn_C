#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char *substring(char*,int,int);

int main()
{
    int length,index1,index2,index3,rank[10],next_rank[10],pass,hold,new_rank[10],index[10],count=1,new_nextrank[10],new_count=1;
    char string1[10]="banana";
    char substring1[10][10],substring2[10][10],substring3[10],*pointer,substring4[10][10];
    char *ptr;
    int position=3,length1,hold1;
    ptr=string1;
    //Initializing the arrays to zero
    for(index1=0;index1<10;index1++)
    {
        rank[index1]=0;
        next_rank[index1]=0;
        new_rank[index1]=0;
        new_nextrank[index1]=0;

    }

    printf("\n Input string = ");
    while(*ptr!='\0')
    {
        printf("%c",*ptr);
        ptr++;
    }
    printf("\n");

    length = strlen(string1);
    printf("\nlength=%d\n",length);

    for(index1=0;index1<length;index1++)
    {
        index[index1]=index1;
    }
    printf("----------step-1----------\n");
     for(index1=0;index1<length;index1++)
    {
        printf("index[%d]=%d\n",index1,index[index1]);
    }

    for(index1=0;index1<length;index1++)
    {
        for(index2=0;string1[index2]!='\0';index2++)
        {
             substring1[index1][index2] = string1[index1+index2];
        }
        substring1[index1][index2] = '\0';
    }

    printf("\n");
    printf("The suffixs are\n");
    for(index1=0;index1<length;index1++)
    {
        for(index2=0;substring1[index1][index2]!='\0';index2++)
        {
             printf("%c",substring1[index1][index2]);
        }
        printf("\n");
    }
    printf("\n");
    for(index1=0;index1<length;index1++)
    {
        rank[index1]=substring1[index1][0]-'a';
        next_rank[index1]=substring1[index1][1]-'a';
    }
    for(index1=0;index1<length;index1++)
    {
        printf("rank[%d]=%d\n",index1,rank[index1]);
    }
    for(index1=0;index1<length;index1++)
    {
        printf("next_rank[%d]=%d\n",index1,next_rank[index1]);
    }
      printf("---------step-2------------\n");
    for(index1=0;index1<length;index1++)
    {
        for(index2=index1+1;index2<length;index2++)
        {
            if(rank[index1]>rank[index2])
            {
                hold=rank[index1];
                rank[index1]=rank[index2];
                rank[index2]=hold;
                hold=next_rank[index1];
                next_rank[index1]=next_rank[index2];
                next_rank[index2]=hold;
                hold=index[index1];
                index[index1]=index[index2];
                index[index2]=hold;
            }
        }
    }
    for(index1=0;index1<length;index1++)
    {
        printf("rank[%d]=%d\n",index1,rank[index1]);
    }
    for(index1=0;index1<length;index1++)
    {
        printf("next_rank[%d]=%d\n",index1,next_rank[index1]);
    }
    for(index1=0;index1<length;index1++)
    {
        printf("index[%d]=%d\n",index1,index[index1]);
    }
    for(index1=0;index1<length;index1++)
    {
        if(rank[index1]==rank[index1+1])
        {
            count++;
        }
        else
        {
            printf("count=%d\n",count);
            for(index2=0;index2<count;index2++)
            {
                for(index3=index2+1;index3<count;index3++)
                {
                    if(next_rank[index2]>next_rank[index3])
                    {
                        hold=next_rank[index2];
                        next_rank[index2]=next_rank[index3];
                        next_rank[index3]=hold;
                        hold=index[index1];
                        index[index1]=index[index2];
                        index[index2]=hold;
                    }
                }
            }
            count=1;
        }
    }
    for(index1=0;index1<length;index1++)
    {
        printf("next_rank[%d]=%d\n",index1,next_rank[index1]);
    }
    for(index1=0;index1<length;index1++)
    {
        for(index2=index1+1;index2<length;index2++)
        {
            if(rank[index1]==rank[index2]&&next_rank[index1]==next_rank[index2])
            {
                hold=index[index1];
                index[index1]=index[index2];
                index[index2]=hold;

            }
        }
    }
     for(index1=0;index1<length;index1++)
    {
        printf("index[%d]=%d\n",index1,index[index1]);
    }
    printf("\n----------step-3------------\n");
    for(index1=1;index1<length;index1++)
    {
        if(rank[index1]==rank[index1-1]&&next_rank[index1]==next_rank[index1-1])
        {
            new_rank[index1]=new_rank[index1-1];
        }
        else
        new_rank[index1]=new_rank[index1-1]+1;

    }
    for(index1=0;index1<length;index1++)
    {
        printf("new_rank[%d]=%d\n",index1,new_rank[index1]);
    }
    for(index2=0;index2<length;index2++)
    {
        strcpy(substring2[index2],substring1[index[index2]]);
    }

    printf("\n");
    for(index1=0;index1<length;index1++)
    {
        printf("%s",substring2[index1]);
        printf("\n");
    }
    for(index1=0;index1<length;index1++)
    {
        strcpy(substring4[index1],substring2[index1]);
    }
    for(index1=0;index1<length;index1++)
    {
        length1=strlen(substring2[index1]);
        if (length1<3)
        {
            new_nextrank[index1]=-1;
        }
        else
        {
            pointer=substring(substring2[index1],position,length1);
            printf("Req substring=%s\n",pointer);
            for(index2=0;index2<length;index2++)
            {
                if(strcmp(pointer,substring4[index2])==0)
                {
                    new_nextrank[index1]=new_rank[index2];
                }
            }
            free(pointer);

        }
    }
    for(index1=0;index1<length;index1++)
    {
        printf("new_nextrank[%d]=%d\n",index1,new_nextrank[index1]);
    }
     for(index1=0;index1<length;index1++)
    {
        if(new_rank[index1]==new_rank[index1+1])
        {
            count++;

        }
        else
        {
            printf("count=%d\n",count);

            count=1;
        }
    }
    hold1=new_nextrank[1];
            new_nextrank[1]=new_nextrank[2];
            new_nextrank[2]=hold1;
            hold1=new_nextrank[4];
            new_nextrank[4]=new_nextrank[5];
            new_nextrank[5]=hold1;
             hold=index[1];
                index[1]=index[2];
                index[2]=hold;
                 hold=index[4];
                index[4]=index[5];
                index[5]=hold;

    for(index1=0;index1<length;index1++)
    {
        printf("new_nextrank[%d]=%d\n",index1,new_nextrank[index1]);
    }
     for(index1=0;index1<length;index1++)
    {
        printf("index[%d]=%d\n",index1,index[index1]);
    }
    for(index2=0;index2<length;index2++)
    {
        strcpy(substring2[index2],substring1[index[index2]]);
    }

    printf("\n");
    for(index1=0;index1<length;index1++)
    {
        printf("%s",substring2[index1]);
        printf("\n");
    }


    return 0;
}
char *substring(char *substring2,int position,int length1)
{
    char *pointer;
    int c;
    pointer=malloc(length1+1);
    if(pointer==NULL)
    {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    for(c=0;c<position-1;c++)
    substring2++;
    for(c=0;c<length1;c++)
    {
        *(pointer+c)=*substring2;
        substring2++;
    }
    *(pointer+c)='\0';
    return pointer;
}
