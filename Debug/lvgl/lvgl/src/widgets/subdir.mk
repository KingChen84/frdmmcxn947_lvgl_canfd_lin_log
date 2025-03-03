################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/lvgl/src/widgets/lv_arc.c \
../lvgl/lvgl/src/widgets/lv_bar.c \
../lvgl/lvgl/src/widgets/lv_btn.c \
../lvgl/lvgl/src/widgets/lv_btnmatrix.c \
../lvgl/lvgl/src/widgets/lv_canvas.c \
../lvgl/lvgl/src/widgets/lv_checkbox.c \
../lvgl/lvgl/src/widgets/lv_dropdown.c \
../lvgl/lvgl/src/widgets/lv_img.c \
../lvgl/lvgl/src/widgets/lv_label.c \
../lvgl/lvgl/src/widgets/lv_line.c \
../lvgl/lvgl/src/widgets/lv_objx_templ.c \
../lvgl/lvgl/src/widgets/lv_roller.c \
../lvgl/lvgl/src/widgets/lv_slider.c \
../lvgl/lvgl/src/widgets/lv_switch.c \
../lvgl/lvgl/src/widgets/lv_table.c \
../lvgl/lvgl/src/widgets/lv_textarea.c 

C_DEPS += \
./lvgl/lvgl/src/widgets/lv_arc.d \
./lvgl/lvgl/src/widgets/lv_bar.d \
./lvgl/lvgl/src/widgets/lv_btn.d \
./lvgl/lvgl/src/widgets/lv_btnmatrix.d \
./lvgl/lvgl/src/widgets/lv_canvas.d \
./lvgl/lvgl/src/widgets/lv_checkbox.d \
./lvgl/lvgl/src/widgets/lv_dropdown.d \
./lvgl/lvgl/src/widgets/lv_img.d \
./lvgl/lvgl/src/widgets/lv_label.d \
./lvgl/lvgl/src/widgets/lv_line.d \
./lvgl/lvgl/src/widgets/lv_objx_templ.d \
./lvgl/lvgl/src/widgets/lv_roller.d \
./lvgl/lvgl/src/widgets/lv_slider.d \
./lvgl/lvgl/src/widgets/lv_switch.d \
./lvgl/lvgl/src/widgets/lv_table.d \
./lvgl/lvgl/src/widgets/lv_textarea.d 

OBJS += \
./lvgl/lvgl/src/widgets/lv_arc.o \
./lvgl/lvgl/src/widgets/lv_bar.o \
./lvgl/lvgl/src/widgets/lv_btn.o \
./lvgl/lvgl/src/widgets/lv_btnmatrix.o \
./lvgl/lvgl/src/widgets/lv_canvas.o \
./lvgl/lvgl/src/widgets/lv_checkbox.o \
./lvgl/lvgl/src/widgets/lv_dropdown.o \
./lvgl/lvgl/src/widgets/lv_img.o \
./lvgl/lvgl/src/widgets/lv_label.o \
./lvgl/lvgl/src/widgets/lv_line.o \
./lvgl/lvgl/src/widgets/lv_objx_templ.o \
./lvgl/lvgl/src/widgets/lv_roller.o \
./lvgl/lvgl/src/widgets/lv_slider.o \
./lvgl/lvgl/src/widgets/lv_switch.o \
./lvgl/lvgl/src/widgets/lv_table.o \
./lvgl/lvgl/src/widgets/lv_textarea.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/lvgl/src/widgets/%.o: ../lvgl/lvgl/src/widgets/%.c lvgl/lvgl/src/widgets/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MCXN947VDF -DCPU_MCXN947VDF_cm33 -DCPU_MCXN947VDF_cm33_core0 -DLV_CONF_INCLUDE_SIMPLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DSD_ENABLED -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\source" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\drivers" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lcdc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\host" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\inc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\gpio" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\fatfs\source\fsl_sd_disk" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\fatfs\source" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\video" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\touchpanel" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\utilities" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\lvgl" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\lvgl\src" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\device" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\startup" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\uart" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\lists" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\osa" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\osa" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\template\usdhc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\CMSIS" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\board" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\custom" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated\guider_customer_fonts" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated\guider_fonts" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\template" -O0 -fno-common -g3 -gdwarf-4 -Wall -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lvgl-2f-lvgl-2f-src-2f-widgets

clean-lvgl-2f-lvgl-2f-src-2f-widgets:
	-$(RM) ./lvgl/lvgl/src/widgets/lv_arc.d ./lvgl/lvgl/src/widgets/lv_arc.o ./lvgl/lvgl/src/widgets/lv_bar.d ./lvgl/lvgl/src/widgets/lv_bar.o ./lvgl/lvgl/src/widgets/lv_btn.d ./lvgl/lvgl/src/widgets/lv_btn.o ./lvgl/lvgl/src/widgets/lv_btnmatrix.d ./lvgl/lvgl/src/widgets/lv_btnmatrix.o ./lvgl/lvgl/src/widgets/lv_canvas.d ./lvgl/lvgl/src/widgets/lv_canvas.o ./lvgl/lvgl/src/widgets/lv_checkbox.d ./lvgl/lvgl/src/widgets/lv_checkbox.o ./lvgl/lvgl/src/widgets/lv_dropdown.d ./lvgl/lvgl/src/widgets/lv_dropdown.o ./lvgl/lvgl/src/widgets/lv_img.d ./lvgl/lvgl/src/widgets/lv_img.o ./lvgl/lvgl/src/widgets/lv_label.d ./lvgl/lvgl/src/widgets/lv_label.o ./lvgl/lvgl/src/widgets/lv_line.d ./lvgl/lvgl/src/widgets/lv_line.o ./lvgl/lvgl/src/widgets/lv_objx_templ.d ./lvgl/lvgl/src/widgets/lv_objx_templ.o ./lvgl/lvgl/src/widgets/lv_roller.d ./lvgl/lvgl/src/widgets/lv_roller.o ./lvgl/lvgl/src/widgets/lv_slider.d ./lvgl/lvgl/src/widgets/lv_slider.o ./lvgl/lvgl/src/widgets/lv_switch.d ./lvgl/lvgl/src/widgets/lv_switch.o ./lvgl/lvgl/src/widgets/lv_table.d ./lvgl/lvgl/src/widgets/lv_table.o ./lvgl/lvgl/src/widgets/lv_textarea.d ./lvgl/lvgl/src/widgets/lv_textarea.o

.PHONY: clean-lvgl-2f-lvgl-2f-src-2f-widgets

