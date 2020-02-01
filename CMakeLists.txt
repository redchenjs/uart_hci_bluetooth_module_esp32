cmake_minimum_required(VERSION 3.5)

set(SUPPORTED_TARGETS esp32)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(bluetooth_hci_uart_controller)
