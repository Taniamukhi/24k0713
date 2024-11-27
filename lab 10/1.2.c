#include <stdio.h>
#include <string.h>
void reversestring(char s1[], int first, int last);

int main() {
    char str[30] = "tania";
    reversestring(str, 0, strlen(str) - 1);
    printf("Reversed string: %s\n", str);
    return 0;
}
void reversestring(char s1[], int first, int last)
{
    if (first >= last)
	 {
        return;
    }
    char tem = s1[first];
    s1[first] = s1[last];
    s1[last] = tem;
    reversestring(s1, first+1, last-1);
}
