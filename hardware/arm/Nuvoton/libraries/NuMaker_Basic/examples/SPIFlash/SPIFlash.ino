/*
  SPI Flash
  
	This sample code demonstrates how to access a Winbond 25x16 SPI flash without FIFO buffers.
	SPI configuration : Master mode; data width 8 bits.
		
*/
#include <SPI.h>
#include <SPIFlash.h>

#define TEST_PAGE_NUM 10  /* page numbers */
#define BYTE_PER_PAGE 256 /* byte per page */

uint8_t SrcArray[BYTE_PER_PAGE];
uint8_t DestArray[BYTE_PER_PAGE];

// set pin 10 as the slave select for the digital pot:
const int slaveSelectPin = SS;

void setup()
{
  uint32_t u32ByteCount, u32FlashAddress, u32PageNumber;
  uint32_t u32Error = 0;
  uint32_t u32ID;
  Serial.begin(115200);
  Serial.print("\n+------------------------------------------------------------------------+\n");
  Serial.print("|               SPI Flash with FIFO mode Sample                          |\n");
  Serial.print("+------------------------------------------------------------------------+\n");  
  Serial.println("This sample code demonstrates how to access a");
  Serial.println("Winbond 25x16 SPI flash without FIFO buffers.");

  // initialize SPIFlash:  
  SPIFlash.begin(slaveSelectPin);
  /* Wait ready */
  SPIFlash.WaitReady();  
  if(SPIFlash.ReadMidDid()!= 0xEF14)
  {
    Serial.print("Wrong ID, 0x");
    Serial.println(u32ID,HEX);
    return;		
  }else
    Serial.print("Flash found: W25x16 ...\n");	

  Serial.print("Erase chip ...");
  SPIFlash.ChipErase(); /* Chip erase */ 
  SPIFlash.WaitReady(); /* Wait ready */
  Serial.println("[OK]");
  
  /* init source data buffer */
  for(u32ByteCount = 0; u32ByteCount < BYTE_PER_PAGE; u32ByteCount++)
  {
    SrcArray[u32ByteCount] = u32ByteCount;
  }
  
  Serial.print("Start to write data to Flash ...");
  /* Program SPI flash */
  u32FlashAddress = 0;
  for(u32PageNumber = 0; u32PageNumber < TEST_PAGE_NUM; u32PageNumber++)
  {  /* page program */
    SPIFlash.PageProgram(u32FlashAddress, SrcArray, BYTE_PER_PAGE);
    SPIFlash.WaitReady();
    u32FlashAddress += 0x100;
  }    
  Serial.print("[OK]\n");
  
  Serial.print("Read & Compare ...");
  /* Read SPI flash */
  u32FlashAddress = 0;
  for(u32PageNumber = 0; u32PageNumber < TEST_PAGE_NUM; u32PageNumber++)
  {  /* page read */
    SPIFlash.ReadData(u32FlashAddress, DestArray, BYTE_PER_PAGE);
    u32FlashAddress += 0x100;
    for(u32ByteCount = 0; u32ByteCount < BYTE_PER_PAGE; u32ByteCount++)
    {
      if(DestArray[u32ByteCount] != SrcArray[u32ByteCount])
        u32Error ++;
    }
  }  
  
  if(u32Error == 0)
     Serial.print("[OK]\n");
  else
    Serial.print("[FAIL]\n");
}
void loop()
{

}