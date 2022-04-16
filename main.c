#include <stdio.h>

char *strflt(char *dst, char *src){
  asm (".intel_syntax noprefix    \n\
        mov edx, edi              \n\
    ini:                          \n\
        mov al, [esi]             \n\
        cmp al, 48                \n\
        setge bl                  \n\
        cmp al, 57                \n\
        setle bh                  \n\
        test bh, bl               \n\
        jnz skip                  \n\
        mov [edi], al             \n\
        inc edi                   \n\
    skip:                         \n\
        inc esi                   \n\
        test al, al               \n\
        jnz ini                   \n\
        mov eax, edx              \n\
        .att_syntax prefix        \n"
        :
        : "D" (dst), "S" (src)
        :
    );
}

int main( ) {
  char *str = "1o50iee23";
  char str2[100];
  printf("%s", strflt(str2, str));
  return 0;
}
