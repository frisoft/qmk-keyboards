# QMK keyboards

## Use

Initial setup

```bash
make setup
```

Update to the latest QMK

```bash
make setup
```

Flash all keyboards

```bash
# Open the nix-shell, ONLY ONCE
cd qmk_firmaware
nix-shell
cd ..
 
sudo make
```

Flash the Dactyl Manuform keyboard

```bash
sudo make dactyl_manuform
```

Clean up

```bash
make clean
```

## Notes

Inspired by https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd
