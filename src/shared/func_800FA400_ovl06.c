/* Shared body (DK-5), from the banked draft of func_800FA400_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8002DF54(u8* a0);
extern s32 func_8002FB58(u8* obj);
extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_80074EE0[];
extern u8 D_80075FC0[];

void DEDUP_NAME(u8* obj) {
    func_8002DF54(obj);
    *(u8**)(obj + 0x58) = D_80074EE0;
    func_8002FB58(obj);
    func_80017248(obj);
    if (!(obj[0x70] & 3)) {
        if (obj[0x15] == 0) {
            if (*(s16*)(obj + 0xA) >= *(s16*)(D_1F80004C.bytes + 0x8C) - 0xA0) {
                return;
            }
        } else {
            if (*(s16*)(D_1F80004C.bytes + 0x8C) + 0xA0 >= *(s16*)(obj + 0xA)) {
                return;
            }
        }
    }
    func_800171E8(obj, 0x1E);
    *(u8**)(obj + 0x58) = D_80075FC0;
    obj[0x62] = 0;
    obj[6]++;
}
