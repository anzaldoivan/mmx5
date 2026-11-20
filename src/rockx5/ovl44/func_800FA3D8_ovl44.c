#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800D1F3C;

void func_800FA3D8_ovl44(u8* arg0) {
    if (D_800D1F3C == 2) {
        func_8002385C(0x10, 0xFF, 0);
        arg0[1]++;
    }
}
