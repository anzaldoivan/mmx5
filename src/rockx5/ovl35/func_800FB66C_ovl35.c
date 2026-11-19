#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_800FFC66_ovl35;
extern s16 D_800FFC68_ovl35;
extern s16 D_800FFC6E_ovl35;
extern s16 D_800FFC70_ovl35;
extern s16 D_800FFC72_ovl35;
extern s16 D_800FFC74_ovl35;
extern s16 D_800FFC76_ovl35;
extern s16 D_800FFC78_ovl35;
extern s16 D_800FFC7A_ovl35;
extern s16 D_800FFC7C_ovl35;
extern s16 D_800FFC7E_ovl35;
extern s16 D_800FFC80_ovl35;
extern s16 D_800FFC82_ovl35;
extern s16 D_800FFC84_ovl35;
extern s16 D_800FFC86_ovl35;
extern s16 D_800FFC88_ovl35;
extern s16 D_800FFC8A_ovl35;
extern s16 D_800FFC8C_ovl35;
extern s16 D_800FFC8E_ovl35;
extern s16 D_800FFC90_ovl35;

// from rockx5 800FB66C (byte twin of 800F3160_ovl09): on timeout or leaving the x window, pick a new pattern (not the last) and set its speeds
void func_800FB66C_ovl35(Ent3160* e) {
    u8 r;

    func_8002D9EC(e, 0x40, 0x40);
    animate_object(e);
    apply_object_motion(e);
    if (--e->unk7C == 0 || e->unkA < D_800FFC66_ovl35 ||
        D_800FFC68_ovl35 < e->unkA) {
        play_sound(2, 0x27, e);
        if (e->unk7E == 4) {
            r = random_byte() % 3;
            if (r == e->unk91) {
                r++;
                if (r >= 3) {
                    r -= 2;
                }
            }
        } else {
            r = random_byte() % 8 + 1;
            if (r == e->unk91) {
                r++;
                if (r >= 9) {
                    r -= 2;
                }
            }
        }
        e->unk91 = r;
        set_animation(e, 3);
        e->unk90 = e->unk47;
        switch (r) {
        case 0:
            e->unk84 = D_800FFC6E_ovl35;
            e->unk88 = D_800FFC70_ovl35;
            break;
        case 1:
            e->unk84 = D_800FFC72_ovl35;
            e->unk88 = D_800FFC74_ovl35;
            break;
        case 2:
            e->unk84 = D_800FFC76_ovl35;
            e->unk88 = D_800FFC78_ovl35;
            break;
        case 3:
            e->unk84 = D_800FFC7A_ovl35;
            e->unk88 = D_800FFC7C_ovl35;
            break;
        case 4:
            e->unk84 = D_800FFC7E_ovl35;
            e->unk88 = D_800FFC80_ovl35;
            break;
        case 5:
            e->unk84 = D_800FFC82_ovl35;
            e->unk88 = D_800FFC84_ovl35;
            break;
        case 6:
            e->unk84 = D_800FFC86_ovl35;
            e->unk88 = D_800FFC88_ovl35;
            break;
        case 7:
            e->unk84 = D_800FFC8A_ovl35;
            e->unk88 = D_800FFC8C_ovl35;
            break;
        case 8:
            e->unk84 = D_800FFC8E_ovl35;
            e->unk88 = D_800FFC90_ovl35;
            break;
        }
        if (e->unk15 == 0) {
            e->unk28 = e->unk20 / 35;
        } else {
            e->unk28 = -e->unk20 / 35;
        }
        e->unk54 = 0;
        e->unk7C = 0;
        e->unk6++;
    }
}
