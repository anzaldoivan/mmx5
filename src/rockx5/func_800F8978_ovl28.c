#include "types.h"

extern u8 D_8009A0A0[];
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void func_800F8978_ovl28(u8* obj) {
    u8* p = D_8009A0A0;
    s32 dx;
    s32 dy;

    dx = (*(s16*)(p + 0xA) - *(s16*)(obj + 0xA)) < 0
             ? (*(s16*)(obj + 0xA) - *(s16*)(p + 0xA))
             : (*(s16*)(p + 0xA) - *(s16*)(obj + 0xA));
    dy = *(s16*)(p + 0xE) - *(s16*)(obj + 0xE);
    if (dy >= 0 ? dx + dy < 6
                : dx + (*(s16*)(obj + 0xE) - *(s16*)(p + 0xE)) < 6) {
        obj[4] = 2;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    func_80017248(obj);
    func_8002DF54(obj);
}
