#ifndef  	_define_function_h
#define 	_define_function_h 1 

/*-------------------------------------------------
Code Name: None
Include  : None
Ouput    : None
function : ��������
---------------------------------------------------*/
/*-------------------------------------------------
delay.c
-------------------------------------------------*/
extern void delay();                              //�����ʱ
extern void delay_10us();                         //��ʱ10us
/*-------------------------------------------------
initialization.c
-------------------------------------------------*/
extern void MCU_Initialization(void);             //оƬ��ʼ��
void Bit_Initialization(void);					  //λ��ʼ��
/*-------------------------------------------------
adc.c
-------------------------------------------------*/
//ADCģʽѡ��
extern void adc_battery();
extern void adc_temp1();
extern void adc_temp2();
//ADC�ɼ�����
extern void ad_voltage_collect();
//ADC������
extern void battery_deal();
extern void temp1_deal();
extern void temp2_deal();
/*-------------------------------------------------
lowpower.c
-------------------------------------------------*/
extern void sleep(void);
/*-------------------------------------------------
pwm.c
-------------------------------------------------*/
extern void open_pwm(void);

#endif 








