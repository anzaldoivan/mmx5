#include "types.h"
#include "mmx5/ovl58.h"
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

void func_800FA004_ovl58(u8* arg0) {
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
    src = D_1F800028 + 0xA00;
    D_800FB600_ovl58.blk = *(Blk200*)src;
    src = D_1F800028 + 0xC00;
    D_800FBA00_ovl58.blk = *(Blk200*)src;
    src = D_1F800028 + 0x800;
    D_800FBE00_ovl58.blk = *(Blk20*)src;
    src = D_1F800028 + 0x1A00;
    D_800FBE40_ovl58.blk = *(Blk200*)src;
    arg0[1]++;
}

extern void func_8002C1C8(void);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];

void func_800FA2F8_ovl58(u8* arg0) {
    u8* p = D_8009A1F8.u;

    p[0xA0] = 1;
    *(s32*)(p + 0x60) += 0xFFFDDDDE;
    if (++*(s16*)(arg0 + 4) >= 60) {
        *(s16*)(p + 0x62) = 0x4E0;
        p[0xA0] = 1;
        func_8002385C(0x77, 0xFF, 0);
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
        func_8002C1C8();
        D_800D50DC = 0;
        D_8009A42C = 1;
        D_80093E66 = 1;
        D_80093DD0[0] = -1;
        D_80093DD0[1] = -1;
        D_80093DD0[2] = -1;
        D_80093DD0[3] = -1;
        D_80093DD0[4] = -1;
        D_80093DD0[5] = -1;
        D_80093DD0[6] = -1;
        D_80093DD0[7] = -1;
        D_80093DD0[8] = -1;
        D_80093DD0[9] = -1;
    }
}
