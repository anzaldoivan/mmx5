#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DF54(u8* a0);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_8009A0A0[];

void func_8004A610(u8* obj) {
    u8* p = D_8009A0A0;
    s32 dx;
    s32 dz;
    s32 a;
    s32 s;
    s32 t;
    s32 c;
    s32 u;

    dx = *(s16*)(p + 0xA) - *(s16*)(obj + 0xA);
    dz = *(s16*)(p + 0xE) - *(s16*)(obj + 0xE);
    if (dx * dx + dz * dz < 0x25) {
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x68) = 0;
        func_800171E8(obj, 1);
        *(s16*)(obj + 0xA) = *(s16*)(p + 0xA);
        *(s16*)(obj + 0xE) = *(s16*)(p + 0xE);
        obj[5]++;
        return;
    }
    a = ratan2(dz, dx);
    *(s32*)(obj + 0x20) = rcos(a);
    s = -rsin(a);
    t = s << 4;
    *(s32*)(obj + 0x24) = ((s << 5) + t) << 1;
    c = *(s32*)(obj + 0x20);
    u = c << 4;
    *(s32*)(obj + 0x20) = ((c << 5) + u) << 1;
    func_8002DF54(obj);
}
