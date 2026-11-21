#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

extern void func_800F0C98_ovl00();
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern u8 D_8009A197;
extern u8 D_800FA86C_ovl00[];
extern void* D_800FA88C_ovl00[];
extern void* D_800FA89C_ovl00;

void func_800EF204_ovl00(u8* obj) {
    u8* scr;
    s32 r;

    func_800F0C98_ovl00();
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        scr = D_1F80004C.bytes;
        if (scr[0x85] != 0) {
            (*(u8**)(scr + 0x80))[0x84] = 0;
        }
        func_8004FD24(obj);
        func_8004D4F4(3, D_800FA86C_ovl00, obj);
        func_80054440(obj, 0x12);
        obj[4] = 3;
        return;
    }
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    if (D_8009A197 == 0) {
        ((void (*)(u8*))D_800FA88C_ovl00[((s8*)obj)[5]])(obj);
        animate_object(obj);
    } else if (((s8*)obj)[5] == 4) {
        ((void (*)(u8*))D_800FA89C_ovl00)(obj);
    }
    if (((s8*)obj)[2] >= 2) {
        r = is_off_screen(obj, 0xC0, 0x40);
    } else {
        r = is_off_screen(obj, 0x40, 0x40);
    }
    if (r == 1) {
        scr = D_1F80004C.bytes;
        if (scr[0x85] != 0) {
            (*(u8**)(scr + 0x80))[0x84] = 0;
        }
        D_1F80004C.bytes[0x93] = r;
        obj[4] = 3;
        return;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    if ((obj[0x70] & 0xC) == 4) {
        scr = D_1F80004C.bytes;
        if (scr[0x85] != 0) {
            (*(u8**)(scr + 0x80))[0x84] = 0;
        }
        func_8004FD24(obj);
        func_8004D4F4(3, D_800FA86C_ovl00, obj);
        obj[4] = 3;
        return;
    }
    func_8002FB58(obj);
}

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);
extern void func_800EF91C_ovl00(s32, s16, s16, s16, s16, s32);
extern s16 D_8009A1F8[];

void func_800EF400_ovl00(u8* obj) {
    u8* q;
    u8* p;
    s8 st;

    if (D_1F80004C.bytes[0x90] == 0) {
        q = *(u8**)(D_1F80004C.bytes + 0x80);
        if (((s8*)q)[2] == 0) {
            st = ((s8*)q)[5];
            if (st == 3) {
                set_animation(obj, 1);
                obj[5] = st;
                obj[6] = 0;
                return;
            }
        }
        if (obj[0x70] & 8) {
            p = *(u8**)(D_1F80004C.bytes + 0x80);
            p[0x87] = 1;
            start_pad_vibration(8);
            play_sound(5, 5, 0);
            if (D_8009A1F8[0x10] == D_8009A1F8[7]) {
                func_8002A600(8, 4, 2);
            }
            func_800EF91C_ovl00(
                0x11, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE) + 0x10,
                *(s16*)(obj + 0xA) + 0x1C, *(s16*)(obj + 0xE) + 0x20, 3);
            func_800EF91C_ovl00(0x12, *(s16*)(obj + 0xA) - 0x1C,
                                *(s16*)(obj + 0xE) + 0x10, *(s16*)(obj + 0xA),
                                *(s16*)(obj + 0xE) + 0x20, 3);
            obj[6] = 2;
            *(s16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x8A) =
                *(s16*)(obj + 0xE) -
                *(s16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xE);
        }
        *(s16*)(obj + 0xA) = *(s16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xA);
        *(s16*)(obj + 0xE) = *(s16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xE) +
                             *(s16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x8A);
    }
}

extern s16 D_8009A1F8[];
extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);
extern void func_800F0740_ovl27(s32, s16, s16, s16, s16, s32);

void func_800F0408_ovl27(Self780* self) {
    Scr780* scr = D_1F80004C.scr780;
    Pl780* pl;

    if (scr->unk90 != 0) {
        return;
    }
    if (self->unk70 & 2) {
        scr->unk80->unk87 = 1;
        start_pad_vibration(8);
        play_sound(5, 5, 0);
        if (D_8009A1F8[0x10] == D_8009A1F8[7]) {
            func_8002A600(8, 4, 2);
        }
        func_800F0740_ovl27(0x11, self->unkA - 0x20, self->unkE - 0x14,
                            self->unkA - 0x10, self->unkE, 3);
        func_800F0740_ovl27(0x18, self->unkA - 0x20, self->unkE,
                            self->unkA - 0x10, self->unkE + 0x14, 3);
        self->unk6 = 4;
        pl = D_1F80004C.scr780->unk80;
        pl->unk8A = pl->unkA - self->unkA;
    }
    self->unkA =
        D_1F80004C.scr780->unk80->unkA - D_1F80004C.scr780->unk80->unk8A;
    self->unkE = D_1F80004C.scr780->unk80->unkE;
}

extern s16 D_8009A1F8[];
extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);
extern void func_800EF91C_ovl00(s32, s16, s16, s16, s16, s32);

void func_800EF780_ovl00(Self780* self) {
    Scr780* scr = D_1F80004C.scr780;
    Pl780* pl;

    if (scr->unk90 != 0) {
        return;
    }
    if (self->unk70 & 1) {
        scr->unk80->unk87 = 1;
        start_pad_vibration(8);
        play_sound(5, 5, 0);
        if (D_8009A1F8[0x10] == D_8009A1F8[7]) {
            func_8002A600(8, 4, 2);
        }
        func_800EF91C_ovl00(0x12, self->unkA + 0x10, self->unkE - 0x14,
                            self->unkA + 0x20, self->unkE, 3);
        func_800EF91C_ovl00(0x14, self->unkA + 0x10, self->unkE,
                            self->unkA + 0x20, self->unkE + 0x14, 3);
        self->unk6 = 6;
        pl = D_1F80004C.scr780->unk80;
        pl->unk8A = self->unkA - pl->unkA;
    }
    self->unkA =
        D_1F80004C.scr780->unk80->unkA + D_1F80004C.scr780->unk80->unk8A;
    self->unkE = D_1F80004C.scr780->unk80->unkE;
}
