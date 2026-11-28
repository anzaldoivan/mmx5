#include "types.h"
#include "mmx5/object.h"
#include "addr.h"

extern X4_P_TAG* D_80091C50[2][4][8];
extern X4_P_TAG* D_80093E70[2][4][8];
extern u8 D_800AA9A8[];
extern u8 D_800C9588[];

void func_80024C60(s8* p);
void func_80024B88(void);

static inline void func_80027120_clear(void) {
    u32 buffer;
    u32 i;
    u32 j;

    buffer = D_1F800000;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            D_80093E70[buffer][i][j] = 0;
            D_80091C50[buffer][i][j] = (X4_P_TAG*)&D_80093E70[buffer][i][j];
        }
    }
}

void func_80027120(void) {
    s32 i;
    s8* p;

    i = D_1F800000;
    D_1F800124 = 0;
    D_1F800100 = D_800AA9A8 + i * 0xA000;
    D_1F800104 = D_800C9588 + (i << 13);
    func_80027120_clear();
    for (p = D_800994A0.s; p < D_800994A0.s + 0xC00; p += 0x60) {
        if (p[3] != 0) {
            func_80024C60(p);
        }
    }
    func_80024B88();
}
