/* Shared body (DK-5), from the banked draft of func_800F5958_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_800F81F4_ovl11(u8* obj);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_8009A0A0[];
extern s16 D_800FA05C_ovl11;

void DEDUP_NAME(u8* obj) {
    D_1F80004C_t* s;
    u8* g;
    u8* g2;
    u8* g3;
    s16 tx;
    s32 dx;
    s32 dy;
    s32 ang;

    func_80017248(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        g = D_8009A0A0;
        if (*(s8*)(g + 2) == 0 && g[0xFA] == 0) {
            obj[0x62] = 8;
        } else {
            obj[0x62] = 6;
        }
        func_800171E8(obj, 3);
        func_800F81F4_ovl11(obj);
        if (D_1F80004C.bytes[0x91] != 0) {
            *(s32*)(obj + 0x2C) = -0x100;
        } else {
            *(s32*)(obj + 0x2C) = -0x200;
        }
        s = &D_1F80004C;
        g2 = D_8009A0A0;
        *(s32*)(obj + 0x24) = 0xFFFC0000;
        *(u16*)(s->bytes + 0x88) = *(u16*)(g2 + 0xA);
        obj[6]++;
        s->bytes[0x90] = 0;
        tx = *(s16*)(g2 + 0xA);
        if (*(s16*)(obj + 0xA) < tx) {
            tx += 0x20;
        } else {
            tx -= 0x20;
        }
        dy = D_800FA05C_ovl11 - *(s16*)(obj + 0xE);
        dx = tx - *(s16*)(obj + 0xA);
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x28) = 0;
        ang = ratan2(dy, dx);
        g3 = D_8009A0A0;
        if (((*(s16*)(g3 + 0xA) - *(s16*)(obj + 0xA)) < 0
                 ? (*(s16*)(obj + 0xA) - *(s16*)(g3 + 0xA))
                 : (*(s16*)(g3 + 0xA) - *(s16*)(obj + 0xA))) > 0xA0) {
            *(s32*)(obj + 0x20) = rcos(ang) * 0x60;
            *(s32*)(obj + 0x24) = -rsin(ang) * 0x60;
        } else {
            *(s32*)(obj + 0x20) = rcos(ang) << 6;
            *(s32*)(obj + 0x24) = -rsin(ang) << 6;
        }
        func_80016490(2, 0x30, obj);
    }
}
