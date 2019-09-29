
/**
 * @file main.c
 * @brief output unicode (japanese) for https://littlevgl.com/ttf-font-to-c-array
 * @author Takashi Kashiwagi
 * @date 2018/11/10
 * @details 
 * --
 * License Type <MIT License>
 * --
 * Copyright 2018 Takashi Kashiwagi
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct{
	uint32_t u32UniCodeBegin;
	uint32_t u32UniCodeEnd;
}stUnicodeTable_t;

static const stUnicodeTable_t s_tUniCodeTableJP[]={
	{0x0020u, 0x007Eu},
	//{0x0080u, 0x00ffu}, // C1 Controls and Latin-1 Supplement
	//{0x0370u, 0x03FFu}, // Greek and Coptic
	//{0x0400u, 0x04FFu}, // Cyrillic
	{0x2000u, 0x206Fu}, // General Punctuation
	{0x2100u, 0x214Fu}, // Letterlike Symbols
	{0x2150u, 0x218Fu}, // Number Forms
	{0x2190u, 0x21FFu}, // Arrows
	{0x2200u, 0x22FFu}, // Mathematical Operators
	{0x2300u, 0x23FFu}, // Miscellaneous Technical
	{0x2500u, 0x257Fu}, // Box Drawing
	{0x25A0u, 0x25FFu}, // Geometric Shapes
	{0x2600u, 0x26FFu}, // Miscellaneous Symbols
	{0x3000u, 0x303Fu}, // CJK Symbols and Punctuation
	{0x3040u, 0x309Fu}, // Hiragana
	{0x30A0u, 0x30FFu}, // Katakana
	{0x4E00u, 0x9FCFu}, // CJK Unified Ideographs
	{0xFF00u, 0xFEEFu}, // Halfwidth and Fullwidth Forms
};

int main(int argc, char *argv[]){
	for(uint32_t i=0;i<(sizeof(s_tUniCodeTableJP)/sizeof(s_tUniCodeTableJP[0]));i++){
		for(uint32_t j=s_tUniCodeTableJP[i].u32UniCodeBegin;j<=s_tUniCodeTableJP[i].u32UniCodeEnd;j++){
//			printf("&#%lu;", j);
			printf("%lu,", j);
		}
	}
	printf("\n");
	return 0;
}
