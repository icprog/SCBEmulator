//ControlCAN.h@DSP Studio
//�ļ��汾��v1.0.2.1

#if !defined(__CONTROL__CAN__H__)
#define __CONTROL__CAN__H__

//�ӿڿ����Ͷ���
#define VCI_USBCAN1		3
#define VCI_USBCAN2		4

//�������÷���״ֵ̬
#define	STATUS_OK			1	//�����ɹ�
#define STATUS_ERR			0	//����ʧ��
#define STATUS_ERR2			-1	//�豸δ��

/*------------����ZLG�ĺ�������������---------------------------------*/

//USB-CAN����������/CANalyst-II�����ǵȣ��忨��Ϣ���������͡�
typedef  struct  _VCI_BOARD_INFO{
	USHORT	hw_Version;
	USHORT	fw_Version;
	USHORT	dr_Version;
	USHORT	in_Version;
	USHORT	irq_Num;
	BYTE	can_Num;
	CHAR	str_Serial_Num[20];
	CHAR	str_hw_Type[40];
	USHORT	Reserved[4];
} VCI_BOARD_INFO,*PVCI_BOARD_INFO;


//����CAN��Ϣ֡���������͡�
typedef  struct  _VCI_CAN_OBJ{
	UINT	ID;
	UINT	TimeStamp;	 			//ʱ���ʶ
	BYTE	TimeFlag;				//�Ƿ�ʹ��ʱ���ʶ
	BYTE	SendType;				//���ͱ�־��������δ��
	BYTE	RemoteFlag;				//�Ƿ���Զ��֡
	BYTE	ExternFlag;				//�Ƿ�����չ֡
	BYTE	DataLen;
	BYTE	Data[8];
	BYTE	Reserved[3];			//����
}VCI_CAN_OBJ,*PVCI_CAN_OBJ;

//����CAN������״̬���������͡�
typedef struct _VCI_CAN_STATUS{
	UCHAR	ErrInterrupt;
	UCHAR	regMode;
	UCHAR	regStatus;
	UCHAR	regALCapture;
	UCHAR	regECCapture; 
	UCHAR	regEWLimit;
	UCHAR	regRECounter; 
	UCHAR	regTECounter;
	DWORD	Reserved;
}VCI_CAN_STATUS,*PVCI_CAN_STATUS;

//���������Ϣ���������͡�
typedef struct _ERR_INFO{
	UINT	ErrCode;
	BYTE	Passive_ErrData[3];
	BYTE	ArLost_ErrData;
} VCI_ERR_INFO,*PVCI_ERR_INFO;

//�����ʼ��CAN����������
typedef struct _INIT_CONFIG{
	DWORD	AccCode;
	DWORD	AccMask;
	DWORD	Reserved;
	UCHAR	Filter;			//�˲���ʽ��0,1������������֡��2������׼֡�˲���3������չ֡�˲���
	UCHAR	Timing0;
	UCHAR	Timing1;
	UCHAR	Mode;			//����ģʽ��0��������ģʽ��1����ֻ��ģʽ,2�����Բ�ģʽ
}VCI_INIT_CONFIG,*PVCI_INIT_CONFIG;

DWORD __stdcall VCI_OpenDevice(DWORD DevType,DWORD DevIndex,DWORD Reserved);
DWORD __stdcall VCI_CloseDevice(DWORD DevType,DWORD DevIndex);
DWORD __stdcall VCI_InitCAN(DWORD DevType, DWORD DevIndex, DWORD CANIndex, PVCI_INIT_CONFIG pInitConfig);

DWORD __stdcall VCI_ReadBoardInfo(DWORD DevType,DWORD DevIndex,PVCI_BOARD_INFO pInfo);
DWORD __stdcall VCI_ReadErrInfo(DWORD DevType,DWORD DevIndex,DWORD CANIndex,PVCI_ERR_INFO pErrInfo);
DWORD __stdcall VCI_ReadCANStatus(DWORD DevType,DWORD DevIndex,DWORD CANIndex,PVCI_CAN_STATUS pCANStatus);

DWORD __stdcall VCI_GetReference(DWORD DevType,DWORD DevIndex,DWORD CANIndex,DWORD Reserved,PVOID pData);
DWORD __stdcall VCI_SetReference(DWORD DevType,DWORD DevIndex,DWORD CANIndex,DWORD RefType,PVOID pData);

DWORD __stdcall VCI_GetReceiveNum(DWORD DevType,DWORD DevIndex,DWORD CANIndex);
DWORD __stdcall VCI_ClearBuffer(DWORD DevType,DWORD DevIndex,DWORD CANIndex);

DWORD __stdcall VCI_StartCAN(DWORD DevType,DWORD DevIndex,DWORD CANIndex);
DWORD __stdcall VCI_ResetCAN(DWORD DevType,DWORD DevIndex,DWORD CANIndex);

DWORD __stdcall VCI_Receive(DWORD DevType,DWORD DevIndex,DWORD CANIndex,PVCI_CAN_OBJ pReceive,ULONG Len,INT WaitTime);
DWORD __stdcall VCI_Transmit(DWORD DeviceType,DWORD DeviceInd,DWORD CANInd,PVCI_CAN_OBJ pSend,DWORD Length);

/*------------�������������ݽṹ����---------------------------------*/

//USB-CAN�����������忨��Ϣ����������1��������ΪVCI_FindUsbDevice�����ķ��ز�����
typedef  struct  _VCI_BOARD_INFO1{
	USHORT	hw_Version;
	USHORT	fw_Version;
	USHORT	dr_Version;
	USHORT	in_Version;
	USHORT	irq_Num;
	BYTE	can_Num;
	BYTE	Reserved;
	CHAR	str_Serial_Num[8];
	CHAR	str_hw_Type[16];
	CHAR	str_Usb_Serial[4][4];
} VCI_BOARD_INFO1,*PVCI_BOARD_INFO1;

DWORD __stdcall VCI_GetReference2(DWORD DevType,DWORD DevIndex,DWORD CANIndex,DWORD Reserved,BYTE *pData);
DWORD __stdcall VCI_SetReference2(DWORD DevType,DWORD DevIndex,DWORD CANIndex,DWORD RefType,BYTE *pData);
DWORD __stdcall VCI_ResumeConfig(DWORD DevType,DWORD DevIndex,DWORD CANIndex);

DWORD __stdcall VCI_ConnectDevice(DWORD DevType,DWORD DevIndex);
DWORD __stdcall VCI_UsbDeviceReset(DWORD DevType,DWORD DevIndex,DWORD Reserved);
DWORD __stdcall VCI_FindUsbDevice(PVCI_BOARD_INFO1 pInfo);

#endif //#define __CONTROL__CAN__H__