# Kyttie
Kyttie is the Catnet reference implemention. More information will be added here... in the future!

## Building
To build kyttie, simply run the Makefile. Things should be autodetected or the defaults should be
sane. Look through the Makefiles if you don't trust a bunch of highschools to not fuck your
computer to high hell.

Kyttie requires some custom kernel patches. Because this software is in it's infancy and is
developed by one person, these aren't published. If you want it so bad, patch the kernel yourself.
Should be too bad ;)

```
make KDIR=<path to built and patched kernel>
```

It's not automatically installed, you have to do that yourself :)

## Kernel Version
Kyttie is actively developed against 6.1.0-rc3, but it's based off some really stagnant kernel APIs
so it should work fine.

## Examples
Don't let the examples directory fool you, that's internal testing stuff.

## Authors
1. Milo Banks

