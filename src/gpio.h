// -------------------------------------------------------------------------------

// Autores:

// Caio Alessandro Resnauer
// Erik Ryuichi Yamamoto
// Victor Jordão

// -------------------------------------------------------------------------------

#define BIT0 (0x1)
#define BIT1 (0x2)
#define BIT2 (0x4)
#define BIT3 (0x8)
#define BIT4 (0x10)
#define BIT5 (0x20)
#define BIT6 (0x40)
#define BIT7 (0x80)
#define BIT8 (0x100)
#define BIT9 (0x200)
#define BIT10 (0x400)
#define BIT11 (0x800)
#define BIT12 (0x1000)
#define BIT13 (0x2000)
#define BIT14 (0x4000)
#define BIT15 (0x8000)

#define GPIO_PORTJN (0x1100) //bits 8 e 12
#define GPIO_PORTAKQ (0x4201) // Portas para os LEDs, LCD e BCDs [Porta A (Bit 0) | Porta K (Bit 9) | Porta Q (Bit 14)]
#define GPIO_PORTBM (0x0802) // Portas para os Transistores BCDs e LEDs e Controle do LCD [Porta B (Bit 1) | Porta M (Bit 11)]
#define GPIO_PORTCL (0x0404) // Portas para o Teclado Matricial [Porta C (Bit 2) | Porta L (Bit 10)]
#define GPIO_PORTEF (0x0030) // Portas para o Motor DC e Motor de Passo Bipolar e Conversor A/D [Porta E (Bit 4) | Porta F (Bit 5)]
#define GPIO_PORTH (0x0080) // Portas para o Motor de Passo Unipolar [Porta H (Bit 7)]
#define GPIO_PORTP (0x2000) // Portas para a UART [Porta P (Bit 13)]

#define LIMITE_ESPERA (500) // Limite de ciclos para esperar a resposta de uma determinada função


void GPIO_Init(void);

uint32_t PortC_Input(void);
uint32_t PortJ_Input(void);

void PortA_Output(uint32_t valor);
void PortB_Output(uint32_t valor);
void PortE_Output(uint32_t valor);
void PortF_Output(uint32_t valor);
void PortH_Output(uint32_t valor);
void PortK_Output(uint32_t valor);
void PortL_Output(uint32_t valor);
void PortM_Output(uint32_t valor);
void PortN_Output(uint32_t valor);
void PortQ_Output(uint32_t valor);