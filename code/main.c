#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int z =40;

struct books {
int id ;
int quan ;
char name [40];
};
struct books r [10];
int insert (int x,int y ,char name [],int n,int b_n)
{
    FILE *file;
    file=fopen("books.txt","a");
    if (file == NULL)
    {
        printf("error.......\n");
    }
    fprintf(file,"%d %d %s \n",x,y,name);
    fclose(file);

}
void del(int did,int b_n)
{
   FILE *file;
   file = fopen("books.txt","r");
   int i=0;
   while(!feof(file))
   {
       fscanf(file,"%d %d ",&r[i].id,&r[i].quan);
       fgets(r[i].name,40,file);
       fscanf(file,"/n");
       i++;
   }
   fclose(file);
   FILE *fp;
   fp=fopen("books.txt","w");
    for (int z=0;z<b_n;z++)
    {
        if (did==r[z].id)
            continue;
         else
            fprintf(fp,"%d %d %s\n",r[z].id,r[z].quan,r[z].name);
    }
    fclose(fp);

}
int search_id(int sid,int b_n)
{
    FILE *file;
   file = fopen("books.txt","r");
   int i=0;
   while(!feof(file))
   {
       fscanf(file,"%d %d ",&r[i].id,&r[i].quan);
       fgets(r[i].name,40,file);
       fscanf(file,"/n");
       i++;
   }
   if (b_n<=0)
   {
    printf("your book not found.....\n");
    return 0;
   }
   else if (sid==r[b_n-1].id){
     printf("%d %s\n",r[b_n-1].quan,r[b_n-1].name);
     return 0;}
   else{
    search_id(sid,b_n-1);}
}
void search_name(int b_n)
{
    int s1,s2;
    char s3[40];
    FILE*file;
    file=fopen("books.txt","r");
    if (file==NULL){printf("your file not found");}
    int i=0;
   while(!feof(file))
   {
       fscanf(file,"%d %d %s\n",&r[i].id,&r[i].quan,r[i].name);
       i++;
   }

       for (int x=0;x<b_n;x++)
    {
        for (int y = x + 1 ; y < b_n; y++)
        {
         if((strcmp(r[x].name,r[y].name))>0 && x+1 < b_n)
           {
               strcpy(s3,r[x].name);
               strcpy(r[x].name,r[y].name);
               strcpy(r[y].name,s3);

               s1=r[x].id;
               r[x].id=r[y].id;
               r[y].id=s1;

               s2=r[x].quan;
               r[x].quan=r[y].quan;
               r[y].quan=s2;
           }
        }

    }
    int low=0,high=b_n-1,mid;
    char b_name [40];
    printf("enter book name : ");
    getchar();
    gets(b_name);
    while (low<=high)
    {
        mid=(low+high)/2;
        if(strcmp(b_name,r[mid].name)==0)
        {
            printf("%d %d \n",r[mid].id,r[mid].quan);
            return;
        }
        else if (strcmp(b_name,r[mid].name)==-1)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    fclose(file);
    printf("your book not found\n");
}
void sorting_veiw (int b_n)
{
    int s1,s2;
    char s3[40];
    FILE*file;
    file=fopen("books.txt","r");
    if (file==NULL){printf("your file not found");}
    int i=0;
    while(!feof(file))
   {
       fscanf(file,"%d %d ",&r[i].id,&r[i].quan);
       fgets(r[i].name,40,file);
       fscanf(file,"/n");
       i++;
   }
    for (int x=0;x<b_n;x++)
    {
        for (int y = x + 1 ; y < b_n; y++)
        {
         if((strcmp(r[x].name,r[y].name))>0 && x+1 < b_n)
           {
               strcpy(s3,r[x].name);
               strcpy(r[x].name,r[y].name);
               strcpy(r[y].name,s3);

               s1=r[x].id;
               r[x].id=r[y].id;
               r[y].id=s1;

               s2=r[x].quan;
               r[x].quan=r[y].quan;
               r[y].quan=s2;
           }
        }

    }
    for(int x=0;x<b_n;x++)
    {
        printf("%d %d %s\n",r[x].id,r[x].quan,r[x].name);
    }


}
void veiw (int b_n)
{
    FILE *file;
    file =fopen("books.txt","r");
    if (file==NULL){printf("your file not found....\n");}
    for(int i=0;i<b_n;i++)
    {
        fscanf(file,"%d %d ",&r[i].id,&r[i].quan);
        fgets(r[i].name,40,file);
        fscanf(file,"\n");
        printf("%d %d %s\n",r[i].id,r[i].quan,r[i].name);
    }
    fclose(file);
}
int main ()
{
    int b_n=2;
    char ch;
    printf("----------------------------wlecome to my project------------------------------\n");
do{
    printf("1-press 1 to insert a book\n");
    printf("2-press 2 to delete a book by id\n");
    printf("3-press 3 to search a book by id\n");
    printf("4-press 4 to search a book by name\n");
    printf("5-press 5 to view sorting books\n");
    printf("6-press 6 to view books\n");
    int o;
    printf("your choise: ");
    scanf("%d",&o);
        switch(o)
        {
        case 1:
            printf("enter the book inforamtion:\n");
            int d,q;
            char n[40];
            scanf("%d %d",&d,&q);
            gets(n);
            b_n++;
            insert(d ,q ,n,z,b_n);
            printf("%d",b_n);
            break;
        case 2:
            printf("inter your id: \n");
            int did;
            scanf("%d",&did);
            del (did,b_n);
            b_n--;
            printf("%d",b_n);
            break;
        case 3:
            printf("enter your id: \n");
            int sid;
            scanf("%d",&sid);
            search_id(sid,b_n);
            break;
        case 4:
            search_name(b_n);
            break;
        case 5:
            sorting_veiw(b_n);
            break;
        case 6:
            veiw(b_n);
            break;
        default:
            printf("\n.........................error..........................\n");
}

printf ("Do you want to repeat the operation Y/N: ");
scanf (" %c", &ch);
    }
    while (ch == 'y' || ch == 'Y');
    return 0;
}
