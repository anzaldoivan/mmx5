#include "types.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern s32 D_800FA5B8_ovl29[];
extern s32 D_800FA5F8_ovl29[];

void func_800F7CB0_ovl29(u8 n, u8* src, u8* base, s32 arg) {
    u8* obj;

    for (; n != 0; n--) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = 0x41;
            obj[1] = 2;
            obj[0x15] = func_8002DF78() & 0x40;
            obj[4] = 0;
            obj[5] = 0;
            obj[6] = 0;
            obj[0x58] = 1;
            if (arg != -1) {
                *(s32*)(obj + 0x20) = arg;
                obj[2] = 0;
            } else {
                *(s32*)(obj + 0x20) = 0;
                obj[2] = 1;
            }
            *(s32*)(obj + 8) =
                *(s32*)(base + 8) + D_800FA5B8_ovl29[func_8002DF78() & 7];
            *(s32*)(obj + 0xC) =
                *(s32*)(base + 0xC) + D_800FA5F8_ovl29[func_8002DF78() & 7];
            obj[0x54] = *src++;
        }
    }
}
