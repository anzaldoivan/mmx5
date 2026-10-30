/* Shared body (DK-5), from the banked draft of func_800F3418_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

extern u8 D_800FAB9C_ovl09[];
extern u8 D_800FABA0_ovl09[];
extern u8 D_800FABA4_ovl09[];
extern u8 D_800FAD58_ovl09[][6];
extern s16 D_8009A0AA;
extern signed char D_800D1CA2;

void DEDUP_NAME(u8* obj) {
    s32 r;

    if (++*(s16*)(obj + 0x7C) & 1) {
        obj[0x47] = obj[0x90];
        func_80017248(obj);
        func_8002DED4(obj);
        *(s16*)(obj + 0x8C) = *(s16*)(obj + 0xA);
        *(s16*)(obj + 0x8E) = *(s16*)(obj + 0xE);
        *(s16*)(obj + 0xA) = *(s16*)(obj + 0x84);
        *(s16*)(obj + 0xE) = *(s16*)(obj + 0x88);
        if (*(s16*)(obj + 0x7C) < 30) {
            *(u8**)(obj + 0x50) = 0;
        } else {
            *(u8**)(obj + 0x50) = D_800FAB9C_ovl09;
        }
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        if (*(s16*)(obj + 0x7C) >= 41) {
            *(u8**)(obj + 0x54) = D_800FABA4_ovl09;
            if (*(s16*)(obj + 0x7E) < 4) {
                func_800171E8(obj, 4);
                *(u8**)(obj + 0x50) = D_800FABA0_ovl09;
                if (D_800D1CA2 / 2 < *(signed char*)(obj + 0x5C)) {
                    if (obj[0x15] == 0) {
                        *(s32*)(obj + 0x20) = -0x20000;
                    } else {
                        *(s32*)(obj + 0x20) = 0x20000;
                    }
                } else {
                    if (obj[0x15] == 0) {
                        *(s32*)(obj + 0x20) = -0x40000;
                    } else {
                        *(s32*)(obj + 0x20) = 0x40000;
                    }
                }
                r = func_8002DF78();
                (*(s16*)(obj + 0x7E))++;
                obj[6]--;
                *(s16*)(obj + 0x7C) = (r % 5 + 3) * 10;
            } else {
                func_800171E8(obj, 0);
                *(u8**)(obj + 0x50) = D_800FAB9C_ovl09;
                obj[5] = D_800FAD58_ovl09[obj[0x96]][obj[0x97]++];
                obj[6] = 0;
            }
        }
        func_8002D9EC(obj, 0x40, 0x40);
    } else {
        func_80017248(obj);
        obj[0x90] = obj[0x47];
        obj[0x47] = 9;
        *(s16*)(obj + 0xA) = *(s16*)(obj + 0x8C);
        *(s16*)(obj + 0xE) = *(s16*)(obj + 0x8E);
        func_8002DED4(obj);
        if (*(s16*)(obj + 0x7C) < 30) {
            *(u8**)(obj + 0x50) = D_800FAB9C_ovl09;
            if (*(s32*)(obj + 0x20) < 0) {
                obj[0x15] = 0;
            } else {
                obj[0x15] = 0x40;
            }
            func_8002D9EC(obj, 0x40, 0x40);
        } else {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            *(u8**)(obj + 0x50) = 0;
        }
    }
}
