//============================================
// global variable
//============================================

sbit if_key_press;
sbit if_usb_plug;
sbit if_adapter_plug;
sbit heating_low;
sbit B_low_battery_shutdown;
sbit B_low_battery_warning;

//working mode
unsigned char work_mode = WORK_MODE_SHUTDOWN;

//ADC
unsigned int AdData;                //ADC��������
unsigned int CurTabData;			//�������ݼĴ���
unsigned char R_AdcStation1_Cnt,R_AdcStation2_Cnt,R_AdcStation3_Cnt;



sbit B_200ms;
sbit B_urr;
sbit B_urt;
sbit B_send_ok;

sbit B_Time500ms;
sbit B_pwm2;
sbit B_pwm3;
sbit if_pwm;

sbit if_adc;

unsigned char R_flag;
unsigned char R_200ms_cnt;

unsigned char t200ms_count;
unsigned char t1s_count;
unsigned char t10s_count;

unsigned char R_LED_S;              //�洢LED״̬�ı���
unsigned char E2_Addr;            //eeprom��ַ
unsigned char E2_Data;            //eeprom����

unsigned int CurTabData;			//�������ݼĴ���
unsigned int AdData;                //ADC��������
unsigned char R_AdcStation1_Cnt,R_AdcStation2_Cnt,R_AdcStation3_Cnt;

unsigned char R_key;        //����������־
unsigned char R_Key_Value;  //�洢��ֵ�ı���

sbit B_Sleep;

//const unsigned int a[2]={0x0c71,0x0e38}; //2.5V 2.9V ADC�����Ƚ�ֵ,�������飬���ݴ洢��RAM��

//λ�����ʼ��
void Bit_Initialization(void)
{
	if_key_press = 0;
	if_usb_plug = 0;
	if_adapter_plug = 0;
	
	heating_low = 0;  //default in low level
	B_low_battery_shutdown = 0;
	B_low_battery_warning = 0;
	
	B_pwm2 = 0;
}