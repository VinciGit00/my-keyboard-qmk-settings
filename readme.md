# keyboard

First of all it is required to download the qmk firmware at the following link: [https://qmk.fm](https://qmk.fm/)

Put the repo in the dir: 

```
/Users/marcovinciguerra/qmk_firmware/keyboards/planck/rev7
```

For compile the firmware:

```
qmk compile -kb planck/rev7 -km marco_vinciguerra
```

- Make lower and raise and after the reset button

![Screenshot 2023-09-16 alle 11.49.44.png](keyboard%20cdc69bf9b29843958d3f2787d9ffaded/Screenshot_2023-09-16_alle_11.49.44.png)

```
qmk flash -kb planck/rev7 -km marco_vinciguerra
```