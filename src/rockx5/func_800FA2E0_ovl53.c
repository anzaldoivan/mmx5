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
extern Blk200 D_800FAD9C_ovl53;
extern Blk200 D_800FB19C_ovl53;

#define D_1F800028 (*(u8**)0x1F800028)

void func_800FA2E0_ovl53(u8* arg0) {
    Blk200* s;

    func_8002C50C();
    func_8002D004();
    func_8002ACC4();
    func_8002906C();
    func_80027238();
    D_80093E66 = 0;
    D_8009A42C = 0;
    D_800D50DC = 0;
    func_8002C1C8();
    s = (Blk200*)(D_1F800028 + 0xC00);
    D_8009A1F8[0x3] = 0;
    D_8009A1F8[0x57] = 0;
    D_8009A1F8[0xAB] = 0;
    D_800FAD9C_ovl53 = *s;
    s = (Blk200*)(D_1F800028 + 0xE00);
    D_800FB19C_ovl53 = *s;
    arg0[1]++;
}
