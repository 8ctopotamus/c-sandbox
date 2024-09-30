// https://www.beej.us/guide/bgc/html/split/pointers2.html#adding-to-pointers

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct animal {
  char *name;
  int leg_count;
};

int compar(const void *elem1, const void *elem2) {
  const struct animal *animal1 = elem1;
  const struct animal *animal2 = elem2;

  if (animal1->leg_count > animal2->leg_count)
    return 1;
  
  if (animal1->leg_count < animal2->leg_count)
    return -1;
  
  return 0;
}

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

  // sorting structs - qsort example 
  struct animal a[4] = {
    {.name="Dog", .leg_count=4},
    {.name="Monkey", .leg_count=2},
    {.name="Antelope", .leg_count=4},
    {.name="Snake", .leg_count=0},
  };

  qsort(a, 4, sizeof(struct animal), compar);

  for (int i = 0; i < 4; i++)
    printf("%d: %s\n", a[i].leg_count, a[i].name);

  return 0;
}
