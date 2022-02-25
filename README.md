# qmk-layouts

My layouts for Planck, Preonic and Drop Alt

## Observations

- Left thumb is responsible for major key combinations
  - Mostly they are based on CMD
  - Occasionally they include shift, rarely opt or control
  - Context-switchng
    - CMD-TAB
    - CMD-` (CMD-SHIFT-TAB)
    - CTRL-TAB
- Right hand is responsible for navigation around text and text selection
  - OPT for skipping words
  - CMD for going to line start and end
  - SHIFT+OPT for quick selection
  - SHIFT+CMD for whole line
  - That means left hand need to hold two modifiers
- Mark the home position for thumb with reversed keycaps, it is confusing for the thumb to be positioned properly.

## Principles for the layout design

- Do not share a key between hands, use to grid layout
- Make all Mac OS modifiers available for on the left hand to do shortcuts when right hand on the mouse/touchpad
- Mirror modifiers on left-most coolumn to allow thumb-pinkey-letter combos like `⌘⌥c` or `⌘⌃g`
- Left thumb home position is optimised for modifiers with CMD, right thumb position for layer with symbols
- Arrows are most used non-letter keys, put them on the most accessible position, right thumb layer & home row
- Symbols are needed more frequently than number, so they take same most accessible layer with right thumb
- Numbers to be typed with one hand, so layer key is also on the left for number layer
  - Home row for most used numbers: 0, 1, 2, 3
  - Trying a reverse layout, since for some reason it made more sense somehow
- Don't do any tap-dance or double-function to thumb keys
- Bonus point: have a dedicated key for switching language
- Preonic is for experimental ideas
  - do not put anything essential on the top row, so the whole layout could be ported back to planck

### Learning curve

The best ergonomic benefit I got out of this is using arrows for navigating without leaving the home row.
It took me some months to finally give up on T-shaped arrows. Firstly I've put them on the most-accessible
layer, where most-used keys are and which is closest to the big space key for the thumb (lower in my case). I kept
the classic arrows on the bottom-right for backup and used the mostly when the right hand was movign from mouse to
keyboard. Slowly I developed the muscle memory for the home row arrows, which freed up one easily-accessible
key for the pinkey, where the up previously was. That turned to be the ideal place for the `enter`, as 
stretching little finger to the right, where the default is apparently too tiring for my hand.
Later I found an even better place for it when I moved the raise layer to the left thumb. That allowed me to place `[` and `]` there, which is used for `х` (ha) and `ъ` in Russian layout.

### Planck

Planck is my main keyboard, which I use daily. 

![planck](/planck/wallpaper.png)

### Preonic

This is for experimental features or crazy ideas to try out, like trying an ergo layout and moving two hands further apart.

![preonic](/preonic/wallpaper.png)

### ~Kyria~ (abandoned)

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