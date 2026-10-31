#include "types.h"
#include "addr.h"

extern u8 D_8009E7A0[];
extern s8 D_800D1C00[];

void func_800223E4(void) {
    for (D_1F80005C = (s8*)D_8009E7A0; D_1F80005C < (s8*)D_8009E7A0 + 0x1200;
         D_1F80005C += 0x30) {
        if (D_800D1C00[0x15] == 0) {
            if (D_1F80005C[0]) {
                D_1F80008C[D_1F80005C[1]](D_1F80005C);
            }
        } else if ((u8)D_1F80005C[0] & 8) {
            D_1F80008C[D_1F80005C[1]](D_1F80005C);
        }
    }
}
