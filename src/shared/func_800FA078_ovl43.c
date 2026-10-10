/* Shared body (DK-5), from the banked draft of func_800FA078_ovl43 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002C50C(void);
extern void func_8002D004(void);
extern void func_8002ACC4(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u8 D_8009A1F8[];

void DEDUP_NAME(u8* arg0) {
    func_8002C50C();
    func_8002D004();
    func_8002ACC4();
    func_8002906C();
    func_80027238();
    D_80093E66 = 0;
    D_8009A42C = 0;
    D_800D50DC = 0;
    func_8002C1C8();
    D_8009A1F8[0x3] = 0;
    D_8009A1F8[0x57] = 0;
    D_8009A1F8[0xAB] = 0;
    arg0[1]++;
}
