#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

//this was a project I wrote for my C programming class in 2023

char stu_name[99], stu_LRN[99], stu_section[99], stu_schoolname[99], stu_schoolyear[99], stu_gender[99], stu_age[99], stu_principal[99], stu_level[99], stu_schooldays[99], stu_present[99], stu_absent[99];
char subjects[8][99] = {"Fili", "Scie", "Engl", "Math", "ArPa", "GMRC", "MAPH", "HELE"};
char remarks[99];
int stu_grade[5][99];

char filename[999];

char input[99];

int choice;

int quarteravg[5];
int totquarter[5];

int totaladd;
int totalavg;


void setup();
void getgrades();
void calculate();
void display();
void remark();
void writetofile();
void deletefile();
void readfile();
void listfile();

char username[] = "teacher23";
char password[] = "1234";
char log_u[99], log_p[99];


int main()
{
    printf("-----STUDENT GRADE VIEWER AND EDITOR----- \n");
    login:
    printf("Please Enter Username: ");
    scanf("%s", log_u);
    printf("\nPlease Enter Password: ");
    scanf("%s", log_p);

    if(strcmp(log_u, username) != 0 || strcmp(log_p, password) != 0)
    {
        printf("Incorrect username or password, please try again \n \n");
        goto login;
    }
    else
    {
        menu:
            system("clear");
            postlist:

        printf("-----Student Grading System----- \n");
        printf("1> Begin Logging Grades \n");
        printf("2> Delete a File\n");
        printf("3> Open a File\n");
        printf("4> List All Files in Directory \n");
        printf("5> Exit the Program \n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            setup();
            goto menu;
            break;
        case 2:
            deletefile();
            goto menu;
            break;
        case 3:
            readfile();
            goto menu;
            break;
        case 4:
            listfile();

            goto postlist;
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Defaulting to Registering...\n");
            setup();
            goto menu;
           break;
        }
    }
}

void setup()
{
    printf("Please Enter Student Name: ");
    scanf("%s",stu_name);
    printf("\n Please Enter Student LRN: ");
    scanf("%s", stu_LRN);
    printf("\n Please Enter Student Section(Number Only): ");
    scanf("%s",stu_section);
    printf("\n Please Enter Student School Name: ");
    scanf("%s",stu_schoolname);
    printf("\n Please Enter School-Year: ");
    scanf("%s",stu_schoolyear);
    printf("\n Please Enter Student Gender: ");
    scanf("%s",stu_gender);
    printf("\n Please Enter Student Age: ");
    scanf("%s",stu_age);
    printf("\n Please Enter Student Principal: ");
    scanf("%s",stu_principal);
    printf("\n Please Enter Student level: ");
    scanf("%s",stu_level);
    printf("\n Please Enter Schooldays: ");
    scanf("%s",stu_schooldays);
    printf("\n Please Enter The Days the Student Was Present: ");
    scanf("%s",stu_present);
    printf("\n Please Enter The Days the Student Was Absent: ");
    scanf("%s",stu_absent);
    getgrades();
}

void getgrades()
{
    for(int o=1; o!=5; o++)
    {
        printf("\n ------------------------");
        for(int i=0; i != 8; i++)
    {
        printf("\nPlease Enter Quarter %d Grade for %s: ", o, subjects[i]);
        scanf("%d", &stu_grade[o][i]);
        totquarter[o] += stu_grade[o][i];

    }
    quarteravg[o] = totquarter[o]/8;
        totaladd += quarteravg[o];
        printf("\n Average for Quarter %d: %d", o, quarteravg[o]);
    }
    printf("\n");
    totalavg = totaladd/4;
    display();
}

void calculate()
{
    for(int o=1; o!=5; o++)
    {
        for(int i=0; i!= 8; i++)
        {
            totquarter[o] += stu_grade[o][i];

        }
        quarteravg[o] = totquarter[o]/8;
        totaladd += quarteravg[o];
    }
    totalavg = totaladd/4;
    display();
}

void display()
{

    printf("Successfully Processed, Now Displaying Data: \n \n \n");
    printf("School Name: %s \n ",stu_schoolname);
    printf("Schoolyear: %s \n",stu_schoolyear);
    printf("Name of Principal: %s \n ------------------------------\n",stu_principal);

    printf("Name of Student: %s \n",stu_name);
    printf("Student LRN: %s \n",stu_LRN);
    printf("Student Section: %s \n",stu_section);
    printf("Student Schoolyear: %s \n",stu_schoolyear);
    printf("Student Gender: %s \n",stu_gender);
    printf("Student Age: %s \n",stu_age);
    printf("Grade %s Section %s\n",stu_level, stu_section);

    for(int o = 1; o!=5; o++)
    {
        printf("------------------------------\n");
        for(int i=0; i!= 8; i++)
        {
            printf("Grade of Student for %s Quarter %d: %d\n", subjects[i], o, stu_grade[o][i]);
        }
        printf("Average for Quarter %d: %d \n \n", o, quarteravg[o]);
    }

    printf("------------------------------ \n");
    printf("The Total Number of Schooldays: %s \n",stu_schooldays);
    printf("The Number of Days the Student was Present: %s \n",stu_present);
    printf("The Number of Days the Student was Absent: %s \n",stu_absent);

    printf( "------------------------------\n");
    printf("Average Grade: %d \n \n---------- \n \n ", totalavg);

    printf("Teacher's Remarks: %s \n", remarks);
    remark();
}

void remark()
{
    printf("\nPlease Enter Your Remarks for %s: ", stu_name);
    scanf("%s", remarks);

    printf("Would you like to save the file? \n 1> Yes \n 2> No(Return to Main Menu) \n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        printf("Saving File... \n");
        writetofile();
        break;
    case 2:
        printf("Returning to Main Menu...\n");
        break;
    default:
        printf("Defaulting to Saving...\n");
        writetofile();
        break;
    }

}

void writetofile()
{
    FILE *f;
    sprintf(filename, "%s.txt", stu_name);
    f = fopen(filename,"w");

    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(f,"School Name: %s \n ",stu_schoolname);
    fprintf(f,"Schoolyear: %s \n",stu_schoolyear);
    fprintf(f,"Name of Principal: %s \n ------------------------------\n",stu_principal);

    fprintf(f,"Name of Student: %s \n",stu_name);
    fprintf(f,"Student LRN: %s \n",stu_LRN);
    fprintf(f,"Student Section: %s \n",stu_section);
    fprintf(f,"Student Schoolyear: %s \n",stu_schoolyear);
    fprintf(f,"Student Gender: %s \n",stu_gender);
    fprintf(f,"Student Age: %s \n",stu_age);
    fprintf(f,"Grade %s Section %s\n",stu_level, stu_section);

    for(int o = 1; o!=5; o++)
    {
        fprintf(f, "------------------------------\n");
        for(int i=0; i!= 8; i++)
        {
            fprintf(f,"Grade of Student for %s Quarter %d: %d\n", subjects[i], o, stu_grade[o][i]);
        }
        fprintf(f,"Average for Quarter %d: %d \n \n", o, quarteravg[o]);
    }
    fprintf(f, "------------------------------\n");
    fprintf(f,"The Total Number of Schooldays: %s \n",stu_schooldays);
    fprintf(f,"The Number of Days the Student was Present: %s \n",stu_present);
    fprintf(f,"The Number of Days the Student was Absent: %s \n",stu_absent);

    fprintf(f, "------------------------------\n");
    fprintf(f,"Average Grade: %d \n \n---------- \n \n ", totalavg);

    fprintf(f,"Teacher's Remarks: %s \n", remarks);


    fclose(f);
    printf("\n \n File Successfully Saved! \n 1> Return to Main Menu \n 2> Create Another File \n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:

        break;
    case 2:
        setup();
        break;
    default:
        break;
    }
}

void deletefile()
{
    listfile();
    loop:
    printf("Please enter the name of the full file name you \n wish to delete(including .txt file extension): ");
    scanf("%s", input);
    sprintf(filename, "%s.txt", input);

    if (remove(input) == 0)
    {
        printf("\n \n The file is deleted successfully! \n 1> Return to Main Menu \n 2> Delete Another File \n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:

        break;
    case 2:
        goto loop;
        break;
    default:
        break;
    }


    } else
    {
        printf("\n The file is not deleted.");
    }

}

void readfile()
{
    FILE *f;
    listfile();
    open:
    printf("\n Please Enter the full file name of the file you want to read: ");
    scanf("%s",input);
    sprintf(filename, "%s.txt", input);
    f = fopen(input,"r");
    if (f == NULL)
    {
        printf("\nError opening file!\n");
        goto open;
    }
    char line[1000];
    while(fgets(line, 1000, f))
    {
        printf("%s", line);
    }
    fclose(f);

    printf("\n \n 1> Return to Main Menu \n 2> Open Another File \n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:

        break;
    case 2:
        goto open;
        break;
    default:
        break;
    }



}


void listfile()
{
    DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }

}
