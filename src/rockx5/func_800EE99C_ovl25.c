#include "types.h"
#include "addr.h"

extern void func_80017668(void);
extern void func_8002ACC4(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);
extern void func_800177B0(s32, s32);
extern void func_80013288(s32);
extern u8 D_800C9310;
extern u8 D_8009A1F8[];
extern Blk200 D_800F0CF4_ovl25;
extern Blk200 D_800F10F4_ovl25;
extern Blk200 D_800F14F4_ovl25;
extern Blk200 D_800F18F4_ovl25;
extern Blk200 D_800F1CF4_ovl25;
extern Blk200 D_800F20F4_ovl25;

void func_800EE99C_ovl25(u8* arg0) {
    u8 i;
    u8* p;
    u8* src;

    for (i = 0; i < 16; i++) {
        p = arg0 + 0x26;
        p[i] = 0;
    }
    func_80017668();
    func_8002ACC4();
    func_8002906C();
    func_80027238();
    D_8009A1F8[3] = 0;
    D_8009A1F8[0x57] = 1;
    D_8009A1F8[0xAB] = 0;
    D_800C9310 |= 1;
    src = D_1F800028 + 0xA00;
    D_800F0CF4_ovl25 = *(Blk200*)src;
    src = D_1F800028 + 0xC00;
    D_800F10F4_ovl25 = *(Blk200*)src;
    src = D_1F800028 + 0xE00;
    D_800F14F4_ovl25 = *(Blk200*)src;
    src = D_1F800028 + 0x1000;
    D_800F18F4_ovl25 = *(Blk200*)src;
    src = D_1F800028 + 0x1200;
    D_800F1CF4_ovl25 = *(Blk200*)src;
    src = D_1F800028 + 0x1400;
    D_800F20F4_ovl25 = *(Blk200*)src;
    do {
        arg0[1]++;
        *(s16*)(arg0 + 4) = 0;
        arg0[2] = 0;
        func_800177B0(0x1C, 0x73);
    } while (0); // !FAKE: loop notes weight arg0's refs so it takes s0
    func_80013288(8);
}
