#include <stdio.h>
#include <string.h>
#include <time.h>

//Structure of store items information
struct Items{
  int id;
  char name[20];
  int price;
} i;

void Display(void){
  FILE *p;
  p= fopen("ItemsCollections.txt", "r");
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
main(){

}