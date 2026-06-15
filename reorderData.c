#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b)
{
    char *log1 = *(char **)a;
    char *log2 = *(char **)b;

    char *content1 = strchr(log1, ' ') + 1;
    char *content2 = strchr(log2, ' ') + 1;

    int res = strcmp(content1, content2);

    if(res == 0)
    {
        char id1[100], id2[100];

        sscanf(log1, "%s", id1);
        sscanf(log2, "%s", id2);

        return strcmp(id1, id2);
    }

    return res;
}


int isDigitLog(char *log)
{
    char *word = strchr(log, ' ') + 1;

    return isdigit(word[0]);
}


char** reorderLogFiles(char** logs, int logsSize, int* returnSize)
{
    char **answer = malloc(sizeof(char*) * logsSize);

    int index = 0;


    // Add letter logs
    for(int i = 0; i < logsSize; i++)
    {
        if(!isDigitLog(logs[i]))
        {
            answer[index++] = logs[i];
        }
    }

    qsort(answer, index, sizeof(char*), compare);

    for(int i = 0; i < logsSize; i++)
    {
        if(isDigitLog(logs[i]))
        {
            answer[index++] = logs[i];
        }
    }


    *returnSize = logsSize;

    return answer;
}
