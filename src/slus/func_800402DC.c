#include "types.h"

extern void func_8003C5D8(void);
extern void func_8003AA4C(u8* arg0);
extern void func_80017248(u8* obj);
extern void (*D_80074D04[])(u8*);

void func_800402DC(u8* arg0) {
    if (((s8*)arg0)[0xD3] != 0) {
        arg0[0xF3] = 0;
        func_8003C5D8();
        func_8003AA4C(arg0);
    } else {
        func_80017248(arg0);
        D_80074D04[(s8)arg0[6]](arg0);
    }
}
