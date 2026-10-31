/* Shared body (DK-5), from the banked draft of func_800FA848_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern s16 D_80101BFC_ovl07[][2];
extern s16 D_80102014_ovl07;
extern s16 D_80102016_ovl07;

void DEDUP_NAME(u8* arg0) {
    s32 x;
    s32 y;

    func_80017248(arg0);
    func_8002DF54(arg0);
    x = D_80101BFC_ovl07[D_1F80004C.bytes[0x90]][0] + D_80102014_ovl07;
    if (*(s16*)(arg0 + 0xA) >= x - 8 && x + 8 >= *(s16*)(arg0 + 0xA)) {
        y = D_80101BFC_ovl07[D_1F80004C.bytes[0x90]][1] + D_80102016_ovl07;
        if (*(s16*)(arg0 + 0xE) >= y - 8 && y + 8 >= *(s16*)(arg0 + 0xE)) {
            D_1F80004C.bytes[0x92] = 0;
            switch (D_1F80004C.bytes[0x90]) {
            case 0:
                arg0[0x15] = 0;
                func_800171E8(arg0, 0x14);
                break;
            case 1:
                arg0[0x15] = 0x40;
                func_800171E8(arg0, 0x14);
                break;
            case 2:
                arg0[0x15] = 0;
                func_800171E8(arg0, 0x12);
                break;
            }
            arg0[6]++;
        }
    }
}
