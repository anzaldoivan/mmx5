#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void (*D_800FE34C_ovl28[])(u8*);

void func_800F6F64_ovl28(u8* obj) {
    u8* p;

    p = *(u8**)(obj + 0x50);
    D_800FE34C_ovl28[((signed char*)obj)[6]](obj);
    if (func_8002D938(obj, 0x60, 0x60) == 0) {
        if (((signed char*)obj)[3] != 0) {
            func_8002D9EC(obj, 0x20, 0x20);
        }
    } else {
        obj[4]++;
    }
    if (((signed char*)p)[4] == 2) {
        obj[4]++;
    }
}
