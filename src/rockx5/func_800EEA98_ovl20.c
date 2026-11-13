#include "types.h"
#include "addr.h"

extern void func_8002C50C(void);
extern void func_8002D004(void);
extern void func_8002ACC4(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);

extern u8 D_8009A428;
extern u8 D_800D1598;
extern u8 D_800F6DF9_ovl20;
extern u8 D_800F6DFA_ovl20;
extern Blk200 D_800F5FF0_ovl20;
extern Blk200 D_800F63F0_ovl20;
extern Blk200 D_800F67F0_ovl20;
extern Blk100 D_800F6BF0_ovl20;

void func_800EEA98_ovl20(u8* arg0) {
    u8* p;
    u8* src;
    u32 i;

    D_8009A428 = 0;
    i = 0;
    p = arg0 + 0x26;
    for (; i < 0x10; i++) {
        p[i] = 0;
    }
    arg0[0x1F] = 0;
    arg0[0x24] = 0;
    *(s16*)(arg0 + 8) = 0;
    *(s16*)(arg0 + 0xA) = 0;
    src = D_1F800028 + 0xE00;
    D_800F5FF0_ovl20 = *(Blk200*)src;
    src = D_1F800028 + 0x1600;
    D_800F63F0_ovl20 = *(Blk200*)src;
    src = D_1F800028 + 0x800;
    D_800F67F0_ovl20 = *(Blk200*)src;
    src = D_1F800028 + 0x80;
    D_800F6BF0_ovl20 = *(Blk100*)src;
    func_8002C50C();
    func_8002D004();
    func_8002ACC4();
    func_8002906C();
    func_80027238();
    D_800F6DF9_ovl20 = 0;
    D_800F6DFA_ovl20 = 0;
    arg0[0xE] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    D_800D1598 = 0;
    arg0[1] = 1;
}
