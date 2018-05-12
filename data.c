//============================================
// global variable
//============================================
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
	if_adc=1;						//if_adcΪ1ʱ���ɼ�����pt3.1�ڵĵ�ѹֵ��if_adcΪ0ʱ���ɼ�����оƬ�ڲ��ο���ѹ��ADֵ 
	if_pwm=0;                       //if_pwmΪ1ʱ�����pwm2�������������if_pwmΪ0ʱ���������pwm3                      		
}
