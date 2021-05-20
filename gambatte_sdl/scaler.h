
#ifndef _SCALER_H
#define _SCALER_H

#include <stdint.h>
#include <SDL/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ScalerType {		// these are the original values used in the other files
	SCALER_NONE = 0,			// 0
	SCALER_15X_SHARP,
	SCALER_15X, 				// 1
	SCALER_15X_BILINEAR, 		// 2
	SCALER_166X_FAST,			// 3
	SCALER_166X_BILINEAR, 		// 4
	SCALER_FULLSCREEN,			// 5
	SCALER_FULLSCREEN_BILINEAR,	// 6
	SCALER_HARDWARE_125X, 		// 7
	SCALER_HARDWARE_136X, 		// 8
	SCALER_HARDWARE_15X, 		// 9
	SCALER_HARDWARE_166X, 		// 10
	SCALER_HARDWARE_FULLSCREEN, // 11
	SCALER_3X_DOTMTRIX, 		// 12
	SCALER_3X_CRT, 				// 13
	SCALER_FULLSCREEN_CRT,		// 14 = CRT Fullscreen?
	
	// unused?
	SCALER_2X_DOTMTRIX,
	SCALER_2X_CRT,
	
	SCALER_BORDER_15X,
	SCALER_BORDER_166X,
	SCALER_BORDER_2X,		
	SCALER_BORDER_2X_CRT,
	SCALER_BORDER_3X,
	SCALER_BORDER_3X_CRT,
} ScalerType;

void scale15x_sharp(uint16_t *dst, uint16_t *src);
void scale15x(uint32_t *to, uint32_t *from);
void scale15x_fast(uint32_t* dst, uint32_t* src);
void scale15x_pseudobilinear(uint32_t* dst, uint32_t* src);
void scale166x_fast(uint32_t* dst, uint32_t* src);
void scale166x_pseudobilinear(uint32_t* dst, uint32_t* src);
void fullscreen_upscale(uint32_t *to, uint32_t *from);
void fullscreen_upscale_pseudobilinear(uint32_t* dst, uint32_t* src);
void scaleborder15x(uint32_t* dst, uint32_t* src);
void scaleborder166x(uint32_t* dst, uint32_t* src);
#ifdef OGA_SCREEN
void scale2x_dotmatrix(uint32_t* dst, uint32_t* src, const uint32_t gridcolor);
void scale2x_crt(uint32_t* dst, uint32_t* src);
void scaleborder2x(uint32_t* dst, uint32_t* src);
void scaleborder2x_crt(uint32_t* dst, uint32_t* src);
#elif VGA_SCREEN
void scale3x_dotmatrix(uint32_t* dst, uint32_t* src, const uint32_t gridcolor);
void scale3x_crt(uint32_t* dst, uint32_t* src);
void fullscreen_crt(uint32_t* dst, uint32_t* src);
void scaleborder3x(uint32_t* dst, uint32_t* src);
void scaleborder3x_crt(uint32_t* dst, uint32_t* src);
#endif

#ifdef __cplusplus
}
#endif

#endif
