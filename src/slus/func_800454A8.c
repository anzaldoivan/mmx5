#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8* func_8002D078();
extern void func_80044F78(void* arg0);
extern Obj8002CC08 D_80098120[];

void func_800454A8(u8* arg0) {
    u8* g = g_Player;
    u8* s2 = arg0 + 0x8C;
    u32 lim;
    s32 n;
    s32 i;
    Obj8002CC08* p;
    u8* o;

    move_object(arg0);
    lim = 1;
    if (g[0xFA] == 4) {
        lim = 3;
    }
    if (*(s8*)(arg0 + 0x98) != 0) {
        n = 0;
        if (s2[2] < lim) {
            for (i = 0; i < 32; i++) {
                p = &D_80098120[i];
                if (p->active != 0 && ((s8*)p)[1] == 0x15 && ((s8*)p)[4] == 1) {
                    n++;
                }
            }
            if (n < (s32)lim) {
                o = func_8002D078();
                if (o != 0) {
                    o[0] = 0x21;
                    o[1] = 0x15;
                    o[2] = 0;
                    o[0x14] = arg0[0x14];
                    *(s32*)(o + 8) = *(s32*)(arg0 + 8);
                    *(s32*)(o + 0xC) = *(s32*)(arg0 + 0xC);
                    o[0x15] = arg0[0x15];
                    s2[2]++;
                }
            }
        }
        if (*(s8*)(arg0 + 0x98) < 0) {
            arg0[3] = 0;
            arg0[4] = 3;
            *(s32*)(arg0 + 0x50) = 0;
            *(s32*)(arg0 + 0x68) = 0;
            return;
        }
        arg0[0x98] = 0;
    }
    if (arg0[0x70] != 0 || (((s32(*)())func_8002F8FC)(arg0), arg0[0x70] != 0)) {
        func_80044F78(arg0);
        arg0[3] = 0;
        arg0[4] = 3;
        *(s32*)(arg0 + 0x50) = 0;
        *(s32*)(arg0 + 0x68) = 0;
    }
    func_8002D9EC(arg0, 0x2A, 0x22);
}
