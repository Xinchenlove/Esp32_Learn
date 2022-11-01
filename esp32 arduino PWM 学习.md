# 使用PWM实现LED呼吸灯

**esp32开发板的几乎所有引脚支持PWM输出**

#### 1、ledcSetup()函数

```c
double ledcSetup(uint8_t chan, double freq, uint8_t bit_num)
```



- 功能为设置LEDC通道对应的频率和计数复位(占空比)
- **uint8_t chan**  表示通道号
  - 取值为0-15 最多可设置16个通道
- **double freq** 期望设置的频率
- **uint8_t bit_num** 占空比复位计数，取值为0-20
  - 该值决定后面ledcWrite方法中占空比可写值，如果写值为10 则占空比最大为2^10-1 1024-1 = 1023

#### 2、ledcAttachPin()函数

```c
void ledcAttachPin(uint8_t pin, uint8_t channel);
```

- 将通道和I/O口连接
-  第一个参数为引脚号，第二个参数为设置的通道

#### 3、ledcWrite()函数

```c
void ledcWrite(uint8_t chan, uint32_t duty)
```

- 指定的 LEDC 通道的输出占空比

- 第一个参数`chan`为我们指定的LEDC通道，第二个参数`duty`表示占空比，其取值范围与`ledcSetup()`函数的`bit_num`有关。















