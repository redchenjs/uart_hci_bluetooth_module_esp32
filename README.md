Bluetooth UART HCI Controller
=============================

BTDM controller inside the ESP32 chip, use UART(H4) as HCI IO.

## Pinmap

| HCI IO | TX | RX | CTS | RTS |
| :----: | -: | -: | --: | --: |
|    Pin |  5 | 18 |  19 |  23 |

## Preparing

### Obtain the Source

```
git clone --recursive https://github.com/redchenjs/bluetooth_uart_hci_controller_esp32.git
```

### Update an existing repository

```
git pull
git submodule update --init --recursive
```

### Setup the Tools

```
./esp-idf/install.sh
```

## Building

### Setup the environment variables

```
export IDF_PATH=$PWD/esp-idf
source ./esp-idf/export.sh
```

### Flash & Monitor

```
idf.py flash monitor
```
