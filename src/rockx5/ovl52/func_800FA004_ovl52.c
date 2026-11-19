#include "types.h"
#include "mmx5/ovl52.h"
#include "mmx5/globals.h"
#include "addr.h"
#define D_800FB160_ovl52_as_Blk200 (*(Blk200*)D_800FB160_ovl52)
#define D_800FB560_ovl52_as_Blk200 (*(Blk200*)D_800FB560_ovl52)

extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_8002C1C8(void);

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u8 D_8009A1F8[];

void func_800FA004_ovl52(u8* arg0) {
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
    src = D_1F800028 + 0xC00;
    D_800FB160_ovl52_as_Blk200 = *(Blk200*)src;
    src = D_1F800028 + 0xE00;
    D_800FB560_ovl52_as_Blk200 = *(Blk200*)src;
    D_8009A1F8[3] = 0;
    D_8009A1F8[0xAB] = 0;
    D_8009A1F8[0x57] = 0;
    *(s16*)(D_8009A1F8 + 0x5E) = 0;
    *(s16*)(D_8009A1F8 + 0x62) = 0x100;
    D_8009A1F8[0xA0] = 1;
    arg0[1]++;
}
