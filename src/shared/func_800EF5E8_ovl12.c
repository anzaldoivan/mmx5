/* Shared body (DK-5), from the banked draft of func_800EF5E8_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void DEDUP_NAME(u8* p) {
    u8* q;
    s16 a;
    s16 b;
    s32 d;

    func_800317B8(p);
    func_80031DD0(p);
    switch (*(s8*)(p + 5)) {
    case 0:
        if (p[0x15] == 0) {
            if (*(s16*)(p + 0xA) < 0x50) {
                if (*(s8*)(p + 6) != 0) {
                    *(s32*)(p + 0x24) = 0x8000;
                } else {
                    *(s32*)(p + 0x24) = -0x8000;
                }
                *(s32*)(p + 0x8C) = 0;
                p[5]++;
            }
        } else if (*(s16*)(p + 0xA) > 0x120) {
            if (*(s8*)(p + 6) != 0) {
                *(s32*)(p + 0x24) = 0x8000;
            } else {
                *(s32*)(p + 0x24) = -0x8000;
            }
            *(s32*)(p + 0x8C) = 0;
            p[5]++;
        }
        break;
    case 1:
        if (++*(s32*)(p + 0x8C) == 0xC) {
            if (p[0x15] == 0) {
                p[0x15] = 0x40;
                *(s32*)(p + 0x20) = 0x50000;
            } else {
                p[0x15] = 0;
                *(s32*)(p + 0x20) = -0x50000;
            }
            p[5]++;
        }
        break;
    case 2:
        if (++*(s32*)(p + 0x8C) == 0x18) {
            *(s32*)(p + 0x24) = 0;
        }
        a = *(s16*)(*(u8**)(p + 0x7C) + 0xA);
        b = *(s16*)(p + 0xA);
        d = a - b;
        if ((d >= 0) ? (d < 0x47) : (b - a < 0x47)) {
            (*(u8**)(p + 0x7C))[7] = 1;
            *(s32*)(p + 0x8C) = 0;
            p[5]++;
        }
        break;
    case 3:
        if (++*(s32*)(p + 0x8C) == 0xB) {
            p[4] = 2;
        }
        break;
    }
    q = *(u8**)(p + 0x7C);
    if (*(s8*)(q + 4) == 2 || *(s8*)(q + 5) == 9) {
        p[4] = 2;
    }
    func_8002D9EC(p, 0x20, 0x10);
    func_80017248(p);
    func_8002DED4(p);
}
