/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2013 Semtech

Description: SX1272 driver specific target board functions implementation

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis and Gregory Cristian
*/
#ifndef __SX1272_ARCH_H__
#define __SX1272_ARCH_H__

/*!
 * \brief Radio hardware registers initialization definition
 *
 * \remark Can be automatically generated by the SX1272 GUI (not yet implemented)
 */
#define RADIO_INIT_REGISTERS_VALUE                \
{                                                 \
    { MODEM_FSK , REG_LNA                , 0x23 },\
    { MODEM_FSK , REG_RXCONFIG           , 0x1E },\
    { MODEM_FSK , REG_RSSICONFIG         , 0xD2 },\
    { MODEM_FSK , REG_PREAMBLEDETECT     , 0xAA },\
    { MODEM_FSK , REG_OSC                , 0x07 },\
    { MODEM_FSK , REG_SYNCCONFIG         , 0x12 },\
    { MODEM_FSK , REG_SYNCVALUE1         , 0xC1 },\
    { MODEM_FSK , REG_SYNCVALUE2         , 0x94 },\
    { MODEM_FSK , REG_SYNCVALUE3         , 0xC1 },\
    { MODEM_FSK , REG_PACKETCONFIG1      , 0xD8 },\
    { MODEM_FSK , REG_FIFOTHRESH         , 0x8F },\
    { MODEM_FSK , REG_IMAGECAL           , 0x02 },\
    { MODEM_FSK , REG_DIOMAPPING1        , 0x00 },\
    { MODEM_FSK , REG_DIOMAPPING2        , 0x30 },\
    { MODEM_LORA, REG_LR_PAYLOADMAXLENGTH, 0x40 },\
}                                                 \

/*!
 * \brief Initializes the radio I/Os pins interface
 */
void SX1272IoInit( void );

/*!
 * \brief Initializes DIO IRQ handlers
 *
 * \param [IN] irqHandlers Array containing the IRQ callback functions
 */
void SX1272IoIrqInit( DioIrqHandler **irqHandlers );

/*!
 * \brief De-initializes the radio I/Os pins interface. 
 *
 * \remark Useful when going in MCU lowpower modes
 */
void SX1272IoDeInit( void );

/*!
 * \brief Gets the board PA selection configuration
 *
 * \param [IN] channel Channel frequency in Hz
 * \retval PaSelect RegPaConfig PaSelect value
 */
uint8_t SX1272GetPaSelect( uint32_t channel );

/*!
 * \brief Set the RF Switch I/Os pins in Low Power mode
 *
 * \param [IN] status enable or disable
 */
void SX1272SetAntSwLowPower( bool status );

/*!
 * \brief Initializes the RF Switch I/Os pins interface
 */
void SX1272AntSwInit( void );

/*!
 * \brief De-initializes the RF Switch I/Os pins interface 
 *
 * \remark Needed to decrease the power consumption in MCU lowpower modes
 */
void SX1272AntSwDeInit( void );

/*!
 * \brief Controls the antena switch if necessary.
 *
 * \remark see errata note
 *
 * \param [IN] rxTx [1: Tx, 0: Rx]
 */
void SX1272SetAntSw( uint8_t rxTx );

/*!
 * \brief Checks if the given RF frequency is supported by the hardware
 *
 * \param [IN] frequency RF frequency to be checked
 * \retval isSupported [true: supported, false: unsupported]
 */
bool SX1272CheckRfFrequency( uint32_t frequency );

/*!
 * Radio hardware and global parameters
 */
extern SX1272_t SX1272;

#endif // __SX1272_ARCH_H__
