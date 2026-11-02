/* Shared body (DK-5), from the banked draft of func_800F049C_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);

void DEDUP_NAME(u8* obj) {
    s32 m;
    s32 k;

    if (--*(s32*)(obj + 0x84) == 0) {
        *(s32*)(obj + 0x84) = 20;
    }
    if (--*(s16*)(obj + 0x7E) == 0) {
        func_8005019C(1, 2, obj, 8, 1);
        *(s16*)(obj + 0x7E) = 2;
    }
    func_80017248(obj);
    func_8002DF54(obj);
    k = 9;
    if (obj[0x15] == 0) {
        k = 10;
        m = obj[0x70] & 10;
    } else {
        m = obj[0x70] & 9;
    }
    if (m == k) {
        *(s16*)(obj + 0x7C) = 60;
        obj[5] = 6;
        obj[6] = 0;
    }
}
