#include "types.h"

extern void func_800F7C7C_ovl00(u8* p);
extern void func_800FA044_ovl00(u8* p);
extern void func_800F7DE0_ovl00(u8* p);
extern void func_800FA118_ovl00(u8* p);

void func_800F9FC0_ovl00(u8* p) {
    if (((s8*)p)[2] < 4) {
        if (((s8*)p)[4] == 0) {
            func_800F7C7C_ovl00(p);
        } else {
            func_800FA044_ovl00(p);
        }
    } else {
        if (((s8*)p)[4] == 0) {
            func_800F7DE0_ovl00(p);
        } else {
            func_800FA118_ovl00(p);
        }
    }
}
