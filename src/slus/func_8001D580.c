#include "types.h"

extern Str18 D_800100A0;

extern void memset(void* dst, s32 c, s32 n);
extern s32 open(u8* name, s32 mode);
extern int VSync(int mode);
extern s32 read(s32 fd, u8* buf, s32 n);
extern void close(s32 fd);

s32 func_8001D580(u8* dst, s32 idx) {
    Name20 name;
    s32 fd;
    s32 n;

    name.s = D_800100A0;
    memset(name.pad, 0, 2);
    do {
        name.s.b[2] += idx;
    } while (0); // !FAKE: fences the sched1 hoist of the loop constants
    n = 30;
    do {
        fd = open(name.s.b, 1);
        if (fd != -1) {
            goto opened; // !FAKE: goto kept for the matching branch layout
        }
        VSync(2);
    } while (--n != 0);
    return 1;
opened: // !FAKE: label kept for the matching branch layout
    n = 30;
    do {
        if (read(fd, dst, 0x1000) == 0x1000) {
            close(fd);
            return 0;
        }
        VSync(2);
    } while (--n != 0);
    close(fd);
    return 2;
}
