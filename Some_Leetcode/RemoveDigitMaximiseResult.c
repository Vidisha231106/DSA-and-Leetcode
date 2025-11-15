//2259. Remove a digit to maximise result

#include <string.h>
#include <stdlib.h>
#include <math.h>

char* removeDigit(char* number, char digit) {
    char * answer = (char*) malloc((strlen(number) + 1) * sizeof(char));
    int index=0;   
    for (int i = 0; i < strlen(number); i++) {
        if (number[i] == digit) {
            index = i; 
            if (i < strlen(number) - 1 && number[i] < number[i + 1]) {
                break;
            }
        }
    }
    int answer_index=0;
    for (int i=0; i<strlen(number); i++){
        if (index==i) continue;
        answer[answer_index]=number[i];
        answer_index++;
    }
    answer[answer_index]='\0';
    return answer;
}
