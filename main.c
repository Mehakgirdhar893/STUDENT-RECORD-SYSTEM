#include <stdio.h>
#include <string.h>

/* ---------- Structure ---------- */
struct record
{
    char name[20];
    int roll;
    float marks;
};

/* ---------- Add Record ---------- */
void addRecord()
{
    struct record s;
    FILE *fp;
    int another = 1;

    fp = fopen("dkb.txt", "ab");

    if (fp == NULL)
    {
        printf("File error!\n");
        return;
    }

    while (another)
    {
        printf("\nEnter Name: ");
        scanf("%s", s.name);

        printf("Enter Roll: ");
        scanf("%d", &s.roll);

        printf("Enter Marks: ");
        scanf("%f", &s.marks);

        fwrite(&s, sizeof(s), 1, fp);

        printf("\nAdd another record? (1-Yes / 0-No): ");
        scanf("%d", &another);
    }

    fclose(fp);
}

/* ---------- Show Records ---------- */
void showRecord()
{
    struct record s;
    FILE *fp = fopen("dkb.txt", "rb");

    if (fp == NULL)
    {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nNAME\tROLL\tMARKS\n");
    printf("---------------------------\n");

    while (fread(&s, sizeof(s), 1, fp))
    {
        printf("%s\t%d\t%.2f\n", s.name, s.roll, s.marks);
    }

    fclose(fp);
}

/* ---------- Search Record ---------- */
void searchRecord()
{
    struct record s;
    FILE *fp = fopen("dkb.txt", "rb");
    int roll, found = 0;

    if (fp == NULL)
    {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nEnter roll to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == roll)
        {
            printf("\nRecord Found:");
            printf("\nName: %s", s.name);
            printf("\nRoll: %d", s.roll);
            printf("\nMarks: %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nRecord not found!\n");

    fclose(fp);
}

/* ---------- Delete Record ---------- */
void deleteRecord()
{
    struct record s;
    FILE *fp, *temp;
    int roll, found = 0;

    fp = fopen("dkb.txt", "rb");
    temp = fopen("temp.txt", "wb");

    if (fp == NULL)
    {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nEnter roll to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == roll)
            found = 1;
        else
            fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("dkb.txt");
    rename("temp.txt", "dkb.txt");

    if (found)
        printf("\nRecord deleted successfully!\n");
    else
        printf("\nRecord not found!\n");
}

/* ---------- Update Record ---------- */
void updateRecord()
{
    struct record s;
    FILE *fp;
    int roll, found = 0;

    fp = fopen("dkb.txt", "rb+");

    if (fp == NULL)
    {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nEnter roll to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == roll)
        {
            printf("\nEnter new name: ");
            scanf("%s", s.name);

            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found)
        printf("\nRecord updated successfully!\n");
    else
        printf("\nRecord not found!\n");
}

/* ---------- Main Function ---------- */
int main()
{
    int choice;

    do
    {
        printf("\n\n====== STUDENT RECORD SYSTEM ======");
        printf("\n1. Add Record");
        printf("\n2. Show Records");
        printf("\n3. Search Record");
        printf("\n4. Delete Record");
        printf("\n5. Update Record");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addRecord(); break;
            case 2: showRecord(); break;
            case 3: searchRecord(); break;
            case 4: deleteRecord(); break;
            case 5: updateRecord(); break;
            case 6: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    }
    while (choice != 6);

    return 0;
}
