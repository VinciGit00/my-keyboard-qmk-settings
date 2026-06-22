# Silakka54

![Silakka54](https://i.imgur.com/JrsS0kY.png)

Silakka54 is a RP2040 Zero based 54-key column staggered split keyboard. PCB uses hotswap sockets. Design is inspired from REVIUNG41 and Corne keyboards.

* Keyboard Maintainer: [Squalius-cephalus](https://github.com/Squalius-cephalus)
* Hardware Supported: Silakka54 PCB
* Hardware Availability: https://github.com/Squalius-cephalus/silakka54

Make example for this keyboard (after setting up your build environment):

    make silakka54:default

Flashing example for this keyboard:

    make silakka54:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical boot button**: Hold BOOT button down and connect MCU to the PC
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

## ⌨️ Mappa tasti (keymap `default`)

Split 6 colonne + pollici. Tieni premuto uno dei due tasti **layer-switch** (in basso a sinistra / a destra, `MO(_ARROWS)`) per raggiungere il layer simboli/frecce.

I keycode usano il layout **Italiano di macOS** (`keymap_italian_mac_iso.h`), così i simboli escono corretti senza cambiare input source.

### Layer base
```
 Tab   1   2   3   4   5  │  6   7   8   9   0  Bksp
 Esc   Q   W   E   R   T  │  Y   U   I   O   P   _
 Sft   A   S   D   F   G  │  H   J   K   L   ;  Ent
 LYR   Z   X   C   V   B  │  N   M   ,   .   /  LYR
                Gui Gui Spc │ Spc Ctl Alt
```

### Layer simboli/frecce  (tieni premuto LYR)
```
  ·    ·   ·   ·   ·   ·  │  ·   ·   ·   ·   ·   ·
  ·    ·   ·   ·   ·   ·  │  ·   ·   ·   ·   ·   ·
  ·    {   }   [   ]   (  │  )   ?   ·   ·   ·   ·
  ·    #   //  ·   ·   ·  │  ·   ·   <   >   ·   ·
                 ←   ↑   · │  ·   ↓   →
```
`·` = trasparente, passa al layer base.

| Tasto | Output |   | Tasto | Output |
|:-----:|:------:|:-:|:-----:|:-------|
| a | `{` |   | j | `?` |
| s | `}` |   | z | `#` |
| d | `[` |   | x | `//` (commento Java) |
| f | `]` |   | , | `<` |
| g | `(` |   | . | `>` |
| h | `)` |   | pollici | ← ↑ ↓ → |
