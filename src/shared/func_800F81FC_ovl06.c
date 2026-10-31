/* Shared body (DK-5), from the banked draft of func_800F81FC_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DED4(u8* obj);
extern void func_80017248(u8* obj);
extern s32 func_8002FB58(u8* obj);
extern void func_8001296C(s32);
extern void func_80016490(s32, s32, u8*);
extern void func_800171E8(u8*, s32);
extern void func_800FAFFC_ovl06(u8*, s32, s32, s32);

void DEDUP_NAME(u8* obj) {
    func_8002DED4(obj);
    func_80017248(obj);
    func_8002FB58(obj);
    if (obj[0x70] & 8) {
        func_8001296C(5);
        func_80016490(2, 7, obj);
        func_800171E8(obj, 0x1B);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) - 0x48),
                            *(s16*)(obj + 0xE), 4);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) - 0x38),
                            *(s16*)(obj + 0xE), 3);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) - 0x28),
                            *(s16*)(obj + 0xE), 2);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) - 0x18),
                            *(s16*)(obj + 0xE), 1);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) - 8),
                            *(s16*)(obj + 0xE), 0);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) + 8),
                            *(s16*)(obj + 0xE), 0);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) + 0x18),
                            *(s16*)(obj + 0xE), 1);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) + 0x28),
                            *(s16*)(obj + 0xE), 2);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) + 0x38),
                            *(s16*)(obj + 0xE), 3);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) + 0x48),
                            *(s16*)(obj + 0xE), 4);
        *(s16*)(obj + 0x7C) = 0x3C;
        obj[6]++;
    }
}
