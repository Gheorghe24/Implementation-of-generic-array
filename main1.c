#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include <inttypes.h>
#define word_len 256
int add_last(void **arr, int *len, data_structure *data)
{

// 	for(int i = 0;i < *len; i++) {
// //
// 	}
	
	return 0; // daca totul e bine
}

int add_at(void **arr, int *len, data_structure *data, int index)
{
	if(index < 0) 
	return -1;
	if(index > *len) {
		//adaugam la final
	}
	return 0;
}

void find(void *data_block, int len, int index) 
{
	if(index < 0 || index > len) {
		return;
	} else {
		// printf("");
		// valoarea de la indexul respectiv
	}
}


int delete_at(void **arr, int *len, int index)
{
	// mutam bitii ramasi in locul elementului scos
	return 0;
}

void print(void *arr, int len) {
	if(arr!=NULL) {
		// printf("Tipul %d");
		// printf("%s pentru %s");
		// printf("%"PRId8"\n", val)   //unde val este un int8_t
		// printf("%"PRId16"\n", val)  //unde val este un int16_t
		// printf("%"PRId32"\n", val)  //unde val este un int32_t
	}
}

int main() {
	// the vector of bytes u have to work with
	// good luck :)
	void *arr = NULL;
	int len = 0;
  char * cmd = malloc(word_len);
  char * dedicator = malloc(word_len);
  char * dedicatul = malloc(word_len);
  char * type = malloc(2);
  int sum1 = 0, sum2 = 0;
  data_structure *date = (data_structure*) malloc(sizeof(data_structure));
  date->header = (head*)malloc(sizeof(head));
  scanf("%s", cmd);

  while (strcmp(cmd, "exit")) {
    if (strcmp(cmd, "insert") == 0) {
		scanf("%s %s %d %d %s",type, dedicator, &sum1, &sum2, dedicatul);
		 date->header->len = len;
		 date->header->type = (unsigned char)type;
		if(strcmp(type, "1") == 0) {
			date->data = malloc(sizeof(dedicator) + sizeof(dedicatul) + 2*sizeof(int16_t));
		} else if(strcmp(type, "2") == 0) {
			date->data = malloc(sizeof(dedicator) + sizeof(dedicatul) + sizeof(int16_t) + sizeof(int32_t));
		} else if(strcmp(type, "3") == 0) {
			date->data = malloc(sizeof(dedicator) + sizeof(dedicatul) + sizeof(int32_t) + sizeof(int32_t));
		}
		
    } else if (!strcmp(cmd, "insert_at index")) {
		scanf("%s %s %d %d %s",type, dedicator, &sum1, &sum2, dedicatul);
		int ceva1 = add_at(&arr, &len, date, ceva1);
    } else if (!strcmp(cmd, "delete_at index")) {
      	int ceva1 = delete_at(&arr, &len, ceva1);
    } else if (!strcmp(cmd, "find index")) {
      	find(arr, len, sum1);
    } else if (!strcmp(cmd, "print")) {
      	//
    } 
    scanf("%s", cmd);
  }
  // alocari
  free(type);
  free(cmd);
  free(dedicatul);
  free(dedicator);

	return 0;
}
