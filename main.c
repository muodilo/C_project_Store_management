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

main(){

}