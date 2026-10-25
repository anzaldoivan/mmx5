/* Adapted from mmx6 @c1c892d src/shared/rock_20/func_800EE4C0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern u8 D_800EE98C_ovl24[];
extern u8 D_800EE9A0_ovl24[];
int VSync(int mode);
void memset(void* dst, s32 c, s32 n);
s32 open(u8* name, s32 mode);
s32 read(s32 fd, u8* buf, s32 n);
s32 write(s32 fd, u8* buf, u32 n);
void close(s32 fd);

s32 func_800F2C4C_ovl24(u8* arg0, s32 arg1, u32 arg2) {
    u8 name[24];
    u8 buf[0x200];
    s32 fd;
    s32 n;
    s32 i;
    u32 tries;

    __builtin_memcpy(name, D_800EE98C_ovl24, 18);
    memset(name + 18, 0, 2);
    arg0[3] = (arg2 >> 13) + ((arg2 % 0x2000) != 0);
    __builtin_memcpy(arg0 + 4, D_800EE9A0_ovl24, 19);
    name[2] += arg1;
    close(open(name, (arg0[3] << 16) | 0x200));
    tries = 0;
    do {
        i = 30;
        do {
            fd = open(name, 2);
            if (fd != -1) {
                goto opened; // !FAKE: retry-loop exit as goto; structured form not tried against the bytes
            }
            VSync(2);
        } while (--i != 0);
        return 1;
    opened:
        i = 30;
        do {
            if (write(fd, arg0, arg2) == arg2) {
                goto written; // !FAKE: retry-loop exit as goto; structured form not tried against the bytes
            }
            VSync(2);
        } while (--i != 0);
        close(fd);
        return 2;
    written:
        close(fd);
        fd = open(name, 1);
        if (fd == -1) {
            break;
        }
        n = read(fd, buf, 0x200);
        close(fd);
        {
            // !FAKE: pins k to $3; gcc 2.7.2 allocates another register without it (byte mismatch)
            register s32 k asm("$3") = 0x200;
            if (n == k) {
                return 0;
            }
        }
        tries++;
    } while (tries < 3);
    return 2;
}
