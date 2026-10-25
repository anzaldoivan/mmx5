# Mega Man X5 decompilation (mmx5)

## Description

**mmx5** is a matching decompilation of ***Mega Man X5*** (PlayStation, Capcom, 2000), USA release SLUS-01334. It
reconstructs C source. Compiled with the original era's toolchain and linked in the original order, this source
rebuilds the code binaries on the disc byte for byte. These binaries are the boot executable `SLUS_013.34` and the
code overlays inside `ROCK_X5.BIN`. Every build checks each binary's hash.

Readable, evidenced source is the first step towards understanding the game's engine and the code it shares with
*Mega Man X4* and *X6*. It is also the first step towards tools, documentation and ports built on this source. Anyone
with their own dump can rebuild the binaries from this README alone.

<!-- psxdecomp: ai-policy -->
> [!IMPORTANT]
> **AI policy:** LLMs produce negligible decompilation results without good guidance. Investigate and familiarize yourself with the console's architecture and the game you are decompiling, and always use your own judgment. Humans drive the decisions. AI reads and writes the code.

<!-- psxdecomp:disc:begin -->
| Disc | Serial | Executable | SHA-1 of the data track |
|---|---|---|---|
| USA | SLUS-01334 | `SLUS_013.34` | `10709231f857636b5ccd3cd9acebc91458dcb5fd` |

The target `SLUS_013.34` has SHA-1 `476e55ff4ac698a1ee0654c0f08804a5837bd2f3` (`config/check.slus.sha`). Every build checks its rebuild against it.
<!-- psxdecomp:disc:end -->

> [!IMPORTANT]
> This repository contains **no game data**: no executable, no disc data, no disassembly listing, no memory image,
> no vendor SDK. You build from your own legally obtained dump. The `.gitignore` is the firewall. The gate is
> `tools/audit_public.py` (its sources are in `config/firewall.txt`), and CI runs it on every push. See
> [`src/NOTICE.md`](src/NOTICE.md).

## Progress

<!-- psxdecomp:progress:begin -->
[![Code][psxd-code]][psxd-progress] [![Functions][psxd-functions]][psxd-progress]

| Category | Name | Status |
|---|---|---|
| `main` | SLUS_013.34 (boot executable) | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=main)](https://decomp.dev/anzaldoivan/mmx5?category=main) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=main)](https://decomp.dev/anzaldoivan/mmx5?category=main) |
| `rock` | ROCK_X5.BIN overlays | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock)](https://decomp.dev/anzaldoivan/mmx5?category=rock) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock)](https://decomp.dev/anzaldoivan/mmx5?category=rock) |
| `sdk` | PsyQ SDK libraries | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=sdk)](https://decomp.dev/anzaldoivan/mmx5?category=sdk) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=sdk)](https://decomp.dev/anzaldoivan/mmx5?category=sdk) |

<details><summary><code>rock</code>: 53 overlays</summary>

| Category | Name | Status |
|---|---|---|
| `rock.ovl00` | Overlay 00 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl00)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl00) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl00)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl00) |
| `rock.ovl01` | Overlay 01 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl01)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl01) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl01)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl01) |
| `rock.ovl02` | Overlay 02 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl02)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl02) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl02)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl02) |
| `rock.ovl03` | Overlay 03 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl03)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl03) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl03)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl03) |
| `rock.ovl04` | Overlay 04 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl04)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl04) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl04)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl04) |
| `rock.ovl05` | Overlay 05 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl05)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl05) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl05)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl05) |
| `rock.ovl06` | Overlay 06 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl06)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl06) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl06)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl06) |
| `rock.ovl07` | Overlay 07 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl07)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl07) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl07)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl07) |
| `rock.ovl08` | Overlay 08 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl08)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl08) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl08)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl08) |
| `rock.ovl09` | Overlay 09 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl09)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl09) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl09)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl09) |
| `rock.ovl10` | Overlay 10 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl10)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl10) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl10)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl10) |
| `rock.ovl11` | Overlay 11 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl11)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl11) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl11)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl11) |
| `rock.ovl12` | Overlay 12 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl12)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl12) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl12)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl12) |
| `rock.ovl14` | Overlay 14 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl14)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl14) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl14)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl14) |
| `rock.ovl16` | Overlay 16 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl16)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl16) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl16)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl16) |
| `rock.ovl18` | Overlay 18 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl18)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl18) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl18)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl18) |
| `rock.ovl20` | Overlay 20 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl20)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl20) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl20)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl20) |
| `rock.ovl21` | Overlay 21 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl21)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl21) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl21)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl21) |
| `rock.ovl22` | Overlay 22 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl22)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl22) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl22)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl22) |
| `rock.ovl23` | Overlay 23 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl23)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl23) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl23)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl23) |
| `rock.ovl24` | Overlay 24 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl24)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl24) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl24)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl24) |
| `rock.ovl25` | Overlay 25 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl25)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl25) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl25)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl25) |
| `rock.ovl26` | Overlay 26 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl26)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl26) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl26)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl26) |
| `rock.ovl27` | Overlay 27 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl27)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl27) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl27)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl27) |
| `rock.ovl28` | Overlay 28 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl28)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl28) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl28)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl28) |
| `rock.ovl29` | Overlay 29 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl29)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl29) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl29)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl29) |
| `rock.ovl30` | Overlay 30 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl30)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl30) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl30)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl30) |
| `rock.ovl31` | Overlay 31 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl31)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl31) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl31)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl31) |
| `rock.ovl32` | Overlay 32 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl32)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl32) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl32)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl32) |
| `rock.ovl33` | Overlay 33 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl33)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl33) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl33)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl33) |
| `rock.ovl34` | Overlay 34 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl34)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl34) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl34)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl34) |
| `rock.ovl35` | Overlay 35 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl35)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl35) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl35)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl35) |
| `rock.ovl36` | Overlay 36 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl36)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl36) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl36)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl36) |
| `rock.ovl37` | Overlay 37 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl37)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl37) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl37)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl37) |
| `rock.ovl40` | Overlay 40 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl40)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl40) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl40)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl40) |
| `rock.ovl41` | Overlay 41 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl41)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl41) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl41)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl41) |
| `rock.ovl42` | Overlay 42 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl42)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl42) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl42)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl42) |
| `rock.ovl43` | Overlay 43 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl43)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl43) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl43)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl43) |
| `rock.ovl44` | Overlay 44 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl44)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl44) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl44)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl44) |
| `rock.ovl45` | Overlay 45 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl45)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl45) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl45)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl45) |
| `rock.ovl46` | Overlay 46 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl46)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl46) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl46)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl46) |
| `rock.ovl47` | Overlay 47 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl47)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl47) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl47)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl47) |
| `rock.ovl48` | Overlay 48 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl48)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl48) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl48)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl48) |
| `rock.ovl49` | Overlay 49 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl49)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl49) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl49)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl49) |
| `rock.ovl50` | Overlay 50 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl50)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl50) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl50)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl50) |
| `rock.ovl51` | Overlay 51 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl51)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl51) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl51)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl51) |
| `rock.ovl52` | Overlay 52 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl52)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl52) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl52)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl52) |
| `rock.ovl53` | Overlay 53 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl53)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl53) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl53)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl53) |
| `rock.ovl54` | Overlay 54 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl54)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl54) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl54)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl54) |
| `rock.ovl55` | Overlay 55 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl55)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl55) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl55)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl55) |
| `rock.ovl56` | Overlay 56 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl56)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl56) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl56)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl56) |
| `rock.ovl57` | Overlay 57 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl57)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl57) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl57)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl57) |
| `rock.ovl58` | Overlay 58 | [![Code](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=rock.ovl58)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl58) [![Functions](https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=rock.ovl58)](https://decomp.dev/anzaldoivan/mmx5?category=rock.ovl58) |

</details>

The published number is the matched code of the `game` category, in bytes. The `sdk` row counts the SDK libraries apart. A complete unit is a C file whose code and data all match. It is not a finished file (`rules/FIN1.md`).

Progress bars powered by [decomp.dev][psxd-progress].

[psxd-code]: https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Code&measure=code&category=game
[psxd-functions]: https://decomp.dev/anzaldoivan/mmx5.svg?mode=shield&label=Functions&measure=functions&category=game
[psxd-progress]: https://decomp.dev/anzaldoivan/mmx5
<!-- psxdecomp:progress:end -->

What does the percentage mean? A function counts as matched only when the whole binary still hashes identically
with it compiled from C. Names and types come only from evidence, never from guesses. An address-named placeholder is
honest. The record behind them is what makes the work auditable. That record is the [cookbook](cookbook/INDEX.md) of
byte-proven idioms, the [codegen map](docs/codegen-map/README.md) and the
[build contract](docs/publish/contract.md).

## Building the decompilation

Requirements: Linux on x86-64 (WSL 2 counts), Git, Bash, Make, Python 3 with `venv`, and `clang-format`. You must
also have your own dump of *Mega Man X5* (USA), SLUS-01334, as `.cue` + `.bin`. The dump never enters the
repository: `disks/` and everything extracted from the dump are git-ignored.

```sh
git clone https://github.com/anzaldoivan/mmx5.git && cd mmx5
bash bootstrap.sh /path/to/your/dump.cue   # venv, binutils, the pinned compiler and maspsx, then the extraction
make check                                 # split, assemble/compile, link, hash-check every binary
```

`bootstrap.sh` fetches every tool by pinned checksum or commit and ends with `bootstrap: OK`. A successful
`make check` prints `check: slus ok`, `check: rockx5 ok` and `check: 2 of 2 green, 0 failed`, then runs the tool
self-tests.

`make disc` rebuilds the whole disc from your extraction plus the built `SLUS_013.34` and `ROCK_X5.BIN` (its
overlay table regenerated from the overlay sizes). It writes the disc into `build/disc/mmx5.cue` + `.bin`. When the
image is identical to the retail track, it prints `disc: track sha1 10709231f857636b5ccd3cd9acebc91458dcb5fd OK`.
`REDUX_CUE=build/disc/mmx5.cue bash tools/redux/run.sh tools/redux/title.lua` boots that image in PCSX-Redux to the
title screen and prints `redux: title OK`. Disc images are git-ignored and refused by the firewall.

`make replay-check PY=...` replays the tracked input script `tools/replay/scripts/intro.pad` in PCSX-Redux. The
script holds pad events per frame and no game bytes. The replay runs on your original image 3 times, on the rebuilt
`build/disc/mmx5.cue` once, and once with a planted one-instruction change (`tools/replay/plants.txt`). The command
prints `replay: original 3 of 3 identical, 8 checkpoints`, `replay: rebuilt 0 divergences` and
`replay: plant caught at stage_start`. It takes about an hour. Details are in `tools/replay/README.md`.

`make shift-scan PY=...` scans the built `SLUS_013.34` and `ROCK_X5.BIN` for references that are still bare
addresses rather than symbols. It reads the references into the main executable and into both overlay regions
(exe->exe, exe->ovl, ovl->ovl). It prints `shift-scan: 0 unsymbolized` and one `shift-scan: plant caught at <addr>` for each direction (its planted
controls).

`make build SHIFT=1` and `make disc SHIFT=1` build a shifted variant into `build/shift/`. Every code and data
address of the executable moves (`SHIFT_PAD`, default 0). Every code overlay in `ROCK_X5.BIN` moves too
(`SHIFT_OVL_PAD`, default 0x10). The build regenerates `ROCK_X5.BIN` and its table of contents from the shifted link,
and it skips the hash check. `make replay-shift PY=...` replays the intro script on `build/shift/disc/mmx5.cue` and
prints `replay: shifted 0 divergences`. Details are in `tools/shift/README.md`.

The `ROCK_X5.BIN` link, default and SHIFT, asserts that each overlay fits its RAM region. `make shift-oversize PY=...`
plants an oversize overlay and prints `shift-oversize: link failed as planted (<ovl>)`.

`PATCHES=<name>` (with `SHIFT=1` only) builds a patched variant into `build/shift-<name>/`. Each
`patches/<name>/<alias>/<file>.c` replaces its twin `src/<alias>/<file>.c`. A patch file without a twin is an error.
`make disc SHIFT=1 PATCHES=<name>` writes `build/shift-<name>/disc/mmx5.cue`.

`make replay-patch PATCHES=<name> PY=...` replays the intro script on that disc three times. It compares the replay with the original from the checkpoint that
`patches/<name>/checkpoint` names. It prints `replay-patch: <name> OK (first divergence <cp> >= declared <cp>, 3 of 3 deterministic, control caught)` when the patch changes the game from that
checkpoint on and never before it.

`PY tools/assets/assets.py export|import|roundtrip` exports `ROCK_X5.DAT` into the git-ignored `assets/` and imports it
back. `roundtrip` prints `assets: container 898 of 898 identical, 0 differences` and `assets: roundtrip OK (1 class)`.
`make disc-assets PY=...` re-exports and re-imports `ROCK_X5.DAT`, rebuilds the image and prints
`disc-assets: re-imported image sha1 matches config/medium.sha1`. Details are in `tools/assets/README.md`.

An asset edit lives in `asset-edits/<name>/` as `edit.json`, `checkpoint` and `README.md`. `asset-edits/m092fill` is
an example. `make disc ASSET_EDIT=<name>` writes `build/asset-<name>/disc/mmx5.cue`. `make replay-asset ASSET_EDIT=<name>
PY=...` prints `replay-asset: <name> OK (first divergence <cp> >= declared <cp>, 3 of 3 deterministic, control caught)`.
`make firewall-check` also plants an exported asset and prints `firewall-check: assets control caught`.
Every modding toggle, with its command and its success string, is in [docs/modding.md](docs/modding.md).

## Repository layout

| Path | Contents |
|---|---|
| `src/` | Decompiled C, one directory per binary (`src/slus/`, `src/rockx5/`) and the code they share (`src/shared/`) |
| `include/` | Headers and assembler macros |
| `config/` | splat configurations, symbol files, hash checks, the firewall's rules |
| `tools/` | Extraction, build, matching and analysis tools |
| `Makefile`, `mk/` | The build and its checks |
| `docs/` | Formats, memory map, codegen map and prior art |
| `cookbook/` | Byte-proven C idioms for this compiler |
| `disks/` | Your dump, if you keep it in the tree (git-ignored) |

## Getting started

### Setting up

`bash bootstrap.sh` without an argument prepares the toolchain alone. `make no-rom` then runs every check that needs
no game file (the same ones CI runs).

### Contributing

Before your first pull request, read [CONTRIBUTING.md](CONTRIBUTING.md). It gives these rules. Bring your own copy of
the game. Never commit anything derived from the game. Follow the AI-use conduct section.

### Reference

Are you new to this compiler or stuck on a function? The [cookbook](cookbook/INDEX.md) and the
[codegen map](docs/codegen-map/README.md) document the code patterns proven so far.

## Acknowledgements

No decompilation of Mega Man X5 existed when this project started (decomp.dev listed none on 2026-10-03). This
project stands on the work of others. Every fact taken from them is tracked with its status in
[`docs/prior-art.md`](docs/prior-art.md). A fact from another project stays a lead until this project's own bytes
prove it.

- **[sozud](https://github.com/sozud)** — [**mmx4**](https://github.com/sozud/mmx4), the matching decompilation of
  *Mega Man X4* (AGPL-3.0), the same engine line. This project shares its license so that code proven shared between
  the games can be adapted with attribution ([`THIRD_PARTY.md`](THIRD_PARTY.md)).
- **[mstan](https://github.com/mstan)** — [MegaManX5Recomp](https://github.com/mstan/MegaManX5Recomp) (PolyForm
  Noncommercial), a static recompilation of this disc. Its disc and layout facts are leads. Its code is not used.
- **acediez** — the [MMX5 Improvement Project addendum](https://archive.org/details/mmx5_improvement_project_addendum)
  and its documentation of the retail disc's tables.
- **[ChrisNonyminus](https://github.com/ChrisNonyminus)** — [mml1](https://github.com/ChrisNonyminus/mml1), a Mega Man
  Legends decompilation (facts only).
- **[Almar's Guides](https://almarsguides.com/retro/walkthroughs/ps1/games/megamanx5/codebreaker/)** — NTSC-U codes,
  used as RAM-map leads.

The governance and method come from ProjectArchitect 3 and the decomp-architect kit distilled from a finished
matching decompilation.

## License

The project's own work — the tooling, the build system, the documentation — is licensed under AGPL-3.0
([`LICENSE`](LICENSE)). No rights are claimed over Capcom's game. **No license is asserted over the reimplemented
sources under `src/`** ([`src/NOTICE.md`](src/NOTICE.md)). Third-party components keep their own licenses
([`THIRD_PARTY.md`](THIRD_PARTY.md)). *Mega Man X5* is the property of its rights holder.
