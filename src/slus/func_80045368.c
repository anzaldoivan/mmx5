#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_80076E34[];
extern u8 D_80076E38[];
extern u8 D_80076E4C[];
extern u32* D_8007B2E8[];
extern s32 D_8009A19C;

void func_80045368(u8* obj) {
    s32 kind;
    u8* sub;
    u8* scr;
    s32 off;

    obj[3] = 1;
    scr = D_1F80001C.bytes;
    off = *(s32*)(scr + 0x30);
    sub = obj + 0x8C;
    *(u32***)(obj + 0x30) = D_8007B2E8;
    do { // !FAKE: fence keeps the 0x7802 constant after the 0x30 store
        *(s16*)(obj + 0x42) = 0x7802;
    } while (0);
    kind = (s32)scr + off;
    *(s32*)(obj + 0x3C) = kind;
    kind = *(s8*)(obj + 1);
    *(s16*)(obj + 0x40) = 0;
    if (kind == 0x14) {
        *(u8**)(obj + 0x50) = D_80076E34;
        obj[0x16] = 0;
        obj[0x64] = 1;
        *(u8**)(obj + 0x68) = D_80076E4C;
        if (D_8009A19C & 0x200) {
            *(s32*)(obj + 0x20) = 0xD0000;
        } else {
            *(s32*)(obj + 0x20) = 0xB0000;
        }
        if (obj[0x15] == 0) {
            *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
        }
        set_animation(obj, 0x1D);
        sub[2] = 0;
    } else {
        *(u8**)(obj + 0x50) = D_80076E38;
        obj[0x64] = 2;
        obj[0x16] = 1;
        *(s32*)(obj + 0x20) = 0;
        obj[0x8C] = 0x5A;
        sub[1] = 8;
        set_animation(obj, 0x1E);
    }
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[5] = 0;
    obj[4]++;
    func_8002D9EC(obj, 0x2A, 0x22);
}
