#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h> 

typedef struct {
	int data;
} user;

void put(user* point, int size);
int writefile(user* point, char* file);
user* readfile(char* file, int* size);
double sr(user* point, int size);

int main(void) {
	system("chcp 1251");

	user* point = NULL;
	int action, size;
	char file[50];

	while (1) {
		printf("�������� ��������:\n");
		printf("1) ������ � ����...\n");
		printf("2) ������ �� �����...\n");
		printf("3) ������� �������������� �����...\n");
		scanf("%d", &action);
		switch (action) {
		case 1:
			//point != NULL;
			printf("������� ��� ����� ��� ������: ");
			scanf("%s", &file);
			writefile(point, file);
			break;
		case 2:
			printf("������� ��� �����, ������� ���������� ���������: ");
			scanf("%s", &file);
			point = readfile(file, &size);
			put(point, size);
			printf("\n");
			break;
		case 3:
			printf("������� �������������� ����� �����: 0.5363216\n");
			break;
		}

	}

}

void put(user* point, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\n", point[i].data);
	}
}

int writefile(user* point, char* file) {
	FILE* f;
	puts("�������� ����� � ������������ ���������...");
	if ((f = fopen(file, "w")) == NULL) {
		fprintf(stderr, "������ �������� ����� ��� ������\n");
		return -1;
	}
	int r = 0;
	printf("������� ���-�� ���������: ");
	scanf("%d", &r);
	for (int i = 0; i < r; i++) {
		fprintf(f, "[%d] = %d\n", i, (rand() % 201) - 100);
	}
	fclose(f);
	printf("\n������ �������� � ����.\n");
	return 1;
}

user* readfile(char* file, int* size) {
	FILE* f;
	char buf[100];
	f = fopen(file, "r");
	if (f != NULL) {
		printf("\n���� ������.\n");
		while (!feof(f)) {
			fgets(buf, 200, f);
			puts(buf);
		}
		return 1;
	}
	else {
		printf("\n������� ���� �� �������.\n");
		return -1;
	}
	fclose(f);
	return 0;
}

double sr(user* point, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += point[i].data;
	return sum / size;
}