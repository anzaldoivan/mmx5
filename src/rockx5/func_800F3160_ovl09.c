#include "types.h"

extern s16 D_800FB62E_ovl09;
extern s16 D_800FB630_ovl09;
extern s16 D_800FB636_ovl09;
extern s16 D_800FB638_ovl09;
extern s16 D_800FB63A_ovl09;
extern s16 D_800FB63C_ovl09;
extern s16 D_800FB63E_ovl09;
extern s16 D_800FB640_ovl09;
extern s16 D_800FB642_ovl09;
extern s16 D_800FB644_ovl09;
extern s16 D_800FB646_ovl09;
extern s16 D_800FB648_ovl09;
extern s16 D_800FB64A_ovl09;
extern s16 D_800FB64C_ovl09;
extern s16 D_800FB64E_ovl09;
extern s16 D_800FB650_ovl09;
extern s16 D_800FB652_ovl09;
extern s16 D_800FB654_ovl09;
extern s16 D_800FB656_ovl09;
extern s16 D_800FB658_ovl09;
extern void func_8002D9EC(Ent3160*, s32, s32);
extern void func_80017248(Ent3160*);
extern void func_8002DED4(Ent3160*);
extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_800171E8(Ent3160*, s32);

// from rockx5 800F3160: on timeout or leaving the x window, pick a new pattern (not the last) and set its speeds
void func_800F3160_ovl09(Ent3160* e) {
    u8 r;

    func_8002D9EC(e, 0x40, 0x40);
    func_80017248(e);
    func_8002DED4(e);
    if (--e->unk7C == 0 || e->unkA < D_800FB62E_ovl09 ||
        D_800FB630_ovl09 < e->unkA) {
        func_80016490(2, 0x27, e);
        if (e->unk7E == 4) {
            r = func_8002DF78() % 3;
            if (r == e->unk91) {
                r++;
                if (r >= 3) {
                    r -= 2;
                }
            }
        } else {
            r = func_8002DF78() % 8 + 1;
            if (r == e->unk91) {
                r++;
                if (r >= 9) {
                    r -= 2;
                }
            }
        }
        e->unk91 = r;
        func_800171E8(e, 3);
        e->unk90 = e->unk47;
        switch (r) {
        case 0:
            e->unk84 = D_800FB636_ovl09;
            e->unk88 = D_800FB638_ovl09;
            break;
        case 1:
            e->unk84 = D_800FB63A_ovl09;
            e->unk88 = D_800FB63C_ovl09;
            break;
        case 2:
            e->unk84 = D_800FB63E_ovl09;
            e->unk88 = D_800FB640_ovl09;
            break;
        case 3:
            e->unk84 = D_800FB642_ovl09;
            e->unk88 = D_800FB644_ovl09;
            break;
        case 4:
            e->unk84 = D_800FB646_ovl09;
            e->unk88 = D_800FB648_ovl09;
            break;
        case 5:
            e->unk84 = D_800FB64A_ovl09;
            e->unk88 = D_800FB64C_ovl09;
            break;
        case 6:
            e->unk84 = D_800FB64E_ovl09;
            e->unk88 = D_800FB650_ovl09;
            break;
        case 7:
            e->unk84 = D_800FB652_ovl09;
            e->unk88 = D_800FB654_ovl09;
            break;
        case 8:
            e->unk84 = D_800FB656_ovl09;
            e->unk88 = D_800FB658_ovl09;
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
