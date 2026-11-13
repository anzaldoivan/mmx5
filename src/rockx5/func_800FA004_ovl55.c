#include "types.h"
#include "addr.h"

extern void func_8002C50C(void);
extern void func_8002D004(void);
extern void func_8002ACC4(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u8 D_8009A23C;
extern Blk200 D_800FBAB8_ovl55;
extern Blk200 D_800FBEB8_ovl55;
extern Blk200 D_800FC2B8_ovl55;
extern Blk200 D_800FC6B8_ovl55;
extern Blk200 D_800FCAB8_ovl55;
extern Blk200 D_800FCEB8_ovl55;

void func_800FA004_ovl55(u8* arg0) {
    u8* src;

    func_8002C50C();
    func_8002D004();
    func_8002ACC4();
    func_8002906C();
    func_80027238();
    D_80093E66 = 0;
    D_8009A42C = 0;
    D_800D50DC = 0;
    func_8002C1C8();
    D_8009A23C = 0;
    src = D_1F800028 + 0xC00;
    D_800FBAB8_ovl55 = *(Blk200*)src;
    src = D_1F800028 + 0x2000;
    D_800FBEB8_ovl55 = *(Blk200*)src;
    src = D_1F800028 + 0xA00;
    D_800FC2B8_ovl55 = *(Blk200*)src;
    src = D_1F800028 + 0x800;
    D_800FC6B8_ovl55 = *(Blk200*)src;
    src = D_1F800028 + 0x1200;
    D_800FCAB8_ovl55 = *(Blk200*)src;
    src = D_1F800028 + 0x1400;
    D_800FCEB8_ovl55 = *(Blk200*)src;
    arg0[1]++;
}
