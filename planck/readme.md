# keyboard

First of all it is required to download the qmk firmware at the following link: [https://qmk.fm](https://qmk.fm/)

Put the repo in the dir: 

```
/Users/marcovinciguerra/qmk_firmware/keyboards/planck/rev7
```

For compile the firmware:

```
qmk compile -kb planck/rev7 -km default
```

- Make lower and raise and after the reset button

![Screenshot 2023-09-16 alle 11.49.44.png](keyboard%20cdc69bf9b29843958d3f2787d9ffaded/Screenshot_2023-09-16_alle_11.49.44.png)

```
qmk flash -kb planck/rev7 -km default
```

## ⌨️ Keymap (keymap `marco_vinciguerra`)

Planck rev7 — 4×12 ortho grid. `Lower` and `Raise` are momentary layers (hold them); together they activate `Adjust`.
Keycodes use the **macOS Italian** layout (`keymap_italian_mac_ansi.h`).

### Base (Qwerty)
```
 Esc   Q   W   E   R   T   Y   U   I   O   P  Bksp
 Tab   A   S   D   F   G   H   J   K   L   ;   '
 Sft   Z   X   C   V   B   N   M   ,   .   /  Ent
 Brt Alt Alt Gui  LO  Sft Spc  RA  ←   ↓   ↑   →
```
> Alternative **Colemak** and **Dvorak** layouts are also available (switchable from the Adjust layer).

### Lower  (hold LO)
```
  `   !   @   #   $   %   ^   &   *   (   )   @
 Del  {   }   [   ]   (   )   _   +   {   }   |
  ·   #   / Vol- Vol+ F11 F12  ~   |  Home End  ·
  ·   ·   ·   ·   ·   ·   ·   ·  Nxt Vol- Vol+ ▶
```
> `c` = Volume down, `v` = Volume up (matching the silakka54 layout).

### Raise  (hold RA)
```
  ~   1   2   3   4   5   6   7   8   9   0  Bksp
 Del F1  F2  F3  F4  F5  F6   -   =   [   ]   \
  ·  F7  F8  F9  F10 F11 F12  #   /  PgU PgD  ·
  ·   ·   ·   ·   ·   ·   ·   ·  Nxt Vol- Vol+ ▶
```

### Adjust  (Lower + Raise)
```
  ·  Boot Dbg RGB Mod Hue+ Hue- Sat+ Sat- Bri+ Bri- Del
  ·  Clr  Mus Aud+ Aud- AGn  AGs  Qwer Cole Dvor Plov  ·
  ·  Vc- Vc+ Mus+ Mus- MIDI+ MIDI- ·   ·    ·    ·    ·
  ·   ·   ·   ·   ·    ·    ·    ·   ·    ·    ·    ·
```
`·` = transparent. Encoder/dip-switch and the Plover layer are handled in code inside the keymap.

