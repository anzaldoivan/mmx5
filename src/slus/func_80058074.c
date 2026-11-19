#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/title.h"

extern s16 D_8007DC74[][3];
extern u8 D_8009A197;
extern void func_80057EDC(u8* a0);

void func_80058074(u8* a0) {
    if (is_off_screen(a0, D_8007DC74[((s8*)a0)[2]][1],
                      D_8007DC74[((s8*)a0)[2]][2]) == 0) {
        if (D_8009A197 == 0) {
            func_80057EDC(a0);
        }
    } else if (a0[0x15] == 0) {
        if (((s8*)a0)[2] == 8) {
            func_8002D760(a0);
        } else {
            func_8002D760(a0);
        }
    }
}
