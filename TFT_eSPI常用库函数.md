```cpp
#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
#define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
//#define LOAD_FONT8N // Font 8. Alternative to Font 8 above, slightly narrower, so 3 digits fit a 160 pixel TFT
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

// Comment out the #define below to stop the SPIFFS filing system and smooth font code being loaded
// this will save ~20kbytes of FLASH
#define SMOOTH_FONT

********************************* 默认值 ********************************
rotation  = 0;
cursor_y  = cursor_x  = 0;
textfont  = 1;
textsize  = 1;
textcolor   = bitmap_fg = 0xFFFF; // White
textbgcolor = bitmap_bg = 0x0000; // Black
padX = 0;             // No padding
isDigits   = false;   // No bounding box adjustment
textwrapX  = true;    // Wrap text at end of line when using print stream
textwrapY  = false;   // Wrap text at bottom of screen when using print stream
textdatum = TL_DATUM; // Top Left text alignment is default
fontsloaded = 0;
***********************************************************************

begin(uint8_t tc) //Included for backwards compatibility
init(uint8_t tc) //Reset, then initialise the TFT display registers

setRotation(uint8_t m) //rotate the screen orientation m = 0-3 or 4-7 for BMP drawing
旋转屏幕，m=0-3或4-7 0 = 0,1 = 90,2 = 180,3 = 270。

writecommand(uint8_t c) //Send an 8 bit command to the TFT examples/320 x 240/TFTwidth(_Matrix/TFT_Matrix.ino
writedata(uint8_t d) //Send a 8 bit data value to the TFT
readcommand8(uint8_t cmd_function, uint8_t index) //Read a 8 bit data value from an indexed command register
readcommand16(uint8_t cmd_function, uint8_t index) //Read a 16 bit data value from an indexed command register
readcommand32(uint8_t cmd_function, uint8_t index) //Read a 32 bit data value from an indexed command register

readPixel(int32_t x0, int32_t y0) //Read 565 pixel colours from a pixel

setCallback(getColorCallback getCol)

readRect(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t *data) //Read 565 pixel colours from a defined area

pushRect(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t *data) //push 565 pixel colours into a defined area

pushImage(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t *data) //plot 16 bit colour sprite or image onto TFT
pushImage(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t *data, uint16_t transp) //plot 16 bit sprite or image with 1 colour being transparent
pushImage(int32_t x, int32_t y, int32_t w, int32_t h, const uint16_t *data) //plot 16 bit image
pushImage(int32_t x, int32_t y, int32_t w, int32_t h, const uint16_t *data, uint16_t transp) //plot 16 bit image with 1 colour being transparent
pushImage(int32_t x, int32_t y, int32_t w, int32_t h, uint8_t *data, bool bpp8) //plot 8 bit image or sprite using a line buffer
pushImage(int32_t x, int32_t y, int32_t w, int32_t h, uint8_t *data, uint8_t transp, bool bpp8) //plot 8 or 1 bit image or sprite with a transparent colour

setSwapBytes(bool swap) //Used by 16 bit pushImage() to swap byte order in colours
getSwapBytes(void)  //Return the swap byte order for colours

readRectRGB(int32_t x0, int32_t y0, int32_t w, int32_t h, uint8_t *data) //Read RGB pixel colours from a defined area




****************************  圆  ***********************************
drawCircle(int32_t x0, int32_t y0, int32_t r, uint32_t color),
在x和y位置使用r和color，绘制一个圆

fillCircle(int32_t x0, int32_t y0, int32_t r, uint32_t color),
在x和y位置使用r和t color中绘制一个实心圆。

/*drawCircleHelper(int32_t x0, int32_t y0, int32_t r, uint8_t cornername, uint32_t color),
在x和y位置使用r和color，绘制一个缺口为cornername度的圆
fillCircleHelper(int32_t x0, int32_t y0, int32_t r, uint8_t cornername, int32_t delta, uint32_t color),
在x和y位置使用r radius和t color中绘制一个cornername度的实心扇形？
*/作用未知

drawEllipse(int16_t x0, int16_t y0, int32_t rx, int32_t ry, uint16_t color),
画椭圆
fillEllipse(int16_t x0, int16_t y0, int32_t rx, int32_t ry, uint16_t color),
填充椭圆
*****************************************************************************


***************************** 矩形 ***********************************
drawRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color),
在x和y位置绘制一个填充的矩形。 w是宽度，h是高度，t是rextangle的颜色

drawRoundRect(int32_t x0, int32_t y0, int32_t w, int32_t h, int32_t radius, uint32_t color),
绘制一个圆角矩形，在x和y位置具有r半径圆角，w宽度和h高度和t颜色

fillRoundRect(int32_t x0, int32_t y0, int32_t w, int32_t h, int32_t radius, uint32_t color),
绘制一个填充的圆角矩形，其中x和y位置具有r半径圆角，w宽度和h高度和t颜色
*********************************************************************

fillScreen(uint32_t color)
将液晶屏颜色更改为color颜色。 color应该是包含UTFT颜色代码的32位变量

******************************** 三角形 **************************************
drawTriangle(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color),
绘制一个三角形位置x、y和z以及color颜色的三角形

fillTriangle(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color),
绘制一个三角形位置x、y和z以及color颜色的填充三角形
******************************************************************************

******************************** 显示单色图像 **************************************
drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color),
首先，您应该将图像转换为十六进制代码。如果您不想更改软件的设置，则必须反转图像的颜色并使图像水平镜像并逆时针旋转90度。现在将其添加到软件并进行转换。打开导出的文件并将十六进制代码复制到Arduino IDE。 x和y是图像的位置。 w和h是图像的大小。您可以在最后一个输入中更改图像的颜色。

drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color),
xbm是一种简单的双色图片位图格式,在早期的cgi中运用较多，目前多用于计数器上
drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t fgcolor, uint16_t bgcolor),
有前景、背景色
***********************************************************************************

*********************************** 光标，文本、图像设置 ****************************************
setCursor(int16_t x, int16_t y)
将光标位置设置为x和y
setCursor(int16_t x, int16_t y, uint8_t font)
将光标位置设置为x和y,字体为font

getCursorX(void)
getCursorY(void)
获取光标位置，X，Y

setTextSize(uint8_t s)
设置文本大小，S是1-7之间的数字
setTextColor(uint16_t c)
设置文本的颜色
setTextColor(uint16_t c, uint16_t b)
设置文本的颜色及其背景

setPivot(int16_t x, int16_t y)
getPivotX(void)
getPivotY(void)

setBitmapColor(uint16_t fgcolor, uint16_t bgcolor), // For 1bpp sprites
设置图像前后颜色

setTextWrap(boolean wrapX, boolean wrapY)
设置文本是否换行

setTextDatum(uint8_t d)
设置文本基准
setTextPadding(uint16_t x_width)
设置填充宽度，擦除原来的文字和数字

getRotation(void)
获取数字m
getTextDatum(void)
获取文本基准

width(void) //Return the pixel width of display (per current rotation)
height(void) //Return the pixel height of display (per current rotation)

textWidth(const String& string)
返回 字符串在当前字体下的像素宽度
textWidth(const String& string, uint8_t font)
返回 字符串在字体font下的像素宽度

fontsLoaded(void) //return an encoded 16 bit value showing the fonts loaded

fontHeight(int16_t font) //return the height of a font (yAdvance for free fonts)
fontHeight(void)

*************************************** 显示文本、数字 *****************
setAddrWindow(int32_t x0, int32_t y0, int32_t w, int32_t h) //define an area to receive a stream of pixels

drawPixel(int32_t x, int32_t y, uint32_t color) //push a single pixel at an arbitrary position

pushColor(uint16_t color) //push a single pixel
pushColor(uint16_t color, uint32_t len) //push a single colour to "len" pixels

startWrite(void) //begin transaction with CS low, MUST later call endWrite
endWrite(void) //end transaction with CS high

pushColors(uint8_t *data, uint32_t len) //push an array of pixels for 16 bit raw image drawing(Assumed that setAddrWindow() has previously been called)
pushColors(uint16_t *data, uint32_t len, bool swap) //push an array of pixels, for image drawing
----------------------------------------------------------------------

drawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint32_t color) //draw a line between 2 arbitrary points

drawFastVLine(int32_t x, int32_t y, int32_t h, uint32_t color) //draw a vertical line
drawFastHLine(int32_t x, int32_t y, int32_t w, uint32_t color) //draw a horizontal line

fillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color)//draw a filled rectangle

color565(uint8_t r, uint8_t g, uint8_t b) //convert three 8 bit RGB levels to a 16 bit colour value
color16to8(uint16_t c) //convert 16 bit colour to an 8 bit 332 RGB colour value
color8to16(uint8_t color) //convert 8 bit colour to a 16 bit 565 colour value

invertDisplay(boolean i) //invert the display colours i = 1 invert, i = 0 normal 反转屏幕的颜色

decodeUTF8(uint8_t c) //Serial UTF-8 decoder with fall-back to extended ASCII
decodeUTF8(uint8_t *buf, uint16_t *index, uint16_t remaining) //Line buffer UTF-8 decoder with fall-back to extended ASCII

drawChar(uint16_t uniCode, int32_t x, int32_t y)//draw a single character in the Adafruit GLCD font(Any UTF-8 decoding must be done before calling drawChar())
drawChar(uint16_t uniCode, int32_t x, int32_t y, uint8_t font)

// Without font number, uses font set by setTextFont()
drawString(const String& string, int32_t poX, int32_t poY)
// With font number
drawString(const String& string, int32_t poX, int32_t poY, uint8_t font)
// Without font number, uses font set by setTextFont()
drawString(const char *string, int32_t poX, int32_t poY)
// With font number. Note: font number is over-ridden if a smooth font is loaded
drawString(const char *string, int32_t poX, int32_t poY, uint8_t font)

//draw string centred on dX
drawCentreString(const String& string, int32_t dX, int32_t poY, uint8_t font)
drawCentreString(const char *string, int32_t dX, int32_t poY, uint8_t font)
//draw string right justified to dX
drawRightString(const String& string, int32_t dX, int32_t poY, uint8_t font)
drawRightString(const char *string, int32_t dX, int32_t poY, uint8_t font)

drawNumber(long long_num, int32_t poX, int32_t poY) //draw a long integer
drawNumber(long long_num, int32_t poX, int32_t poY, uint8_t font)

drawFloat(float floatNumber, uint8_t dp, int32_t poX, int32_t poY) //drawFloat, prints 7 non zero digits maximum
drawFloat(float floatNumber, uint8_t dp, int32_t poX, int32_t poY, uint8_t font)
*************************************************************************************

setFreeFont(const GFXfont *f) //Sets the GFX free font to use
setTextFont(uint8_t f) //Set the font for the print stream
setFreeFont(uint8_t font) //Sets the GFX free font to use

getSetup(setup_t &tft_settings) //Get the setup details for diagnostic and sketch access
```