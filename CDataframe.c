#include "CDATAFRAME.h"
#include "list.h"
CDATAFRAME *createEmptyCDATAFRAME(char* title){
    CDATAFRAME *newcdf = malloc(sizeof(CDATAFRAME));

    newcdf->title = title;
    newcdf->data = lst_create_list();

    newcdf->numCols = 0;
    newcdf->numRows = 0;

    return newcdf;
}

int insertColumn(CDATAFRAME* cdf, COLUMN* col){
    if(cdf->numRows != 0 && col->taille_logique != cdf->numRows){
        return 0;
    }
    else{
        cdf->numCols += 1;
        cdf->numRows = col->taille_logique;
    }

    lnode* node = lst_create_lnode(col);
    lst_insert_tail(cdf->data, node);

    return 1;
}

void printDataframe(CDATAFRAME* cdf){
    printf("%s:\n    ", cdf->title);
    lnode* node = get_first_node(cdf->data);

    for(int j = 0; j < cdf->numCols; j++){
        COLUMN* temp = node->data;

        printf("%s ", temp->title);
        node = get_next_node(cdf->data, node);
    }
    printf("\n");

    node = get_first_node(cdf->data);
    for(int i = 0; i < cdf->numRows; i++){
        printf("[%d] ", i);
        for(int j = 0; j < cdf->numCols; j++){
            COLUMN* temp = node->data;

            printf("%d ", *(temp->data + sizeof(int) * i));
            node = get_next_node(cdf->data, node);
        }
        printf("\n");
        node = get_first_node(cdf->data);
    }
}

void renameColumn(CDATAFRAME* df, char* newName, int col){
    if(col >= df->numCols){
        return;
    }

    lnode* node = get_first_node(df->data);
    COLUMN* temp = node->data;

    for(int i = 0; i < df->numCols; i++){
        if(i == col){
            renameCol(temp, newName);
        }

        node = get_next_node(df->data, node);
        if(node){
            temp = node->data;
        }
    }
}