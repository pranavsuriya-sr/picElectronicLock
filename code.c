#include <xc.h>
int attCount = 0;
unsigned int arr[15][3];
unsigned char print[15][3];
int flag = 0;

void delay_ms(int ms);
void Data(int Value);           
void Cmd(int Value);            
void Send2Lcd(const char Adr, const char *Lcd);

void __interrupt() adcint()
{
	 GIE   = 0;
	if (ADIF == 1)
    {
        flag=1;
        ADIF=0;        
    }
	GIE   = 1;
}

void mainCall()
{
    TRISC=0X00;                
    TRISD=0X00;                
    TRISB=0x00;
    PORTB=0x00;
    PORTC=0x00;
    delay_ms(15);             
     Cmd(0X30);	delay_ms(5);    
     Cmd(0X30);	delay_ms(1);    
     Cmd(0X30);	delay_ms(2);    
     Cmd(0X38);                 
     Cmd(0X06);                 
     Cmd(0X01);                
     Cmd(0X0C);                 
     Send2Lcd(0x80,"1_reg_user");	
     delay_ms(3);
     delay_ms(500);
     Cmd(0X01);
     Send2Lcd(0x80,"2_login");	
     delay_ms(3);
     delay_ms(500);
     Send2Lcd(0x80,"3_delete_user");	
     delay_ms(3);
     delay_ms(500);
     Send2Lcd(0x80,"4_display_count");	
     delay_ms(3);
     delay_ms(500);

}
void idCall()
{

    delay_ms(15);              
     Cmd(0X30);	delay_ms(5);   
     Cmd(0X30);	delay_ms(1);    
     Cmd(0X30);	delay_ms(2);    
     Cmd(0X38);                 
     Cmd(0X06);                 
     Cmd(0X01);                 
     Cmd(0X0C);                 
     Send2Lcd(0x80,"enter id");	
     delay_ms(3);
     delay_ms(500);
}
void pwCall()
{

    delay_ms(15);              
     Cmd(0X30);	delay_ms(5);    
     Cmd(0X30);	delay_ms(1);    
     Cmd(0X30);	delay_ms(2);    
     Cmd(0X38);                 
     Cmd(0X06);                 
     Cmd(0X01);                
     Cmd(0X0C);                 
     Send2Lcd(0x80,"enter pw");	
     delay_ms(3);
     delay_ms(500);

}
void crctCall()
{

    delay_ms(15);              
     Cmd(0X30);	delay_ms(5);    
     Cmd(0X30);	delay_ms(1);    
     Cmd(0X30);	delay_ms(2);    
     Cmd(0X38);                 
     Cmd(0X06);                 
     Cmd(0X01);                 
     Cmd(0X0C);                 
     Send2Lcd(0x80,"crct....enter");	
     delay_ms(3);
     delay_ms(500);

}
void wrongCall()
{

    delay_ms(15);              
     Cmd(0X30);	delay_ms(5);    
     Cmd(0X30);	delay_ms(1);    
     Cmd(0X30);	delay_ms(2);    
     Cmd(0X38);                 
     Cmd(0X06);                 
     Cmd(0X01);                 
     Cmd(0X0C);                 
     Send2Lcd(0x80,"wrong password");	
     delay_ms(3);
     delay_ms(500);

}
void delCall()
{

    delay_ms(15);              
     Cmd(0X30);	delay_ms(5);    
     Cmd(0X30);	delay_ms(1);    
     Cmd(0X30);	delay_ms(2);    
     Cmd(0X38);                 
     Cmd(0X06);                 
     Cmd(0X01);                 
     Cmd(0X0C);                                            
     Send2Lcd(0x80,"user deleted");	                   
     delay_ms(3);
     delay_ms(500);

}
void num1Call()
{

    delay_ms(15);              
     Cmd(0X30);	delay_ms(5);    
     Cmd(0X30);	delay_ms(1);    
     Cmd(0X30);	delay_ms(2);    
     Cmd(0X38);                 
     Cmd(0X06);                 
     Cmd(0X01);                 
     Cmd(0X0C);                                            
     Send2Lcd(0x80,"enter num1");	                   
     delay_ms(3);
     delay_ms(500);

}
void num2Call()
{

    delay_ms(15);              
     Cmd(0X30);	delay_ms(5);    
     Cmd(0X30);	delay_ms(1);    
     Cmd(0X30);	delay_ms(2);    
     Cmd(0X38);                 
     Cmd(0X06);                 
     Cmd(0X01);                 
     Cmd(0X0C);                                            
     Send2Lcd(0x80,"enter num2");	                   
     delay_ms(3);
     delay_ms(500);

}
void Cmd(int Value)
{
     PORTD=Value;
     RC1=0;                     
     RC0=0;                     
     RC2=1;                     
     delay_ms(4);               
     RC2=0;                     
}	

void Data(int Value)
{
     PORTD=Value;
     RC1=1;                     
     RC0=0;                     
     RC2=1;                    
     delay_ms(4);               
     RC2=0;                    
}

void Send2Lcd(const char Adr, const char *Lcd)
{
     Cmd(Adr);
     while(*Lcd!='\0')	{	Data(*Lcd);		Lcd++;	}
     
}
void delay_ms(int ms)
{
	int i,count;
	
	for(i=1;i<=ms;i++)
	{
		count=1000;
		while(count!=1)
		{
			count--;
		}
	}
}
void deleteUser()
{
    
    idCall();
    // Getting the ID
    TRISA = 0x00;
    TRISD = 0x00;
    TRISB = 0x1F;

    nRBPU = 0;
    PCFG3 = 0;
    PCFG2 = 0;
    PCFG1 = 0;
    PCFG0 = 0;

    // Enter the ID to delete
    RB7 = 1;
    RB6 = 1;
    RB5 = 0;
    int deleteNum = 0;
    PORTD = 0x00;
    for (long long k = 0; k < 100000; k++);
    if (RB1 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x21;
        while (RB1 == 0);
        deleteNum = 1;
    }
    else if (RB2 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0xCB;
        while (RB1 == 0);
        deleteNum = 2;
    }
    else if (RB3 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x63;
        while (RB1 == 0);
        deleteNum = 3;
    }
    for (long long k = 0; k < 100000; k++);
    deleteNum = deleteNum * 10;

    int deleteNum2;
    for (long long k = 0; k < 100000; k++);
    if (RB1 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x21;
        while (RB1 == 0);
        deleteNum2 = 1;
    }
    else if (RB2 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0xCB;
        while (RB1 == 0);
        deleteNum2 = 2;
    }
    else if (RB3 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x63;
        while (RB1 == 0);
        deleteNum2 = 3;
    }
    for (long long k = 0; k < 100000; k++);
    deleteNum = deleteNum + deleteNum2;

    // Delete the user by resetting their ID and password in the array
    for (int i = 0; i < 3; i++)
    {
        arr[deleteNum][i] = 0;
      
    }
    
    delCall();
}


void loginUser()
{
    idCall();
    int i = 0;
    unsigned int test[3];
    
    TRISA = 0x00;
    TRISD = 0x00;
    TRISB = 0x1F;
    
    nRBPU = 0;
    PCFG3 = 0;
    PCFG2 = 0;
    PCFG1 = 0;
    PCFG0 = 0;
    
    // For ID input
    int num;
    
    // num1
    RB7 = 1;
    RB6 = 1;
    RB5 = 0;
    int num1;
    PORTD = 0x00;
    num1Call();
    for (long long k = 0; k < 100000; k++);
    if (RB1 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x21;
        while (RB1 == 0);
        num1 = 1;
    }
    else if (RB2 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0xCB;
        while (RB1 == 0);
        num1 = 2;
    }
    else if (RB3 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x63;
        while (RB1 == 0);
        num1 = 3;
    }
    else
    {
        num1 = 0;
    }
    for (long long k = 0; k < 100000; k++);
    num1 = num1 * 10;
    
    
    num2Call();
    // num2
    RB7 = 1;
    RB6 = 1;
    RB5 = 0;
    int num2;
    PORTD = 0x00;
    for (long long k = 0; k < 100000; k++);
    if (RB1 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x21;
        while (RB1 == 0);
        num2 = 1;
    }
    else if (RB2 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0xCB;
        while (RB1 == 0);
        num2 = 2;
    }
    else if (RB3 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x63;
        while (RB1 == 0);
        num2 = 3;
    }
    for (long long k = 0; k < 100000; k++);
    num = num1 + num2;
    
    
    pwCall();
    // Getting the ID
    RA3 = 0;
    RA2 = 0;
    RA1 = 0;
    RA0 = 1;
    
    
    while (i < 3)
    {
        RB7 = 1;
        RB6 = 1;
        RB5 = 0;
        PORTD = 0x00;
        for (long long k = 0; k < 100000; k++);
        if (RB1 == 0)
        {
            for (long long k = 0; k < 100000; k++);
            PORTD = 0x21;
            while (RB1 == 0);
            test[i] = 1;
        }
        else if (RB2 == 0)
        {
            for (long long k = 0; k < 100000; k++);
            PORTD = 0xCB;
            while (RB1 == 0);
            test[i] = 2;

        }
        else if (RB3 == 0)
        {
            for (long long k = 0; k < 100000; k++);
            PORTD = 0x63;
            while (RB1 == 0);
            test[i] = 3;

        }
        else if(RB4 == 0)
        {
            for (long long k = 0; k < 100000; k++);
            PORTD = 0x2D;
            while (RB4 == 0);
            test[i] = 4;

        }
        else
        {
            RB7=1;
            RB6=0;
            RB5=1;
            if(RB1 == 0)
            {
                for (long long k = 0; k < 100000; k++);
                PORTD = 0X6E;
                while(RB1 == 0);
                test[i] = 5;
            }
        }
        
        
        
        for (long long k = 0; k < 100000; k++);
        
        i++;
    }
    
    unsigned char found = 0;

    
    if(test[0] == arr[num][0] && test[1] == arr[num][1] && test[2] == arr[num][2])
    {
        found = 1;
    }
    
    if(found == 1)
    {
        TRISD = 0x00;
        TRISA = 0x00;
        long long dispTime = 0;
        while(dispTime<100000)
        {
            RA0 = 1;
            PORTD = 0x63; //6
            RA0 = 0;
            PORTD = 0; 
            
            RA1 = 1;
            PORTD = 0x63;
            RA1 = 0;
            PORTD = 0;
            
            RA2 = 1;
            PORTD = 0x63;
            RA2 = 0;
            PORTD = 0;
            
            dispTime++;
        }
        attCount = attCount + 1;
        crctCall();
    }
    else
    {
        TRISD = 0x00;
        TRISA = 0x00;
        long long dispTime = 0;
        while(dispTime<100000)
        {
            RA0 = 1;
            PORTD = 0x21; //6
            RA0 = 0;
            PORTD = 0; 
            
            RA1 = 1;
            PORTD = 0x21;
            RA1 = 0;
            PORTD = 0;
            
            RA2 = 1;
            PORTD = 0x21;
            RA2 = 0;
            PORTD = 0;
            
            dispTime++;
        }
        
        int buzz = 2;
        TRISE = 0X00;
        while(buzz)
        {
            PORTE = 0X00;
            for(int bt = 0;bt<3000;bt++);
            PORTE = 0XFF;
            for(int bt = 0;bt<3000;bt++);
            
            buzz--;
        }
        wrongCall();
        PORTE = 0X00;
    }
}

int registerUser()
{
    idCall();
    unsigned int regPass1;
    
    TRISA = 0x00;
    TRISD = 0x00;
    TRISB = 0x1F;
    
    nRBPU = 0;
    PCFG3 = 0;
    PCFG2 = 0;
    PCFG1 = 0;
    PCFG0 = 0;
    
    RB7 = 1;
    RB6 = 1;
    RB5 = 0;
    int regNum = 0;
    PORTD = 0x00;
    num1Call();
    for (long long k = 0; k < 100000; k++);
    if (RB1 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x21;
        while (RB1 == 0);
        regNum = 1;
    }
    else if (RB2 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0xCB;
        while (RB1 == 0);
        regNum = 2;
    }
    else if (RB3 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x63;
        while (RB1 == 0);
        regNum = 3;
    }
    else
    {
        regNum = 0;
    }
    for (long long k = 0; k < 100000; k++);
    regNum = regNum * 10;
    
    
    num2Call();
    int regNum2;
    for (long long k = 0; k < 100000; k++);
    if (RB1 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x21;
        while (RB1 == 0);
        regNum2 = 1;
    }
    else if (RB2 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0xCB;
        while (RB1 == 0);
        regNum2 = 2;
    }
    else if (RB3 == 0)
    {
        for (long long k = 0; k < 100000; k++);
        PORTD = 0x63;
        while (RB1 == 0);
        regNum2 = 3;
    }
    for (long long k = 0; k < 100000; k++);
    regNum = regNum + regNum2;
    
    
    pwCall();
    int i = 0;
    while (i < 3)
    {
        RB7 = 1;
        RB6 = 1;
        RB5 = 0;
        PORTD = 0x00;
        
        
        for (long long k = 0; k < 100000; k++);
        if (RB1 == 0)
        {
            for (long long k = 0; k < 100000; k++);
            PORTD = 0x21;
            while (RB1 == 0);
            regPass1 = 1;
            print[regNum][i] = 0x21;
        }
        else if (RB2 == 0)
        {
            for (long long k = 0; k < 100000; k++);
            PORTD = 0xCB;
            while (RB1 == 0);
            regPass1 = 2;
            print[regNum][i] = 0xCB;
        }
        else if (RB3 == 0)
        {
            for (long long k = 0; k < 100000; k++);
            PORTD = 0x63;
            while (RB1 == 0);
            regPass1 = 3;
            print[regNum][i] = 0x63;
        }
        else if (RB4 == 0)
        {
            for (long long k = 0; k < 100000; k++);
            PORTD = 0x2D;
            while (RB4 == 0);
            regPass1 = 4;
            print[regNum][i] = 0x2D;
        }
        else
        {
            RB7=1;
            RB6=0;
            RB5=1;
            if(RB1 == 0)
            {
                for (long long k = 0; k < 100000; k++);
                PORTD = 0X6E;
                while(RB1 == 0);
                            regPass1 = 5;
                            print[regNum][i] = 0x6E;
            }
        }
        for (long long k = 0; k < 100000; k++);
        arr[regNum][i] = regPass1;
        
        i++;
    }
    
        TRISD = 0x00;
        TRISA = 0x00;
        long long dispTime = 0;
        while(dispTime<100000)
        {
            RA0 = 1;
            PORTD = print[regNum][0]; //6
            RA0 = 0;
            PORTD = 0; 
            
            RA1 = 1;
            PORTD = print[regNum][1];
            RA1 = 0;
            PORTD = 0;
            
            RA2 = 1;
            PORTD = print[regNum][2];
            RA2 = 0;
            PORTD = 0;
            
            dispTime++;
        }
    
        return 0;
        
}


void attCountDisp()
{
    int attnum1, attnum2;
    
    unsigned char hexnum2, hexnum1;
    
    attnum2 = attCount%10;
    
    if(attnum2 == 0)
    {
        hexnum2 = 0XE7;
    }
    
    else if(attnum2 == 1)
    {
        hexnum2 = 0X21;
    }
    
    else if(attnum2 == 2)
    {
        hexnum2 = 0XCB;
    }
    else if(attnum2 == 3)
    {
        hexnum2 = 0X63;
    }
    
    attnum1 = attCount/10;
    if(attnum1 == 0)
    {
        hexnum1 = 0XE7;
    }
    
    else if(attnum1 == 1)
    {
        hexnum1 = 0X21;
    }
    
    else if(attnum1 == 2)
    {
        hexnum1 = 0XCB;
    }
    else if(attnum1 == 3)
    {
        hexnum1 = 0X63;
    }
    
    
        TRISD = 0x00;
        TRISA = 0x00;
        long long dispTime = 0;
        while(dispTime<50000)
        {
            RA0 = 1;
            PORTD = hexnum1; //6
            RA0 = 0;
            PORTD = 0; 
            
            RA1 = 1;
            PORTD = hexnum2;
            RA1 = 0;
            PORTD = 0;
            
            dispTime++;
        }
    
}
void main()
{
 
    while(1)
    {
        mainCall();

        TRISA = 0X00;
        TRISD = 0X00;
        TRISB = 0X1F;
        int i=0,j,p=0;
        nRBPU = 0;
        PCFG3 = 0;
        PCFG2 = 0;
        PCFG1 = 0;
        PCFG0 = 0;
        
        RA3 = 0;RA2=0;RA1=0;RA0=1;
        RB7 = 1;
        RB6 = 1;
        RB5 = 0;
        PORTD = 0X00;
        if(RB1 == 0)
        {
            PORTD = 0X21;
            while(RB1 == 0);
            for(long long k=0;k<100000;k++);
            registerUser();
            for(long long k=0;k<100000;k++);
        }
        
        else if(RB2 == 0)
        {
            PORTD = 0XCB;
            while(RB2 == 0);
            for(long long k=0;k<100000;k++);
            loginUser();
            for(long long k=0;k<100000;k++);
            
    
        }
        
        else if(RB3 == 0)
        {
            PORTD = 0X63;
            while(RB3 == 0);
            for(long long k=0;k<100000;k++);
            deleteUser();
            for(long long k=0;k<100000;k++);
        }
        
        else if(RB4 == 0)
        {
            PORTD = 0X2D;
            while(RB4 == 0);
            for(long long k=0;k<100000;k++);
            attCountDisp();
            for(long long k=0;k<100000;k++);
        }

    }
}
