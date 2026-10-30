/* Shared body (DK-5), from the banked draft of func_800F45B8_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern u8 D_8009A0B4;

void DEDUP_NAME(u8* obj) {
    u8* p;
    u8* q;
    u8* r;
    s16 y;
    s32 st;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 2) {
        if (obj[0x92] != 0) {
            func_800171E8(obj, 5);
            obj[0x92]--;
        } else {
            obj[5] = 6;
            obj[6] = 0;
        }
    }
    if (*(s8*)(obj + 0x45) == 3) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x1A;
            p[0x15] = func_8002DF78() & 0x40;
            p[2] = 9;
            *(s32*)(p + 0x20) = 0;
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
            *(s16*)(p + 0x42) = *(s16*)(obj + 0x42) & 0x7FFF;
            *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0x1E;
            *(s16*)(p + 0xE) = *(s16*)(obj + 0xE) - 0x18;
            p[0x14] = D_8009A0B4;
            *(u8**)(p + 0x50) = obj;
        }
    }
    if (*(s8*)(obj + 0x45) == 1) {
        func_80016490(2, 0x16, obj);
        r = func_8002D1A4();
        if (r != 0) {
            r[0] = 0x41;
            r[1] = 0x22;
            *(s16*)(r + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(r + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(r + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(r + 0x42) = *(s16*)(obj + 0x42) & 0x7FFF;
            *(s16*)(r + 0xA) = *(s16*)(obj + 0xA) - 0x24;
            *(s16*)(r + 0xE) = *(s16*)(obj + 0xE) - 0x28;
            r[0x15] = obj[0x15];
            *(u8**)(r + 0x7C) = obj;
            if (obj[0x91] == 3) {
                st = 6;
                y = *(s16*)(obj + 0xA) - 0xF0;
                goto set; // !FAKE: goto kept for the matching branch layout
            }
            if (obj[0x91] == 0) {
                *(s32*)(r + 0x8C) = (s16)(*(s16*)(obj + 0xA) - 0x50);
                q = func_8002D1A4();
                if (q != 0) {
                    q[0] = 0x41;
                    q[1] = 0x22;
                    *(s16*)(q + 0x40) = *(s16*)(obj + 0x40);
                    *(s32*)(q + 0x30) = *(s32*)(obj + 0x30);
                    *(s32*)(q + 0x3C) = *(s32*)(obj + 0x3C);
                    *(s16*)(q + 0x42) = *(s16*)(obj + 0x42) & 0x7FFF;
                    *(s16*)(q + 0xA) = *(s16*)(obj + 0xA) - 0x24;
                    *(s16*)(q + 0xE) = *(s16*)(obj + 0xE) - 0x28;
                    q[0x15] = obj[0x15];
                    *(u8**)(q + 0x7C) = obj;
                    *(s32*)(q + 0x8C) = (s16)(*(s16*)(obj + 0xA) - 0xF0);
                }
            } else {
                st = 6;
                y = *(s16*)(obj + 0xA) - 0x50;
            set:
                *(s32*)(r + 0x8C) = y;
                obj[5] = st;
                obj[6] = 0;
            }
        }
    }
}
