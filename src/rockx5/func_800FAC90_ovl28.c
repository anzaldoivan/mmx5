#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 rsin(s32);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void func_800FAC90_ovl28(u8* obj) {
    u8* p;

    if (*(u32*)(obj + 0x94) >= 4) {
        func_800317B8(obj);
    }
    if (*(s8*)(obj + 2) == 9) {
        *(s16*)(obj + 0xE) =
            *(u16*)(obj + 0x90) +
            (rsin((*(s16*)(obj + 0xA) - *(s32*)(obj + 0x8C)) * 16) >> 6);
    } else {
        *(s16*)(obj + 0xE) =
            *(u16*)(obj + 0x90) -
            (rsin((*(s16*)(obj + 0xA) - *(s32*)(obj + 0x8C)) * 16) >> 6);
    }
    func_8002D9EC(obj, 0x20, 0x80);
    if (*(s8*)(obj + 3) == 0) {
        if (*(s8*)(obj + 2) == 9) {
            p = *(u8**)(obj + 0x7C);
            *(u16*)(p + 0x7E) |= 2;
        }
        obj[4] = 2;
    }
    func_80017248(obj);
    if (++*(u32*)(obj + 0x94) >= 7) {
        func_8002DF54(obj);
    }
}
