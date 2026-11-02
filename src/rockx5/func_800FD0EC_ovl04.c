#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80028B18(s32, s32, s32, void*);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80050650(s32, s16, s16, s16, s16, s32);
extern u8 D_8009A1F8[];
extern u8 D_80102A58_ovl04[];
extern s16 D_80102D74_ovl04[];
extern s16 D_80102D8C_ovl04[][2];
extern u8 D_80102DB8_ovl04[][8];
extern s16 D_80102E10_ovl04[][2];

void func_800FD0EC_ovl04(u8* obj) {
    s32 i;
    u8* base;
    s32 save8;
    s32 saveC;

    i = *(s16*)(obj + 0x8A);
    save8 = *(s32*)(obj + 0x8);
    saveC = *(s32*)(obj + 0xC);
    for (; i < 11; i++) {
        base = D_8009A1F8;
        if (*(s16*)(base + 0xE) <= D_80102D74_ovl04[i]) {
            *(s16*)(obj + 0xA) = D_80102D8C_ovl04[i][0];
            *(s16*)(obj + 0xE) = D_80102D8C_ovl04[i][1];
            func_80028B18(0, D_80102E10_ovl04[i][0], D_80102E10_ovl04[i][1],
                          D_80102DB8_ovl04[i]);
            base[0x4C] = 1;
            func_8004D4F4(0xC, D_80102A58_ovl04, obj);
            (*(s16*)(obj + 0x8A))++;
            func_80050650(0x20, *(s16*)(obj + 0xA) - 0x20,
                          *(s16*)(obj + 0xE) - 0x20, *(s16*)(obj + 0xA) + 0x20,
                          *(s16*)(obj + 0xE) + 0x20, 5);
            func_80016490(5, 2, obj);
        }
    }
    *(s32*)(obj + 0x8) = save8;
    *(s32*)(obj + 0xC) = saveC;
}
