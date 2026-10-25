#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8003C5D8(u8* obj);
extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];
extern u8 D_800D1C4B;
extern u8 D_8007C370[];

void func_80055D24(u8* obj) {
    u8* player = D_8009A0A0;

    *(s32*)(player + 8) = *(s32*)(obj + 8);
    player[0xF5] = 4;
    func_800171E8(obj, 0xD);
    if (((s8*)obj)[2] == 8) {
        if (((s8*)player)[2] == 0) {
            D_800D1C4B = 1;
        } else {
            D_800D1C00[0x4A] |= 0x10;
            func_8003C5D8(player);
        }
    } else {
        D_800D1C00[0xA1] |= D_8007C370[((s8*)obj)[2]];
    }
    obj[5]++;
}
