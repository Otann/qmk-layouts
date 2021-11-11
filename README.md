# qmk-layouts

My layouts for Planck, Preonic and Drop Alt

## Principles for the layout design

- Preonic is just extended Planck for learning cureve and more confidence with typing passwords
  - do not put anything essential on the top row
  - do not rely on muscle memory for the top row  
- Do not share keys between hands: right thumb is space, left is shift
- _Not about layout, but still:_ mark the home position for thumb with keycaps, it is confusing with more than 2 similar keys per thumb.
- Keep Mac OS modifiers on the left hand to do shortcuts with right hand on the mouse/touchpad
- Mirror modifiers on left-most coolumn to allow thumb-pinkey-letter combos like `⌘⌥c` or `⌘⌃g`
- Modifiers on the left side, layers on the right.
- Arrows are most used non-letter keys, so they are on the most accessible position – layer next to space, under home position
- Symbols are needed more frequently than number, so they take same most accessible layer
- Parenthesis on the strongest position for left hand (2nd and 3rd fingers)
- Allow inward rolls (`()`, `{}`, `->`, `=>`)
- Symbols from left half (from numbers 1-4) fill left side
- Keep some mnemonics
  - `&` and `*` are together
  - `-` and `=` are toghther
  - `_` and `+` are togither and "under" the `-` and `=`
- Raised layer is for numbers on home row and fn-numbers
- Avoid any double-function keys on thumbs (different behavios for on tap/on hold)
- Bonus point: have a dedicated key for switching language


### Historical observations

It took me some months to finally give up on T-shaped arrows. Firstly I've put them on the most-accessible
layer, where most-used keys are and whick is closest to the space for the thumb (lower in my case). I kept
the classic arrows on the bottom-right and used the mostly when the right hand was movign from mouse to
keyboard. Slowly I developed the muscle memory for the flattened arrows, which freed up one easily-accessible
key for the pinkey, where the up previously was. That turned to be the ideal place for the `enter`, as 
stretching little finger to the right, where the default is apparently too tiring for my hand.

Raise/lower around the space confuses my brain

### Planck

Planck layout is also an experimental playground for trying new ideas.
So it may be a little bit different or ahead of preonic.

![planck](/planck/wallpaper.png)

### Preonic

![preonic](/preonic/wallpaper.png)

### Kyria (not completer)

I got stuck with my poor soldering skill and never achievet the reliable bild.
Every attempt to solder it properly ended with one or more keys getting stuck and producing an unexpected
presses, while physically nothings happens, whick make the keyboard unusable, I cann't leave my computer
and come back later discovering a mess typed in the document.

It also takes much more space than planck or preonic, while them not causing any significant discomfort.

![kyria](/kyria/wallpaper.png)

## How to build firmwares

_note: replace the username in the every path with your own_

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