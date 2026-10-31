#include "types.h"

extern u8 D_8009A0A0[];
extern s32 func_8002E024(void*, void*);

void func_800F017C_ovl29(u8* arg0) {
    *(s16*)(arg0 + 0xE) -= 0x10;
    arg0[0x84] = func_8002E024(arg0, D_8009A0A0);
    *(s16*)(arg0 + 0xE) += 0x10;
    if (arg0[0x15] == 0) {
        switch (arg0[0x84]) {
        case 8:
        case 9:
            arg0[0x88] = 0;
            break;
        case 10:
        case 11:
        case 12:
        case 13:
            arg0[0x88] = 1;
            break;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
            arg0[0x88] = 2;
            break;
        case 19:
        case 20:
        case 21:
        case 22:
            arg0[0x88] = 3;
            break;
        case 23:
        case 24:
            arg0[0x88] = 4;
            break;
        }
    } else {
        switch (arg0[0x84]) {
        case 7:
        case 8:
            arg0[0x88] = 0;
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            arg0[0x88] = 1;
            break;
        case 0:
        case 1:
        case 2:
        case 30:
        case 31:
            arg0[0x88] = 2;
            break;
        case 26:
        case 27:
        case 28:
        case 29:
            arg0[0x88] = 3;
            break;
        case 24:
        case 25:
            arg0[0x88] = 4;
            break;
        }
    }
}
