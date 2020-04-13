# Installation of MSM_ATC Screenset

### Prerequisites:
- Mach3
- MachStdMill from Calypso Ventures (MSM_ATC was tested with v2.0.12)
- Home Switches enabled - it is mandatory to have the machine referenced when using ATC system.

1. Download MSM_ATC from here - https://github.com/Haimana/MSM_ATC
2. Extract all files and folders inside your Mach3 installation directory and overwrite all existing files. Some of the needed ATC macros - <i>like M6ATC.m1s, macropump.m1s and so on</i> - will be placed in "macros\MSM_ATC" folder. Move all files found inside this folder into your "macros/DEFAULT_FOLDER_NAME". It is mandatory to copy at least <i>M6ATC.m1s and macropump.m1s</i> to your "macros/DEFAULT_FOLDER_NAME". In the same directory "MSM_ATC" you will find more files: <i>M606, M1000 and Modbus.cfg</i>. These files will be explaind later, for not are not required.
3. Start Mach3 and make sure you have "Auto Tool Changer" option selected and "Run Macro Pump" option is enabled. 
4. If you just enabled the use of macropump you have to restart Mach3
5. Go to MachStdMill/Settings page and press the "Load Screen" button. Load the "MSM_ATC.set" screenset from MachStdMill\Set Files\Custom folder. DO NOT LOAD this screenset directly from Mach3\View\Load Screen menu.
6. If everything is OK you should have now a customized MachStdScreen with the USER page renamed to ATC and a modified Settings/Spindles page where ATC system have to be configured, like bellow:
![Unconfigured ATC Page](MSM_ATC/_Doc/Images/MSM_ATC_Unconfigured.PNG)

 
### Configuration of MSM_ATC
- soon