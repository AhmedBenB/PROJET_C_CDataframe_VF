
#ifndef UNTITLED1_F_H
#define UNTITLED1_F_H
#include "column.h"
#include "list.h"

typedef struct CDATAFRAME {
    char* title;
    list* data;
    int numCols;
    int numRows;
}CDATAFRAME;


/**
* @brief : Create an empty dataframe
* @param1 : Dataframe title
* @return : Pointer to created dataframe
*/
CDATAFRAME *createEmptyCDataframe(char* title);

/**
* @brief : Create a dataframe from user matrix
* @param1 : Dataframe title
* @param2 : User matrix
* @return : Pointer to created dataframe
*/
CDATAFRAME *createCDataframe(char* title, int** data);

/**
* @brief : Insert column in dataframe
* @param1 : Dataframe
* @param2 : Column
* @return : 0 if failed, 1 if succeeded
*/
int insertColumn(CDATAFRAME* cdf, COLUMN* col);

/**
* @brief : Insert row in dataframe
* @param1 : Dataframe
* @param2 : Row
* @param3 : Size of the row
* @return : 0 if failed, 1 if succeeded
*/
int insertRow(CDATAFRAME* cdf, int* row, int size);

/**
* @brief : Delete dataframe
* @param1 : Dataframe
*/
void deleteDataframe(CDATAFRAME** cdf);

/**
* @brief : Delete column in dataframe
* @param1 : Dataframe
* @param2 : Column index
*/
void deleteColumn(CDATAFRAME* cdf, int col);

/**
* @brief : Delete row in dataframe
* @param1 : Dataframe
* @param2 : Row index
*/
void deleteRow(CDATAFRAME* cdf, int row);

/**
* @brief : Print dataframe
* @param1 : Dataframe
*/
void printCDataframe(CDATAFRAME* cdf);

/**
* @brief : Rename column in dataframe
* @param1 : Dataframe
* @param2 : New column name
* @param3 : Column index
*/
void renameColumn(CDATAFRAME* cdf, char* newName, int col);

#endif //UNTITLED1_F_H