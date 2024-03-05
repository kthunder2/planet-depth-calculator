#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct Earth
{
    float depth[MAX];
    float celcius[MAX];
    float fahrenheit[MAX];

};

void addEarth(struct Earth *, int);
void searchEarth(struct Earth , int);
void storeEarth(struct Earth, int);

int main()
{
    int i, j=0; //for menu loop& number of structures

    int num_of_earth=0;

    struct Earth a;

    do
    {
        printf("1) Add depth\n");
        printf("2) Search depth\n");
        printf("3) Store earth\n");
        printf("4) Exit\n");
        printf("What would you like to do?:");
        fflush(stdin);
        scanf("%d", &i);
        fflush(stdin);

        if(i==1)
        {
            addEarth(&a, j);
            j++;
        }
        else if(i==2)
        {
            searchEarth(a, j);
        }

        else if(i==3)
        {
            storeEarth(a, j);
        }

        else if(i==4)
        {
            printf("\nByee!");
        }

        else
        {
            printf("\nWorng input");
        }

    }
    while(i!=4);


    return 0;
}

void addEarth(struct Earth *b, int j)
{
    printf("\nEnter depth:");
    do
    {
        scanf("%f", &b->depth[j]);
        fflush(stdin);
        if(b->depth[j]<0)
        {
            printf("\nInvalid depth value, enter again:");
        }
    }
    while(b->depth<0);



    b->celcius[j] = 10.0*(b->depth[j])+20;
    b->fahrenheit[j] = (9.0/5.0)*(b->celcius[j])+32;

}
void searchEarth(struct Earth b, int j)
{
    int search, k;
    printf("\nEnter the depth:");
    scanf("%d", &search);
    fflush(stdin);
    for(k=0; k<j; k++)
    {
        if(b.depth[k]==search)
        {
            printf("\nThe temperature at depth %.1f is %.1f degrees Celsius", b.depth[k], b.celcius[k]);
            printf("\nThe temperature at depth %.1f is %.1f degrees Fahrenheit\n\n", b.depth[k], b.fahrenheit[k]);
        }
        else if(k==j)
        {
            printf("\nDepth %.1f not found!", b.depth[k]);
        }
    }
}
void storeEarth(struct Earth b, int j)
{
    int k;
    FILE *printer;
    if(printer==NULL)
    {
        printf("\nFile creation unsuccesful!\n");
        exit(1);
    }
    if(printer!=NULL)
    {
        printf("earth.txt is successfully created!\n");
    }
    printer=fopen("earth.txt", "a");
    for(k=0; k<j; k++)
    {
        fprintf(printer, "%.1f %.1f %.1f \n", b.depth[k], b.celcius[k], b.fahrenheit[k]);
    }

    fclose(printer);



}
