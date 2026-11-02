#include "types.h"
#include "addr.h"

extern void func_80013288(s32);
extern u8 D_8009A1F8[];
extern Blk200 D_800FABE8_ovl57;
extern Blk200 D_800FAFE8_ovl57;
extern Blk200 D_800FB3E8_ovl57;

void func_800FA004_ovl57(u8* arg0) {
    Blk200* s;

    D_8009A1F8[0x3] = 0;
    D_8009A1F8[0x57] = 0;
    D_8009A1F8[0xAB] = 1;
    *(s16*)(D_8009A1F8 + 0xB2) = 0;
    *(s16*)(D_8009A1F8 + 0xB6) = 0;
    D_8009A1F8[0xF4] = 1;
    s = (Blk200*)(D_1F800028 + 0x800);
    D_800FABE8_ovl57 = *s;
    s = (Blk200*)(D_1F800028 + 0xA00);
    D_800FAFE8_ovl57 = *s;
    s = (Blk200*)(D_1F800028 + 0x1200);
    D_800FB3E8_ovl57 = *s;
    func_80013288(8);
    arg0[1]++;
}
