#include <stdio.h>

int main()
{
    int id[100], attendance[100];
    int n, searchID;
    int low, high, mid;
    int comparisons = 0;
    int found = 0;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    printf("Enter employee IDs in ascending order:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &id[i]);

        printf("Enter attendance (1-Present, 0-Absent): ");
        scanf("%d", &attendance[i]);
    }

    printf("Enter employee ID to search: ");
    scanf("%d", &searchID);

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;
        comparisons++;

        if(id[mid] == searchID)
        {
            found = 1;
            printf("\nEmployee ID: %d\n", id[mid]);

            if(attendance[mid] == 1)
                printf("Employee is present\n");
            else
                printf("Employee is absent\n");

            break;
        }
        else if(searchID < id[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(found == 0)
        printf("\nEmployee ID not found\n");

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}

