#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DataNode structure using typedef
typedef struct DataNode {
    char* data;
    struct DataNode* next;
} DataNode;

DataNode* createDataNode(char* data);

int main() {
  char data[101];
  scanf("%[^\n]s", data);

  DataNode* pNew = createDataNode(data);

  printf("%s\n", pNew->data);
  printf("%p\n", (void*)pNew->next);

  return 0;
}

// Create a new DataNode
DataNode* createDataNode(char* data) {
    unsigned int string_size = strlen(data);
    char *text = (char*)malloc(sizeof(char)*string_size);
    strcpy(text, data);
    DataNode *pNew = (DataNode*)malloc((sizeof(DataNode)));
    pNew->data = text; //*(pNew).data = text
    pNew->next = NULL;
    
    return pNew;
}