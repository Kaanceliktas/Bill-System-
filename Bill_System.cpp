#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<windows.h>

struct bill
{
 int idno;
 char month[50];
 int e_bill,f_bill,w_bill,g_bill,i_bill;
 int answer=0;
 int std;
}st;
 FILE *fptr;
void write_bill()
   {
    fptr=fopen("bill.txt","ab");
    printf("\nPlease Enter The New Details of bill \n");
    printf("\nEnter The id number of bill ");
    scanf("%d",&st.idno);
    fflush(stdin);
    printf("\n\nEnter The Month of Bill ");
    gets(st.month);
    printf("\nEnter The Value For Electric ");
    scanf("%d",&st.e_bill);
    printf("\nEnter The Value For Food ");
    scanf("%d",&st.f_bill);
    printf("\nEnter The Value For Water ");
    scanf("%d",&st.w_bill);
    printf("\nEnter The Value For Gas ");
    scanf("%d",&st.g_bill);
    printf("\nEnter The Value For Internet ");
    scanf("%d",&st.i_bill);
    st.answer=st.e_bill+st.f_bill+st.w_bill+st.g_bill+st.i_bill;
    fwrite(&st,sizeof(st),1,fptr);
    fclose(fptr);
    printf("\n\nBill Record Has Been Created ");
    getch();
}



void display_all()
{
    system("cls");
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fptr=fopen("bill.txt","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
      printf("\n ID Number of Bill : %d",st.idno);
      printf("\nMonth of Bill : %s",st.month);
      printf("\nValue for Electric: %d",st.e_bill);
      printf("\nValue for Food : %d",st.f_bill);
      printf("\nValue for Water: %d",st.w_bill);
      printf("\nValue for Gas: %d",st.g_bill);
      printf("\nValue for Internet : %d",st.i_bill);
      printf("\nTotal Value of Bill: %d",st.answer);
      printf("\n\n====================================\n");
      getch();
    }
    fclose(fptr);
    getch();
}



void display_sp(int n)
{
    int flag=0;
    fptr=fopen("bill.txt","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(st.idno==n)
        {
        system("cls");
             printf("\nID Number of Bill : %d",st.idno);
             printf("\nMonth of Bill : %s",st.month);
             printf("\nValue for Electric: %d",st.e_bill);
             printf("\nValue for Food : %d",st.f_bill);
             printf("\nValue for Water: %d",st.w_bill);
             printf("\nValue for Gas: %d",st.g_bill);
             printf("\nValue for Internet : %d",st.i_bill);
             printf("\nTotal Value of Bill: %d",st.answer);
            
         flag=1;
        }
    }
    fclose(fptr);
if(flag==0)
 printf("\n\nRecord Not Exist");
    getch();
}



void modify_bill()
{
    int idno,found=0;
   system("cls");
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter the ID Number of Bill");
    scanf("%d",&idno);
    fptr=fopen("bill.txt","rb+");
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
    {
    if(st.idno==idno)
           {
             printf("\n ID Number of Bill : %d",st.idno);
      printf("\nMonth of Bill : %s",st.month);
      printf("\nValue for Electric: %d",st.e_bill);
      printf("\nValue for Food : %d",st.f_bill);
      printf("\nValue for Water: %d",st.w_bill);
      printf("\nValue for Gas: %d",st.g_bill);
      printf("\nValue for Internet : %d",st.i_bill);
      printf("\nTotal Value of Bill: %d",st.answer);
            printf("\nPlease Enter The New Details of Bill \n");
            printf("\nEnter ID Number of Bill ");
            scanf("%d",&st.idno);
            fflush(stdin);
            printf("\n\nEnter the Month of Bill ");
            gets(st.month);
            printf("\nEnter The Value For Electric  : ");
            scanf("%d",&st.e_bill);
            printf("\nEnter The Value For Food  : ");
            scanf("%d",&st.f_bill);
            printf("\nEnter The Value For Water  : ");
            scanf("%d",&st.w_bill);
            printf("\nEnter The Value For Gas  : ");
            scanf("%d",&st.g_bill);
            printf("\nEnter The Value For Internet  : ");
            scanf("%d",&st.i_bill);
            st.answer=st.e_bill+st.f_bill+st.w_bill+st.g_bill+st.i_bill;
            
            fseek(fptr,-(long)sizeof(st),1);
            fwrite(&st,sizeof(st),1,fptr);
            printf("\n\n\t Record Updated");
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    printf("\n\n Record Not Found ");
    getch();
}





void delete_bill()
   {
    int idno;
    FILE *fptr2;
    system("cls");
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter ID Number of Bill That You Want to Delete");
    scanf("%d",&idno);
    fptr=fopen("bill.txt","rb");

    fptr2=fopen("Temp.txt","wb");
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
       if(st.idno!=idno)
       {
      fwrite(&st,sizeof(st),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("bill.txt");
    rename("Temp.dat","bill.txt");
    printf("\n\n\tRecord Deleted ..");
    getch();
}



    void bill_result()
    {
     system("cls");
     fptr=fopen("bill.txt","rb");
     if(fptr==NULL)
     {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

     printf("\n\n\t\t GENERAL BILL \n\n");
     printf("\033[1;31m");
      printf("====================================================================\n");
      printf("BillNo.  Month       E   F   W   G   I  TOTAL                    \n");   
      printf("====================================================================\n");
      printf("\033[0m;");
      while((fread(&st,sizeof(st),1,fptr))>0)
     {
     	 printf("\033[0;32m");
       printf("%-6d %-10s %-3d %-3d %-3d %-3d %-3d %-3d\n ",st.idno,st.month,st.e_bill,st.f_bill,st.w_bill,st.g_bill,st.i_bill,st.answer);
        printf("\033[0m;");
     }
     fclose(fptr);
     getch();
}



   void result()
   {
    int ans,rno;
    char ch;
    system("cls");
    printf("\n\n\nRESULT MENU");
    printf("\n\n\n1. GENERAL BUDGET PAYMENTS \n\n2. SPECIAL BILL \n\n3. BACK TO MAIN MENU");
    printf("\n\n\n PLEASE ENTER YOUR CHOICE ");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 : bill_result();break;
     case 2 : {
        do{
        char ans;
        system("cls");
        printf("\n\nEnter ID Number of Bill : ");
        scanf("%d",&rno);
        display_sp(rno);
        printf("\n\nDo you want to See More Result (y/n)?");
        scanf("%c",&ans);
        }while(ans=='y'||ans=='Y');
        break;
           }
     case 3: break;
     default:  printf("\a");
    }
 }


void intro()
{
 
    
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               Bill Tracking               =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\t\tBeykoz University, Kaan Celiktas");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\t\t\t\t2020");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();

}

void entry_menu()
{
    char ch2;
   system("cls");
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE BILL RECORD");
  printf("\n\n\t2.DISPLAY ALL BILL PAYMENTS");
  printf("\n\n\t3.SEARCH BILL RECORD ");
  printf("\n\n\t4.MODIFY BILL RECORD");
  printf("\n\n\t5.DELETE BILL RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': system("cls");
          write_bill();
          break;
    case '2': display_all();break;
    case '3':  {
           int idno;
           system("cls");
           printf("\n\n\tPlease Enter the Id Number of Bill ");
           scanf("%d",&idno);
           display_sp(idno);
           }
           break;
      case '4': modify_bill();break;
      case '5': delete_bill();break;
      case '6': break;
      default:printf("\a");entry_menu();
   }
}
int main()
{
  char ch;
  intro();
  do
    {
      system("cls");
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. BILL MENU");
      printf("\n\n\t02. ENTRY OR EDIT BUDGET MENU");
      printf("\n\n\t03. EXIT");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
      {
         case '1': system("cls");
               result();
               break;
          case '2': entry_menu();
                break;
          case '3':exit(0);
          default :printf("\a");
    }
    }while(ch!='3');
     return 0;
}
