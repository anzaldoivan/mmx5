#include "types.h"
#include "addr.h"

extern s32 func_8002DF78();
extern u8* func_8002D210();
extern signed char D_800D1CA2;
extern u8 D_800FEB34_ovl39[];

void func_800FA828_ovl39(u8* arg0) {
    u32 r;
    u8* p;
    u8* q;
    u8* o;
    s32 v;
    s32 i;

    r = func_8002DF78() & 0xF;
    if (D_800D1CA2 / 2 < ((s8*)arg0)[0x5C]) {
        D_1F80004C.bytes[0x86] = 0;
    } else if (r < 7) {
        D_1F80004C.bytes[0x86] = 1;
    } else {
        D_1F80004C.bytes[0x86] = 2;
    }
    if (D_1F80004C.bytes[0x8C] == 0) {
        if (!(*(s32*)(D_1F80004C.bytes + 0x8C) & 0xFFFF00)) {
            v = (func_8002DF78() & 1) + 2;
            q = D_1F80004C.bytes;
            q[0x8E] = v;
            q[0x8D] = v;
            if (((s8*)arg0)[7] == 0) {
                D_1F80004C.bytes[0x89] = 0;
                D_1F80004C.bytes[0x8A] = 0;
                D_1F80004C.bytes[0x8B] = 0;
                D_1F80004C.bytes[0x88] = 1;
                for (i = 0; i < 2; i++) {
                    o = func_8002D210();
                    if (o != 0) {
                        o[0] = 0x61;
                        o[1] = 0x1D;
                        o[2] = i;
                        *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
                        *(s32*)(o + 0x30) = *(s32*)(arg0 + 0x30);
                        *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
                        *(u16*)(o + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
                        *(u8**)(o + 0x7C) = arg0;
                        o[4] = 0;
                    }
                }
                arg0[7] = 0x11;
            }
        }
    } else if (((s8*)arg0)[7] == 0 && D_1F80004C.bytes[0x88] == 0) {
        D_1F80004C.bytes[0x8C] = D_1F80004C.bytes[0x8C] - 1;
        goto end; // !FAKE: goto kept for the matching branch layout
    }
    D_1F80004C.bytes[0x86] = 3;
end:
    D_1F80004C.bytes[0x87] = 0;
    p = D_1F80004C.bytes;
    arg0[5] = D_800FEB34_ovl39[p[0x87] + p[0x86] * 2];
    arg0[6] = 0;
}
