# qmk-layouts

My layouts for Planck, Preonic and Drop Alt

## Principles for the layout design

- Preonic is just extended Planck for learning cureve and more confidence with typing passwords
  - do not put anything essential on the top row
  - do not rely on muscle memory for the top row
- Keep T-shaped arrows for now
- Keep Mac OS modifiers on the left hand to do shortcuts with right hand on the mouse/touchpad
- Layers on the right thumb
- Mirror modifiers on left-most coolumn to allow thumb-pinkey-letter cmobos `⌘⌥c` or `⌘⌃g`
- Lower is for symbols, raised is for numbers and navigation. Allows for sequences without layer jiggle.
- Alloow inward rolls (`()`, `{}`, `->`, `=>`)
- Make shift accessible on thumb for faster typing, space-on-hold sounds like a compromise
- Have all modifiers available in their pure form, without on-tap features
- Bonus point: have a dedicated key for switching language

### Planck

Planck layout is also an experimental playground for trying new ideas.
So it may be a little bit different or ahead of preonic.

![planck](/planck/wallpaper.png)

### Preonic

![preonic](/preonic/wallpaper.png)

### Kyria

![kyria](/kyria/wallpaper.png)

## How to build firmwares

1. Install QMK following the [official guide](https://docs.qmk.fm/#/newbs_getting_started)
```shell
brew install qmk/qmk/qmk

```
2. Setup the qmk, there is an option to provide custom location for the cloned git repo
```shell
qmk setup -H ~/Dev/repos/otann/qmk_firmware

```

3. Link the layouts to the corresponding folders
```
$ ln -s ~/Dev/repos/otann/qmk_layouts/preonic ~/Dev/repos/otann/qmk_firmware/keyboards/preonic/keymaps/otann
$ ln -s ~/Dev/repos/otann/qmk_layouts/planck ~/Dev/repos/otann/qmk_firmware/keyboards/planck/keymaps/otann
$ ln -s ~/Dev/repos/otann/qmk_layouts/kyria ~/Dev/repos/otann/qmk_firmware/keyboards/kyria/keymaps/otann
```

4. Build the firmware
```shell
$ qmk compile -kb preonic/rev3 -km otann

```

5. Flash using the [QMK Toolbox app](https://github.com/qmk/qmk_toolbox/releases)


## Notes

The puthon installation may fail, in that case installing virtualenv and getting the python `3.9.6` may help