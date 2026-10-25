/* Shared body (DK-5), from the banked draft of func_800F07E0_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8002DF54(Ent06BC*);
extern s32 func_800F0FF4_ovl04(Ent06BC*, s32);
extern u8 D_80101480_ovl04[][8];

#define G D_1F80004C.bytes
void DEDUP_NAME(Ent06BC* arg0) {
    s32 r;
    u8* p;
    s32 e;

    func_8002DF54(arg0);
    r = func_800F0FF4_ovl04(arg0, 3);
    switch (r) {
    case 2:
        arg0->u5 = D_80101480_ovl04[G[0x80]][7];
        arg0->u6 = 0;
        break;
    case 1:
        if (G[0x82] == 1) {
            arg0->u67 = 1;
            arg0->u28 = 0;
            arg0->u20 = 0;
            arg0->u24 = 0;
            arg0->u2C = 0x4200;
            arg0->u5 = 6;
            arg0->u6 = 0;
        } else {
            G[0x82] = 1;
            arg0->u5 = D_80101480_ovl04[G[0x80]][3];
            arg0->u6 = 0;
            p = arg0->u68;
            e = arg0->uE;
            arg0->uE = e - ((arg0->uE + (signed char)p[1] - p[3]) & 0xF);
        }
        return;
    }
    G[0x82] = 0;
}
