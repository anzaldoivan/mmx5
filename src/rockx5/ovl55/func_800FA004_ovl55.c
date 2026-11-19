#include "types.h"
#include "mmx5/ovl55.h"
#include "mmx5/globals.h"
#include "addr.h"
#define D_800FBAB8_ovl55_as_Blk200 (*(Blk200*)D_800FBAB8_ovl55)
#define D_800FBEB8_ovl55_as_Blk200 (*(Blk200*)D_800FBEB8_ovl55)
#define D_800FC2B8_ovl55_as_Blk200 (*(Blk200*)D_800FC2B8_ovl55)
#define D_800FC6B8_ovl55_as_Blk200 (*(Blk200*)D_800FC6B8_ovl55)
#define D_800FCAB8_ovl55_as_Blk200 (*(Blk200*)D_800FCAB8_ovl55)
#define D_800FCEB8_ovl55_as_Blk200 (*(Blk200*)D_800FCEB8_ovl55)

extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u8 D_8009A23C;

void func_800FA004_ovl55(u8* arg0) {
    u8* src;

    func_8002C50C();
    func_8002D004();
    init_checkpoint_positions();
    func_8002906C();
    func_80027238();
    D_80093E66 = 0;
    D_8009A42C = 0;
    D_800D50DC = 0;
    func_8002C1C8();
    D_8009A23C = 0;
    src = D_1F800028 + 0xC00;
    D_800FBAB8_ovl55_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x2000;
    D_800FBEB8_ovl55_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0xA00;
    D_800FC2B8_ovl55_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x800;
    D_800FC6B8_ovl55_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x1200;
    D_800FCAB8_ovl55_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x1400;
    D_800FCEB8_ovl55_as_Blk200 = *(Blk200*)src;
    arg0[1]++;
}
