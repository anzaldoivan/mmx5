/* Shared body (DK-5), from the banked draft of func_800F40C8_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002D1A4(s16);
extern s32 func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void DEDUP_NAME(u8* obj) {
    s16 n;
    u8* child;

    n = *(s16*)(obj + 0x7E);
    if (n < 0) {
        if (++*(s16*)(obj + 0x7C) == 14) {
            *(s16*)(obj + 0x7C) = 0;
            *(s16*)(obj + 0x7E) = 0;
        }
    } else if (++*(s16*)(obj + 0x7C) == 20) {
        *(s16*)(obj + 0x7C) = 0;
        if (n < 8) {
            child = func_8002D1A4(n);
            if (child != 0) {
                func_80016490(2, 0x82, obj);
                child[0] = 0x41;
                child[1] = 0x10;
                child[2] = obj[0x7E] + 6;
                *(u8**)(child + 0x7C) = obj;
            }
        }
        if (++*(s16*)(obj + 0x7E) == 9) {
            func_800171E8(obj, 0);
        }
    }
    if (*(s16*)(obj + 0x7E) == 10) {
        if (obj[0x15] == 0) {
            obj[0x15] = 0x40;
            *(s32*)(obj + 0x20) = 0xFFFA0000;
        } else {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = 0x60000;
        }
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
