#include "types.h"
#include "mmx5/globals.h"

extern int func_8002D7A0();

void func_800F2410_ovl04(u8* arg0) {
    u8* p;

    if (((s8*)arg0)[5] == 4) {
        p = g_Player;
        p[0xCA] = 0;
        if (p[0x5C] & 0x7F) {
            p[3] = 1;
        }
    }
    func_8002D7A0();
}
