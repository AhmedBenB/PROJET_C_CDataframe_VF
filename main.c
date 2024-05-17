#include <stdio.h>
#include "CDataframe.h"
#include "list.h"

int main() {
    COLUMN *mycol = create_column("COL_0");
    insert_value(mycol, 12);
    insert_value(mycol, 86);
    insert_value(mycol, 23);

    COLUMN *mycol1 = create_column("COL_1");
    insert_value(mycol1, 98);
    insert_value(mycol1, 03);
    insert_value(mycol1, 45);

    COLUMN *mycol2 = create_column("COL_2");
    insert_value(mycol2, 75);
    insert_value(mycol2, 48);
    insert_value(mycol2, 36);

    /**CDATAFRAME* cdf = createEmptyCDataframe("myDataFrame");
    insertColumn(cdf, mycol);
    insertColumn(cdf, mycol1);
    insertColumn(cdf, mycol2);
    printCDataframe(cdf);

    renameColumn(cdf, "newCol1", 1);

    printCDataframe(cdf);

    deleteDataframe(&cdf);**/
    
    return 0;
}
