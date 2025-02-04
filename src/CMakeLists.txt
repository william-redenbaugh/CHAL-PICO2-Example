add_executable(${NAME}
        main.cpp
        
        Agent.cpp
        BlinkAgent.cpp
        )


target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CSAL_SHARED)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CHAL_SHARED)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOSCSAL)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CHAL-RASPI-PICO)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME} 
    pico_stdlib 
	FreeRTOS-Kernel-Heap4 # FreeRTOS kernel and dynamic heap
    freertos_config
    )

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# enable usb output, disable uart output
pico_enable_stdio_usb(${NAME} 1)
pico_enable_stdio_uart(${NAME} 1)
target_compile_definitions(${NAME} PRIVATE
    PICO_DEFAULT_UART_RX_PIN=17
    PICO_DEFAULT_UART_TX_PIN=16
)
