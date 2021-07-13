# qmk-layouts

My layouts for Planck, Preonic and Drop Alt

## Principles for the layout design

- Preonic is just extended Planck for learning cureve and more confidence with typing passwords
  - do not put anything essential on the top row
  - do not rely on muscle memory
- Keep T-shaped arrows for now
- Keep modifiers on the left hand to do shortcuts together with the mouse/touchpad
- Layers on the right thumb
- Lower layer is for keys that are lower on a regular keyboard (top row, numbers and symbols)
- Within layers context:
  - Left hand is for characters: lower for brackets, raised for symbols
  - Right hand is for navigation: regular arrows and vim-styled arrows for now
- Prefer mnemonic over perceived comfort: more important to remember where the key is 
  - question mark is under the exclamation mark
  - back slash is under reular slash
  - grave is raised quotes
  - open brackets on main row, closing below them
- Exception is made for often-used combos, prefer rolling over mnemonic, as it would get to muscle memory faster
   - inverse `>` and `<` so `=>` and `->` would roll with strongest fingers
- Make shift accessible on thumbs for faster typing, space on hold sounds like a compromise
- Have all modifiers available in their pure form, without on-tap features
- Bonus point: have a dedicated key for switching language

### Planck

![planck](/planck_glow.png)

### Preonic

![preonic](/preonic_glow.png)

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
```

4. Build the firmware
```shell
$ qmk compile -kb preonic/rev3 -km otann

```

5. Flash using the [QMK Toolbox app](https://github.com/qmk/qmk_toolbox/releases)


## Notes

The puthon installation may fail, in that case installing virtualenv and getting the python `3.9.6` may help