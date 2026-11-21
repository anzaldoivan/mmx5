#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

extern s32 D_800F9634_ovl26[];
extern s32 D_800F9E30_ovl26[];
extern s32 D_800761A0[];
extern u8 D_8009A0B4;
extern u32* D_80098118;

void func_800F2074_ovl26(Ent2074* o) {
    o->unk4 = 1;
    o->unk6 = 0;
    o->unk60 = 0x20;
    o->unk62 = 0;
    o->unk54 = 0;
    o->unk50 = 0;
    o->unk68 = 0;
    if (o->unk2 == 1) {
        D_1F80004C.scr2074->unk94 = random_byte() & 7;
        if (D_1F80004C.scr2074->unk94 == 2 || D_1F80004C.scr2074->unk94 == 7) {
            D_1F80004C.scr2074->unk94 = 0;
        }
        D_1F80004C.scr2074->unk80->unk8F = 0;
        D_1F80004C.scr2074->unk80->unk88 = 0;
        D_1F80004C.scr2074->unk80->unk92 = 1;
        o->unk54 = &D_800F9634_ovl26[D_1F80004C.scr2074->unk94];
        switch (D_1F80004C.scr2074->unk94) {
        case 0:
            set_animation(o, 0xB);
            break;
        case 1:
            set_animation(o, 0x1B);
            break;
        case 2:
            set_animation(o, 0x1E);
            break;
        case 3:
            set_animation(o, 0x21);
            break;
        case 4:
            set_animation(o, 0x24);
            break;
        case 5:
            set_animation(o, 0x27);
            break;
        case 6:
            set_animation(o, 0x2A);
            break;
        case 7:
            set_animation(o, 0x2D);
            break;
        }
        o->unk16 = 5;
        o->unk14 = D_8009A0B4;
        o->unk58 = D_800761A0;
        o->unk5 = 6;
    } else if (o->unk2 == 2) {
        o->unk54 = D_800F9634_ovl26;
        set_animation(o, 0xB);
        o->unk16 = 5;
        o->unk14 = D_8009A0B4;
        o->unk58 = D_800761A0;
        o->unk5 = 6;
        o->unk6 = 9;
    } else {
        o->unk5C = 0;
        o->unk40 = (*D_80098118 >> 7) + 0xB0;
        o->unk14 = D_8009A0B4;
        o->unk16 = 6;
        o->unk15 = 0;
        o->unk3 = 0;
        o->unk58 = D_800761A0;
        o->unk61 = 0;
        func_8003D29C(0x14, 0x40);
        o->unkA = 0xA10;
        o->unkE = 0x1260;
        o->unk18 = 0xA10;
        o->unk1C = 0x1260;
        o->unk20 = 0;
        o->unk24 = 0;
        o->unk28 = 0;
        o->unk2C = 0;
        o->unk30 = D_800F9E30_ovl26;
        D_1F80004C.scr2074->unk8D = 0;
        D_1F80004C.scr2074->unk90 = 0;
        D_1F80004C.scr2074->unk91 = 0;
        D_1F80004C.scr2074->unk92 = 0;
        D_1F80004C.scr2074->unk93 = 0;
        D_1F80004C.scr2074->unk88 = 0;
        D_1F80004C.scr2074->unk96 = 0;
        D_1F80004C.scr2074->unk97 = 0;
        D_1F80004C.scr2074->unk8F = 0;
        o->unk5 = 2;
        o->unk7 = 0;
        o->unk3 = 0;
        set_animation(o, 0x19);
    }
}

extern void* D_800FA0D0_ovl26[];
extern u8 D_800FA682_ovl26;
extern s32 D_800761A0[];
extern u8 D_8009A11A;
extern u8 D_80074EE0[];

void func_800F23D4_ovl26(u8* o) {
    u8* s;
    u8* p;
    u8* q;
    s32 k;
    s32 v;
    u8 c;
    u8 d;

    ((void (*)(u8*))D_800FA0D0_ovl26[((s8*)o)[5]])(o);
    k = ((s8*)o)[0x45];
    if (k == 0x40) {
        play_sound(2, 0x5F, o);
    } else if (k == 0x41) {
        play_sound(2, 0x60, o);
    } else if (k == 0x42) {
        play_sound(2, 0x61, o);
    }
    if (D_1F80004C.bytes[0x8D] != 0 && o[2] == 0) {
        ((void (*)())func_800317B8)(o);
        if (D_800FA682_ovl26 == 1) {
            s = D_1F80004C.bytes;
            if (s[0x92] == 0) {
                s[0x8C] = 0;
                *(s32**)(o + 0x58) = D_800761A0;
                *(u16*)(o + 0x42) &= 0x7FFF;
            }
        }
        s = D_1F80004C.bytes;
        D_800FA682_ovl26 = s[0x92];
        c = s[0x92];
        if (c == 1) {
            v = *(s32*)(s + 0x88);
            o[0x5C] = s[0x95];
            if (v < 0) {
                if (o[0x47] == 0x4B) {
                    o[0x47] = 0x32;
                }
                D_8009A11A = c;
                o[4] = 2;
                o[5] = 0;
                return;
            }
            if (v > 0) {
                if (v != 0x7F) {
                    *(u8**)(o + 0x58) = D_80074EE0;
                    if ((u32)(v - 0x19) < 2) {
                        D_1F80004C.bytes[0x8C] = 2;
                    } else {
                        D_1F80004C.bytes[0x8C] = 0x1E;
                    }
                }
                if (v == 6 || v == 0xF || v == 0x25) {
                    if (D_1F80004C.bytes[0x8F] == 0 && !((u8)(o[5] - 10) < 2)) {
                        set_animation(o, 0x17);
                        D_1F80004C.bytes[0x8F] = 0x3C;
                    }
                }
            }
            q = D_1F80004C.bytes;
            d = q[0x8C];
            if (d != 0) {
                q[0x8C] = d + 0xFF;
                if (d & 2) {
                    *(u16*)(o + 0x42) |= 0x8000;
                } else {
                    *(u16*)(o + 0x42) &= 0x7FFF;
                }
                if (D_1F80004C.bytes[0x8C] == 0) {
                    *(s32**)(o + 0x58) = D_800761A0;
                    *(u16*)(o + 0x42) &= 0x7FFF;
                }
            }
        }
        func_8002D9EC(o, 0x60, 0x60);
        if (D_1F80004C.bytes[0x8F] != 0) {
            animate_object(o);
            s = D_1F80004C.bytes;
            if (--s[0x8F] == 0) {
                if (((s8*)o)[5] == 5) {
                    set_animation(o, 0x30);
                }
                D_1F80004C.bytes[0x8C] = 0x3C;
            }
            p = func_8002D27C();
            if (p != 0 && (D_1F80004C.bytes[0x8F] & 7) == 0) {
                p[0] = 0x41;
                p[1] = 0x3D;
                p[2] = 0;
                *(s32*)(p + 0x3C) = *(s32*)(o + 0x3C);
                *(u16*)(p + 0x40) = *(u16*)(o + 0x40);
                *(s32*)(p + 0x30) = *(s32*)(o + 0x30);
                *(u16*)(p + 0x42) = *(u16*)(o + 0x42);
                *(u16*)(p + 0xA) =
                    *(u16*)(o + 0xA) + ((random_byte() & 3) * 16 - 0x30);
                *(u16*)(p + 0xE) =
                    *(u16*)(o + 0xE) + ((random_byte() & 3) * 16 - 0x20);
                p[0x15] = random_byte() & 0x40;
                *(u8**)(p + 0x50) = o;
            }
        }
    } else if ((u8)(o[2] - 1) < 2) {
        *(s32**)(o + 0x58) = D_800761A0;
        if (*(u32*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x8C) & 0xFF0000FF) {
            *(u8**)(o + 0x58) = D_80074EE0;
        }
        *(s32*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x88) = func_80031DD0(o);
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x95] = o[0x5C];
        *(u16*)(o + 0x42) = *(u16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x42);
        *(void**)(o + 0x58) =
            *(void**)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x58);
        func_8002D9EC(o, 0x60, 0x60);
        if ((*(s8**)(D_1F80004C.bytes + 0x80))[4] == 2) {
            clear_object_slot(o);
        }
    }
}
