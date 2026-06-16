#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 300
#define MAX_WORD_LEN 20

char* mostCommonWord(char *para, char **ban, int size) {
    static char result[MAX_WORD_LEN]; 
    char words[MAX_WORDS][MAX_WORD_LEN];
    int counts[MAX_WORDS] = {0};
    int total_words = 0;
    char *token = strtok(para, " !?',;.");
    
    while (token != NULL) {
        for (int i = 0; token[i] != '\0'; i++) {
            token[i] = tolower((unsigned char)token[i]);
        }
        bool banned = false;
        for (int i = 0; i < size; i++) {
            if (strcmp(token, ban[i]) == 0) {
                banned = true;
                break;
            }
        }
        if (!banned) {
            bool found = false;
            for (int j = 0; j < total_words; j++) {
                if (strcmp(words[j], token) == 0) {
                    counts[j]++;
                    found = true;
                    break;
                }
            }
            
            if (!found && total_words < MAX_WORDS) {
                strcpy(words[total_words], token);
                counts[total_words] = 1;
                total_words++;
            }
        }
        
        token = strtok(NULL, " !?',;."); 
    }
    int max_count = 0;
    int max_index = 0;
    for (int i = 0; i < total_words; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            max_index = i;
        }
    }

    strcpy(result, words[max_index]);
    return result; 
}
