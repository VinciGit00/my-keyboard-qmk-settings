# my-keyboard-qmk-settings

Configurazioni QMK personali, una cartella per tastiera.

## Tastiere

| Cartella | Tastiera | MCU | Note |
|----------|----------|-----|------|
| [`planck/`](planck/) | Planck rev7 (Drop/OLKB) | STM32 | Ortholinear 4x12, custom matrix, encoder, RGB |
| [`silakka54/`](silakka54/) | Silakka54 | RP2040 Zero | Split column-staggered 54 tasti, hotswap (maker: [Squalius-cephalus](https://github.com/Squalius-cephalus/silakka54)) |

## Uso con QMK

Clona il [QMK firmware](https://qmk.fm/) e copia (o symlink) la cartella della tastiera dentro `qmk_firmware/keyboards/`.

### Planck rev7

```bash
qmk compile -kb planck/rev7 -km default
qmk flash   -kb planck/rev7 -km default
```

### Silakka54

```bash
qmk compile -kb silakka54 -km default
qmk flash   -kb silakka54 -km default
# oppure con make:
make silakka54:default
make silakka54:default:flash
```

Per entrare in bootloader sulla Silakka54: tieni premuto il tasto **BOOT** mentre colleghi l'MCU, oppure premi il tasto mappato su `QK_BOOT`.
