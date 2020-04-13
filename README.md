# Installation of MSM_ATC Screenset

### Prerequisites:
- Mach3
- MachStdMill from Calypso Ventures (MSM_ATC was tested with v2.0.12)
- Home Switches enabled - it is mandatory to have the machine referenced when using ATC system.

1. Download MSM_ATC from here - https://github.com/Haimana/MSM_ATC
2. Extract all files and folders inside your Mach3 installation directory and overwrite all existing files. Some of the needed ATC macros - <i>like M6ATC.m1s, macropump.m1s and so on</i> - will be placed in "macros\MSM_ATC" folder. Move all files found inside this folder into your "macros/DEFAULT_FOLDER_NAME". It is mandatory to copy at least <i>M6ATC.m1s and macropump.m1s</i> to your "macros/DEFAULT_FOLDER_NAME". In the same directory "MSM_ATC" you will find more files: <i>M606, M1000 and Modbus.cfg</i>. These files will be explaind later, for now are not required.
3. Start Mach3 and make sure you have "Auto Tool Changer" option selected and "Run Macro Pump" option is enabled. 
4. If you just enabled the use of macropump you have to restart Mach3
5. Go to MachStdMill/Settings page and press the "Load Screen" button. Load the "MSM_ATC.set" screenset from MachStdMill\Set Files\Custom folder. DO NOT LOAD this screenset directly from Mach3\View\Load Screen menu.
6. If everything is OK you should have now a customized MachStdScreen with the USER page renamed to ATC and a modified Settings/Spindles page where ATC system have to be configured, like bellow:

![Unconfigured ATC Page](_Doc/Images/MSM_ATC_Unconfigured.PNG)
![Unconfigured ATC Settings Page](_Doc/Images/MSM_ATC_Settings_Unconfigured.PNG)

 
### Configuration of MSM_ATC - Settings/Spindles Page
- MSM_ATC is able to work with fixed racks aligned on X or Y Axis. Select the desired axis by pressing the <i>invisible</i> button which is above "Step" and "Clear" labels in Settings/Spindles page. After pressing it a confirmation dialog will ask for confirmation and the labels should switch from Step X to Step Y and from Clear Y to Clear X, or vice versa, if Y axis was previously selected.
- First time we have to declare the first slot's position. This is the position where the first slot's tool is load or released. Set it by filling Rack X, Rack Y and Rack Z fields. All values have to be in Machine Coordinates only!
- If the rack is built with holding forks, the tool have to be removed from or returned to the fork by an additional movement along Y-Axis (if rack is aligned along X-Axis). The Y-Axis position from where this additional movement is starting or ending is called Clear Y (or Clear X for Y-Axis aligned rack). Set the Clear Y (or Clear X for Y-Axis aligned rack) field as an Y-Axis (or X-Axis) position where the tool can be clearly moved up or down, in front of slot's forks.
- If this additional movement is not needed just set Clear Y (Clear X) with the same value with Rack Y (Rack X, for Y-Axis aligned rack). In this case the tool will be loaded or returned only by a vertical movement along Z-Axis. 
-  Step X (Step Y, for X-Axis aligned rack) is the distance between each adjacent slots of the rack, along X Axis (or Y Axis).
-  Safe Z is the Z-Axis position where the spindle is raised when ATC operations occur.
-  MSM_ATC can handle reporting status for each slot of the rack. For now, because the sensor's brain and hardware interface is not configured, we will disable this function. To disable this function we have to set the Check Z value with the same value of Rack Z. If Check Z == Rack Z, this feature is disabled and the ATC system is running in blind mode. The use of these sensors will be explained later. 
-  Empty Z - USE WITH CAUTION! - will allow the machine to move above tool holders at a different position when the spindle does not have tool loaded (when empty spindle). This is helpful for long Z-Axis machines and prevent  the return to Safe Z when the spindle is empty and can travel at a lower Z-Axis position when empty. To disable this intermediary position, just set Empty Z as the same value with Safe Z. This is also recommended for now.
-  TC Feedrate is the speed for ATC operations.
-  ATC Msg. Err. Level - is the level of reported ATC messages. For debugging set a higher value, like 5, which will report any ATC operation. For regular run, set this level at 1 or 2, only basic operation is reported.
-  Sensors Timeout - this is a delay used when checking for slot sensor's status. In some condition, the status is delayed and this waiting time is required. If sensors use is enabled and checked, after this delay the system report the error (if still in error condition) and give to the user the possibility to abort, recheck or ignore the sensor's status inside ATC operations.
- Actual Air Pressure is the air pressure reported by Arduino Sensors (if available). This is a readonly value.
- Min. Working Pressure is the minimum working pressure for properly ATC operations. If no air pressure or nor Arduino Sensors Board available, set it equal or lower (even negative values are allowed) with Actual Air Pressure.
- Slots Management - By default all 10 slots are disabled. You have to enable all the needed (available) slots you want to use. If needed, each slot can be enabled/disabled individually.
- Disabling a slot will also remove it's previously loaded tool. Re-enabling a slot will enable the slot as an empty slot (tool no. 0). 

### Slot Sensors
- MSM_ATC can handle slot sensors. The sensors status have to be passed to OEM Trig #1 - #10 inputs. Because Mach3 alone cannot handle more than 2 parallel ports, a different way for passing slot's sensors status could be an Arduino board which communicate with Mach3 through Modbug protocol and some brains.
- The Arduino code could be found in _Doc folder and was tested with Arduino Uno and Mega 2560. It will require a serial modbus communication device installed and configured for Mach3.
- The schematic:  ![Unconfigured ATC Page](_Doc/Images/Arduino_Schematic_Diagram.PNG)

