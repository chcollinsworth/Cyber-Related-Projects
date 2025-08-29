#include <stdio.h>
#include <string.h>
//password contains the password, size contains the size of the password, lower contains
//the ascii number for the lower end of the range, the upper contains the ascii number for the upper
//end of the range, and amount is the amount of that digit
int checktype(char password[], int size, int lower, int upper, int range){
    int counter = 0;
    int output = 0;
    for(int i = 0; i < size; ++i){
         if((password[i] <= upper) && (password[i]>= lower)){
            counter++;
         }
    }
    if(counter >= range){
        output = 1;
    }
    return output;
}
int checkpassword(char password[], int size){
    int output = 0;
if(checktype(password, size, 97,122, 8) && checktype(password, size, 65,90,1) && checktype(password, size, 48,57,1) && checktype(password, size, 33,47,1)){
    output = 1;
}
    return output;
}
int main(){
    char password[50];
    int check = 100;
    printf("What is your password: ");
    scanf("%s", &password);
    int output = checkpassword(password, sizeof(password));
    if(output == 1){
        printf("Your password is strong");
    } else {
        printf("Your password is weak");
    }
    return 0;
}