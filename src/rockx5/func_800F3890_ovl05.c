#include "types.h"

extern s16 D_800F5960_ovl05;
extern s16 D_800F5962_ovl05;
extern u8 D_800F5964_ovl05[];

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F3890_ovl05(u8* obj) {
    s32 y;

    if (D_800F5964_ovl05[1] != 0) {
        y = *(s16*)(obj + 0xA);
        if (y - 0x40 <= D_800F5960_ovl05 || y <= D_800F5962_ovl05 + 0x40) {
            func_80017248(obj);
            func_8002D9EC(obj, 0xA0, 0xA0);
            return;
        }
    }
    obj[3] = 0;
}
