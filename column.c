#include "column.h"

COLUMN *create_column(char* title){
    COLUMN *newCol = malloc(sizeof(COLUMN));

    newCol->title = title;
    newCol->taille_logique = 0;
    newCol->taille_physique = 0;
    newCol->data = NULL;

    return newCol;
}

int insert_value(COLUMN* col, int value){
    int ret = 0;

    if(col->data == NULL){
        col->data = malloc(REALOC_SIZE);
        *col->data = value;

        col->taille_logique += 1;
        col->taille_physique += sizeof(int);

        ret = 1;
    }
    else if(col->taille_physique / REALOC_SIZE != 0){
        *(col->data + col->taille_physique) = value;

        col->taille_logique += 1;
        col->taille_physique += sizeof(int);

        ret = 1;
    }
    else{
        col->data = realloc(col->data, (REALOC_SIZE) + col->taille_physique);
        *(col->data + col->taille_physique) = value;

        col->taille_logique += 1;
        col->taille_physique += sizeof(int);

        ret = 1;
    }

    return ret;
}

void delete_column(COLUMN** col){
    free((*col)->title);
    (*col)->title = NULL;

    free((*col)->data);
    (*col)->data = NULL;

    (*col)->taille_physique = 0;
    (*col)->taille_logique = 0;

    free(*col);
    *col = NULL;
}

void print_col(COLUMN* col){
    printf("%s: %d, %d\n", col->title, col->taille_logique, col->taille_physique);

    if(col->taille_logique == 0){
        return;
    }

    for(int i = 0; i < col->taille_logique; i++){
        printf("[%d] %d\n", i, *(col->data + (i * sizeof(int))));
    }
}

void renameCol(COLUMN* col, char* new){
    free(col->title);
    col->title = NULL;

    col->title = strdup(new);
}