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
extern Blk200 D_800FB600_ovl58;
extern Blk200 D_800FBA00_ovl58;
extern Blk20 D_800FBE00_ovl58;
extern Blk200 D_800FBE40_ovl58;

void func_800FA004_ovl58(u8* arg0) {
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
    src = D_1F800028 + 0xA00;
    D_800FB600_ovl58 = *(Blk200*)src;
    src = D_1F800028 + 0xC00;
    D_800FBA00_ovl58 = *(Blk200*)src;
    src = D_1F800028 + 0x800;
    D_800FBE00_ovl58 = *(Blk20*)src;
    src = D_1F800028 + 0x1A00;
    D_800FBE40_ovl58 = *(Blk200*)src;
    arg0[1]++;
}
