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
extern void adc();
//ADC�ɼ�����
extern void ad_voltage_collect();
//ADC������
extern void ad_deal();
/*-------------------------------------------------
uart.c
-------------------------------------------------*/
//uart���ͺ���
extern void uart_send(char temp);
//uart���պ���
extern void uart_re();
//uart������
extern void uart();
/*-------------------------------------------------
lowpower.c
-------------------------------------------------*/
extern void sleep(void);
/*-------------------------------------------------
pwm.c
-------------------------------------------------*/
extern void open_pwm(void);

#endif 








