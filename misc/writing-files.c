#include <stdio.h>

int main() {
  
  // Ex 1. writing chars and strings into file
  FILE *fp;
  int x = 32;

  fp = fopen("output.txt", "w");

  fputc('B', fp);
  fputc('\n', fp);
  fprintf(fp, "x = %d\n", x);
  fputs("Hello world!\n", fp);

  fclose(fp);


  // Ex 2. writing binary files
  FILE *fp2;
  unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};
  unsigned char c;

  fp2 = fopen("output.bin", "wb");

  // write to the binary file
  fwrite(bytes, sizeof(char), 6, fp2);

  fclose(fp2);

  // read the binary file we just wrote to
  fp2 = fopen("output.bin", "rb");

  while(fread(&c, sizeof(char), 1, fp2) > 0)
    printf("%d\n", c);

  fclose(fp2);

  return 0;
}

