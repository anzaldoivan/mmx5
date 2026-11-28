#include "types.h"
#include "mmx5/ovl49.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800FA514_ovl49(u8* arg0) {
    Blk200* s;

    func_8002C50C();
    func_8002D004();
    init_checkpoint_positions();
    func_8002906C();
    func_80027238();
    D_80093E66 = 0;
    D_8009A42C = 0;
    D_800D50DC = 0;
    func_8002C1C8();
    s = (Blk200*)(D_1F800028 + 0x1400);
    D_8009A1F8.u[0x3] = 0;
    D_8009A1F8.u[0x57] = 0;
    D_800FB9C4_ovl49.blk = *s;
    s = (Blk200*)(D_1F800028 + 0x1C00);
    D_800FBDC4_ovl49.blk = *s;
    arg0[1]++;
}
