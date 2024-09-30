#include <stdio.h>

int main(void) {
  FILE *fp;

  //fp = fopen("hello.txt", "r");

  // Ex 1. get single char
  //int c = fgetc(fp);
  //printf("%c\n", c);

  // Ex 2. loop and read each char until EOF
  //int c;

  //while((c = fgetc(fp)) != EOF)
    //printf("%c", c);


  // Ex 3. read file one line at at time
  // char s[1024];
  // int linecount = 0;

  // fp = fopen("quote.txt", "r");
  
  // while (fgets(s, sizeof s, fp) != NULL)
    // printf("%d: %s", ++linecount, s);


  // Ex 4. formatted input
  char name[1024];
  float length;
  int mass;

  fp = fopen("whales.txt", "r");

  while(fscanf(fp, "%s %f %d", name, &length, &mass) != EOF)
    printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);


  fclose(fp);

  return 0;
}
