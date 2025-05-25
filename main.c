#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILENAME "student_details2.bin"

int no;//for enrollment number
int pw;//for password


//defining structure
struct student
{
    char fname[50];
    char lname[50];
    int rollno;
    int cour_Id;
    int year;
    float cgpa;
    char mob_no[12];
    char hostel;
    char scholarship;
    char transport;
    char sport;
    char sports[20];


} st;


//function names
void display();
void addstu();
void printstu();
void update();
void deleteStudentByRollNumber();
int TotalStu();
void stuacc(int no);
void findrol();
void findnam();
void findid();
void no_year();
void no_cour();
void no_hostel();
void no_scholar();
void no_trans();
void sports();
void sport();
void SortByCGPA();
void SortByRoll();
void SortByCOUR();
void Topper();
void runner();
void third();


int main()
{
    int choice;
    while(1)
    {
        printf("\n \e[1;34m===========================================================================================================================================================\e[m\n");
        printf("\e[1;33;6m                                                            WELCOME TO STUDENT MANAGEMENT SYSTEM \e[m \n");
        printf("\n \e[1;34m===========================================================================================================================================================\e[m\n\n");
        printf("+--------------------------------+\n");
        printf("| \e[35mCHOOSE THE DESIRED OPTION >>> \e[m |");
        printf("\n|                                |");
        printf("\n| For STUDENT ACCESS : Press \e[1m1\e[m   |");
        printf("\n| For FACULTY ACCESS : Press \e[1m2\e[m   |");
        printf("\n| To EXIT the program : Press \e[1m0\e[m  |");
        printf("\n+--------------------------------+");
        printf("\n\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:

            printf("Enter your roll number : ");
            scanf("%d",&no);
            stuacc(no);
            break;

        case 2:
            printf("Enter passcode : ");
            scanf("%d",&pw);
            if(pw==123)
            {
                printf("\n \e[1;34m-----------------------------------------------------------------------------------------------------------------------------------------------------------\e[m");
                printf("\n\n \e[1;32;5m                                                                  WELCOME FACULTY MEMBER \e[m\n");
                printf("\n \e[1;34m-----------------------------------------------------------------------------------------------------------------------------------------------------------\e[m\n");

                display();
            }
            else
            {
                printf("\e[1;31;6mWRONG PASSWORD\e[m\n\n");
            }
            break;

        case 0:
            printf("THANKS FOR USING THE PROGRAM\n");
            exit(0);

        default:
            printf("\e[1;31;6mWRONG PASSWORD\e[m\n");
        }

    }
}


void display()
{
    int choi;
    while(1)
    {
        printf("+------------------------------------------------------------------------+");
        printf("\n| \e[35mCHOOSE THE DESIRED OPTION >>> \e[m                                         |");
        printf("\n|                                                                        |");
        printf("\n| Add the Student Details: Press \e[1m1\e[m                                       |");
        printf("\n| Show all the student data present in records: Press \e[1m2\e[m                  |");
        printf("\n| Find the student details by Roll Number: Press \e[1m3\e[m                       |");
        printf("\n| Find the student details by First Name: Press \e[1m4\e[m                        |");
        printf("\n| Find the student details by Course Id: Press \e[1m5\e[m                         |");
        printf("\n| Find the total number of Students: Press \e[1m6\e[m                             |");
        printf("\n| Delete the students details by Roll Number: Press \e[1m7\e[m                    |");
        printf("\n| Update the students details by Roll Number: Press \e[1m8\e[m                    |");
        printf("\n| Find the total number of Students in a year: Press \e[1m9\e[m                   |");
        printf("\n| Find the total number of Students in a course: Press \e[1m10\e[m                |");
        printf("\n| Find the total number of Students who opted hostel: Press \e[1m11\e[m           |");
        printf("\n| Find the total number of Students who opted transport system: Press \e[1m12\e[m |");
        printf("\n| Find the total number of Students who have scholarship: press \e[1m13\e[m       |");
        printf("\n| Find the total number of Students who plays sports: press \e[1m14\e[m           |");
        printf("\n| To find number of student who plays a particular sport: press \e[1m15\e[m       |");
        printf("\n| Sort by CGPA of a particular year: Press \e[1m16\e[m                            |");
        printf("\n| Sort by Roll No of a particular year: Press \e[1m17\e[m                         |");
        printf("\n| Sort by CGPA of a particular course: Press \e[1m18\e[m                          |");
        printf("\n| Top performer of a particular year : Press \e[1m19\e[m                          |");
        printf("\n| Runner up of a particular year : Press \e[1m20\e[m                              |");
        printf("\n| Third topper of a particular year : Press \e[1m21\e[m                           |");
        printf("\n| To exit program Press \e[1m0\e[m                                                |\n");
        printf("+------------------------------------------------------------------------+");
        printf("\n\nEnter choice : ");
        scanf("%d",&choi);
        switch(choi)
        {
        case 1:
            addstu();
            break;
        case 2:
            printstu();
            break;
        case 3:
            findrol();
            break;
        case 4:
            findnam();
            break;
        case 5:
            findid();
            break;
        case 6:
            TotalStu();
            break;
        case 7:
            deleteStudentByRollNumber();
            break;
        case 8:
            update();
            break;
        case 9:
            no_year();
            break;
        case 10:
            no_cour();
            break;
        case 11:
            no_hostel();
            break;
        case 12:
            no_trans();
            break;
        case 13:
            no_scholar();
            break;
        case 14:
            sport();
            break;
        case 15:
            sports();
            break;
        case 16:
            SortByCGPA();
            break;
        case 17:
            SortByRoll();
            break;
        case 18:
            SortByCOUR();
            break;
        case 19:
            Topper();
            break;
        case 20:
            runner();
            break;
        case 21:
            third();
            break;
        case 0:
            printf("\e[1;33;6mTHANKS FOR USING THE PROGRAM\e[m");
            exit(0);
        default:
            printf("\e[1;31;6mWRONG CHOICE\e[m");
        }
    }

}


void addstu()
{
    FILE *file;
    file=fopen(FILENAME,"ab+");
    if(file==NULL)
        printf("File could't open");

    printf("\e[1;36mADD STUDENT DETAILS\e[m\n");
    printf("\nFirst Name : ");
    scanf("%s",&st.fname);
    printf("Last Name : ");
    scanf("%s",&st.lname);
    printf("Roll no : ");
    scanf("%d",&st.rollno);
    printf("Course Id : ");
    scanf("%d",&st.cour_Id);
    printf("Year : ");
    scanf("%d",&st.year);
    printf("CGPA : ");
    scanf("%f",&st.cgpa);
    printf("Mobile number : ");
    scanf("%s",&st.mob_no);
    printf("Hostel(Y or N) : ");
    scanf(" %c",&st.hostel);
    printf("Scholarship(Y or N) : ");
    scanf(" %c",&st.scholarship);
    printf("Transport(Y or N) : ");
    scanf(" %c",&st.transport);
    printf("Sport(Y or N) : ");
    scanf(" %c",&st.sport);
    if(st.sport=='Y')
    {
        printf("Sports Name : ");
        scanf("%s",&st.sports);
    }
    fwrite(&st,sizeof(st),1,file);
    fclose(file);
}


void printstu()
{
    FILE *file;
    file=fopen(FILENAME,"rb");
    if(file==NULL)
        printf("file could't open");
    printf("\n\e[1;36mSTUDENT DETAILS\e[m\n\n");
    while(fread(&st,sizeof(st),1,file)==1)
    {
        printf("\e[1;34m----------------------------------\e[m\n");
        printf("Name : %s %s\n", st.fname, st.lname);
        printf("Roll no : %d\n", st.rollno);
        printf("Course Id : %d\n", st.cour_Id);
        printf("Year : %d\n", st.year);
        printf("CGPA : %.2f\n", st.cgpa);
        printf("Mobile number : %s\n", st.mob_no);
        printf("Hostel : %c\n",st.hostel);
        printf("Scholarship : %c\n",st.scholarship);
        printf("Transport : %c\n",st.transport);
        printf("Sports : %c\n",st.sport);
        if(st.sport=='Y')
        {
            printf("Sports Name : %s\n",st.sports);
        }
        printf("\e[1;34m----------------------------------\e[m\n");
        printf("\n");

    }
    fclose(file);
}


void update()
{
    FILE *file;
    file=fopen(FILENAME,"rb+");
    if(file==NULL)
        printf("file could't open");
    int roll;
    printf("Enter student's roll no:");
    scanf("%d",&roll);
    int a=0;
    while(fread(&st,sizeof(st),1,file)==1)
    {
        if(st.rollno==roll)
        {
            fseek(file, -sizeof(st), SEEK_CUR);
            printf("Student record found.\n");
            printf("\e[1;36mADD STUDENT DETAILS : \e[m\n");
            printf("First Name : ");
            scanf("%s",st.fname);
            printf("Last Name : ");
            scanf("%s",st.lname);
            printf("Course Id : ");
            scanf("%d",&st.cour_Id);
            printf("Year : ");
            scanf("%d",&st.year);
            printf("CGPA : ");
            scanf("%f",&st.cgpa);
            printf("Mobile number : ");
            scanf("%s",&st.mob_no);
            printf("Hostel(Y or N) : ");
            scanf(" %c",&st.hostel);
            printf("Scholarship(Y or N) : ");
            scanf(" %c",&st.scholarship);
            printf("Transport(Y or N) : ");
            scanf(" %c",&st.transport);
            printf("Sports : ");
            scanf("%s",&st.sport);
            if(st.sport=='Y')
            {
                printf("Sports : ");
                scanf("%s",&st.sports);
            }
            fwrite(&st,sizeof(st),1,file);
            printf("\n\e[1;33;6mSUCCESSFULLY DATA UPDATED\e[m\n");
            a=1;
            break;

        }
    }
    if(a==0)
        printf("\e[1;31;6mROLL NUMBER NOT FOUND\e[m");
    fclose(file);
}


void deleteStudentByRollNumber()
{
    int found = 0;
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    FILE *tempFile = fopen("tempfile.bin", "wb");
    if (tempFile == NULL)
    {
        fclose(file);
        printf("Error opening temporary file for writing\n");
        return;
    }

    int deleteRollNumber;
    printf("\n\e[1;36mENTER THE ROLL NUMBER OF THE STUDENT TO DELETE : \e[m");
    scanf("%d", &deleteRollNumber);

    while (fread(&st, sizeof(st), 1, file) == 1)
    {
        if (st.rollno == deleteRollNumber)
        {
            found = 1;
        }
        else
        {
            fwrite(&st, sizeof(st), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found)
    {
        printf("\e[1;31;6mSTUDENT WITH ROLL NUMBER %d NOT FOUND\e[m\n", deleteRollNumber);
        remove("tempfile.bin");
        return;
    }
    else
    {
        remove(FILENAME);
        rename("tempfile.bin", FILENAME);
        printf("\e[1;33;6mRECORD DELETED SUCESSFULLY\e[m\n\n");
    }
}


int TotalStu()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return 0;
    }
    int numStudents = 0;
    while (fread(&st, sizeof(st), 1, file) == 1)
    {
        numStudents++;
    }
    fclose(file);
    printf("\n\e[1;36mTOTAL NUMBER OF STUDENTS : %d\n\e[m", numStudents);
    return numStudents;
}


void findrol()
{
    FILE *file;
    file=fopen(FILENAME,"rb");
    if(file==NULL)
        printf("file could't open");
    int roll;
    printf("\n\e[1;36mENTER THE STUDENT'S ROLL NUMBER :\e[m");
    scanf("%d",&roll);
    int a=0;
    while(fread(&st,sizeof(st),1,file)==1)
    {
        if(st.rollno==roll)
        {
            printf("\e[1;34m----------------------------------\e[m\n");
            printf(" Name : %s %s\n", st.fname, st.lname);
            printf(" Roll no : %d\n", st.rollno);
            printf(" Course Id : %d\n", st.cour_Id);
            printf(" Year : %d\n", st.year);
            printf(" CGPA : %.2f\n", st.cgpa);
            printf("Mobile number : %s\n", st.mob_no);
            printf(" Hostel : %c\n",st.hostel);
            printf(" Scholarship : %c\n",st.scholarship);
            printf(" Transport : %c\n",st.transport);
            printf(" Sports : %c\n",st.sport);
            if(st.sport=='Y')
            {
                printf("Sports Name : %s\n",st.sports);
            }
            printf("\e[1;34m----------------------------------\e[m\n");
            printf("\n");
            printf("\n");
            a=1;
            break;

        }
    }
    if(a==0)
        printf("\e[1;31;6mROLL NUMBER IS NOT PRESENT\e[m");
    fclose(file);
}


void findnam()
{
    FILE *file;
    file=fopen(FILENAME,"rb");
    if(file==NULL)
        printf("file could't open");
    char fname[30];
    printf("\n\e[1;36mENTER THE STUDENT'S NAME :\e[m");
    scanf("%s",&fname);
    int a=0;
    while(fread(&st,sizeof(st),1,file)==1)
    {
        if(strcmp(fname,st.fname)==0)
        {
            printf("\e[1;34m----------------------------------\e[m\n");
            printf(" Name : %s %s\n", st.fname, st.lname);
            printf(" Roll no : %d\n", st.rollno);
            printf(" Course Id : %d\n", st.cour_Id);
            printf(" Year : %d\n", st.year);
            printf(" CGPA : %.2f\n", st.cgpa);
            printf("Mobile number : %s\n", st.mob_no);
            printf(" Hostel : %c\n",st.hostel);
            printf(" Scholarship : %c\n",st.scholarship);
            printf(" Transport : %c\n",st.transport);
            printf(" Sports : %c\n",st.sport);
            if(st.sport=='Y')
            {
                printf("Sports Name:%s\n",st.sports);
            }
            printf("\e[1;34m----------------------------------\e[m\n");
            printf("\n");
            a=1;
            break;

        }
    }
    if(a==0)
        printf("\e[1;31;6mNAME IS NOT PRESENT\e[m");
    fclose(file);
}


void findid()
{
    FILE *file;
    file=fopen(FILENAME,"rb");
    if(file==NULL)
        printf("file could't open");
    int id;
    printf("Enter student's course id:");
    scanf("%d",&id);
    int a=0;
    while(fread(&st,sizeof(st),1,file)==1)
    {
        if(st.cour_Id==id)
        {
            printf("\e[1;34m----------------------------------\e[m\n");
            printf(" Name : %s %s\n", st.fname, st.lname);
            printf(" Roll no : %d\n", st.rollno);
            printf(" Course Id : %d\n", st.cour_Id);
            printf(" Year : %d\n", st.year);
            printf(" CGPA : %.2f\n", st.cgpa);
            printf("Mobile number : %s\n", st.mob_no);
            printf(" Hostel(Y or N) : %c\n",st.hostel);
            printf(" Scholarship(Y or N) : %c\n",st.scholarship);
            printf(" Transport(Y or N) : %c\n",st.transport);
            printf(" Sports(Y or N) : %c\n",st.sport);
            if(st.sport=='Y')
            {
                printf("Sports Name:%s\n",st.sports);
            }
            printf("\e[1;34m----------------------------------\e[m\n");
            printf("\n");
            a=1;


        }
    }
    if(a==0)
        printf("\e[1;31;6mCOURSE NUMBER IS NOT PRESENT\e[m");
    fclose(file);

}


void stuacc(int no)
{
    FILE *file;
    file=fopen(FILENAME,"rb");
    if(file==NULL)
        printf("file could't open");

    int a=0;
    while(fread(&st,sizeof(st),1,file)==1)
    {
        if(no==st.rollno)
        {
            printf("\n\t\tSTUDENT DETAILS\n");
            printf("\e[1;34m----------------------------------\e[m\n");
            printf(" Name : %s %s\n", st.fname, st.lname);
            printf(" Roll no : %d\n", st.rollno);
            printf(" Course Id : %d\n", st.cour_Id);
            printf(" Year : %d\n", st.year);
            printf(" CGPA : %.2f\n", st.cgpa);
            printf("Mobile number : %s\n", st.mob_no);
            printf(" Hostel : %c\n",st.hostel);
            printf(" Scholarship : %c\n",st.scholarship);
            printf(" Transport : %c\n",st.transport);
            printf(" Sports : %c\n",st.sport);
            a=1;
            if(st.sport=='Y')
            {
                printf("Sports Name : %s\n",st.sports);
            }
            printf("\e[1;34m----------------------------------\e[m\n");
            printf("\n");
            printf("\n");
        }


    }if(a==0)
        printf("\e[1;31;6mROLL NUMBER IS NOT PRESENT\e[m\n");

    fclose(file);
}


void no_hostel()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }
    int numStudents = 0;
    while (fread(&st, sizeof(st), 1, file) == 1)
    {
        if(st.hostel=='Y')
            numStudents++;
    }
    fclose(file);
    printf("\e[1;36mTOTAL NUMBER OF STUDENTS WHO OPTED HOSTEL : %d\n\e[m", numStudents);
}


void no_scholar()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }
    int numStudents = 0;
    while (fread(&st, sizeof(st), 1, file) == 1)
    {
        if(st.scholarship=='Y')
            numStudents++;
    }
    fclose(file);
    printf("\e[1;36mTOTAL NUMBER OF STUDENTS WHO HAVE SCHOLARSHIP : %d\e[m\n", numStudents);
}


void no_trans()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }
    int numStudents = 0;
    while (fread(&st, sizeof(st), 1, file) == 1)
    {
        if(st.transport=='Y')
            numStudents++;
    }
    fclose(file);
    printf("\e[1;36mTOTAL NUMBER OF STUDENTS WHO OPTED TRANSPORT SYSTEM : %d\e[m\n", numStudents);
}


void sports()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }
    char sport[20];
    printf("Input name of sports:");
    scanf("%s",sport);
    int numStudents = 0;

    while (fread(&st, sizeof(st), 1, file) == 1)
    {
        if(strcasecmp(sport,st.sports)==0)
            numStudents++;
    }
    fclose(file);
    printf("\e[1;36mTOTAL NUMBER OF STUDENTS WHO PLAYS %s : %d\e[m\n",sport,numStudents);
}


void sport()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }
    int numStudents = 0;
    while (fread(&st, sizeof(st), 1, file) == 1)
    {
        if(st.sport=='Y')
            numStudents++;
    }
    fclose(file);
    printf("\e[1;36mTOTAL NUMBER OF STUDENTS WHO PLAYS SPORT : %d\e[m\n", numStudents);
}


void SortByCGPA()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }

    struct student students[100];
    int numStudents = 0;

    while (fread(&students[numStudents], sizeof(struct student), 1, file) == 1)
    {
        numStudents++;
        if (numStudents >= 100)
        {
            printf("Max students limit reached.\n");
            break;
        }
    }
    fclose(file);

    int selectedYear;
    printf("Enter the year to sort students : ");
    scanf("%d", &selectedYear);

    printf("\n\e[1;36mSORTED LIST OF STUDENTS FOR YEAR %d BASED ON CGPA  :\e[m\n", selectedYear);
    for (int i = 0; i < numStudents; ++i)
    {
        if (students[i].year == selectedYear)
        {
            for (int j = i + 1; j < numStudents; ++j)
            {
                if (students[j].year == selectedYear && students[j].cgpa > students[i].cgpa)
                {
                    struct student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
            printf("\e[1;34m----------------------------------\e[m\n");
            printf(" Name : %s %s\n", students[i].fname, students[i].lname);
            printf(" Roll no : %d\n", students[i].rollno);
            printf(" Course Id : %d\n", students[i].cour_Id);
            printf(" Year : %d\n", students[i].year);
            printf(" CGPA : %.2f\n", students[i].cgpa);
            printf(" Mobile number : %s\n", students[i].mob_no);
            printf(" Hostel : %c\n",students[i].hostel);
            printf(" Scholarship : %c\n",students[i].scholarship);
            printf(" Transport : %c\n",students[i].transport);
            printf(" Sports : %c\n",students[i].sport);
            if(st.sport=='Y')
            {
                printf("Sports Name:%s\n",students[i].sports);
            }
            printf("\e[1;34m----------------------------------\e[m\n");
        }
        printf("\n");
    }
}


void SortByRoll()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }

    struct student students[100];
    int numStudents = 0;

    while (fread(&students[numStudents], sizeof(struct student), 1, file) == 1)
    {
        numStudents++;
        if (numStudents >= 100)
        {
            printf("Max students limit reached\n");
            break;
        }
    }
    fclose(file);

    int selectedYear;
    printf("Enter the year to sort students: ");
    scanf("%d", &selectedYear);

    printf("\e[1;36mSORTED LIST OF STUDENTS FOR YEAR %d BASED ON CGPA  :\e[m\n", selectedYear);
    for (int i = 0; i < numStudents; ++i)
    {
        if (students[i].year == selectedYear)
        {
            for (int j = i + 1; j < numStudents; ++j)
            {
                if (students[j].year == selectedYear && students[j].rollno < students[i].rollno)
                {
                    struct student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
            printf("\e[1;34m----------------------------------\e[m\n");
            printf(" Name : %s %s\n", students[i].fname, students[i].lname);
            printf(" Roll no : %d\n", students[i].rollno);
            printf(" Course Id : %d\n", students[i].cour_Id);
            printf(" Year : %d\n", students[i].year);
            printf(" CGPA : %.2f\n", students[i].cgpa);
            printf(" Mobile number : %s\n", students[i].mob_no);
            printf(" Hostel : %c\n",students[i].hostel);
            printf(" Scholarship : %c\n",students[i].scholarship);
            printf(" Transport : %c\n",students[i].transport);
            printf(" Sports : %c\n",students[i].sport);
            if(st.sport=='Y')
            {
                printf("Sports Name:%s\n",students[i].sports);
            }
            printf("\e[1;34m----------------------------------\e[m\n");
        }
        printf("\n");
    }
}


void Topper()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }

    struct student students[100];
    int numStudents = 0;

    while (fread(&students[numStudents], sizeof(struct student), 1, file) == 1)
    {
        numStudents++;
        if (numStudents >= 100)
        {
            printf("Max students limit reached.\n");
            break;
        }
    }
    fclose(file);

    int selectedYear;
    printf("Enter the year to find highest scorer student : ");
    scanf("%d", &selectedYear);

    printf("\e[1;36mHIGHEST SCORER STUDENT FOR YEAR %d BASED ON CGPA : \e[1;36m\n", selectedYear);
    for (int i = 0; i < numStudents; ++i)
    {
        if (students[i].year == selectedYear)
        {
            for (int j = i + 1; j < numStudents; ++j)
            {
                if (students[j].year == selectedYear && students[j].cgpa > students[i].cgpa)
                {
                    struct student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }

        }
    }
    printf("\e[1;34m----------------------------------\e[m\n");
    printf(" Name : %s %s\n", students[0].fname, students[0].lname);
    printf(" Roll no : %d\n", students[0].rollno);
    printf(" Course Id : %d\n", students[0].cour_Id);
    printf(" Year : %d\n", students[0].year);
    printf(" CGPA : %.2f\n", students[0].cgpa);
    printf(" Mobile number : %s\n", students[0].mob_no);
    printf(" Hostel : %c\n",students[0].hostel);
    printf(" Scholarship : %c\n",students[0].scholarship);
    printf(" Transport : %c\n",students[0].transport);
    printf(" Sports : %c\n",students[0].sport);
    if(st.sport=='Y')
    {
        printf("Sports Name:%s\n",students[0].sports);
    }
    printf("\e[1;34m----------------------------------\e[m\n");
    printf("\n");

}


int compareCGPA(const void *a, const void *b) {
    return (*(struct student *)b).cgpa - (*(struct student *)a).cgpa;
}

void SortByCOUR() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }

    struct student students[100];
    int numStudents = 0;

    while (fread(&students[numStudents], sizeof(struct student), 1, file) == 1) {
        numStudents++;
        if (numStudents >= 100) {
            printf("Max students limit reached.\n");
            break;
        }
    }
    fclose(file);

    int selectedCourseId;
    printf("Enter the course ID to sort students: ");
    scanf("%d", &selectedCourseId);

    printf("\e[1;36mSorted Students for Course ID %d Based on CGPA :\e[m\n", selectedCourseId);

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].cour_Id == selectedCourseId) {
            for (int j = i + 1; j < numStudents; ++j) {
                if (students[j].cour_Id == selectedCourseId && students[j].cgpa > students[i].cgpa) {
                    struct student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].cour_Id == selectedCourseId) {
            printf("\e[1;34m----------------------------------\e[m\n");
            printf(" Name : %s %s\n", students[i].fname, students[i].lname);
            printf(" Roll no : %d\n", students[i].rollno);
            printf(" Course Id : %d\n", students[i].cour_Id);
            printf(" Year : %d\n", students[i].year);
            printf(" CGPA : %.2f\n", students[i].cgpa);
            printf(" Mobile number : %s\n", students[i].mob_no);
            printf(" Hostel : %c\n", students[i].hostel);
            printf(" Scholarship : %c\n", students[i].scholarship);
            printf(" Transport : %c\n", students[i].transport);
            printf(" Sports : %c\n", students[i].sport);
            if (students[i].sport == 'Y') {
                printf("Sports Name: %s\n", students[i].sports);
            }
            printf("\e[1;34m----------------------------------\e[m\n");
        }
    }
}


void no_cour()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }
    int cour;
    printf("Input Course_Id:");
    scanf("%d",&cour);
    int numStudents = 0;
    while (fread(&st, sizeof(st), 1, file) == 1)
    {
        if(st.cour_Id==cour)
            numStudents++;
    }
    fclose(file);
    printf("\e[1;36mTOTAL NUMBER OF STUDENTS IN COURSE %d : %d\e[m\n",cour, numStudents);
}


void no_year()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }
    int year;
    printf("Input year:");
    scanf("%d",&year);
    int numStudents = 0;
    while (fread(&st, sizeof(st), 1, file) == 1)
    {
        if(st.year==year)
            numStudents++;
    }
    fclose(file);
    printf("\e[1;36mTOTAL NUMBER OF STUDENTS IN YEAR %d : %d\e[m\n",year, numStudents);
}


void runner()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }

    struct student students[100];
    int numStudents = 0;

    while (fread(&students[numStudents], sizeof(struct student), 1, file) == 1)
    {
        numStudents++;
        if (numStudents >= 100)
        {
            printf("Max students limit reached.\n");
            break;
        }
    }
    fclose(file);

    int selectedYear;
    printf("Enter the year to find runner up scorer : ");
    scanf("%d", &selectedYear);

    printf("\e[1;36mRUNNER UP SCORER FOR YEAR %d BASED ON CGPA : \e[m\n", selectedYear);
    for (int i = 0; i < numStudents; ++i)
    {
        if (students[i].year == selectedYear)
        {
            for (int j = i + 1; j < numStudents; ++j)
            {
                if (students[j].year == selectedYear && students[j].cgpa > students[i].cgpa)
                {
                    struct student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }

        }
    }
    printf("\e[1;34m----------------------------------\e[m\n");
    printf(" Name : %s %s\n", students[1].fname, students[1].lname);
    printf(" Roll no : %d\n", students[1].rollno);
    printf(" Course Id : %d\n", students[1].cour_Id);
    printf(" Year : %d\n", students[1].year);
    printf(" CGPA : %.2f\n", students[1].cgpa);
    printf(" Mobile number : %s\n", students[1].mob_no);
    printf(" Hostel : %c\n",students[1].hostel);
    printf(" Scholarship : %c\n",students[1].scholarship);
    printf(" Transport : %c\n",students[1].transport);
    printf(" Sports : %c\n",students[1].sport);
    if(st.sport=='Y')
    {
        printf("Sports Name : %s\n",students[1].sports);
    }
    printf("\e[1;34m----------------------------------\e[m\n");
    printf("\n");


}


void third()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Error");
        printf("Error opening file for reading.\n");
        return;
    }

    struct student students[100];
    int numStudents = 0;

    while (fread(&students[numStudents], sizeof(struct student), 1, file) == 1)
    {
        numStudents++;
        if (numStudents >= 100)
        {
            printf("Max students limit reached.\n");
            break;
        }
    }
    fclose(file);

    int selectedYear;
    printf("Enter the year to find third scorer : ");
    scanf("%d", &selectedYear);

    printf("Third  scorer for year %d based on CGPA:\n", selectedYear);
    for (int i = 0; i < numStudents; ++i)
    {
        if (students[i].year == selectedYear)
        {
            for (int j = i + 1; j < numStudents; ++j)
            {
                if (students[j].year == selectedYear && students[j].cgpa > students[i].cgpa)
                {
                    struct student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }

        }
    }

    printf("\e[1;34m----------------------------------\e[m\n");
        printf(" Name : %s %s\n", students[2].fname, students[2].lname);
        printf(" Roll no : %d\n", students[2].rollno);
        printf(" Course Id : %d\n", students[2].cour_Id);
        printf(" Year : %d\n", students[2].year);
        printf(" CGPA : %.2f\n", students[2].cgpa);
        printf(" Mobile number : %s\n", students[2].mob_no);
        printf(" Hostel : %c\n",students[2].hostel);
        printf(" Scholarship : %c\n",students[2].scholarship);
        printf(" Transport : %c\n",students[2].transport);
        printf(" Sports : %c\n",students[2].sport);
        if(st.sport=='Y')
        {
            printf("Sports Name:%s\n",students[2].sports);
        }
        printf("\e[1;34m----------------------------------\e[m\n");
        printf("\n");


}
