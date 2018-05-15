//============================================
// global variable
//============================================

//sleep
sbit B_Sleep;

//timer
sbit B_200ms;
sbit B_500ms;
sbit B_800ms;
sbit B_1s;
sbit B_2s;

//battery
sbit B_low_battery_shutdown;
sbit B_low_battery_warning;

//key
sbit B_key_pressed;
sbit B_key_waitfor_release;

//heating
sbit B_heat_level_low;
sbit B_heating;

//working mode
unsigned char work_mode;

//ADC
unsigned int AdData;                //ADC��������
unsigned int CurTabData;			//�������ݼĴ���
unsigned char R_AdcStation1_Cnt,R_AdcStation2_Cnt,R_AdcStation3_Cnt;

//timer count
unsigned char t200ms_count;
unsigned char t500ms_count;
unsigned char t800ms_count;
unsigned char t1s_count;
unsigned char t2s_count;
unsigned char t10s_count;

//const unsigned int a[2]={0x0c71,0x0e38}; //2.5V 2.9V ADC�����Ƚ�ֵ,�������飬���ݴ洢��RAM��

//λ�����ʼ��
void Bit_Initialization(void)
{	
	B_low_battery_shutdown = 0;
	B_low_battery_warning = 0;
	B_heat_level_low = 0;
	B_heating = 0;
}