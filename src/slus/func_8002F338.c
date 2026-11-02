#include "types.h"

extern s16 D_800E931E;
extern s16 D_800E9328[][4];
extern u8 D_800C6A10[];

void func_8002F338(void) {
    u8* obj;
    u8* box;
    u8* row;
    s32 i;
    s16 x;
    s16 y;
    s32 n;

    D_800E931E = 0;
    for (i = 0; i < 64; i++) {
        obj = D_800C6A10 + i * 0xA4;
        if (*(s8*)(obj + 0) != 0 && *(s8*)(obj + 0xA2) != 0 &&
            *(u8**)(obj + 0x68) != 0) {
            if (obj[0x15] == 0x40) {
                x = *(u16*)(obj + 0xA) - *(s8*)*(u8**)(obj + 0x68);
            } else {
                x = *(u16*)(obj + 0xA) + *(s8*)*(u8**)(obj + 0x68);
            }
            row = D_800C6A10 + i * 0xA4;
            box = *(u8**)(row + 0x68);
            n = D_800E931E;
            D_800E9328[n][0] = x - box[2];
            D_800E9328[n][1] = box[2] + x - 1;
            y = *(u16*)(obj + 0xE) + *(s8*)(box + 1);
            D_800E9328[n][2] = y - box[3];
            D_800E9328[n][3] = box[3] + y - 1;
            D_800E931E++;
        }
    }
}
