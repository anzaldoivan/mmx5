#include "types.h"

extern s32 CdControlB(s32, s32, u8*);
extern void SsSetSerialAttr(s32, s32, s32);
extern void func_80017E98(u8 vol);
extern u8 D_800E805C;
extern s32 D_800E8060;
extern s16 D_800E8090;
extern s32 D_800E8094;
extern u8 D_800D1F3C;
extern s32 D_800E80A4;
extern u8 D_800E8098;

void func_80017D88(void) {
    if (D_800E80A4 == 2) {
        D_800E805C = 0;
        func_80017E98(0);
        if (D_800E8094 == 2 && D_800E8090 != 0) {
            while (!CdControlB(9, 0, 0)) {
            }
        }
        SsSetSerialAttr(0, 0, 0);
        D_800E8094 = 0;
        D_800E8098 = 1;
        do {
            D_800D1F3C = 0;
        } while (
            0); // !FAKE: loop notes weight D_800D1F3C's %hi for the s1/s2 order
        D_800E8060 = 0;
    }
}
