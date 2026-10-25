#include "types.h"

extern void func_80032F70(u8*);
extern void func_80033024(u8*);
extern s32 func_8003240C(u8*);
extern s32 func_800326BC(u8*);
extern void func_8003258C(u8*);

extern u8 D_800767E0[];
extern u8 D_800F3FD0_ovl08[];
extern u8 D_800F3FCC_ovl08[];
extern u8 D_8009A198;

void func_800F2EE4_ovl08(u8* p) {
    if (*(s8*)(p + 6) == 0) {
        p[0x75] = 1;
        p[0xA2] = 1;
        *(u8**)(p + 0x58) = D_800767E0;
        *(u8**)(p + 0x68) = D_800F3FD0_ovl08;
        *(u8**)(p + 0x54) = D_800F3FCC_ovl08;
        p[6]++;
    } else if (*(s8*)(p + 6) == 1) {
        if (*(s8*)(p + 3) != 0) {
            func_80032F70(p);
            func_80033024(p);
            if (D_8009A198 == 0) {
                func_8003240C(p);
            }
            func_800326BC(p);
            func_8003258C(p);
        }
    }
}
