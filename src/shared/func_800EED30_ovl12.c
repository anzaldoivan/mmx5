/* Shared body (DK-5), from the banked draft of func_800EED30_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002DF78(void);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s8 D_8009A0A2;
extern u8 D_800F1F94_ovl12[][6];

void DEDUP_NAME(u8* obj) {
    u32 r;

    r = func_8002DF78() & 0xF;
    obj[0x87] = 0;
    if (((s8*)obj)[2] == 0) {
        if (D_8009A0A2 == 0) {
            if (r < 6) {
                obj[0x86] = 0;
            } else if (r < 12) {
                obj[0x86] = 1;
            } else {
                obj[0x86] = 4;
            }
        } else {
            if (r < 6) {
                obj[0x86] = 2;
            } else if (r < 10) {
                obj[0x86] = 3;
            } else {
                obj[0x86] = 4;
            }
        }
    } else {
        if (D_8009A0A2 == 0) {
            if (r < 6) {
                obj[0x86] = 5;
            } else if (r < 10) {
                obj[0x86] = 6;
            } else {
                obj[0x86] = 9;
            }
        } else {
            if (r < 6) {
                obj[0x86] = 7;
            } else if (r < 10) {
                obj[0x86] = 8;
            } else {
                obj[0x86] = 9;
            }
        }
    }
    obj[5] = D_800F1F94_ovl12[obj[0x86]][obj[0x87]++];
    obj[6] = 0;
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0x40, 0x40);
}
