/* Shared body (DK-5), from the banked draft of func_800F51FC_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D1A4();
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s16 D_800FA24C_ovl03;
extern s16 D_800FA24E_ovl03;

void DEDUP_NAME(u8* obj) {
    s32 i;
    s8 state;
    u8* child;

    if (*(s32*)(obj + 0x24) > 0) {
        if (*(s16*)(obj + 0xE) <= D_800FA24C_ovl03) {
            *(s16*)(obj + 0xE) = D_800FA24C_ovl03;
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else if (*(s32*)(obj + 0x24) < 0 &&
               *(s16*)(obj + 0xE) >= D_800FA24E_ovl03) {
        *(s16*)(obj + 0xE) = D_800FA24E_ovl03;
    clear:
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s32*)(obj + 0x24) == 0) {
        state = obj[7];
        if (state == 0 || state == 3 || state == 6 || state == 9) {
            func_800171E8(obj, 8);
            for (i = 0; i < 3; i++) {
                child = func_8002D1A4();
                if (child != 0) {
                    child[0] = 0x61;
                    child[1] = 0x15;
                    child[2] = i;
                    *(u8**)(child + 0x7C) = obj;
                }
            }
        } else {
            func_800171E8(obj, 9);
            for (i = 0; i < 3; i++) {
                child = func_8002D1A4();
                if (child != 0) {
                    child[0] = 0x61;
                    child[1] = 0x15;
                    child[2] = i + 3;
                    *(u8**)(child + 0x7C) = obj;
                }
            }
        }
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
