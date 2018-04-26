#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char * a1=NULL;
    char * a2=NULL;
    a1=(char*)malloc(3*sizeof(char));
    strcpy(a1, "abc");//½«×Ö·û´®¡°abc¡±¸´ÖÆ¸øa1
    a2=(char*)malloc(3*sizeof(char));
    strcpy(a2, "defg");
    int lengthA1=strlen(a1);
	int lengthA2=strlen(a2);
	printf("%d,%d\n",lengthA1,lengthA2);
    if (lengthA1<lengthA1+lengthA2) {
        a1=(char*)realloc(a1, (lengthA1+lengthA2)*sizeof(char));
    }
    for (int i=lengthA1; i<lengthA1+lengthA2; i++) {
        a1[i]=a2[i-lengthA1];
    }
    printf("%s",a1);
    /*free(a1);
    free(a2);*/
    return 0;
}