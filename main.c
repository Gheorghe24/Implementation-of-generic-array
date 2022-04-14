#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include <inttypes.h>
#define word_len 256
void print(void *arr, int len);
int add_last(void **arr, int *len, data_structure *data)
{
	int len_arr = 0;
	void *tmp = (void *)malloc(sizeof(unsigned char) + sizeof(unsigned int) + data->header->len);
	memcpy(tmp, &data->header->type, sizeof(unsigned char));
	len_arr = len_arr + sizeof(unsigned char);
	memcpy(tmp + len_arr, &data->header->len, sizeof(unsigned int));
	len_arr = len_arr + sizeof(unsigned int);
	memcpy(tmp + len_arr, data->data, data->header->len);
	len_arr = len_arr + data->header->len;
	if (*arr == NULL)
	{
		*arr = (void *)malloc(len_arr);
		memcpy(*arr, tmp, len_arr);
	}
	else
	{
		int arr_lenght = 0;
		void *aux = *arr;
		for (int i = 0; i < *len; i++)
		{
			arr_lenght = arr_lenght + sizeof(unsigned char);
			aux += sizeof(unsigned char);
			arr_lenght += sizeof(unsigned int) + *(unsigned int *)aux;
			aux += sizeof(unsigned int) + *(unsigned int *)aux;
		}
		*arr = (void *)realloc(*arr, arr_lenght + len_arr);
		memcpy(*arr + arr_lenght, tmp, len_arr);
	}
	(*len) += 1;
	free(tmp);
	return 0;
}

int add_at(void **arr, int *len, data_structure *data, int index)
{
	if (index < 0)
		return -1;
	if (index >= *len)
	{
		add_last(arr, len, data);
	} else {
		void *aux = *arr;
		int total_len = 0, len1 = 0;
		void *aux2 = NULL;
		for (int i = 0; i < *len; i++)
		{
			if (i == index)
			{
				len1 = total_len;
			}
			total_len = total_len + sizeof(unsigned char);
			aux += sizeof(unsigned char);
			total_len += sizeof(unsigned int) + *(unsigned int *)aux;
			aux += sizeof(unsigned int) + *(unsigned int *)aux;
		}
		int len_arr = 0;
		void *tmp = (void *)malloc(sizeof(unsigned char) + sizeof(unsigned int) + data->header->len);
		memcpy(tmp, &data->header->type, sizeof(unsigned char));
		len_arr = len_arr + sizeof(unsigned char);
		memcpy(tmp + len_arr, &data->header->len, sizeof(unsigned int));
		len_arr = len_arr + sizeof(unsigned int);
		memcpy(tmp + len_arr, data->data, data->header->len);
		len_arr = len_arr + data->header->len;
		//realoc memorie
		*arr = (void*) realloc(*arr, total_len + len_arr);
		aux2 = *arr + len1;
		// mut pointerii
		memmove(aux2 + len_arr, aux2, total_len - len1);
		memmove(aux2, tmp, len_arr);
		free(tmp); 
		(*len) += 1;
	}
	return 0;
}

void find(void *data_block, int len, int index)
{
	void *aux = data_block;
	if (index < 0 || index > len)
	{
		return;
	} else {
		for (int i = 0; i < index; i++)
		{
			aux += sizeof(unsigned char);
			aux += sizeof(unsigned int) + *(unsigned int *)aux;
		}
		// am ajuns la index
		print(aux, 1);
	}
}

int delete_at(void **arr, int *len, int index)
{
	void *aux = *arr;
	int total_len = 0, len1 = 0;
	void *aux2 = NULL;
	for (int i = 0; i < *len; i++)
	{
		if (i == index)
		{
			len1 = total_len;
			aux2 = aux;
		}
		total_len = total_len + sizeof(unsigned char);
		aux += sizeof(unsigned char);
		total_len += sizeof(unsigned int) + *(unsigned int *)aux;
		aux += sizeof(unsigned int) + *(unsigned int *)aux;
	}
	// mut aux2 la finalul lui index
	int len_aux = 0;
	len_aux = len_aux + sizeof(unsigned char);
	aux2 += sizeof(unsigned char);
	len_aux += sizeof(unsigned int) + *(unsigned int *)aux2;
	aux2 += sizeof(unsigned int) + *(unsigned int *)aux2;
	// mut pointerii
	memcpy(*arr + len1, *arr + len1 + len_aux, total_len - len1 - len_aux);
	*arr = (void *)realloc(*arr, total_len - len_aux);
	*len -= 1;
	return 0;
}

void print(void *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		{
			unsigned char type = *(unsigned char *)arr;
			printf("Tipul %c\n", type);
			arr += sizeof(unsigned char) + sizeof(unsigned int);
			printf("%s pentru ", (char *)arr);
			arr += strlen((char *)arr) + 1;
			if (type == 49)
			{
				printf("%s\n", (char *)(arr + sizeof(int16_t)));
				printf("%" PRId8 "\n", *(int8_t *)arr);
				arr += sizeof(int8_t);
				printf("%" PRId8 "\n", *(int8_t *)arr);
				arr += sizeof(int8_t);
			}
			if ((type) == 50)
			{
				printf("%s\n", (char *)(arr + sizeof(int16_t) + sizeof(int32_t)));
				printf("%" PRId16 "\n", *(int16_t *)arr);
				arr += sizeof(int16_t);
				printf("%" PRId32 "\n", *(int32_t *)arr);
				arr += sizeof(int32_t);
			}
			if ((type) == 51)
			{
				printf("%s\n", (char *)(arr + sizeof(int64_t)));
				printf("%" PRId32 "\n", *(int32_t *)arr);
				arr += sizeof(int32_t);
				printf("%" PRId32 "\n", *(int32_t *)arr);
				arr += sizeof(int32_t);
			}
			arr += strlen((char *)arr) + 1;
			printf("\n");
		}
	}
}

int main()
{
	// the vector of bytes u have to work with
	// good luck :)
	void *arr = NULL;
	int len = 0;
	unsigned int len_date = 0;
	char *cmd = malloc(word_len);
	char *dedicator = malloc(word_len);
	char *dedicatul = malloc(word_len);
	char *type = malloc(2);
	data_structure *date = (data_structure *)malloc(sizeof(data_structure));
	date->header = (head *)malloc(sizeof(head));
	scanf("%s", cmd);

	while (strcmp(cmd, "exit"))
	{
		if (strcmp(cmd, "insert") == 0)
		{
			scanf("%s %s", type, dedicator);
			memcpy(&date->header->type, type, sizeof(unsigned char));
			len_date = strlen(dedicator) + 1;
			date->data = malloc(len_date);
			memcpy(date->data, dedicator, len_date);
			if (strcmp(type, "1") == 0)
			{
				date->data = realloc(date->data, 2 * sizeof(int8_t) + len_date);
				int8_t sum81 = 0, sum82 = 0;
				scanf("%hhd %hhd", &sum81, &sum82);
				memcpy(date->data + len_date, &sum81, sizeof(sum81));
				memcpy(date->data + len_date + sizeof(int8_t), &sum82, sizeof(int8_t));
				len_date += 2 * sizeof(int8_t);
			}
			else if (strcmp(type, "2") == 0)
			{
				date->data = realloc(date->data, sizeof(int16_t) + sizeof(int32_t) + len_date);
				int16_t sum161 = 0;
				int32_t sum162 = 0;
				scanf("%hd %d", &sum161, &sum162);
				memcpy(date->data + len_date, &sum161, sizeof(sum161));
				memcpy(date->data + len_date + sizeof(sum161), &sum162, sizeof(sum162));
				len_date += sizeof(int16_t) + sizeof(int32_t);
			}
			else if (strcmp(type, "3") == 0)
			{
				date->data = realloc(date->data, 2 * sizeof(int32_t) + len_date);
				int32_t sum31 = 0, sum32 = 0;
				scanf("%d %d", &sum31, &sum32);
				memcpy(date->data + len_date, &sum31, sizeof(sum31));
				memcpy(date->data + len_date + sizeof(sum31), &sum32, sizeof(sum32));
				len_date += 2 * sizeof(int32_t);
			}
			scanf("%s", dedicatul);
			date->data = realloc(date->data, strlen(dedicatul) + 1 + len_date);
			memcpy(date->data + len_date, dedicatul, strlen(dedicatul) + 1);
			len_date += (strlen(dedicatul) + 1);
			date->header->len = len_date;
			add_last(&arr, &len, date);
			free(date->data);
		}
		else if (!strcmp(cmd, "insert_at"))
		{
			int i = 0;
			scanf("%d", &i);
			// acelasi insert
			scanf("%s %s", type, dedicator);
			memcpy(&date->header->type, type, sizeof(unsigned char));
			len_date = strlen(dedicator) + 1;
			date->data = malloc(len_date);
			memcpy(date->data, dedicator, len_date);
			if (strcmp(type, "1") == 0)
			{
				date->data = realloc(date->data, 2 * sizeof(int8_t) + len_date);
				int8_t sum81 = 0, sum82 = 0;
				scanf("%hhd %hhd", &sum81, &sum82);
				memcpy(date->data + len_date, &sum81, sizeof(sum81));
				memcpy(date->data + len_date + sizeof(int8_t), &sum82, sizeof(int8_t));
				len_date += 2 * sizeof(int8_t);
			}
			else if (strcmp(type, "2") == 0)
			{
				date->data = realloc(date->data, sizeof(int16_t) + sizeof(int32_t) + len_date);
				int16_t sum161 = 0;
				int32_t sum162 = 0;
				scanf("%hd %d", &sum161, &sum162);
				memcpy(date->data + len_date, &sum161, sizeof(sum161));
				memcpy(date->data + len_date + sizeof(sum161), &sum162, sizeof(sum162));
				len_date += sizeof(int16_t) + sizeof(int32_t);
			}
			else if (strcmp(type, "3") == 0)
			{
				date->data = realloc(date->data, 2 * sizeof(int32_t) + len_date);
				int32_t sum31 = 0, sum32 = 0;
				scanf("%d %d", &sum31, &sum32);
				memcpy(date->data + len_date, &sum31, sizeof(sum31));
				memcpy(date->data + len_date + sizeof(sum31), &sum32, sizeof(sum32));
				len_date += 2 * sizeof(int32_t);
			}
			scanf("%s", dedicatul);
			date->data = realloc(date->data, strlen(dedicatul) + 1 + len_date);
			memcpy(date->data + len_date, dedicatul, strlen(dedicatul) + 1);
			len_date += (strlen(dedicatul) + 1);
			date->header->len = len_date;
			add_at(&arr, &len, date, i);
			free(date->data);
		}
		else if (!strcmp(cmd, "delete_at"))
		{
			int i = 0;
			scanf("%d", &i);
			delete_at(&arr, &len, i);
		}
		else if (!strcmp(cmd, "find"))
		{
			int i = 0;
			scanf("%d", &i);
			find(arr, len, i);
		}
		else if (!strcmp(cmd, "print"))
		{
			print(arr, len);
		}
		scanf("%s", cmd);
	}
	// alocari
	free(type);
	free(cmd);
	free(dedicatul);
	free(dedicator);
	free(date->header);
	free(date);
	free(arr);
	return 0;
}
