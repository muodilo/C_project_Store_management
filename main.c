#include <stdio.h>
#include <string.h>
#include <time.h>

//Structure of store items information
struct Items{
  int id;
  char name[20];
  int price;
} i;

void Update(void) {
    FILE *p, *pt;
    FILE *t;
    int id, b = 0, d,e=2;
    printf("Update an item.\n");
    printf("------------\n");
    printf("Do you want to display the catalog before? (yes:1, no:0)\n");
    scanf("%d", &d);
    if (d == 1) {
        Display();
    }
    printf("Enter an item id: ");
    scanf("%d", &id);
    char* fmt = " %[^\n]%*c";
    p = fopen("ItemsC.txt", "r");
    t = fopen("temp.txt", "w");
    while (fscanf(p, "%d\t%[^\t]%*c\t%d\n", &i.id, i.name, &i.price) != EOF) {
        if (i.id == id) {
            b++;
            i.id=1;
            printf("Id found.\n");
            printf("Enter name: ");
            scanf(fmt, i.name);
            printf("\nEnter price: ");
            scanf("%d", &i.price);
            fprintf(t, "%d\t%s\t%d\n", i.id, i.name, i.price);
        }
    }
    fclose(p);
    fclose(t);
    if (b == 0) {
        printf("Id not found!\n");
    }
    else
    {
        p = fopen("ItemsC.txt", "r");
        pt = fopen("temp.txt", "a");
        while (!feof(p))
        {
            fscanf(p, "%d\t%[^\t]%*c\t%d\n", &i.id, i.name, &i.price);
            if (i.id != id)
            {
                i.id=e;
                fprintf(pt, "%d\t%s\t%d\n", i.id, i.name, i.price);
                e++;
            }
        }
        fclose(p);
        fclose(pt);
        remove("ItemsC.txt");
        rename("temp.txt", "ItemsC.txt");
    printf("Item updated!\nPress any key to continue.\n\n");
    getch();
    }
}

void Display(void){
  FILE *p;
  p= fopen("ItemsC.txt", "r");
  printf("Display available Products\n------------------------\n\n");
  printf("ID\tNAME\tPRICE");
  printf("\n--\t----\t\t-----\n");
  while(fscanf(p,"%d\t%[^\t]%*c\t%d\n",&i.id,i.name,&i.price)!=EOF){
      if(strlen(i.name)<=8)
    {
      printf("\n%d\t%s    \t%d", i.id,i.name,i.price);
    }
    else
    {
      printf("\n%d\t%s\t%d", i.id,i.name,i.price);
    }
  }
    fclose(p);
    printf("\nPress any key to continue.\n");
    getch();
  
}

void Del(void)
{
    FILE *p, *pt;
     FILE *t, *n, *nt;
    p = fopen("ItemsC.txt","r");
    t = fopen("temp.txt","a");
    n = fopen("last_id.txt", "r");
    nt = fopen("tem.txt","w");
    int id, l_id, b=0,d,new_id=0;
     //float nbvote, sum;
    printf("Delete an item.\n");
    printf("------------\n\n");
    printf("Do you want to display the catalog before? (yes:1, no:0)\n");
    scanf("%d", &d);
    if (d == 1) {
        Display();
    }
    printf("Enter an item id:___");
    scanf("%d",&id);
    while(fscanf(p, "%d\t%[^\t]%*c\t%d\n", &i.id, i.name, &i.price) != EOF)
    {
        if(i.id==id)
        {
            b++;
            fscanf(n, "%d", &l_id);
            l_id--;
            fprintf(nt,"%d", l_id);
        }
    }
    if(b==0)
    {
        printf("Id not found!");
    }
    else
    {
        pt = fopen("ItemsC.txt","r");
        while(fscanf(pt, "%d\t%[^\t]%*c\t%d\n", &i.id, i.name, &i.price) != EOF)
        {

            if(i.id!=id)
            {
                new_id++;
                i.id = new_id;
                fprintf(t, "%d\t%s\t%d\n", i.id, i.name, i.price);
            }
        }
    }
    fclose(pt);
    fclose(p);
    fclose(t);
    fclose(n);
    fclose(nt);
    if(b==0)
    {
        remove("temp.txt");
        remove("tem.txt");
    }
    else
    {
        remove("ItemsC.txt");
        remove("last_id.txt");
        rename("temp.txt","ItemsC.txt");
        rename("tem.txt","last_id.txt");
        printf("Data updated!\nPress any key to continue.\n\n");
        getch();
    }
}



Record()
{
    FILE *f;
    FILE *l;
    FILE *p;
    int number_of_items,l_id,n;
    printf("##############################");
    printf("\n******RECORD NEW PRODUCT******");
    printf("\n##############################");

    f= fopen("ItemsC.txt","a");
    l= fopen("last_id.txt","r");
    if(l==NULL)
    {
        l_id=0;
    }
    else
    {
        fscanf(l,"%d", &l_id);
    }
    fclose(l);
    p= fopen("last_id.txt","w");
    printf("\n\nHow many items do you want to record: ");
    scanf("%d",&number_of_items);
    char* fmt = " %[^\n]%*c";
    for(n=1;n<=number_of_items;n++)
    {
        l_id+=1;
        i.id = l_id;
        printf("\nEnter Name: ");
        scanf(fmt, i.name);
        printf("\nEnter Price: ");
        scanf("%d", &i.price);
        l_id=i.id;

        fprintf(f,"%d\t%s\t%d\n",i.id,i.name,i.price);

    }
    fclose(f);
    fprintf(p,"%d",l_id);
    fclose(p);
    printf("Data saved!\nPress any key to continue.\n\n");
    getch();
}

    struct ReceiptItem
    {
        char name[30];
        int price;
        int count;
    };

save(struct ReceiptItem items[100],int itemcount,int total_price)
{
    time_t t = time(NULL);
    int k,j;
    char* current_time = ctime(&t);
    FILE *s;
    s=fopen("save_.txt","a");

    fprintf(s,"Date:%s",current_time);
    fprintf(s,"------------------------------\n");

    fprintf(s,"+-------------------------------------+---------+\n");
    fprintf(s,"| Item                | Price | Count | Total   |\n");
    fprintf(s,"+-------------------------------------+---------+\n");

    for (k = 0; k < itemcount; k++)
    {
        if(strlen(items[k].name)<=8)
        {
            fprintf(s,"|%s   \t\t%d\t  %d\t%d\t|\n",items[k].name, items[k].price,
               items[k].count, items[k].price * items[k].count);
        }
        else
        {
            fprintf(s,"|%s\t\t%d\t  %d\t%d\t|\n",items[k].name, items[k].price,
               items[k].count, items[k].price * items[k].count);
        }
    }

    fprintf(s,"+-----------------------------------------------+\n");
    fprintf(s,"| Total price:                           $%5d |\n", total_price);
    fprintf(s,"+-----------------------------------------------+\n\n");

}

float calculate_total_price()
{
    FILE *p;
    float total_price = 0.0;
    p = fopen("l_s_item.txt", "r");

    if (p == NULL)
    {
        printf("Error opening file.\n");
        return total_price;
    }

    while (fscanf(p, "%d\t%[^\t]%*c\t%d\n", &i.id, i.name, &i.price) != EOF)
    {
        total_price += i.price;
    }

    fclose(p);
    return total_price;
}

print_receipt()
{
    int itemcount = 0;
    int found;
    FILE *s;
    time_t t = time(NULL);
    int j,k;
    char* current_time = ctime(&t);
    int total_price = 0;
    FILE *p;
    p = fopen("l_s_item.txt", "r");

    if (p == NULL)
    {
        printf("Error opening file.\n");
        return;
    }



    struct ReceiptItem items[100];  // Assuming maximum of 100 items


    // Read items from file and count their appearances
    while (fscanf(p, "%d\t%[^\t]%*c\t%d\n", &i.id, i.name, &i.price) != EOF)
    {
        int found = 0;

        // Check if the item already exists in the items array
        for (int j = 0; j < itemcount; j++)
        {
            if (strcmp(i.name, items[j].name) == 0)
            {
                items[j].count++;
                found = 1;
                break;
            }
        }

        // If the item doesn't exist, add it to the items array
        if (!found)
        {
            strcpy(items[itemcount].name, i.name);
            items[itemcount].price = i.price;
            items[itemcount].count = 1;
            itemcount++;
        }
    }


    fclose(p);


    printf("Date:%s",current_time);
    printf("------------------------------\n");

    printf("+-----------------------------------------------+\n");
    printf("|                   RECEIPT                     |\n");

    printf("+-------------------------------------+---------+\n");
    printf("| Item                | Price | Count | Total   |\n");
    printf("+-------------------------------------+---------+\n");

    for (k = 0; k < itemcount; k++)
    {
        total_price += items[k].price * items[k].count;
        if(strlen(items[k].name)<=8)
        {
            printf("|%s   \t\t%d\t  %d\t%d\t|\n",items[k].name, items[k].price,
               items[k].count, items[k].price * items[k].count);
        }
        else
        {
            printf("|%s\t\t%d\t  %d\t%d\t|\n",items[k].name, items[k].price,
               items[k].count, items[k].price * items[k].count);
        }
    }

    printf("+-----------------------------------------------+\n");
    printf("| Total price:                           $%5d |\n", total_price);
    printf("+-----------------------------------------------+\n");

    save(items,itemcount,total_price);
    getch();
}

Sell_items()
{
    int choice;
    FILE *p;

    do
    {
        printf("|---------------------------|\n");
        printf("| SELL ITEMS |\n");
        printf("|---------------------------|\n");


        printf("\n\n1- Record items to be sold.");
        printf("\n2- print the receipt");
        printf("\n0- Exit.");
        printf("\nEnter the action: ");
        scanf("\n%d", &choice);
        system("cls");
        switch(choice)
        {
            case 1:
                record_s_item();
                printf("\n\nitems recorded\nPress any key to continue.\n\n");
                getchar();
                break;
            case 2:
                print_receipt();
                break;
        }
        system("cls");
        }while(choice!=0);
        remove("l_s_item.txt");
}

search_backup()
{
    FILE* file = fopen("save_.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        getchar();
        return;
    }
    int b=0;
    char dt[30];
    char* fmt = " %[^\n]%*c";
    printf("Enter  a date : ");
    scanf(fmt,dt);
    char line[256];
    int isDateFound = 0;
    while (fgets(line, sizeof(line), file)) {
        // Check if the line contains the date
        if (strstr(line, dt) != NULL) {
            isDateFound = 1;
            b++;
            if(b=1)
            {
                printf("\n\npayments found for the specified date.\n\n");
            }

            printf("%s", line);  // Print the line with the date

            // Print the following lines until a blank line is encountered
            while (fgets(line, sizeof(line), file) && strcmp(line, "\n") != 0)
            {
                printf("%s", line);
            }
            printf("\n");
        }
    }

    if (!isDateFound) {
        printf("No payments found for the specified date.\n");
    }
    fclose(file);

    printf("\nPress any key to exit");
    getchar();

}


main(){

}