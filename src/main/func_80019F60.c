#include "types.h"

extern void (*D_80070B00[])(u8*);
extern u16 D_80070AD8[][2];

void func_80019F60(u8* p) {
    D_80070B00[*(s8*)(p + 5)](p);
    *(u16*)(p + 0xA) = D_80070AD8[*(s8*)(p + 2)][0];
    *(u16*)(p + 0xE) = D_80070AD8[*(s8*)(p + 2)][1];
}
