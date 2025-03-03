################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../startup/startup_mcxn947_cm33_core0.cpp 

C_SRCS += \
../startup/boot_multicore_slave.c 

CPP_DEPS += \
./startup/startup_mcxn947_cm33_core0.d 

C_DEPS += \
./startup/boot_multicore_slave.d 

OBJS += \
./startup/boot_multicore_slave.o \
./startup/startup_mcxn947_cm33_core0.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MCXN947VDF -DCPU_MCXN947VDF_cm33 -DCPU_MCXN947VDF_cm33_core0 -DLV_CONF_INCLUDE_SIMPLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DSD_ENABLED -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\source" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\drivers" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lcdc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\host" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\inc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\gpio" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\fatfs\source\fsl_sd_disk" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\fatfs\source" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\video" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\touchpanel" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\utilities" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\lvgl" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\lvgl\src" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\device" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\startup" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\uart" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\lists" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\osa" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\osa" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\template\usdhc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\CMSIS" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\board" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\custom" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated\guider_customer_fonts" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated\guider_fonts" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\template" -O0 -fno-common -g3 -gdwarf-4 -Wall -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup/%.o: ../startup/%.cpp startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -std=gnu++11 -DCPU_MCXN947VDF -DCR_INTEGER_PRINTF -DSD_ENABLED -DCPU_MCXN947VDF_cm33 -DCPU_MCXN947VDF_cm33_core0 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\source" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\drivers" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lcdc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\video" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\touchpanel" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\utilities" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\lvgl" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\lvgl\src" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\device" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\startup" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\uart" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\lists" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\CMSIS" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\board" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\custom" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated\guider_customer_fonts" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated\guider_fonts" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\template" -O0 -fno-common -g3 -gdwarf-4 -Wall -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -fno-builtin -fno-rtti -fno-exceptions -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/boot_multicore_slave.d ./startup/boot_multicore_slave.o ./startup/startup_mcxn947_cm33_core0.d ./startup/startup_mcxn947_cm33_core0.o

.PHONY: clean-startup

