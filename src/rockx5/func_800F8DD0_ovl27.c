#include "types.h"
#include "addr.h"

extern void func_8002DF54(u8* a0);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_8009A1F8[];

void func_800F8DD0_ovl27(u8* obj) {
    u8* p;
    u8* q;
    s32 ang;
    s32 e;
    s32 dx;
    s32 y;
    s32 x;

    p = D_8009A1F8;
    e = *(s16*)(obj + 0xE) - 0x78;
    dx = *(s16*)(D_1F80004C.bytes + 0x86) - *(s16*)(obj + 0xA);
    ang = ratan2(e - *(s16*)(p + 0xE), dx);
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x20) = rcos(ang) * 16;
    *(s32*)(obj + 0x24) = rsin(ang) * 16;
    if (*(s32*)(obj + 0x20) != 0) {
        *(s32*)(obj + 0x20) = *(s32*)(obj + 0x20) * 3 / 2;
    } else {
        *(s32*)(obj + 0x20) = 0;
    }
    if (*(s32*)(obj + 0x24) != 0) {
        *(s32*)(obj + 0x24) = *(s32*)(obj + 0x24) * 3 / 2;
    } else {
        *(s32*)(obj + 0x24) = 0;
    }
    func_8002DF54(obj);
    x = *(s16*)(D_1F80004C.bytes + 0x86);
    if (*(s16*)(obj + 0xA) >= x - 3 && *(s16*)(obj + 0xA) <= x + 3) {
        q = D_8009A1F8;
        y = *(s16*)(q + 0xE);
        if (*(s16*)(obj + 0xE) >= y + 0x75 && *(s16*)(obj + 0xE) <= y + 0x7B) {
            *(s16*)(obj + 0x7C) = 0x28;
            obj[6]++;
        }
    }
}
