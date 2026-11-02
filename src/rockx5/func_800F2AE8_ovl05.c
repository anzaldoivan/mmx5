#include "types.h"

extern s32 func_8002FB58(u8* obj);
extern s32 func_800F29B4_ovl05(s16 x, s16 y);
extern u8 D_8009A0A0[];

void func_800F2AE8_ovl05(void) {
    u8* base = D_8009A0A0;
    u8* box = *(u8**)(base + 0x68);
    s16 x;
    s16 y;

    if (box != 0) {
        func_8002FB58(base);
        *(s32*)(base + 0x18) = *(s32*)(base + 0x8);
        *(s32*)(base + 0x1C) = *(s32*)(base + 0xC);
        x = *(s16*)(base + 0xA) + ((s8*)box)[0];
        y = *(s16*)(base + 0xE) + ((s8*)box)[1];
        if (func_800F29B4_ovl05(x - box[2] + 1, y - box[3] + 1) == 0 &&
            func_800F29B4_ovl05(box[2] + x - 1, y - box[3] + 1) == 0 &&
            func_800F29B4_ovl05(x - box[2] + 1, box[3] + y - 1) == 0) {
            func_800F29B4_ovl05(box[2] + x - 1, box[3] + y - 1);
        }
    }
}
