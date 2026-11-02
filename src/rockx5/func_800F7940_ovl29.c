#include "types.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern s32 D_800FA5B8_ovl29[];
extern s32 D_800FA5D8_ovl29[];
extern s32 D_800FA5F8_ovl29[];

void func_800F7940_ovl29(u8 n, u8* src, u8* base, s32 mode) {
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
            if (mode != 0) {
                obj[0x55] = 1;
                *(s32*)(obj + 0x20) = 0;
                *(s32*)(obj + 0x28) = 0;
                *(s32*)(obj + 0x24) = 0;
                *(s32*)(obj + 0x2C) = 0;
                obj[0x58] = 0;
                if (func_8002DF78() & 1) {
                    *(s32*)(obj + 8) =
                        *(s32*)(base + 8) + ((*(u8**)(base + 0x68))[2] << 16) +
                        D_800FA5D8_ovl29[func_8002DF78() & 7] / 2;
                } else {
                    *(s32*)(obj + 8) =
                        *(s32*)(base + 8) - ((*(u8**)(base + 0x68))[2] << 16) +
                        D_800FA5D8_ovl29[func_8002DF78() & 7] / 2;
                }
                *(s32*)(obj + 0xC) =
                    *(s32*)(base + 0xC) + D_800FA5F8_ovl29[func_8002DF78() & 7];
            } else {
                *(s32*)(obj + 0x20) = 0;
                obj[2] = 1;
                *(s32*)(obj + 8) =
                    *(s32*)(base + 8) + D_800FA5B8_ovl29[func_8002DF78() & 7];
                *(s32*)(obj + 0xC) =
                    *(s32*)(base + 0xC) + D_800FA5F8_ovl29[func_8002DF78() & 7];
                obj[0x58] = 1;
            }
            obj[0x54] = *src++;
        }
    }
}
