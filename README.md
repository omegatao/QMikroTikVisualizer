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

2. spdlog
### Install Through Package Managers:
* Debian: `sudo apt install libspdlog-dev`
* Homebrew: `brew install spdlog`
* MacPorts: `sudo port install spdlog`
* FreeBSD:  `pkg install spdlog`
* Fedora: `dnf install spdlog`
* Gentoo: `emerge dev-libs/spdlog`
* Arch Linux: `pacman -S spdlog`
* openSUSE: `sudo zypper in spdlog-devel`
* vcpkg: `vcpkg install spdlog`
* conan: `spdlog/[>=1.4.1]`
* conda: `conda install -c conda-forge spdlog`
* build2: ```depends: spdlog ^1.8.2```