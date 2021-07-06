# qmk-layouts

My layouts for Planck, Preonic and Drop Alt

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
```

4. Build the firmware
```shell
$ qmk compile -kb preonic/rev3 -km otann

```

5. Flash using the [QMK Toolbox app](https://github.com/qmk/qmk_toolbox/releases)


## Notes

The puthon installation may fail, in that case installing virtualenv and getting the python `3.9.6`