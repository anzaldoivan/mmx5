#include "types.h"

extern s8 D_800D1C1D;
void func_800EEB64_ovl00(u8* arg0);

void func_800EEB14_ovl00(u8* arg0) {
    u8 v = (u8)D_800D1C1D;

    arg0[5] = v;
    if ((s8)v >= 2) {
        arg0[5] = 1;
    }
    arg0[6] = 0;
    arg0[4]++;
    func_800EEB64_ovl00(arg0);
}

extern void (*D_800FA214_ovl00[])(u8*);

void func_800EEB64_ovl00(u8* arg0) {
    D_800FA214_ovl00[*(signed char*)(arg0 + 5)](arg0);
}
