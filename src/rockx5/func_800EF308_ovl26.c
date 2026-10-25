#include "types.h"

extern s32 func_8002D800(u8* a0);
extern void func_80028B18(s32, s32, s32, void*);
extern int func_8002D760();
extern s16 D_8009A206;
extern s16 D_8009A0AE;
extern s32 D_800E92F8;
extern s8 D_800D1C1D;

void func_800EF308_ovl26(u8* obj) {
    u8* p;
    s32 y;

    if (func_8002D800(obj) == 0) {
        p = *(u8**)(obj + 0x18);
        y = *(s16*)(p + 0xC);
        if (D_8009A206 < y) {
            return;
        }
        if (D_8009A0AE < y + 0x30) {
            return;
        }
        func_80028B18(0, *(s16*)(p + 0), *(s16*)(p + 2), p + 4);
        obj[4]++;
        if (((s8*)obj)[2] == 0) {
            D_800E92F8 = 1;
            D_800D1C1D = 1;
        }
    } else {
        func_8002D760(obj);
    }
}
