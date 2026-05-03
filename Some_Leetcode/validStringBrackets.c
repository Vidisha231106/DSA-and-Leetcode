//678 

#include <string.h>

bool checkValidString(char* s) {
    int open_flag=0;
    int close_flag=0;
    int star=0;
    for (int i=0; i<strlen(s); i++){
        if (s[i]=='('){
            open_flag++;
            close_flag++;
        }
        else if (s[i]==')'){
            if (open_flag>0){
                open_flag--;
            }
            close_flag--;
        }
        else{
            if (open_flag>0){
                open_flag--;
            }
            close_flag++;
        }
        if (close_flag<0){
            return false;
        }
    }
    return (open_flag == 0);
}