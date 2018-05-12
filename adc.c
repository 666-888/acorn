#include "CSU8RP3216.h"
#include "define_function.h"
#include "define_data.h"

//ADCģʽѡ��
void adc()
{
	if(if_adc)
	{
		SRADCON1=0X80;			//ʹ��ADת����VDD���ο���ѹ
		SRADCON2=0X10;			//����pt3.1��Ϊ����ͨ��
		PT3CON=0x02;			//����pt3.1Ϊģ���
		ad_voltage_collect();
		ad_deal();
	}                       	
	else                    	
	{                       	
		SRADCON1=0X81;      	//ʹ��ADת����P3.0�ⲿ�������ο���ѹ    
		SRADCON2=0Xa0;			//��������ͨ��(AIN10)Ϊ�ڲ��ο���ѹ�����òο���ѹ��С
		PT3CON=0X01;        	//����pt3.0Ϊģ���
		ad_voltage_collect();	
	}	
}

//ADC�ɼ�����
void ad_voltage_collect()
{
	int temp;							//ADֵ��ʱ�Ĵ���                        
	int i;                              //�����Ĵ���                            
	OFFEX = 0;	                        //offset��������					    
	AdData = 0;                         //��ADC�������ݵĸߵ�λ�Ĵ���           
	delay_10us();						//ADת��ǰ��ʱ10us
	for(i=1;i<=8;i++)                   //ѭ���ɰ˴�ADֵ                        
	{		                                                                    
		SRADS=1;                        //��ʼAD ת��                           
		asm("nop");	                                                            
		while(SRADS);                   //�ȴ�AD ת��                           
		OFFEX = !OFFEX;                 //offset ����                           
		temp=SRADH;                     //ȡADֵ�ĸ�λ                          
		AdData=(temp<<8)+SRADL+AdData;  //�ۼӰ˴�ADֵ��AdData�Ĵ���            
	}                                                                           
	C=0;								//bcf	status,c                        
	AdData>>=3;					        //��˴�ƽ�������ս������AdData�Ĵ���	
}
//ADC������
void ad_deal()
{	
	asm("movlw	TabStartAddr");
	asm("movwf	_EADRL");
	asm("movlw	.high(TabStartAddr)");	//ȡ���ַ��λ
	asm("movwf	_EADRH");				//�������ַ	
	asm("movp");						//����
	asm("nop");
	asm("movwf	_CurTabData");
	asm("movfw	_EDATH");
	asm("movwf	_CurTabData+1");		//��ֵ
	
	if(AdData<CurTabData)					//�Ƚϱ�ֵ�Ͳɼ�����ADֵ
	{									//��ADֵС���led1,led2ָʾ��                 
		R_AdcStation2_Cnt=0;                                                          
		R_AdcStation3_Cnt=0;                                                          
		R_AdcStation1_Cnt++;                                                          
		if(R_AdcStation1_Cnt>=20)       //�˲�����                                    
		{                               //����20��ADֵ�ȵ�һ����ֵС��ص�led1��led2  
			R_AdcStation1_Cnt=0;                                                      
			led1=0;                     //��led1��led2                                
			led2=0;                                                                   
		}                                                                             
	}                                                                                 
	else 			
	{                                   //��ADֵС����led1                            
		asm("movlw	1");
		asm("addwf	_EADRL,1");
		asm("clrf	_WORK");
		asm("addwfc _EADRH,1");			//�������ַ
		asm("movp");					//����
		asm("nop");
		asm("movwf	_CurTabData");
		asm("movfw	_EDATH");
		asm("movwf	_CurTabData+1");	//��ֵ

		if(AdData<CurTabData)                //�Ƚϱ�ֵ�Ͳɼ�����ADֵ                    
		{                         		
			R_AdcStation1_Cnt=0;
			R_AdcStation3_Cnt=0;
			R_AdcStation2_Cnt++;
			if(R_AdcStation2_Cnt>=10)	//�˲�����                                       
			{                           //����10��ADֵ�ȵڶ�����ֵС����led1����led2     
				R_AdcStation2_Cnt=0;                                                     
				led1=1;                 //��led1����led2                                 
				led2=0;	                                                                 
			}                                                                            
		}                                                                                
		else                                                                             
		{                               //��ADֵ������led2                               
			R_AdcStation1_Cnt=0;                                                         
			R_AdcStation2_Cnt=0;                                                         
			R_AdcStation3_Cnt++;                                                         
			if(R_AdcStation3_Cnt>=10)   //�˲�����                                       
			{                           //����10��ADֵ�ȵڶ�����ֵ������led2����led1     
				R_AdcStation3_Cnt=0;                                                     
				led1=0;                 //��led2����led1                                 
				led2=1;	
			}
		}
	}
}