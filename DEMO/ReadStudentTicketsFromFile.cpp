#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ReadStudentTicketsFromFile(PQueue& qu, const char* fileName) {
	FILE* file;
	file = fopen(fileName, "r");
	if (file == NULL) {
		printf("Error opening file %s.\n", fileName);
		return;
	}

	int n;
	if (fscanf(file, "%d\n", &n) != 1) {
		printf("Error reading number of elements from file %s.\n", fileName);
		fclose(file);
		return;
	}

	for (int i = 0; i < n; i++) {
		ItemType x;
		char line[1024];
		if (fgets(line, sizeof(line), file) == NULL) {
			printf("Error reading line %d from file %s.\n", i + 1, fileName);
			continue;
		}
		char* token;
		token = strtok(line, "#");
		strncpy(x.Mssv, token, sizeof(x.Mssv) - 1);
		x.Mssv[sizeof(x.Mssv) - 1] = '\0';

		token = strtok(NULL, "#");
		strncpy(x.TenSV, token, sizeof(x.TenSV) - 1);
		x.TenSV[sizeof(x.TenSV) - 1] = '\0';

		token = strtok(NULL, "#");
		strncpy(x.Lop, token, sizeof(x.Lop) - 1);
		x.Lop[sizeof(x.Lop) - 1] = '\0';

		token = strtok(NULL, "#");
		strncpy(x.Ill, token, sizeof(x.Ill) - 1);
		x.Ill[sizeof(x.Ill) - 1] = '\0';

		token = strtok(NULL, "#");
		x.CV = atoi(token);

		token = strtok(NULL, "#");
		x.Tgian = atoi(token);

		PQueueNode* p = createPQueueNode(x);
		if (p == NULL) {
			printf("Error creating node for line %d.\n", i + 1);
			continue;
		}


		if (insert(qu, p) == 0) {
			printf("Error inserting node into priority queue for line %d.\n", i + 1);
		}
	}

	fclose(file);
}