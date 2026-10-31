/* Shared body (DK-5), from the banked draft of func_800F5B0C_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8* func_8002C938();
extern void func_8002DED4(u8* obj);
extern u8 D_8009A197;
extern u8 D_800D1C10;
extern u8 D_800F9E6C_ovl03[];
extern u8 D_800FA0BC_ovl03[];

void DEDUP_NAME(u8* obj) {
    s32 i;
    s16 t;
    u8* p;

    t = ++*(u16*)(obj + 0x7C);
    if (t == 1) {
        *(u8**)(obj + 0x54) = D_800F9E6C_ovl03;
        D_8009A197 = 0;
        D_800D1C10 = 0;
    } else if (t == 0x1E) {
        func_800171E8(obj, 5);
        obj[7] = 0;
        for (i = 0; i < 3; i++) {
            p = func_8002C938();
            if (p != 0) {
                p[0] = 0x61;
                p[1] = 0x39;
                p[2] = 3;
                *(u8**)(p + 0x80) = obj;
            }
        }
    } else if (t == 0x6E) {
        func_800171E8(obj, 1);
        obj[5] = D_800FA0BC_ovl03[obj[0x93]++ + obj[0x92] * 6];
        obj[6] = 0;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
