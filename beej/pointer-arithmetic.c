// https://www.beej.us/guide/bgc/html/split/pointers2.html#adding-to-pointers

#include <stdio.h>
#include <string.h>

int my_strlen(char *s) {
  char *p = s;
  while(*p != '\0') 
    p++;
  return p - s;
}

void *my_memcopy(void *dest, void *src, int byte_count) {
  char *s = src, *d = dest;

  while(byte_count--) {
    *d++ = *s++; 
  }
  
  return dest;
}

int main(void) {
  // 11.1 pointer arithmetic

  // int a[] = {11, 22, 33, 44, 55, 999}; // 999 is sentinal value
  // int *p = &a[0];

  // 11.1.1 adding to pointers

  // printf("%d %p\n", *p, p);
  // printf("%d %p\n", *(p + 1), p + 1);
  
  // for (int i = 0; i < 5; i++) {
  //   printf("%d %d %p", i, *(p + i), p + i);
  // }


  // 11.1.2 changing pointers
  // while (*p != 999) {
  //   printf("%d\n", *p);
  //   p++;
  // }
  

  // 11.1.3. subtracting pointers
  // printf("%d\n", my_strlen("Hello, world!"));

  // 11.2 array/pointer equivalence
  // a[b] == *(a + b)
  // E1[E2] is identical to (*((E1)+(E2)))

  // for (int i = 0; i < 5; i++)
  //   printf("%d\n", a[i]);

  // for (int i = 0; i < 5; i++)
  //   printf("%d\n", p[i]);

  // for (int i = 0; i < 5; i++)
  //   printf("%d\n", *(a + i));
   
  // for (int i = 0; i < 5; i++)
  //   printf("%d\n", *(p + i));

  // for (int i = 0; i < 5; i++)
  //   printf("%d\n", *(p++));
  //   printf("%d\n", *(a++));

  // 11.3 void pointers
  // char s[] = "Goats!";
  // char t[100];

  // memcpy(t, s, 7);

  // printf("%s\n", t);

  // int a[] = {11, 22, 33};
  // int b[3];

  // memcpy(b, a, 3 * sizeof(int));

  // printf("%d\n", b[1]);

  // 


  return 0;
}
