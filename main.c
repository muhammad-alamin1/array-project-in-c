#include <stdio.h>

#define MAX_LENGTH 100

int main()
{
    system("cls");

    int data[MAX_LENGTH];
    int length = 0, value, i, index;
    unsigned short int input;

    do
    {
        printf("Menu: \n\n");
        printf("1. Add \n");
        printf("2. Insert \n");
        printf("3. Edit \n");
        printf("4. Delete \n");
        printf("5. Display \n");
        printf("6. Clear \n");
        printf("0. Exit \n");
        printf("_______________\n");

        printf("Enter a Menu: \n");
        scanf("%hu", &input);

        system("cls");
        printf("========= Result ========= \n\n");

        switch(input)
        {
        case 0:
            break;
        case 1:
            // add operation
            printf("Enter an Integer value: ");
            scanf("%d", &value);
            data[length] = value;
            printf("%d inserted at index %d \n", value, length);
            length++;

            break;
        case 2:
            // Insert
            printf("Enter an Integer value: ");
            scanf("%d", &value);
            printf("Enter an Index Between 0 - %d: ", length);
            scanf("%d", &index);

            // 1 2 3 0 0 0 logic
            // 1 2 3 3 0 0
            // 1 2 2 3 0 0
            // 1 1 2 3 0 0
            // 5 1 2 3 0 0  insert 5

            for(i = length; i > index; i--)
            {
                data[i] = data[i - 1];
            }
            data[index] = value;
            length++;
            printf("%d inserted at index %d \n", value, length);

            break;
        case 3:
            // Edit
            printf("Enter an Index Between 0 - %d: ", length-1);
            scanf("%d", &index);
            printf("Enter an new Integer value: ");
            scanf("%d", &value);

            data[index] = value;
            printf("%d data Updated Successfully. At index %d\n",value, index);

            break;
        case 4:
            // delete
            printf("Enter an Index Between 0 - %d: ", length-1);
            scanf("%d", &index);

            int del_val = data[index];
            for(i = index; i < length; i++)
            {
                data[i] = data[i + 1];
            }
            data[length] = 0;
            length--;

            printf("%d data Deleted Successfully. At index %d\n",del_val, index);

            break;
        case 5:
            // Display data
            if(length == 0)
            {
                printf("There is no data.\n");
                break;
            }else{
                printf("Data: ");
                for(i = 0; i < length; i++)
                {
                    printf("%d\t", data[i]);
                }
                printf("\n");
            }

            break;
        case 6:
            for(i = 0; i < length; i++)
            {
                data[i] = 0;
            }
            length = 0;
            printf("Data Cleared. \n");

            break;
        default:
            printf("Invalid Input.\n");
            break;
        }
        printf("\n========= Result =========\n");
    }while(input != 0);
    //system("cls");


    return 0;
}
