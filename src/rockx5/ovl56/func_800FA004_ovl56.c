#include "types.h"
#include "mmx5/ovl56.h"
#include "mmx5/globals.h"
#include "addr.h"
#define D_800FC700_ovl56_as_Blk200 (*(Blk200*)D_800FC700_ovl56)
#define D_800FCB00_ovl56_as_Blk200 (*(Blk200*)D_800FCB00_ovl56)
#define D_800FCF00_ovl56_as_Blk200 (*(Blk200*)D_800FCF00_ovl56)
#define D_800FD300_ovl56_as_Blk200 (*(Blk200*)D_800FD300_ovl56)
#define D_800FD700_ovl56_as_Blk200 (*(Blk200*)D_800FD700_ovl56)
#define D_800FDB00_ovl56_as_Blk200 (*(Blk200*)D_800FDB00_ovl56)

extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern Blk200 D_800FBF00_ovl56;
extern Blk200 D_800FC300_ovl56;

void func_800FA004_ovl56(u8* arg0) {
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
    src = D_1F800028 + 0x800;
    D_800FBF00_ovl56 = *(Blk200*)src;
    src = D_1F800028 + 0xA00;
    D_800FC300_ovl56 = *(Blk200*)src;
    src = D_1F800028 + 0x2400;
    D_800FC700_ovl56_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x2600;
    D_800FCB00_ovl56_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x2800;
    D_800FCF00_ovl56_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x1C00;
    D_800FD300_ovl56_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x2A00;
    D_800FD700_ovl56_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0x1E00;
    D_800FDB00_ovl56_as_Blk200 = *(Blk200*)src;
    arg0[1]++;
}
