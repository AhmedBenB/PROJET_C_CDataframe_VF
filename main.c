#include <stdio.h>
#include "CDataframe.h"
#include "list.h"

int main() {
    COLUMN *mycol = create_column("COL_0");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);

    COLUMN *mycol1 = create_column("COL_1");
    insert_value(mycol1, 46);
    insert_value(mycol1, 97);
    insert_value(mycol1, 28);

    COLUMN *mycol2 = create_column("COL_2");
    insert_value(mycol2, 34);
    insert_value(mycol2, 19);
    insert_value(mycol2, 76);

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
