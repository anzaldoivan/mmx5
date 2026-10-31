/* Shared body (DK-5), from the banked draft of func_800F3834_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_80044DE0();
extern s32 func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8003D2C4(void);
extern u8 D_8009A1F8[];
extern s8 D_800D1C00[];
extern u8 D_800FC1C8_ovl10;

void DEDUP_NAME(u8* obj) {
    u8* q;
    u8* p;
    u8* r;
    u8* q2;

    func_80017248(obj);
    if (func_80044DE0() == 0) {
        if (--*(s16*)(obj + 0x7E) == 0) {
            func_80016490(0, 0xE, 0);
            *(s16*)(obj + 0x7E) = 3;
        }
        if (D_800D1C00[0xC] != 0xC) {
            q = D_8009A1F8;
            *(s16*)(q + 0x26) = 0x1F50;
        } else {
            q2 = D_8009A1F8;
            *(s16*)(q2 + 0x26) = 0xA50;
        }
        if ((s8)++obj[0x5C] == D_800D1C00[0xA2]) {
            if (D_800D1C00[0xC] != 0xC) {
                p = D_8009A1F8;
                *(s16*)(p + 0x24) = 0x1F70;
            } else {
                p = D_8009A1F8;
                *(s16*)(p + 0x24) = 0xA70;
            }
            r = D_8009A1F8;
            r[0x48] = D_800FC1C8_ovl10;
            func_800171E8(obj, 0x17);
            obj[5] = 9;
            obj[6] = 0;
            func_8003D2C4();
        }
    }
}
