# WifiJammer
Using esp8266 Module, attacking the different wifi network and creating fake .<br />
Making Wi-Fi Jammer using NodeMCU:<br />
Contents<br />
1 Making Wi-Fi Jammer using NodeMCU:<br />
2 Method 1: Uploading Jammer Arduino sketch into ESP12<br />
3 Running the NodeMCU Wi-Fi Jammer:<br />
4 Make multiple fake WiFi networks ( Another Feature )<br />
5 Method 2: Uploading Wi-Fi Jammer firmware into ESP12 using ESP8266 flasher ( Simple Way )<br />
For this, you will have to burn the code or firmware into NodeMCU to use as a Wi-Fi jammer. There are two methods we will be discussing which you can use. <br />
<br />
<br />
Method 1: Uploading Jammer Arduino sketch into ESP12<br />
Step 1: First, we will start by uploading the Arduino code. Go to File>Preferences in Arduino IDE and add this link <br />1. (http://arduino.esp8266.com/stable/package_esp8266com_index.json ) <br />
2.(https://raw.githubusercontent.com/wiki/tobozo/Arduino/package_deauther_index.json)<br /> to the Additional Boards Manager URLs and select OK. <br />
Now close the Arduino IDE and reopen.<br />
Step 2: Go to Tools > Board > Board Manager. Search for ESP8266 and select ESP8266 (version 2.0.0 as this code will only work for this version). <br />
Step 3: Now go to File>Preferences and select the folder path under ‘More Preferences’.  Now open ESP8266 > hardware > ESP8266 > 2.0.0 > tools > sdk > and open the ‘user_interface.h’ file with text editor<br />
Step 4: Go to the last line of the code and before #endif add these lines: <br />
typedef void (** freedom_outside_cb__t)(uint8 status);<br />
int wifi_register_send_pkt_freedom_cb(freedom_outside_cb_t cb);<br />
void wifi_unregister_send_pkt_freedom__cb(void);<br />
 int wifi_send_pkt_freedom(uint8 ** buf, int len, bool sys_seq);<br />
After this Save the file. <br />
Step 5: Now extract the library you downloaded earlier and open it. open: esp8266_deauther-master -> esp8266_deauther -> esp8266_deauther.ino<br />

<br />
<br />
This will be the sketch that we will upload into the NodeMCU; this sketch it to be compiled. In case of error install these libraries.<br />
1.ArduinoJson<br />2.ESP8266 OLED SSD1306<br />3.Adafruit NeoPixel<br />4.LinkedList<br />

Our code is ready to be uploaded. Connect the NodeMCU to your PC, go to Tools menu and select NodeMCU esp-12E, select the correct port and then upload.<br />
<br />

**Drivers and COM Port**

In order to upload successfully, you must select the correct COM port. You can think of it as the address with that your computer accesses the ESP8266. The best way to find the correct port is to open the Arduino IDE and see what ports are listed there. This looks the same for every OS, including Linux. On Windows, COM1 is usually never the correct port. On Windows you can also have a look at your device manager, there you can also see if a device is not recognized.<br />
If none of the COM ports work correctly or you can't find any COM Port, you might need to install the drivers.<br />
The driver you need depends on the UART (USB to Serial) chip that is used on your development board.<br />
Those are the drivers of the most used chips:<br />
💾 CP2102(https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)<br />
💾 CH340(https://sparks.gogo.co.nz/ch340.html)

**Upload Settings**
Those are the recommended upload/compile settings for Arduino:<br />
Board: Generic ESP8266 Module  <br />
Flash Mode: DOUT<br />
Flash Frequency: 80 MHZ<br />
CPU Frequency: 160 MHz<br />
Flash Size: 1M (256K SPIFFS)<br />
Reset Method: nodemcu<br />
Upload Speed: 115200<br />
Port: < com port of your device ><br />
