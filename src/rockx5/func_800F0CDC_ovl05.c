#include "types.h"

extern void func_800F103C_ovl05(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_800F0FFC_ovl05(u8* obj);
extern s32 func_8004FD24(u8* a0);
extern X4_Obj D_8009A0A0;

void func_800F0CDC_ovl05(u8* obj) {
    s32 v;

    func_800F103C_ovl05(obj);
    if (((D_8009A0A0.y_pos.i.hi - *(s16*)(obj + 0xE)) < 0
             ? (*(s16*)(obj + 0xE) - D_8009A0A0.y_pos.i.hi)
             : (D_8009A0A0.y_pos.i.hi - *(s16*)(obj + 0xE))) >= 3) {
        v = 0x20000;
        if (D_8009A0A0.y_pos.i.hi >= *(s16*)(obj + 0xE)) {
            v = 0xFFFD0000;
        }
        *(s32*)(obj + 0x24) = v | 0x8000;
    } else {
        *(s32*)(obj + 0x24) = 0;
    }
    if (((D_8009A0A0.x_pos.i.hi - *(s16*)(obj + 0xA)) < 0
             ? (*(s16*)(obj + 0xA) - D_8009A0A0.x_pos.i.hi)
             : (D_8009A0A0.x_pos.i.hi - *(s16*)(obj + 0xA))) < 0x11) {
        *(s32*)(obj + 0x24) = 0;
        obj[6]++;
    }
    func_8002DED4(obj);
    if (func_800F0FFC_ovl05(obj) != 0) {
        obj[3] = 0;
        func_8004FD24(obj);
        obj[4] = 2;
    }
}
