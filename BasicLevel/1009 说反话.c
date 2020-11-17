#include <stdio.h>
#include <string.h>

int main() {
    char sentence[81];
    gets(sentence);

    //scan and print
    for (int i = (int) strlen(sentence); i >= 0; i--) {
        //replace all space with \0
        if (sentence[i] == ' ') {
            sentence[i] = '\0';
            //输入保证句子末尾没有多余的空格
            //so i + 1 always be safe
            printf("%s ", &sentence[i + 1]);
        } else if (i == 0) {    //first word
            printf("%s", sentence);
        }
    }

    return 0;
}
