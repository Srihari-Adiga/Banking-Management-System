#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
//#include "declaration.h"
void fordelay(double);
int i, j;
void menu(int code);
int home();
void close();
void login();
void edit(int);     //1
void withdraw(int); //4
void deposit(int);  //2
void delete (int);  //6
void transfer(int); //5
void see(int);      //3

struct account
{

    char name[60];
    int age, pin;
    char address[60];
    char citizenship[15];
    double phone, acc_no;
    char acc_type[10];
    float amt;
} add, upd, check, rem, transaction, change;

int countDigit(double n)
{
    if (n == 0)
        return 1;
    int count = 0;
    long long num=n;
    while (num != 0) {
        num = num/10;
        ++count;
    }
    return count;
}

void rewrite() //Program to copy details of file with altered data to original file
{
    FILE *old = fopen("details.txt", "w");
    FILE *new = fopen("new.txt", "r");
    while (fscanf(new, "%d %lf %s %d %lf %s %s %f", &change.pin, &change.acc_no, change.name, &change.age, &change.phone, change.citizenship, change.acc_type, &change.amt) != EOF)
    {
        fprintf(old, "\n%d %.0lf %s %d %.0lf %s %s %.2f\n", change.pin, change.acc_no, change.name, change.age, change.phone, change.citizenship, change.acc_type, change.amt);
    }
    fclose(old);
    fclose(new);
}

void edit(int code) //Program to edit the Phone Number
{
    FILE *old = fopen("details.txt", "r");
    FILE *new = fopen("new.txt", "w");
    system("cls");
    int choice = 0;
    double phno, actno;
    printf("Enter   1 - To change Phone Number\n");
    scanf("%d", &choice);
    printf("\nEnter new Phone Number - \n");
    scanf("%lf", &phno);
    int flag = 0;
    //int code=0;
    if (choice == 1)
    {
        while (fscanf(old, "%d %lf %s %d %lf %s %s %f", &upd.pin, &upd.acc_no, upd.name, &upd.age, &upd.phone, upd.citizenship, upd.acc_type, &upd.amt) != EOF)
        {
            if (upd.pin == code)
            {
                upd.phone = phno;
                flag = 1;
                //code = upd.pin;
            }

            fprintf(new, "\n%d %.0lf %s %d %.0lf %s %s %.2f\n", upd.pin, upd.acc_no, upd.name, upd.age, upd.phone, upd.citizenship, upd.acc_type, upd.amt);
        }
        if (flag == 1)
        {
            printf("Phone number updated successfully\n");
            for (int i = 0; i <= 7; i++)
            {
                fordelay(100000000);
                printf(".");
            }
            fclose(old);
            fclose(new);
            rewrite();
            system("cls");
            menu(code);
        }
        else if (flag = 0)
        {
            printf("There was a error in the entered account number - Retry");
            for (int i = 0; i <= 7; i++)
            {
                fordelay(100000000);
                printf(".");
            }
            fclose(old);
            fclose(new);
            rewrite();
            system("cls");
            menu(code);
        }
    }
    else
    {
        printf("Invalid Choice - Retry");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        fclose(old);
        fclose(new);
        system("cls");
        menu(code);
    }
}

void deposit(int code) // Function to deposit money into the account
{
    FILE *old = fopen("details.txt", "r");
    FILE *new = fopen("new.txt", "w");
    system("cls");
    float depamt = 0;
    int flag = 0;
    printf("Enter the Amount to be Deposited in your account - ");
    scanf("%f", &depamt);
    while (fscanf(old, "%d %lf %s %d %lf %s %s %f", &upd.pin, &upd.acc_no, upd.name, &upd.age, &upd.phone, upd.citizenship, upd.acc_type, &upd.amt) != EOF)
    {
        if (upd.pin == code)
        {
            upd.amt = upd.amt + depamt;
            flag = 1;
        }
        fprintf(new, "\n%d %.0lf %s %d %.0lf %s %s %.2f\n", upd.pin, upd.acc_no, upd.name, upd.age, upd.phone, upd.citizenship, upd.acc_type, upd.amt);
    }
    if (flag == 1)
    {
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("Tansaction Successful");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        fclose(old);
        fclose(new);
        rewrite();
        system("cls");
        menu(code);
    }
    else if (flag == 0)
    {
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("Tansaction Unsuccessful - Retry");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        fclose(old);
        fclose(new);
        system("cls");
        menu(code);
    }
}

void see(int code) //Fuction to dispaly account details
{
    FILE *old = fopen("details.txt", "r");
    system("cls");
    while (fscanf(old, "%d %lf %s %d %lf %s %s %f", &check.pin, &check.acc_no, check.name, &check.age, &check.phone, check.citizenship, check.acc_type, &check.amt) != EOF)
    {
        if (check.pin == code)
        {
            printf("Name: %s\n", check.name);
            printf("Age: %d\n", check.age);
            printf("Phone: %.0lf\n", check.phone);
            printf("Account Type: %s\n", check.acc_type);
            printf("Nationality: %s\n", check.citizenship);
            printf("Balance: %.2f\n", check.amt);
            break;
        }
    }
    fflush(stdin);
    char choice;
heres:
    printf("\nSelect to go to the main menu (Y) or exit the program (N): ");
    scanf("%c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        system("cls");
        menu(code);
    }
    else if (choice == 'N' || choice == 'n')
    {
        system("cls");
        close();
    }
    else if ((choice != 'N' || choice != 'n') && (choice != 'Y' || choice != 'y'))
    {
        printf("\nInvalid Selection - Choose again");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        goto heres;
    }
    fclose(old);
}

void withdraw(int code) //Function to withdraw from account
{
    FILE *old = fopen("details.txt", "r");
    FILE *new = fopen("new.txt", "w");
    system("cls");
    float witamt = 0;
    int flag = 0;
    printf("Enter the Amount to be Withdrawn from your account - ");
    scanf("%f", &witamt);
    while (fscanf(old, "%d %lf %s %d %lf %s %s %f", &upd.pin, &upd.acc_no, upd.name, &upd.age, &upd.phone, upd.citizenship, upd.acc_type, &upd.amt) != EOF)
    {
        if (upd.pin == code)
        {
            upd.amt = upd.amt - witamt;
            flag = 1;
        }
        fprintf(new, "\n%d %.0lf %s %d %.0lf %s %s %.2f\n", upd.pin, upd.acc_no, upd.name, upd.age, upd.phone, upd.citizenship, upd.acc_type, upd.amt);
    }
    if (flag == 1)
    {
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("Tansaction Successful");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        fclose(old);
        fclose(new);
        rewrite();
        system("cls");
        menu(code);
    }
    else if (flag == 0)
    {
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("Tansaction Unsuccessful - Retry");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        fclose(old);
        fclose(new);
        system("cls");
        menu(code);
    }
}

void transfer(int code) // Function to send money to another account
{
    FILE *old = fopen("details.txt", "r");
    FILE *new = fopen("new.txt", "w");
    double toacctno;
    float tamt = 0;
    system("cls");
    int flag = 0;
    printf("Enter the amount to be Transfered - ");
    scanf("%f", &tamt);
    printf("\nEnter the account number to be transferred money to - ");
    scanf("%lf", &toacctno);
    while (fscanf(old, "%d %lf %s %d %lf %s %s %f", &transaction.pin, &transaction.acc_no, transaction.name, &transaction.age, &transaction.phone, transaction.citizenship, transaction.acc_type, &transaction.amt) != EOF)
    {
        if (transaction.pin == code)
        {
            transaction.amt = transaction.amt - tamt;
            flag = 1;
        }
        if (transaction.acc_no == toacctno)
        {
            transaction.amt = transaction.amt + tamt;
            flag = 1;
        }

        fprintf(new, "\n%d %.0lf %s %d %.0lf %s %s %.2f\n", transaction.pin, transaction.acc_no, transaction.name, transaction.age, transaction.phone, transaction.citizenship, transaction.acc_type, transaction.amt);
    }
    if (flag == 1)
    {
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("Tansaction Successful");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        fclose(old);
        fclose(new);
        rewrite();
        system("cls");
        menu(code);
    }
    else if (flag == 0)
    {
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("Tansaction Unsuccessful - Retry");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        fclose(old);
        fclose(new);
        system("cls");
        menu(code);
    }
}

void delete (int code) // Function to delete your account
{
    FILE *old = fopen("details.txt", "r");
    FILE *new = fopen("new.txt", "w");
    system("cls");
    int flag = 0;
    while (fscanf(old, "%d %lf %s %d %lf %s %s %f", &rem.pin, &rem.acc_no, rem.name, &rem.age, &rem.phone, rem.citizenship, rem.acc_type, &rem.amt) != EOF)
    {
        if (rem.pin == code)
        {
            flag = 1;
            continue;
        }
        else if (rem.pin != code)
        {
            fprintf(new, "\n%d %.0lf %s %d %.0lf %s %s %.2f\n", rem.pin, rem.acc_no, rem.name, rem.age, rem.phone, rem.citizenship, rem.acc_type, rem.amt);
        }
    }
    if (flag == 1)
    {
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("Acount Deletion Successful");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        fclose(old);
        fclose(new);
        rewrite();
        system("cls");
        home();
    }
    else if (flag == 0)
    {
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        printf("Account Deletion Unsuccessful - Retry");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        menu(code);
    }
}

void fordelay(double l) //Function to delay 
{
    double n;
    for (i = 0; i < l; i++)
        n = i;
}

double generate() //Function to generate a random account number
{
    double n = 6200;
    srand(time(NULL));
    for (int i = 0; i <= 7; i++)
    {
        n = n * 10;
        n = n + rand() % 10;
    }
    return n;
}

void display_and_menu(int code) //Function to display basic details after logging into account
{
    FILE *info;
    info = fopen("details.txt", "r");
    int test = 0;
    printf("\nACC.NO\t\tNAME\t\t\tPHONE No.\t\tCITIZENSHIP\t      ACCOUNT TYPE\n");
    while (fscanf(info, "%d %lf %s %d %lf %s %s %f", &add.pin, &add.acc_no, add.name, &add.age, &add.phone, add.citizenship, add.acc_type, &add.amt) != EOF)
    {
        if (add.pin == code)
        {
            printf("\n%.0lf\t%s\t            %.0lf\t\t      %s \t            %s\n", add.acc_no, add.name, add.phone, add.citizenship, add.acc_type);
            menu(code);
            break;
            test++;
        }
    }

    fclose(info);
}

void check_display(int code, double accno) //Function to check the PIN and Account Number
{
    FILE *key;
    key = fopen("details.txt", "r");
    int flag = 0;
    //system("cls");
    while (fscanf(key, "%d %lf %s %d %lf %s %s %f", &add.pin, &add.acc_no, add.name, &add.age, &add.phone, add.citizenship, add.acc_type, &add.amt) != EOF)
    {
        if (add.pin == code && add.acc_no == accno)
        {
            flag = 1;
            printf("\nPin Matched!!LOADING\n");
            for (int i = 0; i <= 7; i++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            display_and_menu(code);
        }
    }

    if (flag == 0)
    {
        printf("\n**INAVLID PIN/ACCOUNT NUMBER**\n\n");
        //login();
        int choice;
        printf("Enter: 1 - To Retry\t2 - Go to Previous Page : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: login(); break;
            case 2: home(); break;
            default: home(); break;
        }
    }

    fclose(key);
}

void create() //Function to create a new account
{
    int option;
    char password[10], ch;
    FILE *p;
    printf("\n*****////CREATING NEW ACCOUNT//////*****\n");
    p = fopen("details.txt", "a+");
new_account:
    printf("\nSet 4 digit PIN Number : ");
    for (int i = 0; i < 4; i++)
    {
        ch = getch();
        password[i] = ch;
        ch = '*';
        printf("%c", ch);
    }
    check.pin = atoi(password);

    while (fscanf(p, "%d %lf %s %d %lf %s %s %f", &add.pin, &add.acc_no, add.name, &add.age, &add.phone, add.citizenship, add.acc_type, &add.amt) != EOF)
    {
        if (check.pin == add.pin || check.acc_no == add.acc_no)
        {
            printf("\nAccount already exists!!!\n");
            fordelay(10000000);
            goto new_account;
        }
    }
    add.pin = check.pin;
    add.acc_no = generate();
    printf("\n\nNAME : ");
    scanf("%s", add.name);
    printf("\nAGE : ");
    scanf("%d", &add.age);
    printf("\nPHONE NO : ");
    scanf("%lf", &add.phone);
    printf("\nNATIONALITY : ");
    scanf("%s", add.citizenship);
    printf("\nACCOUNT TYPE : ");
    scanf("%s", add.acc_type);
    printf("\nINITIAL DEPOSIT AMOUNT :Rs. ");
    scanf("%f", &add.amt);
    fflush(p);
    int no_of_digits = countDigit(add.phone);
    if(no_of_digits==10)
    {
        fprintf(p, "\n%d %.0lf %s %d %.0lf %s %s %.2f\n", add.pin, add.acc_no, add.name, add.age, add.phone, add.citizenship, add.acc_type, add.amt);
        fclose(p);
        printf("\nYour account number is : %.0lf\n", add.acc_no);
        printf("\n\n\t\t\tAccount Created Successfully!!!!\n");
    }
    else
    {
        printf("\n\n\t\tAccount cannot be created.\n\n");
        printf("\t\tPhone Number must be equal to 10 digits!!\n");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }

    }
    
leave_page:
    printf("\n\tPress 1 to go to the home page and press 2 to exit\n");
    scanf("%d", &option);
    if (option == 1)
    {
        system("cls");
        home();
    }
    else if (option == 2)
    {
        system("cls");
        close();
    }
    else
    {
        printf("\nInvalid Choice\a");
        goto leave_page;
    }
}

int home() // HOMEPAGE
{
    int choice;
    system("cls");
    printf("\t\t\t******//Welcome to the OVERSEAS BANK OF INDIA//*****\n\n");
    printf("1.Login\n2.Create a new account\n3.Exit\n\n");
enter:
    printf("Enter your choice\n\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        login();
        break;
    case 2:
        system("cls");
        create();
        break;
    case 3:
        system("cls");
        close();
        break;

    default:
        printf("Invalid choice\n");
        goto enter;
        break;
    }
}

int main()
{
    int choice;
    printf("\n\t\t\t******//VIRTUAL BANKING SYSTEM //*****\n");
    printf("\n\n1.Press 1 to enter home page\n");
    printf("\n2.Press 2 to leave page\n\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        home();
        break;
    case 2:
        system("cls");
        close();
        break;
    default:
        printf("\nInvalid Choice\n");
        break;
    }

    return 0;
}

void login() //Function to Login to existing account
{
    system("cls");
    printf("\t\t\t*****LOGIN PAGE******\n\n");
    int pin;
    char password[10], ch;
    double accno;
    printf("Enter the pin number : ");
    for (int i = 0; i < 4; i++)
    {
        ch = getch();
        password[i] = ch;
        ch = '*';
        printf("%c", ch);
    }
    pin = atoi(password);
    printf("\n\nEnter Account number : ");
    scanf("%lf", &accno);

    check_display(pin, accno);
}

void menu(int code) //Function accept the choice of the user from a given menu
{
    int option;
here:
    printf("\n**************************************\n");
    printf("/////***MAIN MENU***/////\n\n");
    printf("1.Edit Account Details\n");
    printf("2.Deposit Amount\n");
    printf("3.View full account details\n");
    printf("4.Withdraw Amount\n");
    printf("5.Transfer amount\n");
    printf("6.Delete account\n");
    printf("7.Go to home page\n");
    printf("8.Exit\n\n");
    printf("Enter the Sl.No to choose the corresponding option\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        edit(code);
        break;
    case 2:
        deposit(code);
        break;
    case 3:
        see(code);
        break;
    case 4:
        withdraw(code);
        break;
    case 5:
        transfer(code);
        break;
    case 6:
        delete (code);
        break;
    case 7:
        system("cls");
        home();
        break;
    case 8:
        system("cls");
        close();
        break;
    default:
        printf("Invalid option\n");
        for (int i = 0; i <= 7; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        goto here;
    }
}

void close() //Function to Close the program
{
    for (int i = 0; i <= 7; i++)
    {
        fordelay(100000000);
        printf(".");
    }
    printf("\n\n\t\t\tThank you!! Visit Again\n");
}