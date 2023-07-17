# QMikroTikVisualizer
Displays real-time information from a MikroTik router using Qt qml with fancy visual effects.

# Before compilation
## Install prerequsite
1. libmaxminddb
### On Ubuntu via PPA
MaxMind provides a PPA for recent version of Ubuntu. To add the PPA to your APT sources, run:

$ sudo add-apt-repository ppa:maxmind/ppa
Then install the packages by running:

$ sudo apt update
$ sudo apt install libmaxminddb0 libmaxminddb-dev mmdb-bin

### On macOS via Homebrew or MacPorts
You can install libmaxminddb on macOS using Homebrew:

$ brew install libmaxminddb
Or with MacPorts:

$ sudo port install libmaxminddb

### On Arch linux
install using pacman
$ sudo pacman -S libmaxminddb