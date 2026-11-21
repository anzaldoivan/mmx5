#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern u8 D_8009A0B4;
extern u8 D_800750C0[];
extern u8 D_800F9624_ovl03[];
extern u8 D_800F959C_ovl03[];
extern u8 D_800F95A4_ovl03[];
extern u16 D_800D1C0C;

void func_800EF094_ovl03(ObjEF094* e) {
    e->unk0 = 0x41;
    e->unk5C = 3;
    e->unk60 = 3;
    e->unk61 = 0;
    e->unk14 = D_8009A0B4;
    e->unk58 = D_800750C0;
    e->unk20 = 0;
    e->unk30 = D_800F9624_ovl03;
    e->unk16 = 6;
    e->unk54 = D_800F959C_ovl03;
    e->unk50 = D_800F95A4_ovl03;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk67 = 0;
    e->unk68 = 0;
    e->unk80 = 0;
    e->unk84 = 0;
    e->unk88 = 0;
    e->unk8C = 0;
    e->unk90 = 0;
    e->unk94 = 0;
    e->unk18 = e->unk8;
    e->unk1C = e->unkC;
    e->unk4++;
    switch (e->unk2) {
    case 0:
        set_animation(e, 0);
        e->unk5 = 2;
        break;
    case 1:
        set_animation(e, 3);
        e->unk5 = 5;
        e->unk88 = 1;
        break;
    case 4:
        set_animation(e, 3);
        e->unk5 = 7;
        e->unk88 = 1;
        break;
    default:
        set_animation(e, 3);
        e->unk5 = 6;
        e->unk88 = 1;
        break;
    }
    e->unk6 = 0;
    if (D_800D1C0C == 2) {
        e->unk7 = e->unk5;
        e->unk5 = 9;
        e->unk54 = 0;
        e->unk50 = 0;
    }
}

extern u8 D_8009A197;
extern void (*D_800F9660_ovl03[])(ObjEF094*);
extern void* D_800F9658_ovl03[];
extern u8 D_800F9644_ovl03[];
extern void func_800EFD08_ovl03(ObjEF094*);
extern void func_8004D4F4(s32, void*, ObjEF094*);
extern void func_80054440(ObjEF094*, s32);

void func_800EF220_ovl03(ObjEF094* e) {
    u8 hit;
    u8 i;
    s32 r;
    s32 state;

    if (D_8009A197 == 0) {
        e->unk18 = e->unk8;
        e->unk1C = e->unkC;
        D_800F9660_ovl03[e->unk5](e);
    }
    hit = func_800317B8(e);
    if (e->unk2 == 4 && hit == 1) {
        e->unk5 = 8;
        e->unk6 = 0;
    }
    if (e->unk5 != 0) {
        e->unk94 = e->unk5;
    }
    if (e->unk5 != 9) {
        for (i = 0; i < 2 - e->unk88; i++) {
            e->unk54 = D_800F9658_ovl03[i];
            r = func_80031DD0(e);
            if (r < 0) {
                if (i == 0 && e->unk88 == 0) {
                    func_800EFD08_ovl03(e);
                }
                func_8004FD24(e);
                func_8004D4F4(4, D_800F9644_ovl03, e);
                func_80054440(e, 8);
                state = e->unk4 + 1;
                goto end; // !FAKE: shared store tail with the 0x20 probe below
            }
            if (r != 0) {
                break;
            }
        }
    }
    if (is_off_screen(e, 0x20, 0x20) == 0) {
        if (e->unk5 != 9) {
            func_8002D9EC(e, 0x20, 0x20);
        }
        return;
    }
    state = 3;
end:
    e->unk4 = state;
}
