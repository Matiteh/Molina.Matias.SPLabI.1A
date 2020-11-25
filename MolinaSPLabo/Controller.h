int controller_loadFromText(char* path , LinkedList* pArrayListeBicicleta);
int controller_loadFromBinary(char* path , LinkedList* pArrayListeBicicleta,int* idMax, char* pId);
int controller_addeBicicleta(LinkedList* pArrayListeBicicleta, int* idMax);
int controller_editeBicicleta(LinkedList* pArrayListeBicicleta);
int controller_removeeBicicleta(LinkedList* pArrayListeBicicleta);
int controller_ListeBicicleta(LinkedList* pArrayListeBicicleta);
int controller_sorteBicicleta(LinkedList* pArrayListeBicicleta);
int controller_saveAsText(char* path , LinkedList* pArrayListeBicicleta);
int controller_saveAsBinary(char* path , LinkedList* pArrayListeBicicleta,int* idMax, char* pId);
void controller_setTiempo(LinkedList* pArrayListeBicicleta);
void controller_filtroTipo (LinkedList* pArrayListeBicicleta);

