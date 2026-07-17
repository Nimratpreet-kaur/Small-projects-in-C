#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
    char name[30];
    char address[50];
    char father_name[30];
    char mother_name[30];
    long int mobile_no;
    char sex[10];
    char e_mail[50];
} per;
per p[100];
int count = 0;
void cleanBuffer();
void addName();
void list();
void printPerson(int i);
void modify();
void search();
void del();
int main()
{
    printf("\t***Welcome to Phone book***\n");
    printf("\t\tMENU\n");
    int to_do;

    while (1)
    {
        printf("1.Add Name\t2.List    \t3.Modify \n4.Exit    \t5.Search  \t6.Delete\n");
        printf("Enter Your Choice:\n");
        if(scanf("%d",&to_do) !=1)
        {
            cleanBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        cleanBuffer();

        if (to_do == 1)
        {
            addName();
        }
        else if (to_do == 2)
        {
            list();
        }
        else if (to_do == 3)
        {
            modify();
        }
        else if (to_do == 4)
        {
            break;
        }
        else if (to_do == 5)
        {
            search();
        }
        else if (to_do == 6)
        {
            del();
        }
        else 
        {
            printf("Invalid Choice!Try again");
        }
    }
}
void cleanBuffer()
{
    int c;
    while((c = getchar()) != '\n' && c !=EOF);
}

//*to remove new line added by using fgets and scanf both 
void removeNewline(char *str) 
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') 
    {
        str[len - 1] = '\0';
    }
}

void addName()
{
    if (count>100)
    {
        printf("No more space");
        return;
    }
    printf("Name:");
    fgets(p[count].name,30,stdin);
    cleanBuffer();
    printf("Adress:");
    fgets(p[count].address,50,stdin);
    cleanBuffer();
    printf("Father's Name:");
    fgets(p[count].father_name,30,stdin);
    cleanBuffer();
    printf("Mother's Name:");
    fgets(p[count].mother_name,30,stdin);
    cleanBuffer();
    printf("Mobile Number:");
    scanf("%ld", &p[count].mobile_no);
    cleanBuffer();
    printf("Sex:");
    fgets(p[count].sex,10,stdin);
    cleanBuffer();
    printf("E-mail:");
    fgets(p[count].e_mail,50,stdin);
    cleanBuffer();
    count++;
}
void list()
{
    printf("\t***LIST***\n");
    for (int i = 0; i < count; i++)
    {
        printf("Name:%s\n", p[i].name);
        printf("Address:%s\n", p[i].address);
        printf("Father's Name:%s\n", p[i].father_name);
        printf("Mother's Name:%s\n", p[i].mother_name);
        printf("Mobile number:%ld\n", p[i].mobile_no);
        printf("Sex:%s\n", p[i].sex);
        printf("E-mail:%s\n", p[i].e_mail);
        printf("\n");
    }
}
void printPerson(int i)
{
    printf("Name:%s\n", p[i].name);
    printf("Address:%s\n", p[i].address);
    printf("Father's Name:%s\n", p[i].father_name);
    printf("Mother's Name:%s\n", p[i].mother_name);
    printf("Mobile number:%ld\n", p[i].mobile_no);
    printf("Sex:%s\n", p[i].sex);
    printf("E-mail:%s\n", p[i].e_mail);
    printf("\n");
}
void modify()
{
    printf("Enter mobile nummber of person you wish to modify:");
    long int modify_number;
    scanf("%ld", &modify_number);
    cleanBuffer();
    int n = 0;
    for (int i = 0; i < count; i++)
    {
        if (modify_number != p[i].mobile_no)
        {
            n++;
        }
        else if (modify_number == p[i].mobile_no)
        {
            printf("\t***Existing information***\n");
            printPerson(n);
            printf("Enter new Information\n");
            printf("Name:");
            fgets(p[i].name,30,stdin);
            cleanBuffer();
            printf("Address:");
            fgets(p[i].address,50,stdin);
            cleanBuffer();
            printf("Father's Name:");
            fgets(p[i].father_name,30,stdin);
            cleanBuffer();
            printf("Mother's Name:");
            fgets(p[i].mother_name,30,stdin);
            cleanBuffer();
            printf("Mobile number:");
            scanf("%ld",&p[i].mobile_no);
            cleanBuffer();//to clean new line
            printf("Sex:");
            fgets(p[count].sex,10,stdin);
            cleanBuffer();
            printf("E-mail:");
            fgets(p[count].e_mail,50,stdin);
            cleanBuffer();
            printf("\n");
            break;
        }
    }
}

void search()
{
    char search_name[30];
    printf("Enter Name to search:");
    fgets(search_name,30,stdin);
    cleanBuffer();
    int len =strlen(search_name);
    int count = 0;
    for(int i=0;i<len;i++)
    {
        if(search_name == p[i].name){
            printf("\tDetails of %s\n",search_name);
            count++;
            printPerson(i);
        }
    }
    if(count==0)
    {
        printf("No Person named %s found\n",search_name);
    }
    if (count>1)
    {
        printf("\t ***%d people named %s found***\n",count,search_name);
    }
}

void del()
{
    long int search_no;
    printf("Enter Phone Number :\n");
    scanf("%ld",&search_no);
    cleanBuffer();
    int found = -1;
    for (int i = 0;i< count;i++)
    {
        if (search_no == p[i].mobile_no)
        {
            found =i;
        }
    }
    if(found==-1)
    {
        printf("Phone Number %ld not found!",search_no);
    }
    else
    {
        for(int i= found;i<count -1;i++)
        {
            p[i]=p[i+1];
        }
        count--;
    }
    printf("\t***Information Deleted seccessfully***\n");
}