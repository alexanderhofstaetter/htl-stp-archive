//
//  Manchester.h
//

#ifndef _ManchesterGlobal_h
#define _ManchesterGlobal_h

#define F_CPU 8000000UL

/* 2500 Bits pro Sekunde*/
#define BAUD_RATE 2500

/* Die Zeit für ein Bit pro Sekunde */
#define BIT_TIME 400

#define HALF_TIME 200

/* DIe Zeit zwischen zwei Samples in µs/cycles */
#define SAMPLE_TIME 100

#define DATA_SAMPLES 32

#define SET_BIT(byte, bit) ((byte) |= (1UL << (bit)))

#define CLEAR_BIT(byte,bit) ((byte) &= ~(1UL << (bit)))

#define IS_SET(byte,bit) (((byte) & (1UL << (bit))) >> (bit))

#endif