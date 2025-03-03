################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_edma.c \
../drivers/fsl_edma_soc.c \
../drivers/fsl_flexcan.c \
../drivers/fsl_flexio.c \
../drivers/fsl_flexio_mculcd.c \
../drivers/fsl_flexio_mculcd_edma.c \
../drivers/fsl_flexio_mculcd_smartdma.c \
../drivers/fsl_gpio.c \
../drivers/fsl_inputmux.c \
../drivers/fsl_lpflexcomm.c \
../drivers/fsl_lpi2c.c \
../drivers/fsl_lpspi.c \
../drivers/fsl_lpspi_cmsis.c \
../drivers/fsl_lpspi_edma.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_reset.c \
../drivers/fsl_smartdma.c \
../drivers/fsl_smartdma_mcxn.c \
../drivers/fsl_smartdma_rt500.c \
../drivers/fsl_spc.c \
../drivers/fsl_usdhc.c 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_edma.d \
./drivers/fsl_edma_soc.d \
./drivers/fsl_flexcan.d \
./drivers/fsl_flexio.d \
./drivers/fsl_flexio_mculcd.d \
./drivers/fsl_flexio_mculcd_edma.d \
./drivers/fsl_flexio_mculcd_smartdma.d \
./drivers/fsl_gpio.d \
./drivers/fsl_inputmux.d \
./drivers/fsl_lpflexcomm.d \
./drivers/fsl_lpi2c.d \
./drivers/fsl_lpspi.d \
./drivers/fsl_lpspi_cmsis.d \
./drivers/fsl_lpspi_edma.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_reset.d \
./drivers/fsl_smartdma.d \
./drivers/fsl_smartdma_mcxn.d \
./drivers/fsl_smartdma_rt500.d \
./drivers/fsl_spc.d \
./drivers/fsl_usdhc.d 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_edma.o \
./drivers/fsl_edma_soc.o \
./drivers/fsl_flexcan.o \
./drivers/fsl_flexio.o \
./drivers/fsl_flexio_mculcd.o \
./drivers/fsl_flexio_mculcd_edma.o \
./drivers/fsl_flexio_mculcd_smartdma.o \
./drivers/fsl_gpio.o \
./drivers/fsl_inputmux.o \
./drivers/fsl_lpflexcomm.o \
./drivers/fsl_lpi2c.o \
./drivers/fsl_lpspi.o \
./drivers/fsl_lpspi_cmsis.o \
./drivers/fsl_lpspi_edma.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_reset.o \
./drivers/fsl_smartdma.o \
./drivers/fsl_smartdma_mcxn.o \
./drivers/fsl_smartdma_rt500.o \
./drivers/fsl_spc.o \
./drivers/fsl_usdhc.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MCXN947VDF -DCPU_MCXN947VDF_cm33 -DCPU_MCXN947VDF_cm33_core0 -DLV_CONF_INCLUDE_SIMPLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DSD_ENABLED -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\source" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\drivers" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lcdc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\host" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\inc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\gpio" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\fatfs\source\fsl_sd_disk" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\fatfs\source" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\video" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\touchpanel" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\utilities" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\lvgl" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\lvgl\src" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\device" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\startup" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\uart" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\lists" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\osa" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\osa" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\template\usdhc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\CMSIS" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\board" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\custom" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated\guider_customer_fonts" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated\guider_fonts" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\template" -O0 -fno-common -g3 -gdwarf-4 -Wall -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_edma.d ./drivers/fsl_edma.o ./drivers/fsl_edma_soc.d ./drivers/fsl_edma_soc.o ./drivers/fsl_flexcan.d ./drivers/fsl_flexcan.o ./drivers/fsl_flexio.d ./drivers/fsl_flexio.o ./drivers/fsl_flexio_mculcd.d ./drivers/fsl_flexio_mculcd.o ./drivers/fsl_flexio_mculcd_edma.d ./drivers/fsl_flexio_mculcd_edma.o ./drivers/fsl_flexio_mculcd_smartdma.d ./drivers/fsl_flexio_mculcd_smartdma.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_inputmux.d ./drivers/fsl_inputmux.o ./drivers/fsl_lpflexcomm.d ./drivers/fsl_lpflexcomm.o ./drivers/fsl_lpi2c.d ./drivers/fsl_lpi2c.o ./drivers/fsl_lpspi.d ./drivers/fsl_lpspi.o ./drivers/fsl_lpspi_cmsis.d ./drivers/fsl_lpspi_cmsis.o ./drivers/fsl_lpspi_edma.d ./drivers/fsl_lpspi_edma.o ./drivers/fsl_lpuart.d ./drivers/fsl_lpuart.o ./drivers/fsl_reset.d ./drivers/fsl_reset.o ./drivers/fsl_smartdma.d ./drivers/fsl_smartdma.o ./drivers/fsl_smartdma_mcxn.d ./drivers/fsl_smartdma_mcxn.o ./drivers/fsl_smartdma_rt500.d ./drivers/fsl_smartdma_rt500.o ./drivers/fsl_spc.d ./drivers/fsl_spc.o ./drivers/fsl_usdhc.d ./drivers/fsl_usdhc.o

.PHONY: clean-drivers

