/* Shared body (DK-5), from the banked draft of func_800F60C0_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8002DF54(u8* a0);
extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);
extern u16 D_800FA05C_ovl11[];

void DEDUP_NAME(u8* obj) {
    u32 r;
    s32 t;
    s32 o;
    u16 d;

    func_8002DF54(obj);
    func_80017248(obj);
    func_8002D9EC(obj, 0x40, 0x40);
    if (*(s8*)(obj + 3) == 0) {
        *(s8*)(obj + 0x9A) = 0;
    } else {
        *(s8*)(obj + 0x9A) = 1;
    }
    *(s8*)(obj + 3) = 1;
    if (*(s8*)(obj + 0x9A) == 0) {
        *(s32*)(obj + 0x54) = 0;
        *(s32*)(obj + 0x50) = 0;
        *(s8*)(obj + 0x9A) = 0;
        *(s8*)(obj + 3) = 0;
        D_1F80004C.bytes[0x92] = 5;
        if (*(s16*)(obj + 0x7E) == 0) {
            func_800171E8(obj, 1);
            r = func_8002DF78();
            d = D_800FA05C_ovl11[0];
            o = (u8)(r % 3) * 16 - 0x70;
            *(s16*)(obj + 0xE) = d + o;
            t = (u8)((u32)func_8002DF78() % 80);
            *(s16*)(obj + 0x7C) = (t + 0x50) / 4;
            *(s32*)(obj + 0x24) = 0;
            *(s8*)(obj + 6) = 9;
            D_1F80004C.bytes[0x93] = 0x3C;
            return;
        }
        *(s8*)(obj + 6) = 2;
        *(s16*)(obj + 0x7C) = 0x1E;
    }
}
