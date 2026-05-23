#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int main(int argc, char * argv[])
{
    FILE * fin;
    int n;
    const char *filename;
    Node *root=NULL;

    if (argc != 2)
    {
        printf("нет имени файла");
        return 3;
    }

    filename=argv[1];

    fin=fopen(filename,"r");

    if(fin==NULL)
    {
        printf("ошибка открытия");
        fclose(fin);
        return 1;
    }

    while(fscanf(fin,"%d",&n)==1)
    {
        root=add(root, n);
    }

    if(root==NULL)
    {
        printf("дерево пустое");
        fclose(fin);
        freetree(root);
        return 0;
    }

    printtree(root, 0);
    printf("\n");
    obhod(root);
    
    freetree(root);
    fclose(fin);
    return 0;
}
