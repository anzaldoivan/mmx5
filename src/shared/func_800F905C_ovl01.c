/* Shared body (DK-5), from the banked draft of func_800F905C_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8001296C(s32);
extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002A600(s32, s32, s32);
extern void func_8002DED4(u8* obj);
extern s16 D_8009A0AA;
extern signed char D_800D1C0C;
extern u8 D_800FD578_ovl01[];
extern u8 D_800FD57C_ovl01[];
extern u8 D_800FD608_ovl01[];

void DEDUP_NAME(u8* obj) {
    s32 lim;

    lim = 0x40;
    if (D_800D1C0C != 0xC) {
        lim = 0x120;
    }
    if (lim < *(s16*)(obj + 0xE)) {
        *(u8**)(obj + 0x68) = D_800FD608_ovl01;
    }
    if (*(s16*)(obj + 0x7C) >= 0x79) {
        if ((obj[0x70] & 8) && lim < *(s16*)(obj + 0xE)) {
            func_8001296C(5);
            func_80016490(2, 7, obj);
            func_800171E8(obj, 0xF);
            *(u8**)(obj + 0x50) = D_800FD57C_ovl01;
            *(u8**)(obj + 0x54) = D_800FD578_ovl01;
            func_8002A600(0x1E, 4, 2);
            obj[6]++;
        }
        if (*(s16*)(obj + 0xA) > D_8009A0AA) {
            obj[0x15] = 0;
        } else {
            obj[0x15] = 0x40;
        }
        func_8002DED4(obj);
        func_80017248(obj);
    }
    (*(s16*)(obj + 0x7C))++;
}
