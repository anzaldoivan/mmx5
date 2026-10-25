#include "types.h"

extern void func_8003A94C(void);
extern s32 func_8003EFE0(u8* arg0);
extern void func_80017248(u8* obj);
extern void (*D_80074CD8[])(u8*);

void func_80040260(u8* arg0) {
    if (((s8*)arg0)[0xD3] != 0) {
        func_8003A94C();
    } else if (func_8003EFE0(arg0) == 0) {
        func_80017248(arg0);
        D_80074CD8[(s8)arg0[6]](arg0);
    }
}
