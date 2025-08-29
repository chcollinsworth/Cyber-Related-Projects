#include <stdio.h>
#include <string.h>
/*
This code will need to take the ascii number of a letter and shift it by a particular number of letters. 
This can be achieved by creating a function that will take the index i in a string and adding a number called shift.
If a number overflows past Z it will need to be returned to A and then continue adding.
Capital letters will remain capitalized as well as lowercase being left lowercase.
Shift must be less than 26
 
Create a function that will shift the letter of a index of a string by an amount
*/
void ciphertext(int shift, char word[], int size){//This function will shift the letters of a plaintext string
    for(int i = 0; i < size; ++i){
        if((word[i] >= 65) && (word[i] <= 90)){//This checks if the letter is capitalized
            if((word[i] + shift) > 90){ //This checks if we have an overflow from the shift and to circle back to A
                word[i] = (word[i] + shift) - 26;
            } else {
                word[i] = word[i] + shift;
            }
        }   else if((word[i] >= 97) && (word[i] <= 122)){//Checks if the letter is lowercase
                if((word[i] + shift) > 122){
                    word[i] = (word[i] + shift) - 26;
                } else {
                    word[i] = word[i] + shift;
                }
            }
    }
}
int main(){
    char word[15];
    int shift = 3;

    printf("What is your plaintext: ");
    scanf("%s", &word);

    printf("\nHow much shift(less than 26): ");
    scanf("%d", &shift);

    ciphertext(shift, word, strlen(word));
    printf("The cipher text is %s", word);

    return 0;
}