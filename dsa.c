/*
Author: BADDYM
Project: Data Structures and Algorithms (SAMPLE)
Whatsapp: +256 781-181-958
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
start:

    // MENU
    printf("@@@@@@@@@@@@@@@@@@@ MENU @@@@@@@@@@@@@@@@@@@ \n");
    printf("Type 1 to Read the Data \n");
    printf("Type 2 to Insert New Data \n");
    printf("Type 3 to Update the Data \n");
    printf("Type 4 to Delete the Data \n");
    printf("Type 5 to EXIT! \n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n \n");

    int select;
    printf(">>>>>>>>> ");
    scanf("%d", &select);

    if (select == 1)
    {
        goto read_data;
    }
    else if (select == 2)
    {
        goto insert_data;
    }
    else if (select == 3)
    {
        goto update_data;
    }
    else if (select == 4)
    {
        goto delete_data;
    }
    else if (select == 5)
    {
        return 0;
    }
    else
    {
        printf("INVALID ENTRY, TRY AGAIN!!! \n \n");
        goto start;
    }

insert_data:
    printf("@@@@@@@@@@@@@@@@@@@ INSERT NEW DATA @@@@@@@@@@@@@@@@@@@ \n");
    int entries;
    printf("How many records are you inserting? (ENTER INTEGER) \n");
    printf(">>>>>>>>> ");
    scanf("%d", &entries);
    if (entries == 1){
        printf("Inserting %d Record. \n \n", entries);
    }else if(entries > 1){
        printf("Inserting %d Records. \n \n", entries);
    }else{
        goto start;
    }

    for (int i = 1; i <= entries; i++){
        char first_name[20];
        char last_name[20];
        char date_of_birth[12];
        char reg_no[7];
        char prog_code[5];
        int tuition;

        // NAMES
        printf("Enter your Last Name \n");
        printf(">>>>>>>>> ");
        scanf("%s", last_name);

        printf("Enter your First Name \n");
        printf(">>>>>>>>> ");
        scanf("%s", first_name);

        // Insert DOB
        printf("Enter your Date of Birth (YYYY-MM-DD) \n");
        printf(">>>>>>>>> ");
        scanf("%s", date_of_birth);

        // Get the Length of the String
        int date_length = strlen(date_of_birth);
        if (date_length > 10){
            printf("INVALID: Date too Long!! \n \n");
            goto start;
        }else if(date_length < 10){
            printf("INVALID: Date too Short!! \n \n");
            goto start;
        }

        //REGISTRATION NUMBER
        printf("Enter Registration Number \n");
        printf(">>>>>>>>> ");
        scanf("%s", reg_no);

        //Check regno
        int reg_no_check = strlen(reg_no);
        if(reg_no_check > 6){
            printf("INVALID: Registration Number too Long!! \n \n");
            goto start;
        }

        //PROGRAM CODE
        printf("Enter Program Code \n");
        printf(">>>>>>>>> ");
        scanf("%s", prog_code);

        //check prog_code
        int prog_code_check = strlen(prog_code);
        if(prog_code_check > 4){
            printf("INVALID: Program Code too Long!! \n \n");
            goto start;
        }

        //TUITION
        printf("Enter Annual Tuition \n");
        printf(">>>>>>>>> ");
        scanf("%d", &tuition);

        //check tuition
        if(tuition == 0 || tuition < 0){
            printf("Tuition Can't be zero! \n \n");
            goto start;
        }

        //WRITE DATA TO THE FILE
        FILE *file_check = fopen("student_details.csv","r");

        if(file_check == NULL){
            //File doesn't exit
            printf("New File Created. \n");
            //Create the File
            FILE *create_file = fopen("student_details.csv","w");
            //Add data to file
            fprintf(create_file, "%s,%s %s,%s,%s,%d \n",reg_no, last_name, first_name, date_of_birth, prog_code, tuition);
            fclose(create_file);

        }else{
            //File Exists
            printf("Record Added. \n");
            //Loop through all the data
            FILE *exists = fopen("student_details.csv","r");
            char data[1000];
            int exists_bool = 0;

            while(fgets(data, sizeof(data), exists)){
                char reg_no2[7];
                sprintf(reg_no2,"%s",strtok(data,","));

                printf("From file =%s, From Variable =%s \n",reg_no2, reg_no);

                printf("Comparison = %d \n", strcmp(reg_no2, reg_no));

                //Compare the registration numbers
                if(strcmp(reg_no2, reg_no) == 0){
                    exists_bool = 1;
                    break;
                }
            }

            //Prevent Duplicate Entry
            if(exists_bool == 0){
                //Create a new entry
                FILE *create_new = fopen("student_details.csv","a");
                //Append new data
                fprintf(create_new, "%s,%s %s,%s,%s,%d \n",reg_no, last_name, first_name, date_of_birth, prog_code, tuition);
                fclose(create_new);

                // OUTPUT
                printf("\n \n");
                printf("@@@@@@@@@@@@@@@ SUCCESS @@@@@@@@@@@@@@@ \n");
                printf("NAME: %s %s \n", last_name, first_name);
                printf("DOB: %s \n", date_of_birth);
                printf("REG No: %s \n", reg_no);
                printf("PROGRAM CODE: %s \n", prog_code);
                printf("ANNUAL TUITION: %d \n", tuition);
                printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n \n");
            }else{
                // OUTPUT
                printf("\n \n");
                printf("@@@@@@@@@@@@@@@ FAILED @@@@@@@@@@@@@@@ \n");
                printf("NAME: %s %s \n", last_name, first_name);
                printf("DOB: %s \n", date_of_birth);
                printf("REG No: %s \n", reg_no);
                printf("PROGRAM CODE: %s \n", prog_code);
                printf("ANNUAL TUITION: %d \n", tuition);
                printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n \n");
            }

            printf("\n \n");
            //Append new row

            fclose(exists);
        }
    }

    goto start;

read_data:
    printf("@@@@@@@@@@@@@@@@@@@ READ DATA @@@@@@@@@@@@@@@@@@@ \n");
    //Loop through all the data
    FILE *exists = fopen("student_details.csv","r");
    char data[1000];
    while(fgets(data, sizeof(data), exists)){
        printf("REG No.: %s \n", strtok(data,","));
        printf("NAME: %s \n", strtok(NULL,","));
        printf("DATE OF BIRTH: %s \n", strtok(NULL,","));
        printf("PROGRAM CODE: %s \n", strtok(NULL,","));
        printf("TUITION: %s \n", strtok(NULL,","));
    }
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n \n");
    fclose(exists);

    goto start;

update_data:
    printf("@@@@@@@@@@@@@@@@@@@ UPDATE EXISTING DATA @@@@@@@@@@@@@@@@@@@ \n");
    char reg_no[7];
    printf("Enter Student Registraion Number: \n");
    printf(">>>>>>>>> ");
    scanf("%s", reg_no);


    goto start;

delete_data:
    printf("@@@@@@@@@@@@@@@@@@@ DELETE DATA @@@@@@@@@@@@@@@@@@@ \n");
    char reg_no[7];
    printf("Enter Student Registraion Number: \n");
    printf(">>>>>>>>> ");
    scanf("%s", reg_no);

    goto start;

    return 0;
}
