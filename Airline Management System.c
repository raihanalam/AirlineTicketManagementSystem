#include<stdio.h>
#include<time.h>
#include<string.h>
#include<conio.h>
void header();
void home();
void flight();
void booking(int fl, char bill[200], char ftime[30],char airline[100]);
void cancellation();
void precords();
void plist();
void adminmode();
void password();
void login();
void forgotpassword();
void quit();
void cancel_req();
void cancel();
void schedule();
time_t t;
char choice;
int main()
{
    int i=0;
    char c,pass[100];
    FILE *maspass;
    maspass=fopen("password.txt","r+");

    while((c=fgetc(maspass))!=EOF)
    {
        pass[i]=c;
        i++;
    }
    pass[i]='\0';

    if(maspass=='\0')
    {
        fclose(maspass);
        printf("Set A Master Password Now\n");
        gets(pass);
        maspass=fopen("password.txt","w");
        fprintf(maspass,"%s",pass);
    }
    fclose(maspass);
    while(1)
    {
    system("cls");
    header();

    printf("\t\t\t\t\t\t\t ---------------\t    --------------------\n");
    printf("\t\t\t\t\t\t\t | 1 > Booking |\t    | 2 > Cancellation |\n");
    printf("\t\t\t\t\t\t\t ---------------\t    --------------------\n");
    printf("\t\t\t--------------------\t\t\t\t\t\t\t\t\t-----------------\n");
    printf("\t\t\tOur Airline Partners\t\t\t\t\t\t\t\t\tOur Paid Partners\n");
    printf("\t\t\t--------------------\t\t\t\t\t\t\t\t\t-----------------\n");
    printf("\t\t\t> Biman Bangladesh Airline\t\t\t\t\t\t\t\t> Visa\n");
    printf("\t\t\t> US-Bangla Airlines\t\t\t\t\t\t\t\t\t> Master Card\n");
    printf("\t\t\t> Malaysia Airlines\t\t\t\t\t\t\t\t\t> Paypal\n");
    printf("\t\t\t> Emirates\t\t\t\t\t\t\t\t\t\t> Payoneer\n");
    printf("\t\t\t> Qatar Airways\n");
    printf("\t\t\t> Singapore Airlines\n");
    printf("\t\t\t> Air India\n");

    printf("\t\t\t\t\t\t---------------\t    ------------------------ \t------------\n");
    printf("\t\t\t\t\t\t| 3 > Sign In |\t    | 4 > Forgoot Password | \t| 0 > Exit |\n");
    printf("\t\t\t\t\t\t---------------\t    ------------------------ \t------------\n");


    fflush(stdin);
    choice  = getche();
    if(choice=='1')
        flight();
    else if(choice=='2')
        cancellation();
    else if(choice=='3')
        //home();
        login();
    else if(choice=='4')
        forgotpassword();
    else if (choice=='0')
        exit(0);
    }
    getch();
}
void header()
{
    char a[100];
    FILE *user;
    user=fopen("user.txt","r");
    fgets(a,20,user);

    printf("   \t\t\t\t\t\t=============================================================\n");
    printf("   \t\t\t\t\t\t||                      AIRLINE TICKET                     ||\n");
    printf("   \t\t\t\t\t\t=============================================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUser: %s\n",a);
    fclose(user);
}
//Home Page for loged users
void home()
{
    while(1)
    {
    system("cls");
    header();

    printf("-------------\n");
    printf("| Main MENU |\n");
    printf("-------------\n\n");
    printf("1 > Booking\n");
    printf("2 > Cancellation\n");
    printf("3 > Passengers Record\n");
    printf("4 > Passengers List\n");
    printf("5 > Cancellation Request\n");
    printf("6 > Admin MOde\n");
    printf("7 > Log Out\n\n");

    printf("---------------\t------------\n");
    printf("| Choice > Go |\t| 0 > Exit |\n");
    printf("---------------\t------------\n");

    fflush(stdin);
    choice  = getche();

    switch(choice)
    {
        case '1':
            flight();
            break;
        case '2':
            cancellation();
            break;
        case '3':
            precords();
            break;
        case '4':
            plist();
            break;
        case '5':
            cancel_req();
        case '6':
            adminmode();
            break;
        case '7':
            {
                FILE *user;
                user=fopen("user.txt","w");
                fprintf(user,"Unknown");
                fclose(user);
                main();
                break;
            }
        case '0':
            quit();
            break;

    }
    }
}
void flight()
{
    while(1)
    {
    system("cls");
    header();
    int fl;

    printf("\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t\t\t\t\t~ List Of The Flights ~\n");
    printf("\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    printf("SNO\tFlight No\tFrom\t\tTo\t\t\tE Class\t\tB Class\t\tF Class\t\tFlight Time\tAirline\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");

    FILE *flight;
    flight=fopen("flight.txt", "r");
    char c;
    while((c=fgetc(flight))!=EOF)
        putchar(c);
    fclose(flight);

    printf("----------------\t-----------\t------------\n");
    printf("| 1 > Book Now |\t|# > Back |\t| 0 > Exit |\n");
    printf("----------------\t-----------\t------------\n");
    choice=getche();
    if(choice=='1')
    {
        printf("\n------------------------------\n");
        printf("Enter SNO Number Of Flights: |\n");
        printf("------------------------------\n");

        scanf("%d",&fl);
        char a,b[20000],s[1000];
        int i=0,c=1,d=0,j;
        ///Reading E Class/ B Class/ F Class Bill from Flight File
        FILE *copy;
        copy=fopen("flight.txt", "r");
        //Copying Full File in a string
        while((a=fgetc(copy))!=EOF)
        {
            b[i]=a;
            i++;
        }
        b[i]='\0';
        fclose(copy);

        for(i=0;b[i]!='\0';i++)
        {
            //Checking line using SNO(FL)
            if(b[i]=='\n')
            {
                c++;
                if(c==fl)
                {
                    d=i;
                }
            }
        }
        //Copying Line in a String(S)
        for(i=d+1,j=0;b[i]!='\n';i++,j++)
        {
            s[j]=b[i];
        }
        s[j]='\0';
        ///Reading Time from Flight file
        int t=13,ti=0,tim=0;
        char ftime[50];
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='\t')
            {
                ti++;
                if(ti==t)
                   tim=i;
            }
        }
        for(i=tim+1,j=0;s[i]!='\t';i++,j++)
        {
            ftime[j]=s[i];
        }
        ftime[i]='\0';

        int al=14,all=0,air=0;
        char airline[100];
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='\t')
            {
                all++;
                if(all==al)
                   air=i;
            }
        }
        for(i=air+1,j=0;s[i]!='\t';i++,j++)
        {
            airline[j]=s[i];
        }
        airline[i]='\0';

        printf("-------------------------------------------\n");
        printf("| 1 > E Class | 2 > B Class | 3 > F Class |\n");
        printf("-------------------------------------------\n");
        int m=0,k=0;
        char clas,bill[200];

        choice=getche();

        if(choice=='1')
            clas=7;
        else if(choice=='2')
            clas=9;
        else if(choice=='3')
            clas=11;

        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='\t')
            {
                m++;
                if(m==clas)
                    k=i;
            }
        }

        for(i=k+1,j=0;s[i]!='\t';i++,j++)
        {
            bill[j]=s[i];
        }
        bill[j]='\0';

        if(fl>=1 && fl<=12)
            booking(fl,bill,ftime,airline);
    }
    else if(choice=='#')
    {
        main();
    }
    else if(choice=='0')
    {
        quit();
    }
}
}
//For booking Tickets
void booking(int fl, char bill[200], char ftime[30],char airline[100])
{
while(1)
{
    system("cls");
    header();
    time(&t);
    struct booking
    {
    char name[100],address[100];
    int age;
    char passport[100];
    char gender[8];
    int phone;
    };

    struct booking list[30];
    int i,many=0;
    int ticket_id;
    printf("\n----------------------\n");
    printf("| Number of Tickets: |");
    printf("\n----------------------\n");
    scanf("%d",&many);

    if(many>0 && many<=100)
    {
        //Initializing booking id from Ticket_Counter file;
        FILE *ticket_counter;
        ticket_counter=fopen("ticketcounter.txt", "r");
        if(ticket_counter=='\0'){
            fclose(ticket_counter);
            ticket_counter=fopen("ticketcounter.txt", "w");
            fprintf(ticket_counter,"%s","0");
            fclose(ticket_counter);
        }
        ticket_counter=fopen("ticketcounter.txt", "r");
        fscanf(ticket_counter,"%d",&ticket_id);
        fclose(ticket_counter);

        //Getting Input for Ticket
        for(i=0;i<many;i++)
        {
            printf("\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\t\t\t\t\t\t\t\t~ Enter Information For Ticket %d ~",i+1);
            printf("\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            fflush(stdin);
            printf("Name: ");
            gets(list[i].name);
            printf("Passport Number: ");
            scanf("%s",&list[i].passport);
            printf("Address: ");
            fflush(stdin);
            gets(list[i].address);
            printf("Age: ");
            scanf("%d",&list[i].age);
            printf("Gender: ");
            scanf("%d",&list[i].gender);
            printf("Mobile Number: ");
            fflush(stdin);
            scanf("%d",&list[i].phone);

        }

        //Payment information
        printf("\n\t\t\t\t\t\t\t\t\t-------------------\n");
        printf("\t\t\t\t\t\t\t\t\tPayment Information\n");
        printf("\t\t\t\t\t\t\t\t\t-------------------\n");

        struct pay
        {
            int number[20];
            int ex_date[2];
            char name[20];
            char pin[20];
            char amount[100];
        };
        struct pay user;

        printf("----------------------\n");
        printf("Credit Card/Debit Card\n");
        printf("----------------------\n\n");

        fflush(stdin);
        printf("Card Number: ");
        scanf("%d",&user.number);
        fflush(stdin);
        printf("Card Owner Name(Surname): ");
        gets(user.name);
        printf("Card Expired Date(MM/YY): ");
        scanf("%d%d",&user.ex_date[0],&user.ex_date[1]);
        if(user.ex_date[0]> 10000*10 && user.ex_date[1]<100000*20)
        {
            printf("Date Expired! Try again");
            flight();
        }
        printf("Enter Amount(TK):");
        scanf("%s",&user.amount);
        //Checking bill comes from chossing class
        int d=strcmp(bill,user.amount);
        if(d==0)
        {
            printf("Card Security Number: ");
            fflush(stdin);
            gets(user.pin);

            printf("----------------\t\t------------\n");
            printf("| 1 > Purchase |\t\t| 0 > Exit |\n");
            printf("----------------\t\t------------\n\n");

            choice=getche();

            if(choice=='0')
            {
                quit();
            }
            else if(choice=='1')
            {
                for(i=0;i<many;i++)
                {
                    //Initializing File for Passenger List
                    FILE *plist;
                    plist=fopen("plist.txt", "a");
                    if(plist==NULL)
                    {
                        printf("Error");
                        exit(1);
                    }
                    else
                        fprintf(plist,"BOID%d     : %s  FL60%d\n",ticket_id+1+i,list[i].name,fl+50);
                        fclose(plist);
                    //Initializing File for Passenger Records
                    FILE *precords;
                    precords=fopen("precords.txt", "a");
                    if(precords==NULL)
                    {
                        printf("Error");
                        exit(1);
                    }
                    else
                    {
                        fprintf(precords,"-----------------------\n");
                        fprintf(precords," Booking ID : BOID%d \n",ticket_id+1+i);
                        fprintf(precords,"-----------------------\n");
                        fprintf(precords,"Flight No   : FL60%d\n",fl+50);
                        fprintf(precords,"Name        : %s\n",list[i].name);
                        fprintf(precords,"Address     : %s\n",list[i].address);
                        fprintf(precords,"Passport NO : %s\n",list[i].passport);
                        fprintf(precords,"Age         : %d\n",list[i].age);
                        fprintf(precords,"Gender      : %s\n",list[i].gender);
                        fprintf(precords,"Mobile No   : %d\n",list[i].phone);
                        fprintf(precords,"Card Number : %d\n",user.number);
                        fprintf(precords,"Paid        : %s\n",user.amount);
                        fprintf(precords,"Booking Time: %s",ctime(&t));
                        fclose(precords);
                    }
                }
                printf("\n\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\t\t\t\t\t\t\t\t~ Congratulations Your Ticket Is Ready ~\n");
                printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

                for(i=0;i<many;i++)
                {
                    printf("............\n");
                    printf("| Ticket %d |\n",i+1);
                    printf("............\n");
                    printf("\n\n");
                    printf("\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\t\t\t\t\t\t|                     Airline Ticket                     |\n");
                    printf("\t\t\t\t\t\t|--------------------------------------------------------|\n");
                    printf("\t\t\t\t\t\t| \t\t\tBooking ID : BOID%d\n\t\t\t\t\t\t|\n",ticket_id+1+i);
                    printf("\t\t\t\t\t\t| Name       : %s\n",list[i].name);
                    printf("\t\t\t\t\t\t| Passport NO: %s\n",list[i].passport);
                    printf("\t\t\t\t\t\t| Flight NO  : FL60%d\n",fl+50);
                    printf("\t\t\t\t\t\t| Flight Time: %s\n",ftime);
                    printf("\t\t\t\t\t\t| Airline    : %s\n",airline);
                    printf("\t\t\t\t\t\t| Gate No    : %d\n",many+3);
                    printf("\t\t\t\t\t\t| Seats NO   : A%d\n",i+10);
                    printf("\t\t\t\t\t\t| Paid       : %s\n",user.amount);
                    printf("\t\t\t\t\t\t|-------------------------------------------------------|\n");
                    printf("\t\t\t\t\t\t|            Thank You For Using Our Service            |\n");
                    printf("\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
                }
                ///Printing Ticket Id In Ticket Counter File
                //For using the next ticket number
                ticket_counter=fopen("ticketcounter.txt", "w");
                fprintf(ticket_counter,"%d\n",ticket_id+many);
                fclose(ticket_counter);

                printf("\n---------------\t\t------------\t\t------------");
                printf("\n| 1 > Booking |\t\t| # > Home |\t\t| 0 > Exitt|");
                printf("\n---------------\t\t------------\t\t------------\n\n");

                choice=getche();

                if(choice=='1')
                    flight();
                else if(choice=='#')
                    main();
                else if(choice=='0')
                    quit();
            }
        }
    }
}
}
//For Cancelling Ticket
void cancellation()
{
    while(1)
    {
    system("cls");
    header();
    printf("\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t\t\t\t\t~ Ticket Cancel ~\n");
    printf("\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~\n\n");

    struct user
    {
        char bookid[20];
        char name[20];
        char passport[20];
        char email[30];
    };

    struct user ca;

    ///Searching Booking ID From Passengers Records File
    printf("Search Your Booking ID First:");
    scanf("%s",&ca.bookid);

    char ID[200],str[20];
    int j,count=0;

    FILE *search_id;
    search_id=fopen("plist.txt", "r");

    if(search_id==NULL)
    {
        printf("Error! File Missing!");
        exit(1);
    }
    else
    {
        while((fscanf(search_id,"%s",&ID))!=EOF)
            if(strcmp(ca.bookid,ID)==0)
                count++;
        fclose(search_id);
    }
    if(count==1)
    {
        printf("\nEnter Your Name: ");
        fflush(stdin);
        gets(ca.name);
        printf("\nEnter Passport Number: ");
        gets(ca.passport);
        printf("\nEnter Your Email: ");
        gets(ca.email);


        ///Checking Valid Email
        int i,x=0,y=0,c=0;
        for(i=0;ca.email[i]!='\0';i++)
        {
            if(ca.email[i]==' ' )
            y++;
            else if(ca.email[i]=='@')
            c++;
            else if(ca.email[i]=='.')
            x++;
        }
        FILE *cancel;
        cancel=fopen("cancelation.txt", "a" );

        if(c==1 && y==0 && x>0)
        {
            fprintf(cancel,"%s\n",ca.bookid);
            fprintf(cancel,"----------\n");
            fprintf(cancel,"%s\n",ca.name);
            fprintf(cancel,"%s\n",ca.passport);
            fprintf(cancel,"%s\n\n",ca.email);
            fclose(cancel);
            printf("\n\t\t\t\t\t\t\tWe recived your cancellation request, we will check it immediatly.\n\n\t\t\t\t\t\t\t\tWe will confirm you in your email after cancellation.\n");
    }
        else
        {
            printf("Invalid Email! Please Enter a valid email!");
        }
    }
    else
    {
        printf("Sorry We Couldnot Find Your Booking");
    }

    printf("\n------------\t\t------------");
    printf("\n| # > Back |\t\t| 0 > Exit |");
    printf("\n------------\t\t------------\n");
    choice=getche();

    if(choice=='#')
        main();

    else if(choice=='0')
        quit();
    }
}
//Passengers Records
void precords()
{
    while(1)
    {
    system("cls");
    header();
    printf("\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t\t\t\t\t~ Passengers Records ~\n");
    printf("\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~\n\n");

    ///Reading Data From Passengers Records File
    char c;
    FILE *precords;
    precords=fopen("precords.txt", "r");
    if(precords==NULL)
    {
        printf("Error");
        exit(1);
    }
    else
    {
        while ((c = fgetc(precords)) != EOF)
            putchar(c);
        fclose(precords);
    }
    printf("\n------------\t\t------------");
    printf("\n| # > Menu |\t\t| 0 > Exit |");
    printf("\n------------\t\t------------\n");

    choice=getche();
    if(choice=='#')
        home();
    else if(choice=='0')
        quit();
    }

}
//Passengers List
void plist()
{
    while(1)
    {
    system("cls");
    header();
    printf("\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t\t\t\t\t~ List Of Passengers ~\n");
    printf("\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~\n\n");
    ///Reading Data From Passengers List
    char name;

    FILE *plist;
    plist=fopen("plist.txt", "r");
    if(plist==NULL)
    {
        printf("Error");
        exit(1);
    }
    else
    {
        while ((name = fgetc(plist)) != EOF)
            putchar(name);
        fclose(plist);
    }
int d;
    printf("\n------------\t\t------------");
    printf("\n| # > Menu |\t\t| 0 > Exit |");
    printf("\n------------\t\t------------\n");

    choice=getche();
    if(choice=='#')
        home();
    else if(choice=='0')
        quit();
    }
}

//Login Option For Admin
void login()
{
    while(1)
    {
    system("cls");
    header();

    printf("\n\t\t\t\t\t\t\t\t\tYOU MUST LOG IN FIRST\n");
    printf("\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~\n");

    char name[20];
    int pass1,pass;
    printf("Enter Username:");
    fflush(stdin);
    gets(name);
    printf("\nEnter Password:");
    scanf("%d",&pass1);

    //Initializing Name For Showing User
    int c;
    FILE *user;
    user=fopen("user.txt","w");
    fprintf(user,"%s                 \n",name);
    fclose(user);

    FILE *password1;
    password1=fopen("password.txt", "r");
    if(password1==NULL)
    {
        printf("Error! File Missing!");
        exit(1);
    }
    else
        fscanf(password1,"%d",&pass);
        fclose(password1);

    if(pass1==pass)
    {
        home();
    }
    else if(pass1!=pass)
        printf("\nWrong Password.\n\n");
    }
}
///For Changing Username & Password
void password()
{
    system("cls");
    header();

    char name2[10];
    int pass;

    printf("\t\t\t\t\t\t\t\tSecurity System\n");
    printf("\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~\n");

    //Getting Input For Usernamre
    FILE *username;
    username=fopen("username.txt", "w");
    if(username==NULL)
    {
        printf("Error");
        exit(1);
    }
    else
        printf("Enter New Username:");
        fflush(stdin);
        gets(name2);
        fputs(name2,username);
        printf("\nSuccesfull\n\n");
        fclose(username);
    //Getting Input For New Password
    FILE *password1;
    password1=fopen("password.txt", "w");
    if(password1==NULL)
    {
        printf("Error");
        exit(1);
    }
    else
        printf("Enter New Password:");
        fflush(stdin);
        scanf("%d",&pass);
        fprintf(password1,"%d",pass);
        printf("\nSuccesfull\n\n");
        fclose(password1);

    printf("------------\t\t-----------\n");
    printf("| # > Menu |\t\t| 0 > Exit|\n");
    printf("------------\t\t-----------\n");

    choice=getche();
    if(choice=='#')
        home();
    else if(choice=='0')
        quit();
    else
        home();
}
void adminmode()
{
    while(1)
    {
    system("cls");
    header();

    printf("\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t\t\t\t\t~ Admin Mode ~\n");
    printf("\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~\n\n");

    printf("1 > Change Schedule\n");
    printf("2 > Change User Name & Password\n");
    printf("3 > Delete All Records\n");
    printf("4 > Delete All List\n\n");
    printf("------------\t\t------------\n");
    printf("| # > Home |\t\t| 0 > Exit |\n");
    printf("------------\t\t------------\n");

    choice=getche();

    if(choice=='1')
    {
        schedule();
    }
    else if(choice=='2')
    {
        password();
    }
    else if(choice=='3')
    {
        FILE *del_rec;
        del_rec=fopen("precords.txt","w");
        fclose(del_rec);
        printf("\nSuccesfully Deleted\n");

    }
    else if(choice=='4')
    {
        FILE *del_list;
        del_list=fopen("plist.txt","w");
        fclose(del_list);
        printf("\nSuccesfully Deleted\n");
    }
    else if(choice=='#')
    {
        home();
    }
    else if(choice=='0')
    {
        quit();
    }

    printf("\n------------\t\t------------\n");
    printf("| # > Home |\t\t| 0 > Exit |\n");
    printf("------------\t\t------------\n");

    choice=getche();
    if(choice=='#')
        home();
    else if(choice=='0')
        quit();
    }
}
void forgotpassword()
{
    while(1)
    {
    system("cls");
    header();
    char name[20];
    char name1[20];
    int pass;
    FILE *password1;
        password1=fopen("password.txt", "r");
        fscanf(password1,"%d",&pass);
        fclose(password1);

    printf("Enter Your Username For Recover Your Password: ");
    fflush(stdin);
    gets(name1);


    FILE *username;
    username=fopen("username.txt", "r");
        fgets(name,20,username);
        fclose(username);

    int s=strcmp(name,name1);
    if(s==0)
    {
        printf("\nYour password is: %d\n",pass);
    }
    else
    {
        printf("Wrong Username\n");
    }

    printf("------------\t------------\n");
    printf("| # > Back |\t| 0 > Exit |\n");
    printf("------------\t------------\n");

    choice=getche();
    if(choice=='#')
        main();
    else if(choice=='0')
            quit();
    }
}
void cancel_req()
{
    while(1)
    {
    system("cls");
    header();
    printf("\t\t\t\t\t\t\t\t\t----------------------\n");
    printf("\t\t\t\t\t\t\t\t\tCancellation Request\n");
    printf("\t\t\t\t\t\t\t\t\t----------------------\n");
    char c;
    FILE *cancel_req;
    cancel_req=fopen("cancelation.txt", "r");

    if(cancel_req==NULL)
    {
        printf("Error! File Missing!");
        exit(1);
    }
    else
    {
        while((c=fgetc(cancel_req))!=EOF)
            putchar(c);
        fclose(cancel_req);
    }
    fclose(cancel_req);

    char a,str[200000],name[10];
    int i=0;
    FILE *check;
    check=fopen("d:\\project\\plist.txt", "r");

    while((a=fgetc(check))!=EOF)
    {
        str[i]=a;
        i++;
    }
    str[i]='\0';
    fclose(check);

    printf("----------------------------\n");
    printf("Enter Booking Id For Cancel: \n");
    printf("----------------------------\n");
    fflush(stdin);
    gets(name);

    int len=strlen(name);
    for(len;len<9;len++)
    {
        name[len]=' ';
    }
    name[len]='\0';
    int x=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==name[0] && str[i+1]==name[1] && str[i+2]==name[2] && str[i+3]==name[3] && str[i+4]==name[4] && str[i+5]==name[5] && str[i+6]==name[6] && str[i+7]==name[7] && str[i+8]==name[8])
        {
            str[i]='C';
            str[i+1]='a';
            str[i+2]='n';
            str[i+3]='c';
            str[i+4]='e';
            str[i+5]='l';
            str[i+6]='l';
            str[i+7]='e';
            str[i+8]='d';
            x++;
        }
    }
    FILE *cancel;
    cancel=fopen("plist.txt", "w");
    fprintf(cancel,"%s",str);
    fclose(cancel);
    if(x==0)
        printf("Enter Valid Booking ID & Try Again!");
    else
        printf("Succesfully Cancelled");

    printf("\n------------\t-------------------------\t------------");
    printf("\n| # > Menu |\t| 1 > Clear All Request |\t| 0 > Exit |");
    printf("\n------------\t-------------------------\t------------\n");

    choice=getche();
    if(choice=='#')
        home();
    else if(choice=='1')
    {
        FILE *clear;
        clear=fopen("cancelation.txt", "w");
        fclose(clear);
        printf("Succesfull");
    }
    else if(choice=='0')
        quit();
    }

}
void schedule()
{
    struct add
    {
        int class[3];
        char flight[10],from[10],to[15],air[20],time[10];
    };
    while(1)
    {
    system("cls");
    header();
    printf("\t\t\t\t\t\t\t\t\t-------------------\n");
    printf("\t\t\t\t\t\t\t\t\t- Change Schedule -\n");
    printf("\t\t\t\t\t\t\t\t\t-------------------\n\n");
    FILE *flight;
    flight=fopen("d:\\project\\flight.txt", "r");
    char c;
    while((c=fgetc(flight))!=EOF)
        putchar(c);
    fclose(flight);

    printf("1: Change Specific Line\n");
    printf("2: Edit File\n\n");
    printf("------------\t------------\n");
    printf("| # > Back |\t| 0 > Exit |\n");
    printf("------------\t------------\n");

    choice=getche();
    if(choice=='1')
    {
            char str[20000],c;
    int i=0,line=0,sn,size=0,index=0;
    struct add n;

    FILE *cpy;
    cpy=fopen("flight1.txt", "r");
    while((c=fgetc(cpy)) != EOF)
    {
        str[i]=c;
        i++;
    }
    str[i]='\0';
    fclose(cpy);
    printf("Enter SNO Number:");
    scanf("%d",&sn);
    sn=sn-1;

    for(i=0;str[i]!='\0';i++)
    {
       if(str[i]=='\n')
       {
            line++;
            if(line==sn)
            {
                index=i;
            }
       }
    }
    for(i=index+1;str[i]!='\n';i++)
    {
        size++;
    }
    printf("Enter Flight NO:");
    fflush(stdin);
    gets(n.flight);
    printf("Enter From:");
    gets(n.from);
    printf("Enter To:");
    gets(n.to);
    printf("Enter E Class:");
    scanf("%d",&n.class[0]);
    printf("Enter B Class:");
    scanf("%d",&n.class[1]);
    printf("Enter F Class:");
    scanf("%d",&n.class[2]);
    printf("Enter Time:");
    fflush(stdin);
    gets(n.time);
    printf("Enter Airline:");
    gets(n.air);
    FILE *print;
    print=fopen("flight1.txt", "w");
    fprintf(print,"%d\t%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%s\n",sn+1,n.flight,n.from,n.to,n.class[0],n.class[1],n.class[2],n.time,n.air);
    fclose(print);
    char str1[300],d;
    FILE *cpy1;
    i=0;
    cpy1=fopen("flight1.txt", "r");
    while((d=fgetc(cpy1)) != EOF)
    {
        str1[i]=d;
        i++;
    }
    str1[i]='\0';
    fclose(cpy1);
    int j=0;
    for(i=index+1;str1[j]!='\0';i++)
    {
        str[i]=str1[j];
        j++;
    }
    FILE *print1;
    print1=fopen("flight1.txt","w");
    fprintf(print1,"%s",str);
    fclose(print1);

    }
    else if(choice=='2')
    {
        system("flight.txt");
    }
    else if(choice=='#')
    {
        main();
    }
    else if(choice=='0')
    {
        quit();
    }

    }
}
void quit()
{
    FILE *user;
    user=fopen("user.txt","w");
    fprintf(user,"Unknown");
    fclose(user);
    exit(0);
}
