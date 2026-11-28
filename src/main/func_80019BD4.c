#include "types.h"

extern X4_P_TAG* D_80091C50[2][4][8];
extern X4_P_TAG* D_80093E70[2][4][8];

void func_80019BD4(void) {
    u32 i;
    u32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            D_80093E70[0][i][j] = 0;
            D_80093E70[1][i][j] = 0;
            D_80091C50[0][i][j] = (X4_P_TAG*)&D_80093E70[0][i][j];
            D_80091C50[1][i][j] = (X4_P_TAG*)&D_80093E70[1][i][j];
        }
    }
}
