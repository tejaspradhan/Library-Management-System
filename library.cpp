#include<simplecpp>
#include<stdio.h>

int i, j, tot=0;
struct library
  {
    int acc_no;
    char title[50];
    char name[50];
    float price;
    int flag;

  };  struct library b[100],temp[100];
void addbook(struct library *x);
void display(struct library *x);
void adisplay();
void stitle();
void blist();
main_program
{
            //Library Management




  int n,a;
  printf("Welcome to the Library\n");
  while(1!=0)
  {
    printf("To continue to main menu, press 1 \n To Exit press 2 \n");
    scanf("%d",&n);
    if(n==2)
    break;
    else
    {
       printf("Press 1=>Adding book info\n 2=> Displaying book info\n 3=>List all the books of the given author\n 4=>List the title of the specified book\n 5=>List total no of books\n 6=>List the books in order of accession no.:\n");
       scanf("%d",&a);
       switch(a)
       {
         case 1: int m;

                  printf("Enter the no. of books to add\n");
                  scanf("%d",&m);
                 for( i=tot; i<(m+tot); i++)
                 {
                  addbook(&b[i]);
                 }
                 tot += m;
                 break;

         case 2: printf("Accession No.\tTitle\t\tAuthor\t\tPrice\tIssue Status\n");
                 for(j=0;j<tot;j++)
                 {
                 display(&b[j]);
                 }
                break;
         case 3: adisplay();
                 break;

         case 4: stitle();
                 break;

         case 5:  printf("Total number of books added are : %d \n", tot );
                 break;

         case 6:  blist();
                 break;


        default: printf("Enter a valid no.");
       }//switch
    } //else

  }//while

}

void addbook(struct library *x)
{

     int k=0, l=0;
     printf("Enter name of the book(with a fullstop in the end):\t");
     while(x->title[k-1]!='.')
     {
        scanf("%c",&x->title[k]);
        k++;
     }
     printf("Enter accession no.:\t");
     scanf("%d",&x->acc_no);

     printf("Enter name of the author(with a fullstop in the end):\t");
     while(x->name[l-1]!='.')
     {
        scanf("%c",&x->name[l]);
        l++;
     }

      printf("Enter the price:\t");
     scanf("%f",&x->price);

     printf("Enter 1 if book is issued or press 2 if not:\t");
     scanf("%d",&x->flag);
}

void display(struct library *x)
{
 int i=0, j=0;

      printf("%d\t",x->acc_no);
     while(x->title[i-1]!='.')
     {
        printf("%c",x->title[i]);
        i++;
     }
     printf("\t");

    while(x->name[j-1]!='.')
     {
        printf("%c",x->name[j]);
        j++;
     }

     printf("\t");
     printf("%0.2f\t",x->price);
     if(x->flag == 1)
     {
     printf("Issued\n");
     }
     else
     {
     printf("Not issued\n");
     }
}

void adisplay()   // To display books written by a particular author.
{
   int t=0,v;
   char aut[50];
  printf("Enter the author name to be searched\n");
  while(aut[t-1]!='.')
{
  scanf("%c",&aut[t]);
  t++;
  }
  int s=0,k=0, counter=0;
   for(i=0; i<tot; i++)
   {
     v=strlen(b[i].name);
     if(t==v)
     {
        for(j=0; j<t; j++)
      {
         if(aut[j]==b[i].name[j])
         {
          s++;
         }
      }
     if(s==t)
     {
       counter++;
       printf("Accession No.:%d\n Book Name: ",b[i].acc_no);
       while(b[i].title[k-1]!='.')
       {
         printf("%c",b[i].title[k]);
         k++;
       }
       printf("\n");
      }

     }
   }
if(counter==0)
{
printf("No records found \n");
}

}
void stitle()
{
  int t=0,v, s=0,counter = 0;
  char tit[50];
  printf("Enter the title of the book to be searched\n");
  while(tit[t-1]!='.')
{
  scanf("%c",&tit[t]);
  t++;
  }

  for(i=0; i<tot; i++)
   {
     v=strlen(b[i].title);
     if(t==v)
     {
    for(j=0; j<t; j++)
      {
        if( tit[j]== b[i].title[j] )
         {
          s++;
         }
      }
  if(s==t)
     {
       counter++;
       display(&b[i]);
      }

     }

   }
if (counter ==0)
printf("Book not found");
}
void blist()
{
 for (i = 0;i < tot; i++)
   {
     for (j = 0 ; j < 2-i ; j++)
      {
        if (b[j].acc_no> b[j+1].acc_no)
           {
             temp[j] = b[j];
             b[j] = b[j+1];
             b[j+1] = temp[j];

           }
      }
   }
    for(i=0;i<tot;i++)
     {
       display(&b[i]);
     }


}










