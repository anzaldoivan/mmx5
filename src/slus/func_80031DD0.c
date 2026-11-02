#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_80074E40[];
extern u8 D_800D1C4A;
extern Obj8002CC08 D_80098120[];
extern u8 D_800D1C00[];
extern s32 func_8002E408(u8* p, s32 a, u8* b, u8* c);
extern s32 func_80031F60(u8*, Obj8002CC08*);

s32 func_80031DD0(u8* arg0) {
    Obj8002CC08* p;
    u8* g;
    u8* c;
    s32 ok;
    s32 v;

    g = D_8009A0A0;
    if (*(s8*)(arg0 + 0x7A) == 0) {
        if (*(u8**)(arg0 + 0x58) == D_80074E40) {
            ok = 0;
            if (((s8*)g)[2] == 0) {
                ok = g[0xFA] == 3;
            } else {
                if (*(s32*)(g + 0xFC) & 0x10000) {
                    ok = 1;
                }
                if (D_800D1C4A & 0x10) {
                    ok = 1;
                }
            }
            if (ok == 0) {
                return 0;
            }
        }
        if (*(s8*)(arg0 + 5) != 0) {
            *(u16*)(arg0 + 0x42) &= 0x7FFF;
        }
        for (p = D_80098120; p < D_80098120 + 32; p++) {
            c = D_800D1C00;
            if (p->active != 0 &&
                func_8002E408((u8*)p, (s32)arg0, (u8*)p + 0x80,
                              (u8*)p + 0x82) != 0) {
                v = func_80031F60(arg0, p);
                if (v == 0x7E) {
                    return 0;
                }
                if (v < 0 && *(u8**)(arg0 + 0x58) != D_80074E40) {
                    (*(s32*)(c + 0xB4))++;
                }
                if (v != 0) {
                    return v;
                }
            }
        }
    }
    arg0[0x65] = 0;
    return 0;
}
