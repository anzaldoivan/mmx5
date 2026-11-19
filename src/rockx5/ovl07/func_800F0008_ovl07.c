#include "types.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

extern s32 func_800F09A0_ovl07(u8* p);
extern void func_800F0AC4_ovl07(u8* o);
extern void func_800F0AA0_ovl07(u8* o);
extern s32 D_801007F0_ovl07[];
extern s32 D_801007F8_ovl07[];
extern s32 D_80100800_ovl07[];
extern s32 D_80100808_ovl07[];
extern s32 D_80100810_ovl07[];
extern s32 D_80100818_ovl07[];

void func_800F0008_ovl07(u8* o) {
    s32 v;

    switch (func_800F09A0_ovl07(o)) {
    case 0:
        if (o[0x7C] == 0) {
            v = D_801007F0_ovl07[o[0x7D]];
            if (v >= *(s32*)(o + 0x20)) {
                goto store; // !FAKE: goto kept for the matching branch layout
            }
            goto ed4; // !FAKE: goto kept for the matching branch layout
        }
        v = D_801007F8_ovl07[o[0x7D]];
        if (*(s32*)(o + 0x20) >= v) {
            goto ed4; // !FAKE: goto kept for the matching branch layout
        }
        goto aa0; // !FAKE: goto kept for the matching branch layout
    case 1:
        if (o[0x7C] != 0) {
            v = D_80100800_ovl07[o[0x7D]];
            if (*(s32*)(o + 0x20) < v) {
                goto aa0; // !FAKE: goto kept for the matching branch layout
            }
        store:
            *(s32*)(o + 0x20) = v;
            func_800F0AC4_ovl07(o);
            break;
        }
        v = D_80100808_ovl07[o[0x7D]];
        if (v < *(s32*)(o + 0x20)) {
        aa0:
            func_800F0AA0_ovl07(o);
            move_object(o);
            break;
        }
    ed4:
        apply_object_motion(o);
        break;
    default:
        if (o[0x7C] == 0) {
            apply_object_motion(o);
            v = D_80100810_ovl07[o[0x7D]];
            if (v - *(s32*)(o + 0x20) >= 0) {
                *(s32*)(o + 0x20) = v;
            }
        } else {
            func_800F0AA0_ovl07(o);
            move_object(o);
            v = D_80100818_ovl07[o[0x7D]];
            if (v - *(s32*)(o + 0x20) < 0) {
                *(s32*)(o + 0x20) = v;
            }
        }
        break;
    }
}
