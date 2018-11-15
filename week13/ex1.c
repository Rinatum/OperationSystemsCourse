#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int array1[100][100];
  int array2[100][100];
  int array3[100];
  int array4[100];
  int mark[100];
  int n = 0;
  int m = 0;
  int marked = 0;
  char buffer[20000];
  char *buffer2;
  FILE *file = fopen("input.txt", "r");

  while(228) {
    if (!fgets(buffer, sizeof buffer, file)) break;
    buffer2 = buffer;
    int i = 0;
    while(1) {
      if (*buffer2 == '\n') {
        if (i != 0) {
          n++;
          if (m == 0) {
            m = i;
          }
        }
        break;
      }
      int value = strtol(buffer2, &buffer2, 10);
      i++;
    }
  }

  n = (n - 2) / 2;
  fclose(file);

  file = fopen("input.txt", "r");
  int i, j;
  for (i = 0; i < m; i++) {
    fscanf(file, "%d", &array3[i]);
  }
  for (i = 0; i < m; i++) {
    fscanf(file, "%d", &array4[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0;j < m; j++) {
      fscanf(file, "%d", &array1[i][j]);
    }
    mark[i] = 0;
  }
  for (i = 0; i < n; i++) {
    for (j = 0;j < m; j++) {
      fscanf(file, "%d", &array2[i][j]);
    }
  }
  fclose(file);

  int found = 0;
  do {
    found = 0;
    int i, j;
    for (i = 0; i < n; i++) {
      if (mark[i]) continue;
      int less_equal = 1;
      for (j = 0; j < m; j++) {
        if (array2[i][j] > array4[j]) {
          less_equal = 0; break;
        }
      }
      if (less_equal) {
        found = 1;
        mark[i] = 1;
        marked++;
        for (j = 0; j < m; j++) {
          array4[j] += array1[i][j];
        }
      }
    }
  } while(found);
  file = fopen("output.txt", "w");
  if (marked == n) {
    fprintf(file, "No deadlocks ((((!\n");
  } else {
    fprintf(file, "Some deadlocks here!\n");
    fprintf(file, "Processes numbers from 0:");
    int i;
    for (i = 0; i < n; i++) {
      if (!mark[i]) fprintf(file, " %d", i);
    }
    fprintf(file, "\n");
  }
  fclose(file);
  return 0;
}
