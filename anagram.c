#include <string.h>
#include <ctype.h>
#define SIZE 256

int is_anagram(const char *test, const char *original) {
    int tlen = (int) strlen(test);
    int olen = (int) strlen(original);
    int map1[SIZE] = {0};
    int map2[SIZE] = {0};
  
  if(tlen != olen) return 0;
  
    int i = 0;
    while(i < tlen) {
        
        map1[(int) tolower(test[i])] = 1;
        map2[(int) tolower(original[i])] = 1;
        
      i++;
    }
    
    int j = 0;
    while(j < SIZE) {
        if(map1[j] != map2[j]) return 0;
        j++;
    }
    return 1;
}

