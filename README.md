# qmk-layouts

My layouts for Planck, Preonic and Drop Alt

## How to build firmwares

1. Clone this repo to `qmk-layouts`
2. Clone the [official QMK repo](https://github.com/qmk/qmk_firmware) next to it to `qmk_firmware` folder **with --recurse-submodules**
```
$ git clone --recurse-submodules git@github.com:qmk/qmk_firmware.git
```
3. Create symlinks for the layout, i.e.
```
$ cp -r qmk-layouts/planck qmk_firmware/keyboards/planck/keymaps/otann
$ cd qmk_firmware
$ util/docker_build.sh planck/rev6:otann
```


## Notes

If you cloned the qmk repo without submodules, here is how to pull them
```
$ git submodule update --init --recursive
```
